#ifndef CASINO_H
#define CASINO_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <unordered_map>

using namespace std;

#include "User.h"
#include "Maquina.h"
#include "BlackJack.h"
#include "ClassicSlots.h"
#include "Roleta.h"
#include "Uteis.h"
#include "XML.h"

class Casino
{
    list <User *> LU;
    list <User *> LU_Espera;
    list <Maquina *> LM;
    int maxJog;
<<<<<<< HEAD
    unordered_map<string, Maquina *>HashMaq;
=======
    
>>>>>>> 6891137fee2868f4480f9bda4d8b31bf635b21ee

    string NOME;
    time_t HORA_ABERTURA, HORA_FECHO;

    public:
        Casino(string _nome);
        virtual ~Casino();

        void Ass_ListaUsusarios(list<User *> &_LU){ LU = _LU; }                 // ASSOCIAR A LISTA DE USUÁRIO DO CASINO A UMA LISTA DADA

        bool Add(User *U);                                                      // ADICIONAR USUÁRIOS À LISTA
        bool Add(Maquina *M);                                                   // ADICIONAR MÁQUINAS À LISTA
        string Get_Estado(int ID);                                              // RETORNAR O ESTADO DE UMA MÁQUINA DADO UM ID

        list<Maquina *> *Listar_Tipo(string Tipo, ostream &saida = cout); //INACABADO       // LISTAR TODOS OS TIPOS DE MÁQUINA DADO UM TIPO
        void Desligar(int ID_MAQ);                                              // DESLIGAR UMA MÁQUINA DADO UM ID

        int MemoriaCasino();                                                    // CALCULAR A MEMÓRIA TOTAL DO CASINO

        void Listar_Sup_Prob_Ganhar(float X, ostream &saida = cout);            // LISTAR AS MÁQUINAS COM UM VALOR DE PROBABILIDADE DE GANHAR SUPERIOR AO DADO
        bool Load(const string &ficheiro);                                      // CARREGAR O FICHEIRO XML

        void SubirProbabilidadeVizinhas(Maquina *M_ganhou, float raio, list<Maquina *> &LM_Vizinhas);

        void Prob_Avaria(Maquina *M);
        list<Maquina *> * Ranking_Dos_Fracos();
        /*
        list<string> * Ranking_Dos_Fracos();
        list<Maquina *> * Ranking_Das_Mais_Trabalhadores();
        list<User *> *Jogadores_Mais_Frequentes();
        list<User *> *Jogadores_Mais_Ganhos();
        void Relatorio(string fich_xml);
        
        void Run(bool Debug = true);
        */
};

#endif // CASINO_H
