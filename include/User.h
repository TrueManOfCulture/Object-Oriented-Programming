#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class User
{
    string ID;
    string NOME;
    string CIDADE;
    int IDADE;
    int tempoDeJogo;
    int premioGanho=0;

    public:
        User(string _id, string _nome, string _cidade, int _idade);
        virtual ~User();

        void Show(ostream &saida = cout);                                // MOSTRA OS DADOS DO USER
        int Memoria(){ return sizeof(*this); }                           // CALCULA A MEMÓRIA OCUPADA
        int Get_IDADE(){ return IDADE; }                                 // RETORNA A IDADE
        string Get_ID(){ return ID; }                                    // RETORNA O ID
        void Inc_TempoJogo(int tempo){ tempoDeJogo += tempo; }
        int Get_TempoJogo(){ return tempoDeJogo; }
        void Inc_premioGanho(int premio){ premioGanho+=premio; };
        int Get_premioGanho(){ return premioGanho; }
        string Get_Nome(){return NOME;}
};

#endif // USER_H