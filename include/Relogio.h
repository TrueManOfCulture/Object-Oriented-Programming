#ifndef RELOGIO_H_INCLUDED
#define RELOGIO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Relogio{
    time_t START;
    int VELOCIDADE;
    time_t Hora_Inicio;
    time_t tempoParado;
    bool parado;

    public:
        Relogio(int Vel, time_t inicio);
        time_t VerTimeRelogio();
        void stop();
        void start();
        void WaitSegundos(int s);
        void Wait(int s);
};



#endif // RELOGIO_H_INCLUDED