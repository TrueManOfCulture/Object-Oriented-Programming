#include "Maquina.h"

Maquina::Maquina(int _id, int _prob_ganhar, int _premio, int _posX, int _posY, int _temp)
{
    ID = _id;
    PROB_GANHAR = _prob_ganhar;
    PREMIO = _premio;
    posX = _posX;
    posY = _posY;
    TEMPERATURA = _temp;
}

Maquina::~Maquina()
{
    //dtor
}

void Maquina::Show(ostream &saida)
{
    saida << "ID: " << ID << endl << "PROB_GANHAR: " << PROB_GANHAR << endl << "PREMIO: " << PREMIO << endl << "posX: " << posX << endl << "posY: " << posY << endl << "TEMP: " << TEMPERATURA << endl << endl;
}
