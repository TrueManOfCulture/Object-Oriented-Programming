#ifndef MAQUINA_H
#define MAQUINA_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

//#include "User.h"

class Maquina
{
    //User *U;
    int ID;
    int PROB_GANHAR;
    int PREMIO;
    int posX, posY;
    int TEMPERATURA;

    public:
        Maquina(int _id, int _prob_ganhar, int _premio, int _posX, int _posY, int _temp);
        virtual ~Maquina();
        int Get_PROB_GANHAR(){ return PROB_GANHAR; }
        virtual void Jogar(){}

        virtual string Get_TIPO(){ return "SEM_TIPO"; }
        virtual void Show();

};

#endif // MAQUINA_H
