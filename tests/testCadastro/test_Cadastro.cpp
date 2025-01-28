#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Cadastro.hpp"
#include <fstream>
#include <sstream>

TEST_CASE("Teste do Sistema de Cadastro") {
    Cadastro sistema;

    // 1. Salva o estado original do arquivo
    std::ifstream arquivoOriginal(sistema.getArquivo());
    std::stringstream bufferOriginal;
    if (arquivoOriginal.is_open()) {
        bufferOriginal << arquivoOriginal.rdbuf(); // Lê todo o conteúdo do arquivo
        arquivoOriginal.close();
    }

    SUBCASE("Persistência em arquivo") {
        // 2. Executa o teste
        sistema.cadastrarJogador("Jhonantan", "jhon");
        sistema.salvarEmArquivo();

        // Verifica se o arquivo foi criado
        std::ifstream arquivo(sistema.getArquivo());
        CHECK(arquivo.is_open()); // Garante que o arquivo existe

        // Teste de carregamento
        Cadastro sistema2;
        sistema2.carregarDeArquivo();
        CHECK(sistema2.getJogadores().size() == 1);
    }

    // 3. Restaura o estado original do arquivo
    std::ofstream arquivoRestaurado(sistema.getArquivo());
    if (arquivoRestaurado.is_open()) {
        arquivoRestaurado << bufferOriginal.rdbuf(); // Escreve o conteúdo original de volta
        arquivoRestaurado.close();
    }
}
