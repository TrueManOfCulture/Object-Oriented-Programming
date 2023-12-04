#ifndef CLASSICSLOTS_H
#define CLASSICSLOTS_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <unistd.h>

using namespace std;

#include "User.h"
#include "Maquina.h"
#include "Uteis.h"

class ClassicSlots : public Maquina
{
    public:
        ClassicSlots(float _prob_ganhar, float _prob_avaria,  int _premio, int _posX, int _posY, int _temp, string _tipo, User *U = NULL, ESTADO_MAQUINA _est = OFF);
        virtual ~ClassicSlots();

        void Jogar();                                   // FUNÇÃO DE JOGAR
        //string Get_TIPO(){ return TIPO; }               // RETORNA O TIPO
        int Memoria(){ return sizeof(*this); }          // CALCULO DE MEMÓRIA
};

#endif // CLASSICSLOTS_H
