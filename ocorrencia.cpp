#include <iostream>
#include <vector>

using namespace std;
void menuOcorrencia();

struct Ocorrencia{
    char realizada;
    string descricao;
    Data data;
    int hora;// duração real;
    string cpf_passageiro;
    int cod_roteiro;
}; 


int gestaoOcorrencia(vector<Ocorrencia> &ocorrencia){

    bool validar = true;
    int op;

    do{
        menuEmbarque();
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
                    // Listar passageiro;
                break;
            case 5:
                    // Listar roteiro;
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
void menuEmbarque(){
    cout << "Bem vindo a Vans TransPaGente" << endl;
    cout << "1. Incluir uma ocorrência"<< endl; //solicita o CPF e Código
    cout << "2. Excluir uma ocorrência"<< endl; //solicita o CPF e Código
    cout << "3. Alterar uma ocorrência"<< endl; //solicita o CPF e Código
    cout << "4. Listar todas as ocorrências por Passageiro" << endl; //Solicita o CPF
    cout << "4. Listar todas as ocorrências por Roteiro" << endl; //Solicita o Codigo
    cout << "0. Sair" <<endl;
    cout << "Digite uma opção:";
}