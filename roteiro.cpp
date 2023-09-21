#include <iostream>
#include <vector>

using namespace std;
void menuRoteiro();

struct Roteiro
{
   int codigo;
   Data data;
   int hora;
   int duracao;
   string origem;
   string destino;
};

int gestaoRoteiro(vector<Roteiro> &roteiros){

    bool validar = true;
    int op;

    do{
        menuRoteiro();
        cin >> op;
        switch (op){
            case 1:
                    //incluir
                break;
            case 2:
                    // excluir
                break;
            case 3:
                    // Alterar;
                break;
            case 4: 
                    // Lista;
                break;
            case 5:
                    //Localizar(por CPF);
                break;
            case 0:
                validar = false;
                break;
            default:
                cout << "Opção Invalida!!!" <<endl;
                break;
        }
    } while (validar);
    

    return 0;
}

void menuRoteiro(){
    cout << "Bem vindo a Vans TransPaGente" << endl;
    cout << "1-Incluir Roteiro"<< endl;
    cout << "2-Excluir Roteiro"<< endl; // pode ser por cpf
    cout << "3-Alterar (apenas código)"<< endl; //buscar por cpf
    cout << "4-Listar " << endl; //listar o que os pasageiros e seus respectivos roteiro?
    cout << "5-Localizar (Por codigo)" << endl;
    cout << "0-Sair" <<endl;
    cout << "Digite uma opção:";
}