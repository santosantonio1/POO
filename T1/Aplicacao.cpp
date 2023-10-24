#include "Aplicacao.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;
Aplicacao::Aplicacao(){
    numCinemas = numFilmes = numProgramacao = 0;
}
Aplicacao::~Aplicacao(){
    for(int i=0; i<numCinemas; i++) delete cinemas[i];
    for(int i=0; i<numFilmes; i++) delete filmes[i];
    for(int i=0; i<numProgramacao; i++) delete programacao[i];
    numCinemas = numFilmes = numProgramacao = 0;
}
bool Aplicacao::carregaFilmes(string nomeArquivo){
    //Carrega os filmes de um arquivo em um vetor

    ifstream filmes_input;
    filmes_input.open(nomeArquivo, ios::in);
    if(!filmes_input.is_open()) return false;
    do{ 
        filmes[numFilmes] = new Filme;        
        filmes_input >> *filmes[numFilmes];
        if(!filmes_input.eof()) //So aumenta pois na sobrecarga do operador >> o programa testa o getline()
                                //Entao, so adicionar um filme com os dados se o input_file nao tiver acabado
        numFilmes++;
    }while(filmes_input.good());
    filmes_input.close();
    return true;
}
bool Aplicacao::salvaFilmes(string nomeArquivo){
    //Salva os filmes que estao em um array em um arquivo
    ofstream filmes_output;
    filmes_output.open(nomeArquivo, ios::out);
    if(!filmes_output.is_open()) return false;
    for(int i=0; i<numFilmes; i++){
        filmes_output << *filmes[i];
    }
    filmes_output.close();
    return true;
}
void Aplicacao::mostraFilmes(){
    for(int i=0; i<numFilmes; i++){
        cout << filmes[i]->str() << endl;
    }
}
void Aplicacao::ordenaFilmes(){
    //Ordena os filmes por ordem alfabetica utilizando o algoritimo Bubble_sort
    int t = numFilmes;
    bool trocou;
    do{
        t--;
        trocou = false;
        for(int i=0; i<t; i++){
            if(*filmes[i+1] < *filmes[i]){
                Filme *aux = filmes[i+1];
                filmes[i+1] = filmes[i];
                filmes[i] = aux;
                trocou = true;
            }
        }
    }while(trocou);
}
Filme * Aplicacao::obtemFilme(int id){
    for(int i=0; i<numFilmes; i++){
        if(filmes[i]->obtemNumero() == id) return filmes[i];
    }
    return nullptr;
}
bool Aplicacao::carregaCinemas(string nomeArquivo){
    //Carrega os cinemas de um arquivo em um vetor
    ifstream cinemas_input;
    cinemas_input.open(nomeArquivo, ios::in);
    if(!cinemas_input.is_open()) return false;
    do{
        cinemas[numCinemas] = new Cinema;
        cinemas_input >> *cinemas[numCinemas];
        if(!cinemas_input.eof()) //Na sobrecarga do operador >> e feito testes com getline(), inclusive no final do arquivo
        numCinemas++;            //Entao so adicionar o cinema se nao for o final do arquivo
    }while(cinemas_input.good()); 
    cinemas_input.close();
    return true;
}
bool Aplicacao::salvaCinemas(string nomeArquivo){
    //Salva os cinemas do vetor em um arquivo
    ofstream cinemas_output;
    cinemas_output.open(nomeArquivo, ios::out);
    if(!cinemas_output.good()) return false;
    for(int i=0; i<numCinemas; i++){
        cinemas_output << *cinemas[i];
    }
    cinemas_output.close();
    return true;
}
void Aplicacao::mostraCinemas(){
    for(int i=0; i<numCinemas; i++){
        cout << cinemas[i]->str() << endl;
    }
}
void Aplicacao::ordenaCinemas(){
    //Ordena os cinemas por ordem alfabetica utilizando o algoritimo Bubble_Sort
    int tam = numCinemas;
    bool trocou;
    do{
        tam--;
        trocou = false;
        for(int i=0; i<tam; i++){
            if(*cinemas[i+1]< *cinemas[i]){
                Cinema *aux = cinemas[i];
                cinemas[i] = cinemas[i+1];
                cinemas[i+1] = aux;
                trocou = true;
            }
        }
    }while(trocou);
}
Cinema * Aplicacao::obtemCinema(int id){
    for(int i=0; i<numCinemas; i++){
        if(cinemas[i]->obtemNumero() == id) return cinemas[i];
    }
    return nullptr;
}
bool Aplicacao::carregaProgramacao(string nomeArquivo){
    //Carrega a programacao de um arquivo em um vetor
    ifstream prog_input;
    prog_input.open(nomeArquivo, ios::in);
    if(!prog_input.is_open()) return false;
    do{
        programacao[numProgramacao] = new Programacao;
        int n; string aux;
        if(getline(prog_input, aux)) { 
            n = stoi(aux);
            programacao[numProgramacao]->defineCinema(obtemCinema(n));
        }
        if(getline(prog_input, aux)){
            n = stoi(aux);
            programacao[numProgramacao]->defineSala(n);
        }
        if(getline(prog_input, aux)){
            n = stoi(aux);
            programacao[numProgramacao]->defineFilme(obtemFilme(n));
        }
        if(getline(prog_input, aux)){
            n = stoi(aux);
            programacao[numProgramacao]->defineTipoDeExibicao(n);
        }
        getline(prog_input, aux);
        programacao[numProgramacao]->defineHorarios(aux);
        if(!prog_input.eof())
        numProgramacao++;
    }while(prog_input.good());
    prog_input.close();
    return true;
}
void Aplicacao::mostraProgramacao(){
    for(int i=0; i<numCinemas; i++){
        cout << cinemas[i]->obtemNome() << "\n" << endl;
        for(int j=0; j<numProgramacao; j++){
            if(programacao[j]->obtemCinema()->obtemNumero() == cinemas[i]->obtemNumero())
            cout << programacao[j]->str(false) << endl;
        }
        cout << endl;
    }
}
