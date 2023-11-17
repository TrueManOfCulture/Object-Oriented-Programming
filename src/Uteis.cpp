#include "../include/Uteis.h"

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

/*STRING *Read_Split_Line_File(FILE *f, int n_campos_max, int *n_campos_lidos, char *separadores)
{
    *n_campos_lidos = 0;
    if (!f) return NULL;
    if (fgets(LT , MAX_LINHA_FICHEIRO , f) != NULL)    
    {
        
        STRING *Res = (STRING *)malloc(n_campos_max*sizeof(STRING));  
        char *pch = strtok (LT, separadores);
        int cont = 0;
        while (pch != NULL)
        {
            Res[cont] = (char *)malloc((strlen(pch)+1)*sizeof(char)); 
            strcpy(Res[cont++], pch);
            pch = strtok (NULL, separadores);
        }
        *n_campos_lidos = cont;
        return Res;
    }
    return NULL;
}

void LerFicheiroUser(list<User *> &LU, string fic)
{
    int n_campos_max = 4;
    int n_campos_lidos;
    int n_linhas_lidas = 0;
    int i;
    int n=0;

    ifstream ficheiro(fic);

    if(!ficheiro.is_open()){
        cerr << "ERRO AO ABRIR O FICHEIRO [" << fic << "]!" << endl;
        exit(-1);
    }

    string linha;
    getline(ficheiro, linha);

    User *U;

    while(){
        STRING *V = Read_Split_Line_File(ficheiro, n_campos_max, &n_campos_lidos, "\t");

        int cod = atoi(V[0]), idade = atoi(V[3]);
        string nome = V[1], cidade = V[2];

        U = new User(cod, nome, cidade, idade);

        LU.push_back(U);
    }

    delete U;

    ficheiro.close();
}*/