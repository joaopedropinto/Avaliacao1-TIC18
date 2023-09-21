#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Constante para o número máximo de roteiros
const int MAX_ROTEIROS = 100;

// Estrutura para armazenar informações do Roteiro
struct Roteiro {
    string codigo;
    string data_hora_prevista;
    string duracao_prevista;
    string origem;
    string destino;
};

bool codigoJaExiste(const vector<Roteiro>& roteiros, const string& codigo) {
    for (const Roteiro& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            return true; // O Código já existe na lista
        }
    }
    return false; // O Código não existe na lista
}

bool ValidarCodigo(vector<Roteiro>& roteiros, const string& codigo) {

    codigoJaExiste(roteiros, codigo);

    // Verificar se todos os caracteres são dígitos
    if (!regex_match(codigo, regex("\\d+"))) {
        return false; // Código inválido
    }

    return true;
}

bool ValidarHora(const string& duracao) {
    // Neste exemplo, vamos verificar se a data e hora têm o formato DD/MM/AAAA HH:MM
    regex horaRegex("[0-1][0-9]:[0-5][0-9]$");
    return regex_match(duracao, horaRegex);
}

bool ValidarDataHora(const string& data_hora) {
    // Neste exemplo, vamos verificar se a data e hora têm o formato DD/MM/AAAA HH:MM
    regex dataHoraRegex("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/[0-9]{4} [0-1][0-9]:[0-5][0-9]$");
    return regex_match(data_hora, dataHoraRegex);
}

// Função para incluir um roteiro
bool IncluirRoteiro(vector<Roteiro>& roteiros, string codigo, string data_hora_prevista, string duracao_prevista, string origem, string destino) {
    if (roteiros.size() >= MAX_ROTEIROS) {
        cout << "Limite de roteiros atingido." << endl;
        return false;
    }

    if (!ValidarCodigo(roteiros, codigo)) {
        cout << "Código inválido.\n" << endl;
        cout << "Roteiro não incluído!\n" << endl;
        return false;
    }

    if (!ValidarDataHora(data_hora_prevista)) {
        cout << "Data e hora previstas inválidas.\n" << endl;
        cout << "Roteiro não incluído!\n" << endl;
        return false;
    }

    Roteiro novoRoteiro;
    novoRoteiro.codigo = codigo;
    novoRoteiro.data_hora_prevista = data_hora_prevista;
    novoRoteiro.duracao_prevista = duracao_prevista;
    novoRoteiro.origem = origem;
    novoRoteiro.destino = destino;

    roteiros.push_back(novoRoteiro);

    cout << "\nRoteiro inserido com sucesso!\n" << endl;
    return true;
}

// Função para excluir um roteiro
bool ExcluirRoteiro(vector<Roteiro>& roteiros, const string& codigo) {
    for (auto it = roteiros.begin(); it != roteiros.end(); ++it) {
        if (it->codigo == codigo) {
            roteiros.erase(it);
            cout << "Roteiro excluído com sucesso." << endl;
            return true;
        }
    }

    cout << "Roteiro não encontrado." << endl;
    return false;
}

// Função para alterar dados de um roteiro
bool AlterarDadosRoteiro(vector<Roteiro>& roteiros, const string& codigo, string novaDataHoraPrevista, string novaDuracaoPrevista, string novaOrigem, string novoDestino) {
    for (Roteiro& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            if (!ValidarDataHora(novaDataHoraPrevista)) {
                cout << "Data e hora previstas inválidas.\n" << endl;
                return false;
            }

            roteiro.data_hora_prevista = novaDataHoraPrevista;
            roteiro.duracao_prevista = novaDuracaoPrevista;
            roteiro.origem = novaOrigem;
            roteiro.destino = novoDestino;

            cout << "Dados do roteiro alterados com sucesso." << endl;
            return true;
        }
    }

    cout << "Roteiro não encontrado." << endl;
    return false;
}

// Função para listar todos os roteiros
void ListarRoteiros(const vector<Roteiro>& roteiros) {
    cout << "\nLista de roteiros:" << endl;
    for (const Roteiro& roteiro : roteiros) {
        cout << "Código: " << roteiro.codigo << ", Data e hora previstas: " << roteiro.data_hora_prevista
             << ", Duração prevista: " << roteiro.duracao_prevista << ", Origem: " << roteiro.origem
             << ", Destino: " << roteiro.destino << endl;
    }
}

