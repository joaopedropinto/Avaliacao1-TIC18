#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>

using namespace std;

int serv;
vector passageiros;

struct Roteiro
{
    string codigo;
    string DH_prev;
    string DU_pres;
    string origenm;
    string destino;
};

struct Passageiro
{
    string cpf;
    string nome;
    string dtnas;
    int numalt;
    Roteiro passageiro;
};

void incluir(){
        Passageiro passageiro;
        cout << "Informe seu nome: ";
        cin >> passageiro.nome;
        cout << endl;
        
        cout << "Informe seu CPF: ";
        cin >> passageiro.cpf;
        cout << endl;

        cout << "Informe sua data de nascimento: ";
        cin >> passageiro.dtnas;
        cout << endl;

        passageiro.numalt = rand() % 1000;
        passageiros.push_back(passageiro);
}

void excluir(vector<Passageiro> & passageiros){
string cpf;

cout << "Informe o cpf do passageiro que deseja excluir: ";
cin >> cpf;

for (int i = 0; i < passageiros.size(); i++)
{
    if (cpf == passageiros[i].cpf)
    {
        passageiros.erase(std::find(passageiros.begin(),passageiros.end(),i));
    }
    
}
}

void alterar(vector<Passageiro> & passageiros){
string cpf;
    cout << "Informe o cpf que deseja alterar";
    cin >> cpf;

    for (int i = 0; i < passageiros.size(); i++){
        if (cpf == passageiros[i].cpf){
        replace(passageiros.begin(), passageiros.end(),passageiros[i].cpf, cpf);
        }
    
    }
}

int main(vector<Passageiro>,string cpf){
srand(time(0));
cout << "Tipos de serviços disponíveis: \n 1.Incluir \n 2.Excluir \n 3.Alterar(apenas por CPF) \n 4.Listar \n 5.Localizar(por CPF) \n 0.Sair";
cin >> serv; 
cout << endl;


while (serv == 1 || serv == 2 || serv == 3 || serv == 4 || serv == 5)
{
    cout << "Informe o tipo de serviço desejado: ";
    cin >> serv;
    
    switch (serv)
      {
         case 1:
            incluir();
            break;
         case 2:
            excluir();
            break;
         case 3:
            alterar();
            break;
         case 4:
            listar();
            break;
         case 5:
            localizar();
            break;         
         default:
      }  
    

}
}