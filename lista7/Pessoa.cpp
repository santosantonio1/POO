#include "Pessoa.hpp"
Pessoa::Pessoa(string n, string r):nome(n),rg(r) {}
string Pessoa::obtemNome(){ return nome; }
string Pessoa::obtemRG(){ return rg; }
void Pessoa::defineNome(string n){ nome = n; }
void Pessoa::defineRG(string r){ rg = r; }