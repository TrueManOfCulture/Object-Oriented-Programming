#ifndef CASINO_H
#define CASINO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

#include "User.h"
#include "Maquina.h"
#include "BlackJack.h"
#include "ClassicSlots.h"
#include "Roleta.h"
#include "Uteis.h"

class Casino
{
    list <User *> LU;
    list <User *> LU_Espera;
    list <Maquina *> LM;

    string NOME;
    int HORA_ABERTURA, HORA_FECHO;

    public:
        Casino(string _nome, int _horaA, int _horaF);
        virtual ~Casino();

        void Add(User *U);
        void Add(Maquina *M);
        string Get_Estado(int ID);

        list<Maquina *> *Listar_Tipo(string Tipo, ostream &saida = cout);

        int MemoriaCasino();

        /*
        bool Load(const string &ficheiro);
        void Listar(ostream &f = std::cout);
        void Desligar(int id_maq);
        int Memoria_Total();
        list<string> * Ranking_Dos_Fracos();
        list<Maquina *> * Ranking_Das_Mais_Trabalhadores();
        list<User *> *Jogadores_Mais_Frequentes();
        list<User *> *Jogadores_Mais_Ganhos();
        void Relatorio(string fich_xml);
        void SubirProbabilidadeVizinhas(Maquina *M_ganhou, float R, list<Maquina *> &lmvizinhas);
        void Listar(float X, ostream &f = std::cout);
        void Run(bool Debug = true);
        */
};

#endif // CASINO_H
