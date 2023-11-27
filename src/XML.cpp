#include "../include/XML.h"

//Obter conteudo dentro de tags
string ObterConteudo(string linha){
    string conteudo;
    int pos_ini, pos_fim;
    pos_ini = linha.find(">")+1; // posicao do inicio da string  
    pos_fim = linha.find("<",1); //posicao do fim da string
    conteudo = linha.substr(pos_ini,pos_fim-pos_ini);
    return conteudo;
}

