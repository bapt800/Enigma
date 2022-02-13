#include "turing.hpp"



std::string turing_decode(std::string msg, struct rotors_Settings rotorsSettings, std::string litteral)
{
    Enigma enigma;
    struct rotors_Settings settings(rotorsSettings._rotor1_table, rotorsSettings._rotor2_table, rotorsSettings._rotor3_table);
    enigma.set_rotors_settings(settings);

    //litteral = clean_text_input(litteral);

    std::string white_msg;
    int FULL_STOP = 0;
    while (FULL_STOP < 10000)
    {
        FULL_STOP++;

        white_msg = enigma.decode(msg);


        for (int index_white=0; index_white<white_msg.size(); index_white++)
        {
            if (white_msg.at(index_white) == litteral.at(0))
            {
                bool verif = true;
                for (int test_all_litteral=0; test_all_litteral<litteral.size(); test_all_litteral++)
                {
                    if ( (index_white+test_all_litteral) >=  white_msg.size())
                    {
                        verif = false;
                        break;
                    }
                    if (white_msg.at(index_white+test_all_litteral) != litteral.at(test_all_litteral))
                    {
                        verif = false;
                        break;
                    }
                }
                if (verif == true)
                {
                    return white_msg;
                }

            }
        }

        settings._rotor1_index = (settings._rotor1_index+ 1)% 26;
        if (settings._rotor1_index == 0)
        {
            settings._rotor2_index = (settings._rotor2_index+ 1)% 26;
        }
        if (settings._rotor2_index == 0)
        {
            settings._rotor3_index = (settings._rotor3_index+ 1)% 26;
        }

        enigma.set_rotors_settings(settings);
    }
    return "NONE";

}
