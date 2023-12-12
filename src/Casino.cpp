#include "../include/Casino.h"

Casino::Casino(string _nome)
{
    NOME = _nome;
}

Casino::~Casino()
{
    
}

// recebe string hh:mm e passa a hora para o int hora e os minutos para a variável minuto
void horas(int &hora, int &minuto, string linha)
{
    char *cstr = new char[linha.length() + 1];
    strcpy(cstr, linha.c_str());
    linha = strtok(cstr, ":");
    hora = stoi(linha);
    minuto = stoi(strtok(NULL, ":"));
}

void inicializarDefCasino(ifstream &infoCasino, int &maxJog, time_t &HORA_ABERTURA, time_t &HORA_FECHO)
{
    int hora, minuto;
    maxJog = stoi(ObterConteudo(infoCasino));
    horas(hora, minuto, ObterConteudo(infoCasino));
    HORA_ABERTURA = convertToTime(hora, minuto);
    horas(hora, minuto, ObterConteudo(infoCasino));
    HORA_FECHO = convertToTime(hora, minuto);
}

Maquina *MaquinaTipo(float pGanhar, float pAvariar, int premio, int x, int y, int tempoAviso, string nome)
{
    Maquina *M;
    
    if (nome == "BlackJack")
        M = new BlackJack(pGanhar, pAvariar, premio, x, y, tempoAviso, nome);
    if (nome == "ClassicSlots")
        M = new ClassicSlots(pGanhar, pAvariar, premio, x, y, tempoAviso, nome);
    if (nome == "Roleta")
        M = new Roleta(pGanhar, pAvariar, premio, x, y, tempoAviso, nome);
    if(nome == "Craps")
        M = new Craps(pGanhar,pAvariar, premio,x,y,tempoAviso,nome);

    return M;
}

bool Casino::Load(const string &ficheiro)
{
    int premio, x, y, tempoAviso;
    string nome;
    float pGanhar, pAvariar;

    ifstream infoCasino(ficheiro);

    if (!infoCasino.is_open())
    {
        cout << "File not found" << endl;
        return false;
    }

    saltarNLinhas(infoCasino, 3);

    // Obter definicoes de casino
    inicializarDefCasino(infoCasino, maxUser, HORA_ABERTURA, HORA_FECHO);
    saltarNLinhas(infoCasino, 2);
    string tag = ObterTag(infoCasino);
    int a = 0;

    Maquina *M;

    while (tag == "MAQUINA")
    {
        nome = ObterConteudo(infoCasino);
        pGanhar = stof(ObterConteudo(infoCasino));
        pAvariar = stof(ObterConteudo(infoCasino));
        premio = stoi(ObterConteudo(infoCasino));
        x = stoi(ObterConteudo(infoCasino));
        y = stoi(ObterConteudo(infoCasino));
        tempoAviso = stoi(ObterConteudo(infoCasino));

        //(float _prob_ganhar, float _prob_avaria,  int _premio, int _posX, int _posY, int _temp)
        M = MaquinaTipo(pGanhar, pAvariar, premio, x, y, tempoAviso, nome);
        //M->Show();    PASSEI ESTE PARA O ADD
        Add(M);
        saltarNLinhas(infoCasino, 1);
        tag = ObterTag(infoCasino);
    }

    delete M; // É NECESSÁRIO ESTAR AQUI PORQUE NA FUNÇÃO MAQUINATIPO AS MÁQUINAS VAO SER CRIADAS DINAMICAMENTE COM new, E ENT É NECESSARIO APAGAR

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

    if (HashMaq.find(key) == HashMaq.end())
    {
        HashMaq[key] = M;
        M->Show();
    }
    else
    {
        M->Dec_STATIC_ID();
        cout << "Erro! Já existe uma máquina na posição: " << key << "!" << endl << endl;
        return false;
    }

    return true;
}

void Casino::Listar(ostream &f)
{
    /*cout<<"Maquinas No Casino"<<endl<<endl;

    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
    {
     it->second->Show(f);
    }

    cout<<"Users No Casino"<<endl<<endl;

    for (map<string, User *>::iterator it = HashUser.begin(); it != HashUser.end(); ++it)
    {
      it->second->Show(f);  
    }*/

    int a;

    cout << "--- MENU LISTAR ---" << endl;
    cout << "\t1- Lista Total" << endl;
    cout << "\t2- Lista Máquinas" << endl;
    cout << "\t3- Lista User" << endl;
    cout << endl << "Opção: ";
    cin >> a;

    switch (a)
    {
    case 1:
        cout << endl;
        for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
            it->second->Show(f);
        for (map<string, User *>::iterator it = HashUser.begin(); it != HashUser.end(); ++it)
            it->second->Show(f);
        break;

    case 2:
        OP_ListMaquina(f);
        break;

    case 3:
        OP_ListUser(f);
        break;
    
    default:
        cout << "Escolha uma opção válida" << endl;
        break;
    }

}

