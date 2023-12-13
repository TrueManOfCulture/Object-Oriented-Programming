#ifndef CASINO_H
#define CASINO_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <map>
#include <iterator>

using namespace std;

#include "User.h"
#include "Maquina.h"
#include "BlackJack.h"
#include "ClassicSlots.h"
#include "Roleta.h"
#include "Craps.h"
#include "XML.h"
#include "Relogio.h"
#include "Uteis.h"
#include "Menu.h"

class Casino
{
    list <User *> LU;
    list <User *> LU_Espera;
    list<User *> LU_Total;
    int maxUser;

    //map com posicoes de maquinas como chave e a maquina como valor
    map<string, Maquina *> HashMaq;

    //map com id como chave e usuario como valor
    map<string, User *> HashUser;
    list<Maquina *> LM_Total;
    

    string NOME;
    time_t HORA_ABERTURA, HORA_FECHO;

    public:
        Casino(string _nome);
        virtual ~Casino();

        bool Add(Maquina *M);                                                   // ADICIONAR MÁQUINAS À LISTA
        bool Add(User *U);                                                      // ADICIONAR USUÁRIOS À LISTA
        string Get_Estado(int ID);   
        int Qnt_Jog();

        list<Maquina *> *Listar_Tipo(string Tipo, ostream &saida = cout);       // LISTAR TODOS OS TIPOS DE MÁQUINA DADO UM TIPO
        void Desligar(int ID_MAQ);                                              // DESLIGAR UMA MÁQUINA DADO UM ID

        int MemoriaCasino();                                                    // CALCULAR A MEMÓRIA TOTAL DO CASINO

        void Listar_Sup_Prob_Ganhar(float X, ostream &saida = cout);            // LISTAR AS MÁQUINAS COM UM VALOR DE PROBABILIDADE DE GANHAR SUPERIOR AO DADO
        bool Load(const string &ficheiro);                                      // CARREGAR O FICHEIRO XML

        void SubirProbabilidadeVizinhas(Maquina *M_ganhou, float raio, list<Maquina *> &LM_Vizinhas);
        

        time_t getHoraAbertura(){ return HORA_ABERTURA;};
        time_t getHoraFecho(){return HORA_FECHO;};
        void Run(bool Debug = true);
        void Listar(ostream &f=cout);

        list<User *> *Jogadores_Mais_Ganhos();
        list<User *> *Jogadores_Mais_Frequentes();
        list<Maquina *> *Ranking_Das_Mais_Trabalhadores();
        void Set_ProbMaquina();
        void alterarProb(int id, int prob);

        list<Maquina *> *Ranking_Dos_Fracos();
        
        /*
            void Relatorio(string fich_xml);
        */

        // FUNÇÕES PARA TESTES  [ TEMPORÁRIAS ]
        map<string, Maquina *> Ass_HashMaq(){ return HashMaq; }
        map<string, User *> Ass_HashUser(){ return HashUser; }
        void Ass_ListaUsusarios(list<User *> &_LU){ LU = _LU; }                 // ASSOCIAR A LISTA DE USUÁRIO DO CASINO A UMA LISTA DADA

        void OP_ListMaquina(ostream &f = cout);
        void PesqMaq(int _ID, ostream &f = cout);
        void OP_ListUser(ostream &f = cout);
        void PesqUser(string _ID, ostream &f = cout);
};

#endif // CASINO_H
