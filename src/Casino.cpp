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
    int premio, x, y, tempoAviso;
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
        M->Dec_STATIC_ID();
        delete M;
        cout<<"Erro! Já existe uma máquina na posição: "<< key <<"!" << endl << endl;
        return false;
    }
    return true;
}


list<Maquina *> *Casino::Listar_Tipo(string Tipo, ostream &saida)
{
    list<Maquina *> *LM_Tipo = new list<Maquina *>;

    for(map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        if(Tipo == it->second->Get_TIPO())
        {
            LM_Tipo->push_back(it->second);
            (it->second)->Show(saida);
        }

    return LM_Tipo;
}

string Casino::Get_Estado(int ID)
{
    for(map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        if(ID == it->second->Get_ID())
            return EnumToString(it->second->Get_ESTADO());

    cout << endl << endl << "ERRO! NENHUMA MÁQUINA ENCONTRADA COM O ID " << ID << "!" << endl;
    return EnumToString(ERRO);
}

int Casino::MemoriaCasino()
{
    int TOTAL;
    int MEM_MAQ = 0, MEM_U = 0;

    cout << HashMaq.size();

    for(map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it){
        MEM_MAQ += it->second->Memoria();
    }

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
    for(map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        if(it->second->Get_PROB_GANHAR() > X)
            it->second->Show(saida);
}

void Casino::Desligar(int ID_MAQ)
{
    for(map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it){
        if(it->second->Get_ID() == ID_MAQ){
            it->second->Set_ESTADO(OFF);
        }
    }
}

void Casino::SubirProbabilidadeVizinhas(Maquina *M_ganhou, float raio, list<Maquina *> &LM_Vizinhas)
{
    for(map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it){
        float dist = CalcularDistancia(M_ganhou, it->second);
        if(raio >= dist)
        {
            if(dist == 0){
                continue;
            }
            else{
                LM_Vizinhas.push_back(it->second);
                it->second->Set_PROB_GANHAR(5);
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
    list<Maquina *> *Res = new list<Maquina *>;
    //list<Maquina *>::iterator ResIT = Res.begin();

    for(map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it){
        if(it->second->Get_QNT_AVARIA() > aux){
            Res->push_front(it->second);
            aux = it->second->Get_QNT_AVARIA();
        }
        /*else{
            for(list<Maquina* >::iterator it = Res.begin(); it != Res.end(); ++it){
                if((*it)->Get_QNT_AVARIA() > (*ResIT)->Get_QNT_AVARIA()){

                }
            }
        }*/
    }

    return Res;
}