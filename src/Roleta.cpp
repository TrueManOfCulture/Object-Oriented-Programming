#include "../include/Roleta.h"

Roleta::Roleta(float _prob_ganhar, float _prob_avaria,  int _premio, int _posX, int _posY, int _temp, string _tipo, User *U, ESTADO_MAQUINA _est)
    : Maquina(_prob_ganhar, _prob_avaria, _premio, _posX, _posY, _temp, _tipo, U, _est)
{
    //ctor
}

Roleta::~Roleta()
{
    //dtor
}

void Roleta::Jogar()
{
    /*int RESULTADO = AleatorioINT(1, 36);

    int esc;
    cout << "Onde vai apostar: " << endl << "\t1- Vermelho"*/
}
