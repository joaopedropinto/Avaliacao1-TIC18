#include <iostream>
#include <vector>
#include <string>
#include <regex>

struct Ocorrencia
{
    string descricao = "Sem ocorrências";
    string data_Hora = "Sem data hora";
    string numeroApolice = "Sem numero";
};

struct Embarque
{
    Passageiro passageiro = {};
    Roteiro roteiro = {};
    string data_Hora = "";
    string duracao = "";
    bool realizada = false;
    Ocorrencia ocorrencia = {};
};

void criaEmbarque(vector<Embarque> &embarques, vector<Passageiro> &passageiros, vector<Roteiro> &roteiros)
{
    regex datahoraValida(R"((0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4} (0[0-9]|1[0-9]|2[0-3]):[0-5][0-9])"),
        duracaoValida("([01]?[0-9]|2[0-3]):[0-5][0-9]");
    Passageiro passageiro;
    Roteiro roteiro;
    Embarque embarque;
    string cpf, codigo;
    char aconteceuEmbarque;
    bool flag = false;

    cout << "\nInforme o CPF do passageiro que vai embarcar (xxx.xxx.xxx-xx): ";
    cin >> cpf;

    for (auto &it : passageiros)
    {
        if (it.cpf == cpf)
        {
            passageiro = it;
            flag = true;
        }
    }

    if (!flag)
    {
        cout << "\nPassageiro não encontrado" << endl;
        return;
    }

    flag = false;

    cout << "Informe o código do roteiro do embarque: ";
    cin >> codigo;

    for (auto &it : roteiros)
    {
        if (it.codigo == codigo)
        {
            roteiro = it;
            flag = true;
        }
    }

    if (!flag)
    {
        cout << "\nRoteiro não encontrado" << endl;
        return;
    }

    cout << "Informe a Data e Hora real do embarque (dd/mm/aaaa hh:mm): ";
    cin.ignore();
    getline(cin, embarque.data_Hora);

    while (true)
    {
        if (regex_match(embarque.data_Hora, datahoraValida))
        {
            break;
        }
        else
        {
            cout << "\nData ou hora inválida (dd/mm/aaaa hh:mm), tente novamente: ";
            getline(cin, embarque.data_Hora);
        }
    }

    cout << "Informe a duração do embarque (hh:mm): ";
    cin >> embarque.duracao;

    while (true)
    {
        if (regex_match(embarque.duracao, duracaoValida))
        {
            break;
        }
        else
        {
            cout << "\nDuração inválida (hh:mm), tente novamente: ";
            cin >> embarque.duracao;
        }
    }

    cout << "O embarque já aconteceu? (S/N): ";
    cin >> aconteceuEmbarque;

    while (true)
    {
        if (aconteceuEmbarque == 's' || aconteceuEmbarque == 'S')
        {
            embarque.realizada = true;
            break;
        }
        else if (aconteceuEmbarque == 'n' || aconteceuEmbarque == 'N')
        {
            embarque.realizada = false;
            break;
        }
        else
        {
            cout << "Por favor, informe uma opção válida, o embarque já aconteceu? (S/N): ";
            cin >> aconteceuEmbarque;
        }
    }

    embarques.push_back({passageiro, roteiro, embarque.data_Hora, embarque.duracao, embarque.realizada});
}

void excluirEmbarque(vector<Embarque> &embarques){
    Passageiro passageiro;
    Roteiro roteiro;
    Embarque embarque;
    string cpf, codigo;
    cout << "Informe o código do roteiro: ";
    cin >> codigo;

    cout << "Passageiros embarcados nesse roteiro:" << endl;
    for (Embarque &it : embarques)
    {
        if (it.roteiro.codigo == codigo)
        {
            if (it.passageiro.numAutorizacao != "")
            {
                cout << "CPF: " << it.passageiro.cpf << ", Nome: " << it.passageiro.nome << ", Data de nascimento: " << it.passageiro.dataNascimento << ", Número de autorização: "
                     << it.passageiro.numAutorizacao << endl;
            }
            else
            {
                cout << "CPF: " << it.passageiro.cpf << ", Nome: " << it.passageiro.nome << ", Data de nascimento: " << it.passageiro.dataNascimento << endl;
            }
        }
    }

    cout << "Informe o CPF de qual passageiro listado não embarcará: ";
    cin >> cpf;

    for (auto it = embarques.begin(); it != embarques.end(); ++it)
    {
        if (it->roteiro.codigo == codigo && it->passageiro.cpf == cpf)
        {
            embarques.erase(it);
            cout << "\nEmbarque excluido com sucesso.\n";
            return;
        }
    }

    cout << "\nPassageiro não encontrado!" << endl;
}

