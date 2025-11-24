#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include "CorridaCarroPacoteHeader.h"

class Rede
{
private:
	Pacote* pacote;

public:
	Rede();
	~Rede();

	static void transmitirDadosParaRede(unsigned short passo, unsigned short cor, unsigned short posicao, unsigned short velocidade, unsigned short pista);
	static unsigned int printarInformacoesNoTerminal();
	static unsigned int gerarNovaPosicao(unsigned int dados);
	static void printEstadoPista(int);
	static void printDadosRede(string, unsigned short (*function)(unsigned int), int);
};

#endif
