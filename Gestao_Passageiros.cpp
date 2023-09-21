#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Passageiro {
   string nome;
   string cpf;
   string dataNascimento;
   string autorizacaoResponsavel;
};

bool ehMenorDeIdade(string& dataNascimento) {
    time_t t = time(0);
    tm* agora = localtime(&t);

    int anoNascimento, mesNascimento, diaNascimento;
    sscanf(dataNascimento.c_str(), "%d/%d/%d", &diaNascimento, &mesNascimento, &anoNascimento);

    int idade = agora->tm_year + 1900 - anoNascimento;
    if (agora->tm_mon < mesNascimento - 1 || (agora->tm_mon == mesNascimento - 1 && agora->tm_mday < diaNascimento)) {
        idade--;
    }

    return idade < 18;
}

bool cpfExiste(vector<Passageiro>& passageiros, string& cpf) {
    for(auto& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            return true; // O CPF já existe
        }
    }
    return false; // O CPF não existe
}

bool formatoCPFValido(string& cpf) {
    // Verifica se o CPF possui 11 caracteres (incluindo dígitos e pontuação)
    if (cpf.size() != 14) {
        return false;
    }

    // Verifica se os caracteres nas posições específicas são dígitos e se os pontos e traço estão nos lugares corretos
    for (int i = 0; i < 14; ++i) {
        if (i == 3 || i == 7) {
            if (cpf[i] != '.') {
                return false;
            }
        } else if (i == 11) {
            if (cpf[i] != '-') {
                return false;
            }
        } else {
            if (!isdigit(cpf[i])) {
                return false;
            }
        }
    }

    return true;
}


void IncluirPassageiro(vector<Passageiro>& passageiros) {
    Passageiro novoPassageiro;
    cout << "Nome: ";
    getline(cin, novoPassageiro.nome);
    string cpf;

do {
    cout << "CPF: ";
    getline(cin, cpf);
    if (!formatoCPFValido(cpf)) {
        cout << "CPF em formato inválido. Por favor, insira um CPF válido no formato XXX.XXX.XXX-XX.\n";
        cpf = ""; // Limpa o valor para continuar o loop
    } else if (cpfExiste(passageiros, cpf)) {
        cout << "CPF já existente. Por favor, insira outro CPF.\n";
        cpf = ""; // Limpa o valor para continuar o loop
    }

} while (cpf == "");

    novoPassageiro.cpf = cpf;

    cout << "Data de Nascimento (dd/mm/aaaa): ";
    getline(cin, novoPassageiro.dataNascimento);

    if (ehMenorDeIdade(novoPassageiro.dataNascimento)) {
        cout << "Número de Autorização do Responsável: ";
        getline(cin, novoPassageiro.autorizacaoResponsavel);
    }

    passageiros.push_back(novoPassageiro);
    cout << "Passageiro incluído com sucesso!\n";
}


void ExcluirPassageiro(vector<Passageiro>& passageiros) {
   string cpf;
   cout << "Digite o CPF do passageiro a ser excluído: ";
   getline(cin, cpf);

   for(auto it = passageiros.begin(); it != passageiros.end(); ++it) {
       if (it->cpf == cpf) {
           passageiros.erase(it);
           cout << "Passageiro excluído com sucesso!\n";
           return;
       }
   }

   cout << "Passageiro com CPF " << cpf << " não encontrado.\n";
}

