#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

struct Roteiro {
    string codigo;
    string descricao;
    float preco;
    string Data_Hora_Prevista;
    float Duracao_Prevista;
    string Origem;
    string Destino;
};

bool codigoExiste(const vector<Roteiro>& roteiros, const string& codigo) {
    for(const auto& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            return true; 
        }
    }
    return false; 
}

bool ehDataValida(const string& dataPrevista) {
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

void IncluirRoteiro(vector<Roteiro>& roteiros) {
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

    cout << "Descrição: ";
    getline(cin, novoRoteiro.descricao);
    cout << "Preço: ";
    cin >> novoRoteiro.preco;
    cin.ignore(); 

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

    cout << "Duração Prevista (em horas): ";
    cin >> novoRoteiro.Duracao_Prevista;
    cin.ignore();

    cout << "Origem: ";
    getline(cin, novoRoteiro.Origem);

    cout << "Destino: ";
    getline(cin, novoRoteiro.Destino);

    roteiros.push_back(novoRoteiro);
    cout << "Roteiro incluído com sucesso!\n";
}


void ExcluirRoteiro(vector<Roteiro>& roteiros) {
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

void AlterarRoteiro(vector<Roteiro>& roteiros) {
    string codigo;
    cout << "Digite o Código do roteiro a ser alterado: ";
    getline(cin, codigo);

    for(auto& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            cout << "Dados do Roteiro:\n";
            cout << "Código: " << roteiro.codigo << ", Descrição: " << roteiro.descricao << ", Preço: " << roteiro.preco << "\n";

            char alterarDescricao, alterarPreco;

            cout << "Deseja alterar a Descrição (S/N)? ";
            cin >> alterarDescricao;
            cin.ignore();

            if(alterarDescricao == 'S' || alterarDescricao == 's') {
                cout << "Nova Descrição: ";
                getline(cin, roteiro.descricao);
            }

            cout << "Deseja alterar o Preço (S/N)? ";
            cin >> alterarPreco;
            cin.ignore();

            if(alterarPreco == 'S' || alterarPreco == 's') {
                cout << "Novo Preço: ";
                cin >> roteiro.preco;
                cin.ignore(); 
            }

            cout << "Roteiro alterado com sucesso!\n";
            return;
        }
    }

    cout << "Roteiro com Código " << codigo << " não encontrado.\n";
}

void ListarRoteiros(const vector<Roteiro>& roteiros) {
    cout << "Lista de Roteiros:\n";
    for(const auto& roteiro : roteiros) {
        cout << "Código: " << roteiro.codigo << ", Descrição: " << roteiro.descricao << ", Preço: " << roteiro.preco << ", Data e Hora Prevista: " << roteiro.Data_Hora_Prevista << ", Duração Prevista: " << roteiro.Duracao_Prevista << ", Origem: " << roteiro.Origem << ", Destino: " << roteiro.Destino << "\n";
    }
}

void LocalizarRoteiro(const vector<Roteiro>& roteiros) {
    string codigo;
    cout << "Digite o Código do roteiro a ser localizado: ";
    getline(cin, codigo);

    for(const auto& roteiro : roteiros) {
        if (roteiro.codigo == codigo) {
            cout << "Código: " << roteiro.codigo << ", Descrição: " << roteiro.descricao << ", Preço: " << roteiro.preco << "\n";
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
