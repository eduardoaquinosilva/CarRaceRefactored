#ifndef CARRO_H
#define CARRO_H

#include <iostream>
#include "Cor.h"

class Carro
{
private:
	unsigned short posicao;
	unsigned short velocidade;
	unsigned short cor;
	unsigned short derrapa;
	float velocidadeMedia;
public:
	Carro(unsigned short, unsigned short, unsigned short, unsigned short);

	void desenharCarro();

	void espacos(int);

	void atualizaVelocidade();
	void atualizaDerrapagem();

	unsigned short Posicao();
	unsigned short Velocidade();
	unsigned short Cor();
	unsigned short Derrapa();

	void Posicao(unsigned short);
	void atualizaVelocidadeMedia(int);

	void printCarInfo(int, int = PRETO);
};

inline void Carro::espacos(int quantidadeEspaco) { while (quantidadeEspaco-- > 0) std::cout << ' '; }

inline void Carro::atualizaVelocidade() { this->velocidade = (rand() % 10 + 1); }

inline void Carro::atualizaDerrapagem() { this->derrapa = (rand() % 2); }

inline void Carro::atualizaVelocidadeMedia(int passo) { this->velocidadeMedia = float(this->posicao) / float(passo); }

inline unsigned short Carro::Posicao() { return this->posicao; }

inline unsigned short Carro::Velocidade() { return this->velocidade; }

inline unsigned short Carro::Cor() { return this->cor; }

inline unsigned short Carro::Derrapa() { return this->derrapa; }

inline void Carro::Posicao(unsigned short posicao) { this->posicao = posicao; }

#endif
