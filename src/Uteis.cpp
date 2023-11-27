#include "../include/Uteis.h"

LinhaTexto LT;

int AleatorioINT(int minN, int maxN)
{
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(minN, maxN);

    int random_number = distribution(generator);

    return random_number;
}

string AleatorioVECTOR_STRINGS(vector<string> L)
{
    random_device rd;
    default_random_engine generator(rd());

    uniform_int_distribution<int> distribution(0, L.size() - 1);
    int indiceAleatorio = distribution(generator);

    string elementoAleatorio = L[indiceAleatorio];

    return elementoAleatorio;
}

STRING *Read_Split_Line_File(ifstream &f, int n_campos_max, int &n_campos_lidos, const char *separadores)
{
    n_campos_lidos = 0;
    if (!f.is_open()) return NULL;
    f.getline(LT, MAX_LINHA_FICHEIRO);
    if (!f.eof())
    {
        STRING *Res = new STRING[n_campos_max];
        char *pch = strtok(LT, separadores);
        int cont = 0;
        while (pch != NULL)
        {
            Res[cont] = pch;
            ++cont;
            pch = strtok(NULL, separadores);
        }
        n_campos_lidos = cont;
        return Res;
    }
    return NULL;
}

void LerFicheiroUser(list<User *> &LU, string fic)
{
    int n_campos_max = 4;
    int n_campos_lidos;
    int n_linhas_lidas = 0;
    int n = 0;

    ifstream F1(fic);

    User *U;

    if (!F1.is_open())
    {
        cerr << "ERRO: Impossivel abrir ficheiro!" << endl;
        exit(1);
    }
    while (!F1.eof())
    {
        STRING *V = Read_Split_Line_File(F1, n_campos_max, n_campos_lidos, "\t\n\r");

        int IDADE;
        string COD, NOME, CIDADE;

        if (V != NULL)
        {
            COD = V[0];
            NOME = V[1];
            CIDADE = V[2];
            IDADE = atoi(V[3].c_str());

            U = new User(COD, NOME, CIDADE, IDADE);
            LU.push_back(U);
            
            ++n;

            delete[] V;
        }
    }

    F1.close();
}

//Para saltar um determinado numero de linhas num ficheiro
bool saltarNLinhas(ifstream &f, int nlinhas)
{
    for(int i = 0; i<nlinhas; i++){
        f.getline(LT, MAX_LINHA_FICHEIRO);
        if(f.eof())
            return false;
    }
    
    return true;
}