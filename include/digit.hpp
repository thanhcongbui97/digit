#ifndef DIGIT_HPP
#define DIGIT_HPP

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

#define MAX_ONE 20
#define MAX_TEN 10
#define MAX_LLION 128
#define MAX_INPUT_LENGTH 1024
#define MAX_OUTPUT 128

enum err_no {
    ok = 0,
    invalid_input = 1,
    too_long_input = 2,
    total_err_no
};

void print_digit_letter(char *digit_letter[MAX_LLION][MAX_LLION]);

int set_digit_letter(char *digit_letter[MAX_LLION][MAX_LLION], char *letters[MAX_LLION]);

class digit_lang {
private:
    const char *negative;
    std::vector<const char *> ones;
    std::vector<const char *> tens;
    std::vector<const char *> lions;
    uint8_t hundred_llion = 3, billion_llion = 9;

public:
    digit_lang(const char *_neg, std::vector<const char*> _ones, std::vector<const char*> _tens, std::vector<const char*> _lions) {
        this->negative  = _neg;
        this->ones      = _ones;
        this->tens      = _tens;
        this->lions     = _lions;
    }

    int spell_number(const char *s);
private:
    int spell_llion(int i, char *digit_letter[]);
    int spell_ones(const char *s, char *digit_letter[]);
    int spell_tens(const char *s, char *digit_letter[], int len);
    int spell_hundred(const char *s, char *digit_letter[], int len);
    int spell_billion(const char *s, char *letters[], int len);
    int validate_check(const char *s);
};

#endif /*DIGIT_HPP*/
