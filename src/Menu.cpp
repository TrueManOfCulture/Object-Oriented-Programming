#include "../include/Menu.h"

#include "../include/Casino.h"

//////////////    MENU    //////////////

void Menu(Casino *C,bool &parar, ostream &f){

        int b;

        cout << "--- MENU ---" << endl;
        cout << "1. Listar o estado atual do Casino" << endl;
        cout << "2. Funções das Máquinas" << endl;
        cout << "3. Funções dos Users" << endl;
        cout << "4. Calcular a memória total " << endl;
        cout << "5. Parar Simulação " << endl;
        cout << "0. Sair do Menu" << endl;
        cout << endl
                <<"Opção: ";
        cin >> b;

        switch (b) {
                case 1:
                        cout << endl;
                        C->Listar(f);
                        cout << endl;
                        break;

                case 2:
                        op_2(C, f);
                        break;

                case 3:
                        op_3(C, f);
                        break;

                case 4:
                        cout << endl;
                        f << "Memória do Casino: " << C->MemoriaCasino() << endl;
                        cout << endl;
                        break;

                case 5:
                        exit(0);
                        break;

                case 0:
                        break;

                default:
                        cout << "Escolha uma opção válida" << endl;
                        break;
        }
} 

//////////////    MENU MAQUINAS   //////////////

void op_2(Casino *C, ostream &f){

        int b, ID;

        cout << endl
             << "--- Funções das Máquinas ---" << endl;
        cout << "1. Adicionar uma Máquina" << endl;
        cout << "2. Remover uma Máquina" << endl;
        cout << "3. Saber o estado de uma Máquina (com ID)" << endl;
        cout << "4. Alterar a probabilidade de uma Máquina (com ID)  " << endl;
        cout << "5. Pesquisar Máquina (com ID)" << endl;
        cout << "6. Listar Máquinas de um dado tipo" << endl;
        cout << "7. Listar Máquinas que mais avariam" << endl;
        cout << "8. Listar Máquinas mais usadas" << endl;
        cout << "9. Voltar atrás" << endl;
        cout << endl
                <<"Opção: ";
        cin >> b;

        switch (b)
        {
        case 1:
                /* code */
                break;

        case 2:
                /* code */
                break;

        case 3:
                cout << endl;
                cout << "ID: ";
                cin >> ID;
                break;

        case 4:
                cout << endl;
                cout << "ID: ";
                cin >> ID;
                break;

        case 5:
                cout << endl;
                cout << "ID: ";
                cin >> ID;
                C->PesqMaq(ID, f);
                break;

        case 6:
                /* code */
                break;

        case 7:
                /* code */
                break;
        
        case 8:
                /* code */
                break;

        case 9:
                cout << endl;
                bool x = true;
                Menu(C, x);
                cout << endl; 
                break;
        
        default:
                cout << "Escolha uma opção válida" << endl;
                break;
        }
}

//////////////    MENU USERS    //////////////

void op_3(Casino *C, ostream &f){

        int b;
        string ID;

        cout << endl
             << "--- Funções dos Users ---" << endl;
        cout << "1. Listar Users que passaram mais tempo no Casino" << endl;
        cout << "2. Listar Users que mais prémios ganharam" << endl;
        cout << "3. Pesquisar User (com ID)" << endl;
        cout << "4. Voltar atrás" << endl;
        cout << endl
                <<"Opção: ";
        cin >> b;

        switch (b)
        {
        case 1:
                /* code */
                break;

        case 2:
                /* code */
                break;

        case 3:

                cout << endl;
                cout << "ID: ";
                cin >> ID;
                C->PesqUser(ID, f);
                break;

        case 4:
                
                cout << endl;
                bool x = false;
                Menu(C,x);
                cout << endl;

                break;
                     
        default:

                break;

        }
}

