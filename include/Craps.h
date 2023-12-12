#ifndef CRAPS_H
#define CRAPS_H

#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

#include "User.h"
#include "Maquina.h"
#include "Uteis.h"

class Craps : public Maquina
{
    public:
        Craps(float _prob_ganhar, float _prob_avaria,  int _premio, int _posX, int _posY, int _temp, string _tipo, User *U = NULL, ESTADO_MAQUINA _est = OFF);
        virtual ~Craps();

        bool Jogar();                               // Função de Jogar
        //string Get_TIPO(){ return TIPO; }         // Retornar o TIPO da máquina
        int Memoria(){ return sizeof(*this); }      // Retornar o espaço em memória que a máquina ocupa
};

#endif // CRAPS_H
