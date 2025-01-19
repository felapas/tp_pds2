#include "Connect4.hpp"
#include <iostream>

Connect4::Connect4() : Jogo("Connect 4", 6, 7), jogadorAtual(1) {};

void Connect4::iniciar() {
    std::cout << "Bem-vindo ao Conncect4" << std::endl;
    tabuleiro = Tabuleiro(6,7); //
    jogadorAtual = 1;
};

void Connect4::lerJogada(int& linha , int& coluna) {
    std::cout << "Jogador " << jogadorAtual << ", insira a coluna para sua jogada (1 a 7): ";
    std::cin >> coluna;
    coluna--;
}


void Connect4::lerJogada(int& coluna) {
    std::cout << "Jogador " << jogadorAtual << ", insira a coluna para sua jogada (1 a 7): ";
    std::cin >> coluna;
    coluna--;
}

bool Connect4::validarJogada(int coluna) {
    if (coluna < 0 || coluna >= 7) {
        std::cout << "Coluna inválida! Escolha uma entre 1 e 7." << std::endl;
        return false;
    };
    if (tabuleiro.getPosicao(0, coluna) != ' ') {
        std::cout << "Coluna cheia! Escolha outra." << std::endl;
        return false;
    }
    for (int linha = 5; linha >= 0; --linha) {
        if (tabuleiro.getPosicao(linha, coluna) == ' ') {
            char simbolo = (jogadorAtual == 1) ? 'X' : 'O';
            tabuleiro.setPosicao(linha, coluna, simbolo);
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1; 
            return true;
        }
    };

    return false;
};

bool Connect4::validarJogada(int linha , int coluna) {
    if (coluna < 0 || coluna >= 7) {
        std::cout << "Coluna inválida! Escolha uma entre 1 e 7." << std::endl;
        return false;
    };
    if (tabuleiro.getPosicao(0, coluna) != ' ') {
        std::cout << "Coluna cheia! Escolha outra." << std::endl;
        return false;
    }
    for (int linha = 5; linha >= 0; --linha) {
        if (tabuleiro.getPosicao(linha, coluna) == ' ') {
            char simbolo = (jogadorAtual == 1) ? 'X' : 'O';
            tabuleiro.setPosicao(linha, coluna, simbolo);
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1; 
            return true;
        }
    };

    return false;
}

bool Connect4::validarVitoria() {
    const int linhas = 6;
    const int colunas = 7;
    char simboloAtual;

    // Verifica linhas
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas - 3; ++j) {
            simboloAtual = tabuleiro.getPosicao(i, j);
            if (simboloAtual != ' ' &&
                simboloAtual == tabuleiro.getPosicao(i, j + 1) &&
                simboloAtual == tabuleiro.getPosicao(i, j + 2) &&
                simboloAtual == tabuleiro.getPosicao(i, j + 3)) {
                std::cout << "Jogador " << ((simboloAtual == 'X') ? 1 : 2) << " venceu!" << std::endl;
                return true;
            }
        }
    }

    // Verifica colunas
    for (int j = 0; j < colunas; ++j) {
        for (int i = 0; i < linhas - 3; ++i) {
            simboloAtual = tabuleiro.getPosicao(i, j);
            if (simboloAtual != ' ' &&
                simboloAtual == tabuleiro.getPosicao(i + 1, j) &&
                simboloAtual == tabuleiro.getPosicao(i + 2, j) &&
                simboloAtual == tabuleiro.getPosicao(i + 3, j)) {
                std::cout << "Jogador " << ((simboloAtual == 'X') ? 1 : 2) << " venceu!" << std::endl;
                return true;
            }
        }
    }

    // Verifica diagonais (descendente)
    for (int i = 0; i < linhas - 3; ++i) {
        for (int j = 0; j < colunas - 3; ++j) {
            simboloAtual = tabuleiro.getPosicao(i, j);
            if (simboloAtual != ' ' &&
                simboloAtual == tabuleiro.getPosicao(i + 1, j + 1) &&
                simboloAtual == tabuleiro.getPosicao(i + 2, j + 2) &&
                simboloAtual == tabuleiro.getPosicao(i + 3, j + 3)) {
                std::cout << "Jogador " << ((simboloAtual == 'X') ? 1 : 2) << " venceu!" << std::endl;
                return true;
            }
        }
    }

    // Verifica diagonais (ascendente)
    for (int i = 3; i < linhas; ++i) {
        for (int j = 0; j < colunas - 3; ++j) {
            simboloAtual = tabuleiro.getPosicao(i, j);
            if (simboloAtual != ' ' &&
                simboloAtual == tabuleiro.getPosicao(i - 1, j + 1) &&
                simboloAtual == tabuleiro.getPosicao(i - 2, j + 2) &&
                simboloAtual == tabuleiro.getPosicao(i - 3, j + 3)) {
                std::cout << "Jogador " << ((simboloAtual == 'X') ? 1 : 2) << " venceu!" << std::endl;
                return true;
            }
        }
    }
        // Verifica empate
    for (int j = 0; j < colunas; ++j) {
        if (tabuleiro.getPosicao(0, j) == ' ') {
            return false; // Ainda há espaço para jogadas
        }
    }

    std::cout << "Empate!" << std::endl;
    return true;
}

int Connect4::getJogadorAtual() {
    return jogadorAtual;
}