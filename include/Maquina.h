#ifndef MAQUINA_H
#define MAQUINA_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

#include "User.h"

class Uteis{};

enum ESTADO_MAQUINA {OFF, ON, AVARIADA, ERRO};

class Maquina
{
    User *U;
    static int ID;
    int ID__;
    float PROB_GANHAR;
    float PROB_AVARIA;
    int PREMIO;
    int posX, posY;
    int TEMPERATURA = 20;
    string TIPO;
    ESTADO_MAQUINA ESTADO;
    int QNT_AVARIA;

    public:
        Maquina(float _prob_ganhar, float _prob_avaria,  int _premio, int _posX, int _posY, int _temp, string _tipo, User *U = NULL, ESTADO_MAQUINA _est = OFF);
        virtual ~Maquina();

        ESTADO_MAQUINA Get_ESTADO(){ return ESTADO; }               // RETORNA O ESTADO DA MÁQUINA
        int Get_ID (){ return ID__; }                               // RETORNA O ID DA MÁQUINA
        int Get_POSX(){ return posX; }                              // RETORNA A POSX
        int Get_POSY(){ return posY; }                              // RETORNA A POSY
        float Get_PROB_GANHAR(){ return PROB_GANHAR; }              // RETORNA A PROBABILIDADE DE GANHAR DE UMA MÁQUINA
        void Set_ESTADO(ESTADO_MAQUINA _est);                       // ALTERA O ESTADO DA MÁQUINA
        void Set_PROB_GANHAR(float _prob){ PROB_GANHAR += _prob; }  // ALTERA A PROBABILIDADE DE GANHAR DA MÁQUINA
        string Get_TIPO(){ return TIPO; }                           // RETORNA O TIPO DA MÁQUINA
        float Get_PROB_AVARIA(){ return PROB_AVARIA; }              //RETORNA A PROBABILIDADE DE AVARIA
        void Inc_QNT_AVARIA(){ QNT_AVARIA++; }                      //INCREMENTA A QUANTIDADE DE AVARIA
        int Get_QNT_AVARIA(){ return QNT_AVARIA; }                  //RETORNA A QUANTIDADE DE AVARIAS
        void Set_User(User *_U){ U = _U; }
        User *Get_User(){ return U; }

        virtual void Jogar();                                       //FUNÇÃO PARA JOGAR NA MÁQUINA ESCOLHIDA

        void Show(ostream &saida = cout);                           // MOSTRA OS DADOS DA MÁQUINA
        virtual int Memoria(){ return sizeof(*this); }              // CALCULA A MEMÓRIA OCUPADA

        void Dec_STATIC_ID(){ ID--; }

       void Aquecer();
};

#endif // MAQUINA_H
