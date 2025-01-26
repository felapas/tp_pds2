#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>
#include <string>
#include <map>

/**
 * @file Jogador.hpp
 * @brief Representação de um jogador e suas estatísticas.
 * 
 * Esta classe armazena as informações de um jogador, incluindo nome, apelido
 * e estatísticas de vitórias e derrotas em diferentes jogos.
 */

/**
 * @class Jogador
 * @brief Representa um jogador e suas estatísticas.
 * 
 * A classe Jogador armazena o nome, apelido e estatísticas de vitórias e derrotas
 * em diferentes jogos. As estatísticas são armazenadas em mapas, onde a chave é o
 * nome do jogo e o valor é o número de vitórias ou derrotas.
 */
class Jogador {
private:
    std::string _nome; ///< Nome completo do jogador.
    std::string _apelido; ///< Apelido único do jogador.
    std::map<std::string, int> _vitorias; ///< Mapa de vitórias por jogo.
    std::map<std::string, int> _derrotas; ///< Mapa de derrotas por jogo.

public:
    /**
     * @brief Construtor padrão.
     * 
     * Inicializa um jogador sem nome ou apelido.
     */
    Jogador() = default;

    /**
     * @brief Construtor da classe Jogador.
     * 
     * Inicializa o jogador com nome e apelido, e define as estatísticas iniciais
     * de vitórias e derrotas como zero para todos os jogos.
     * 
     * @param[in] nome Nome completo do jogador.
     * @param[in] apelido Apelido único do jogador.
     */
    Jogador(const std::string& nome, const std::string& apelido);

    /**
     * @brief Retorna o nome do jogador.
     * 
     * @return std::string O nome completo do jogador.
     */
    std::string getNome() const;

    /**
     * @brief Retorna o apelido do jogador.
     * 
     * @return std::string O apelido único do jogador.
     */
    std::string getApelido() const;

    /**
     * @brief Retorna o mapa de vitórias do jogador.
     * 
     * @return std::map<std::string, int> Mapa de vitórias, onde a chave é o nome do jogo
     * e o valor é o número de vitórias.
     */
    std::map<std::string, int> getVitorias() const;

    /**
     * @brief Retorna o mapa de derrotas do jogador.
     * 
     * @return std::map<std::string, int> Mapa de derrotas, onde a chave é o nome do jogo
     * e o valor é o número de derrotas.
     */
    std::map<std::string, int> getDerrotas() const;

    /**
     * @brief Define o número de vitórias do jogador em um jogo específico.
     * 
     * @param[in] jogo Nome do jogo.
     * @param[in] numVitorias Número de vitórias a ser definido.
     */
    void setVitorias(std::string jogo, int numVitorias);

    /**
     * @brief Define o número de derrotas do jogador em um jogo específico.
     * 
     * @param[in] jogo Nome do jogo.
     * @param[in] numDerrotas Número de derrotas a ser definido.
     */
    void setDerrotas(std::string jogo, int numDerrotas);

    /**
     * @brief Incrementa o número de vitórias do jogador em um jogo específico.
     * 
     * @param[in] jogo Nome do jogo.
     */
    void adicionarVitoria(const std::string& jogo);

    /**
     * @brief Incrementa o número de derrotas do jogador em um jogo específico.
     * 
     * @param[in] jogo Nome do jogo.
     */
    void adicionarDerrota(const std::string& jogo);

    /**
     * @brief Exibe as estatísticas do jogador.
     * 
     * Mostra o nome, apelido e o número de vitórias e derrotas em cada jogo.
     */
    void mostrarEstatisticas() const;
};

#endif