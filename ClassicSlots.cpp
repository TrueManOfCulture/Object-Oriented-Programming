#include "ClassicSlots.h"

ClassicSlots::ClassicSlots(int _id, int _prob_ganhar, int _premio, int _posX, int _posY, int _temp)
    : Maquina(_id, _prob_ganhar, _premio, _posX, _posY, _temp)
{

}

ClassicSlots::~ClassicSlots()
{

}

void ClassicSlots::Jogar()
{
    vector<string> L_Resultado = {"Banana", "Barra de Ouro", "Sino", "7"};
    string slot1, slot2, slot3;

    int Resultado = AleatorioINT(1, 100);

    if(Resultado <= Get_PROB_GANHAR()){ // SE RESULTADO FOR MENOR QUE PROB_GANHAR O USER GANHA
        string VENCER = AleatorioVECTOR_STRINGS(L_Resultado);
        slot1 = VENCER;
        slot2 = VENCER;
        slot3 = VENCER;

        //_sleep ADICIONA SUSPENSE
        //1000 = 1s
        cout << "Loading..." << endl;
        _sleep(1000);
        cout << slot1 << "  ";
        _sleep(1000);
        cout << slot2 << "  ";
        _sleep(2000);
        cout << slot3;

        if((slot1 == "7") && (slot2 == "7") && (slot3 == "7")) {
            cout << endl << "!!! JACKPOT !!!" << endl;
        }
        else{
            if((slot1 == slot2) && (slot2 == slot3)){
                cout << endl << "Ganhou" << endl;
            }
        }
    }
    else{
        do{ // GARANTE QUE OS 3 VALORES NÃO SEJAM IGUAIS MAS QUE AINDA POSSA HAVER DOIS VALORES IGUAIS E UM DIFERENTE
            slot1 = AleatorioVECTOR_STRINGS(L_Resultado);
            slot2 = AleatorioVECTOR_STRINGS(L_Resultado);
            slot3 = AleatorioVECTOR_STRINGS(L_Resultado);


        }while((slot1 == slot2) && (slot2 == slot3));

        cout << "Loading..." << endl;
        _sleep(1000);
        cout << slot1 << "  ";
        _sleep(1000);
        cout << slot2 << "  ";
        _sleep(2000);
        cout << slot3;

        cout << endl << "Perdeu" << endl;
    }
}
