#include <iostream>
#include "Jogador.hpp"
#include "Cadastro.hpp"

int main() {
    // Para ler entrada e saída dos usuários
    std::string entrada;
    // Sistema de cadastro de clientes
    Cadastro sistema;


    while (std::cin >> entrada) {
        // Entradas para o sistema de cadastro de clientes
        if (entrada == "CJ") {
            std::string nome, apelido;
            std::cin >> nome >> apelido;
            sistema.cadastrarJogador(nome, apelido);
        }
        if (entrada == "RJ") {
            std::string apelido;
            std::cin >> apelido;
            sistema.removerJogador(apelido);
        }
        if (entrada == "LJ") {
            sistema.listarJogadores();
        }

        // Entrada que executa partida de algum jogo
        if (entrada == "EP") {
            
        }

        // Finaliza o programa
        if (entrada == "FS") 
            break;
    }

    return 0;
}