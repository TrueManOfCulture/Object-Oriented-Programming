#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <string>
#include <list>
#include <vector>
//#include <conio.h>

using namespace std;

#include "User.h"
#include "Maquina.h"
#include "Uteis.h"

class BlackJack : public Maquina
{
    public:
        BlackJack(float _prob_ganhar, float _prob_avaria,  int _premio, int _posX, int _posY, int _temp, string _tipo, User *U = NULL, ESTADO_MAQUINA _est = OFF);
        virtual ~BlackJack();

        void Jogar();                               // Função de Jogar
        string Get_TIPO(){ return "BLACKJACK"; }    // Retornar o TIPO da máquina
        int Memoria(){ return sizeof(*this); }      // Retornar o espaço em memória que a máquina ocupa
};

#endif // BLACKJACK_H
