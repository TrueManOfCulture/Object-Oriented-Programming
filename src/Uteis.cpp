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
