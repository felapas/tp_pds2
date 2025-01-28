#include <iostream>
#include <set> // Para o conjunto de entradas válidas
#include <string>
#include "Jogador.hpp"
#include "Cadastro.hpp"
#include "Connect4.hpp"
#include "Jogo_Da_Velha.hpp"
#include "Reversi.hpp"
#include "GerenciadorDeJogos.hpp"

// Função que verifica se a entrada do usuário é válida
void verificarEntrada(const std::string& entrada) {
    const std::set<std::string>entradasValidas = {"CJ", "RJ", "LJ", "EP", "FS"};

    if (entradasValidas.find(entrada) == entradasValidas.end()) {
        throw (std::invalid_argument(entrada + ": entrada inválida. Entradas válidas disponíveis no Menu!\n"));
    }
}

int main() {
    // Para ler entrada e saída dos usuários
    std::string entrada;
    // Sistema de cadastro de clientes
    Cadastro sistema;
    GerenciadorDeJogos gerenciador(sistema);
    sistema.carregarDeArquivo();
    std::cout << "----------------------------------------------------------" << std::endl
    << "Olá! Este é o Menu, escolha o que deseja fazer: " << std::endl 
    << "[CJ] - cadastrar um jogador" <<std::endl << "[RJ] - remover um jogador" <<std::endl
    << "[LJ] - listar jogadores" <<std::endl << "[EP] - escolher algum jogo para jogar!" <<std::endl
    << "[FS] - finalizar o programa" << std::endl
    << "----------------------------------------------------------" << std::endl;

    while (true) {
        // Lê a entrada do usuário e verifica exceções de entradas inválidas
        try {
            std::cin >> entrada;
            verificarEntrada(entrada);
        }
        catch (std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            continue;
        }
        // Cadastra os jogadores
        if (entrada == "CJ") {
            std::string nome, apelido;
            std::cout<< "Insira o nome do jogador: ";
            std::cin >> nome;
            std::cout<< "Insira o apelido do jogador: ";
            std::cin >> apelido;
            sistema.cadastrarJogador(nome, apelido);
        }
        // Remove algum jogador
        if (entrada == "RJ") {
            std::string apelido;
            std::cin >> apelido;
            sistema.removerJogador(apelido);
        }
        // Lista os jogadores
        if (entrada == "LJ") {
            sistema.listarJogadores();
        }

        // Entrada que executa partida de algum jogo
        if (entrada == "EP") {
            std::cout << "Escolha um jogo:\n";
            std::cout << "1 - Jogo da Velha\n";
            std::cout << "2 - Connect4\n";
            std::cout << "3 - Reversi\n";
            
            while (true) {
                try {
                    int opcao;

                    std::cin >> opcao;
                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        throw (std::invalid_argument("Opção inválida. Digite um valor inteiro.\n"));
                    }

                    if ( (opcao >= 1) && (opcao <= 3) ) {
                        Jogo* jogo = nullptr;
                        if ( gerenciador.selecionarJogadores() ) {
                            gerenciador.executarJogo(jogo, opcao);
                        }
                        delete jogo;
                        break; // Sai do loop, pois a entrada foi válida (entre 1 e 3)
                    } else {
                        std::cout << "Opção inválida.\n";
                    }
                } catch (const std::invalid_argument& e) {
                    std::cout << e.what() << std::endl;
                    continue;
                }
            }
        }
            // Finaliza o programa
        if (entrada == "FS"){
            sistema.salvarEmArquivo();
            break;
        }
    }
}
