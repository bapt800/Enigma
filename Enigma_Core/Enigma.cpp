#include "Enigma.hpp"


int get_alphabet_index(char c)
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


Enigma::Enigma()
{
	srand(time(NULL)); //init random gen, but can be init only once

}

Enigma::~Enigma()
{
}

char Enigma::jump_rotor(char letter)
{
    letter = rotor1.table[(get_alphabet_index(letter)+ rotor1.index)% 26];
    rotor1.index = (rotor1.index + 1 )% 26;

    letter = rotor2.table[(get_alphabet_index(letter)+ rotor2.index)% 26];
    if (rotor1.index == 0)
    {
    rotor2.index = (rotor2.index + 1 )% 26;
    }

    letter = rotor3.table[(get_alphabet_index(letter)+ rotor3.index)% 26];
    if (rotor1.index == 0 && rotor2.index == 0)
    {
    rotor3.index = (rotor3.index + 1 )% 26;
    }

    return letter;
}

char Enigma::jump_rotor_reverse_static(char letter)
{
    letter = rotor3.table[(get_alphabet_index(letter)+ rotor3.index)% 26];
    letter = rotor2.table[(get_alphabet_index(letter)+ rotor2.index)% 26];
    letter = rotor1.table[(get_alphabet_index(letter)+ rotor1.index)% 26];
    return letter;
}

char Enigma::jump_reflector(char letter)
{
    //return reflector.table[get_alphabet_index(letter)];
    return alphabet[get_index_rotor(letter, reflector)];
}

char Enigma::inv_jump_rotor(char letter)
{


    letter = alphabet[get_index_rotor(letter, rotor3)];
    letter = alphabet[get_index_rotor(letter, rotor2)];
    letter = alphabet[get_index_rotor(letter, rotor1)];


    rotor1.index = (rotor1.index + 1 )% 26;
    if (rotor1.index == 0)
    {
    rotor2.index = (rotor2.index + 1 )% 26;
    }
    if (rotor1.index == 0 && rotor2.index == 0)
    {
    rotor3.index = (rotor3.index + 1 )% 26;
    }

    return letter;
}

char Enigma::inv_jump_rotor_reverse_static(char letter)
{
    letter = alphabet[get_index_rotor(letter, rotor1)];
    letter = alphabet[get_index_rotor(letter, rotor2)];
    letter = alphabet[get_index_rotor(letter, rotor3)];


    return letter;
}

std::string Enigma::code(std::string msg)
{
    std::string msg_Return;
    for (int i =0; i<msg.size(); i++)
    {
        msg_Return.push_back(jump_rotor_reverse_static(jump_reflector(jump_rotor(msg.at(i)))));
    }
    return msg_Return;
}

std::string Enigma::decode(std::string msg)
{
    rotor1.index = 0;
    rotor2.index = 0;
    rotor3.index = 0;

    std::string msg_Return;
    for (int i =0; i<msg.size(); i++)
    {
        char c;
        c = inv_jump_rotor(msg.at(i));
        c = jump_reflector(c);
        c = inv_jump_rotor_reverse_static(c);
        msg_Return.push_back(c);
    }
    return msg_Return;
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

unsigned int Enigma::get_index_rotor(char letter, rotor rotor)
{
    int i = 0;
    while (0<=i && letter != rotor.table[i] && i<26)
    {
        i++;
    }
    i = (i - rotor.index)% 26;
    return i;
}