void AlterarPassageiro(vector<Passageiro>& passageiros) {
    string cpf;

    do {
    cout << "Novo CPF: ";
    getline(cin, cpf);
    if (!formatoCPFValido(cpf)) {
        cout << "CPF em formato inválido. Por favor, insira um CPF válido no formato XXX.XXX.XXX-XX.\n";
        cpf = ""; // Limpa o valor para continuar o loop
    } else if (cpfExiste(passageiros, cpf)) {
        cout << "CPF já existente. Por favor, insira outro CPF.\n";
        cpf = ""; // Limpa o valor para continuar o loop
    }
} while (cpf == "");

    for(auto& passageiro : passageiros) {
        if (passageiro.cpf == cpf) {
            cout << "Dados do Passageiro:\n";
            cout << "Nome: " << passageiro.nome << ", CPF: " << passageiro.cpf << ", Data de Nascimento: " << passageiro.dataNascimento;
            
            if (ehMenorDeIdade(passageiro.dataNascimento)) {
                cout << ", Autorização do Responsável: " << passageiro.autorizacaoResponsavel;
            }

            cout << "\n";

            char alterarNome, alterarCpf, alterarNascimento;

            cout << "Deseja alterar o Nome (S/N)? ";
            cin >> alterarNome;
            cin.ignore();

            if(alterarNome == 'S' || alterarNome == 's') {
                cout << "Novo Nome: ";
                getline(cin, passageiro.nome);
            }

            cout << "Deseja alterar o CPF (S/N)? ";
            cin >> alterarCpf;
            cin.ignore();

            if(alterarCpf == 'S' || alterarCpf == 's') {
                string novoCpf;
                do {
                    cout << "Novo CPF: ";
                    getline(cin, novoCpf);
                    if (cpfExiste(passageiros, novoCpf)) {
                        cout << "CPF já existente. Por favor, insira outro CPF.\n";
                    }
                } while (cpfExiste(passageiros, novoCpf));
                passageiro.cpf = novoCpf;
            }

            cout << "Deseja alterar a Data de Nascimento (S/N)? ";
            cin >> alterarNascimento;
            cin.ignore();

            if(alterarNascimento == 'S' || alterarNascimento == 's') {
                cout << "Nova Data de Nascimento (dd/mm/aaaa): ";
                getline(cin, passageiro.dataNascimento);
            }

            if (ehMenorDeIdade(passageiro.dataNascimento)) {
                cout << "Número de Autorização do Responsável: ";
                getline(cin, passageiro.autorizacaoResponsavel);
            } else {
                passageiro.autorizacaoResponsavel = ""; // Limpa a autorização se não for menor de idade
            }

            cout << "Passageiro alterado com sucesso!\n";
            return;
        }
    }

    cout << "Passageiro com CPF " << cpf << " não encontrado.\n";
}



void ListarPassageiros(vector<Passageiro>& passageiros) {
   cout << "Lista de Passageiros:\n";
   for(auto& passageiro : passageiros) {
       cout << "Nome: " << passageiro.nome << ", CPF: " << passageiro.cpf << ", Idade: " << passageiro.dataNascimento;
       if (ehMenorDeIdade(passageiro.dataNascimento)) {
            cout << ", Autorização do Responsável: " << passageiro.autorizacaoResponsavel;
        }

        cout << "\n";
    }
}


void LocalizarPassageiro(vector<Passageiro>& passageiros) {
   string cpf;
   cout << "Digite o CPF do passageiro a ser localizado: ";
   getline(cin, cpf);

   for(auto& passageiro : passageiros) {
       if (passageiro.cpf == cpf) {
           cout << "Nome: " << passageiro.nome << ", CPF: " << passageiro.cpf << ", Idade: " << passageiro.dataNascimento << "\n";
           return;
       }
       if (ehMenorDeIdade(passageiro.dataNascimento)) {
            cout << ", Autorização do Responsável: " << passageiro.autorizacaoResponsavel;
        }

        cout << "\n";

   }

   cout << "Passageiro com CPF " << cpf << " não encontrado.\n";
}

int main() {
   vector<Passageiro> passageiros;
   int escolha;

   do {
       cout << "\nMenu de Opções:\n";
       cout << "1. Incluir Passageiro\n";
       cout << "2. Excluir Passageiro\n";
       cout << "3. Alterar Passageiro (por CPF)\n";
       cout << "4. Listar Passageiros\n";
       cout << "5. Localizar Passageiro\n";
       cout << "0. Sair\n";
       cout << "Escolha uma opção: ";
       cin >> escolha;
       cin.ignore(); 

       switch(escolha) {
           case 1:
               IncluirPassageiro(passageiros);
               break;
           case 2:
               ExcluirPassageiro(passageiros);
               break;
           case 3:
               AlterarPassageiro(passageiros);
               break;
           case 4:
               ListarPassageiros(passageiros);
               break;
           case 5:
               LocalizarPassageiro(passageiros);
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



