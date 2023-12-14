#include <iostream>
#include <string>
#include <locale>

using namespace std;

#include "./include/Casino.h"
#include "./include/User.h"
#include "./include/BlackJack.h"
#include "./include/ClassicSlots.h"
#include "./include/Maquina.h"
#include "./include/Relogio.h"
#include "./include/Roleta.h"
#include "./include/User.h"
#include "./include/Uteis.h"
#include "./include/XML.h"
#include "./include/Craps.h"

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

    C.Run();

    
}
