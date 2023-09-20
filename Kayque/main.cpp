#include <iostream>
#include <regex>
#include <string>
<<<<<<< HEAD
#include <vector>
#include <iomanip>

using namespace std;

// Constante para o número máximo de passageiros
const int MAX_PASSAGEIROS = 40;
=======
#include <iomanip>

using namespace std;
const int MAX_PASSAGEIROS = 300;
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa

// Estrutura para armazenar informações do Passageiro
struct Passageiro {
    string cpf;
    string nome;
    string data_nascimento;
    string numero_autorizacao;
};

<<<<<<< HEAD
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

=======
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


>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
bool ValidarDataNascimento(const string& data) {
    // Neste exemplo, vamos verificar se a data tem o formato DD/MM/AAAA
    regex dataRegex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/[0-9]{4}$");
    return regex_match(data, dataRegex);
}

<<<<<<< HEAD
// Função para incluir um passageiro
bool IncluirPassageiro(vector<Passageiro>& passageiros, string nome, string cpf, string data_nascimento, string numero_autorizacao) {
    if (passageiros.size() >= MAX_PASSAGEIROS) {
=======

// Função para incluir um passageiro
bool IncluirPassageiro(Passageiro passageiros[], int& quantidade, string nome, string cpf, string data_nascimento, string numero_autorizacao) {
    if (quantidade >= MAX_PASSAGEIROS) {
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
        cout << "Limite de passageiros atingido." << endl;
        return false;
    }

<<<<<<< HEAD
    for (const Passageiro& passageiro : passageiros) {
        if (passageiro.cpf == cpf || passageiro.nome == nome) {
            cout << "Passageiro com o mesmo CPF ou nome já existe.\n" << endl;
            cout << "Passageiro não incluido!.\n" << endl;
=======
    for (int i = 0; i < quantidade; ++i) {
        if (passageiros[i].cpf == cpf || passageiros[i].nome == nome) {
            cout << "Passageiro com o mesmo cpf ou nome já existe.\n" << endl;
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
            return false;
        }
    }

    if (!ValidarCPF(cpf)) {
        cout << "CPF inválido.\n" << endl;
<<<<<<< HEAD
        cout << "Passageiro não incluido!.\n" << endl;
=======
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
        return false;
    }

    if (!ValidarDataNascimento(data_nascimento)) {
        cout << "Data de nascimento inválida.\n" << endl;
<<<<<<< HEAD
        cout << "Passageiro não incluido!.\n" << endl;
        return false;
    }

    Passageiro novoPassageiro;
    novoPassageiro.nome = nome;
    novoPassageiro.cpf = cpf;
    novoPassageiro.data_nascimento = data_nascimento;
    novoPassageiro.numero_autorizacao = numero_autorizacao;

    passageiros.push_back(novoPassageiro);
=======
        return false;
    }

    passageiros[quantidade].nome = nome;
    passageiros[quantidade].cpf = cpf;
    passageiros[quantidade].data_nascimento = data_nascimento;
    passageiros[quantidade].numero_autorizacao = numero_autorizacao;
    quantidade++;
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa

    cout << "Passageiro inserido com sucesso!\n" << endl;
    return true;
}

<<<<<<< HEAD
// Função para excluir um passageiro
bool ExcluirPassageiro(vector<Passageiro>& passageiros, const string& cpf) {
    for (auto it = passageiros.begin(); it != passageiros.end(); ++it) {
        if (it->cpf == cpf) {
            passageiros.erase(it);
=======

// Função para excluir um passageiro
bool ExcluirPassageiro(Passageiro passageiros[], int& quantidade, const string& cpf) {
    for (int i = 0; i < quantidade; ++i) {
        if (passageiros[i].cpf == cpf) {
            // Movendo os passageiros seguintes para preencher o espaço
            for (int j = i; j < quantidade - 1; ++j) {
                passageiros[j] = passageiros[j + 1];
            }
            quantidade--;

>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
            cout << "Passageiro excluído com sucesso." << endl;
            return true;
        }
    }

    cout << "Passageiro não encontrado." << endl;
    return false;
}

<<<<<<< HEAD
// Função para alterar dados de um passageiro
bool AlterarDadosPassageiro(vector<Passageiro>& passageiros, const string& cpf, string novoNome, string novaDataNascimento, string novoNumeroAutorizacao) {
    for (Passageiro& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
=======

// Função para alterar dados de um passageiro
bool AlterarDadosPassageiro(Passageiro passageiros[], int quantidade, const string& cpf, string novoNome, string novaDataNascimento, string novoNumeroAutorizacao) {
    for (int i = 0; i < quantidade; ++i) {
        if (passageiros[i].cpf == cpf) {

>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
            if (!ValidarDataNascimento(novaDataNascimento)) {
                cout << "Data de nascimento inválida.\n" << endl;
                return false;
            }

<<<<<<< HEAD
            passageiro.nome = novoNome;
            passageiro.data_nascimento = novaDataNascimento;
            passageiro.numero_autorizacao = novoNumeroAutorizacao;
=======
            // Altera os dados do passageiro
            passageiros[i].nome = novoNome;
            passageiros[i].data_nascimento = novaDataNascimento;
            passageiros[i].numero_autorizacao = novoNumeroAutorizacao;
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa

            cout << "Dados do passageiro alterados com sucesso." << endl;
            return true;
        }
    }

    cout << "Passageiro não encontrado." << endl;
    return false;
}

<<<<<<< HEAD
// Função para listar todos os passageiros
void ListarPassageiros(const vector<Passageiro>& passageiros) {
    cout << "\nLista de passageiros:" << endl;
    for (const Passageiro& passageiro : passageiros) {
        cout << "CPF: " << passageiro.cpf << ", Nome: " << passageiro.nome << ", Data de nascimento: " << passageiro.data_nascimento << ", Número de autorização: " << passageiro.numero_autorizacao << endl;
=======

// Função para listar todos os passageiro
void ListarPassageiro(const Passageiro passageiros[], int quantidade) {
    cout << "\nLista de passageiro:" << endl;
    for (int i = 0; i < quantidade; ++i) {
        cout << "CPF: " << passageiros[i].cpf << ", Nome: " << passageiros[i].nome << ", Data de nascimento: " << passageiros[i].data_nascimento << ", Número de autorização: " << passageiros[i].numero_autorizacao << endl;
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
    }
}

// Função para localizar o passageiro por CPF
<<<<<<< HEAD
void LocalizarPassageiro(const vector<Passageiro>& passageiros, const string& cpf) {
    for (const Passageiro& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            cout << "O nome do passageiro é: " << passageiro.nome << endl;
=======
void LocalizarPassageiro(const Passageiro passageiros[], int quantidade, const string& cpf) {
    for (int i = 0; i < quantidade; ++i) {
        if (passageiros[i].cpf == cpf) {
            cout << "O nome do passageiro é: " << passageiros[i].nome << endl;
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
            return;
        }
    }

    cout << "Passageiro não encontrado." << endl;
}

<<<<<<< HEAD
int main() {
    vector<Passageiro> passageiros;
=======

int main() {
    Passageiro passageiros[MAX_PASSAGEIROS];
    int quantidade = 0;
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Incluir passageiro" << endl;
        cout << "2. Excluir passageiro" << endl;
        cout << "3. Alterar dados do passageiro" << endl;
<<<<<<< HEAD
        cout << "4. Listar passageiros" << endl;
=======
        cout << "4. Listar passageiro" << endl;
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
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
<<<<<<< HEAD
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
=======
                cin >> nome;
                cout << "Digite o cpf do passageiro: ";
                cin >> cpf;
                cout << "Digite a data de nascimento(01/01/2001): ";
                cin >> data_nascimento;
                cout << "Digite o numero de autorização: ";
                cin >> numero_autorizacao;

                IncluirPassageiro(passageiros, quantidade, nome, cpf, data_nascimento, numero_autorizacao);
                break;
                
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
                break;
            }
            case 2: {
                string cpf;
                cout << "Digite o CPF do passageiro a ser excluído: ";
                cin >> cpf;

<<<<<<< HEAD
                ExcluirPassageiro(passageiros, cpf);
=======
                ExcluirPassageiro(passageiros, quantidade, cpf);
                break;
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
                break;
            }
            case 3: {
                string cpf;
<<<<<<< HEAD
                cout << "\nDigite o CPF do passageiro para alterar os dados: ";
=======
                cout << "Digite o CPF do passageiro para alterar os dados: ";
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
                cin >> cpf;

                string novoNome, novaDataNascimento, novoNumeroAutorizacao;
                cout << "Digite o novo nome: ";
<<<<<<< HEAD
                // Limpa o buffer de entrada
                cin.ignore();
                getline(cin, novoNome);
=======
                cin >> novoNome;
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
                cout << "Digite a nova data de nascimento (01/01/2001): ";
                cin >> novaDataNascimento;
                cout << "Digite o novo número de autorização: ";
                cin >> novoNumeroAutorizacao;

<<<<<<< HEAD
                AlterarDadosPassageiro(passageiros, cpf, novoNome, novaDataNascimento, novoNumeroAutorizacao);
                break;
            }
            case 4: {
                ListarPassageiros(passageiros);
=======
                AlterarDadosPassageiro(passageiros, quantidade, cpf, novoNome, novaDataNascimento, novoNumeroAutorizacao);
                break;
            }

            case 4: {
                ListarPassageiro(passageiros, quantidade);
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
                break;
            }
            case 5: {
                string cpf;
<<<<<<< HEAD
                cout << "Digite o CPF do passageiro para localizá-lo: ";
                cin >> cpf;

                LocalizarPassageiro(passageiros, cpf);
=======
                cout << "Digite o CPF do passageiro para localiza-lo: ";
                cin >> cpf;

                LocalizarPassageiro(passageiros, quantidade, cpf);
>>>>>>> 164bc28dca16e4826fd6df348640990b09f15efa
                break;
            }
            default:
                cout << "Opção inválida." << endl;
        }
    }

    return 0;
}
