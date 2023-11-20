#include "../include/Maquina.h"

Maquina::Maquina(int _id, int _prob_ganhar, int _premio, int _posX, int _posY, int _temp, string _tipo, string _estado)
{
    ID = _id;
    PROB_GANHAR = _prob_ganhar;
    PREMIO = _premio;
    posX = _posX;
    posY = _posY;
    TEMPERATURA = _temp;
    TIPO = _tipo;
    ESTADO = _estado;
}

Maquina::~Maquina()
{
    //dtor
}

void Maquina::Show(ostream &saida)
{
    saida << "ID: " << ID << endl << "PROB_GANHAR: " << PROB_GANHAR << endl << "PREMIO: " << PREMIO << endl << "posX: " << posX << endl << "posY: " << posY << endl << "TEMP: " << TEMPERATURA << "TIPO: "<< TIPO << "ESTADO: "<< ESTADO << endl << endl;
}
