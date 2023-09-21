#include <iostream>
#include <vector>

using namespace std;


struct Embarca{
    string realizada;
    Data data;//data real de embarque
    string duracao;// duração real;
    Passageiros passageiro;//todos os dados de passageiros
    Roteiros roteiro;//todos os dados de roteiro
   
}; 


int menuEmbarque();
bool switCaseEmbarque(int op, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros, vector<Embarca> &embarques);
void cadastraEmbaque();
void cadastrarEmbarque(int umaPessoa, int umRoteiro, vector<Embarca> &embarques, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros);
void listarEmbarques(std::vector<Embarca>& embarques);

int gestaoDeEmbarque(vector<Passageiros> &passageiros, vector<Roteiros> &roteiros, vector<Embarca> &embarques){

    bool continuar = true;
    do{
       continuar = switCaseEmbarque(menuEmbarque(), passageiros, roteiros, embarques); 
    } while (continuar);
    

    return 0;
}

bool switCaseEmbarque(int op, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros, vector<Embarca> &embarques){
    int codigo;
    string cpf;
    int indice_pessoa;//posição(indice) no meu vector para buscar
    int indice_roteiro;//posição(indice) no meu vector para buscar
    switch (op){
            case 1:
                    //incluir embarque
                    //solicitar cpf e o codigo do passageiro;
                    cin.ignore();
                    cout <<endl << "Digite um CPF: ";
                    getline(cin, cpf);
                    
                    cout << "Digite o codigo: ";
                    cin >> codigo;
                    cout<<endl;

                    ///verificar se o cpf esta cadastrado em passsageiro e verificar se roteiro esta cadastrado
                    indice_pessoa = localizarPassageiroPorCPF(passageiros, cpf);//pega o indece -1 não encontrou ou é a posição
                    indice_roteiro = localizarRoteiro(roteiros, codigo);//pega o indece -1 não encontrou ou é a posição
                   
                    if((indice_roteiro != -1) && (indice_pessoa !=-1)){
                         cout << endl <<"Dados Validos!"<< endl;
                        //CadastarEmbarque
                            cadastrarEmbarque(indice_pessoa, indice_roteiro, embarques, passageiros, roteiros);
                    }else{
                         cout << endl << "Dados Invalidos"<< endl;
                     }
                break;
            case 2:
                    // excluir
                break;
            case 3:
                    // Alterar;
                break;
            case 4: 
               listarEmbarques(embarques);
                // Lista;
                break;
            case 5:
                    
                break;
            case 0:
                return false;
                break;
            default:
                cout << "Opção Invalida!!!" <<endl;
                break;
        }
    return true;
}

int menuEmbarque(){

     int op;
    cout << "Bem vindo a Vans TransPaGente" << endl;
    cout << "1-Incluir um Novo embarque"<< endl;
    cout << "2-Excluir registro de embarque"<< endl; // pode ser por cpf
    cout << "3-Alterar "<< endl; 
    cout << "4-Listar todos os embarques" << endl; //listar o que os pasageiros e seus respectivos roteiro?
    cout << "0-Sair" <<endl;
    cout << "Digite uma opção:";
    cin >> op;
    
    return op; //rotana o opçao desejada
}

void cadastrarEmbarque(int indice_pessoa, int indice_roteiro, vector<Embarca> &embarques, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros){
    Embarca embarcar;//struct do tipo embarcar

    string realizada;
    Data data;//data real de embarque //struc do data
    string duracao;// duração real;

    cout <<"O passageiro embarcou S/N:" <<endl;//validar esse parametro
    getline(cin, realizada);
    cin.ignore(); 
    embarcar.realizada = realizada;///tipo struc

    cout <<"Data de embarque: " << endl;
    getline(cin, data.data);
    cin.ignore(); 
    embarcar.data.data = data.data;
    
    cout <<"Hora real do embarque: " << endl;
    cin >> data.hora;
    embarcar.data.hora = data.hora;

    cout <<"Duracao da Vigem: " << endl;
    getline(cin, duracao);
    cin.ignore();

    embarcar.passageiro = passageiros[indice_pessoa]; //passando os dados de um passageiro
    embarcar.roteiro = roteiros[indice_roteiro]; //passando os dados de um roteiro

    embarques.push_back(embarcar); //Registra o Embarque na coleção de embarques
}

void listarEmbarques(std::vector<Embarca>& embarques) {
    std::cout << "Lista de Embarques:" << std::endl;
    for (const Embarca& embarque : embarques) {
        std::cout << "Realizada: " << embarque.realizada << std::endl;
        std::cout << "Data de Embarque: " << embarque.data.data << std::endl;
        std::cout << "Hora de Embarque: " << embarque.data.hora << std::endl;
        std::cout << "Duração: " << embarque.duracao << std::endl;
        std::cout << "Nome do Passageiro: " << embarque.passageiro.nome << std::endl;
        std::cout << "CPF do Passageiro: " << embarque.passageiro.cpf << std::endl;
        std::cout << "Data de Nascimento do Passageiro: " << embarque.passageiro.dataNascimento << std::endl;
        std::cout << "Número de Autorização: " << embarque.passageiro.numAltorizacao << std::endl;
        std::cout << "Origem do Roteiro: " << embarque.roteiro.origem << std::endl;
        std::cout << "Destino do Roteiro: " << embarque.roteiro.destino << std::endl;
        std::cout << "Data e Hora Previstas: " << embarque.roteiro.data_hora_prevista.data << " " << embarque.roteiro.data_hora_prevista.hora << std::endl;
        std::cout << std::endl;
    }
}