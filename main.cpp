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

    digit_lang digit_german (
        {"negativ"},
        { "", "eins", "zwei", "drei", "vier", "fuhnf", "sechs", "sieben", "acht", "neun",  "zehn", "elf", "tsvulef", "dry-tsayn", "feer-tsayn", "fuhnf-tsayn", "zekh-tsayn", "zeeb-tsayn", "akt-tsayn", "noin-tsayn" },
        { "", "zehn", "zwanzig", "DRY-sig", "vierzig", "FUHNF-tsig", "sechzig", "siebzig", "achtzig", "neunzig" },
        { "", "hundert", "tausend", "million", "milliarde"},
        "German"
    );

    digit_en.spell_number("123456");
    digit_en.spell_number("abcd");
    digit_vn.spell_number("231-4355");
    digit_vn.spell_number("-12345678912345678945130000000");
    digit_german.spell_number("52");
    return 0;
}