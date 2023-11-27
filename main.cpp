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
    setlocale(LC_ALL, "PORTUGUESE");

    Casino C("Solverde", 15, 27);

    list<User *> LU;
    C.Load("CasinoData.xml");

    LerFicheiroUser(LU, "USERS.txt");
    //cout << ObterConteudo("<TEMP_AVISO>70</TEMP_AVISO>")<<endl;

    for(list<User *>::iterator it = LU.begin(); it != LU.end(); ++it){
            cout << (*it)->Memoria() << endl;
            //(*it)->TAMANHO_NOME();
    }

    //C.Ass_ListaUsusarios(LU);

    //C.MemoriaCasino();

    
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
<<<<<<< HEAD
=======

    Maquina *Maq = new ClassicSlots(1, 1, 1, 1, 1, 1, "ClassicSlots");
    //Maq->Jogar();
>>>>>>> 6ec20a3b55737d9ed6a5139391acc538b6c63170
}