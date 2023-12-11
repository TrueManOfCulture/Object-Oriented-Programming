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
    int premioGanho;

    public:
        User(string _id, string _nome, string _cidade, int _idade);
        virtual ~User();

        void Show();                                // MOSTRA OS DADOS DO USER
        int Memoria(){ return sizeof(*this); }      // CALCULA A MEMÓRIA OCUPADA
        int Get_IDADE(){ return IDADE; }            // RETORNA A IDADE
        string Get_ID(){ return ID; }               // RETORNA oO ID
        void Set_TempoJogo(int tempo){tempoDeJogo=tempo;}
        int Get_TempoJogo(){return tempoDeJogo;}
        void Set_premioGanho(int premio){premioGanho=premio;};
        int Get_premioGanho(){return premioGanho;}
};

#endif // USER_H
