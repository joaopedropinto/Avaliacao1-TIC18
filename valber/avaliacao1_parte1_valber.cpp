#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <ctime>
#include <sstream>

using namespace std;

struct Passageiro
{
    string cpf;
    string nome;
    string dataNascimento;
    string numAutorizacao;
};

int calcularIdade(string &dataNascimento) {

    vector<int> componentesData;
    istringstream ss(dataNascimento);
    string componente;
    while (getline(ss, componente, '/')) {
        componentesData.push_back(stoi(componente));
    }

    if (componentesData.size() != 3) {
        cerr << "Formato de data inválido!" << endl;
        return -1;
    }

    int dia = componentesData[0];
    int mes = componentesData[1];
    int ano = componentesData[2];

    time_t agora = time(nullptr);
    tm tmAtual = *localtime(&agora);

    int idade = tmAtual.tm_year + 1900 - ano;

    if (mes > tmAtual.tm_mon + 1 || (mes == tmAtual.tm_mon + 1 && dia > tmAtual.tm_mday)) {
        idade--;
    }

    return idade;
}

void criaPassageiro(vector<Passageiro> &passageiros)
{
    Passageiro passageiro;
    regex cpfValido("[0-9]{3}\\.?[0-9]{3}\\.?[0-9]{3}\\-?[0-9]{2}"),
        dataValida("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\\d{4}$");

    cout << "CPF: ";
    cin >> passageiro.cpf;

    while (true)
    {
        if (regex_match(passageiro.cpf, cpfValido))
        {
            break;
        }
        else
        {
            cout << "CPF invalido, digite novamente: ";
            cin >> passageiro.cpf;
        }
    }

    for (Passageiro &it : passageiros)
    {
        if (it.cpf == passageiro.cpf)
        {
            cout << "CPF ja cadastrado!" << endl;
            return;
        }
    }

    cout << "Nome: ";
    cin.ignore();
    getline(cin, passageiro.nome);

    cout << "Data de Nascimento (dia/mes/ano): ";
    cin >> passageiro.dataNascimento;

    while (true)
    {
        if (regex_match(passageiro.dataNascimento, dataValida))
        {
            break;
        }
        else
        {
            cout << "Data invalida, digite novamente: ";
            cin >> passageiro.dataNascimento;
        }
    }

    if(calcularIdade(passageiro.dataNascimento) < 18) {
        cout << "Numero de Autorizacao: ";
        cin >> passageiro.numAutorizacao;

        for (Passageiro &it : passageiros)
        {
            if (it.numAutorizacao == passageiro.numAutorizacao)
            {
                cout << "Numero de autorizacao ja cadastrado!" << endl;
                return;
            }
        }
    } else {
        passageiro.numAutorizacao = "";
    }


    passageiros.push_back(passageiro);

    cout << "Passageiro inserido!" << endl;
}

