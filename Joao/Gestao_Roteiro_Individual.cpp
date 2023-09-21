#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <regex>
#include <limits>

using namespace std;

struct Roteiro
{
  int codigo;
  string data_horaPrevista;
  string duracaoPrevista;
  string origem;
  string destino;
};

bool teste_codigo(const int &codigo, vector<Roteiro> &roteiros)
{

  Roteiro roteiro;
  for (const auto &roteiro : roteiros)
  {
    if (roteiro.codigo == codigo)
    {
      return false;
    }
  }
  return true;
}
void limpar_buffer(){
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool validar_datahora(const string& dataHora) {
    regex padrao(R"((0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/\d{4} (0[0-9]|1[0-9]|2[0-3]):[0-5][0-9])");

    return regex_match(dataHora, padrao);
}

bool validar_duracao(const string& duracao){
  regex padrao("([01]?[0-9]|2[0-3]):[0-5][0-9]");
  
  return regex_match(duracao, padrao);
}


void incluir_rote(vector<Roteiro> &roteiros)
{

  Roteiro roteiro;
  int codigo;
  bool teste;

  do
  {
    cout << "Informe o Código do roteiro: ";
    cin >> codigo;

    if (teste_codigo(codigo, roteiros))
    {
      roteiro.codigo = codigo;
      teste = true;
    }
    else
    {
      cout << "Código inválido! Tente novamente!" << endl;
      teste = false;
    }
  } while(teste == false);

  cout << "Informe a Data e Hora Prevista (formato dd/mm/aaaa hh:mm): ";
  limpar_buffer();
  getline(cin, roteiro.data_horaPrevista);

  while(true){

    if(validar_datahora(roteiro.data_horaPrevista)){
      break;
    }else{
      cout << "Data ou hora incorretos! Tente novamente!" << endl;
      cout << "Informe a Data e Hora Prevista (formato dd/mm/aaaa hh:mm): ";
      getline(cin, roteiro.data_horaPrevista);
    }

  }

  do{

    cout << "Informe a Duração Prevista (formato hh:mm): ";
    cin >> roteiro.duracaoPrevista;
    if(validar_duracao(roteiro.duracaoPrevista)){
      teste = true;
    }else{
      cout << "Duração incorreta! Tente novamente!" << endl;
      teste = false;
    }
  }while(teste == false);

  cout << "Informe a Origem: ";
  limpar_buffer();
  getline(cin, roteiro.origem);
  

  cout << "Informe o Destino: ";
  getline(cin, roteiro.destino);

  roteiros.push_back(roteiro);
  cout << "Roteiro incluído com sucesso!" << endl;
}

void excluir_rote(vector<Roteiro> &roteiros)
{
  int codigo;

  cout << "Informe o código do roteiro a ser excluído: " << endl;
  cin >> codigo;

  for (auto it = roteiros.begin(); it != roteiros.end(); it++)
  {
    if (codigo == it->codigo)
    {
      roteiros.erase(it);
      cout << "Roteiro excluido com sucesso!" << endl;
      return;
    }
  }
  cout << "Código " << codigo << " não encontrado!" << endl;
}

void alterar_rote(vector<Roteiro> &roteiros)
{

  int codigo;

  cout << "Informe o código do roteiro a ser alterado: " << endl;
  cin >> codigo;

  for (auto &roteiro : roteiros)
  {

    if (codigo == roteiro.codigo)
    {
      string resp, teste_cpf;
      bool teste;

      cout << "Roteiro encontrado!" << endl;
      cout << "Dados encontrados:" << endl;
      cout << "Código: " << roteiro.codigo << endl;
      cout << "Data e Hora Prevista: " << roteiro.data_horaPrevista << endl;
      cout << "Duração Prevista: " << roteiro.duracaoPrevista << endl;
      cout << "Origem: " << roteiro.origem << endl;
      cout << "Destino: " << roteiro.destino << endl;

      cout << "O codigo do roteiro está incorreto? Se sim, pedimos que insira o roteiro novamente! (S/N)" << endl;
      cin >> resp;

      if (resp == "s" || resp == "sim"){

        for (auto it = roteiros.begin(); it != roteiros.end(); it++){
          if (codigo == it->codigo){
            roteiros.erase(it);
            cout << "Roteiro excluido com sucesso!" << endl;
            return;
          }
        }
      }
      else{
        cout << "Código não alterado!" << endl;
      }

      cout << "Você deseja alterar Data e Hora Prevista?(S/N)" << endl;
      cin >> resp;

      if (resp == "s" || resp == "sim"){
        cout << "Informe a nova Data e Hora Prevista (formato dd/mm/aaaa hh:mm): ";
        limpar_buffer();
        getline(cin, roteiro.data_horaPrevista);

        while(true){

          if(validar_datahora(roteiro.data_horaPrevista)){
            break;
          }else{
            cout << "Data ou hora incorretos! Tente novamente!" << endl;
            cout << "Informe a nova Data e Hora Prevista (formato dd/mm/aaaa hh:mm): ";
            getline(cin, roteiro.data_horaPrevista);
          }
        }

      }else{
        cout << "Data e Hora Prevista não alteradas!" << endl;
      }
      cout << "Você deseja alterar a Duração Prevista?(S/N)" << endl;
      cin >> resp;

      if (resp == "s" || resp == "sim"){
        do{
          cout << "Informe a nova Duração Prevista (formato hh:mm): ";
          cin >> roteiro.duracaoPrevista;
          if(validar_duracao(roteiro.duracaoPrevista)){
            teste = true;
          }else{
            cout << "Duração incorreta! Tente novamente!" << endl;
            teste = false;
          }

      }while(teste == false);

      }else{
        cout << "Duração Prevista não alterada!!" << endl;
      }

      cout << "Você deseja alterar a Origem? (S/N): ";
      cin >> resp;
      if (resp == "s" || resp == "sim"){
        cout << "Informe a nova Origem: ";
        limpar_buffer();
        getline(cin, roteiro.origem);
      }else{
        cout << "Origem não alterada!!" << endl;
      }

      cout << "Você deseja alterar o Destino? (S/N): ";
      cin >> resp;
      if (resp == "s" || resp == "sim"){
        cout << "Informe o novo Destino: ";
        limpar_buffer();
        getline(cin, roteiro.destino);
      }

      cout << "Roteiro atualizado com sucesso!" << endl;
      return;
    }else{
      cout << "Roteiro não encontrado!" << endl;
    }
  }
}

void listar_rote(vector<Roteiro> &roteiros){

  cout << "Lista de Roteiros cadastrados: " << endl;

  for (const auto &roteiro : roteiros)
  {

    cout << "Código: " << roteiro.codigo << ", Data e Hora Prevista: " << roteiro.data_horaPrevista
         << ", Duração Prevista: " << roteiro.duracaoPrevista << ", Origem: " << roteiro.origem
         << ", Destino: " << roteiro.destino << endl;
  }
}

void localizar_rote(vector<Roteiro> &roteiros)
{
  Roteiro roteiro;
  int codigo;

  cout << "Informe o código do Roteiro a ser localizado: " << endl;
  cin >> codigo;

  for (const auto &roteiro : roteiros)
  {
    if (codigo == roteiro.codigo)
    {
      cout << "Dados do roteiro solicitado:" << endl;
      cout << "Código: " << roteiro.codigo << endl;
      cout << "Data e Hora Prevista: " << roteiro.data_horaPrevista << endl;
      cout << "Duração Prevista: " << roteiro.duracaoPrevista << endl;
      cout << "Origem: " << roteiro.origem << endl;
      cout << "Destino: " << roteiro.destino << endl;
      return;
    }
  }
  cout << "Roteiro não encontrado!" << endl;
}

int main(void)
{

  int opcao;
  vector<Roteiro> roteiros;

  while (true)
  {
    cout << endl << "!! Gestão de Roteiros !!" << endl << endl;
    cout << "Insira a opção desejada: " << endl;
    cout << "1. Incluir " << endl;
    cout << "2. Excluir" << endl;
    cout << "3. Alterar (apenas por código)" << endl;
    cout << "4. Listar" << endl;
    cout << "5. Localizar (apenas por código)" << endl;
    cout << "0. Sair." << endl;

    cin >> opcao;

    switch (opcao)
    {

    case 1:
      incluir_rote(roteiros);
      break;

    case 2:
      excluir_rote(roteiros);
      break;

    case 3:
      alterar_rote(roteiros);
      break;

    case 4:
      listar_rote(roteiros);
      break;

    case 5:
      localizar_rote(roteiros);
      break;

    case 0:
      cout << "Obrigado por utilizar nosso serviço!" << endl;
      return 1;
      break;

    default:
      cout << "Opção não existente, tente novamente!" << endl;
      break;
    }
  }

  return 0;
}