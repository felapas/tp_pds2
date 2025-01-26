#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

#include <iostream>
#include "Jogo.hpp"

/**
 * @file JogoDaVelha.hpp
 * @brief Implementação do jogo da velha.
 * 
 * Esta classe implementa o jogo da velha, onde dois jogadores alternam turnos para
 * marcar espaços em um tabuleiro 3x3. O objetivo é ser o primeiro a alinhar três
 * marcas (horizontal, vertical ou diagonal).
 */

/**
 * @class JogoDaVelha
 * @brief Classe que implementa o jogo da velha.
 * 
 * O jogo da velha é um jogo de estratégia em que dois jogadores alternam turnos
 * para marcar espaços em um tabuleiro 3x3. A classe herda da classe base `Jogo`
 * e implementa seus métodos virtuais.
 */
class JogoDaVelha : public Jogo {
private:
    int jogadorAtual; ///< Indica o jogador atual (1 ou 2).

public:
    /**
     * @brief Construtor da classe JogoDaVelha.
     * 
     * Inicializa o jogo com um tabuleiro 3x3 e define o jogador 1 como o primeiro a jogar.
     */
    JogoDaVelha();

    /**
     * @brief Inicializa o jogo.
     * 
     * Exibe uma mensagem de boas-vindas e prepara o tabuleiro para o início do jogo.
     */
    void iniciar() override;

    /**
     * @brief Lê a jogada do jogador atual (versão não utilizada).
     * 
     * Este método é mantido para compatibilidade com a interface base, mas não é utilizado
     * no jogo da velha, pois o jogo requer a escolha de linha e coluna.
     * 
     * @param[out] linha Linha (não utilizada no jogo da velha).
     */
    void lerJogada(int& linha) override;

    /**
     * @brief Lê a jogada do jogador atual.
     * 
     * Solicita ao jogador atual que insira a linha e a coluna onde deseja jogar.
     * 
     * @param[out] linha Linha escolhida pelo jogador (1-3).
     * @param[out] coluna Coluna escolhida pelo jogador (1-3).
     */
    void lerJogada(int& linha, int& coluna) override;

    /**
     * @brief Valida a jogada do jogador.
     * 
     * Verifica se a posição escolhida é válida e se está vazia.
     * 
     * @param[in] linha Linha escolhida pelo jogador.
     * @param[in] coluna Coluna escolhida pelo jogador.
     * @return true Se a jogada é válida.
     * @return false Se a jogada é inválida (posição ocupada ou fora do intervalo).
     */
    bool validarJogada(int linha, int coluna) override;

    /**
     * @brief Valida a jogada do jogador (versão não utilizada).
     * 
     * Este método é mantido para compatibilidade com a interface base, mas não é utilizado
     * no jogo da velha, pois o jogo requer a escolha de linha e coluna.
     * 
     * @param[in] linha Linha (não utilizada no jogo da velha).
     * @return true Se a jogada é válida.
     * @return false Se a jogada é inválida.
     */
    bool validarJogada(int linha) override;

    /**
     * @brief Verifica se há um vencedor ou empate.
     * 
     * Verifica todas as possíveis combinações de três marcas consecutivas no tabuleiro
     * (horizontal, vertical e diagonal) para determinar se o jogo terminou.
     * 
     * @return true Se houver um vencedor ou empate.
     * @return false Se o jogo deve continuar.
     */
    bool validarVitoria() override;

    /**
     * @brief Retorna o jogador atual.
     * 
     * @return int O jogador atual (1 ou 2).
     */
    int getJogadorAtual() override;
};

#endif