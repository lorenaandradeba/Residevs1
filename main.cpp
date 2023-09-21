#include <iostream>
#include <string>
#include <vector>
#include "validar.cpp"

#include "passageiro.cpp" //arquivo que gerencia os passageiros;
#include "roteiro.cpp"//arquivo que gerencia os roteiros
#include "embarca.cpp"

using namespace std;
int menuPrincipal();
bool gerenciarAcessos(int op, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros, vector<Embarca> &embarques);

int main (){
    vector<Passageiros> passageiros;//vectores principais
    vector<Roteiros> roteiros;//vectores principais
    vector<Embarca> embarques;//vectores principais
   
    Passageiros novaPassoa;
    novaPassoa.nome = "Daniel";
    novaPassoa.cpf = "1";
    novaPassoa.numAltorizacao = 1;
    novaPassoa.dataNascimento = "22/03/2001";

    Roteiros novoRoteiro;
    novoRoteiro.codigo = 1;
    novoRoteiro.origem = "Ilheus";
    novoRoteiro.destino = "Serra Grande";
    novoRoteiro.data_hora_prevista.data = "25/05/2025";
    novoRoteiro.data_hora_prevista.hora = 2;

    bool continuar = true;

    do{
        //1ºparamentro uma opcao escolhida, 2º e 3º os vectores;
        continuar = gerenciarAcessos(menuPrincipal(), passageiros, roteiros, embarques);
        //o retono é true ou false para encerrar o acesso ou sair o while. na variavel continuar   
    } while (continuar);//continuar a execução do  gerenciarAcessos sai do programa;
    
    return 0;
} 

bool gerenciarAcessos(int op, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros, vector<Embarca> &embarques){
     switch (op){
        case 1:
            gestaoDePassageiros(passageiros);// vai para o arquivo passageiro.cpp
            break;
        case 2:
            gestaoDeRoteiros(roteiros);// vai para o arquivo roteiro.cpp
            break;
        case 3:
            gestaoDeEmbarque(passageiros, roteiros, embarques);//3 vectores
            break;
        case 0:
           return false;
        default:
                return true;////continuar o gerenciarAcesso o usuario digitou uma opçao invalida
        }
        return true;//continuar o gerenciarAcesso;
}

int menuPrincipal(){
    int op = 0;
    cout <<endl <<"----------------------------" <<endl;
    cout << "1-Gestao de Passageiro" <<endl;
    cout << "2-Gerenciar Roteiro" <<endl;
    cout << "3-Gerenciar Embarque" <<endl;
    cout << "0-Sair" <<endl;
    cout << "Digite uma opcao:";

    cin >>op;
    cout<<endl; 
    return op;
}