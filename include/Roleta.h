#ifndef ROLETA_H
#define ROLETA_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
//#include <conio.h>

using namespace std;

#include "User.h"
#include "Maquina.h"
#include "Uteis.h"

class Roleta : public Maquina
{
    public:
        Roleta(int _id, int _prob_ganhar, int _premio, int _posX, int _posY, int _temp, string _tipo);
        virtual ~Roleta();

        void Jogar();
        string Get_TIPO(){ return "ROLETA"; }
        int Memoria(){ return sizeof(*this); }
};

#endif // ROLETA_H
