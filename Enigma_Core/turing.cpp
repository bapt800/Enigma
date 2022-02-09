#include "turing.h"



std::string turing_decode(std::string msg, struct rotors_Settings rotorsSettings, std::string litteral)
{
    Enigma enigma;
    enigma.set_rotors_settings(rotorsSettings);

    std::string white_msg;
    int FULL_STOP = 0;
    while (FULL_STOP < 1000)
    {
        FULL_STOP++;

        white_msg = enigma.decode(msg);
        if (white_msg.size() != msg.size())
        {
            return "ERROR";
        }

        bool succes = false;
        int index_litteral = 0;
        int index_white_full = 0;
        for (int index_white=0; index_white<white_msg.size(); index_white++)
        {
            if (white_msg.at(index_white) == litteral.at(index_litteral))
            {
                return white_msg;
            }
        }

        rotorsSettings._rotor1_index = (rotorsSettings._rotor1_index+1)% 26;
        if (rotorsSettings._rotor1_index == 0)
        {
            rotorsSettings._rotor2_index = (rotorsSettings._rotor2_index+1)% 26;
        }
        if (rotorsSettings._rotor2_index == 0)
        {
            rotorsSettings._rotor3_index = (rotorsSettings._rotor3_index+1)% 26;
        }

        enigma.set_rotors_settings(rotorsSettings);
    }
    return "NONE";

}
