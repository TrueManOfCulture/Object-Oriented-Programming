#include "../include/Roleta.h"

Roleta::Roleta(int _id, int _prob_ganhar, int _premio, int _posX, int _posY, int _temp, string _tipo, string _estado)
    : Maquina(_id, _prob_ganhar, _premio, _posX, _posY, _temp, _tipo, _estado)
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
