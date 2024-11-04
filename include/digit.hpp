/**
 * Author:    Cong, Bui Thanh
 * Created:   11.01.2024
 * 
 * This program was written first in C to test the performance
 **/


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

enum err_no {
    ok = 0,
    invalid_input = 1,
    too_long_input = 2,
    total_err_no
};

int set_digit_letter(char *digit_letter[MAX_LLION][MAX_LLION], char *letters[MAX_LLION]);

class digit_lang {
protected:
    const char *negative;
    std::vector<const char *> ones;
    std::vector<const char *> tens;
    std::vector<const char *> lions;
    uint8_t hundred_llion = 3, billion_llion = 9;
    const char *lang;

public:
    digit_lang() {
        this->negative  = {"negative"};
        this->ones      = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",  "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
        this->tens      = { "", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
        this->lions     = { "", "hundred", "thousand", "million", "billion"};
        this->lang      = {"English"};
    }

    digit_lang(const char *_neg, std::vector<const char*> _ones, std::vector<const char*> _tens, std::vector<const char*> _lions, const char *_lang) {
        this->negative  = _neg;
        this->ones      = _ones;
        this->tens      = _tens;
        this->lions     = _lions;
        this->lang     = _lang;
    }

    virtual int spell_number(const char *s);
    virtual void print_digit_letter(char *digit_letter[MAX_LLION][MAX_LLION]);
protected:
    virtual int spell_llion(int i, char *digit_letter[]);
    virtual int spell_ones(const char *s, char *digit_letter[]);
    virtual int spell_tens(const char *s, char *digit_letter[], int len);
    virtual int spell_hundred(const char *s, char *digit_letter[], int len);
    virtual int spell_billion(const char *s, char *letters[], int len);
    int validate_check(const char *s);
    int standardize(char **s, char *letter[]);
};

class digit_vn : public digit_lang {
public:
    digit_vn() {
        this->negative  = {"am"};
        this->ones      = { "", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin",  "muoi", "muoi mot", "muoi hai", "muoi ba", "muoi bon", "muoi lam", "muoi sau", "muoi bay", "muoi tam", "muoi chin" };
        this->tens      = { "", "muoi", "hai muoi", "ba muoi", "bon muoi", "nam muoi", "sau muoi", "bay muoi", "tam muoi", "chin muoi" };
        this->lions     = { "", "tram", "nghin", "trieu", "ty"};
        this->lang      = {"Vietnamese"};
    }
};

#endif /*DIGIT_HPP*/
