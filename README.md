# digit
 utilities to spell a number from word

# To start, going with Make:
    $ make

# Class Interface:
## class digit_lang () is the base class, that can be overiden with 5 of element
- First, is how the negative number is spelling from that language
- Second, is counting from 1 to 19
- Third, is counting with multiple of tens
- Fourth, is couting with power of thousand, include the hundred number
- And final, the language's name itself

It can be also adding another language by using the Polymorphism ability of self class , even the spell_number() and print_digit_letter() function can also be overriden or by just calling the constructor it self to generate new language pattern.