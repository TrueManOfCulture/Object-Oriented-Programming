#include "../include/Casino.h"

Casino::Casino(string _nome)
{
    NOME = _nome;
    qtMaqAv = 0;
    parar = false;
}

Casino::~Casino()
{
    Relatorio("relatorio.xml");

    for (list<User *>::iterator it = LU.begin(); it != LU.end(); ++it)
        delete (*it);

    for (list<Maquina *>::iterator it = LM_Total.begin(); it != LM_Total.end(); ++it)
        delete (*it);

    cout << "PASSEI EM [" << __FUNCTION__ << "] E TUDO APAGADO!" << endl;
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
    if (nome == "Craps")
        M = new Craps(pGanhar, pAvariar, premio, x, y, tempoAviso, nome);

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

        M = MaquinaTipo(pGanhar, pAvariar, premio, x, y, tempoAviso, nome);
        Add(M);
        saltarNLinhas(infoCasino, 1);
        tag = ObterTag(infoCasino);
    }

    return true;
}

string criarKey(Maquina *M) // junta as coordenasdas da maquina numa key x,y
{
    int x = M->Get_POSX(), y = M->Get_POSY();

    string key = to_string(x) + "," + to_string(y);

    return key;
}

void Casino::Set_ProbMaquina()
{
    int id , prob;
    bool encontrado = false;
    map<string, Maquina *>::iterator it;
    while (!encontrado)
    {
        id = getInt("Qual e o id da maquina cuja a probabilidade quer alterar?", 1, 1000);
        for (it = HashMaq.begin(); it != HashMaq.end(); it++)
        {
            if (it->second->Get_ID() == id){
                encontrado = true;
                break;
            } 
        }
        if (!encontrado){
            cout << "Maquina nao encontrada, volte a introduzir" << endl;
        }
    }
    prob = getInt("Qual e a probabilidade da maquina cuja a probabilidade quer alterar?", 0, 100);
    alterarProb(it->second, prob);
}

void Casino::alterarProb(Maquina *M, int prob)
{
    HashMaq[criarKey(M)]->Set_Prob_Maquina(prob);
}

bool Casino::Add(Maquina *M)
{
    string key = criarKey(M);

    if (HashMaq.find(key) == HashMaq.end())
    {
        HashMaq[key] = M;
        LM_Total.push_back(M);
    }
    else
    {
        cout << "Erro! Já existe uma máquina na posição: " << key << "!" << endl << endl;
        return false;
    }

    return true;
}

bool Casino::AddMaquina()
{
    string nome;
    int posX, posY, tempAviso, premio;
    float probAv, probGanhar;
    cout << "Qual e o nome da maquina que quer adicionar: " << endl;
    cin >> nome;
    posX = getInt("Qual é a coordenada x da maquina?: ", 1, 10000);
    posY = getInt("Qual é a coordenada y da maquina?: ", 1, 10000);
    premio = getInt("Qual é o premio da máquina?", 1, 1000000);
    tempAviso = getInt("Qual é a temperatura de aviso da maquina?: ", 1, 10000);
    probAv = getInt("Qual é a probabilidade de avaria da maquina em percentagem?: ", 1, 100);
    probGanhar = getInt("Qual é a probabilidade de ganhar da maquina em percentagem?: ", 0, 100);
    Maquina *M = MaquinaTipo(probGanhar, probAv, premio, posX, posY, tempAviso, nome);
    return !Add(M);
}

bool Casino::RemoverMaquina()
{
    int id;
    bool encontrado = false;
    map<string, Maquina *>::iterator it;
    while (!encontrado)
    {
        id = getInt("Qual e o id da maquina que quer remover?", 1, 100000);
        for (it = HashMaq.begin(); it != HashMaq.end(); it++)
        {
            if (it->second->Get_ID() == id){
                encontrado = true;
                HashMaq.erase(it);
                return false;
            } 
        }
        if (!encontrado){
            cout << "Maquina nao encontrada, volte a introduzir" << endl;
        }
    }
    return true;
}

