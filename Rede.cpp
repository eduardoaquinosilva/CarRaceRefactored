#include <iostream>
#include <string>
#include "Pacote.h"
#include "Cor.h"
#include "Rede.h"
#include "Carro.h"
using namespace std;

unsigned int Rede::redeEmBits = 0;

void Rede::transmitirDadosParaRede(unsigned short passo, Carro* carro, int corSecundaria) {
	redeEmBits = Pacote::empacotarParaRede(passo, carro->Cor(), carro->Posicao(), carro->Velocidade(), carro->Derrapa());

	cout << "Transmitindo dados..." << endl;
	ajustarCor(corSecundaria, carro->Cor());
	cout << redeEmBits;
	resetCor();
}

unsigned int Rede::printarInformacoesNoTerminal() {
	cout << "\nRecebendo dados..." << endl;

	printDadosRede(string("Frame: "), &Pacote::passo);

	printDadosRede(string("Pos: "), &Pacote::posicao);

	printDadosRede(string("Vel: "), &Pacote::velocidade);

	printEstadoPista();

	return redeEmBits;
}

unsigned int Rede::gerarNovaPosicao(unsigned int dados) {
	unsigned short posicaoAtual = Pacote::posicao(dados);
	unsigned short velo = Pacote::velocidade(dados);
	unsigned short oleo = Pacote::pista(dados);
	unsigned short novaPosicao = posicaoAtual + (velo - oleo);
	
	cout << "Processando dados..." << endl;
	ajustarCor(Pacote::cor(dados), PRETO);
	cout << "Próxima posição: " << novaPosicao << "\n\n";
	resetCor();
	return novaPosicao;
}

void Rede::printEstadoPista(int corSecundaria) {
	ajustarCor(Pacote::cor(redeEmBits), corSecundaria);
	cout << " Oil: ";
	resetCor();
	ajustarCor(corSecundaria, Pacote::cor(redeEmBits));
	
	if (Pacote::pista(redeEmBits) == 1) {
		cout << " " << "true" << " " << endl;
	} else {
		cout << " " << "false" << " " << endl;
	}
	
	resetCor();
}

void Rede::printDadosRede(string text, unsigned short (*function)(unsigned int), int corSecundaria) {
	ajustarCor(Pacote::cor(redeEmBits), corSecundaria);
	cout << text;
	resetCor();
	
	ajustarCor(corSecundaria, Pacote::cor(redeEmBits));
	cout << " " << function(redeEmBits) << " ";
	resetCor();
}
