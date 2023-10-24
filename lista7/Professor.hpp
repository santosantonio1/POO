#ifndef _PROFESSOR_HPP
#define _PROFESSOR_HPP
#include "Pessoa.hpp"
class Professor : public Pessoa {
    private:
    string unidade;
    int ano_de_ingresso;
    double salario;
    public:
    Professor(string n="", string r="", string u="", int a=0, double s=0.0);
    string obtemUnidade();
    int obtemAnoIngresso();
    double obtemSalarioFixo();
    void defineUnidade(string u);
    void defineAnoIngresso(int a);
    void defineSalarioFixo(double s);
};
#endif