#include "../include/Casino.h"

Casino::Casino(string _nome)
{
    NOME = _nome;
}

Casino::~Casino()
{
    //dtor
}

bool Casino::Load(const string &ficheiro)
{
    ifstream infoCasino(ficheiro);

    if (!infoCasino.is_open()){
        cout<<"File not found"<<endl;
        return false;
    } 

    int n_campos_lidos;
    saltarNLinhas(infoCasino,2);
    STRING *V = Read_Split_Line_File(infoCasino, 10, n_campos_lidos, "<>");

    cout << V[2] << endl;
    cout << "Numero de elementos: " << n_campos_lidos << endl;

    return true;
}

void Casino::Add(User *U)
{
    LU.push_back(U);
}

void Casino::Add(Maquina *M)
{
    LM.push_back(M);
}

list<Maquina *> *Casino::Listar_Tipo(string Tipo, ostream &saida)
{
    list<Maquina *> LM_Tipo;

    for(list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
        if(Tipo == (*it)->Get_TIPO())
        {
            LM_Tipo.push_back(*it);
            (*it)->Show(saida);
        }


    return NULL; // RETORNA NULL CASO NÃO ENCONTRE
}

string Casino::Get_Estado(int ID)
{
    for(list <Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
        if(ID == (*it)->Get_ID())
            return EnumToString((*it)->Get_ESTADO());

    cout << endl << endl << "ERRO! NENHUMA MÁQUINA ENCONTRADA COM O ID " << ID << "!" << endl;
    return EnumToString(ERRO);
}

int Casino::MemoriaCasino()
{
    int TOTAL;
    int MEM_MAQ = 0, MEM_U = 0;

    for(list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
        MEM_MAQ += (*it)->Memoria();

    for(list<User *>::iterator it = LU.begin(); it != LU.end(); ++it)
        MEM_U += (*it)->Memoria();

    for(list<User *>::iterator it = LU_Espera.begin(); it != LU_Espera.end(); ++it)
        MEM_U += (*it)->Memoria();

    TOTAL = sizeof(*this) + MEM_MAQ + MEM_U;

    cout << endl << "MÁQ: " << MEM_MAQ << endl << "U: " << MEM_U << endl << endl << "TOTAL: " << TOTAL;

    return TOTAL;
}

void Casino::Listar_Sup_Prob_Ganhar(float X, ostream &saida = std::cout)
{
    for(list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it)
        if((*it)->Get_PROB_GANHAR() > X)
            (*it)->Show(saida);
}

void Casino::Desligar(int ID_MAQ)
{
    for(list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it){
        if((*it)->Get_ID() == ID_MAQ){
            (*it)->Set_ESTADO(OFF);
        }
    }
}