#include "Aluno.hpp"
Aluno::Aluno(string n, string r, string m, int a): matricula(m),ano_de_ingresso(a),Pessoa(n,r){}
string Aluno::obtemMatricula(){ return matricula; }
int Aluno::obtemAnoIngresso(){ return ano_de_ingresso; }
void Aluno::defineMatricula(string m){ matricula = m; }
void Aluno::defineAnoIngresso(int a){ ano_de_ingresso = a; }