void alteraEmbarque(vector<Embarque> &embarques)
{
    string codigo, cpf;

    cout << "Informe o código do roteiro do embarque: ";
    cin >> codigo;

    cout << "Passageiros embarcados nesse roteiro:" << endl;
    for (Embarque &it : embarques)
    {
        if (it.roteiro.codigo == codigo)
        {
            if (it.passageiro.numAutorizacao != "")
            {
                cout << "CPF: " << it.passageiro.cpf << ", Nome: " << it.passageiro.nome << ", Data de nascimento: " << it.passageiro.dataNascimento << ", Número de autorização: "
                     << it.passageiro.numAutorizacao << endl;
            }
            else
            {
                cout << "CPF: " << it.passageiro.cpf << ", Nome: " << it.passageiro.nome << ", Data de nascimento: " << it.passageiro.dataNascimento << endl;
            }
        }
    }

    cout << "Informe o CPF de qual passageiro será alterado: ";
    cin >> cpf;

    for (Embarque &it : embarques)
    {
        if (it.roteiro.codigo == codigo && it.passageiro.cpf == cpf)
        {
            cout << "Informe a nova duração do embarque: ";
            cin.ignore();
            getline(cin, it.duracao);
            cout << "Registro de embarque alterado com sucesso!\n";
            return;
        }
    }

    cout << "\nPassageiro não encontrado no embarque." << endl;
}

void listaEmbarque(vector<Embarque> &embarques)
{
    string aconteceu = "Não";

    if (embarques.empty())
    {
        cout << "\nNão existem embarques cadastrados!" << endl;
        return;
    }
    cout << "\nLista de embarques cadastrados:" << endl;
    for (Embarque &it : embarques)
    {
        if(it.realizada == 1) {
            aconteceu = "Sim";
        }

        cout << "Passageiro" << endl;
        if (it.passageiro.numAutorizacao != "")
        {
            cout << "CPF: " << it.passageiro.cpf << ", Nome: " << it.passageiro.nome << ", Data de nascimento: " << it.passageiro.dataNascimento << ", Número de autorização: " << it.passageiro.numAutorizacao << endl;
        }
        else
        {
            cout << "CPF: " << it.passageiro.cpf << ", Nome: " << it.passageiro.nome << ", Data de nascimento: " << it.passageiro.dataNascimento << endl;
        }
        cout << "Roteiro" << endl;
        cout << "Código: " << it.roteiro.codigo << ", Data hora prevista: " << it.roteiro.dataHoraPrevista << ", Duracao prevista: " << it.roteiro.duracaoPrevista << ", Origem: " << it.roteiro.origem << ", Destino: " << it.roteiro.destino << endl;
        cout << "Embarque" << endl;
        cout << "Data hora real: " << it.data_Hora << ", Duração: " << it.duracao << ", Já aconteceu? " << aconteceu << endl
             << endl;
    }
}

void menuEmbarque(vector<Embarque> &embarques, vector<Passageiro> &passageiros, vector<Roteiro> &roteiros)
{
    while(true){

        cout << endl
            << "==== Gestão de Embarques ==== " << endl
            << "Serviços disponíveis:" << endl;
        cout << "1. Incluir embarque" << endl;
        cout << "2. Excluir embarque" << endl;
        cout << "3. Alterar (apenas por código de roteiro e CPF de passageiro)" << endl;
        cout << "4. Listar embarques" << endl;
        cout << "0. Voltar ao Menu Principal" << endl;
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        switch (opcao)
        {

        case 1:
            criaEmbarque(embarques, passageiros, roteiros);
            break;
        case 2:
            excluirEmbarque(embarques);
            break;
        case 3:
            alteraEmbarque(embarques);
            break;
        case 4:
            listaEmbarque(embarques);
            break;
        case 0:
            cout << "Voltando ao menu principal" << endl;
            return;

        default:
            cout << "Informe um valor válido!" << endl;
            break;
        }
    }
}