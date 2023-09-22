void alterarOcorrencia(vector<Embarca> &embarques){
    int codigo;
    string cpf;
    int indice_embarque;
    bool encontrou = false;
    string nomePassageiro;

    cout <<endl << "Informe o CPF: ";
    cin.ignore();
    getline(cin, cpf);
                    
    cout << "Digite o codigo: ";
    cin >> codigo;
    cout<<endl;

    // localizar o índice do embarque a ser alterado
    indice_embarque = localizarEmbarque(embarques, cpf, codigo);

    if ( indice_embarque != -1 ) {
        cout << endl << "Dados Validos!" << endl;

        for (size_t i = 0; i < embarques.size(); i++) {
            if (embarques[i].passageiro.cpf == cpf && embarques[i].roteiro.codigo == codigo){
                encontrou = true;
                nomePassageiro = embarques[i].passageiro.nome;
                
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
                    embarques[i].descricao = descricao;
                }
                
                cout << "Deseja alterar a data (s/n)? ";
                cin >> flag;

                if ( flag == "s" ) {
                    cout <<"Informe a data: " << endl;
                    cin.ignore(); 
                    getline(cin, data);
                } else {
                    embarques[i].data = data;
                }

                cout << "Deseja alterar a hora (s/n)? ";
                cin >> flag;

                if ( flag == "s" ) {
                    cout <<"Informe a hora: " << endl;
                    cin >> hora;
                } else {
                    embarques[i].hora = hora;
                }

                cout << "Deseja alterar o numero do Apolice (s/n)? ";
                cin >> flag;

                if ( flag == "s" ) {
                    cout <<"Informe o numero do Apolice: " << endl;
                    cin >> numApolice;
                } else {
                    embarques[i].numApolice = numApolice;
                }

                cout << "-----------------------------------------------------------------------------" << endl;
                cout << "\t\tOcorrência de "<<nomePassageiro<<" do Roteiro "<<codigo<<" foi alterada com sucesso." << endl;
                cout << "-----------------------------------------------------------------------------" << endl;
            }
        }
        if (!encontrou){
            cout << "-----------------------------------------------------------------------------" << endl;
            cout << "\t\tOps! Ocorrência não encontrada." << endl;
            cout << "-----------------------------------------------------------------------------" << endl;
        }
    } else {
         cout << endl << "Dados Invalidos" << endl;
    }
}