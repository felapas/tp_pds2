#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../../include/Reversi.hpp"

TEST_CASE("Testando a inicialização do jogo") {
    Reversi reversi;

    SUBCASE("Jogador inicial deve ser 1") {
        CHECK(reversi.getJogadorAtual() == 1);
    }
}

TEST_CASE("Testando a validação de jogadas") {
    Reversi reversi;
    reversi.iniciar();

    SUBCASE("Jogada válida na posição (3, 2) para o jogador 1") {
        CHECK(reversi.validarJogada(3, 2) == true);
    }

    SUBCASE("Jogada inválida na posição (0, 0) para o jogador 1") {
        CHECK(reversi.validarJogada(0, 0) == false);
    }

    SUBCASE("Jogada inválida em uma posição já ocupada") {
        CHECK(reversi.validarJogada(3, 3) == false); // Posição já ocupada por 'O'
    }
}

TEST_CASE("Testando a alternância de jogadores") {
    Reversi reversi;
    reversi.iniciar();

    SUBCASE("Jogador deve alternar após uma jogada válida") {
        reversi.validarJogada(3, 2); // Jogador 1 faz uma jogada
        CHECK(reversi.getJogadorAtual() == 2); // Deve alternar para o jogador 2
    }
}

TEST_CASE("Testando a verificação de vitória") {
    Reversi reversi;
    reversi.iniciar();
    reversi.validarJogada(2, 3);
    reversi.validarJogada(2, 2);
    reversi.validarJogada(2, 1);
    reversi.validarJogada(1, 3);
    reversi.validarJogada(0, 4);
    reversi.validarJogada(5, 3);
    reversi.validarJogada(6, 3);
    reversi.validarJogada(2, 4);
    reversi.validarJogada(3, 5);
    CHECK(reversi.validarVitoria() == 1);


}