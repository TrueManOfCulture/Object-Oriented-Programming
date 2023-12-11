#include "../include/Maquina.h"

#include "../include/Uteis.h"

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
    QNT_AVARIA = 0;
}

Maquina::~Maquina()
{
    //dtor
}

void Maquina::Show(ostream &saida)
{
    saida << "ID: " << ID__ << endl;
    saida << "PROB_GANHAR: " << PROB_GANHAR << endl;
    saida << "PREMIO: " << PREMIO << endl;
    saida << "posX: " << posX << endl;
    saida << "posY: " << posY << endl;
    saida << "TEMP: " << TEMPERATURA << endl;
    saida << "TIPO: "<< TIPO << endl;
    saida << "QNT_AVARIAS: " << QNT_AVARIA << endl << endl;
}

void Maquina::Jogar(){
    int tempoJogo; //Tempo de jogo em minutos
    tempoJogo = AleatorioINT(5,50);
    U->Set_TempoJogo(U->Get_TempoJogo()+tempoJogo);
}