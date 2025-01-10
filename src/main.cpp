#include <iostream>
#include "Jogador.hpp"
#include "Cadastro.hpp"
#include "Jogo_da_Velha.hpp"

int main() {
    // Para ler entrada e saída dos usuários
    std::string entrada;
    // Sistema de cadastro de clientes
    Cadastro sistema;
    sistema.carregarDeArquivo();
    

    while (std::cin >> entrada) {
        // Entrada que cadastra os jogadores
        if (entrada == "CJ") {
            std::string nome, apelido;
            std::cin >> nome >> apelido;
            sistema.cadastrarJogador(nome, apelido);
        }
        // Entrada que remove algum jogador
        if (entrada == "RJ") {
            std::string apelido;
            std::cin >> apelido;
            sistema.removerJogador(apelido);
        }
        // Entrada que lista os jogadores
        if (entrada == "LJ") {
            sistema.listarJogadores();
        }

        // Entrada que executa partida de algum jogo
        if (entrada == "EP") {
            std::cout << "Escolha um jogo:\n";
            std::cout << "1 - Jogo da Velha\n";
            std::cout << "2 - Lig4 (indisponível no momento)\n";
            std::cout << "3 - Reversi (indisponível no momento)\n";
            
            int opcao;
            std::cin >> opcao;

            if (opcao == 1) {
                JogoDaVelha jogo;
                jogo.iniciar();

                while (true) {
                    jogo.exibirTabuleiro();
                    int linha, coluna;

                    do {
                        jogo.lerJogada(linha, coluna);
                    } while (!jogo.validarJogada(linha, coluna));

                    if (jogo.validarVitoria()) {
                        jogo.exibirTabuleiro();
                        break;
                    }
                }
            } else {
                std::cout << "Opção inválida ou jogo não implementado.\n";
            }
        }

        // Finaliza o programa
        if (entrada == "FS") 
            break;
    }

    sistema.salvarEmArquivo();

    return 0;
}