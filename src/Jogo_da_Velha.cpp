#include "Jogo_Da_Velha.hpp"

// Construtor
JogoDaVelha::JogoDaVelha() : Jogo("Jogo da Velha", 3, 3), jogadorAtual(1) {}

// Inicia o jogo
void JogoDaVelha::iniciar() {
    std::cout << "Bem-vindo ao Jogo da Velha!" << std::endl;
    tabuleiro = Tabuleiro(3, 3);
    jogadorAtual = 1;            
}

// Lê uma jogada do jogador
void JogoDaVelha::lerJogada(int& linha, int& coluna) {
    std::cout << "Jogador " << jogadorAtual << ", insira sua jogada (linha e coluna): ";
    std::cin >> linha >> coluna;

    linha--;
    coluna--;
}
void JogoDaVelha::lerJogada(int& linha) {
    std::cout << "Jogador " << jogadorAtual << ", você deve informar a linha e a coluna.";
}


int JogoDaVelha::getJogadorAtual(){
    return jogadorAtual;
}


// Valida se a jogada é válida
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

// Valida se a jogada é válida
bool JogoDaVelha::validarJogada(int linha) {
    return false;
}
// Valida se houve vitória ou empate
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
