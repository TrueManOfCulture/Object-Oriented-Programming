#include "../include/Casino.h"


Casino::Casino(string _nome)
{
    NOME = _nome;
}

Casino::~Casino()
{
    //dtor
}

//recebe string hh:mm e passa a hora para o int hora e os minutos para a variável minuto
void horas(int &hora, int &minuto,string linha){
    char * cstr = new char [linha.length()+1];
    strcpy (cstr, linha.c_str());
    linha = strtok(cstr,":");
    hora = stoi(linha);
    minuto = stoi(strtok(NULL,":"));
}

void inicializarDefCasino(ifstream &infoCasino, int &maxJog, time_t &HORA_ABERTURA,time_t &HORA_FECHO){
    int hora,minuto;
    maxJog = stoi(ObterConteudo(infoCasino));
    horas(hora,minuto, ObterConteudo(infoCasino));
    HORA_ABERTURA = convertToTime(hora,minuto);
    horas(hora,minuto, ObterConteudo(infoCasino));
    HORA_FECHO = convertToTime(hora,minuto);
}

bool Casino::Load(const string &ficheiro)
{
    int premio,x,y,tempoAviso;
    string nome;
    float pGanhar, pAvariar;

    ifstream infoCasino(ficheiro);

    if (!infoCasino.is_open()){
        cout<<"File not found"<<endl;
        return false;
    } 

    saltarNLinhas(infoCasino,3);

    //Obter definicoes de casino
    inicializarDefCasino(infoCasino,maxJog,HORA_ABERTURA,HORA_FECHO);
    saltarNLinhas(infoCasino, 2);
    string tag = ObterTag(infoCasino);
    int a=0;
    while(tag=="MAQUINA"){
        nome = ObterConteudo(infoCasino);
        pGanhar = stof(ObterConteudo(infoCasino));
        pAvariar = stof(ObterConteudo(infoCasino));
        premio = stoi(ObterConteudo(infoCasino));
        x = stoi(ObterConteudo(infoCasino));;
        y = stoi(ObterConteudo(infoCasino));
        tempoAviso = stoi(ObterConteudo(infoCasino));

        //(float _prob_ganhar, float _prob_avaria,  int _premio, int _posX, int _posY, int _temp)
        Maquina *M = new Maquina(pGanhar,pAvariar, premio,x,y,tempoAviso,nome);
        M->Show();
        Add(M);
        saltarNLinhas(infoCasino,1);
        tag = ObterTag(infoCasino);
    }
    return true;
}

bool Casino::Add(User *U)
{
    LU.push_back(U);

    return true;
}

string criarKey(Maquina *M) // junta as coordenasdas da maquina numa key x,y
{
    int x = M->Get_POSX(), y = M->Get_POSY();

    string key = to_string(x) + "," + to_string(y);

    return key;
}


bool Casino::Add(Maquina *M)
{
 
 string key = criarKey(M);

    if(HashMaq.find(key) == HashMaq.end()){

        HashMaq[key] = M;
    } else {
        cout<<"Erro! Já existe uma máquina na posição: "<< key <<"!" << endl << endl;
        return false;
    }
    return true;
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

void Casino::Listar_Sup_Prob_Ganhar(float X, ostream &saida)
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

void Casino::SubirProbabilidadeVizinhas(Maquina *M_ganhou, float raio, list<Maquina *> &LM_Vizinhas)
{
    for(list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it){
        float dist = CalcularDistancia(M_ganhou, (*it));
        if(raio >= dist)
        {
            if(dist == 0){
                continue;
            }
            else{
                LM_Vizinhas.push_back(*it);
                (*it)->Set_PROB_GANHAR(5);
            }
        }
    }
}

void Prob_Avaria(Maquina *M)
{
    if(M->Get_PROB_AVARIA() >= AleatorioINT(1, 100)){
        M->Set_ESTADO(AVARIADA);
        M->Inc_QNT_AVARIA();
    }
}

list<Maquina *> *Casino::Ranking_Dos_Fracos()
{
    int aux = -1;
    list<Maquina *> Res;

    for(list<Maquina *>::iterator it = LM.begin(); it != LM.end(); ++it){
        if((*it)->Get_QNT_AVARIA() > aux)
            Res.push_back(*it); //INACABADO
    }
}