// Enigma_Console.cpp : définit le point d'entrée de l'application.
//
//My codes are in English and in French.
//C'est une horreur pour les review...

#include "main.hpp"

using namespace std;

int main()
{
	Enigma enigma;

	string msgToCode = "HelloWorld";


	string black_msg = enigma.codeMsg(msgToCode);
	cout << "\n\nbase msg: " <<msgToCode << "\nblack msg: " << black_msg;
	cout << "\n\nblack msg: " << black_msg << "\nclear msg: " << enigma.decodeMsg(black_msg);


	return 0;
}
