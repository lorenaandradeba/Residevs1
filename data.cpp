#ifndef DATA_H
#define DATA_H

#include <string>

struct Data {
    int dia;
    int mes;
    int ano;
};

bool dataValida(int dia, int mes, int ano, std::string &erro);
void inicializarData(int dia, int mes, int ano, std::string &erro, Data &data);
bool dataValida(Data data);
void alteraData(Data *data, int dia, int mes, int ano);
std::string to_string_zeros(int numero);
std::string dataParaString(Data data);

#endif // DATA_H