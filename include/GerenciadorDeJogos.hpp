#ifndef GERENCIADOR_DE_JOGOS_H
#define GERENCIADOR_DE_JOGOS_H

#include "Cadastro.hpp"
#include "Jogador.hpp"
#include "Jogo_Da_Velha.hpp"
#include "Connect4.hpp"
#include "Reversi.hpp"
#include <string>

/**
 * @file GerenciadorDeJogos.hpp
 * @brief Gerenciador de execução de jogos.
 * 
 * Esta classe é responsável por gerenciar a execução dos jogos, incluindo:
 * - Seleção de jogadores.
 * - Execução de partidas.
 * - Atualização de estatísticas dos jogadores.
 */

/**
 * @class GerenciadorDeJogos
 * @brief Gerencia a execução de jogos e a interação com os jogadores.
 * 
 * O GerenciadorDeJogos coordena a seleção de jogadores, a execução de partidas
 * e a atualização das estatísticas dos jogadores após cada jogo.
 */
class GerenciadorDeJogos {
private:
    Cadastro& cadastro; ///< Referência ao sistema de cadastro de jogadores.
    Jogador* jogador1;  ///< Ponteiro para o jogador 1.
    Jogador* jogador2;  ///< Ponteiro para o jogador 2.

public:
    /**
     * @brief Construtor da classe GerenciadorDeJogos.
     * 
     * Inicializa o gerenciador com uma referência ao sistema de cadastro.
     * 
     * @param[in] cadastro Referência ao sistema de cadastro de jogadores.
     */
    GerenciadorDeJogos(Cadastro& cadastro);

    /**
     * @brief Seleciona os jogadores para a partida.
     * 
     * Solicita os apelidos dos jogadores e verifica se eles estão cadastrados.
     * 
     * @return true Se ambos os jogadores foram selecionados com sucesso.
     * @return false Se um ou ambos os jogadores não foram encontrados.
     */
    bool selecionarJogadores();

    /**
     * @brief Atualiza as estatísticas dos jogadores após uma partida.
     * 
     * Incrementa o número de vitórias do jogador vencedor e o número de derrotas
     * do jogador perdedor no jogo especificado.
     * 
     * @param[in] vencedorApelido Apelido do jogador vencedor.
     * @param[in] jogo Nome do jogo (ex: "VELHA", "LIG4", "REVERSI").
     */
    void atualizarEstatisticas(const std::string& vencedorApelido, const std::string& jogo);

    /**
     * @brief Executa um jogo com base na opção selecionada.
     * 
     * Cria uma instância do jogo correspondente à opção fornecida e gerencia
     * a execução da partida.
     * 
     * @param[out] jogo Ponteiro para o jogo a ser executado.
     * @param[in] opcao Opção do jogo (1: Jogo da Velha, 2: Connect4, 3: Reversi).
     */
    void executarJogo(Jogo* jogo, const int& opcao);
};

#endif