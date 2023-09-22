//protótipos
void excluirOcorrencia(vector<Ocorrencia> &ocorrencia, vector<Embarca> &embarques, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros);
void alterarOcorrencia(vector<Ocorrencia> &ocorrencia, vector<Embarca> &embarques, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros);


//funções
void excluirOcorrencia(vector<Ocorrencia> &ocorrencia, vector<Embarca> &embarques, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros){
    int codigo;
    string cpf;
    int indice_passageiro;
    int indice_roteiro;
    int indice_ocorrencia;
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
    indice_ocorrencia = 0; //criar função pra pegar indice

    if ( (indice_roteiro != -1) && (indice_passageiro != -1) && (indice_ocorrencia != -1) )
    {
        cout << endl <<"Dados Validos!"<< endl;
        
        vector<Ocorrencia>::iterator it;
        
        it = ocorrencia.begin();
        advance(it, indice_ocorrencia);
        ocorrencia.erase(it); // exclui a ocorrência
    } else {
         cout << endl << "Dados Invalidos" << endl;
    }
}

void alterarOcorrencia(vector<Ocorrencia> &ocorrencia, vector<Embarca> &embarques, vector<Passageiros> &passageiros, vector<Roteiros> &roteiros){
    int codigo;
    string cpf;
    int indice_passageiro;
    int indice_roteiro;
    int indice_ocorrencia;
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
    indice_ocorrencia = 0; //VER ISSOA QUI

    if ( (indice_roteiro != -1) && (indice_passageiro != -1) && (indice_ocorrencia != -1)) {
        cout << endl <<"Dados Validos!"<< endl;
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
            descricao = ocorrencia[indice_ocorrencia].descricao;
        }
        
        cout << "Deseja alterar a data (s/n)? ";
        cin >> flag;

        if ( flag == "s" ) {
            cout <<"Informe a data: " << endl;
            cin.ignore(); 
            getline(cin, data);
        } else {
            data = ocorrencia[indice_ocorrencia].data;
        }

        cout << "Deseja alterar a hora (s/n)? ";
        cin >> flag;

        if ( flag == "s" ) {
            cout <<"Informe a hora: " << endl;
            cin >> hora;
        } else {
            hora = ocorrencia[indice_ocorrencia].hora;
        }

        cout << "Deseja alterar o numero do Apolice (s/n)? ";
        cin >> flag;

        if ( flag == "s" ) {
            cout <<"Informe o numero do Apolice: " << endl;
            cin >> numApolice;
        } else {
            numApolice = ocorrencia[indice_ocorrencia].numApolice;
        }
    } else {
         cout << endl << "Dados Invalidos" << endl;
    }
}