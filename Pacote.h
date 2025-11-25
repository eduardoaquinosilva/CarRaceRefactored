#ifndef PACKAGE_H
#define PACKAGE_H

class Pacote
{
public:
	static unsigned int empacotarParaRede(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);	
	static unsigned short passo(unsigned int);
	static unsigned short cor(unsigned int);
	static unsigned short posicao(unsigned int);
	static unsigned short velocidade(unsigned int);
	static unsigned short pista(unsigned int);
};

inline unsigned short Pacote::passo(unsigned int passo) { return (passo >> 24); }

inline unsigned short Pacote::cor(unsigned int cor) { unsigned int corBitwise = cor >> 16; return (corBitwise & 0xFF); }

inline unsigned short Pacote::posicao(unsigned int posicao) { unsigned int posicaoBitwise = posicao >> 9; return (posicaoBitwise & 0xFF); }

inline unsigned short Pacote::velocidade(unsigned int velocidade) { unsigned int velocidadeBitwise = velocidade >> 5; return (velocidadeBitwise & 0xF); }

inline unsigned short Pacote::pista(unsigned int pista) { unsigned int pistaBitwise = pista >> 4; return (pistaBitwise & 1); }

#endif
