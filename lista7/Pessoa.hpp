#ifndef _PESSOA_HPP
#define _PESSOA_HPP
#include <string>
using namespace std;
class Pessoa{
    private:
    string nome, rg;
    public:
    Pessoa(string n = "", string r = "");
    string obtemNome();
    string obtemRG();
    void defineNome(string n);
    void defineRG(string r);
};
#endif