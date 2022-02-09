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

    struct rotors_Settings rotorsSet((char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 5,
                               (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3,
                               (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 4);
    enigma.set_rotors_settings(rotorsSet);

    cout << enigma.code("Hello") << endl;
    cout << enigma.decode("GFOQV");

    cout << endl;

	return 0;
}
