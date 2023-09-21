#include <iostream>
#include <vector>
#include <string>
#include<algorithm>

using namespace std;

struct Passageiro
{
    string cpf;
    string nome;
    string dtnas;
    int numalt;
};
void incluir(vector<Passageiro> &passageiros);//parametro por referencia de main
void excluir(vector<Passageiro> &passageiros,int pos);
void alterar(vector<Passageiro> & passageiros, int pos);
void listar(vector<Passageiro> &passageiros);
void localizar(vector<Passageiro> &passageiros,int pos);
int busca(vector<Passageiro> &passageiros,string cpf);


int  gerenciarPassageiros(vector<Passageiro>&passageiros){
    bool validar;
    int serv;
    string cpf;
    int pos;
    //menu de serviços
    do
    {
        cout << "Tipos de serviços disponíveis: \n 1.Incluir \n 2.Excluir \n 3.Alterar(apenas por CPF) \n 4.Listar \n 5.Localizar(por CPF) \n 0.Sair\n" << endl;;
        cout << "Informe o tipo de serviço desejado: ";
        cin >> serv;  
        switch (serv)
      {
         case 1:
            incluir(passageiros);
            cout << endl;
            break;
         case 2:
            cout << "Informe o cpf do passageiro para exclusão: ";
            cin >> cpf;
            pos = busca(passageiros,cpf);
            excluir(passageiros,pos);
            cout << endl;
            break;
         case 3:
            cout << "Informe o cpf do passageiro para executar alterações: ";
            cin >> cpf;
            pos = busca(passageiros,cpf);
            alterar(passageiros,pos);
            cout << endl;
            break;
         case 4:
            listar(passageiros);
            cout << endl;
            break;
         case 5:
            cout << "Informe o cpf do passageiro para localizar: ";
            cin >> cpf;
            pos = busca(passageiros,cpf);
            localizar(passageiros,pos);
            cout << endl;
            break;        
         case 0:
            validar = false;
            cout << "Obrigado por usar nossos serviços." << endl;
         break;
      }
       validar = true;
    } while ( validar);
    
    
    return 0;
}

void incluir(vector<Passageiro> &passageiros){
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
        
        cout << "Informe o numero de altenticação: ";
        cin >> passageiro.numalt;
        cout << endl;
        
        passageiros.push_back(passageiro);
}
int busca(vector<Passageiro> &passageiros, string cpf) {

    for (auto i = 0u; i < passageiros.size(); ++i) {
        if (passageiros[i].cpf == cpf)
            return i;//encontrou;
    }
    return -1;//não encontrou;
}

 void excluir(vector<Passageiro> &passageiros,int pos){
    if (pos != -1)
    {
        passageiros.erase(passageiros.begin()+pos);
    }else{
        cout << "Passageiros não encontrado." << endl;
    }
}

void alterar(vector<Passageiro> & passageiros, int pos){
    
    string confirm;

    if (pos != -1)
    {
        cout << "Deseja alterar o nome do passageiro? S ou N.";
        cin >> confirm;
        if (confirm == "S"|| confirm == "s")
        {
            cout << "Digite o novo nome: ";
            cin >> passageiros[pos].nome;
            cout << endl;
        }
        cout << "Deseja alterar o CPF do passageiro? S ou N.";
        cin >> confirm;
        if (confirm == "S"||confirm == "s")
        {
            cout << "Digite o novo CPF: ";
            cin >> passageiros[pos].cpf;
            cout << endl;
        }
        cout << "Deseja alterar a data de nascimento do passageiro? S ou N.";
        cin >> confirm;
        if (confirm == "S"||confirm == "s")
        {
            cout << "Digite a nova data de nascimento: ";
            cin >> passageiros[pos].dtnas;
            cout << endl;
        }
        cout << "Deseja alterar o numero de altorização do passageiro? S ou N.";
        cin >> confirm;
        if (confirm == "S"||confirm == "s")
        {
            cout << "Digite a novo numeno de altorização: ";
            cin >> passageiros[pos].numalt;
            cout << endl;
        }
    }else{
        cout << "Passageiros não encontrado." << endl;
    }


}

void listar(vector<Passageiro> &passageiros) {

    for (auto i = 0u; i < passageiros.size(); ++i) {
       cout << i+1 << ". " << "Nome " << passageiros[i].nome << " CPF " << passageiros[i].cpf << " Data de nascimento " << passageiros[i].dtnas << " numero de altorização " << passageiros[i].numalt << endl;
    }
}

 void localizar(vector<Passageiro> &passageiros,int pos){
    if (pos != -1)
    {
        cout << "Nome " << passageiros[pos].nome << " CPF " << passageiros[pos].cpf << " Data de nascimento " << passageiros[pos].dtnas << " numero de altorização " << passageiros[pos].numalt << endl;
    }else{
        cout << "Passageiros não encontrado." << endl;
    }
}