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
    static int ID;
    float PROB_GANHAR;
    int PREMIO;
    int posX, posY;
    int TEMPERATURA;
    string TIPO;
    ESTADO_MAQUINA ESTADO;                             

    public:
        Maquina(float _prob_ganhar, int _premio, int _posX, int _posY, int _temp, string _tipo, User *U = NULL, ESTADO_MAQUINA _est = OFF);
        virtual ~Maquina();

        ESTADO_MAQUINA Get_ESTADO(){ return ESTADO; }               // RETORNA O ESTADO DA MÁQUINA
        int Get_ID (){ return ID; }                                 // RETORNA O ID DA MÁQUINA
        float Get_PROB_GANHAR(){ return PROB_GANHAR; }              // RETORNA A PROBABILIDADE DE GANHAR DE UMA MÁQUINA
        void Set_ESTADO(ESTADO_MAQUINA _est){ ESTADO = _est; }      // ALTERA O TIPO ESTADO DA MÁQUINA
        virtual void Jogar(){}

        virtual string Get_TIPO(){ return "SEM_TIPO"; }             // RETORNA O TIPO DA MÁQUINA
        virtual void Show(ostream &saida = cout);                   // MOSTRA OS DADOS DA MÁQUINA
        virtual int Memoria(){ return sizeof(*this); }              // CALCULA A MEMÓRIA OCUPADA
};

#endif // MAQUINA_H
