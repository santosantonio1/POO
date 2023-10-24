#include "Professor.hpp"
Professor::Professor(string n, string r, string u, int a, double s):unidade(u),ano_de_ingresso(a),salario(s),Pessoa(n,r){}
string Professor::obtemUnidade(){ return unidade; }
int Professor::obtemAnoIngresso(){ return ano_de_ingresso; }
double Professor::obtemSalarioFixo(){ return salario; }
void Professor::defineUnidade(string u){ unidade = u; }
void Professor::defineAnoIngresso(int a){ ano_de_ingresso = a; }
void Professor::defineSalarioFixo(double s){ salario = s; }