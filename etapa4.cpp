int registrarOcorrenciaPorRoteiro () {
    int codigo;
    Ocorrencia ocorrencia_atual;

    cout << "Digite o codigo do roteiro: " << endl;
    cin >> codigo;

    cout << "Descreva o que aconteceu:" << endl;
    cin.ignore(); 
    getline(cin, ocorrencia_atual.descricao);
        
    cout <<"Informe a data: " << endl;
    cin.ignore(); 
    getline(cin, ocorrencia_atual.data);

    cout <<"Informe a hora: " << endl;
    cin >> ocorrencia_atual.hora;
    
    cout <<"Informe o numero do Apolice: " << endl;
    cin >> ocorrencia_atual.numApolice;

    // rodar em todos os embarques
    for (Embarca embarque: embarques) {
        //ver se o embarque está vinculado ao código em questão
        if (embarque.roteiro.codigo == codigo) {
            embarque.ocorrencia = ocorrencia_atual.ocorrencia; //sem perguntar nada
            //embarque.ocorrencia.push_back(ocorrencia_atual.ocorrencia); //se for vetor

            /*
            // se for pra perguntar sobre sobrescrever
            if (embarque.ocorrencia.descricao.empty())
            {
                cout << "Já existe uma ocorrencia vinculada a esse roteiro no embarque do passageiro " << embarque.passageiro.nome << ".\n
                Deseja sobrescrever (s/n)?"

                if (flag == "s") {
                    embarque.ocorrencia = ocorrencia_atual.ocorrencia; //sem perguntar nada
                    embarque.ocorrencia.push_back(ocorrencia_atual.ocorrencia); //se for vetor
                }
            }
            */
        }
    }
}