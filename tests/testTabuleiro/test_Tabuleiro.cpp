#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "../../include/Tabuleiro.hpp"

TEST_CASE("Teste do Tabuleiro"){
    SUBCASE("Inicialização do Tabuleiro"){
        Tabuleiro tabuleiro(4,3);   //Inicialização com parâmetros válidos
        CHECK(tabuleiro.getLinhas() == 4);
        CHECK(tabuleiro.getColunas() == 3);

        CHECK_THROWS_AS(Tabuleiro(-9, -4), std::invalid_argument);
        CHECK_THROWS_AS(Tabuleiro(0, 0), std::invalid_argument);
    }
    SUBCASE("Posições do tabuleiro"){
        Tabuleiro tabuleiro(4,3);
        tabuleiro.setPosicao(1,1,'X');
        CHECK(tabuleiro.getPosicao(1, 1) == 'X');
        CHECK_FALSE(tabuleiro.posicaoValida(8,9));

    }
}