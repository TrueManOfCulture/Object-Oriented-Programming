#include "../include/User.h"

User::User(int _id, string _nome, string _cidade, int _idade)
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
    cout << "ID: " << ID << endl << "NOME: " << NOME << endl << "CIDADE: " << CIDADE << endl << "IDADE: " << IDADE << endl << endl;
}