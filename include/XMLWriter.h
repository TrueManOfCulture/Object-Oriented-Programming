#ifndef XMLWRITER_H
#define XMLWRITER_H
#include <iostream>
#include <string>
using namespace std;
#include <list>
#include <fstream>

class XMLWriter
{
    ofstream F;
    list<string> TAGS;

    string Tabulacoes(int N);
public:
    XMLWriter();
    ~XMLWriter();
    void WriteStartDocument(string ficheiro);
    void WriteEndDocument();
    void WriteElementString(string el, string valor);
    void WriteStartElement(string el);
    void WriteEndElement();
};

#endif // XMLWRITER_H
