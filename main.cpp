#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>

#include "data.h"


using namespace std;

struct Passageiro
{
    string cpf;
    string nome;
    Data dt_nascimento;
    int num_autorizacao;
};
struct Roteiro
{
    int codigo;    
    Data data;
    int hora;
    int duracao;
    string origem;
    string destino;

};
struct Embarca{
    char realizada;
    Data data;//data real de embarque
    int hora;//hora real de embarque
    int duracao;// duração real;
    Passageiro passageiro;
    Roteiro roteiro;
}; 
struct Ocorrencia{
    char realizada;
    string descricao;
    Data data;
    int hora;// duração real;
    Passageiro passageiro;
    Roteiro roteiro;
}; 

//Funcoes de Passageiro
int gestaoPassageiro(vector<Passageiro> &passageiros);
void incluirPassageiro(vector<Passageiro> &passageiros);
void alterarPassageiro(vector<Passageiro> &passageiros);
void excluirPassageiro(vector<Passageiro> &passageiros);
void listarPassageiros(vector<Passageiro> passageiros);
void localizarPassageiroCPF(vector<Passageiro> passageiros);
bool verificaPassageiroExiste(vector<Passageiro> passageiros, string cpf);
Passageiro getPassageiro(vector<Passageiro> passageiros, string cpf);
int retornaIdade(Data dtNascimento);
//Funcoes de Passageiro

//Funcoes de Roteiro
int gestaoRoteiro(vector<Roteiro> &roteiros);
void incluirRoteiro(vector<Roteiro> &roteiros);
void alterarRoteiro(vector<Roteiro> &roteiros);
void excluirRoteiro(vector<Roteiro> &roteiros);
void listarRoteiros(vector<Roteiro> roteiros);
void localizarRoteiro(vector<Roteiro> roteiros);
bool verificaRoteiroExiste(vector<Roteiro> roteiros, int codigo);
Roteiro getRoteiro(vector<Roteiro> roteiros, int codigo);
//Funcoes de Roteiro

//Funcoes de Embarque
void menuEmbarque();
int gestaoEmbarque(vector<Embarca> &embarques, vector<Passageiro> passageiros, vector<Roteiro> roteiros);
void incluirEmbarque(vector<Embarca> &embarques, vector<Passageiro> passageiros, vector<Roteiro> roteiros);
void listarEmbarque(vector<Embarca> embarques);
//Funcoes de Embarque


//Funcoes de Ocorrencia
void menuEmbarque();
void listarOcorrencia(vector<Ocorrencia> ocorrencia);
//Funcoes de Ocorrencia



