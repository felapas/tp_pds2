#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Cadastro.hpp"
#include <fstream> // Para verificar se o arquivo existe

TEST_CASE("Teste do Sistema de Cadastro") {
    Cadastro sistema;
    sistema.getJogadores().clear();

    SUBCASE("Persistência em arquivo") {
        sistema.cadastrarJogador("Legolas", "elf");
        sistema.salvarEmArquivo();

        // Verifica se o arquivo foi criado (C++11)
        std::ifstream arquivo(sistema.getArquivo());
        CHECK(arquivo.is_open()); // Verifica se o arquivo existe e está aberto

        // Teste de carregamento
        Cadastro sistema2;
        sistema2.carregarDeArquivo();
        CHECK(sistema2.getJogadores().size() == 1);
    }
}