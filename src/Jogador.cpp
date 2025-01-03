#include "Jogador.hpp"
#include <iostream>


Jogador::Jogador(const std::string& nome, const std::string& apelido) 
: _nome(nome), _apelido(apelido) {
    _vitorias = 0;
    _derrotas = 0;
}

std::string Jogador::getNome() const {
    return _nome;
}

std::string Jogador::getApelido() const {
    return _apelido;
}

void Jogador::adicionarVitoria(const std::string& jogo) {
    _vitorias++;
}
void Jogador::adicionarDerrota(const std::string& jogo) {
    _derrotas++;
}
void Jogador::mostrarEstatisticas() const {
    std::cout << this->_nome << " " << this->_apelido << " ";
    std::cout << this->_vitorias << this->_derrotas << " ";
} 