void Casino::Listar(ostream &f)
{
    int emUso = HashUser.size() - LU_Espera.size();
    cout << "Numero de Pessoas no Casino: " << HashUser.size() << endl;
    cout << "Numero de Pessoas a jogar: " << emUso << endl;
    cout << "Numero de Pessoas na Lista de Espera: " << LU_Espera.size() << endl;
    cout << "Numero de Maquinas no Casino: " << HashMaq.size() << endl;
    cout << "Numero de Maquinas em Uso: " << emUso << endl;
    cout << "Numero de Maquinas Avariadas: " << qtMaqAv << endl;
    cout << "Numero de Maquinas Disponíveis: " << HashMaq.size() - emUso << endl;
}

void Casino::ListarUsuariosAtuais(ostream &f)
{
    f << "Lista de Usuarios" << endl;
    for (list<User *>::iterator it = LU_Total.begin(); it != LU_Total.end(); ++it)
        (*it)->Show(f);
}

void Casino::ListarUsuarios(ostream &f)
{
    f << "Lista de Usuarios" << endl;
    for (map<string, User *>::iterator it = HashUser.begin(); it != HashUser.end(); ++it)
        it->second->Show(f);
}

void Casino::ListarMaquinasAtuais(ostream &f)
{
    f << "Lista de Máquinas" << endl;
    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        it->second->Show(f);
}

void Casino::ListarMaquinas(ostream &f)
{
    f << "Lista de Máquinas" << endl;
    mostrarListaMaquina(LM_Total, f);
}

bool Casino::PesqMaq(int _ID, ostream &f)
{
    for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        if (_ID == it->second->Get_ID())
        {
            it->second->Show(f);
            return true;
        }

    f << "Nenhuma Máquina encontrada com o ID " << _ID << endl;
    return false;
}

bool Casino::PesqUser(string _ID, ostream &f)
{
    for (map<string, User *>::iterator it = HashUser.begin(); it != HashUser.end(); ++it)
        if (_ID == it->second->Get_ID())
        {
            it->second->Show(f);
            return true;
        }

    f << "Nenhum User encontrada com o ID " << _ID << endl;
    return false;
}

void Casino::Listar(float X, ostream &f)
{
    for (list<Maquina *>::iterator it = LM_Total.begin(); it != LM_Total.end(); ++it)
    {
        if ((*it)->Get_PROB_GANHAR() >= X)
            (*it)->Show(f);
    }
}

