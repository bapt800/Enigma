#pragma once

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdlib.h>


class Enigma
{
public:
	Enigma();
	~Enigma();

	void shuffle_rotors();

	char jumpInRotor(char* rotor, char* c);
	char inv_jumpInRotor(char* rotor, char* c);


	std::string codeMsg(std::string clear_msg);
	std::string decodeMsg(std::string black_msg);

	std::string enigma_code(std::string clear_msg);
	std::string enigma_decode(std::string black_msg);

    char* get_rotors();

	static unsigned int gen_randomNumber();
	static int get_alphabet_index(char c); //not by me

private:

	char _alphabet[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	char _rotor1[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	char _rotor2[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	
	int rotor_poss = 0; //position du rotor, pour que ca tourne
};



