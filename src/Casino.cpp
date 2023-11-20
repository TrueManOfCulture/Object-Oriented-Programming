#include "../include/Casino.h"

Casino::Casino(string _nome, int _horaA, int _horaF)
{
    NOME = _nome;
    HORA_ABERTURA = _horaA;
    HORA_FECHO = _horaF;
}

Casino::~Casino()
{
    //dtor
}

void Casino::Add(User *U)
{
    LU.push_back(U);
}

void Casino::Add(Maquina *M)
{
    LM.push_back(M);
}

list<Maquina *> *Casino::Listar_Tipo(string Tipo, ostream &saida)
{
    list<Maquina *> LM_Tipo;

    for(list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
        if(Tipo == (*it)->Get_TIPO())
        {
            LM_Tipo.push_back(*it);
            (*it)->Show(saida);
        }

    return NULL;
}

string Casino::Get_Estado(int ID)
{
    for(list <Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
        if(ID == (*it)->GET_ID())
            return (*it)->GET_ESTADO();

            return "deu merda guys";
}