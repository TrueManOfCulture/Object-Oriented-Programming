#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

class User
{
    int ID;
    string NOME;
    string CIDADE;
    int IDADE;

    public:
        User(int _id, string _nome, string _cidade, int _idade);
        virtual ~User();

        void Show();
};

#endif // USER_H
