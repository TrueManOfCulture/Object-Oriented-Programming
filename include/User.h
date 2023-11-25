#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class User
{
    string ID;
    string NOME;
    string CIDADE;
    int IDADE;

    public:
        User(string _id, string _nome, string _cidade, int _idade);
        virtual ~User();

        void Show();
        void TAMANHO_NOME(){ cout << sizeof(NOME) << endl; }
        int Memoria(){ return sizeof(*this); }
        int Get_IDADE(){ return IDADE; }
};

#endif // USER_H
