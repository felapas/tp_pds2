#ifndef JOGO_H
#define JOGO_H

#include <iostream>
#include "Tabuleiro.hpp"

/**
 * @file Jogo.hpp
 * @brief Interface base para jogos de tabuleiro.
 * 
 * Esta classe define a interface comum para todos os jogos de tabuleiro,
 * incluindo métodos para iniciar o jogo, ler jogadas, validar jogadas e
 * verificar condições de vitória.
 */

/**
 * @class Jogo
 * @brief Classe abstrata que representa um jogo de tabuleiro.
 * 
 * A classe Jogo define a interface básica para jogos de tabuleiro, incluindo
 * métodos para gerenciar o estado do jogo, interagir com os jogadores e
 * verificar condições de vitória. Classes derivadas devem implementar esses
 * métodos para criar jogos específicos.
 */
class Jogo {
protected:
    const std::string nomeJogo; ///< Nome do jogo.
    Tabuleiro tabuleiro; ///< Tabuleiro do jogo.

public:
    /**
     * @brief Construtor da classe Jogo.
     * 
     * Inicializa o jogo com um nome e as dimensões do tabuleiro.
     * 
     * @param[in] nome Nome do jogo.
     * @param[in] linhas Número de linhas do tabuleiro.
     * @param[in] colunas Número de colunas do tabuleiro.
     */
    Jogo(const std::string& nome, int linhas, int colunas)
        : nomeJogo(nome), tabuleiro(linhas, colunas) {}

    /**
     * @brief Inicializa o jogo.
     * 
     * Método puramente virtual que deve ser implementado pelas classes derivadas
     * para configurar o estado inicial do jogo.
     */
    virtual void iniciar() = 0;

    /**
     * @brief Lê a jogada do jogador atual.
     * 
     * Método puramente virtual que deve ser implementado pelas classes derivadas
     * para ler a jogada do jogador atual (linha e coluna).
     * 
     * @param[out] linha Linha escolhida pelo jogador.
     * @param[out] coluna Coluna escolhida pelo jogador.
     */
    virtual void lerJogada(int& linha, int& coluna) = 0;

    /**
     * @brief Lê a jogada do jogador atual (versão para Connect 4).
     * 
     * Método puramente virtual que deve ser implementado pelas classes derivadas
     * para ler a jogada do jogador atual (apenas coluna).
     * 
     * @param[out] coluna Coluna escolhida pelo jogador.
     */
    virtual void lerJogada(int& coluna) = 0;

    /**
     * @brief Valida a jogada do jogador.
     * 
     * Método puramente virtual que deve ser implementado pelas classes derivadas
     * para validar se a jogada é permitida.
     * 
     * @param[in] linha Linha escolhida pelo jogador.
     * @param[in] coluna Coluna escolhida pelo jogador.
     * @return true Se a jogada é válida.
     * @return false Se a jogada é inválida.
     */
    virtual bool validarJogada(int linha, int coluna) = 0;

    /**
     * @brief Valida a jogada do jogador (versão para Connect 4).
     * 
     * Método puramente virtual que deve ser implementado pelas classes derivadas
     * para validar se a jogada é permitida (apenas coluna).
     * 
     * @param[in] coluna Coluna escolhida pelo jogador.
     * @return true Se a jogada é válida.
     * @return false Se a jogada é inválida.
     */
    virtual bool validarJogada(int coluna) = 0;

    /**
     * @brief Verifica se há um vencedor ou empate.
     * 
     * Método puramente virtual que deve ser implementado pelas classes derivadas
     * para verificar se o jogo terminou com uma vitória ou empate.
     * 
     * @return 1 Se houve um vencedor.
     * @return 0 Se o jogo deve continuar.
     * @return 2 Se houve um empate.
     */
    virtual int validarVitoria() = 0;

    /**
     * @brief Exibe o tabuleiro do jogo.
     * 
     * Chama o método `exibirTabuleiro` da classe `Tabuleiro` para mostrar o estado
     * atual do jogo.
     */
    void exibirTabuleiro() const {
        tabuleiro.exibirTabuleiro();
    }

    /**
     * @brief Retorna o jogador atual.
     * 
     * Método puramente virtual que deve ser implementado pelas classes derivadas
     * para retornar o jogador atual (1 ou 2).
     * 
     * @return int O jogador atual.
     */
    virtual int getJogadorAtual() = 0;

    /**
     * @brief Destrutor virtual da classe Jogo.
     * 
     * Garante que o destrutor das classes derivadas seja chamado corretamente.
     */
    virtual ~Jogo() = default;
};

#endif