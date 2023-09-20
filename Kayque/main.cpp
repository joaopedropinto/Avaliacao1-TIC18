#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Constante para o número máximo de passageiros
const int MAX_PASSAGEIROS = 40;

// Estrutura para armazenar informações do Passageiro
struct Passageiro {
    string cpf;
    string nome;
    string data_nascimento;
    string numero_autorizacao;
};

bool ValidarCPF(const string& cpf) {
    // Verificar se o CPF tem exatamente 11 dígitos
    if (cpf.length() != 11) {
        return false;
    }

    // Verificar se todos os caracteres são dígitos
    if (!regex_match(cpf, regex("\\d{11}"))) {
        return false;
    }

    return true;
}

bool ValidarDataNascimento(const string& data) {
    // Neste exemplo, vamos verificar se a data tem o formato DD/MM/AAAA
    regex dataRegex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/[0-9]{4}$");
    return regex_match(data, dataRegex);
}

// Função para incluir um passageiro
bool IncluirPassageiro(vector<Passageiro>& passageiros, string nome, string cpf, string data_nascimento, string numero_autorizacao) {
    if (passageiros.size() >= MAX_PASSAGEIROS) {
        cout << "Limite de passageiros atingido." << endl;
        return false;
    }

    for (const Passageiro& passageiro : passageiros) {
        if (passageiro.cpf == cpf || passageiro.nome == nome) {
            cout << "Passageiro com o mesmo CPF ou nome já existe.\n" << endl;
            cout << "Passageiro não incluido!.\n" << endl;
            return false;
        }
    }

    if (!ValidarCPF(cpf)) {
        cout << "CPF inválido.\n" << endl;
        cout << "Passageiro não incluido!.\n" << endl;
        return false;
    }

    if (!ValidarDataNascimento(data_nascimento)) {
        cout << "Data de nascimento inválida.\n" << endl;
        cout << "Passageiro não incluido!.\n" << endl;
        return false;
    }

    Passageiro novoPassageiro;
    novoPassageiro.nome = nome;
    novoPassageiro.cpf = cpf;
    novoPassageiro.data_nascimento = data_nascimento;
    novoPassageiro.numero_autorizacao = numero_autorizacao;

    passageiros.push_back(novoPassageiro);

    cout << "Passageiro inserido com sucesso!\n" << endl;
    return true;
}

// Função para excluir um passageiro
bool ExcluirPassageiro(vector<Passageiro>& passageiros, const string& cpf) {
    for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
        if (it->cpf == cpf) {
            passageiros.erase(it);
            cout << "Passageiro excluído com sucesso." << endl;
            return true;
        }
    }

    cout << "Passageiro não encontrado." << endl;
    return false;
}

// Função para alterar dados de um passageiro
bool AlterarDadosPassageiro(vector<Passageiro>& passageiros, const string& cpf, string novoNome, string novaDataNascimento, string novoNumeroAutorizacao) {
    for (Passageiro& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            if (!ValidarDataNascimento(novaDataNascimento)) {
                cout << "Data de nascimento inválida.\n" << endl;
                return false;
            }

            passageiro.nome = novoNome;
            passageiro.data_nascimento = novaDataNascimento;
            passageiro.numero_autorizacao = novoNumeroAutorizacao;

            cout << "Dados do passageiro alterados com sucesso." << endl;
            return true;
        }
    }

    cout << "Passageiro não encontrado." << endl;
    return false;
}

// Função para listar todos os passageiros
void ListarPassageiros(const vector<Passageiro>& passageiros) {
    cout << "\nLista de passageiros:" << endl;
    for (const Passageiro& passageiro : passageiros) {
        cout << "CPF: " << passageiro.cpf << ", Nome: " << passageiro.nome << ", Data de nascimento: " << passageiro.data_nascimento << ", Número de autorização: " << passageiro.numero_autorizacao << endl;
    }
}

// Função para localizar o passageiro por CPF
void LocalizarPassageiro(const vector<Passageiro>& passageiros, const string& cpf) {
    for (const Passageiro& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            cout << "O nome do passageiro é: " << passageiro.nome << endl;
            return;
        }
    }

    cout << "Passageiro não encontrado." << endl;
}

int main() {
    vector<Passageiro> passageiros;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Incluir passageiro" << endl;
        cout << "2. Excluir passageiro" << endl;
        cout << "3. Alterar dados do passageiro" << endl;
        cout << "4. Listar passageiros" << endl;
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
                // Limpa o buffer de entrada
                cin.ignore();
                getline(cin, nome);
                cout << "Digite o CPF do passageiro: ";
                cin >> cpf;
                cout << "Digite a data de nascimento (01/01/2001): ";
                cin >> data_nascimento;
                cout << "Digite o número de autorização: ";
                cin >> numero_autorizacao;

                IncluirPassageiro(passageiros, nome, cpf, data_nascimento, numero_autorizacao);
                break;
            }
            case 2: {
                string cpf;
                cout << "Digite o CPF do passageiro a ser excluído: ";
                cin >> cpf;

                ExcluirPassageiro(passageiros, cpf);
                break;
            }
            case 3: {
                string cpf;
                cout << "\nDigite o CPF do passageiro para alterar os dados: ";
                cin >> cpf;

                string novoNome, novaDataNascimento, novoNumeroAutorizacao;
                cout << "Digite o novo nome: ";
                // Limpa o buffer de entrada
                cin.ignore();
                getline(cin, novoNome);
                cout << "Digite a nova data de nascimento (01/01/2001): ";
                cin >> novaDataNascimento;
                cout << "Digite o novo número de autorização: ";
                cin >> novoNumeroAutorizacao;

                AlterarDadosPassageiro(passageiros, cpf, novoNome, novaDataNascimento, novoNumeroAutorizacao);
                break;
            }
            case 4: {
                ListarPassageiros(passageiros);
                break;
            }
            case 5: {
                string cpf;
                cout << "Digite o CPF do passageiro para localizá-lo: ";
                cin >> cpf;

                LocalizarPassageiro(passageiros, cpf);
                break;
            }
            default:
                cout << "Opção inválida." << endl;
        }
    }

    return 0;
}
