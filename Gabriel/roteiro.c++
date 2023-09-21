#include <iostream>
#include <vector>
#include <string>


using namespace std;


struct Roteiro
{
    string codigo;
    string DH_prev;
    string DU_pres;
    string origenm;
    string destino;
};
void incluir(vector<Roteiro> &roteiros);//parametro por referencia de main
void excluir(vector<Roteiro> &roteiros,int pos);
void alterar(vector<Roteiro> & roteiros, int pos);
void listar(vector<Roteiro> &roteiros);
void localizar(vector<Roteiro> &roteiros,int pos);
int busca(vector<Roteiro> &roteiros,string codigo);


int  gerenciarRoteiros(vector<Roteiro>&roteiros){
    bool validar;
    int serv;
    string codigo;
    int pos;
    //menu de serviços
    do
    {
        cout << "Tipos de serviços disponíveis: \n 1.Incluir \n 2.Excluir \n 3.Alterar(apenas por codigo) \n 4.Listar \n 5.Localizar(por codigo) \n 0.Sair\n" << endl;;
        cout << "Informe o tipo de serviço desejado: ";
        cin >> serv;  
        switch (serv)
      {
         case 1:
            incluir(roteiros);
            cout << endl;
            break;
         case 2:
            cout << "Informe o codigo do roteiro para exclusão: ";
            cin >> codigo;
            pos = busca(roteiros,codigo);
            excluir(roteiros,pos);
            cout << endl;
            break;
         case 3:
            cout << "Informe o codigo do Roteiro para executar alterações: ";
            cin >> codigo;
            pos = busca(roteiros,codigo);
            alterar(roteiros,pos);
            cout << endl;
            break;
         case 4:
            listar(roteiros);
            cout << endl;
            break;
         case 5:
            cout << "Informe o codigo do Roteiro para localizar: ";
            cin >> codigo;
            pos = busca(roteiros,codigo);
            localizar(roteiros,pos);
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

void incluir(vector<Roteiro> &roteiros){
        Roteiro roteiros;
        cout << "Informe a origem da viagem: ";
        cin >> roteiros.origem;
        cout << endl;
       
        cout << "Informe o do roteiro codigo: ";
        cin >> roteiros.codigo;
        cout << endl;

        cout << "Informe : ";
        cin >> roteiros.destino;
        cout << endl;
        
        cout << "Informe o numero do codigo: ";
        cin >> roteiros.codigo;
        cout << endl;
        
        Roteiro.push_back(roteiros);
}
int busca(vector<Roteiro> &roteiros, string codigo) {

    for (auto i = 0u; i < roteiros.size(); ++i) {
        if (roteiros[i].codigo == codigo)
            return i;//encontrou;
    }
    return -1;//não encontrou;
}

 void excluir(vector<Roteiro> &roteiros,int pos){
    if (pos != -1)
    {
        roteiros.erase(roteiros.begin()+pos);
    }else{
        cout << "roteiros não encontrado." << endl;
    }
}

void alterar(vector<Roteiro> & roteiros, int pos){
    
    string confirm;

    if (pos != -1)
    {
        cout << "Deseja alterar o origem do Roteiro? S ou N.";
        cin >> confirm;
        if (confirm == "S"|| confirm == "s")
        {
            cout << "Digite o novo origem: ";
            cin >> roteiros[pos].origem;
            cout << endl;
        }
        cout << "Deseja alterar o codigo do Roteiro? S ou N.";
        cin >> confirm;
        if (confirm == "S"||confirm == "s")
        {
            cout << "Digite o novo codigo: ";
            cin >> roteiros[pos].codigo;
            cout << endl;
        }
        cout << "Deseja alterar a data de nascimento do Roteiro? S ou N.";
        cin >> confirm;
        if (confirm == "S"||confirm == "s")
        {
            cout << "Digite a nova data de nascimento: ";
            cin >> roteiros[pos].destino;
            cout << endl;
        }
        cout << "Deseja alterar o numero de altorização do Roteiro? S ou N.";
        cin >> confirm;
        if (confirm == "S"||confirm == "s")
        {
            cout << "Digite a novo numeno de altorização: ";
            cin >> roteiros[pos].numalt;
            cout << endl;
        }
    }else{
        cout << "roteiros não encontrado." << endl;
    }


}

void listar(vector<Roteiro> &roteiros) {

    for (auto i = 0u; i < roteiros.size(); ++i) {
       cout << i+1 << ". " << "origem " << roteiros[i].origem << " codigo " << roteiros[i].codigo << " Data de nascimento " << roteiros[i].destino << " numero de altorização " << roteiros[i].numalt << endl;
    }
}

 void localizar(vector<Roteiro> &roteiros,int pos){
    if (pos != -1)
    {
        cout << "origem " << roteiros[pos].origem << " codigo " << roteiros[pos].codigo << " Data de nascimento " << roteiros[pos].destino << " numero de altorização " << roteiros[pos].numalt << endl;
    }else{
        cout << "roteiros não encontrado." << endl;
    }
}