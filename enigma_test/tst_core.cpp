#include "catch2/catch.hpp"
#include "Enigma.hpp"

TEST_CASE("Test enigma_lib init", "[Enigma]")
{
    Enigma enigma;
    REQUIRE(0 == 0);
}


TEST_CASE("jump_rotor", "[Enigma]")
{
    Enigma enigma;
    REQUIRE('A' == enigma.jump_rotor('a'));
    REQUIRE('B' == enigma.jump_rotor('a'));
    for (int i = 0; i < 24; ++i) {
        enigma.jump_rotor('a');
    }
    REQUIRE('B' == enigma.jump_rotor('a'));
}

TEST_CASE("get_alphabet_index", "[Enigma]")
{
    char alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    for (int i = 0; i < 26; ++i) {
        REQUIRE(get_alphabet_index(alphabet[i]) == i);
    }

}
