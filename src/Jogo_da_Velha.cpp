#include "Jogo_Da_Velha.hpp"

// Construtor do Jogo da Velha
JogoDaVelha::JogoDaVelha() : Jogo("Jogo da Velha", 3, 3), jogadorAtual(1) {}

// Inicia o jogo
void JogoDaVelha::iniciar() {
    std::cout << "Bem-vindo ao Jogo da Velha!" << std::endl;    
}

// Lê uma jogada do jogador
void JogoDaVelha::lerJogada(int& linha, int& coluna) {
    std::cout << "Jogador " << jogadorAtual << ", insira sua jogada (linha e coluna): ";
    
    while (true) {
        try {
            std::cin >> linha;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                throw (std::invalid_argument("Opção inválida. Digite um valor inteiro para a linha.\n"));
            }
            linha--;
            std::cin >> coluna;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                throw (std::invalid_argument("Opção inválida. Digite um valor inteiro para a coluna.\n"));
            }
            coluna--;
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            continue;
        }
    }
}

// Inutilizada, apenas para o caso de uma entrada inválida
void JogoDaVelha::lerJogada(int& linha) {
    std::cout << "Jogador " << jogadorAtual << ", você deve informar a linha e a coluna.";
}

int JogoDaVelha::getJogadorAtual(){
    return jogadorAtual;
}


// Verifica se a jogada é válida e atualiza o tabuleiro
bool JogoDaVelha::validarJogada(int linha, int coluna) {
    if (!tabuleiro.posicaoValida(linha, coluna)) {
        std::cout << "Posição inválida! Tente novamente." << std::endl;
        return false;
    }

    if (tabuleiro.getPosicao(linha, coluna) != ' ') {
        std::cout << "Posição já ocupada! Tente novamente." << std::endl;
        return false;
    }

    // Atualiza o tabuleiro
    char simbolo = (jogadorAtual == 1) ? 'X' : 'O'; 
    tabuleiro.setPosicao(linha, coluna, simbolo); // Atualiza o tabuleiro
    jogadorAtual = (jogadorAtual == 1) ? 2 : 1; // Alterna o jogador
    return true;
}

// Verifica se a jogada é válida
bool JogoDaVelha::validarJogada(int linha) {
    return false;
}

// Valida se houve vitória ou empate percorrendo o tabuleiro, as linhas, as colunas e as diagonais
bool JogoDaVelha::validarVitoria() {
    // Verifica linhas e colunas
    for (int i = 0; i < 3; ++i) {
        if (tabuleiro.getPosicao(i, 0) == tabuleiro.getPosicao(i, 1) &&
            tabuleiro.getPosicao(i, 1) == tabuleiro.getPosicao(i, 2) &&
            tabuleiro.getPosicao(i, 0) != ' ') {
            std::cout << "Jogador " << ((tabuleiro.getPosicao(i, 0) == 'X') ? 1 : 2) << " venceu!" << std::endl;
            return true;
        }

        if (tabuleiro.getPosicao(0, i) == tabuleiro.getPosicao(1, i) &&
            tabuleiro.getPosicao(1, i) == tabuleiro.getPosicao(2, i) &&
            tabuleiro.getPosicao(0, i) != ' ') {
            std::cout << "Jogador " << ((tabuleiro.getPosicao(0, i) == 'X') ? 1 : 2) << " venceu!" << std::endl;
            return true;
        }
    }

    // Verifica diagonais
    if (tabuleiro.getPosicao(0, 0) == tabuleiro.getPosicao(1, 1) &&
        tabuleiro.getPosicao(1, 1) == tabuleiro.getPosicao(2, 2) &&
        tabuleiro.getPosicao(0, 0) != ' ') {
        std::cout << "Jogador " << ((tabuleiro.getPosicao(0, 0) == 'X') ? 1 : 2) << " venceu!" << std::endl;
        return true;
    }

    if (tabuleiro.getPosicao(0, 2) == tabuleiro.getPosicao(1, 1) &&
        tabuleiro.getPosicao(1, 1) == tabuleiro.getPosicao(2, 0) &&
        tabuleiro.getPosicao(0, 2) != ' ') {
        std::cout << "Jogador " << ((tabuleiro.getPosicao(0, 2) == 'X') ? 1 : 2) << " venceu!" << std::endl;
        return true;
    }

    // Verifica empate
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro.getPosicao(i, j) == ' ') {
                return false;
            }
        }
    }

    std::cout << "Empate!" << std::endl;
    return true;
}
