#include "../include/XMLWriter.h"

XMLWriter::XMLWriter()
{
    
}

XMLWriter::~XMLWriter()
{

}

string XMLWriter::Tabulacoes(int N)
{
    string s = "";
    for (int i = 0; i < N; i++)
        s += "\t";
    return s;
}
void XMLWriter::WriteStartDocument(string ficheiro)
{
    F.open(ficheiro);
}

void XMLWriter::WriteElementString(string el, string valor)
{
    F << Tabulacoes(TAGS.size()+1) << "<" << el <<">" << valor << "</" << el << ">" << endl;
}
void XMLWriter::WriteStartElement(string el)
{
    TAGS.push_front(el);
    F << Tabulacoes(TAGS.size()) << "<" << el <<">" << endl;
}
void XMLWriter::WriteEndElement()
{
    string el = TAGS.front();
    TAGS.pop_front();
    F << Tabulacoes(TAGS.size()) << "</" << el <<">" << endl;
}

void XMLWriter::WriteEndDocument(){
    F.close();
}
