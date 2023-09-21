#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

struct Data
{
    int dia;
    int mes;
    int ano;
};
struct Passageiro
{
    string nome;
    string cpf;
    Data dtNascimento;
    string numAutorizacao;
};

bool teste_digito(const string &cpf)
{
    for (char c : cpf)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

bool valida_cpf(const string &cpf, vector<Passageiro> &passageiros)
{
    if (cpf.length() != 11 || !teste_digito(cpf))
    {
        return false;
    }
    else
    {
        for (auto &passageiro : passageiros)
        {
            if (passageiro.cpf == cpf)
            {
                return false;
            }
        }
        return true;
    }
}

bool data_valida(int dia, int mes, int ano)
{
    if (ano < 1900 || ano > 2100)
    {
        return false;
    }
    if (mes < 1 || mes > 12)
    {
        return false;
    }
    int diasNoMes = 0;

    if (mes == 2)
    {
        diasNoMes = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28;
    }
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        diasNoMes = 30;
    }
    else
    {
        diasNoMes = 31;
    }
    if (dia < 1 || dia > diasNoMes)
    {
        return false;
    }
    return true;
}

int calcula_idade(int dia, int mes, int ano){

    time_t agora = time(nullptr);
    tm tmNasc = {};

    tmNasc.tm_year = ano - 1900;
    tmNasc.tm_mon = mes - 1;     
    tmNasc.tm_mday = dia;  

    time_t dataNascT = std::mktime(&tmNasc);

    std::tm* tmAtual = std::localtime(&agora);

    int idade = tmAtual->tm_year - tmNasc.tm_year;

    if (tmAtual->tm_mon < tmNasc.tm_mon || (tmAtual->tm_mon == tmNasc.tm_mon && tmAtual->tm_mday < tmNasc.tm_mday)) {
        idade--;
    }

    return idade;

}

void incluir_pass(vector<Passageiro> &passageiros)
{

    int idade, dia, mes, ano;
    string cpf;
    Passageiro passageiro;
    bool teste;

    do
    {
        cout << "Informe o CPF do passageiro a ser incluído (apenas dígitos): " << endl;
        cin >> cpf;
        if (valida_cpf(cpf, passageiros))
        {
            passageiro.cpf = cpf;
            teste = true;
        }
        else
        {
            cout << "CPF inválido!" << endl;
            teste = false;
        }

    } while (teste == false);

    cout << "Informe o nome do passageiro a ser incluído: " << endl;
    cin.ignore();
    getline(cin, passageiro.nome);

    do
    {
        cout << "Informe a data de nascimento do passageiro a ser incluído: " << endl;
        cout << "Dia: (dd)" << endl;
        cin >> dia;
        cout << "Mês: (mm)" << endl;
        cin >> mes;
        cout << "Ano: (aaaa)" << endl;
        cin >> ano;

        if (data_valida(dia, mes, ano))
        {

            passageiro.dtNascimento.dia = dia;
            passageiro.dtNascimento.mes = mes;
            passageiro.dtNascimento.ano = ano;
            teste = true;
        }
        else
        {
            cout << "Data incorreta, tente novamente!" << endl;
            teste = false;
        }

    } while (teste == false);

    idade = calcula_idade(dia, mes, ano);

    if (idade < 18)
    {
        cout << "Informe o número de autorizaçao do passageiro: " << endl;
        cin >> passageiro.numAutorizacao;
    }
    else
    {
        passageiro.numAutorizacao = "Maior";
    }

    passageiros.push_back(passageiro);
}

void excluir_pass(vector<Passageiro> &passageiros)
{
    string cpf;

    cout << "Informe o CPF do passageiro a ser excluído (apenas dígitos): " << endl;
    cin >> cpf;

    for (auto it = passageiros.begin(); it != passageiros.end(); it++)
    {
        if (cpf == it->cpf)
        {
            passageiros.erase(it);
            cout << "Passageiro excluido com sucesso!" << endl;
            return;
        }
    }

    cout << "CPF " << cpf << " nao encontrado!" << endl;
}

