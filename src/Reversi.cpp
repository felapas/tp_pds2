#include "Reversi.hpp"
#include "GerenciadorDeJogos.hpp"

// Cosntrutor do Reversi
Reversi::Reversi() : Jogo("Reversi", 8, 8), jogadorAtual(1) {}

void Reversi::iniciar() {
    std::cout << "Bem vindo ao Reversi!" << std::endl;

    // Peças iniciais centrais são posicionadas
    tabuleiro.setPosicao(3, 3, 'O');
    tabuleiro.setPosicao(3, 4, 'X');
    tabuleiro.setPosicao(4, 3, 'X');
    tabuleiro.setPosicao(4, 4, 'O');
}

void Reversi::lerJogada(int& linha, int& coluna) {
    std::cout << "Jogador " << jogadorAtual << ", insira sua jogada (linha e coluna): ";
    
    while (true) {
        try {
            std::cin >> linha; // Lê a linha
            if (std::cin.fail()) {
                // Tratamento de entrada inválida
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                throw (std::invalid_argument("Opção inválida. Digite um valor inteiro para a linha.\n"));
            }
            linha--; // Ajuste do índice pra começar em 0
            std::cin >> coluna; // Lê a coluna
            if (std::cin.fail()) {
                // Tratamento de entrada inválida
                std::cin.clear();
                std::cin.ignore(32767, '\n');
                throw (std::invalid_argument("Opção inválida. Digite um valor inteiro para a coluna.\n"));
            }
            coluna--; // Ajuste do índice pra começar em 0
            break;
        } catch (const std::invalid_argument& e) {
            // Exibe mensagem de erro e solicita nova entrada
            std::cout << e.what() << std::endl;
            continue;
        }
    }
}

void Reversi::lerJogada(int& linha) {
    std::cout << "Jogador " << jogadorAtual << ", você deve informar a linha e a coluna.";
}

void Reversi::alternarJogador() {
    jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
}

bool Reversi::podeCapturar(int linha, int coluna, int deltaLinha, int deltaColuna) const {
    // Verifica se é possível capturar peças do oponente em uma direção específica
    char simboloAtual = (jogadorAtual == 1) ? 'X' : 'O';
    char simboloOponente = (jogadorAtual == 1) ? 'O' : 'X';

    int i = linha + deltaLinha;
    int j = coluna + deltaColuna;
    bool encontrouOponente = false;

    // Percorre na direção especificada para verificar captura
    while (tabuleiro.posicaoValida(i, j) && tabuleiro.getPosicao(i, j) == simboloOponente) {
        encontrouOponente = true;
        i += deltaLinha;
        j += deltaColuna;
    }

    // Verifica se a captura é válida
    if (encontrouOponente && tabuleiro.posicaoValida(i, j) && tabuleiro.getPosicao(i, j) == simboloAtual) {
        return true;
    }

    return false;
}

void Reversi::capturarPecas(int linha, int coluna, int deltaLinha, int deltaColuna) {
    //Capturar peças do oponente na direção especificada
    char simboloAtual = (jogadorAtual == 1) ? 'X' : 'O';

    int i = linha + deltaLinha;
    int j = coluna + deltaColuna;

    //Substitui as peças do oponente pelas do jogador atual
    while (tabuleiro.getPosicao(i, j) != simboloAtual) {
        tabuleiro.setPosicao(i, j, simboloAtual);
        i += deltaLinha;
        j += deltaColuna;
    }
}

bool Reversi::validarJogada(int linha, int coluna) {
    //Verifica se a jogada é válida
    if (!tabuleiro.posicaoValida(linha, coluna) || tabuleiro.getPosicao(linha, coluna) != ' ') {
        std::cout << "Jogada inválida! Tente novamente." << std::endl;
        return false;
    }

    bool jogadaValida = false;
    //Verifica todas as direções possíveis pra captura de peças
    for (int deltaLinha = -1; deltaLinha <= 1; ++deltaLinha) {
        for (int deltaColuna = -1; deltaColuna <= 1; ++deltaColuna) {
            if (deltaLinha == 0 && deltaColuna == 0) continue;
            if (podeCapturar(linha, coluna, deltaLinha, deltaColuna)) {
                jogadaValida = true;
            }
        }
    }

    if (jogadaValida) {
        // Atualiza o tabuleiro com a jogada e captura as peças
        char simboloAtual = (jogadorAtual == 1) ? 'X' : 'O';
        tabuleiro.setPosicao(linha, coluna, simboloAtual); // Adiciona a peça na posição

        // Captura peças do oponente em todas as direções válidas
        for (int deltaLinha = -1; deltaLinha <= 1; ++deltaLinha) {
            for (int deltaColuna = -1; deltaColuna <= 1; ++deltaColuna) {
                if (deltaLinha == 0 && deltaColuna == 0) continue;
                if (podeCapturar(linha, coluna, deltaLinha, deltaColuna)) {
                    capturarPecas(linha, coluna, deltaLinha, deltaColuna);
                }
            }
        }
        alternarJogador();
    } else {
        std::cout << "Nenhuma peça pôde ser capturada. Jogada inválida!" << std::endl;
    }

    return jogadaValida;
}

bool Reversi::validarJogada(int linha) {
    return false;
}

int Reversi::validarVitoria() {
    // Dois loops que verificam se há movimentos válidos para ambos os jogadores
    
    // Verifica se o tabuleiro está cheio
    bool tabuleiroCheio = true;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro.getPosicao(i, j) == ' ') {
                tabuleiroCheio = false; // Ainda há movimentos possíveis
            }
        }
    }

    bool jogadasPossiveis = false;
    // Verifica se há possibilidade de captura de peças
    for (int linha = 0; linha < 8; ++linha) {
        for (int coluna = 0; coluna < 8; ++coluna) {
            if (tabuleiro.getPosicao(linha, coluna) == ' ') {
                for (int deltaLinha = -1; deltaLinha <= 1; ++deltaLinha) {
                    for (int deltaColuna = -1; deltaColuna <= 1; ++deltaColuna) {
                        if (deltaLinha == 0 && deltaColuna == 0) continue;
                        if (podeCapturar(linha, coluna, deltaLinha, deltaColuna)) {
                            std::cout << "jogador " << jogadorAtual << " pode capturar peças em: " << linha + 1 << ", " << coluna + 1 << std::endl;
                            jogadasPossiveis = true;
                        }
                    }
                }
            }
        }
    }

    // Em caso de vitória, exibe a mensagem de fim de jogo e checa as peças
    // Só é possível haver vitória se o tabuleiro estiver cheio ou o jogador atual estiver sem jogadas possíveis
    if ( !jogadasPossiveis && tabuleiroCheio ) {
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
            jogadorAtual = 1;
            return 1;
        } else if (contagemO > contagemX) {
            std::cout << "Jogador 2 venceu!" << std::endl;
            jogadorAtual = 2;
            return 1;
        } else {
            return 2; // Empate para peças iguais
        }
    }
    return 0;
}

int Reversi::getJogadorAtual() {
    return jogadorAtual;
}
