#ifndef GERENCIADOR_DE_JOGOS_H
#define GERENCIADOR_DE_JOGOS_H

#include "Cadastro.hpp"
#include "Jogador.hpp"
#include "Jogo_Da_Velha.hpp"
#include <string>

class GerenciadorDeJogos {
private:
    Cadastro& cadastro; // Referência ao sistema de cadastro
    Jogador* jogador1;  // Ponteiro para o jogador 1
    Jogador* jogador2;  // Ponteiro para o jogador 2

public:
    GerenciadorDeJogos(Cadastro& cadastro);

    bool selecionarJogadores();
    void executarJogo(JogoDaVelha& jogo);
    void atualizarEstatisticas(const std::string& vencedorApelido, const std::string& jogo);
};

#endif
