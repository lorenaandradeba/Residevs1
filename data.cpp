#include <iostream>
#include <string>

using namespace std;

struct Data {
    int dia;
    int mes;
    int ano;
};

bool dataValida (int dia, int mes, int ano) {
    if (ano < 1900 || ano > 2100) { return false; }
    if (mes < 1 || mes > 12) { return false; }
    int diasNoMes = 0;
    if (mes == 2) {
        diasNoMes = 
        (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        diasNoMes = 30;
    }
    else {
        diasNoMes = 31;
    }
    if (dia < 1 || dia > diasNoMes) { return false; }

    return true;
}

bool dataValida(struct Data data) {
    return dataValida(data.dia, data.mes, data.ano);
}

void alteraData(struct Data *data, int dia, int mes, int ano) {
    if(dataValida(dia, mes, ano)) {
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
    string numeroString = to_string(numero);

    if (numero < 10){
        numeroString = "0" + numeroString;
    }

    return numeroString;
}

string dataParaString(struct Data data)
{
    string dia = to_string_zeros(data.dia);
    string mes = to_string_zeros(data.mes);
    string ano = to_string_zeros(data.ano);

    return dia+"/"+mes+"/"+ano;
}