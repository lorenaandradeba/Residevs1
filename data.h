#include <iostream>
#include <string>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};
bool dataValida (int dia, int mes, int ano, std::string &erro) {
    erro = "";
    if (ano < 1900 || ano > 2100) { 
        erro = "Ano está fora no intervalo 1900-2100";
        return false; 
    }
    if (mes < 1 || mes > 12) { 
        erro = "Mês está fora no intervalo 1-12";
        return false; 
    }
    int dias_no_mes = 0;
    if (mes == 2) {
        dias_no_mes = 
        (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        dias_no_mes = 30;
    }
    else {
        dias_no_mes = 31;
    }
    if (dia < 1 || dia > dias_no_mes) { 
        erro = "Dia do mês está fora no intervalo";
        return false; 
    }

    return true;
}
void inicializarData(int dia, int mes, int ano, std::string &erro, Data &data) {
    if(dataValida(dia, mes, ano, erro)){
        data.dia = dia;
        data.mes = mes;
        data.ano = ano;
    }else{
        data.dia = 1;
        data.mes = 1;
        data.ano = 1900;
    }
}

bool dataValida(struct Data data) {

    string erro;
    return dataValida(data.dia, data.mes, data.ano, erro);
}

void alteraData(struct Data *data, int dia, int mes, int ano) {
    string erro;
    if(dataValida(dia, mes, ano, erro)) {
        data->dia = dia;
        data->mes = mes;
        data->ano = ano;
    }
    else {
        data->dia = 1;
        data->mes = 1;
        data->ano = 1900;
    }
}

string to_string_zeros(int numero) {
    string numero_string = to_string(numero);

    if (numero < 10){
        numero_string = "0" + numero_string;
    }

    return numero_string;
}

string dataParaString(struct Data data)
{
    string dia = to_string_zeros(data.dia);
    string mes = to_string_zeros(data.mes);
    string ano = to_string_zeros(data.ano);

    return dia+"/"+mes+"/"+ano;
}
