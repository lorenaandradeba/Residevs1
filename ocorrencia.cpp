#include <iostream>
#include <vector>

using namespace std;
struct Ocorrencia{
    string descricao;
    string data;
    int hora;
    int numApolice;
    
    Embarca embarque;
}; 

void menuOcorrencia();
void cadastrarOcorrencia(vector<Ocorrencia> &ocorrencia, vector<Embarca> &embarques, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros);
Embarca localizarEmbarque(vector<Embarca> &embarques, string cpf, int codigo);
void listarPorPassageiro(vector<Ocorrencia>& Ocorrencias);
void listarPorRoteiro(vector<Ocorrencia>& Ocorrencias);

int gestaoOcorrencia(vector<Ocorrencia> &ocorrencias, vector<Embarca> &embarques, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros){
    bool validar = true;
    int op;

    do{
        menuOcorrencia();
        cin >> op;
        switch (op){
            case 1:
                cadastrarOcorrencia(ocorrencias, embarques, passageiros, roteiros);
                break;
            case 2:
                    // excluir
                break;
            case 3:
                    // Alterar;
                break;
            case 4: 
                listarPorPassageiro(ocorrencias);   // Listar passageiro;
                break;
            case 5:
                listarPorRoteiro(ocorrencias);   // Listar roteiro;
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


void listarPorPassageiro(vector<Ocorrencia>& Ocorrencias) {
    string cpf;
    string nome="";
    cout <<endl << "Informe o CPF: ";
    cin.ignore();
    getline(cin, cpf);
    
    for (const Ocorrencia& o : Ocorrencias) {
        if(o.embarque.passageiro.cpf == cpf){
            if (nome==""){
                nome=o.embarque.passageiro.nome;
                cout << "Lista de Ocorrencias do Passageiro: "<< nome <<":" << endl;
            }
            cout << "Descrição: " << o.descricao << endl;
            cout << "Data: " << o.data << std::endl;
            cout << "Hora: " << o.hora << std::endl;
        
            cout << endl;
        }
    }
}

void listarPorRoteiro(vector<Ocorrencia>& Ocorrencias) {
    int codigo;
    cout <<endl << "Informe o Código: ";
    cin>>codigo;
    string nome="";
    
    for (const Ocorrencia& o : Ocorrencias) {
        if(o.embarque.roteiro.codigo == codigo){
            if (nome==""){
                nome=o.embarque.roteiro.codigo;
                cout << "Lista de Ocorrencias do Roteiro: "<< nome <<":" << endl;
            }
            cout << "Descrição: " << o.descricao << endl;
            cout << "Data: " << o.data << endl;
            cout << "Hora: " << o.hora << std::endl;
        
            cout << endl;
        }
    }
}
Embarca localizarEmbarque(vector<Embarca> &embarques, string cpf, int codigo){
    for (const Embarca &e : embarques) {
        if (e.passageiro.cpf == cpf && e.roteiro.codigo == codigo){
            return e;
        }
    }
    return Embarca{};
}
void cadastrarOcorrencia(vector<Ocorrencia> &ocorrencia, vector<Embarca> &embarques, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros){
    int codigo;
    string cpf;
    int indice_passageiro;
    int indice_roteiro;
    Embarca embarque;

    cout <<endl << "Informe o CPF: ";
    cin.ignore();
    getline(cin, cpf);
                    
    cout << "Digite o codigo: ";
    cin >> codigo;
    cout<<endl;
    ///verificar se o cpf esta cadastrado em passsageiro e verificar se roteiro esta cadastrado
    indice_passageiro = localizarPassageiroPorCPF(passageiros, cpf);//pega o indece -1 não encontrou ou é a posição
    indice_roteiro = localizarRoteiro(roteiros, codigo);//pega o indece -1 não encontrou ou é a posição
    embarque = localizarEmbarque(embarques, cpf, codigo);

    if((indice_roteiro != -1) && (indice_passageiro !=-1)){
        cout << endl <<"Dados Validos!"<< endl;
        //CadastarOcorrencia
        string descricao;
        string data;
        int hora;
        int numApolice;
        cout <<"Descreva o que aconteceu:" <<endl;
        cin.ignore(); 
        getline(cin, descricao);
           
        cout <<"Informe a data: " << endl;
        cin.ignore(); 
        getline(cin, data);

        cout <<"Informe a hora: " << endl;
        cin >> hora;
        
        cout <<"Informe o numero do Apolice: " << endl;
        cin >> numApolice;
        Ocorrencia ocorrenciaAtual;

        ocorrenciaAtual.descricao = descricao;
        ocorrenciaAtual.data = data;
        ocorrenciaAtual.hora = hora;
        ocorrenciaAtual.numApolice = numApolice;
        ocorrenciaAtual.embarque = embarque;
        

        ocorrencia.push_back(ocorrenciaAtual); //Registra a ocorrencia
    }else{
         cout << endl << "Dados Invalidos"<< endl;
    }

}
void menuOcorrencia(){
    cout << endl<< "==== Menu Ocorrência ====" << endl;
    cout << "1. Incluir uma ocorrência"<< endl; //solicita o CPF e Código
    cout << "2. Excluir uma ocorrência"<< endl; //solicita o CPF e Código
    cout << "3. Alterar uma ocorrência"<< endl; //solicita o CPF e Código
    cout << "4. Listar todas as ocorrências por Passageiro" << endl; //Solicita o CPF
    cout << "5. Listar todas as ocorrências por Roteiro" << endl; //Solicita o Codigo
    cout << "0. Sair" <<endl;
    cout << "Digite uma opção:";
}