void menu();
int main(){
    vector<Passageiro> passageiros;
    vector<Roteiro> roteiros; 
    vector<Embarca> embarques; 

    bool validar = true;
    int op;

    do{
        menu();//menu pricipal dentro de main.cpp
        cin >> op;
        if ( op ==1 ){
            gestaoPassageiro(passageiros);//função dentro do arquivo passageiro.cpp
        }else if (op == 2){
            gestaoRoteiro(roteiros);//função dentro do arquivo roteiro.cpp
        }else if (op == 3){
            gestaoEmbarque(embarques, passageiros, roteiros);//função dentro do arquivo roteiro.cpp
        }else{
            validar = false;
        }
    } while (validar);

    return 0;
}
int gestaoPassageiro(vector<Passageiro> &passageiros){
    bool validar = true;
    int op;
    do{
        cout << "-----------------------------------------------------------------------------" << endl;
        cout <<  setw(45) << "Menu de Passageiro" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "1. Incluir um Novo Passageiro"<< endl;
        cout << "2. Excluir um Passageiro"<< endl; 
        cout << "3. Alterar (apenas por CPF)"<< endl; 
        cout << "4. Listar " << endl; 
        cout << "5. Localizar Passageiro(Por CPF)" << endl;
        cout << "0. Sair" <<endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "Digite a opção desejada:" <<endl;
        cin >> op;
        switch (op){
            case 1:
                incluirPassageiro(passageiros); //incluir
                break;
            case 2:
                excluirPassageiro(passageiros); // excluir
                break;
            case 3:
                alterarPassageiro(passageiros); // Alterar;
                break;
            case 4: 
                listarPassageiros(passageiros); // Listar;
                break;
            case 5:
                localizarPassageiroCPF(passageiros);//Localizar(por CPF);
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


void incluirPassageiro(vector<Passageiro> &passageiros){
    string erro="";
    int dia, mes, ano;
    string cpf;
    string nome="";
    Data dt_nascimento;
    int num_autorizacao;
    //Não permite incluir um cpf em branco
    do{  
        cout << "Digite o CPF:" << endl;
        cin >> cpf;
    } while (cpf=="");
    
    //Não permite incluir um cpf repetido
    bool ja_existe_cpf = verificaPassageiroExiste(passageiros, cpf);

    if (ja_existe_cpf)
        cout << "Ops! O CPF "<<cpf<<" já está registrado em nosso sistema." << endl;
    else{
        //Não permite incluir um nome em branco
        do{  
            cout << "Digite o Nome:" << endl;
            cin.ignore();
            getline(cin, nome);
        } while (nome=="");

        //não permite incluir uma data de nascimento invalida
        do {
            cout << "A data de nascimento dia:" << endl;
            cin >> dia;
            cout << "Mes:" << endl;
            cin >> mes;
            cout << "Ano:" << endl;
            cin >> ano;
            inicializarData(dia, mes, ano, erro, dt_nascimento);
            if (erro!="")
                cout << "Erro ao inicializar data: " << erro << endl;

        } while (erro != "");

        Passageiro atual;

        if (retornaIdade(dt_nascimento) < 18){
            cout << "Por favor, insira o número de autorização para menores de idade:" << endl;
            cin >> num_autorizacao;
            atual.num_autorizacao = num_autorizacao;
        }
        atual.cpf = cpf;
        atual.nome = nome;
        atual.dt_nascimento = dt_nascimento;

        passageiros.push_back(atual);
    }
}
void alterarPassageiro(vector<Passageiro> &passageiros){
    string cpf;
    cout << "Digite o CPF do passageiro que deseja alterar:" << endl;
    cin >> cpf;
    for (size_t i = 0; i < passageiros.size(); i++) {
        if (passageiros[i].cpf == cpf){
            string erro="";
            int dia, mes, ano;
            string nome;
            Data dt_nascimento;
            int num_autorizacao;
            char altera;
            cout << "Deseja alterar o nome? (s/n):" << endl;
            cin >> altera;
            if(altera == 's'){
                //não permite alterar um nome vazio
                do{  
                    cout << "Digite o Nome:" << endl;
                    cin.ignore();
                    getline(cin, nome);
                } while (nome=="");
                passageiros[i].nome = nome;
            }
        
            cout << "Deseja alterar a data de nascimento? (s/n):" << endl;
            cin >> altera;
            if(altera == 's'){
                do {
                    cout << "A data de nascimento dia:" << endl;
                    cin >> dia;
                    cout << "Mes:" << endl;
                    cin >> mes;
                    cout << "Ano:" << endl;
                    cin >> ano;
                    inicializarData(dia, mes, ano, erro, dt_nascimento);
                    if (erro!="")
                        cout << "Erro ao inicializar data: " << erro << endl;

                } while (erro != "");
                if (retornaIdade(dt_nascimento) < 18){
                    cout << "Por favor, insira o número de autorização para menores de idade:" << endl;
                    cin >> num_autorizacao;
                    passageiros[i].num_autorizacao = num_autorizacao;
                }
                passageiros[i].dt_nascimento = dt_nascimento;
            }
            return;
        }
    }
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "\t\tPassageiro com CPF: "<<cpf<<" não encontrado" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
}
void excluirPassageiro(vector<Passageiro> &passageiros){
    string cpf;
    string nome;
    cout << "Digite o CPF do passageiro que deseja excluir:" << endl;
    cin >> cpf;
    for (size_t i = 0; i < passageiros.size(); i++) {
        if (passageiros[i].cpf == cpf){
            nome = passageiros[i].nome;
            passageiros.erase(passageiros.begin() + i);
            
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << "\t\tPassageiro: "<<nome<<" excluido com sucesso." << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
        }
    }
}
void listarPassageiros(vector<Passageiro> passageiros){
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << left << setw(40) << "NOME" << setw(16) << "CPF" << "Data de Nascimento" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    for (const Passageiro &p : passageiros) 
        cout << left << setw(40) << p.nome << setw(16) << p.cpf << dataParaString(p.dt_nascimento) << endl;
    
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << endl;
}
void localizarPassageiroCPF(vector<Passageiro> passageiros){
    string cpf;
    cout << "Digite o CPF do passageiro que deseja localizar:" << endl;
    cin >> cpf;
    
    for (const Passageiro &p : passageiros) {
        if (p.cpf == cpf){
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << left << setw(40) << "NOME" << setw(16) << "CPF" << "Data de Nascimento" << endl;
            cout << "-----------------------------------------------------------------------------" << endl;

            cout << left << setw(40) << p.nome << setw(16) << p.cpf << dataParaString(p.dt_nascimento) << endl;
            return;
        }
    }
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "\t\tPassageiro com CPF: "<<cpf<<" não encontrado" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;

}
bool verificaPassageiroExiste(vector<Passageiro> passageiros, string cpf){
    for (const Passageiro &p : passageiros) {
        if (p.cpf == cpf)
            return true;

    }
    return false;
}
Passageiro getPassageiro(vector<Passageiro> passageiros, string cpf){
    for (const Passageiro &p : passageiros) {
        if (p.cpf == cpf)
            return p;
    }
    return Passageiro{};
}
int retornaIdade(Data dtNascimento){
    // Obtém a data e hora atual
    time_t agora = time(nullptr);
    tm* dataHora = localtime(&agora);

     // Extrai o dia, mês e ano da estrutura tm
    int diaAtual = dataHora->tm_mday;
    int mesAtual = dataHora->tm_mon + 1; // Adicione 1 ao mês, pois janeiro é 0
    int anoAtual = dataHora->tm_year + 1900; // Adicione 1900 ao ano, pois tm_year conta os anos desde 1900
    
    int idade;

    if (dtNascimento.mes > mesAtual || (dtNascimento.mes == mesAtual && dtNascimento.dia > diaAtual)) {
        // Ainda não fez aniversário este ano
        idade = anoAtual - dtNascimento.ano - 1;
    } else {
        // Já fez aniversário este ano
        idade = anoAtual - dtNascimento.ano;
    }

    return idade;

}

int gestaoRoteiro(vector<Roteiro> &roteiros){
    bool validar = true;
    int op;
    do{
        
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
        cout <<  setw(55) << "Menu de Roteiro" << endl;
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
        cout << "1. Incluir"<< endl;
        cout << "2. Excluir"<< endl; 
        cout << "3. Alterar"<< endl; 
        cout << "4. Listar" << endl; 
        cout << "5. Localizar" << endl;
        cout << "0. Sair" <<endl;
        cout << "--------------------------------------------------------------------------------------------------------" << endl;
        cout << "Digite a opção desejada:" <<endl;
        cin >> op;
        switch (op){
            case 1:
                incluirRoteiro(roteiros); //incluir
                break;
            case 2:
                excluirRoteiro(roteiros); // excluir
                break;
            case 3:
                alterarRoteiro(roteiros); // Alterar;
                break;
            case 4: 
                listarRoteiros(roteiros); // Listar;
                break;
            case 5:
                localizarRoteiro(roteiros);//Localizar(por CPF);
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
void incluirRoteiro(vector<Roteiro> &roteiros){
    string erro="";
    int dia, mes, ano;
    int codigo;
    Data dataPrevista;
    int hora;
    int duracao;

    string origem="";
    string destino="";

   
    cout << "Digite o código do Roteiro:" << endl;
    cin >> codigo;
    
    
    //Não permite incluir um cpf repetido
    bool ja_existe_codigo = verificaRoteiroExiste(roteiros, codigo);

    if (ja_existe_codigo)
        cout << "Ops! O Código "<<codigo<<" já está registrado em nosso sistema." << endl;
    else{
        //não permite incluir uma data invalida
        do {
            cout << "A data prevista dia:" << endl;
            cin >> dia;
            cout << "Mes:" << endl;
            cin >> mes;
            cout << "Ano:" << endl;
            cin >> ano;
            inicializarData(dia, mes, ano, erro, dataPrevista);
            if (erro!="")
                cout << "Erro ao inicializar data: " << erro << endl;
        } while (erro != "");

        //não permite incluir uma hora fora do intervalo previsto
        do
        {
            cout << "Digite hora prevista: intervalo permitido [1-20]" << endl;
            cin >> hora;
        } while (hora < 1 || hora > 20);


         //não permite incluir uma duracao maior que 10
        do
        {
            cout << "Digite duração prevista para esse roteiro: intervalo permitido [1-10]" << endl;
            cin >> duracao;
        } while (duracao < 1 || duracao > 10);

        //Não permite incluir uma origem em branco
        do{  
            cout << "Digite a Origem:" << endl;
            cin.ignore();
            getline(cin, origem);
        } while (origem=="");

        //Não permite incluir um destino em branco
        do{  
            cout << "Digite o Destino:" << endl;
            cin.ignore();
            getline(cin, destino);
        } while (destino=="");

        Roteiro atual;

        atual.codigo = codigo;
        atual.data = dataPrevista;
        atual.hora = hora;
        atual.duracao = duracao;

        atual.origem = origem;
        atual.destino = destino;

        roteiros.push_back(atual);
    }
}
void alterarRoteiro(vector<Roteiro> &roteiros){
    int codigo;
    cout << "Digite o código do roteiro que deseja alterar:" << endl;
    cin >> codigo;
    for (size_t i = 0; i < roteiros.size(); i++) {
        if (roteiros[i].codigo == codigo){
            string erro="";
            int dia, mes, ano;
            int codigo;
            Data dataPrevista;
            int hora;
            int duracao;

            string origem="";
            string destino="";

            char altera;

            cout << "Deseja alterar a data prevista? (s/n):" << endl;
            cin >> altera;
            if(altera == 's'){
               //não permite incluir uma data invalida
                do {
                    cout << "A data prevista dia:" << endl;
                    cin >> dia;
                    cout << "Mes:" << endl;
                    cin >> mes;
                    cout << "Ano:" << endl;
                    cin >> ano;
                    inicializarData(dia, mes, ano, erro, dataPrevista);
                    if (erro!="")
                        cout << "Erro ao inicializar data: " << erro << endl;
                } while (erro != "");

                roteiros[i].data = dataPrevista;
            }
        
            cout << "Deseja alterar hora prevista? (s/n):" << endl;
            cin >> altera;
            if(altera == 's'){
                 do
                {
                    cout << "Digite hora prevista: intervalo permitido [1-20]" << endl;
                    cin >> hora;
                } while (hora < 1 || hora > 20);
                roteiros[i].hora = hora;
            }

            cout << "Deseja alterar duração prevista? (s/n):" << endl;
            cin >> altera;
            if(altera == 's'){
                //não permite incluir uma duracao maior que 10
                do
                {
                    cout << "Digite duração prevista para esse roteiro: intervalo permitido [1-10]" << endl;
                    cin >> duracao;
                } while (duracao < 1 || duracao > 10);
                roteiros[i].duracao = duracao;
            }
            
            cout << "Deseja alterar origem? (s/n):" << endl;
            cin >> altera;
            if(altera == 's'){
                 //Não permite incluir uma origem em branco
                do{  
                    cout << "Digite a Origem:" << endl;
                    cin.ignore();
                    getline(cin, origem);
                } while (origem=="");
                roteiros[i].origem = origem;
            }

            cout << "Deseja alterar destino? (s/n):" << endl;
            cin >> altera;
            if(altera == 's'){
                 //Não permite incluir um destino em branco
                do{  
                    cout << "Digite o Destino:" << endl;
                    cin.ignore();
                    getline(cin, destino);
                } while (destino=="");
                roteiros[i].destino = destino;
            }
            return;
        }
    }
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "\t\tRoteiro com código="<<codigo<<" não encontrado" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
}
void excluirRoteiro(vector<Roteiro> &roteiros){
    int codigo;
    string origem;
    string destino;

    cout << "Digite o codigo do roteiro que deseja excluir:" << endl;
    cin >> codigo;
    for (size_t i = 0; i < roteiros.size(); i++) {
        if (roteiros[i].codigo == codigo){
            origem = roteiros[i].origem;
            destino = roteiros[i].destino;
            roteiros.erase(roteiros.begin() + i);
            
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << "\t\tRoteiro de "<<origem<<" ate "<<destino<<" excluido com sucesso." << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
        }
    }
}
void listarRoteiros(vector<Roteiro> roteiros){
    
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(10) << "Código" << setw(19) << "Data"  << setw(13) << "Hora"  << setw(30) << "Origem"  <<  "Destino" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    for (const Roteiro &p : roteiros) 
        cout << left << setw(10) << p.codigo << setw(19) << dataParaString(p.data)  << setw(13) << p.hora  << setw(30) << p.origem <<  p.destino << endl;
    
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}
void localizarRoteiro(vector<Roteiro> roteiros){
    int codigo;
    cout << "Digite o Cógigo do roteiro0 que deseja localizar:" << endl;
    cin >> codigo;
    
    for (const Roteiro &p : roteiros) {
        if (p.codigo == codigo){
           
            cout << "--------------------------------------------------------------------------------------------------------" << endl;
            cout << left << setw(10) << "Código" << setw(19) << "Data"  << setw(13) << "Hora"  << setw(30) << "Origem" <<   "Destino" << endl;
            cout << "--------------------------------------------------------------------------------------------------------" << endl;

            cout << left << setw(10) << p.codigo << setw(19) << dataParaString(p.data)  << setw(13) << p.hora  << setw(30) << p.origem <<  p.destino << endl;
            return;
        }
    }
    cout << "--------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\t\tRoteiro com o código="<<codigo<<" não encontrado" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;

}
bool verificaRoteiroExiste(vector<Roteiro> roteiros, int codigo){
    for (const Roteiro &p : roteiros) {
        if (p.codigo == codigo)
            return true;

    }
    return false;
}

Roteiro getRoteiro(vector<Roteiro> roteiros, int codigo){
    for (const Roteiro &p : roteiros) {
        if (p.codigo == codigo)
            return p;

    }
    return Roteiro{};
}

void menuEmbarque(){
    cout << "-----------------------------------------------------------------------------" << endl;
    cout <<  setw(45) << "Menu de Embarques" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "1. Incluir um Novo embarque"<< endl;
    cout << "2. Excluir registro de embarque"<< endl; // pode ser por cpf
    cout << "3. Alterar "<< endl; 
    cout << "4. Listar todos os embarques" << endl; //listar o que os pasageiros e seus respectivos roteiro?
    cout << "0. Sair" <<endl;
    cout << "Digite uma opção:";
}
int gestaoEmbarque(vector<Embarca> &embarques, vector<Passageiro> passageiros, vector<Roteiro> roteiros){
    bool validar = true;
    int op;

    do{
        menuEmbarque();
        cin >> op;
        switch (op){
            case 1:
                incluirEmbarque(embarques, passageiros, roteiros);   //incluir
                break;
            case 2:
                    // excluir
                break;
            case 3:
                    // Alterar;
                break;
            case 4: 
                listarEmbarque(embarques);    // Lista;
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
void incluirEmbarque(vector<Embarca> &embarques, vector<Passageiro> passageiros, vector<Roteiro> roteiros){
    string erro="";
    int dia, mes, ano;
    string cpf;
    int cod_roteiro;
    Data dataEmbarque;
    int horaEmbarque;
    int duracaoEmbarque;
    char realizado;
    Passageiro passageiroAtual;
    Roteiro roteiroAtual;

    //Não permite incluir um cpf em branco
    do{  
        cout << "Digite o CPF:" << endl;
        cin >> cpf;
    } while (cpf=="");
    
    //Não permite incluir um cpf repetido
    bool encontrou_cpf = verificaPassageiroExiste(passageiros, cpf);

    if (encontrou_cpf){
        cout << "Digite o codigo do roteiro:" << endl;
        cin >> cod_roteiro;
        bool encontrou_codigo = verificaRoteiroExiste(roteiros, cod_roteiro);
            if (encontrou_codigo){
                 //não permite incluir uma data invalida
                do {
                    cout << "Qual a data: Dia:" << endl;
                    cin >> dia;
                    cout << "Mes:" << endl;
                    cin >> mes;
                    cout << "Ano:" << endl;
                    cin >> ano;
                    inicializarData(dia, mes, ano, erro, dataEmbarque);
                    if (erro!="")
                        cout << "Erro ao inicializar data: " << erro << endl;
                } while (erro != "");

                //não permite incluir uma hora fora do intervalo previsto
                do
                {
                    cout << "Digite hora: intervalo permitido [1-20]" << endl;
                    cin >> horaEmbarque;
                } while (horaEmbarque < 1 || horaEmbarque > 20);


                //não permite incluir uma duracao maior que 10
                do
                {
                    cout << "Digite duração para esse roteiro: intervalo permitido [1-10]" << endl;
                    cin >> duracaoEmbarque;
                } while (duracaoEmbarque < 1 || duracaoEmbarque > 10);
                
                do
                {
                    cout << "O embarque foi realizado? (s/n)" << endl;
                    cin >> realizado;
                } while (realizado != 's' && realizado != 'S' && realizado != 'n' && realizado != 'N' );
                
                Embarca atual;

                atual.data = dataEmbarque;
                atual.hora = horaEmbarque;
                atual.duracao = duracaoEmbarque;
                atual.realizada = realizado;
                atual.passageiro = getPassageiro(passageiros,  cpf);
                atual.roteiro = getRoteiro(roteiros,  cod_roteiro);

                embarques.push_back(atual);
            }


    }

                
    
        
    


}
//void listarEmbarque(vector<Embarca> embarques) //se dentro da struct tiver o Objeto Roteiro
void listarEmbarque(vector<Embarca> embarques){
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << left << setw(50) << "Embarques Realizados" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    for (const Embarca &e : embarques) {
        if (e.realizada=='s' || e.realizada=='S')
        {    
            cout << "Data de Embarque: " << dataParaString(e.data) << endl;
            cout << "Hora de Embarque: " << e.hora << endl;
            cout << "Duração: " << e.duracao << " horas" << endl << endl;
            //cout << left << setw(19) << dataParaString(e.data) << setw(13) << e.hora << e.duracao << endl;
            cout << "Passageiro:" << endl;
            cout << "--------------------" << endl;
            cout << "\tCPF: " << e.passageiro.cpf << ", Nome: " << e.passageiro.nome << endl;
            
            cout << endl;
            
            cout << "Roteiro:" << endl;
            cout << "--------------------" << endl;
            cout << "\tCódigo: " << e.roteiro.codigo << ", Origem: " << e.roteiro.origem << ", Destino: " << e.roteiro.destino << endl;
            
            cout << "-----------------------------------------------------------------------------" << endl;
        }
    }

    cout << "-----------------------------------------------------------------------------" << endl;
    cout << left << setw(50) << "Embarques não Realizados" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    for (const Embarca &e : embarques) {
        if (e.realizada!='s'){
            cout << "Data de Embarque: " << dataParaString(e.data) << endl;
            cout << "Hora de Embarque: " << e.hora << endl;
            cout << "Duração: " << e.duracao << " horas" << endl << endl;
            //cout << left << setw(19) << dataParaString(e.data) << setw(13) << e.hora << e.duracao << endl;
            cout << "Passageiro:" << endl;
            cout << "--------------------" << endl;
            cout << "\tCPF: " << e.passageiro.cpf << ", Nome: " << e.passageiro.nome << endl;
            
            cout << endl;
            
            cout << "Roteiro:" << endl;
            cout << "--------------------" << endl;
            cout << "\tCódigo: " << e.roteiro.codigo << ", Origem: " << e.roteiro.origem << ", Destino: " << e.roteiro.destino << endl;
            
            cout << "-----------------------------------------------------------------------------" << endl;
        }
    }   
    
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << endl;

}


void menuOcorrencia(){
    cout << "-----------------------------------------------------------------------------" << endl;
    cout <<  setw(45) << "Menu de Ocorrncia" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "1. Incluir uma ocorrência"<< endl; //solicita o CPF e Código
    cout << "2. Excluir uma ocorrência"<< endl; //solicita o CPF e Código
    cout << "3. Alterar uma ocorrência"<< endl; //solicita o CPF e Código
    cout << "4. Listar todas as ocorrências por Passageiro" << endl; //Solicita o CPF
    cout << "4. Listar todas as ocorrências por Roteiro" << endl; //Solicita o Codigo
    cout << "0. Sair" <<endl;
    cout << "Digite uma opção:";
}

void menu(){
    cout << "-----------------------------------------------------------------------------" << endl;
    cout <<  setw(40) << "Bem vindo a Vans TransPaGente" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "1. Acessar Menu de Passageiro"<< endl;
    cout << "2. Acessar Menu de Roteiro"<< endl; 
    cout << "3. Acessar Menu de Embarque"<< endl; 
    cout << "0. Sair"<< endl;
}