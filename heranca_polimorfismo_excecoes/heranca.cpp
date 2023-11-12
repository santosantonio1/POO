#include <iostream>
using namespace std;
class Animal{
    protected:
    string som;
    string tipo;
    public:
    Animal(string s="", string t="") : som(s), tipo(t) {}
    virtual void Som()=0;
};
class Porco : public Animal {
    public:
    Porco(string s="") : Animal("Oink Oink", "Porco") {}
    void Som(){
        cout << "Sou um MACACO !!!! " << som << endl;
        cout << "Gosto de fazer macaquice!" << endl;
    }
};
class Macaco : public Animal {
    public:
    Macaco(string s="") : Animal("Uh Uh Ah Ah", "Macaco") {}
    void Som(){
        cout << "Sou um PORQUINHO..." << som << endl;
        cout << "Gosto de deitar na lama e fazer porquice..." << endl; 
    }
};
int main(){

    
    Porco p1;
    Macaco m1;

    p1.Som();
    cout << endl;
    m1.Som();

    return 0;
}