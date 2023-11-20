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

ESTADO_MAQUINA Casino::Get_Estado(int ID)
{
    for(list <Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
        if(ID == (*it)->GET_ID())
            return (*it)->GET_ESTADO();

    cout << endl << endl << "ERRO! NENHUMA MÁQUINA ENCONTRADA COM O ID " << ID << "!" << endl;
    return ERRO;
}

int Casino::MemoriaCasino()
{
    int TOTAL;
    int MEM_MAQ = 0, MEM_U = 0;

    for(list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
        MEM_MAQ += (*it)->Memoria();

    for(list<User *>::iterator it = LU.begin(); it != LU.end(); ++it)
        MEM_U += (*it)->Memoria();

    for(list<User *>::iterator it = LU_Espera.begin(); it != LU_Espera.end(); ++it)
        MEM_U += (*it)->Memoria();

    TOTAL = sizeof(*this) + MEM_MAQ + MEM_U;

    return TOTAL;
}