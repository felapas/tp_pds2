#include "Jogador.hpp"
#include <iostream>

Jogador::Jogador(const std::string& nome, const std::string& apelido) 
: _nome(nome), _apelido(apelido) {
    _vitorias["REVERSI"] = 0;
    _vitorias["LIG4"] = 0;
    _vitorias["VELHA"] = 0;
    _derrotas["REVERSI"] = 0;
    _derrotas["LIG4"] = 0;
    _derrotas["VELHA"] = 0;
}

std::string Jogador::getNome() const {
    return _nome;
}

std::string Jogador::getApelido() const {
    return _apelido;
}

std::map<std::string,int> Jogador::getVitorias() const {
    return _vitorias;
}

std::map<std::string,int> Jogador::getDerrotas() const {
    return _derrotas;
}

void Jogador::adicionarVitoria(const std::string& jogo) {
    _vitorias[jogo]++;
}

void Jogador::adicionarDerrota(const std::string& jogo) {
    _derrotas[jogo]++;
}

void Jogador::setVitorias(std::string jogo, int numVitorias){
    _vitorias.insert({jogo ,numVitorias});
}

void Jogador::setDerrotas(std::string jogo, int numDerrotas) {
    _derrotas[jogo] = numDerrotas;
}

void Jogador::mostrarEstatisticas() const {
    std::cout << "Apelido: " << _apelido << " | Nome: " << _nome << std::endl;

    for (std::map<std::string, int>::const_iterator it = _vitorias.begin(); it != _vitorias.end(); ++it) {
        const std::string& jogo = it->first;
        int vitorias = it->second;
        int derrotas = _derrotas.count(jogo) ? _derrotas.at(jogo) : 0;
        std::cout << jogo << " - V: " << vitorias << " D: " << derrotas << std::endl;
    }
}