void Casino::Run(bool debug)
{

    Relogio *R = new Relogio(1000, HORA_ABERTURA);
    time_t horaAtual = R->VerTimeRelogio();
    int userEscolhido, prob, probAv, quantUs;
    list<Maquina *> lmvizinhas;

    while (difftime(horaAtual, HORA_FECHO) < 0 && !parar)
    {

        /*if (kbhit){
            ch = getch();
            if(ch == 'M'|| ch == 'm'){
                R->stop();
                while(Menu(this));
                R->start();
            }
        }*/
        probAv = AleatorioINT(1, 100);
        quantUs = AleatorioINT(1, 10);

        // Colocar Usuários no Casino
        for (int i = 0; i < quantUs; i++)
        {
            userEscolhido = AleatorioINT(0, LU.size() - 1);
            prob = AleatorioINT(1, 100);
            if (prob <= 70)
            {
                list<User *>::iterator userIt = LU.begin();
                advance(userIt, userEscolhido);
                Add(*userIt);
                if (debug)
                    cout << "Adicionou o user: " << (*userIt)->Get_Nome() << endl
                         << endl;
            }
        }
        // Jogar
        for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        {
            Maquina *M = it->second;

            if (M->Get_ESTADO() == AVARIADA)
            {
                M->Set_ESTADO(OFF);
                qtMaqAv--;
                if (debug)
                    cout << "Maquina " << M->Get_ID() << " foi concertada" << endl
                         << endl;
            }

            if (M->Get_TEMP_AT() >= M->Get_TEMP_AV())
            {
                if (debug)
                    cout << "Máquina: " << M->Get_ID() << " ATINGIU A TEMPERATURA DE AVISO  ////////////////////////////////////////////////////";
            }

            if (probAv <= M->Get_PROB_AVARIA() || M->Get_TEMP_AT() >= M->Get_TEMP_AV())
            {
                M->Set_ESTADO(AVARIADA);
                qtMaqAv++;
                M->Reset_TEMP_AT();
                if (debug)
                    cout << "Maquina " << M->Get_ID() << " avariou" << endl
                         << endl;
            }

            if (M->Get_ESTADO() == OFF && !LU_Espera.empty())
            {
                M->Set_User(LU_Espera.front());
                if (debug)
                    cout << "O User " << LU_Espera.front()->Get_Nome() << " foi adicionado a maquina " << M->Get_ID() << endl
                         << endl;
                LU_Espera.pop_front();
                M->Set_ESTADO(ON);
            }
        }
        Listar();
        horaAtual = R->VerTimeRelogio();
        cout << "Hora: " << ctime(&horaAtual) << endl
             << endl;
        R->Wait(1);
        R->stop();
        while(Menu(this));
        R->start();
        system("clear");
        for (map<string, Maquina *>::iterator it = HashMaq.begin(); it != HashMaq.end(); ++it)
        {
            Maquina *M = it->second;
            if (M->Get_ESTADO() == ON)
            {
                if (M->Jogar(debug))
                    SubirProbabilidadeVizinhas(M, 1, lmvizinhas);
                HashUser.erase(M->Get_User()->Get_ID());
            }
        }
    }
    
    Relatorio("relatorio.xml");
}

list<Maquina *> *Casino::Listar_Tipo(string Tipo, ostream &saida)
{
    list<Maquina *> *LM_Tipo = new list<Maquina *>;
    transform(Tipo.begin(), Tipo.end(), Tipo.begin(), ::toupper);
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

    cout << endl
         << endl
         << "ERRO! NENHUMA MÁQUINA ENCONTRADA COM O ID " << ID << "!" << endl;
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
    if (LU_Espera.size() < maxUser - HashMaq.size())
    { // caso a fila não esteja cheia
        string key = U->Get_ID();
        if (HashUser.find(key) == HashUser.end())
        { // caso a fila não esteja cheia
            HashUser[key] = U;
            LU_Espera.push_back(U);
            LU_Total.push_back(U);
            return true;
        }
        else
        {
            cout << "Erro! Esse User já esta no casino, ID: " << key << "!" << endl
                 << endl;
            return false;
        }
    }
    cout << "Erro! O casino está cheio!" << endl
         << endl;
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

    for (list<User *>::iterator it = LU_Total.begin(); it != LU_Total.end(); ++it)
        MEM_U += (*it)->Memoria();

    for (map<string, User *>::iterator it = HashUser.begin(); it != HashUser.end(); ++it)
        MEM_U = it->second->Memoria();

    TOTAL = sizeof(*this) + MEM_MAQ + MEM_U;

    return TOTAL;
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
                it->second->Inc_PROB_GANHAR(5);
            }
        }
    }
}

bool compare_Ranking_Dos_Fracos(Maquina *M1, Maquina *M2)
{
    return (M1->Get_QNT_AVARIA() > M2->Get_QNT_AVARIA());
}

list<Maquina *> *Casino::Ranking_Dos_Fracos()
{
    list<Maquina *> *Res = new list<Maquina *>;

    for (list<Maquina *>::iterator it = LM_Total.begin(); it != LM_Total.end(); ++it)
        Res->push_back(*it);

    Res->sort(compare_Ranking_Dos_Fracos);

    return Res;
}

