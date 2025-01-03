#include "Cadastro.hpp"
#include <iostream>
#include <fstream>

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

bool Cadastro::salvarEmArquivo(){
    std::ofstream out(_arquivo, std::fstream::out);
    if (!out.is_open()) {
        std::cout << "ERRO: falha ao abrir o arquivo" << std::endl;
        return false;
    }

    for (auto it = _jogadores.begin(); it != _jogadores.end(); it++) {
        out << it->second.getNome() << " " << it->second.getApelido() << " ";
        
        auto vitorias = it->second.getVitorias();
        auto derrotas = it->second.getDerrotas();

        for (auto it_vitorias = vitorias.begin(); it_vitorias != vitorias.end(); it_vitorias++) {
            out << it_vitorias->first << " " << it_vitorias->second << " ";
        }
        for (auto it_derrotas = derrotas.begin(); it_derrotas != derrotas.end(); it_derrotas++) {
            out << it_derrotas->first << " " << it_derrotas->second << " ";
        }
    }

    out.close();
}
bool Cadastro::carregarDeArquivo(){
    std::ifstream in(_arquivo, std::fstream::in);
    if (!in.is_open()) {
        std::cout << "ERRO: falha ao abrir o arquivo" << std::endl;
        return false;
    }
    
    std::string entrada;
    while (in >> entrada) {
        std::string nome, apelido;
        in >> nome >> apelido;
        Jogador jogador(nome,apelido);

        for (int i = 0; i < 3; i++) {
            std::string jogo;
            int n_vitorias;
            in >> jogo >> n_vitorias;
            jogador.setVitorias(jogo, n_vitorias);
        }
        for (int i = 0; i < 3; i++) {
            std::string jogo;
            int n_derrotas;
            in >> jogo >> n_derrotas;
            jogador.setVitorias(jogo, n_derrotas);
        }

        _jogadores.insert({apelido,jogador});
    }

    in.close();
}
