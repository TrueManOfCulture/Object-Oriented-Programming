#include "../include/Relogio.h"

Relogio::Relogio(int Vel, time_t inicio){
    START = time(0);
    VELOCIDADE = Vel;
    tempoParadoVirt = time(0);
    tempoParadoReal = time(0);
    parado = false;

    struct tm *tmp = localtime(&inicio);
    Hora_Inicio = mktime(tmp);
}

Relogio::~Relogio()
{
    // dtor
}

void Relogio::start(){
    parado = false;
    time_t Dif = difftime(time(0), tempoParadoReal);
    START += Dif;
}

void Relogio::stop(){
    parado = true;
    tempoParadoVirt = VerTimeRelogio();
    tempoParadoReal = time(0);
}

time_t Relogio::VerTimeRelogio(){
    time_t Dif = difftime(time(0), START);
    time_t Simulada = Hora_Inicio + Dif *VELOCIDADE;
    if(parado)
        return tempoParadoVirt;
    return Simulada;
}

void Relogio::WaitSegundos(int s){
    clock_t T0 = clock();
    clock_t T1 = T0 + s;
    while (clock() < T1);
}

void Relogio::Wait(int s){
    WaitSegundos(s*CLOCKS_PER_SEC);
}

//Verificar tecla pressionada
// if (kbhit){
//     ch = getch();
//     //verificar se e o enter
// }

//Funcao Loop
// int Run(Supermercado *S)
// {
//     while(1)
//     {
//         printf("Estou a trabalhar... entre as [%d] e as [%d]\n", S->HORA_INICIO, S->HORA_FIM);
//         size_t MEMORIA = MemoriaOcupadaSupermercado(S);
//         printf("MEMORIA do [%s]= %lu Bytes\n", S->NOME, MEMORIA);
//         // ShowProdutos(LIDL);
//         // ShowClientes(LIDL);
//         // ShowFuncionarios(S);
//         ShowEstado(S);

//         ProcessarCaixas(S);

//         EntrarMaisCliente(S);

//         IrCaixaPagar(S);

//         wait(2000);
//     }
// }
