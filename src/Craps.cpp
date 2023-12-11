#include "../include/Craps.h"

Craps::Craps(float _prob_ganhar, float _prob_avaria,  int _premio, int _posX, int _posY, int _temp, string _tipo, User *U, ESTADO_MAQUINA _est)
    : Maquina(_prob_ganhar, _prob_avaria, _premio, _posX, _posY, _temp, _tipo, U, _est)
{
    cout << "Passei por " << __FUNCTION__<< endl;
}

Craps::~Craps()
{
    //dtor
}

void Craps::Jogar()
{
    
}