void Casino::OP_ListMaquina(ostream &f)
{
    int b, ID;
    string Tipo;

    cout << endl << "--- Listar Máquinas ---" << endl;
    cout << "\t1- Lista Total" << endl;
    cout << "\t2- Lista Máquinas por Tipo" << endl;
    cout << "\t3- Pesquisar Máquina por ID" << endl;
    cout << "\t0- Voltar" << endl;
    cout << endl << "Opção: ";
    cin >> b;

    switch (b)
    {
    case 1:
        for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
           it->second->Show(f);
        break;

    case 2:
        cout << "Tipo das Máquinas: ";
        cin >> Tipo;

        Listar_Tipo(Tipo, f);
        break;

    case 3:
        cout << "ID: ";
        cin >> ID;

        PesqMaq(ID, f);
        break;

    case 0:
        Listar(f);
        break;

    default:
        cout << "Escolha uma opção válida" << endl;
        break;
    }
}

void Casino::OP_ListUser(ostream &f)
{
    int b;
    string ID;

    cout << endl << "--- Listar Users ---" << endl;
    cout << "\t1- Lista Total" << endl;
    cout << "\t2- Pesquisar User por ID" << endl;
    cout << "\t0- Voltar" << endl;
    cout << endl << "Opção: ";
    cin >> b;

    switch (b)
    {
    case 1:
        for (map<string, User *>::iterator it = HashUser.begin(); it != HashUser.end(); ++it)
            it->second->Show(f);
        break;
    
    case 2:
        cout << "ID: ";
        cin >> ID;

        PesqUser(ID, f);
        break;

    case 0:
        Listar(f);
        break;

    default:
        cout << "Escolha uma opção válida" << endl;
        break;
    }
}

void Casino::PesqMaq(int _ID, ostream &f)
{
    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        if(_ID == it->second->Get_ID()){
            it->second->Show(f);
            break;
        }

    cout << "Nenhuma Máquina encontrada com o ID " << _ID << endl;
}

void Casino::PesqUser(string _ID, ostream &f)
{
    for (map<string, User *>::iterator it = HashUser.begin(); it != HashUser.end(); ++it)
        if(_ID == it->second->Get_ID()){
            it->second->Show(f);
            break;
        }

    cout << "Nenhum User encontrada com o ID " << _ID << endl;
}

/*
    - NO FINAL TAMBÉM SERÁ NECESSÁRIO APAGAR R UMA VEZ QUE É CRIADO DINAMICAMENTE, A NÃO SER QUE NUMA FUNÇÃO CHAMADA ISSO SEJA FEITO
    - SERÁ NECESSÁRIO FZR UMA PARTE PARA VERIFICAR SE A MÁQUINA NÃO ANTINGE A TEMPERATURA DE AVISO
    - N SE ESCOLHE UMA MÁQUINA ESPECIFICA PARA AVARIAR, TODAS AS MÁQUINAS SERÃO PERCORRIDAS E CADA MÁQUINA TEM A SUA PROBABILIDADE DE AVARIAR
        .. PROBABILIDADE DE AVARIAR TEM DE USAR A PROBABILIDADE DE AVARIA DA MÁQUINA
    
*/

void Casino::Run(bool debug) 
{
    Relogio *R = new Relogio(1000, HORA_ABERTURA);
    time_t horaAtual = R->VerTimeRelogio();
    int userEscolhido, prob, maquinaQueAvaria;


    while (difftime(horaAtual, HORA_FECHO) < 0)
    {
        /*if (kbhit){
            ch = getch();
            if(ch == 'M'|| ch == 'm'){
                menu();
            }
        }*/
        Listar();
        userEscolhido = AleatorioINT(0, LU.size() - 1);
        prob = AleatorioINT(1, 100);
        maquinaQueAvaria = AleatorioINT(0, HashMaq.size() - 1);
        //Colocar Usuários no Casino
        if (prob <= 5)
        {
            list<User *>::iterator userIt = LU.begin();
            advance(userIt, userEscolhido);
            Add(*userIt);
        }

        map<string,Maquina*>::iterator MaquinaIt = HashMaq.begin();
        advance(MaquinaIt, maquinaQueAvaria);

        if(prob >= 95){
            map<string,Maquina*>::iterator MaquinaIt = HashMaq.begin();
            advance(MaquinaIt, maquinaQueAvaria);
            MaquinaIt->second->Set_ESTADO(AVARIADA);
        }
        //Jogar  NA MINHA OPINIÃO MUDÁVA-SE O JOGAR() PARA JÁ FZR A VERIFICAÇÃO DE PROBABILIDADE
        for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        {
            if(it->second->Get_ESTADO() == ON)
            {
                it->second->Jogar();
            }
            if(it->second->Get_ESTADO() == OFF && !LU_Espera.empty()){
                it->second->Set_User(LU_Espera.front());
                LU_Espera.pop_front();
                it->second->Set_ESTADO(ON);
            }
        }

        horaAtual = R->VerTimeRelogio();
        R->Wait(2);
    }
}

