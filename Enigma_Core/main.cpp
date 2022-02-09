// Enigma_Console.cpp : définit le point d'entrée de l'application.
//
//My codes are in English and in French.
//C'est une horreur pour les review...

#include "main.hpp"

using namespace std;

int main()
{
    cout << "--> START <--\n" ;

	Enigma enigma;

    /*
	string msgToCode = "HelloWorld";
    string result = enigma.code(msgToCode);

    cout << "input: " << msgToCode << "\n";
    cout << "response: " << result << "\n";
    cout << "decode: " << enigma.decode(result);
    */
    string mmm;
    //mmm.push_back(enigma.jump_rotor('a'));

    cout << enigma.code("Hello") << endl;
    cout << enigma.decode("IHQSX");


    cout << endl;

	return 0;
}
