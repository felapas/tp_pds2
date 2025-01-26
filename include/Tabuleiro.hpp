#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <vector>
#include <iostream>

/**
 * @file Tabuleiro.hpp
 * @brief Representação do tabuleiro de um jogo.
 * 
 * Esta classe representa um tabuleiro genérico para jogos, com funcionalidades
 * para exibir o tabuleiro, acessar e modificar posições, e verificar a validade
 * de uma posição.
 */

/**
 * @class Tabuleiro
 * @brief Classe que representa o tabuleiro de um jogo.
 * 
 * O tabuleiro é representado por uma matriz de caracteres, onde cada posição pode
 * conter um caractere que representa o estado daquela célula (por exemplo, 'X', 'O' ou ' ').
 */
class Tabuleiro {
private:
    int linhas; ///< Número de linhas do tabuleiro.
    int colunas; ///< Número de colunas do tabuleiro.
    std::vector<std::vector<char>> matriz; ///< Matriz que representa o tabuleiro.

public:
    /**
     * @brief Construtor da classe Tabuleiro.
     * 
     * Inicializa o tabuleiro com o número de linhas e colunas especificado, e preenche
     * todas as posições com o caractere de espaço (' ').
     * 
     * @param[in] linhas Número de linhas do tabuleiro.
     * @param[in] colunas Número de colunas do tabuleiro.
     */
    Tabuleiro(int linhas, int colunas) 
        : linhas(linhas), colunas(colunas), matriz(linhas, std::vector<char>(colunas, ' ')) {}

    /**
     * @brief Exibe o tabuleiro no console.
     * 
     * Formata e exibe o estado atual do tabuleiro, mostrando as linhas e colunas
     * com os caracteres correspondentes.
     */
    void exibirTabuleiro() const;

    /**
     * @brief Retorna o número de linhas do tabuleiro.
     * 
     * @return int Número de linhas do tabuleiro.
     */
    int getLinhas() const;

    /**
     * @brief Retorna o número de colunas do tabuleiro.
     * 
     * @return int Número de colunas do tabuleiro.
     */
    int getColunas() const;

    /**
     * @brief Retorna o caractere em uma posição específica do tabuleiro.
     * 
     * @param[in] linha Linha da posição desejada.
     * @param[in] coluna Coluna da posição desejada.
     * @return char Caractere na posição especificada.
     */
    char getPosicao(int linha, int coluna) const;

    /**
     * @brief Define o caractere em uma posição específica do tabuleiro.
     * 
     * @param[in] linha Linha da posição desejada.
     * @param[in] coluna Coluna da posição desejada.
     * @param[in] simbolo Caractere a ser colocado na posição especificada.
     */
    void setPosicao(int linha, int coluna, char simbolo);

    /**
     * @brief Verifica se uma posição é válida no tabuleiro.
     * 
     * Verifica se a linha e a coluna estão dentro dos limites do tabuleiro.
     * 
     * @param[in] linha Linha da posição desejada.
     * @param[in] coluna Coluna da posição desejada.
     * @return true Se a posição é válida.
     * @return false Se a posição está fora dos limites do tabuleiro.
     */
    bool posicaoValida(int linha, int coluna) const;
};

#endif