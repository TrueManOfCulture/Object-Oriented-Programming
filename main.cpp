#include <iostream>
#include <locale>
#include <string>
#include <list>
#include <fstream>

using namespace std;

#include "include/Maquina.h"
#include "include/ClassicSlots.h"
#include "include/BlackJack.h"
#include "include/Casino.h"
#include "include/Roleta.h"
#include "include/Uteis.h"

int main()
{
    setlocale(LC_ALL, "PORTUGUESE");

    Casino C("Solverde", 19, 27);


    list<User *> LU;

    LerFicheiroUser(LU, "USERS.txt");


    for(list<User *>::iterator it = LU.begin(); it != LU.end(); ++it){
        (*it)->Show();
    }


    /*Maquina *Maq = new BlackJack(1, 20, 100, 1, 1, 50);
    C.Add(Maq);
    Maq = new BlackJack(2, 20, 100, 1, 1, 50);
    C.Add(Maq);
    Maq = new BlackJack(3, 20, 100, 1, 1, 50);
    C.Add(Maq);
    Maq = new BlackJack(4, 20, 100, 1, 1, 50);
    C.Add(Maq);

    Maq = new Roleta(5, 20, 100, 1, 2, 50);
    C.Add(Maq);
    Maq = new Roleta(6, 20, 100, 1, 2, 50);
    C.Add(Maq);
    Maq = new Roleta(7, 20, 100, 1, 2, 50);
    C.Add(Maq);

    Maq = new ClassicSlots(8, 20, 100, 1, 2, 50);
    C.Add(Maq);
    Maq = new ClassicSlots(9, 20, 100, 1, 2, 50);
    C.Add(Maq);

    Maq = new Maquina(10, 20, 100, 1, 2, 50);
    C.Add(Maq);

    ofstream ficheiro("TESTE.txt");

    C.Listar_Tipo("BLACKJACK");

    ficheiro.close();*/
}
