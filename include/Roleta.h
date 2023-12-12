#ifndef ROLETA_H
#define ROLETA_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
//#include <conio.h>

using namespace std;

#include "User.h"
#include "Maquina.h"
#include "Uteis.h"

class Roleta : public Maquina
{
    public:
        Roleta(float _prob_ganhar, float _prob_avaria,  int _premio, int _posX, int _posY, int _temp, string _tipo, User *U = NULL, ESTADO_MAQUINA _est = OFF);
        virtual ~Roleta();

        bool Jogar();                               // FUNÇÃO DE JOGAR
        //string Get_TIPO(){ return TIPO; }           // RETORNA O TIPO DA MÁQUINA
        int Memoria(){ return sizeof(*this); }      // CALCULA A MEMÓRIA OCUPADA
};

#endif // ROLETA_H
