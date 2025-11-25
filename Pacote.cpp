#include <iostream>
#include "Pacote.h"

unsigned int Pacote::empacotarParaRede(unsigned short passo, unsigned short cor, unsigned short posicao, unsigned short velocidade, unsigned short pista) {
	unsigned int pacote = 0;
	pacote = passo;
	pacote = pacote << (8);
	pacote = (pacote | cor);
	pacote = pacote << (7);
	pacote = (pacote | posicao);
	pacote = pacote << (4);
	pacote = (pacote | velocidade);
	pacote = pacote << (1);
	pacote = (pacote | pista);
	pacote = pacote << (4);
	return pacote;
}
