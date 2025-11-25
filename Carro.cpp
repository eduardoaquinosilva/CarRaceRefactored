#include <iostream>
#include "Carro.h"
#include "Cor.h"
using namespace std;

Carro::Carro(unsigned short posicao, unsigned short velocidade, unsigned short cor, unsigned short derrapa) {
	this->posicao = posicao;
	this->velocidade = velocidade;
	this->cor = cor;
	this->derrapa = derrapa;
	this->velocidadeMedia = 0;
}

void Carro::desenharCarro() {
	ajustarCor(cor, PRETO);
	cout << "\n\n\n";
	espacos(posicao); cout << "\xDB\xDC\xDB\xDB\xDB\xDB\xDB\xDC\n";
	espacos(posicao); cout << "\xDFO\xDF\xDF\xDF\xDFO\xDF\xDF\n";
	cout << "---------------------------------------------------------------------------------------------------|--------------------";
	cout.width(101); cout << "100" << endl; resetCor();
}

void Carro::printCarInfo(int corPrincipal, int corSecundaria) {
	cout << " Posição ";
	resetCor();
	ajustarCor(corPrincipal, corSecundaria);
	cout << " "; cout.width(3); cout << this->posicao << " ";
	resetCor();
	ajustarCor(corSecundaria, corPrincipal);
	cout << " Velocidade média ";
	resetCor();
	ajustarCor(corPrincipal, corSecundaria);
	cout << " " << this->velocidadeMedia << " " << endl;
	resetCor();
}
