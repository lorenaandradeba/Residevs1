#include <iostream>
#include <string>
#include <vector>
#include "validar.cpp"

#include "passageiro.cpp" //arquivo que gerencia os passageiros;
#include "roteiro.cpp"//arquivo que gerencia os roteiros
#include "embarca.cpp"
#include "ocorrencia.cpp"
// #include "ocorrenciaRoteiro.cpp"

using namespace std;
int menuPrincipal();
bool gerenciarAcessos(int op, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros, 
vector<Embarca> &embarques);

int main (){
    vector<Passageiros> passageiros;//vectores principais
    vector<Roteiros> roteiros;//vectores principais
    vector<Embarca> embarques;//vectores principais
   

    bool continuar = true;

    do{
        //1ºparamentro uma opcao escolhida, 2º e 3º os vectores;
        continuar = gerenciarAcessos(menuPrincipal(), passageiros, roteiros, embarques);
        //o retono é true ou false para encerrar o acesso ou sair o while. na variavel continuar   
    } while (continuar);//continuar a execução do  gerenciarAcessos sai do programa;
    
    return 0;
} 

bool gerenciarAcessos(int op, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros, 
vector<Embarca> &embarques){

    //objetos do tipo struc
    Passageiros novoPassageiro;
    Roteiros novoRoteiro;
    Embarca novoEmbarque;
    Ocorrencia novaOcorrencia;
   
   
    //primeiro cadastro de Passageiro
   
    novoPassageiro.cpf = "1";
    novoPassageiro.nome = "lorena";
    novoPassageiro.dataNascimento = "1";
    novoPassageiro.numAltorizacao = 1;
    
    passageiros.push_back(novoPassageiro);

    //Primeiro Cadastro de roteiro
    novoRoteiro.codigo = 1;
    novoRoteiro.data_hora_prevista.data = 1;
    novoRoteiro.data_hora_prevista.hora = 1;
    
    novoRoteiro.origem ="Ilheus";
    novoRoteiro.destino = "Serra Grande";

    roteiros.push_back(novoRoteiro);
    
    //segundo cadastro de Passageiro
    novoPassageiro.cpf = "2";
    novoPassageiro.nome = "Daniel";
    novoPassageiro.dataNascimento = "1";
    novoPassageiro.numAltorizacao = 1;
    
    passageiros.push_back(novoPassageiro);

    //segundo cadatro de roteiro
    novoRoteiro.codigo = 2;
    novoRoteiro.data_hora_prevista.data = 1;
    novoRoteiro.data_hora_prevista.hora = 1;
    
    novoRoteiro.origem ="ilheus";
    novoRoteiro.destino = "itabuna";

    roteiros.push_back(novoRoteiro);


    ///Primeiro embarque
    novoEmbarque.data.data = 22/03/2023;
    novoEmbarque.data.hora = 2;
    novoEmbarque.roteiro =  roteiros[1];
    novoEmbarque.realizada = "S";
    novoEmbarque.passageiro = passageiros[1];
    embarques.push_back(novoEmbarque);

    ///Segundo embarque
    novoEmbarque.data.data = 22/03/2023;
    novoEmbarque.data.hora = 1;
    novoEmbarque.roteiro =  roteiros[0];
    novoEmbarque.realizada = "S";
    novoEmbarque.passageiro = passageiros[1];
    embarques.push_back(novoEmbarque);

    ///Terceiro embarque
    novoEmbarque.data.data = 22/03/2023;
    novoEmbarque.data.hora = 1;
    novoEmbarque.roteiro =  roteiros[0];
    novoEmbarque.realizada = "S";
    novoEmbarque.passageiro = passageiros[0];
    embarques.push_back(novoEmbarque);

    //Quarto embarque
    novoEmbarque.data.data = 22/03/2023;
    novoEmbarque.data.data = 1;
    novoEmbarque.realizada = "S";
    novoEmbarque.roteiro =  roteiros[1];
    novoEmbarque.passageiro = passageiros[0];
    embarques.push_back(novoEmbarque);

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
        case 4:
            gestaoOcorrencia(embarques);
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
    cout << "4-Gerenciar Ocorrencias por Embarque" <<endl;
    cout << "0-Sair" <<endl;
    cout << "Digite uma opcao:";

    cin >>op;
    cout<<endl; 
    return op;
}