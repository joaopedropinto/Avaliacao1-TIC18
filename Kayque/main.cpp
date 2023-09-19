#include <iostream>
#include <regex>
#include <string>
#include <iomanip>

using namespace std;
const int MAX_PASSAGEIROS = 300;

// Estrutura para armazenar informações do Passageiro
struct Passageiro {
    string cpf;
    string nome;
    string data_nascimento;
    string numero_autorizacao;
};

// Estrutura para armazenar informações do Roteiro
struct Roteiro {
    string cpf;
    string data_hora_prevista;
    string duracao_prevista;
    string origem;
    string destino;
};


bool ValidarCPF(const string& cpf) {
    // Neste exemplo, vamos simplesmente verificar se o CPF tem 11 dígitos
    return cpf.length() == 11;
}


bool ValidarDataNascimento(const string& data) {
    // Neste exemplo, vamos verificar se a data tem o formato DD/MM/AAAA
    regex dataRegex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/[0-9]{4}$");
    return regex_match(data, dataRegex);
}


// Função para incluir um passageiro
bool IncluirPassageiro(Passageiro passageiros[], int& quantidade, string nome, string cpf, string data_nascimento, string numero_autorizacao) {
    if (quantidade >= MAX_PASSAGEIROS) {
        cout << "Limite de passageiros atingido." << endl;
        return false;
    }

    for (int i = 0; i < quantidade; ++i) {
        if (passageiros[i].cpf == cpf || passageiros[i].nome == nome) {
            cout << "Passageiro com o mesmo cpf ou nome já existe.\n" << endl;
            return false;
        }
    }

    if (!ValidarCPF(cpf)) {
        cout << "CPF inválido.\n" << endl;
        return false;
    }

    if (!ValidarDataNascimento(data_nascimento)) {
        cout << "Data de nascimento inválida.\n" << endl;
        return false;
    }

    passageiros[quantidade].nome = nome;
    passageiros[quantidade].cpf = cpf;
    passageiros[quantidade].data_nascimento = data_nascimento;
    passageiros[quantidade].numero_autorizacao = numero_autorizacao;
    quantidade++;

    cout << "Passageiro inserido com sucesso!\n" << endl;
    return true;
}


// Função para excluir um passageiro
bool ExcluirPassageiro(Passageiro passageiros[], int& quantidade, const string& cpf) {
    for (int i = 0; i < quantidade; ++i) {
        if (passageiros[i].cpf == cpf) {
            // Movendo os passageiros seguintes para preencher o espaço
            for (int j = i; j < quantidade - 1; ++j) {
                passageiros[j] = passageiros[j + 1];
            }
            quantidade--;

            cout << "Passageiro excluído com sucesso." << endl;
            return true;
        }
    }

    cout << "Passageiro não encontrado." << endl;
    return false;
}


// Função para alterar dados de um passageiro
bool AlterarDadosPassageiro(Passageiro passageiros[], int quantidade, const string& cpf, string novoNome, string novaDataNascimento, string novoNumeroAutorizacao) {
    for (int i = 0; i < quantidade; ++i) {
        if (passageiros[i].cpf == cpf) {

            if (!ValidarDataNascimento(novaDataNascimento)) {
                cout << "Data de nascimento inválida.\n" << endl;
                return false;
            }

            // Altera os dados do passageiro
            passageiros[i].nome = novoNome;
            passageiros[i].data_nascimento = novaDataNascimento;
            passageiros[i].numero_autorizacao = novoNumeroAutorizacao;

            cout << "Dados do passageiro alterados com sucesso." << endl;
            return true;
        }
    }

    cout << "Passageiro não encontrado." << endl;
    return false;
}


// Função para listar todos os passageiro
void ListarPassageiro(const Passageiro passageiros[], int quantidade) {
    cout << "\nLista de passageiro:" << endl;
    for (int i = 0; i < quantidade; ++i) {
        cout << "CPF: " << passageiros[i].cpf << ", Nome: " << passageiros[i].nome << ", Data de nascimento: " << passageiros[i].data_nascimento << ", Número de autorização: " << passageiros[i].numero_autorizacao << endl;
    }
}

// Função para localizar o passageiro por CPF
void LocalizarPassageiro(const Passageiro passageiros[], int quantidade, const string& cpf) {
    for (int i = 0; i < quantidade; ++i) {
        if (passageiros[i].cpf == cpf) {
            cout << "O nome do passageiro é: " << passageiros[i].nome << endl;
            return;
        }
    }

    cout << "Passageiro não encontrado." << endl;
}


int main() {
    Passageiro passageiros[MAX_PASSAGEIROS];
    int quantidade = 0;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Incluir passageiro" << endl;
        cout << "2. Excluir passageiro" << endl;
        cout << "3. Alterar dados do passageiro" << endl;
        cout << "4. Listar passageiro" << endl;
        cout << "5. Localizar passageiro por CPF" << endl;
        cout << "6. Sair" << endl;
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        if (opcao == 6) {
            break;
        }

        switch (opcao) {
            case 1: {
                string nome, cpf, data_nascimento, numero_autorizacao;

                cout << "\nDigite o nome do passageiro: ";
                cin >> nome;
                cout << "Digite o cpf do passageiro: ";
                cin >> cpf;
                cout << "Digite a data de nascimento(01/01/2001): ";
                cin >> data_nascimento;
                cout << "Digite o numero de autorização: ";
                cin >> numero_autorizacao;

                IncluirPassageiro(passageiros, quantidade, nome, cpf, data_nascimento, numero_autorizacao);
                break;
                
                break;
            }
            case 2: {
                string cpf;
                cout << "Digite o CPF do passageiro a ser excluído: ";
                cin >> cpf;

                ExcluirPassageiro(passageiros, quantidade, cpf);
                break;
                break;
            }
            case 3: {
                string cpf;
                cout << "Digite o CPF do passageiro para alterar os dados: ";
                cin >> cpf;

                string novoNome, novaDataNascimento, novoNumeroAutorizacao;
                cout << "Digite o novo nome: ";
                cin >> novoNome;
                cout << "Digite a nova data de nascimento (01/01/2001): ";
                cin >> novaDataNascimento;
                cout << "Digite o novo número de autorização: ";
                cin >> novoNumeroAutorizacao;

                AlterarDadosPassageiro(passageiros, quantidade, cpf, novoNome, novaDataNascimento, novoNumeroAutorizacao);
                break;
            }

            case 4: {
                ListarPassageiro(passageiros, quantidade);
                break;
            }
            case 5: {
                string cpf;
                cout << "Digite o CPF do passageiro para localiza-lo: ";
                cin >> cpf;

                LocalizarPassageiro(passageiros, quantidade, cpf);
                break;
            }
            default:
                cout << "Opção inválida." << endl;
        }
    }

    return 0;
}
