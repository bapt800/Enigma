#ifndef TURING_H
#define TURING_H

#include "Enigma.hpp"
#include <string>

//prendre la structure rotors_Settings, mais n'utilise pas l'index même si fournit.
std::string turing_decode(std::string msg, struct rotors_Settings rotorsSettings, std::string litteral);


#endif // TURING_H
