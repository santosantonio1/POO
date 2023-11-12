#ifndef _A_HPP
#define _A_HPP
#include <iostream>
#include <exception>
using namespace std;
class my_exception : public exception {
    public:
    virtual const char * what() const throw() {
        return "MEU ERRO PERSONALIZADO FEITO COM PRINCIPIOS DE POO!!!!";
    }
};
#endif