#include "Enigma.hpp"



Enigma::Enigma()
{
	srand(time(NULL)); //init random gen, but can be init only once

	shuffle_rotors();
}

Enigma::~Enigma()
{
}

void Enigma::shuffle_rotors()
{

	//std::cout << _rotor1; //tres cool pour voir nimp -> use debug tool
	char* table_rotors[] = {_rotor1, _rotor2};

	for (int index_rotor = 0; index_rotor < 2; index_rotor++)
	{
		char* rotor = table_rotors[index_rotor];

		for (int i = 0; i < 26; i++)
		{
			int rand_num = gen_randomNumber();
			std::cout << rand_num << std::endl;

			char cbuff = rotor[i];
			rotor[i] = rotor[rand_num];
			rotor[rand_num] = cbuff;


		}
	}

}


char Enigma::jumpInRotor(char* rotor, char* c)
{
	return rotor[get_alphabet_index(*c)];
}

std::string Enigma::codeMsg(std::string clear_msg)
{
	std::string msg_black;
	char* table_rotors[] = { _rotor1, _rotor2 };

	for (unsigned int index_msg = 0; index_msg < clear_msg.size(); index_msg++)
	{

		char char_toCode = clear_msg.at(index_msg);

		for (int index_rotor = 0; index_rotor < 2; index_rotor++)
		{
			char* rotor = table_rotors[index_rotor];

			char_toCode = jumpInRotor(rotor, &char_toCode);
		}

		msg_black.push_back(char_toCode);
	}
	return msg_black;
}

std::string Enigma::decodeMsg(std::string black_msg)
{
	std::string msg_clear;
	char* inv_table_rotors[] = { _rotor1,_rotor2 };

	for (unsigned int index_msg = 0; index_msg < black_msg.size(); index_msg++)
	{

		char char_toCode = black_msg.at(index_msg);

		for (int index_rotor = 0; index_rotor < 2; index_rotor++)
		{
			char* rotor = inv_table_rotors[index_rotor];

			char_toCode = jumpInRotor(rotor, &char_toCode);
		}

		msg_clear.push_back(char_toCode);
	}
	return msg_clear;
}

unsigned int Enigma::gen_randomNumber()
{
	static unsigned int max_number = 25;
	unsigned int random_number = (rand() % max_number);
	if (random_number>25)
	{
		std::cout << "\n--> error random num upper than 25: "<< random_number <<" <--\n";
	}
	return random_number;
}

int Enigma::get_alphabet_index(char c)
{
	if (c >= 'a' && c <= 'z') {
		return c - 'a';
	}
	else if (c >= 'A' && c <= 'Z') {
		return c - 'A';
	}
	else
	{
		return -1; //not a letter
	}
}

void Enigma::cout_rotors()
{
	std::cout << "rotor 1 a la sortie:" << _Rotors.rotor1 << "\n";
	std::cout << _Rotors.rotor2 << "\n";
}


