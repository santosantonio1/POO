#include <iostream>
#include <exception>
#include <vector>
#include "a.hpp"
using namespace std;
// class my_exception : public exception {
//     virtual const char * what() const throw(){
//         return "MEU ERRO PERSONALIZADO!!!!!!!!!!!!!!";
//     }
// };
int main(){
    
    vector<int> v;
    for(int i=0;i<5;i++) v.push_back(i+1);

    try{
        for(int i=0;i<6;i++) v.pop_back();
        throw my_exception();
    }

    catch (exception &e){
        cout << e.what() << endl;
    }

    return 0;
}