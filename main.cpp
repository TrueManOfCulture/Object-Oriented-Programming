#include <iostream>
#include <locale>
#include <string>
#include <list>

using namespace std;

#include "Maquina.h"
#include "ClassicSlots.h"
#include "BlackJack.h"
#include "Casino.h"
#include "Roleta.h"

int main()
{
    setlocale(LC_ALL, "PORTUGUESE");

    Casino C("Solverde", 15, 27);
    Maquina *Maq = new BlackJack(1, 20, 100, 1, 1, 50);
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

    C.Listar_Tipo("BLACKJACK");
}
