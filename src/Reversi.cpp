#include "Reversi.hpp"


Reversi::Reversi() : Jogo("Reversi", 8, 8), jogadorAtual(1) {}

void Reversi::iniciar() {
    std::cout << "Bem vindo ao Reversi!" << std::endl;
    tabuleiro = Tabuleiro(8, 8);
    jogadorAtual = 1;

    //posicoes iniciais
    tabuleiro.setPosicao(3, 3, 'O');
    tabuleiro.setPosicao(3, 4, 'X');
    tabuleiro.setPosicao(4, 3, 'X');
    tabuleiro.setPosicao(4, 4, 'O');
}

void Reversi::lerJogada(int& linha, int& coluna){
    std::cout << "Jogador " << jogadorAtual << ", insira sua jogada (linha e coluna): ";
    std::cin >> linha >> coluna;

//ajuste para indices iniciando em 0
    linha --;
    coluna--;
}

void Reversi::alternarJogador() {
    jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
}

bool Reversi::podeCapturar(int linha, int coluna, int deltaLinha, int deltaColuna) const {
    char simboloAtual = (jogadorAtual == 1) ? 'X' : 'O';
    char simboloOponente = (jogadorAtual == 1) ? 'O' : 'X';

    int i = linha + deltaLinha;
    int j = coluna + deltaColuna;
    bool encontrouOponente = false;

    while (tabuleiro.posicaoValida(i, j) && tabuleiro.getPosicao(i, j) == simboloOponente) {
        encontrouOponente = true;
        i += deltaLinha;
        j += deltaColuna;
    }

    if (encontrouOponente && tabuleiro.posicaoValida(i, j) && tabuleiro.getPosicao(i, j) == simboloAtual) {
        return true;
    }

    return false;
}

void Reversi::capturarPecas(int linha, int coluna, int deltaLinha, int deltaColuna) {
    char simboloAtual = (jogadorAtual == 1) ? 'X' : 'O';

    int i = linha + deltaLinha;
    int j = coluna + deltaColuna;

    while (tabuleiro.getPosicao(i, j) != simboloAtual) {
        tabuleiro.setPosicao(i, j, simboloAtual);
        i += deltaLinha;
        j += deltaColuna;
    }
}

bool Reversi::validarJogada(int linha, int coluna) {
    if (!tabuleiro.posicaoValida(linha, coluna) || tabuleiro.getPosicao(linha, coluna) != ' ') {
        std::cout << "Jogada inválida! Tente novamente." << std::endl;
        return false;
    }

    bool jogadaValida = false;
    for (int deltaLinha = -1; deltaLinha <= 1; ++deltaLinha) {
        for (int deltaColuna = -1; deltaColuna <= 1; ++deltaColuna) {
            if (deltaLinha == 0 && deltaColuna == 0) continue;
            if (podeCapturar(linha, coluna, deltaLinha, deltaColuna)) {
                capturarPecas(linha, coluna, deltaLinha, deltaColuna);
                jogadaValida = true;
            }
        }
    }

    if (!jogadaValida) {
        std::cout << "Nenhuma peça capturada. Jogada inválida!" << std::endl;
    }

    return jogadaValida;
}
bool Reversi::validarJogada(int linha) {
    return false;
}


bool Reversi::validarVitoria() {
    // Verifica se há movimentos válidos para ambos os jogadores
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro.getPosicao(i, j) == ' ') {
                return false; // Ainda há movimentos possíveis
            }
        }
    }

    // Calcula o número de peças de cada jogador
    int contagemX = 0, contagemO = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro.getPosicao(i, j) == 'X') contagemX++;
            if (tabuleiro.getPosicao(i, j) == 'O') contagemO++;
        }
    }

    std::cout << "Fim do jogo!" << std::endl;
    std::cout << "Jogador 1 (X): " << contagemX << " peças" << std::endl;
    std::cout << "Jogador 2 (O): " << contagemO << " peças" << std::endl;

    if (contagemX > contagemO) {
        std::cout << "Jogador 1 venceu!" << std::endl;
    } else if (contagemO > contagemX) {
        std::cout << "Jogador 2 venceu!" << std::endl;
    } else {
        std::cout << "Empate!" << std::endl;
    }
    return true;
}

int Reversi::getJogadorAtual() {
    return jogadorAtual;
}
