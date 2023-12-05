#include "../include/BlackJack.h"

BlackJack::BlackJack(float _prob_ganhar, float _prob_avaria,  int _premio, int _posX, int _posY, int _temp, string _tipo, User *U, ESTADO_MAQUINA _est)
    : Maquina(_prob_ganhar, _prob_avaria, _premio, _posX, _posY, _temp, _tipo, U, _est)
{
    cout << "Passei por " << __FUNCTION__<< endl;
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