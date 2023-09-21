#include <iostream>
#include <string>
#include <vector>


using namespace std;
void menuPassageiro();

struct Passageiro
{
    string cpf;
    string nome;
    Data dtNascimento;
    int numAutorizacao;
};


int gestaoPassageiro(vector<Passageiro> &passageiros){

    bool validar = true;
    int op;

    do{
        menuPassageiro();
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
void menuPassageiro(){
    cout << "Bem vindo a Vans TransPaGente" << endl;
    cout << "1-Incluir um Novo Passageiro"<< endl;
    cout << "2-Excluir um Passageiro inserido"<< endl; // pode ser por cpf
    cout << "3-Alterar (apenas por CPF)"<< endl; //buscar por cpf
    cout << "4-Listar " << endl; //listar o que os pasageiros e seus respectivos roteiro?
    cout << "5-Localizar Passageiro(Por CPF)" << endl;
    cout << "0-Sair" <<endl;
    cout << "Digite uma opção:";
}