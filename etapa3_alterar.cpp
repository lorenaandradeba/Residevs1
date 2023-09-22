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