#include "Tabuleiro.hpp"
#include <iostream>

// Construtor do tabuleiro
Tabuleiro::Tabuleiro(int linhas, int colunas) {
        if (linhas <= 0 || colunas <= 0) {
            throw std::invalid_argument("Dimensões do tabuleiro devem ser positivas.");
        }
        this->linhas = linhas;
        this->colunas = colunas;
        matriz = std::vector<std::vector<char>>(linhas, std::vector<char>(colunas, ' '));
    };
// Inicializa a variável estática
Tabuleiro::Tema Tabuleiro::temaAtual = Tabuleiro::Tema::Tradicional;

void Tabuleiro::setTema(Tema novoTema) {
    temaAtual = novoTema;
}

Tabuleiro::Tema Tabuleiro::getTema() {
    return temaAtual;
}

#define COR_RESET   "\033[0m"
#define COR_VERMELHO "\033[91m"
#define COR_AZUL     "\033[94m"
#define COR_ROSA     "\033[95m"
#define COR_VERDE    "\033[92m"
#define COR_AMARELO  "\033[93m"
#define COR_PRETO    "\033[30m"
#define COR_BRANCO   "\033[97m"

// Exibe o tabuleiro na tela
void Tabuleiro::exibirTabuleiro() const {
    std::string corX, corO;

    switch (temaAtual) {
        case Tema::Tradicional:
            corX = COR_VERMELHO;
            corO = COR_AZUL;
            break;
        case Tema::Cyberpunk:
            corX = COR_ROSA;
            corO = COR_VERDE;
            break;
        case Tema::Natal:
            corX = COR_VERMELHO;
            corO = COR_VERDE;
            break;
        case Tema::Brasil:
            corX = COR_AMARELO;
            corO = COR_AZUL;
            break;
        case Tema::GaloDoido:
            corX = COR_BRANCO;
            corO = COR_PRETO;
            break;
    }

    std::cout << "PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";

    for (int i = 0; i < linhas; i++) {
        std::cout << "\t";
        for (int j = 0; j < colunas; j++) {
            std::cout << "     ";
            if (j < colunas - 1) std::cout << "|";
        }
        std::cout << "\n\t";

        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == 'X') {
                std::cout << "  " << corX << matriz[i][j] << COR_RESET << "  ";
            } else if (matriz[i][j] == 'O') {
                std::cout << "  " << corO << matriz[i][j] << COR_RESET << "  ";
            } else {
                std::cout << "  " << matriz[i][j] << "  ";
            }
            if (j < colunas - 1) std::cout << "|";
        }
        std::cout << "\n";

        if (i < linhas - 1) {
            std::cout << "\t";
            for (int j = 0; j < colunas; j++) {
                std::cout << "_____";
                if (j < colunas - 1) std::cout << "|";
            }
            std::cout << "\n";
        }
    }

    std::cout << "\t";
    for (int j = 0; j < colunas; j++) {
        std::cout << "     ";
        if (j < colunas - 1) std::cout << "|";
    }
    std::cout << "\n";
}

int Tabuleiro::getLinhas() const {
    return linhas;
}

int Tabuleiro::getColunas() const {
    return colunas;
}

char Tabuleiro::getPosicao(int linha, int coluna) const {
    return matriz[linha][coluna];
}

void Tabuleiro::setPosicao(int linha, int coluna, char simbolo) {
    matriz[linha][coluna] = simbolo; 
}

// Verifica se a posição está dentro do tabuleiro definido
bool Tabuleiro::posicaoValida(int linha, int coluna) const {
    return linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas;
}
