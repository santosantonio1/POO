#include "Cinema.hpp"
#include <sstream>

Cinema::Cinema(){
    numero = 0;
    nome = "";
    salas = 0;
}
Cinema::Cinema(int n, string nm, Endereco &e, int s){
    numero = n;
    nome = nm;
    endereco = e;
    salas = s;
}
Cinema::~Cinema(){

}
int Cinema::obtemNumero() const {
    return numero;
}
string Cinema::obtemNome() const {
    return nome;
}
Endereco Cinema::obtemEndereco() const{
    return endereco;
}
int Cinema::obtemSalas() const {
    return salas;
}
string Cinema::str() const {
    //FORMATO: nome [numero]
    //Endereco (logradouro, numero, - complemento - Bairro nome_bairro - cidade - estado)
    //Cinema(s): num_salas
    stringstream ss;
    ss << nome << " [" << numero << "] " << endl;
    ss << endereco.str() << endl;
    ss << "Cinema(s): " << salas << endl;
    return ss.str();  
}
void Cinema::defineNumero(int n){
    numero = n;
}
void Cinema::defineNome(string nm){
    nome = nm;
}
void Cinema::defineEndereco(Endereco &e){
    endereco = e;
}
void Cinema::defineSalas(int s){
    salas = s;
}
bool Cinema::operator<(const Cinema &c) const{
    int i=0;
    string c_nome = c.obtemNome();
    for(int i=0; i<nome.length(); i++){
        if(nome[i]<c_nome[i]) return true;
        if(nome[i]>c_nome[i]) return false;
    }
    return true;
}
istream & operator>>(istream &in, Cinema &c){
    string aux;
    if(getline(in, aux)) c.numero = stoi(aux);
    getline(in, c.nome);
    in >> c.endereco;
    if(getline(in, aux)) c.salas = stoi(aux);
    return in;
}
ostream & operator<<(ostream &out, const Cinema &c){
    out << c.numero << endl;
    out << c.nome << endl;
    out << c.endereco;
    out << c.salas << endl;
    return out;
}