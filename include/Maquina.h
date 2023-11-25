#ifndef MAQUINA_H
#define MAQUINA_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

#include "User.h"

enum ESTADO_MAQUINA{OFF, ON, AVARIADA, ERRO};

class Maquina
{
    //User *U;
    int ID;
    float PROB_GANHAR;
    int PREMIO;
    int posX, posY;
    int TEMPERATURA;
    string TIPO;
    ESTADO_MAQUINA ESTADO;

    public:
        Maquina(int _id, float _prob_ganhar, int _premio, int _posX, int _posY, int _temp, string _tipo, User *U = NULL, ESTADO_MAQUINA _est = OFF);
        
        virtual ~Maquina();
        ESTADO_MAQUINA GET_ESTADO(){ return ESTADO; }
        int GET_ID (){return ID; }
        float Get_PROB_GANHAR(){ return PROB_GANHAR; }
        virtual void Jogar(){}

        virtual string Get_TIPO(){ return "SEM_TIPO"; }
        virtual void Show(ostream &saida = cout);
        virtual int Memoria(){ return sizeof(*this); }

};

#endif // MAQUINA_H