void excluirPassageiro(vector<Passageiro> &passageiros)
{
    string cpf;
    cout << "Digite o CPF do passageiro para excluir: ";
    cin >> cpf;

    for (auto it = passageiros.begin(); it != passageiros.end(); ++it)
    {
        if (it->cpf == cpf)
        {
            passageiros.erase(it);
            cout << "Passageiro excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "Passageiro nao encontrado." << endl;
}

void alteraPassageiro(vector<Passageiro> &passageiros)
{
    string cpf;
    char decisao;

    cout << "Deseja alterar o CPF? (s/n): ";
    cin >> decisao;

    if (decisao == 's')
    {
        excluirPassageiro(passageiros);
        criaPassageiro(passageiros);
        return;
    }

    cout << "Digite o CPF do passageiro que terá os dados alterados: ";
    cin >> cpf;

    for (Passageiro &it : passageiros)
    {
        if (it.cpf == cpf)
        {
            cout << "Deseja mudar o nome? (s/n): ";
            cin >> decisao;

            if (decisao == 's')
            {
                cout << "Novo Nome: ";
                cin.ignore();
                getline(cin, it.nome);
            }

            cout << "Deseja mudar a data de nascimento? (s/n): ";
            cin >> decisao;

            if (decisao == 's')
            {
                string dataAux = it.dataNascimento;
                cout << "Nova Data de Nascimento: ";
                cin >> it.dataNascimento;

                if(calcularIdade(dataAux) >= 18 && calcularIdade(it.dataNascimento) < 18) {
                    cout << "Agora o passageiro precisa de numero de autorizacao, insira por favor: ";
                    cin >> it.numAutorizacao;

                    for (Passageiro &itAutorizacao : passageiros)
                    {
                        if (itAutorizacao.numAutorizacao == it.numAutorizacao)
                        {
                            cout << "Numero de autorizacao ja cadastrado!" << endl;
                            return;
                        }
                    }
                }
            }

            if(it.numAutorizacao != "" || calcularIdade(it.dataNascimento) < 18) {
                cout << "Deseja mudar o numero de autorizacao? (s/n): ";
                cin >> decisao;

                if (decisao == 's')
                {
                    cout << "Novo Número de Autorizacao: ";
                    cin >> it.numAutorizacao;

                    for (Passageiro &itAutorizacao : passageiros)
                    {
                        if (itAutorizacao.numAutorizacao == it.numAutorizacao)
                        {
                            cout << "Numero de autorizacao ja cadastrado!" << endl;
                            return;
                        }
                    }
                }
            }

            cout << "Passageiro atualizado com sucesso!" << endl;
            return;
        }
    }

    cout << "Passageiro nao encontrado." << endl;
}

void listaPassageiro(vector<Passageiro> &passageiros)
{
    if (passageiros.empty())
    {
        cout << "Nao existem passageiros!" << endl;
        return;
    }
    cout << "Passageiros:" << endl;
    for (Passageiro &it : passageiros)
    {
        if(it.numAutorizacao != "") {
            cout << "CPF: " << it.cpf << ", Nome: " << it.nome << ", Data de Nascimento: " << it.dataNascimento << ", Número de Autorização: " << 
            it.numAutorizacao << endl;
        } else {
            cout << "CPF: " << it.cpf << ", Nome: " << it.nome << ", Data de Nascimento: " << it.dataNascimento << endl;
        }
    }
}

void localizaPassageiro(vector<Passageiro> &passageiros)
{
    string cpf;
    cout << "Digite o CPF do passageiro para localizar: ";
    cin >> cpf;

    if (passageiros.empty())
    {
        cout << "A lista de passageiros está vazia." << endl;
        return;
    }

    for (Passageiro &it : passageiros)
    {
        if (it.cpf == cpf)
        {
            if(it.numAutorizacao != "") {
                cout << "Passageiro encontrado!" << endl;
                cout << "CPF: " << it.cpf << ", Nome: " << it.nome << ", Data de Nascimento: " << it.dataNascimento << ", Número de Autorização: " << 
                it.numAutorizacao << endl;
                return;
            } else {
                cout << "Passageiro encontrado!" << endl;
                cout << "CPF: " << it.cpf << ", Nome: " << it.nome << ", Data de Nascimento: " << it.dataNascimento << endl;
                return;
            }
            
        }
    }

    cout << "Passageiro nao encontrado!" << endl;
}

int main()
{
    vector<Passageiro> listaPassageiros;
    int opt;

    while (true)
    {
        cout << endl << "Escolha uma opcao:" << endl;
        cout << "Criar passageiro - 1" << endl;
        cout << "Excluir passageiro - 2" << endl;
        cout << "Alterar passageiro - 3" << endl;
        cout << "Listar passageiros - 4" << endl;
        cout << "Localizar passageiro - 5" << endl;
        cout << "Sair  - 0" << endl;

        cin >> opt;

        switch (opt)
        {
        case 1:
            criaPassageiro(listaPassageiros);
            break;
        case 2:
            excluirPassageiro(listaPassageiros);
            break;
        case 3:
            alteraPassageiro(listaPassageiros);
            break;
        case 4:
            listaPassageiro(listaPassageiros);
            break;
        case 5:
            localizaPassageiro(listaPassageiros);
            break;
        case 0:
            cout << "Programa finalizado!" << endl;
            return 0;
        default:
            cout << "Digite um valor válido!" << endl;
        }
    }

    return 0;
}