list<Maquina *> *Casino::Listar_Tipo(string Tipo, ostream &saida)
{
    list<Maquina *> *LM_Tipo = new list<Maquina *>;

    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
    {
        if (Tipo == it->second->Get_TIPO())
        {
            LM_Tipo->push_back(it->second);
            it->second->Show(saida);
        }
    }

    return LM_Tipo;
}

string Casino::Get_Estado(int ID)
{
    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        if (ID == it->second->Get_ID())
            return EnumToString(it->second->Get_ESTADO());

    cout << endl << endl << "ERRO! NENHUMA MÁQUINA ENCONTRADA COM O ID " << ID << "!" << endl;
    return EnumToString(ERRO);
}

int Casino::Qnt_Jog()
{
    int num_jog = 0;

    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        if (it->second->Get_ESTADO() == ON)
            num_jog += 1;

    return num_jog;
}

bool Casino::Add(User *U)
{
    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
    { // percorrer as maquinas
        if (it->second->Get_ESTADO() != OFF)
        { // ver se as maquinas estao ON ou AVARIDAS (Ocupadas)

            if (HashUser.size() < maxUser)
            { // caso a fila não esteja cheia
                string key = U->Get_ID();

                if (HashUser.find(key) == HashUser.end())
                { // caso a fila não esteja cheia
                    HashUser[key] = U;
                    return true;
                }
                else
                {
                    cout << "Erro! Esse User já esta no casino, ID: " << key << "!" << endl << endl;
                    return false;
                }
            }
            else
            { // caso a fila esteja cheia
                cout << "Erro! O casino está cheio!" << endl << endl;
                return false;
            }
        }
        else
        { // Por a jogar
            it->second->Set_ESTADO(ON);
            it->second->Set_User(U);

            string key = U->Get_ID();
            HashUser[key] = U;
            return true;
        }
    }

    return false;
}

int Casino::MemoriaCasino()
{
    int TOTAL;
    int MEM_MAQ = 0, MEM_U = 0;

    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        MEM_MAQ += it->second->Memoria();
    
    for (list<User *>::iterator it = LU.begin(); it != LU.end(); ++it)
        MEM_U += (*it)->Memoria();

    for (list<User *>::iterator it = LU_Espera.begin(); it != LU_Espera.end(); ++it)
        MEM_U += (*it)->Memoria();
    
    for(map<string, User *>::iterator it = HashUser.begin(); it != HashUser.end(); ++it)
        MEM_U = it->second->Memoria();

    TOTAL = sizeof(*this) + MEM_MAQ + MEM_U;

    cout << endl << "MÁQ: " << MEM_MAQ << endl << "U: " << MEM_U << endl << endl << "TOTAL: " << TOTAL;

    return TOTAL;
}

void Casino::Listar_Sup_Prob_Ganhar(float X, ostream &saida)
{
    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        if (it->second->Get_PROB_GANHAR() > X)
            it->second->Show(saida);
}

void Casino::Desligar(int ID_MAQ)
{
    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        if (it->second->Get_ID() == ID_MAQ)
            it->second->Set_ESTADO(OFF);
}

void Casino::SubirProbabilidadeVizinhas(Maquina *M_ganhou, float raio, list<Maquina *> &LM_Vizinhas)
{
    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
    {
        float dist = CalcularDistancia(M_ganhou, it->second);
        if (raio >= dist)
        {
            if (dist == 0)
            {
                continue;
            }
            else
            {
                LM_Vizinhas.push_back(it->second);
                it->second->Set_PROB_GANHAR(5);
            }
        }
    }
}

list<Maquina *> *Casino::Ranking_Dos_Fracos()
{
    int aux = -1;
    list<Maquina *> *Res = new list<Maquina *>;

    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
    {
        if (it->second->Get_QNT_AVARIA() >= aux)
        {
            Res->push_front(it->second);
            aux = it->second->Get_QNT_AVARIA();
        }
        else
        {
            list<Maquina *>::iterator it_Res = Res->begin();
            while (it_Res != Res->end() && (*it_Res)->Get_QNT_AVARIA() >= it->second->Get_QNT_AVARIA())
            {
                ++it_Res;
            }

            if (it_Res == Res->end())
            {
                Res->push_back(it->second);
            }
            else
            {
                Res->insert(it_Res, it->second);
            }
        }
    }

    return Res;
}

list<User *> *Casino::Jogadores_Mais_Ganhos()
{
    int aux = -1;
    list<User *> *Res = new list<User *>;

    for(map<string, User *>::iterator it = HashUser.begin(); it != HashUser.end(); ++it)
    {
        if (it->second->Get_premioGanho() >= aux)
        {
            Res->push_front(it->second);
            aux = it->second->Get_premioGanho();
        }
        else
        {
            list<User *>::iterator it_Res = Res->begin();
            while (it_Res != Res->end() && (*it_Res)->Get_premioGanho() >= it->second->Get_premioGanho())
            {
                ++it_Res;
            }

            if (it_Res == Res->end())
            {
                Res->push_back(it->second);
            }
            else
            {
                Res->insert(it_Res, it->second);
            }
        }
    }

    return Res;
}