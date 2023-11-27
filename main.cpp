#include <iostream>
#include <locale>
#include <string>
#include <list>
#include <fstream>

using namespace std;

#include "./include/Maquina.h"
#include "./include/ClassicSlots.h"
#include "./include/BlackJack.h"
#include "./include/Casino.h"
#include "./include/Roleta.h"
#include "./include/Uteis.h"
#include "./include/User.h"
#include "./include/XML.h"

int main()
{
    /*ifstream dadosCasino("CasinoData.xml");
    setlocale(LC_ALL, "PORTUGUESE");
    saltarNLinhas(dadosCasino, 2);
    string nomeCasino = ObterConteudo(dadosCasino);

    Casino C(nomeCasino);

    C.Load("CasinoData.xml");*/

    //cout << ObterConteudo("<TEMP_AVISO>70</TEMP_AVISO>")<<endl;
<<<<<<< HEAD
    /*for(list<User *>::iterator it = LU.begin(); it != LU.end(); ++it){
            cout << (*it)->Memoria() << endl;
            (*it)->TAMANHO_NOME();
    }*/

    //C.Ass_ListaUsusarios(LU);

    //C.MemoriaCasino();

    
=======

>>>>>>> e6adf915262ebab1df3eba12a3e28b7e7019389c
    /*Maquina *Maq = new BlackJack(1, 1, 1, 1, 1, 1, "BlackJack");
    C.Add(Maq);
    Maq = new BlackJack(1, 1, 1, 1, 1, 1, "BlackJack");
    C.Add(Maq);
    Maq = new BlackJack(1, 1, 1, 1, 1, 1, "BlackJack");
    C.Add(Maq);
    Maq = new BlackJack(1, 1, 1, 1, 1, 1, "BlackJack");
    C.Add(Maq);

    Maq = new Roleta(1, 1, 1, 1, 1, 1, "Roleta");
    C.Add(Maq);
    Maq = new Roleta(1, 1, 1, 1, 1, 1, "Roleta");
    C.Add(Maq);
    Maq = new Roleta(1, 1, 1, 1, 1, 1, "Roleta");
    C.Add(Maq);

    Maq = new ClassicSlots(1, 1, 1, 1, 1, 1, "ClassicSlots");
    C.Add(Maq);
    Maq = new ClassicSlots(1, 1, 1, 1, 1, 1, "ClassicSlots");
    C.Add(Maq);

    Maq = new Maquina(1, 1, 1, 1, 1, 1, "Maquina");
    C.Add(Maq);

    ofstream ficheiro("TESTE.txt");

    C.Listar_Tipo("BLACKJACK");

    ficheiro.close();*/

    /*Maquina *Maq = new ClassicSlots(5, 50, 1, 1, 70, "Classic Slots", NULL, ON);
    C.Add(Maq);
    //Maq->Jogar();

    cout << C.Get_Estado(12) << endl;

    C.Desligar(12);

    cout << C.Get_Estado(12) << endl;*/


    //TESTAR SIZEOF DE CADA ELEMENTO EM MAQUINA

    Casino C("Solverde");

    list<User *> LU;
    LerFicheiroUser(LU, "USERS.txt");
    C.Ass_ListaUsusarios(LU);

    Maquina *Maq = new ClassicSlots(5, 50, 1, 1, 70, "CLASSIC SLOTS", NULL, ON);
    C.Add(Maq);
    Maq = new ClassicSlots(5, 50, 1, 1, 70, "CLASSIC SLOTS", NULL, ON);
    C.Add(Maq);
    Maq = new ClassicSlots(5, 50, 1, 1, 70, "CLASSIC SLOTS", NULL, ON);
    C.Add(Maq);

    C.MemoriaCasino();
}