void alterar_pass(vector<Passageiro> &passageiros)
{

    string cpf;
    int dia, mes, ano, idade;

    cout << "Informe o CPF do passageiro a ser alterado (apenas dígitos): " << endl;
    cin >> cpf;

    for (auto &passageiro : passageiros)
    {

        if (cpf == passageiro.cpf)
        {
            string resp, teste_cpf;
            bool teste;

            cout << "Passageiro encontrado!" << endl;
            cout << "Dados encontrados:" << endl;
            cout << "CPF: " << passageiro.cpf << endl;
            cout << "Nome: " << passageiro.nome << endl;
            cout << "Data de Nascimento: " << passageiro.dtNascimento.dia << "/" << passageiro.dtNascimento.mes << "/" << passageiro.dtNascimento.ano << endl;
            cout << "Numero de Autorizaçao: " << passageiro.numAutorizacao << endl;

            cout << "O CPF está incorreto? Se sim, pedimos para que insira o passageiro novamente! (S/N)" << endl;
            cin >> resp;
            if (resp == "s" || resp == "sim")
            {

                for (auto it = passageiros.begin(); it != passageiros.end(); it++)
                {
                    if (cpf == it->cpf)
                    {
                        passageiros.erase(it);
                        cout << "Passageiro excluido com sucesso!" << endl;
                        return;
                    }
                }
            }
            else
            {
                cout << "CPF nao alterado!" << endl;
            }

            cout << "Você deseja alterar o nome do passageiro?(S/N)" << endl;
            cin >> resp;
            if (resp == "s" || resp == "sim")
            {
                cout << "Informe o novo nome: " << endl;
                cin.ignore();
                getline(cin, passageiro.nome);
            }
            else
            {
                cout << "Nome nao alterado!" << endl;
            }

            cout << "Você deseja alterar a data de nascimento do passageiro?(S/N)" << endl;
            cin >> resp;
            if (resp == "s" || resp == "sim")
            {
                do
                {
                    cout << "Informe a data de nascimento do passageiro a ser incluído: " << endl;
                    cout << "Dia: (dd)" << endl;
                    cin >> dia;
                    cout << "Mês: (mm)" << endl;
                    cin >> mes;
                    cout << "Ano: (aaaa)" << endl;
                    cin >> ano;

                    if (data_valida(dia, mes, ano))
                    {

                        passageiro.dtNascimento.dia = dia;
                        passageiro.dtNascimento.mes = mes;
                        passageiro.dtNascimento.ano = ano;
                        teste = true;
                    }
                    else
                    {
                        cout << "Data incorreta, tente novamente!" << endl;
                        teste = false;
                    }

                } while (teste == false);

                idade = calcula_idade(dia, mes, ano);

                if (idade < 18)
                {
                    cout << "Informe o número de autorizaçao do passageiro: " << endl;
                    cin >> passageiro.numAutorizacao;
                }
                else
                {
                    passageiro.numAutorizacao = "Maior";
                }
            }
            else
            {
                cout << "Data de nascimento nao alterada!!" << endl;
            }
            cout << "Passageiro atualizado!" << endl;
            return;
        }
        else
        {
            cout << "Passageiro nao encontrado!" << endl;
        }
    }
}

void listar_pass(const vector<Passageiro> &passageiros)
{

    cout << "Lista de passageiros presentes: " << endl;

    for (const auto &passageiro : passageiros)
    {
        cout << "CPF: " << passageiro.cpf << ", Nome: " << passageiro.nome << ", Data de Nascimento: " 
        << passageiro.dtNascimento.dia << "/" << passageiro.dtNascimento.mes << "/" 
        << passageiro.dtNascimento.ano << " Número de autorizaçao: " << passageiro.numAutorizacao << endl;
    }
    
}

void localizar_pass(const vector<Passageiro> &passageiros)
{
    Passageiro passageiro;
    string cpf;

    cout << "Informe o CPF do passageiro a ser localizado: " << endl;
    cin >> cpf;

    for (const auto &passageiro : passageiros)
    {
        if (cpf == passageiro.cpf)
        {
            cout << "Dados do passageiro solicitado:" << endl;
            cout << "CPF: " << passageiro.cpf << endl;
            cout << "Nome: " << passageiro.nome << endl;
            cout << "Data de Nascimento: " << passageiro.dtNascimento.dia << "/" << passageiro.dtNascimento.mes << "/" << passageiro.dtNascimento.ano << endl;
            cout << "Número de Autorizaçao: " << passageiro.numAutorizacao << endl;
            return;
        }
    }
    cout << "Passageiro nao encontrado!" << endl;
}

int main(void)
{

    int opcao;
    vector<Passageiro> passageiros;

    while (true)
    {
        cout << endl
             << "!! Gestao de Passageiros !!" << endl
             << endl;
        cout << "Insira a opçao desejada: " << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar (apenas por CPF)" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar (por CPF)" << endl;
        cout << "0. Sair." << endl;

        cin >> opcao;

        switch (opcao)
        {

        case 1:
            incluir_pass(passageiros);
            break;

        case 2:
            excluir_pass(passageiros);
            break;

        case 3:
            alterar_pass(passageiros);
            break;

        case 4:
            listar_pass(passageiros);
            break;

        case 5:
            localizar_pass(passageiros);
            break;

        case 0:
            cout << "Obrigado por utilizar nosso serviço!" << endl;
            return 1;
            break;

        default:
            cout << "Opçao nao existente, tente novamente!" << endl;
            break;
        }
    }

    return 0;
}