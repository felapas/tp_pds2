#include "Cadastro.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


void Cadastro::cadastrarJogador(const std::string& nome, const std::string& apelido) {
    if (_jogadores.find(apelido) != _jogadores.end()) {
        std::cout << "ERRO: jogador repetido" << std::endl;
    }
    else {
        _jogadores[apelido] = Jogador(nome, apelido);
        std::cout << "Jogador " << apelido << " cadastrado com sucesso!" << std::endl;
    }
}

bool Cadastro::removerJogador(const std::string& apelido) {
    if(_jogadores.erase(apelido)) {
        std::cout << "Jogador \"" << apelido << "\" removido com sucesso!\n";
        return true;
    }
    else{
        std::cout << "ERRO: jogador inexistente.\n";
        return false;
    }
}

void Cadastro::listarJogadores() {
    if (_jogadores.empty()) {
        std::cout << "Nenhum jogador cadastrado.\n";
        return;
    }

    std::cout << "Jogadores cadastrados:\n";
    for (const auto& [apelido, jogador] : _jogadores) {
        jogador.mostrarEstatisticas();
        std::cout << std::endl;
    }
}

bool Cadastro::salvarEmArquivo() {
    std::ofstream out(_arquivo, std::fstream::out);
    if (!out.is_open()) {
        std::cout << "ERRO: falha ao abrir o arquivo" << std::endl;
        return false;
    }

    for (const auto& [apelido, jogador] : _jogadores) {
        out << jogador.getNome() << " " << jogador.getApelido() << "\n";

        auto vitorias = jogador.getVitorias();
        auto derrotas = jogador.getDerrotas();

        for (const auto& [jogo, num] : vitorias) {
            out << "V " << jogo << " " << num << "\n";
        }
        for (const auto& [jogo, num] : derrotas) {
            out << "D " << jogo << " " << num << "\n";
        }
        out << "---\n"; 
    }

    out.close();
    return true;
}
bool Cadastro::carregarDeArquivo() {
    std::ifstream in(_arquivo, std::fstream::in);
    if (!in.is_open()) {
        std::cout << "ERRO: falha ao abrir o arquivo" << std::endl;
        return false;
    }
    
    std::string linha;
    while (std::getline(in, linha)) {
        if (linha == "---") continue; 

        std::istringstream ss(linha);
        std::string nome, apelido;
        ss >> nome >> apelido;

        Jogador jogador(nome, apelido);

        while (std::getline(in, linha) && linha != "---") {
            std::istringstream ss(linha);
            char tipo; 
            std::string jogo;
            int num;

            ss >> tipo >> jogo >> num;
            if (tipo == 'V') {
                jogador.setVitorias(jogo, num);
            } else if (tipo == 'D') {
                jogador.setDerrotas(jogo, num);
            }
        }

        _jogadores[apelido] = jogador;
    }

    in.close();
    return true;
}