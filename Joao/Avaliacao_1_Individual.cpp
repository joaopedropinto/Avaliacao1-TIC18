#include <iostream>
#include <string>
#include <ctime>
#include <vector>

using namespace std;

struct Passageiro {
    string nome;
    string cpf;
    string dtNascimento;
    int numAutorizacao;
};

struct Roteiro {
    int codigo;
    string dataHoraPrev;
    string duracaoPrev;
    string origem;
    string destino;
};

Passageiro incluir_pass(){

    int idade;
    Passageiro passageiro;

    cout << "Informe o CPF do passageiro a ser incluído (xxx.xxx.xxx-xx): " << endl;
    cin >> passageiro.cpf;
    cout << "Informe o nome do passageiro a ser incluído: " << endl;
    cin >> passageiro.nome;
    cout << "Informe a data de nascimento do passageiro a ser incluído: (dd/mm/aaaa)" << endl;
    cin >> passageiro.dtNascimento;

    if(idade < 18){
        cout << "Informe o número de autorização do passageiro: " << endl;
        cin >> passageiro.numAutorizacao;
    }

    return passageiro;
}
void excluir_pass(vector<Passageiro> &passageiros){
    string cpf;
    cout << "Informe o CPF do passageiro a ser excluído (xxx.xxx.xxx-xx): " << endl;
    cin >> cpf;
    for(auto it = passageiros.begin(); it != passageiros.end(); it++){
        if(cpf == it->cpf){
            passageiros.erase(passageiros.begin() + distance(passageiros.begin(), it));
            cout << "Passageiro excluido com sucesso!";
        }
}

void alterar_pass(vector<Passageiro> passageiros){
    cout << "Informe o CPF do passageiro a ser alterado (xxx.xxx.xxx-xx): " << endl;
    cout << "Você deseja alterar o nome do passageiro?(S/N)" << endl;
    cout << "Você deseja alterar o CPF do passageiro?(S/N)" << endl;
    cout << "Você deseja alterar a data de nascimento do passageiro?(S/N)" << endl;
}

void listar_pass(vector<Passageiro> passageiros){
    cout << "Lista de passageiros presentes: " << endl;
    for(auto it = passageiros.begin(); it != passageiros.end(); it++){
        cout << it -> nome << " " << it -> cpf << endl;
    }

}

void localizar_pass(vector<Passageiro> passageiros){
    string cpf;
    cout << "Informe o CPF do passageiro a ser localizado: " << endl;
    cin >> cpf;
    for(auto it = passageiros.begin(); it != passageiros.end(); it++){
        if(cpf == it->cpf){
            cout << "Dados do passageiro solicitado: " << endl;
            cout << it -> nome << " " << it -> cpf << endl;
        }
    }
    
}

int main(void){

    int opcao;
    vector<Passageiro> passageiros;

    while(true){
        cout << "Insira a opção desejada: " << endl;
        cout << "1. Incluir "<< endl;
        cout << "2. Excluir" << endl;
        cout << "3. Alterar (apenas por CPF)" << endl;
        cout << "4. Listar" << endl;
        cout << "5. Localizar (por CPF)" << endl;
        cout << "0. Sair." << endl;

        cin >> opcao;

        switch (opcao){

            case 1:
                passageiros.push_back(incluir_pass());
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
                cout << "Opção não existente, tente novamente!!" << endl; 
                break;
        }
    }
    
    return 0;
}