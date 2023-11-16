#include "../include/BlackJack.h"

BlackJack::BlackJack(int _id, int _prob_ganhar, int _premio, int _posX, int _posY, int _temp)
    : Maquina(_id, _prob_ganhar, _premio, _posX, _posY, _temp)
{
    //ctor
}

BlackJack::~BlackJack()
{
    //dtor
}

void BlackJack::Jogar()
{
    /*vector<string> L_Resultado = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Rainha", "Rei", "Valete", "�s"};
    while(1){
        if(_kbhit()){
            char ch = _getch();
            cout << "Pressed key: " << ch << endl;

            if(ch == 'M' || ch == 'm'){
                cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;


            }
        }
    }*/
}
