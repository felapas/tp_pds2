#ifndef CADASTRO_H
#define CADASTRO_H

#include "Jogador.hpp"
#include <iostream>
#include <map>

/**
 * @file Cadastro.hpp
 * @brief Sistema de gerenciamento de cadastro de jogadores.
 * 
 * Esta classe é responsável por gerenciar o cadastro de jogadores, incluindo:
 * - Cadastro e remoção de jogadores.
 * - Listagem de jogadores cadastrados.
 * - Persistência dos dados em arquivo.
 */

/**
 * @class Cadastro
 * @brief Gerencia o cadastro de jogadores e suas operações.
 * 
 * A classe Cadastro armazena os jogadores em um mapa, onde a chave é o apelido
 * do jogador e o valor é um objeto da classe Jogador. Além disso, fornece métodos
 * para salvar e carregar os dados de jogadores em um arquivo.
 */
class Cadastro {
private:
    std::map<std::string, Jogador> _jogadores; ///< Mapa de jogadores, indexado por apelido.
    std::string _arquivo = "../gamedata/logs_jogadores.txt"; ///< Caminho do arquivo de persistência.

public:
    /**
     * @brief Cadastra um novo jogador no sistema.
     * 
     * Verifica se o apelido já existe no mapa de jogadores. Se não existir, cria um novo jogador
     * e o adiciona ao mapa. Caso contrário, exibe uma mensagem de erro.
     * 
     * @param[in] nome Nome completo do jogador.
     * @param[in] apelido Apelido único do jogador.
     * 
     * @throw std::invalid_argument Se o apelido já estiver em uso.
     * 
     */
    void cadastrarJogador(const std::string& nome, const std::string& apelido);

    /**
     * @brief Remove um jogador do sistema.
     * 
     * Verifica se o jogador com o apelido fornecido existe no mapa. Se existir, remove o jogador
     * e retorna true. Caso contrário, exibe uma mensagem de erro e retorna false.
     * 
     * @param[in] apelido Apelido do jogador a ser removido.
     * @return true Se o jogador foi removido com sucesso.
     * @return false Se o jogador não foi encontrado.
     */
    bool removerJogador(const std::string& apelido);

    /**
     * @brief Lista todos os jogadores cadastrados.
     * 
     * Verifica se há jogadores no mapa. Se houver, exibe as estatísticas de cada jogador.
     * Caso contrário, exibe uma mensagem informando que não há jogadores cadastrados.
     * 
     */
    void listarJogadores();

    /**
     * @brief Retorna o caminho do arquivo de persistência.
     * 
     * @return Caminho do arquivo onde os dados dos jogadores são salvos.
     */
    std::string getArquivo() const { return _arquivo; }

    /**
     * @brief Retorna o mapa de jogadores cadastrados.
     * 
     * @return Referência para o mapa de jogadores, onde a chave é o apelido e o valor é o objeto Jogador.
     */
    std::map<std::string, Jogador>& getJogadores();

    /**
     * @brief Salva os dados dos jogadores em um arquivo.
     * 
     * Abre o arquivo especificado em `_arquivo` e salva os dados de todos os jogadores,
     * incluindo nome, apelido, vitórias e derrotas. Se o arquivo não puder ser aberto,
     * exibe uma mensagem de erro e retorna false.
     * 
     * @return true Se os dados foram salvos com sucesso.
     * @return false Se houve falha ao abrir o arquivo.
     * 
     */
    bool salvarEmArquivo();

    /**
     * @brief Carrega os dados dos jogadores de um arquivo.
     * 
     * Abre o arquivo especificado em `_arquivo` e carrega os dados dos jogadores,
     * incluindo nome, apelido, vitórias e derrotas. Se o arquivo não puder ser aberto,
     * exibe uma mensagem de erro e retorna false.
     * 
     * @return true Se os dados foram carregados com sucesso.
     * @return false Se houve falha ao abrir o arquivo.
     * 
     */
    bool carregarDeArquivo();
    void setArquivo(const std::string arquivo);
};

#endif