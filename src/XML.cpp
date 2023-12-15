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
        cout << "Não tinha conteudo"<<endl;
        cout<<"Linha: "<< V[1];
        return NULL;
    }
    conteudo = V[2];
    return conteudo;
}

string ObterTag(ifstream &f){
    if (!f.is_open()){
        cout<<"Ficheiro não encontrado"<<endl;
        return NULL;
    } 

    int n_campos_lidos;
    STRING *V = Read_Split_Line_File(f, 10, n_campos_lidos, "<>");
    return V[1];
}

