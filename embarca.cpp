//Função Incluir embarque - LEANDRO 
bool incluirEmbarque(vector<Embarca> &embarques, vector<Passageiro> &passageiros, vector<Roteiro> &roteiros)
{
    cout << "--- Inclusão de Embarque ---" << endl;

    Embarca embarca;
    int dia, mes, ano, codigo;
    string cpf;
    int indice_passageiro;
    int indice_codigo;


     indice_passageiro = encontrarPassageiro(passageiros);
     indice_codigo = encontrarRoteiro(roteiros);

     if(indice_passageiro >= 0 && indice_codigo) // o passageiro foi encontrado.
     {
        cout << "CPF e código encontrado!";
         cout << "Insira o dia real: ";
        cin >> dia;

        cout << "Insira o mês real: ";
        cin >> mes; 

        cout << "Insira o ano real: ";
        cin >> ano; 

        cout << "Insira a hora real: ";
        cin >> embarca.hora;

        cout << "O embarque já aconteceu (s/n)? ";
        cin >> embarca.realizada;


        if (!validarData(dia, mes, ano)) // caso a data esteja inválida, seja o dia, mês ou ano.
        {
        return false;
        }

        embarca.data = formatarData(dia, mes, ano); // os valores que antes eram int, são convertidos no tipo string.
        cout << "Cadastro realizado com sucesso!";

        embarca.passageiro = passageiros[indice_passageiro];
        embarca.roteiro = roteiros[indice_codigo];

        // Encontrando a posição correta para inserir o roteiro com base no código
        auto it = lower_bound(embarques.begin(), embarques.end(), embarca, compararPorCodigo);
        // Inserindo o roteiro na posição encontrada
        embarques.insert(it, embarca);
        embarques.push_back(embarca);

        } else {
        return false; //Sai da função pois o código não foi encontrado.
     }
     
}