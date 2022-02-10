#pragma once

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdlib.h>


int get_alphabet_index(char c);
std::string clean_text_input(std::string input);

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

struct rotors_Settings
{
    char* _rotor1_table;
    int _rotor1_index;
    char* _rotor2_table;
    int _rotor2_index;
    char* _rotor3_table;
    int _rotor3_index;

    rotors_Settings(){}
    rotors_Settings(char* rotor1_table, char* rotor2_table, char* rotor3_table)
    {
        _rotor1_table=rotor1_table;
        _rotor1_index=0;
        _rotor2_table=rotor2_table;
        _rotor2_index=0;
        _rotor3_table=rotor3_table;
        _rotor3_index=0;
    }
    rotors_Settings(char* rotor1_table, int rotor1_index, char* rotor2_table, int rotor2_index, char* rotor3_table, int rotor3_index)
    {
        _rotor1_table=rotor1_table;
        _rotor1_index=rotor1_index;
        _rotor2_table=rotor2_table;
        _rotor2_index=rotor2_index;
        _rotor3_table=rotor3_table;
        _rotor3_index=rotor3_index;
    }
};


class Enigma
{
public:
	Enigma();
    Enigma(struct rotors_Settings settings);
	~Enigma();

    char jump_rotor(char letter);
    char jump_rotor_reverse_static(char letter);
    char jump_reflector(char letter);

    char inv_jump_rotor(char letter);
    char inv_jump_rotor_reverse_static(char letter);

    std::string code(std::string msg);
    std::string decode(std::string msg);

    void set_rotors_settings(struct rotors_Settings settings);
    struct rotors_Settings get_rotors_settings();

	static unsigned int gen_randomNumber();
    unsigned int get_index_rotor(char letter, rotor rotor);

private:
    char alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

    struct rotor rotor1, rotor2, rotor3;
    struct rotor reflector;

    struct rotors_Settings rotors_settings;

};




//char _alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };


