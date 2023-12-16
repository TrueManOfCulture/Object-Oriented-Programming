#include "../include/Menu.h"

#include "../include/Casino.h"

//////////////    MENU    //////////////

bool Menu(Casino *C, ostream &f)
{
        int b;
        string relatorio;

        cout << "--- MENU ---" << endl;
        cout << "1. Listar o estado atual do Casino" << endl; 
        cout << "2. Funções das Máquinas" << endl;
        cout << "3. Funções dos Users" << endl;
        cout << "4. Calcular a memória total " << endl;
        cout << "5. Parar Simulação " << endl;
        cout << "6. Enviar Relatório dos estado das maquinas" << endl;
        cout << "0. Continuar simulação" << endl;
        cout << endl
                <<"Opção: ";
        cin >> b;

        switch (b) {
                case 0:
                        return false;
                case 1:
                        f << endl;
                        C->Listar(f);
                        f << endl;
                        break;

                case 2:
                        while(op_2(C, f));
                        break;

                case 3:
                        while(op_3(C, f));
                        break;

                case 4:
                        f << endl;
                        f << "Memória do Casino: " << C->MemoriaCasino() << endl;
                        f << endl;
                        break;

                case 5:
                        C->pararCasino();
                        return false;

                case 6:
                        cout<<"Para que ficheiro quer enviar o relatorio do estado atual do casino?(nomedoficheiro.xml): "<<endl;
                        cin >> relatorio;
                        C->Relatorio(relatorio);
                        break;
                default:
                        return false;
        }
        return true;
} 

//////////////    MENU MAQUINAS   //////////////

bool op_2(Casino *C, ostream &f){

        int b, ID, cont;
        string Tipo;
        list<Maquina *> *lista;

        cout << endl
             << "--- Funções das Máquinas ---" << endl;
        cout << "1.  Adicionar uma Máquina" << endl;
        cout << "2.  Remover uma Máquina (com ID)" << endl;
        cout << "3.  Saber o estado de uma Máquina (com ID)" << endl;
        cout << "4.  Alterar a probabilidade de uma Máquina (com ID)  " << endl;
        cout << "5.  Pesquisar Máquina (com ID)" << endl;
        cout << "6.  Listar Maquinas Atuais" << endl;
        cout << "7.  Listar Máquinas de um dado tipo" << endl;
        cout << "8.  Listar Máquinas ordenadas pela qauntidade de avarias" << endl;
        cout << "9.  Listar Máquinas ordenadas da mais usada para a menos usada" << endl;
        cout << "10. Listar Histórico de maquinas"<<endl;
        cout << "11. Listar máquinas que possuem uma probabilidade acima de um determinado valor" << endl;
        cout << "12. Jogar ClassicSlots" << endl;
        cout << "0.  Voltar atrás" << endl;
        cout << endl;
        b = getInt("Opção: ",0,11);

        switch (b)
        {
        case 0:
                return false;
                break;
        case 1:
                while(C->AddMaquina());
                break;

        case 2:
                C->RemoverMaquina();
                break;

        case 3:
                cout << "ID: "<< endl;
                cin >> ID;
                f<<C->Get_Estado(ID)<< endl;
                break;

        case 4:
                C->Set_ProbMaquina();
                cout << endl;
                
                break;

        case 5:
                cout << endl;
                cout << "ID: ";
                cin >> ID;
                C->PesqMaq(ID, f);
                cout << endl;
                break;

        case 6:
                C->ListarMaquinasAtuais(f);
                break;

        case 7:
                cout << "Escreva o Tipo {ClassicSlots, Roleta, BlackJack, Craps}: "<<endl;
                cin >> Tipo;
                lista = C->Listar_Tipo(Tipo, f);
                cout << endl;
                delete lista;
                break;

        case 8:
                lista = C->Ranking_Dos_Fracos();
                mostrarListaMaquina(*lista, f);
                cout << endl;
                delete lista;
                break;
        
        case 9:
                lista = C->Ranking_Das_Mais_Trabalhadores();
                mostrarListaMaquina(*lista, f);
                cout << endl;
                delete lista;
                break;

        case 10:
                C->ListarMaquinas(f);
                break;

        case 11:
                int p=getInt("Listar máquina acima de que probabilidade?",0,100);
                C->Listar(p,f);
                break;
        
        case 12:
                Maquina *CS = new ClassicSlots(10, 5, 100, 10, 10, 90, "ClassicSlots");
                CS->Jogar(false);
                delete CS;
        }
        return true;
}

//////////////    MENU USERS    //////////////

bool op_3(Casino *C, ostream &f){

        int b;
        string ID;
        list<User *> *lista;

        cout << endl << "--- Funções dos Users ---" << endl;
        cout << "1. Listar todos os Users"<< endl;
        cout << "2. Listar Users que passaram mais tempo no Casino" << endl;
        cout << "3. Listar Users que mais prémios ganharam" << endl;
        cout << "4. Pesquisar User (com ID)" << endl;
        cout << "5. Remover User (com ID)" << endl;
        cout << "6. Voltar atrás" << endl;
        cout << endl;
        b = getInt("Opção: ", 1, 6);

        switch (b)
        {
        case 1:
                cout << endl;
                C->ListarUsuariosAtuais(f);
                cout << endl;
                break;
        case 2: 
                cout << endl;
                lista = C->Jogadores_Mais_Frequentes();
                mostrarListaUtilizador((*lista),f);
                cout << endl;
                delete lista;
                break;

        case 3:
                cout << endl;
                lista = C->Jogadores_Mais_Ganhos();
                mostrarListaUtilizador((*lista),f);
                cout << endl;
                delete lista;
                break;

        case 4:
                cout << endl;
                cout << "ID: ";
                cin >> ID;
                cout << endl;
                C->PesqUser(ID, f);
                break;

        case 5:
                while(C->RemoverUser(f));
                break;
        case 6:
                return false;
                break;
                     
        default:
                cout<< "Introduza uma opção válida!" << endl;
                break;

        }
        return true;
}

