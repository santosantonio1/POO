#include "Filme.hpp"
#include <sstream>
#include <iostream>
using namespace std;

Filme::Filme(int n, string t, int f, string e){
    numero = n;
    titulo = t;
    faixaEtaria = f;
    estilo = e;
}
Filme::~Filme(){

}
int Filme::obtemNumero() const {
    return numero;
}
string Filme::obtemTitulo() const {
    return titulo;
}
int Filme::obtemFaixaEtaria() const {
    return faixaEtaria;
}
string Filme::obtemEstilo() const {
    return estilo;
}
string Filme::str() const {
    //FORMATO: titulo [numero] - faixa_etaria - estilo
    stringstream ss;
    ss << titulo << " [" << numero << "] - ";
    if(faixaEtaria < 1) ss << "LIVRE";
    else ss << faixaEtaria << " anos";
    ss << " - " << estilo;
    return ss.str();
}
void Filme::defineNumero(int n){
    numero = n;
}
void Filme::defineTitulo(string t){
    titulo = t;
}
void Filme::defineFaixaEtaria(int f){
    faixaEtaria = f;
}
void Filme::defineEstilo(string e){
    estilo = e;
}
bool Filme::operator<(const Filme &f) const{
    string f_titulo = f.obtemTitulo();
    for(int i=0; i<titulo.length(); i++){
        if(titulo[i]<f_titulo[i]) return true;
        if(titulo[i]>f_titulo[i]) return false;
    }
    return false;
}
istream & operator>>(istream &in, Filme &f){
    string aux;
    if(getline(in, aux)) f.numero = stoi(aux);
    getline(in, f.titulo);
    if(getline(in, aux)) f.faixaEtaria = stoi(aux);
    getline(in, f.estilo);
    return in;
} 
ostream & operator<<(ostream &out, const Filme &f){
    out << f.numero << endl;
    out << f.titulo << endl;
    out << f.faixaEtaria << endl;
    out << f.estilo << endl;
    return out;
}