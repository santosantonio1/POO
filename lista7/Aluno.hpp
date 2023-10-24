#ifndef _ALUNO_HPP
#define _ALUNO_HPP
#include "Pessoa.hpp"
class Aluno : public Pessoa {
    private:
    string matricula;
    int ano_de_ingresso;
    public:
    Aluno(string n="", string r="", string m="", int a=0);
    string obtemMatricula();
    int obtemAnoIngresso();
    void defineMatricula(string m);
    void defineAnoIngresso(int a);
};
#endif