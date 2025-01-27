#include "Connect4.hpp"
#include "GerenciadorDeJogos.hpp"
#include <iostream>

// Construtor da classe Connect4
Connect4::Connect4() : Jogo("Connect4", 6, 7), jogadorAtual(1) {};

// Inicializa o jogo Connect4 e define o tamanho do tabuleiro
void Connect4::iniciar() {
    std::cout << "Bem-vindo ao Connect4" << std::endl
    << "Escolha o seu tamanho de tabuleiro (insira um valor de 1 a 7): " << std::endl
    << " [1] 6 linhas x 7 colunas (mais usado)\n [2] 4×5\n [3] 5×6\n [4] 7×8\n"
    << " [5] 7×9\n [6] 7×10\n [7] 8×8" << std::endl;

    int opcao = 1;
    while (true) {
        try {
            std::cin >> opcao;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                throw (std::invalid_argument("Opção inválida. Digite um valor inteiro de 1 a 7.\n"));
            }
            if ( opcao < 1 ) {
                throw (std::invalid_argument("Valor muito baixo. Digite um valor inteiro de 1 a 7.\n"));
            } else if ( opcao > 7 ) {
                throw (std::invalid_argument("Valor muito alto. Digite um valor inteiro de 1 a 7.\n"));
            }
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            continue;
        }
    }
    
    if ( opcao == 1 ) {
        tabuleiro = Tabuleiro(6, 7);
    } else if ( opcao == 2 ) {
        tabuleiro = Tabuleiro(4, 5);
    } else if ( opcao == 3 ) {
        tabuleiro = Tabuleiro(5, 6);
    } else if ( opcao == 4 ) {
        tabuleiro = Tabuleiro(7, 8);
    } else if ( opcao == 5 ) {
        tabuleiro = Tabuleiro(7, 9);
    } else if ( opcao == 6 ) {
        tabuleiro = Tabuleiro(7, 10);
    } else if ( opcao == 7 ) {
        tabuleiro = Tabuleiro(8, 8);
    }
};

void Connect4::lerJogada(int& linha , int& coluna) {
    std::cout << "Jogador " << jogadorAtual << ", insira a coluna para sua jogada (1 a 7): ";
    std::cin >> linha; // Inutilizada, apenas para manter a assinatura da função, 
                       // pois o Connect4 não usa linha, apenas coluna
    coluna--;
}

// Lê a jogada do jogador atual
void Connect4::lerJogada(int& coluna) {
    std::cout << "Jogador " << jogadorAtual << ", insira a coluna para sua jogada "
    << "(insira apenas um valor de 1 a " << tabuleiro.getColunas() << "): ";
    
    while (true) {
        try {
            std::cin >> coluna;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                throw (std::invalid_argument("Opção inválida. Digite um valor inteiro.\n"));
            }
            coluna--;
            break;
        } catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
            continue;
        }
    }
}

// Valida a jogada do jogador atual e atualiza o tabuleiro
bool Connect4::validarJogada(int coluna) {
    if ( coluna < 0 || coluna >= tabuleiro.getColunas() ) {
        std::cout << "Coluna inválida! Escolha uma entre 1 e " << tabuleiro.getColunas() << "." << std::endl;
        return false;
    };
    if (tabuleiro.getPosicao(0, coluna) != ' ') {
        std::cout << "Coluna cheia! Escolha outra." << std::endl;
        return false;
    }
    for (int linha = tabuleiro.getLinhas() - 1; linha >= 0; --linha) {
        if (tabuleiro.getPosicao(linha, coluna) == ' ') {
            char simbolo = (jogadorAtual == 1) ? 'X' : 'O';
            tabuleiro.setPosicao(linha, coluna, simbolo);
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1; 
            return true;
        }
    };

    return false;
};

bool Connect4::validarJogada(int linha , int coluna) { // Também inutilizada, apenas para manter a assinatura da função
    if (coluna < 0 || coluna >= 7) {
        std::cout << "Coluna inválida! Escolha uma entre 1 e 7." << std::endl;
        return false;
    };
    if (tabuleiro.getPosicao(0, coluna) != ' ') {
        std::cout << "Coluna cheia! Escolha outra." << std::endl;
        return false;
    }
    for (linha = 5; linha >= 0; --linha) {
        if (tabuleiro.getPosicao(linha, coluna) == ' ') {
            char simbolo = (jogadorAtual == 1) ? 'X' : 'O';
            tabuleiro.setPosicao(linha, coluna, simbolo);
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1; 
            return true;
        }
    };

    return false;
}

// Verifica se houve vitória após a última jogada percorrendo o tabuleiro
int Connect4::validarVitoria() {
    const int linhas = tabuleiro.getLinhas();
    const int colunas = tabuleiro.getColunas();
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
                return 1;
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
                return 1;
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
                return 1;
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
                return 1;
            }
        }
    }
        // Verifica empate
    for (int j = 0; j < colunas; ++j) {
        if (tabuleiro.getPosicao(0, j) == ' ') {
            return 0; // Ainda há espaço para jogadas
        }
    }

    return 2;
}

int Connect4::getJogadorAtual() {
    return jogadorAtual;
}