#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include "Pacote.h"
#include "Carro.h"

class Rede
{
public:
	static unsigned int redeEmBits;

	static void transmitirDadosParaRede(unsigned short, Carro*, int = PRETO);
	static unsigned int printarInformacoesNoTerminal();
	static unsigned int gerarNovaPosicao(unsigned int dados);
	static void printEstadoPista(int = PRETO);
	static void printDadosRede(std::string, unsigned short (*function)(unsigned int), int = PRETO);
};

#endif
