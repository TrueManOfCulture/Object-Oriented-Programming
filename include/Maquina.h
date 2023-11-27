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
    int POSICAO[2];                                 

    public:
Maquina::Maquina(float _prob_ganhar, int _premio, int _posX, int _posY, int pos[2], int _temp, string _tipo, User *U, ESTADO_MAQUINA _est);
        
        void ReturnBytes(){ cout << "ID: " << sizeof(ID) << endl << "PROB_GANHAR: " << sizeof(PROB_GANHAR) << endl << "PREMIO: " << sizeof(PREMIO) << endl << "PosX: " << sizeof(posX) << endl << "PosY: " << sizeof(posY) << endl << "Temp: " << sizeof(TEMPERATURA) << endl << "TIPO: " << sizeof(TIPO) << endl << "ESTADO: " << sizeof(ESTADO) << endl << endl; }
        
        virtual ~Maquina();
        ESTADO_MAQUINA Get_ESTADO(){ return ESTADO; }
        int Get_ID (){ return ID; }
        float Get_PROB_GANHAR(){ return PROB_GANHAR; }
        void Set_ESTADO(ESTADO_MAQUINA _est){ ESTADO = _est; }
        virtual void Jogar(){}

        virtual string Get_TIPO(){ return "SEM_TIPO"; }
        virtual void Show(ostream &saida = cout);
        virtual int Memoria(){ return sizeof(*this); }

};

#endif // MAQUINA_H
