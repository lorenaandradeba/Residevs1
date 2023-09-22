#include <iostream>
#include <vector>

using namespace std;
struct Ocorrencia{
    string descricao;
    Data data;
    int numApolice;
    Embarca embarque;
}; 

void menuOcorrencia();
void cadastrarOcorrencia(vector<Ocorrencia> &ocorrencias, int indiceEmbarque);
void listaOcorrenciasCpf(vector<Ocorrencia> &ocorrencias, string cpf);
void listaOcorrenciasRoteiro(vector<Ocorrencia> &ocorrencias, string roteiro);
void listarTodasOcorrencias(vector<Ocorrencia> &ocorrencias);


int gestaoOcorrencia(vector<Ocorrencia> &ocorrencias, vector<Embarca> &embarques){
    bool validar = true;
    int op;
    string cpf;
    int codigoRoteiro;
    int indiceEmbarque = -1;

    do{
        menuOcorrencia();
        cin >> op;
        switch (op){
            case 1:
                cin.ignore();
                cout << "Digite o codigo: ";
                cin >> codigoRoteiro;
                cin.ignore();
                cout << "Digite um CPF: ";
                getline(cin, cpf);
                indiceEmbarque = buscarEmbarques(embarques, codigoRoteiro, cpf);

                if(indiceEmbarque != -1){
                    cout<<endl << "Cadastrando ocorrencia..." <<endl;
                    //cadastrarOcorrencia(ocorrencias, indiceEmbarque);
                }else{
                    cout <<endl <<"Embarque não localizado" <<endl;
                }
                break;
            case 2:
                    //exluir
                break;
            case 3:
                     // Alterar;
                break;
            case 4:
                    //listarPorPassageiro(ocorrencias);
                break;
            case 5: 
                   // Listar passageiro por roteiro;
                break;
            case 6:
                //registar ocorencia por roteiro
                break;
            //    
            case 7:
            //lista todas as ocorencias.
                listarTodasOcorrencias(ocorrencias);
                break;
            case 0:
                    return 0;
                break;
            default:
                cout << "Opção Invalida!!!" <<endl;
                break;
        }
    } while (validar);
    

    return 0;
}

void menuOcorrencia(){

    cout << endl<< "==== Menu Ocorrência ====" << endl;

    cout << "1. Incluir uma ocorrência"<< endl; //solicita o CPF e Código
    cout << "2. Excluir uma ocorrência"<< endl; //solicita o CPF e Código
    cout << "3. Alterar uma ocorrência"<< endl; //solicita o CPF e Código
    cout << "4. Listar todas as ocorrências por Passageiro" << endl; //Solicita o CPF
    cout <<" 5. Incluir Ocorrencia por Roteiro" <<endl;
    cout << "6. Listar todas as ocorrências por Roteiro" << endl; //Solicita o Codigo
    cout << "0. Sair" <<endl;
    cout << "Digite uma opção:";
}

void listarTodasOcorrencias(vector<Ocorrencia>& ocorrencias) {
    for (Ocorrencia& ocorrencia : ocorrencias) {
        std::cout<< endl << "Descrição: " << ocorrencia.descricao << std::endl;
        std::cout << "Data: " << ocorrencia.data.data << std::endl; 
        std::cout << "Número da Apólice: " << ocorrencia.numApolice << std::endl;
        std::cout << "Embarque: " << ocorrencia.embarque.roteiro.codigo << std::endl; 
        std::cout << "Passageiro: " << ocorrencia.embarque.passageiro.nome << std::endl; 
        std::cout << "--------------------------" << std::endl;
    }
}