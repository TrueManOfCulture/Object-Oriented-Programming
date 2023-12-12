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
    tempAviso = _temp;
    TIPO = _tipo;
    ESTADO = _est;
    PROB_AVARIA = _prob_avaria;
    QNT_AVARIA = 0;
    tempoDeJogo = 0;
    tempAtual = 20;
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
    saida << "TEMPATUAL: " << tempAtual << endl;
    saida << "TIPO: "<< TIPO << endl;
    saida << "QNT_AVARIAS: " << QNT_AVARIA << endl<< endl;
}

<<<<<<< HEAD
bool Maquina::Jogar(){
    int tempoJogo,probGanhar; //Tempo de jogo em minutos

    probGanhar = AleatorioINT(0,100);
    tempoJogo = AleatorioINT(5,50);
    U->Inc_TempoJogo(tempoJogo);
    Inc_Tempo_Jogo(tempoJogo);
    if(probGanhar<=PROB_GANHAR) {
        U->Inc_premioGanho(PREMIO);
        cout<<U->Get_Nome()<<" galhou "<<PREMIO<<"  euros" <<endl<<endl;
        return true;
    }
    ESTADO = OFF;
    cout<<U->Get_Nome()<<" jogou por "<<tempoJogo<<" minutos" <<endl<<endl;
    return false;
=======
void Maquina::Jogar(){
    int tempoJogo;

    tempoJogo = AleatorioINT(5,50);
    U->Set_TempoJogo(U->Get_TempoJogo()+tempoJogo);

    if(AleatorioINT(1, 100) <= PROB_GANHAR){
        U->Set_premioGanho(PREMIO);
    }
>>>>>>> fd64c97c3a19f040738181737350e5c364c6552c
}

void Maquina::Set_ESTADO(ESTADO_MAQUINA _est)
{
    if(_est == AVARIADA){
        ESTADO = _est;
        Inc_QNT_AVARIA();
    }
    else{
        ESTADO = _est;
    }
}

<<<<<<< HEAD
void Maquina::Aquecer(){ tempAtual += AleatorioINT(-2, 5); }
=======
void Maquina::Aquecer()
{
    TEMPERATURA += AleatorioINT(-2, 5);
}
>>>>>>> fd64c97c3a19f040738181737350e5c364c6552c
