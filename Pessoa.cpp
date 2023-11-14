#include "Pessoa.h"

Pessoa::Pessoa(string _nome, int _idade)
{
    NOME = _nome;
    IDADE =_idade;
}

Pessoa::~Pessoa()
{
    //dtor
}

void Pessoa::Show()
{
    cout << "NOME: [" << NOME << "]" << endl;
    cout << "IDADE: [" << IDADE << "]" << endl;
}
