#include <iostream>
#include "Jogador.hpp"
#include "Cadastro.hpp"
#include "Connect4.hpp"
#include "Jogo_da_Velha.hpp"
#include "Reversi.hpp"
#include "GerenciadorDeJogos.hpp"
int main() {
    // Para ler entrada e saída dos usuários
    std::string entrada;
    // Sistema de cadastro de clientes
    Cadastro sistema;
    GerenciadorDeJogos gerenciador(sistema);
    sistema.carregarDeArquivo();
    std::cout << "Olá! Este é o Menu, escolha o que deseja fazer: " << std::endl 
    << "[CJ] - cadastrar um jogador" <<std::endl << "[RJ] - remover um jogador" <<std::endl
    << "[LJ] - listar jogadores" <<std::endl << "[EP] - escolher algum jogo para jogar!" <<std::endl;

    while (std::cin >> entrada) {
        // Entrada que cadastra os jogadores
        if (entrada == "CJ") {
            std::string nome, apelido;
            std::cout<< "Insira o nome do jogador: ";
            std::cin >> nome;
            std::cout<< "Insita o apelido do jogador: ";
            std::cin >> apelido;
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
            std::cout << "2 - Connect4\n";
            std::cout << "3 - Reversi (indisponível no momento)\n";
            
            int opcao;
            std::cin >> opcao;

            Jogo* jogo;
            if (1 <= opcao <= 3) {
                gerenciador.selecionarJogadores();
                gerenciador.executarJogo(jogo, opcao);
            }
            else {
                std::cout << "Opção inválida ou jogo não implementado.\n";
            }
        }

            // Finaliza o programa
        if (entrada == "FS"){
            sistema.salvarEmArquivo();
            break;
        }
    }
}
