#include "../include/Uteis.h"

LinhaTexto LT;

int AleatorioINT(int minN, int maxN)
{
    if ((maxN - minN + 1) == 0) {
        return -1;
    }
    return minN + rand()%(maxN-minN+1);
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

int getInt(string pergunta, int menor,int maior){
	int num;
	cout<< pergunta<<endl;
    do{
        cout<<pergunta<<"("<<menor<<"-"<<maior<<")"<<endl;
		cin >> num;
		if(num<menor ||num>maior){
			printf("Input invalido, por favor volte a introduzir");
		}
	}while(num<menor ||num>maior);
    fflush(stdin);
    return num;
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

time_t convertToTime(int hora, int minutos){
	time_t x = time(0);
	struct tm *tmp = localtime(&x);
	tmp->tm_hour = hora;
	tmp->tm_min = minutos;
	time_t tempo = mktime(tmp);
	return tempo;
}

//Mostrar uma lista de maquinas num ostream
void mostrarListaMaquina(list<Maquina *> maquinas,ostream &f){
    for (list<Maquina *>::iterator it = maquinas.begin(); it != maquinas.end(); ++it)
        (*it)->Show(f);
    
}

//Mostrar uma lista de utilizadores num ostream
void mostrarListaUtilizador(list<User *> users,ostream &f=cout){
    for (list<User *>::iterator it = users.begin(); it != users.end(); ++it)
        (*it)->Show(f);
}

string EnumToString(ESTADO_MAQUINA _est)
{
    switch (_est)
    {
    case 0:
        return "OFF";
        break;

    case 1:
        return "ON";
        break;

    case 2:
        return "AVARIADA";
        break;

    case 3:
        return "ERRO";
        break;
    
    default:
        return "ESTADO NÃO ENCONTRADO!";
        break;
    }
}

float CalcularDistancia(Maquina *M1, Maquina *M2)
{
    float calc1 = abs((M2->Get_POSX() - M1->Get_POSX())*(M2->Get_POSX() - M1->Get_POSX()));
    float calc2 = abs((M2->Get_POSY() - M1->Get_POSY())*(M2->Get_POSY() - M1->Get_POSY()));
    
    return sqrt(calc1+calc2);   
}