#ifndef REVERSI_H
#define REVERSI_H

#include <iostream>
#include "Jogo.hpp"

class Reversi : public Jogo {
private:
   int jogadorAtual;
   bool podeCapturar(int linha, int coluna, int deltaLinha, int deltaColuna) const;
   void capturarPecas(int linha, int coluna, int deltaLinha, int deltaColuna);

public:
  Reversi();

  void iniciar() override;
  void lerJogada(int& linha, int& coluna) override;
  void alternarJogador();
  bool validarJogada(int linha) override;
  bool validarJogada(int linha, int coluna) override;
  bool validarVitoria() override;
  int getJogadorAtual() override;
};

#endif
