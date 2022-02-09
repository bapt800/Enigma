// Enigma_Console.cpp : définit le point d'entrée de l'application.

#include "main.hpp"

using namespace std;

int main()
{
    cout << "--> START <--\n" ;

	Enigma enigma;

    struct rotors_Settings rotorsSet((char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 8,
                               (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 4,
                               (char*)"ABCDEFGHIJKLMNOPQRSTUVWXYZ", 12);
    enigma.set_rotors_settings(rotorsSet);

    string msg_black = enigma.code("RAPPORT DE PATROUILLE DU SOUS MARIN NAUTILUS PREMIER CONTACT AU NORD DE BREST. MER CALME. CHALUTIER ISOLE. PAS D ENGAGEMENT. DEUXIEME CONTACT AU SUD DE BRIGHTON. CONVOI MARCHAND. TROIS NAVIRES COULES. ESCORTE EN DEROUTE. INTEMPERIES SUR LE RETOUR. AVARIE EXTERNE TUBE TORPILLE SUPERIEUR GAUCHE. BALLAST ENDOMMAGE. RETOUR A LORIENT LUNDI MIDI.PROCHAINE PATROUILLE A L EST DE HORNSEA TRANSMISSION TERMINEE");
    cout << msg_black << endl << enigma.decode(msg_black) << endl;

    //prendre la structure rotors_Settings, mais n'utilise pas l'index fournit.
    cout << "\n\n   turing algo now \n" << turing_decode(msg_black, rotorsSet, "RAPPORTDEPATROUILLEDUSOUSMARIN");

    cout << endl;

	return 0;
}
