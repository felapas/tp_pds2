#include "Tabuleiro.hpp"

// Construtor do tabuleiro
Tabuleiro::Tabuleiro(int linhas, int colunas) {
        if (linhas <= 0 || colunas <= 0) {
            throw std::invalid_argument("Dimensões do tabuleiro devem ser positivas.");
        }
        this->linhas = linhas;
        this->colunas = colunas;
        matriz = std::vector<std::vector<char>>(linhas, std::vector<char>(colunas, ' '));
    };
#define COR_RESET   "\033[0m"
#define COR_ROSA "\033[95m"
#define COR_VERDE    "\033[92m"

// Exibe o tabuleiro na tela
void Tabuleiro::exibirTabuleiro() const {
    std::cout << "PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";

    for (int i = 0; i < linhas; i++) {
        // Linha superior das células
        std::cout << "\t";
        for (int j = 0; j < colunas; j++) {
            std::cout << "     ";
            if (j < colunas - 1) std::cout << "|";
        }
        std::cout << "\n\t";

        // Linha com os valores das células
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == 'X') {
                std::cout << "  " << COR_ROSA << matriz[i][j] << COR_RESET << "  ";
            } else if (matriz[i][j] == 'O') {
                std::cout << "  " << COR_VERDE << matriz[i][j] << COR_RESET << "  ";
            } else {
                std::cout << "  " << matriz[i][j] << "  ";
            }
            if (j < colunas - 1) std::cout << "|";
        }
        std::cout << "\n";

        // Linha divisória entre as células (exceto na última linha)
        if (i < linhas - 1) {
            std::cout << "\t";
            for (int j = 0; j < colunas; j++) {
                std::cout << "_____";
                if (j < colunas - 1) std::cout << "|";
            }
            std::cout << "\n";
        }
    }

    // Linha inferior do tabuleiro
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
