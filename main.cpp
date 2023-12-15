#include <iostream>
#include <string>
#include <locale>

using namespace std;

#include "./include/Casino.h"

int main()
{
    setlocale(LC_ALL, "PORTUGUESE");
    srand(time(0));

    list<User *> LU;
    LerFicheiroUser(LU, "USERS.txt");

    ifstream dadosCasino("CasinoData.xml");
    saltarNLinhas(dadosCasino, 2);
    string nomeCasino = ObterConteudo(dadosCasino);
    dadosCasino.close();
    Casino C(nomeCasino);
    C.Load("CasinoData.xml");
    C.Ass_ListaUsusarios(LU);

    C.Run(false);

    
}
