#include <iostream>
#include <vector>

using namespace std;
struct Ocorrencia{
    string descricao;
    string data;
    int hora;
    int numApolice;
    
}; 

void menuOcorrencia();
void cadastrarOcorrencia(vector<Embarca> &embarques);
void listarPorPassageiro(vector<Embarca>& embarques);
void listarPorRoteiro(vector<Embarca>& embarques);
void excluirOcorrencia(vector<Embarca> &embarques);
void alterarOcorrencia(vector<Embarca> &embarques);
int gestaoOcorrencia(vector<Embarca> &embarques){
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
                excluirOcorrencia(ocorrencias, embarques, passageiros, roteiros);// excluir
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
int obterIndiceDoEmbarque(vector<Embarca> &embarques, string cpf, int codigo);

void listarPorPassageiro(vector<Embarca>& embarques) {
    string cpf;
    string nome="";
    cout <<endl << "Informe o CPF: ";
    cin.ignore();
    getline(cin, cpf);
    
    for (const Embarca& e : embarques) {
        //Verifica se o cpf digitado e se tem ocorrencia para o embarque
        if(e.passageiro.cpf == cpf && !e.ocorrencia.descricao.empty()){
            if (nome==""){
                nome=e.passageiro.nome;
                cout << "Lista de Ocorrencias do Passageiro: "<< nome <<":" << endl;
            }
            if (!e.ocorrencia.descricao.empty()){
                cout << "Roteiro: " << e.roteiro.codigo << endl;
                cout << "Descrição: " << e.ocorrencia.descricao << endl;
                cout << "Data: " << e.data << std::endl;
                cout << "Hora: " << e.hora << std::endl;
            
                cout << endl;
                
            }
        }
    }
}

void listarPorRoteiro(vector<Embarca>& embarques) {
    int codigo;
    cout <<endl << "Informe o Código: ";
    cin>>codigo;
    string nome="";
    
    for (const Embarca& e: embarques) {
        if(e.roteiro.codigo == codigo && !e.ocorrencia.descricao.empty()){
            if (nome==""){
                nome= e.roteiro.codigo;
                cout << "Lista de Ocorrencias do Roteiro: "<< nome <<":" << endl;
            }
            if (!e.ocorrencia.descricao.empty()){
                cout << "Descrição: " << o.descricao << endl;
                cout << "Data: " << o.data << endl;
                cout << "Hora: " << o.hora << std::endl;
        
                cout << endl;
            }
            
        }
    }
}

void cadastrarOcorrencia(vector<Embarca> &embarques){
    int codigo;
    string cpf;
    Embarca embarque;
    cout <<endl << "Informe o CPF: ";
    cin.ignore();
    getline(cin, cpf);
                    
    cout << "Digite o codigo: ";
    cin >> codigo;
    cout<<endl;
    
    for (const Embarca &e : embarques) {
        if (e.passageiro.cpf == cpf && e.roteiro.codigo == codigo){
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
            
            embarque.ocorrencia = ocorrenciaAtual;
        }
    }else{
         cout << endl << "Dados Invalidos"<< endl;
    }
}
//funções
void excluirOcorrencia(vector<Embarca> &embarques){
    int codigo;
    string cpf;
    string nomePassageiro;
    bool encontrou = false;
    cout <<endl << "Informe o CPF: ";
    cin.ignore();
    getline(cin, cpf);
                    
    cout << "Digite o codigo: ";
    cin >> codigo;
    cout<<endl;
    for (size_t i = 0; i < embarques.size(); i++) {
        if (embarques[i].passageiro.cpf == cpf && embarques[i].roteiro.codigo == codigo){
           encontrou = true;
           nomePassageiro = embarques[i].passageiro.nome;
           embarques[i].ocorrencia = {};

           cout << "-----------------------------------------------------------------------------" << endl;
           cout << "\t\tOcorrência de "<<nomePassageiro<<" do Roteiro "<<codigo<<" foi excluido com sucesso." << endl;
           cout << "-----------------------------------------------------------------------------" << endl;
        }
    }
    if (!encontrou){
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "\t\tOps! Ocorrência não encontrada." << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
    }
}

void alterarOcorrencia(vector<Embarca> &embarques)
{
    int codigo;
    string cpf;
    int indice_embarque;

    cout <<endl << "Informe o CPF: ";
    cin.ignore();
    getline(cin, cpf);
                    
    cout << "Digite o codigo: ";
    cin >> codigo;
    cout<<endl;

    // localizar o índice do embarque a ser alterado
    indice_embarque = obterIndiceDoEmbarque(embarques, cpf, codigo);

    if ( indice_embarque != -1 ) 
    {
        cout << "Dados Validos!" << endl;

        string nomePassageiro = embarques[i].passageiro.nome;
        
        //AlterarOcorrencia
        string flag;
        string descricao;
        string data;
        int hora;
        int numApolice;

        cout << "Deseja alterar a descricao da ocorrencia (s/n)? ";
        cin >> flag;

        if ( flag == "s" ) {
            cout <<"Descreva o que aconteceu:" <<endl;
            cin.ignore(); 
            getline(cin, descricao);
        } else {
            embarques[indice_embarque].ocorrencia.descricao = descricao;
        }
        
        cout << "Deseja alterar a data (s/n)? ";
        cin >> flag;

        if ( flag == "s" ) {
            cout <<"Informe a data: " << endl;
            cin.ignore(); 
            getline(cin, data);
        } else {
            embarques[indice_embarque].ocorrencia.data = data;
        }

        cout << "Deseja alterar a hora (s/n)? ";
        cin >> flag;

        if ( flag == "s" ) {
            cout <<"Informe a hora: " << endl;
            cin >> hora;
        } else {
            embarques[indice_embarque].ocorrencia.hora = hora;
        }

        cout << "Deseja alterar o numero do Apolice (s/n)? ";
        cin >> flag;

        if ( flag == "s" ) {
            cout <<"Informe o numero do Apolice: " << endl;
            cin >> numApolice;
        } else {
            embarques[indice_embarque].ocorrencia.numApolice = numApolice;
        }

        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "\t\tOcorrência de "<<nomePassageiro<<" do Roteiro "<<codigo<<" foi alterada com sucesso." << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
    } 
    else {
        cout << "Dados Invalidos!" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "\t\tOps! Ocorrência não encontrada." << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
    }
} 

int obterIndiceDoEmbarque(vector<Embarca> &embarques, string cpf, int codigo)
{
    int indice_embarque = -1;
    int i = 0;

    for (Embarca embarque: embarques) {
        if ( embarque.passageiro.cpf == cpf && embarque.roteiro.codigo == codigo ) {
            indice_embarque = i;
        }

        i++;
    }

    return indice_embarque;
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