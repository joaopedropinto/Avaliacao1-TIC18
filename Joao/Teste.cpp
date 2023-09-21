#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Roteiro {
    int Codigo;
    string Data_HoraPrevista;
    string DuracaoPrevista;
    string Origem;
    string Destino;
};

// Função para exibir o menu
void exibirMenu() {
    cout << "Menu de Opções:" << endl;
    cout << "1. Incluir" << endl;
    cout << "2. Excluir" << endl;
    cout << "3. Alterar (apenas por Código)" << endl;
    cout << "4. Listar" << endl;
    cout << "5. Localizar (por Código)" << endl;
    cout << "0. Sair" << endl;
}

// Função para incluir um roteiro na coleção
void incluirRoteiro(vector<Roteiro>& roteiros) {
    Roteiro novoRoteiro;
    cout << "Informe o Código do roteiro: ";
    cin >> novoRoteiro.Codigo;
    cout << "Informe a Data e Hora Prevista: ";
    cin.ignore(); // Limpar o buffer do teclado
    getline(cin, novoRoteiro.Data_HoraPrevista);
    cout << "Informe a Duração Prevista: ";
    getline(cin, novoRoteiro.DuracaoPrevista);
    cout << "Informe a Origem: ";
    getline(cin, novoRoteiro.Origem);
    cout << "Informe o Destino: ";
    getline(cin, novoRoteiro.Destino);
    roteiros.push_back(novoRoteiro);
    cout << "Roteiro incluído com sucesso!" << endl;
}

// Função para excluir um roteiro da coleção por Código
void excluirRoteiro(vector<Roteiro>& roteiros) {
    int codigo;
    cout << "Informe o Código do roteiro a ser excluído: ";
    cin >> codigo;
    
    for (auto it = roteiros.begin(); it != roteiros.end(); ++it) {
        if (it->Codigo == codigo) {
            roteiros.erase(it);
            cout << "Roteiro excluído com sucesso!" << endl;
            return;
        }
    }
    
    cout << "Roteiro com Código " << codigo << " não encontrado." << endl;
}

// Função para alterar os dados de um roteiro por Código
void alterarRoteiro(vector<Roteiro>& roteiros) {
    int codigo;
    cout << "Informe o Código do roteiro a ser alterado: ";
    cin >> codigo;
    
    for (auto& roteiro : roteiros) {
        if (roteiro.Codigo == codigo) {
            cout << "Dados do roteiro:" << endl;
            cout << "Código: " << roteiro.Codigo << endl;
            cout << "Data e Hora Prevista: " << roteiro.Data_HoraPrevista << endl;
            cout << "Duração Prevista: " << roteiro.DuracaoPrevista << endl;
            cout << "Origem: " << roteiro.Origem << endl;
            cout << "Destino: " << roteiro.Destino << endl;
            
            char resposta;
            cout << "Deseja alterar a Data e Hora Prevista? (S/N): ";
            cin >> resposta;
            if (resposta == 'S' || resposta == 's') {
                cout << "Nova Data e Hora Prevista: ";
                cin.ignore(); // Limpar o buffer do teclado
                getline(cin, roteiro.Data_HoraPrevista);
            }
            
            cout << "Deseja alterar a Duração Prevista? (S/N): ";
            cin >> resposta;
            if (resposta == 'S' || resposta == 's') {
                cout << "Nova Duração Prevista: ";
                cin.ignore(); // Limpar o buffer do teclado
                getline(cin, roteiro.DuracaoPrevista);
            }
            
            cout << "Deseja alterar a Origem? (S/N): ";
            cin >> resposta;
            if (resposta == 'S' || resposta == 's') {
                cout << "Nova Origem: ";
                cin.ignore(); // Limpar o buffer do teclado
                getline(cin, roteiro.Origem);
            }
            
            cout << "Deseja alterar o Destino? (S/N): ";
            cin >> resposta;
            if (resposta == 'S' || resposta == 's') {
                cout << "Novo Destino: ";
                cin.ignore(); // Limpar o buffer do teclado
                getline(cin, roteiro.Destino);
            }
            
            cout << "Roteiro alterado com sucesso!" << endl;
            return;
        }
    }
    
    cout << "Roteiro com Código " << codigo << " não encontrado." << endl;
}

// Função para listar todos os roteiros
void listarRoteiros(const vector<Roteiro>& roteiros) {
    cout << "Lista de Roteiros:" << endl;
    for (const auto& roteiro : roteiros) {
        cout << "Código: " << roteiro.Codigo << ", Data e Hora Prevista: " << roteiro.Data_HoraPrevista
             << ", Duração Prevista: " << roteiro.DuracaoPrevista << ", Origem: " << roteiro.Origem
             << ", Destino: " << roteiro.Destino << endl;
    }
}

