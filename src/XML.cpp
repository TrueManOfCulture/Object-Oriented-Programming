#include "../include/XML.h"

string ObterConteudo(ifstream &f){
    string conteudo;
    if (!f.is_open()){
        cout<<"File not found"<<endl;
        return NULL;
    } 

    int n_campos_lidos;
    STRING *V = Read_Split_Line_File(f, 10, n_campos_lidos, "<>");
    if(n_campos_lidos<4){
        cout << "Nao tinha conteudo"<<endl;
        return NULL;
    }
    conteudo = V[2];
    return conteudo;
}

