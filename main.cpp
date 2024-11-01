#include "digit.hpp"


int main() {
    digit_lang digit_en;

    digit_lang digit_vn (
        {"am"},
        { "", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin",  "muoi", "muoi mot", "muoi hai", "muoi ba", "muoi bon", "muoi lam", "muoi sau", "muoi bay", "muoi tam", "muoi chin" },
        { "", "muoi", "hai muoi", "ba muoi", "bon muoi", "nam muoi", "sau muoi", "bay muoi", "tam muoi", "chin muoi" },
        { "", "tram", "nghin", "trieu", "ty"},
        "Vietnamese"
    );

    digit_en.spell_number("123456");
    digit_en.spell_number("abcd");
    digit_vn.spell_number("231-4355");
    digit_vn.spell_number("-12345678912345678945130000000");
    return 0;
}