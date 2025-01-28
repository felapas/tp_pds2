#ifndef REVERSI_H
#define REVERSI_H

#include <iostream>
#include "Jogo.hpp"

/**
 * @file Reversi.hpp
 * @brief Implementação do jogo Reversi (também conhecido como Othello).
 * 
 * Esta classe implementa o jogo Reversi, onde dois jogadores alternam turnos para
 * colocar peças no tabuleiro, capturando as peças do oponente. O objetivo é ter
 * mais peças da sua cor no tabuleiro ao final do jogo.
 */

/**
 * @class Reversi
 * @brief Classe que implementa o jogo Reversi.
 * 
 * O Reversi é um jogo de estratégia em que dois jogadores alternam turnos para
 * colocar peças no tabuleiro, capturando as peças do oponente. A classe herda da
 * classe base `Jogo` e implementa seus métodos virtuais.
 */
class Reversi : public Jogo {
private:
    int jogadorAtual; ///< Indica o jogador atual (1 ou 2).

    /**
     * @brief Verifica se é possível capturar peças em uma direção.
     * 
     * Verifica se, a partir de uma posição específica, é possível capturar peças
     * do oponente em uma direção dada por `deltaLinha` e `deltaColuna`.
     * 
     * @param[in] linha Linha da posição inicial.
     * @param[in] coluna Coluna da posição inicial.
     * @param[in] deltaLinha Direção vertical da verificação (-1, 0, 1).
     * @param[in] deltaColuna Direção horizontal da verificação (-1, 0, 1).
     * @return true Se a captura é possível.
     * @return false Caso contrário.
     */
    bool podeCapturar(int linha, int coluna, int deltaLinha, int deltaColuna) const;

    /**
     * @brief Captura as peças do oponente em uma direção.
     * 
     * A partir de uma posição específica, captura as peças do oponente em uma
     * direção dada por `deltaLinha` e `deltaColuna`.
     * 
     * @param[in] linha Linha da posição inicial.
     * @param[in] coluna Coluna da posição inicial.
     * @param[in] deltaLinha Direção vertical da captura (-1, 0, 1).
     * @param[in] deltaColuna Direção horizontal da captura (-1, 0, 1).
     */
    void capturarPecas(int linha, int coluna, int deltaLinha, int deltaColuna);

public:
    /**
     * @brief Construtor da classe Reversi.
     * 
     * Inicializa o jogo com um tabuleiro 8x8 e define o jogador 1 como o primeiro a jogar.
     */
    Reversi();

    /**
     * @brief Inicializa o jogo.
     * 
     * Configura o tabuleiro com as peças iniciais e exibe uma mensagem de boas-vindas.
     */
    void iniciar() override;

    /**
     * @brief Lê a jogada do jogador atual (versão não utilizada).
     * 
     * Este método é mantido para compatibilidade com a interface base, mas não é utilizado
     * no Reversi, pois o jogo requer a escolha de linha e coluna.
     * 
     * @param[out] linha Linha (não utilizada no Reversi).
     */
    void lerJogada(int& linha) override;

    /**
     * @brief Lê a jogada do jogador atual.
     * 
     * Solicita ao jogador atual que insira a linha e a coluna onde deseja jogar.
     * 
     * @param[out] linha Linha escolhida pelo jogador (1-8).
     * @param[out] coluna Coluna escolhida pelo jogador (1-8).
     */
    void lerJogada(int& linha, int& coluna) override;

    /**
     * @brief Alterna o jogador atual.
     * 
     * Muda o jogador atual de 1 para 2 ou de 2 para 1.
     */
    void alternarJogador();

    /**
     * @brief Valida a jogada do jogador (versão não utilizada).
     * 
     * Este método é mantido para compatibilidade com a interface base, mas não é utilizado
     * no Reversi, pois o jogo requer a escolha de linha e coluna.
     * 
     * @param[in] linha Linha (não utilizada no Reversi).
     * @return true Se a jogada é válida.
     * @return false Se a jogada é inválida.
     */
    bool validarJogada(int linha) override;

    /**
     * @brief Valida a jogada do jogador.
     * 
     * Verifica se a posição escolhida é válida e se resulta em captura de peças do oponente.
     * Em caso positivo, realiza alterações no tabuleiro.
     * 
     * @param[in] linha Linha escolhida pelo jogador.
     * @param[in] coluna Coluna escolhida pelo jogador.
     * @return true Se a jogada é válida. Então, captura as peças do oponente na direção que for possível, e muda o jogador atual e preenche o espaço do tabuleiro correspondente.
     * @return false Se a jogada é inválida.
     */
    bool validarJogada(int linha, int coluna) override;
    
    /**
     * @brief Verifica se há um vencedor ou empate.
     * 
     * Verifica se o jogo terminou (tabuleiro cheio ou sem jogadas válidas) e determina
     * o vencedor com base na contagem de peças.
     * 
     * @return true Se houver um vencedor ou empate.
     * @return false Se o jogo deve continuar.
     */
    int validarVitoria() override;

    /**
     * @brief Retorna o jogador atual.
     * 
     * @return int O jogador atual (1 ou 2).
     */
    int getJogadorAtual() override;
};

#endif