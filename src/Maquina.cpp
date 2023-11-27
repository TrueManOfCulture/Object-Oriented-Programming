#include "../include/Maquina.h"

int Maquina::ID = 0;

Maquina::Maquina(float _prob_ganhar, float _prob_avaria,  int _premio, int _posX, int _posY, int _temp, string _tipo, User *U, ESTADO_MAQUINA _est)
{
    ID++;
    ID__ = ID;
    PROB_GANHAR = _prob_ganhar;
    PREMIO = _premio;
    posX = _posX;
    posY = _posY;
    TEMPERATURA = _temp;
    TIPO = _tipo;
    ESTADO = _est;
    PROB_AVARIA = _prob_avaria;
}

Maquina::~Maquina()
{
    //dtor
}

void Maquina::Show(ostream &saida)
{
    saida << "ID: " << ID__ << endl << "PROB_GANHAR: " << PROB_GANHAR << endl << "PREMIO: " << PREMIO << endl << "posX: " << posX << endl << "posY: " << posY << endl << "TEMP: " << TEMPERATURA << endl << "TIPO: "<< TIPO << endl << endl;
}
