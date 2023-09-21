#include <iostream>
#include <vector>

using namespace std;
void menuEmbarque();

struct Embarca{
    char realizada;
    Data data;//data real de embarque
    int hora;//hora real de embarque
    int duracao;// duração real;
    vector<Passageiro> passageiros;//Embarque[0], passageiro[i], 
    int cod_roteiro;
}; 


int gestaoEmbarque(vector<Embarca> &embarques){

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
                    // Lista;
                break;
            case 5:
                    
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
    cout << "1-Incluir um Novo embarque"<< endl;
    cout << "2-Excluir registro de embarque"<< endl; // pode ser por cpf
    cout << "3-Alterar "<< endl; 
    cout << "4-Listar todos os embarques" << endl; //listar o que os pasageiros e seus respectivos roteiro?
    cout << "0-Sair" <<endl;
    cout << "Digite uma opção:";
}