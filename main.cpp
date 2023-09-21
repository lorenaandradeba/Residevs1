#include <iostream>
#include <string>
#include <vector>


#include "passageiro.cpp"
#include "roteiro.cpp"
#include "embarca.cpp"
#include "data.cpp"
#include "ocorrencia.cpp"

using namespace std;

void menu();
int main(){
    vector<Embarca> embarques;// vectores principais;
    vector<Passageiro> passageiros;//vectores principais;
    vector<Roteiro> roteiros; //vectores principais;
    vector<Ocorrencia> ocorrencia; //vectores principais;
    bool validar = true;
    int op;

    do{
        menu();//menu pricipal dentro de main.cpp
        cin >> op;
        if ( op ==1 )
            gestaoPassageiro(passageiros);//função dentro do arquivo passageiro.cpp
        else if (op == 2)
            gestaoRoteiro(roteiros);//função dentro do arquivo roteiro.cpp
        else if(op==3)
            gestaoEmbarque(embarques);//função dentro do arquivo embarcar.cpp
        else if(op==4)
            gestaoOcorrencia(ocorrencia);//função dentro do arquivo ocorrencia.cpp
        else
            validar = false;
        
    } while (validar);

    return 0;
}
void menu(){
    cout << "Bem vindo a Vans TransPaGente" <<endl;
    cout << "1. Acessar Menu de Passageiro" << endl;
    cout << "2. Acessar Menu de Roteiro" << endl; 
    cout << "3. Acessar Menu de Embarque" << endl; 
    cout << "4. Gestão de Ocorrências" << endl; 
    cout << "0. Sair"<< endl;
}