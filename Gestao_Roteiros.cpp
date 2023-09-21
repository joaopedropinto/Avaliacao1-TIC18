#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

struct Roteiro {
    string codigo;
    string Data_Hora_Prevista;
    string Duracao_Prevista;
    string Origem;
    string Destino;
};

bool codigoExiste(vector<Roteiro> &roteiros, string &codigo) {
    for(auto &roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            return true; 
        }
    }
    return false; 
}

bool ehDataValida(string &dataPrevista) {
    tm tmPrevista = {};
    istringstream ss(dataPrevista);
    ss >> get_time(&tmPrevista, "%d/%m/%Y %H:%M");

    if (ss.fail()) {
        return false; 
    }

    time_t tPrevista = mktime(&tmPrevista);
    time_t agora = time(0);

    return tPrevista >= agora; 
}

void IncluirRoteiro(vector<Roteiro> &roteiros) {
    Roteiro novoRoteiro;
    string codigo;
    do {
        cout << "Código: ";
        getline(cin, codigo);
        if (codigoExiste(roteiros, codigo)) {
            cout << "Código já existente. Por favor, insira outro código.\n";
            codigo = ""; 
        }
    } while (codigo == "");

    novoRoteiro.codigo = codigo;

    string dataPrevista;
    do {
        cout << "Data e Hora Prevista (dd/mm/yyyy hh:mm): ";
        getline(cin, dataPrevista);
        if (!ehDataValida(dataPrevista)) {
            cout << "Data prevista inválida. Por favor, insira uma data futura.\n";
            dataPrevista = ""; 
        }
    } while (dataPrevista == "");
    novoRoteiro.Data_Hora_Prevista = dataPrevista;

    cout << "Duração Prevista: ";
    cin >> novoRoteiro.Duracao_Prevista;
    cin.ignore();

    cout << "Origem: ";
    getline(cin, novoRoteiro.Origem);

    cout << "Destino: ";
    getline(cin, novoRoteiro.Destino);

    roteiros.push_back(novoRoteiro);
    cout << "Roteiro incluído com sucesso!\n";
}


void ExcluirRoteiro(vector<Roteiro> &roteiros) {
    string codigo;
    cout << "Digite o Código do roteiro a ser excluído: ";
    getline(cin, codigo);

    for(auto it = roteiros.begin(); it != roteiros.end(); ++it) {
        if (it->codigo == codigo) {
            roteiros.erase(it);
            cout << "Roteiro excluído com sucesso!\n";
            return;
        }
    }

    cout << "Roteiro com Código " << codigo << " não encontrado.\n";
}

void AlterarRoteiro(vector<Roteiro> &roteiros) {
    string codigo;
    cout << "Codigo: ";
    getline(cin, codigo);


    for(auto& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            cout << "Dados do Passageiro:\n";
            cout << "Data e Hora: " << roteiro.Data_Hora_Prevista << ", Duração Prevista: " << roteiro.Duracao_Prevista << ", Origem e Destino: " << roteiro.Origem << " - " << roteiro.Destino << endl;


            char alterarDataHora, alterarDuracao, alterarOrigem, alterarDestino;

            cout << "Deseja alterar Data Hora Prevista (S/N)? ";
            cin >> alterarDataHora;
            cin.ignore();

            if(alterarDataHora == 'S' || alterarDataHora == 's') {
                cout << "Nova Data Hora Prevista: ";
                getline(cin, roteiro.Data_Hora_Prevista);
            }

            cout << "Deseja alterar Duração (S/N)? ";
            cin >> alterarDuracao;
            cin.ignore();

            if(alterarDuracao == 'S' || alterarDuracao == 's') {
                cout << "Nova Duração: ";
                getline(cin, roteiro.Duracao_Prevista);
            }

            cout << "Deseja alterar Origem (S/N)? ";
            cin >> alterarOrigem;
            cin.ignore();

            if(alterarOrigem == 'S' || alterarOrigem == 's') {
                cout << "Nova origem: ";
                getline(cin, roteiro.Origem);
            }

            cout << "Deseja alterar Destino (S/N)? ";
            cin >> alterarDestino;
            cin.ignore();

            if(alterarDestino == 'S' || alterarDestino == 's') {
                cout << "Novo destino: ";
                getline(cin, roteiro.Destino);
            }

            cout << "Roteiro alterado com sucesso!\n";
            return;
        }
    }

    cout << "Código " << codigo << " não encontrado.\n";
}

void ListarRoteiros(vector<Roteiro> &roteiros) {
    cout << "Lista de Roteiros:\n";
    for(auto &roteiro : roteiros) {
        cout << "Código: " << roteiro.codigo << ", Descrição: " << ", Data e Hora Prevista: " << roteiro.Data_Hora_Prevista << ", Duração Prevista: " << roteiro.Duracao_Prevista << ", Origem: " << roteiro.Origem << ", Destino: " << roteiro.Destino << "\n";
    }
}

void LocalizarRoteiro(vector<Roteiro> &roteiros) {
    string codigo;
    cout << "Digite o Código do roteiro a ser localizado: ";
    getline(cin, codigo);

    for(auto &roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            cout << "Código: " << roteiro.codigo << ", Descrição: " << "\n";
            return;
        }
    }

    cout << "Roteiro com Código " << codigo << " não encontrado.\n";
}

int main() {
    vector<Roteiro> roteiros;
    int escolha;

    do {
        cout << "\nMenu de Opções:\n";
        cout << "1. Incluir Roteiro\n";
        cout << "2. Excluir Roteiro\n";
        cout << "3. Alterar Roteiro (por Código)\n";
        cout << "4. Listar Roteiros\n";
        cout << "5. Localizar Roteiro (por Código)\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;
        cin.ignore(); 

        switch(escolha) {
            case 1:
                IncluirRoteiro(roteiros);
                break;
            case 2:
                ExcluirRoteiro(roteiros);
                break;
            case 3:
                AlterarRoteiro(roteiros);
                break;
            case 4:
                ListarRoteiros(roteiros);
                break;
            case 5:
                LocalizarRoteiro(roteiros);
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
                break;
        }

    } while(escolha != 0);

    return 0;
}
