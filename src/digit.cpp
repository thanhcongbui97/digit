#include "digit.hpp"

const char *err_msg [] = {
    "OK",
    "INVALID INPUT",
    "INPUT IS TOO LONG",
    "UNKNOW ERROR",
};

void print_digit_letter(char *digit_letter[MAX_LLION][MAX_LLION]) {
    int j, k;
    for (j = 0; j < MAX_LLION; j++) {
        for(k = 0; k < MAX_LLION; k++) {
            int r = MAX_LLION - j - 1;
            if (digit_letter[r][k] == NULL || strlen(digit_letter[r][k]) == 0) {
                continue;
            }
            printf("%s ", digit_letter[r][k]);
        } 
    }
    printf("\n");
}

int set_digit_letter(char *digit_letter[MAX_LLION][MAX_LLION], char *letters[MAX_LLION]) {
    int j, k, i;
    i = 0;
    for (j = 0; j < MAX_LLION; j++) {
        for(k = 0; k < MAX_LLION; k++) {
            int r = MAX_LLION - j - 1;
            if (digit_letter[r][k] == NULL || strlen(digit_letter[r][k]) == 0) {
                continue;
            }
            letters[i] = digit_letter[r][k];
            i++;
        }
    }

    return i;
}

int digit_lang::validate_check(const char *s) {
    if (strlen(s) > MAX_INPUT_LENGTH) {
        return too_long_input;
    }
    
    if ((s[0] != '-') && (s[0] < '0' || s[0] > '9')) {
        return invalid_input;
    }

    uint32_t i;
    for (i = 1; i < strlen(s); i++) {
        if (s[i] < '0' || s[i] > '9') {
            return invalid_input;
        }
    }

    return ok;
}

int digit_lang::spell_llion(int i, char *digit_letter[]) {
    if (i < 3) {
        return 0;
    }
    digit_letter[0] = (char*)this->lions[((i - 3) % 9) / 3 + 2];
    return 1;
}

int digit_lang::spell_ones(const char *s, char *digit_letter[]) {
    digit_letter[0] = (char*)this->ones[s[0] - '0'];
    return 1;
}

int digit_lang::spell_tens(const char *s, char *digit_letter[], int len) {
    int i = 0, j = 0;
    if (len == 2) {
        if (s[j] == '1') {
            /* From 11 to 19 */
            j++;
            digit_letter[i++] = (char*)this->ones[s[j] - '0' + 10];
            return i;
        } else {
            digit_letter[i++] = (char*)this->tens[s[j++] - '0'];
        }
    }

    i += spell_ones(s + j, digit_letter + i);

    return i;
}

int digit_lang::spell_hundred(const char *s, char *digit_letter[], int len) {
    int i = 0, j = 0, lead = 0;

    for (i = 0; i < len; i++) {
        if (s[i] != '0') {
            lead = 1;
        }
    }
    
    if (lead == 0) {
        return 0;
    }

    int n_len = len;
    i = 0;
    if (s[0] == '-') {
        digit_letter[i++] = (char*)this->negative;
        j++;
    }

    if (n_len - j > 3) {
        return 0;
    }

    if (n_len - j == 3) {
        digit_letter[i++] = (char*)this->ones[s[j++] - '0'];

        if (strlen(digit_letter[i - 1]) > 0) {
            /* Add hundred */
            digit_letter[i++] = (char*)this->lions[1];
        }
    }
    
    i += spell_tens(s + j, digit_letter + i, n_len -j);

    return i;
}

int digit_lang::spell_billion(const char *s, char *letters[], int len) {
    char *digit_letter[MAX_LLION][MAX_LLION] = {0};
    int i = 0, letter = 0, offset = 0, hundred_llion = 3;

    while (i + hundred_llion < len) {
        offset = 0;
        i += hundred_llion;
        letter = spell_hundred(s + len - i, digit_letter[i/hundred_llion], hundred_llion);
        offset += letter;
        if (letter > 0) {
            offset += spell_llion(i - hundred_llion, digit_letter[i/hundred_llion] + offset);
        }    
    }

    offset = 0;
    letter = spell_hundred(s, digit_letter[i/hundred_llion + 1] + offset, len - i);
    offset += letter;
    if (letter > 0) {
        offset += spell_llion(i, digit_letter[i/hundred_llion + 1] + offset);
    }

    return set_digit_letter(digit_letter, letters);
}

int digit_lang::spell_number(const char *s) {

    int err = validate_check(s);
    if (err != ok) {
        printf("%s ERROR [%s] : %s\n", __func__, err_msg[err], s);
        return err;
    }

    char *digit_letter[MAX_LLION][MAX_LLION] = {0};

    int i = 0, letter = 0, offset = 0, billion_llion = 9;

    while (i + billion_llion < (int)strlen(s)) {
        offset = 0;
        i += billion_llion;
        letter = spell_billion(s + strlen(s) - i, digit_letter[i/billion_llion], billion_llion);
        offset += letter;
        
        offset += spell_llion(i - billion_llion, digit_letter[i/billion_llion] + offset);
    }

    offset = 0;
    letter = spell_billion(s, digit_letter[i/billion_llion + 1] + offset, strlen(s) - i);
    offset += letter;
    offset += spell_llion(i, digit_letter[i/billion_llion + 1] + offset);

    print_digit_letter(digit_letter);

    return i/billion_llion;
}
