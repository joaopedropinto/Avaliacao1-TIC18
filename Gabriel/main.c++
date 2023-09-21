#include <iostream>
#include <vector>

#include "passageiro.c++"
#include "roteiro.c++"



int main(){
    vector<Passageiro> passageiros;//vector principal passageiros
    vector<Roteiro> roteiros;//vector principal roteiros
    
    int serv;

    cout << "1.Gerenciar passageiros \n 2.Gerencias Roteiros \n 0.Sair \n";
    cout << "Serviço escolhido:";
    cin >> serv;
    cout << endl;
    
    switch (serv)
    {
    case 1:
        
        gerenciarPassageiros(passageiros);
        break;
    case 2:
        //gerenciarRoteiros(passageiros);
        break;
    default:
        break;
    }

    return 0;
}