bool Casino::RemoverUser(ostream &f){
    string id;
    cout<<"Qual é o ID do user que quer remover?:"<<endl;
    cin >> id;
    map<string, User *>::iterator it;
    it = HashUser.find(id);
    if(it==HashUser.end()){
        cout<<"User nao encontrado"<<endl;
        return true;
    }
    cout << it->second->Get_Nome() << " foi removido"<<endl;
    return false;
}

// Funcao para comparar Maquinas que mais trabalharam
bool compare_Ranking_Das_Mais_Trabalhadores(Maquina *M1, Maquina *M2)
{
    return (M1->Get_TEMPO_JOGO() > M1->Get_TEMPO_JOGO());
}

// Lista ordenada por maquinas que mais trabalharam
list<Maquina *> *Casino::Ranking_Das_Mais_Trabalhadores()
{
    list<Maquina *> *Res = new list<Maquina *>;

    for (list<Maquina *>::iterator it = LM_Total.begin(); it != LM_Total.end(); ++it)
        Res->push_back(*it);

    Res->sort(compare_Ranking_Das_Mais_Trabalhadores);

    return Res;
}

// Funcao para comparar jogadores que mais ganharam
bool compare_Jogadores_Mais_Ganhos(User *U1, User *U2)
{
    return (U1->Get_premioGanho() > U2->Get_premioGanho());
}

// Obter lista de jogadores que mais galhou ordenada
list<User *> *Casino::Jogadores_Mais_Ganhos()
{
    list<User *> *Res = new list<User *>;

    for (list<User *>::iterator it = LU_Total.begin(); it != LU_Total.end(); ++it){
        if((*it)->Get_premioGanho()!=0) Res->push_back(*it);
    }

    Res->sort(compare_Jogadores_Mais_Ganhos);

    return Res;
}

// Funcao para comparar jogadores mais frequentes
bool compare_Jogadores_Mais_Frequentes(User *U1, User *U2)
{
    return (U1->Get_TempoJogo() > U2->Get_TempoJogo());
}

// Obter Lista de jogadores mais frequentes ordernada
list<User *> *Casino::Jogadores_Mais_Frequentes()
{
    list<User *> *Res = new list<User *>;

    for (list<User *>::iterator it = LU_Total.begin(); it != LU_Total.end(); ++it)
        Res->push_back(*it);

    for (list<User *>::iterator it = Res->begin(); it != Res->end(); ++it)
        Res->sort(compare_Jogadores_Mais_Frequentes);

    return Res;
}

// Funcao para escrever relatorio
void Casino::Relatorio(string fich_xml)
{
    XMLWriter XX;
    XX.WriteStartDocument(fich_xml);
    XX.WriteStartElement("LISTA_MAQ");
    for (list<Maquina *>::iterator it = LM_Total.begin(); it != LM_Total.end(); ++it)
    {
        Maquina *M = *it;
        XX.WriteStartElement("MAQUINA");
        XX.WriteElementString("ID", to_string(M->Get_ID()));
        XX.WriteElementString("NOME", M->Get_TIPO());
        XX.WriteElementString("PROB_G", to_string((int)M->Get_PROB_GANHAR()));
        XX.WriteElementString("PROB_A", to_string((int)M->Get_PROB_AVARIA()));
        XX.WriteElementString("PREMIO", to_string(M->Get_Premio()));
        XX.WriteElementString("X", to_string(M->Get_POSX()));
        XX.WriteElementString("Y", to_string(M->Get_POSY()));
        XX.WriteElementString("TEMP_AVISO", to_string(M->Get_TEMP_AV()));
        XX.WriteElementString("ESTADO", EnumToString(M->Get_ESTADO()));
        XX.WriteElementString("QNTAVARIA", to_string(M->Get_QNT_AVARIA()));
        XX.WriteElementString("TEMPOJOGO", to_string(M->Get_TEMPO_JOGO()));
        XX.WriteEndElement();
    }
    XX.WriteEndElement();
    XX.WriteEndDocument();
}
