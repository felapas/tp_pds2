#ifndef JOGO_CONNECT4_H
#define JOGO_CONNECT4_H

#include <iostream>
#include "Jogo.hpp"

/**
 * @file Connect4.hpp
 * @brief Implementação do jogo Connect 4.
 * 
 * Esta classe implementa o jogo Connect 4, onde dois jogadores competem para alinhar
 * quatro peças consecutivas (horizontal, vertical ou diagonal) em um tabuleiro 6x7.
 * A classe herda da classe base `Jogo` e implementa seus métodos virtuais.
 */

/**
 * @class Connect4
 * @brief Classe que implementa o jogo Connect 4.
 * 
 * O Connect 4 é um jogo de estratégia em que os jogadores alternam turnos para
 * inserir peças em uma coluna do tabuleiro. O objetivo é ser o primeiro a alinhar
 * quatro peças consecutivas.
 */
class Connect4 : public Jogo {
private:
    int jogadorAtual; ///< Indica o jogador atual (1 ou 2).

public:
    /**
     * @brief Construtor da classe Connect4.
     * 
     * Inicializa o jogo com um tabuleiro 6x7 e define o jogador 1 como o primeiro a jogar.
     */
    Connect4();

    /**
     * @brief Inicializa o jogo.
     * 
     * Exibe uma mensagem de boas-vindas e prepara o tabuleiro para o início do jogo.
     */
    void iniciar() override;

    /**
     * @brief Lê a jogada do jogador atual (versão para Connect 4).
     * 
     * Solicita ao jogador atual que insira a coluna onde deseja jogar.
     * 
     * @param[out] coluna Coluna escolhida pelo jogador (1-7).
     */
    void lerJogada(int& coluna) override;

    /**
     * @brief Lê a jogada do jogador atual (versão não utilizada).
     * 
     * Este método é mantido para compatibilidade com a interface base, mas não é utilizado
     * no Connect 4, pois o jogo só requer a escolha de uma coluna.
     * 
     * @param[out] coluna Coluna escolhida pelo jogador.
     * @param[out] linha Linha (não utilizada no Connect 4).
     */
    void lerJogada(int& coluna, int& linha) override;

    /**
     * @brief Valida a jogada do jogador (versão para Connect 4).
     * 
     * Verifica se a coluna escolhida é válida e se há espaço disponível nela.
     * 
     * @param[in] coluna Coluna escolhida pelo jogador.
     * @return true Se a jogada é válida.
     * @return false Se a jogada é inválida (coluna cheia ou fora do intervalo).
     */
    bool validarJogada(int coluna) override;

    /**
     * @brief Valida a jogada do jogador (versão não utilizada).
     * 
     * Este método é mantido para compatibilidade com a interface base, mas não é utilizado
     * no Connect 4, pois o jogo só requer a escolha de uma coluna.
     * 
     * @param[in] linha Linha (não utilizada no Connect 4).
     * @param[in] coluna Coluna escolhida pelo jogador.
     * @return true Se a jogada é válida.
     * @return false Se a jogada é inválida.
     */
    bool validarJogada(int linha, int coluna) override;

    /**
     * @brief Verifica se há um vencedor ou empate.
     * 
     * Verifica todas as possíveis combinações de quatro peças consecutivas no tabuleiro
     * (horizontal, vertical e diagonal) para determinar se o jogo terminou.
     * 
     * @return 1 Se houver um vencedor.
     * @return 0 Se o jogo deve continuar.
     * @return 2 Se o jogo terminou em empate.
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