#ifndef CASINO_H
#define CASINO_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>

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
    time_t HORA_ABERTURA, HORA_FECHO;

    public:
        Casino(string _nome);
        virtual ~Casino();

        void Ass_ListaUsusarios(list<User *> &_LU){ LU = _LU; }

        void Add(User *U);
        void Add(Maquina *M);
        ESTADO_MAQUINA Get_Estado(int ID);

        list<Maquina *> *Listar_Tipo(string Tipo, ostream &saida = cout);
        void Desligar(int ID_MAQ);

        int MemoriaCasino();

        void Listar(float X, ostream &saida = std::cout);
        bool Load(const string &ficheiro);
        /*
        
        void Listar(ostream &f = std::cout);
        int Memoria_Total(); - EM FASE DE TESTES
        list<string> * Ranking_Dos_Fracos();
        list<Maquina *> * Ranking_Das_Mais_Trabalhadores();
        list<User *> *Jogadores_Mais_Frequentes();
        list<User *> *Jogadores_Mais_Ganhos();
        void Relatorio(string fich_xml);
        void SubirProbabilidadeVizinhas(Maquina *M_ganhou, float R, list<Maquina *> &lmvizinhas);
        void Run(bool Debug = true);
        */
};

#endif // CASINO_H