// Função para localizar um roteiro por Código
void localizarRoteiro(const vector<Roteiro>& roteiros) {
    int codigo;
    cout << "Informe o Código do roteiro a ser localizado: ";
    cin >> codigo;
    
    for (const auto& roteiro : roteiros) {
        if (roteiro.Codigo == codigo) {
            cout << "Roteiro encontrado:" << endl;
            cout << "Código: " << roteiro.Codigo << endl;
            cout << "Data e Hora Prevista: " << roteiro.Data_HoraPrevista << endl;
            cout << "Duração Prevista: " << roteiro.DuracaoPrevista << endl;
            cout << "Origem: " << roteiro.Origem << endl;
            cout << "Destino: " << roteiro.Destino << endl;
            return;
        }
    }
    
    cout << "Roteiro com Código " << codigo << " não encontrado." << endl;
}

int main() {
    vector<Roteiro> roteiros;
    int opcao;
    
    do {
        exibirMenu();
        cout << "Escolha uma opção: ";
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                incluirRoteiro(roteiros);
                break;
            case 2:
                excluirRoteiro(roteiros);
                break;
            case 3:
                alterarRoteiro(roteiros);
                break;
            case 4:
                listarRoteiros(roteiros);
                break;
            case 5:
                localizarRoteiro(roteiros);
                break;
            case 0:
                cout << "Saindo do programa." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    } while (opcao != 0);
    
    return 0;
}

bool data_valida(int dia, int mes, int ano){
    if(ano < 1900 || ano > 2100){
        return false;
    }
    if(mes < 1 || mes > 12){
        return false;
    }
    int diasNoMes = 0;
    
    if(mes == 2){
        diasNoMes = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) ? 29 : 28;

    }else if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
        diasNoMes = 30;
    }else{
        diasNoMes = 31;
    }
    if(dia < 1 || dia > diasNoMes){
        return false;
    }
}

#include <iostream>
#include <ctime>

// Função para calcular a idade a partir do dia, mês e ano de nascimento
int calcularIdade(int diaNascimento, int mesNascimento, int anoNascimento) {
    // Obter a data atual
    std::time_t agora = std::time(nullptr);
    std::tm tmNascimento = {};

    // Definir a data de nascimento
    tmNascimento.tm_year = anoNascimento - 1900; // Ano - 1900
    tmNascimento.tm_mon = mesNascimento - 1;     // Mês (0-11)
    tmNascimento.tm_mday = diaNascimento;        // Dia

    // Converter as datas em segundos desde 1970
    std::time_t dataNascimentoT = std::mktime(&tmNascimento);

    // Calcular a idade
    std::tm* tmAtual = std::localtime(&agora);
    int idade = tmAtual->tm_year - tmNascimento.tm_year;

    if (tmAtual->tm_mon < tmNascimento.tm_mon || (tmAtual->tm_mon == tmNascimento.tm_mon && tmAtual->tm_mday < tmNascimento.tm_mday)) {
        idade--; // Ainda não fez aniversário neste ano
    }

    return idade;
}
void coisei() {
    int diaNascimento, mesNascimento, anoNascimento;

    std::cout << "Informe o dia de nascimento: ";
    std::cin >> diaNascimento;
    std::cout << "Informe o mês de nascimento: ";
    std::cin >> mesNascimento;
    std::cout << "Informe o ano de nascimento: ";
    std::cin >> anoNascimento;

    int idade = calcularIdade(diaNascimento, mesNascimento, anoNascimento);

    std::cout << "A idade é: " << idade << " anos" << std::endl;


}

#include <iostream>
#include <regex>
#include <string>

bool validarDataHora(const std::string& dataHora) {
    // Expressão regular para validar data e hora no formato "dd/mm/aaaa hh:mm"
    std::regex padrao("^(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/(\\d{4}) (?:[01]\\d|2[0-3]):[0-5]\\d$");

    return std::regex_match(dataHora, padrao);
}

int main() {
    std::string dataHora;

    std::cout << "Informe uma data e hora no formato dd/mm/aaaa hh:mm ";
    std::getline(std::cin, dataHora);

    if (validarDataHora(dataHora)) {
        std::cout << "A data e hora são válidas." << std::endl;
    } else {
        std::cout << "A data e hora não são válidas." << std::endl;
    }

    return 0;
}
