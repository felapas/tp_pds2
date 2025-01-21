#ifndef GERENCIADOR_DE_JOGOS_H
#define GERENCIADOR_DE_JOGOS_H

#include "Cadastro.hpp"
#include "Jogador.hpp"
#include "Jogo_Da_Velha.hpp"
#include "Connect4.hpp"
#include "Reversi.hpp"
#include <string>

class GerenciadorDeJogos {
private:
    Cadastro& cadastro; // Referência ao sistema de cadastro
    Jogador* jogador1;  // Ponteiro para o jogador 1
    Jogador* jogador2;  // Ponteiro para o jogador 2

public:
    GerenciadorDeJogos(Cadastro& cadastro);

    bool selecionarJogadores();
    void atualizarEstatisticas(const std::string& vencedorApelido, const std::string& jogo);
    void executarJogo(Jogo* jogo, const int& opcao);
};

#endif
