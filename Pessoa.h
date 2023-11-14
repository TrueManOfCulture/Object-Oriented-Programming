#ifndef PESSOA_H
#define PESSOA_H

#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
    string NOME;
    int IDADE;

    public:
        Pessoa(string _nome, int _idade);
        virtual ~Pessoa();
        void Show();
};

#endif // PESSOA_H