// Função para localizar o roteiro por código
void LocalizarRoteiro(const vector<Roteiro>& roteiros, const string& codigo) {
    for (const Roteiro& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            cout << "Origem do roteiro: " << roteiro.origem << ", Destino do roteiro: " << roteiro.destino << endl;
            return;
        }
    }

    cout << "Roteiro não encontrado." << endl;
}

int main() {
    vector<Roteiro> roteiros;

    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Incluir roteiro" << endl;
        cout << "2. Excluir roteiro" << endl;
        cout << "3. Alterar dados do roteiro" << endl;
        cout << "4. Listar roteiros" << endl;
        cout << "5. Localizar roteiro por código" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opção: ";

        int opcao;
        cin >> opcao;

        if (opcao == 0) {
            break;
        }

        switch (opcao) {
            case 1: {
                string codigo, data_hora_prevista, duracao_prevista, origem, destino;

                cout << "\nDigite o código do roteiro: ";
                cin >> codigo;

                while (codigoJaExiste(roteiros, codigo)) {
                    cout << "Código não cadastrado. Por favor, insira um código válido." << endl;
                    cout << "\nDigite o código do passageiro: ";
                    cin >> codigo;
                }

                cout << "Digite a data e hora previstas (DD/MM/AAAA HH:MM): ";
                // Limpa o buffer de entrada
                cin.ignore();
                getline(cin, data_hora_prevista);

                // Verifique se a data e hora prevista é válida
                while (!ValidarDataHora(data_hora_prevista)) {
                    cout << "Data e hora inválida. Por favor, insira uma data e hora válida." << endl;
                    cout << "Digite a data e hora previstas (DD/MM/AAAA HH:MM): ";
                    getline(cin, data_hora_prevista);
                }

                cout << "Digite a duração (HH:MM): ";
                getline(cin, duracao_prevista);

                // Verifique se a duração é válida
                while (!ValidarHora(duracao_prevista)) {
                    cout << "Hora inválida. Por favor, insira uma hora válida." << endl;
                    cout << "Digite a duração (HH:MM): ";
                    getline(cin, duracao_prevista);
                }

                cout << "Digite a origem: ";
                getline(cin, origem);

                cout << "Digite o destino: ";
                // Limpa o buffer de entrada
                cin.ignore();
                getline(cin, destino);

                IncluirRoteiro(roteiros, codigo, data_hora_prevista, duracao_prevista, origem, destino);
                break;
            }
            case 2: {
                string codigo;
                cout << "\nDigite o código do roteiro a ser excluído: ";
                cin.ignore();
                getline(cin, codigo);

                // Verifique se o codigo é válido
                while (!codigoJaExiste(roteiros, codigo)) {
                    cout << "Código não cadastrado. Por favor, insira um código válido." << endl;
                    cout << "\nDigite o código do passageiro: ";
                    cin >> codigo;
                }

                ExcluirRoteiro(roteiros, codigo);
                break;
            }
            case 3: {
                string codigo;
                cout << "\nDigite o código do roteiro para alterar os dados: ";
                cin.ignore();
                getline(cin, codigo);

                // Verifique se o codigo é válido
                while (!codigoJaExiste(roteiros, codigo)) {
                    cout << "Código não cadastrado. Por favor, insira um código válido." << endl;
                    cout << "\nDigite o código do passageiro: ";
                    cin >> codigo;
                }

                string novaDataHoraPrevista, novaDuracaoPrevista, novaOrigem, novoDestino;
                cout << "Digite a nova data e hora previstas (DD/MM/AAAA HH:MM): ";
                getline(cin, novaDataHoraPrevista);
                cout << "Digite a nova duração prevista: ";
                getline(cin, novaDuracaoPrevista);
                cout << "Digite a nova origem: ";
                getline(cin, novaOrigem);
                cout << "Digite o novo destino: ";
                getline(cin, novoDestino);

                AlterarDadosRoteiro(roteiros, codigo, novaDataHoraPrevista, novaDuracaoPrevista, novaOrigem, novoDestino);
                break;
            }
            case 4: {
                ListarRoteiros(roteiros);
                break;
            }
            case 5: {
                string codigo;
                cout << "\nDigite o código do roteiro para localizá-lo: ";
                cin.ignore();
                getline(cin, codigo);

                // Verifique se o codigo é válido
                while (!codigoJaExiste(roteiros, codigo)) {
                    cout << "Código não cadastrado. Por favor, insira um código válido." << endl;
                    cout << "\nDigite o código do passageiro: ";
                    cin >> codigo;
                }

                LocalizarRoteiro(roteiros, codigo);
                break;
            }
            default:
                cout << "Opção inválida." << endl;
        }
    }

    return 0;
}

