#pragma once

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdlib.h>


int get_alphabet_index(char c);

struct rotor
{
    char* table;
    int index;

    rotor()
    {
        table = (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        index = 0;
    }
};




class Enigma
{
public:
	Enigma();
	~Enigma();

    char jump_rotor(char letter);
    char jump_rotor_reverse_static(char letter);
    char jump_reflector(char letter);

    char inv_jump_rotor(char letter);
    char inv_jump_rotor_reverse_static(char letter);

    std::string code(std::string msg);
    std::string decode(std::string msg);

    //void set_rotors(struct rotors_Settings); //next step

	static unsigned int gen_randomNumber();
    unsigned int get_index_rotor(char letter, rotor rotor);

private:
    char alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

    struct rotor rotor1, rotor2, rotor3;
    struct rotor reflector;

};




//char _alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };


