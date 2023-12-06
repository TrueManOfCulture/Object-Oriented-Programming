#include "../include/User.h"

User::User(string _id, string _nome, string _cidade, int _idade)
{
    ID = _id;
    NOME = _nome;
    CIDADE = _cidade;
    IDADE = _idade;
}

User::~User()
{
    //dtor
}

void User::Show()
{
    cout << "ID: " << ID << endl;
    cout << "NOME: " << NOME << endl;
    cout << "CIDADE: " << CIDADE << endl;
    cout << "IDADE: " << IDADE << endl << endl;
}