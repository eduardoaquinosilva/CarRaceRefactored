#include <iostream>
#include "CorridaCarroCorHeader.h"
#include "CorridaCarroRedeHeader.h"
using namespace std;

//Para Desenhar
void desenhar(unsigned short, unsigned short);
void espacos(int);
void printCarInfo(int, int, int, int);

int main() {
	// --------------------
	// Inicializando dados:
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout.precision(2);
	srand(unsigned(time(NULL)));

	unsigned short pos1 = 0;
	unsigned short pos2 = 0;

	unsigned short velo1 = 0;
	unsigned short velo2 = 0;
	
	unsigned short cor1 = VERDE;
	unsigned short cor2 = AZUL;
	
	unsigned short estPis1 = 0;
	unsigned short estPis2 = 0;

	int passo = 0;
	// --------------------

	do
	{

	// ------------------------
	// Limpando sistema anterior e desenhando carros nas posições atuais
	system("cls");
	desenhar(pos1, VERDE);
	desenhar(pos2, AZUL);
	// ------------------------
	
	// ------------------------
	// Gerando nova Velocidade e valor para óleo
	velo1 = (rand() % 10 + 1);
	velo2 = (rand() % 10 + 1);

	estPis1 = (rand() % 2);
	estPis2 = (rand() % 2);
	// ------------------------

			
	// ----------------------------------
	// Dados na tela e Calcula Próxima posição
	Rede::Rede::transmitirDadosParaRede(passo,cor1,pos1,velo1,estPis1);
	pos1 = Rede::gerarNovaPosicao(Rede::printarInformacoesNoTerminal());

	Rede::transmitirDadosParaRede(passo,cor2,pos2,velo2,estPis2);
	pos2 = Rede::gerarNovaPosicao(Rede::printarInformacoesNoTerminal());
	// ----------------------------------


	// Aguarda pressionamento de tecla
	system("pause > NULL");
	// -------------------------------

	passo = passo + 1;
	} while (pos1 <= 100 && pos2 <= 100);
	// --------------------
	//Inicializando Velocidades Média
	float velocidadeMedia1 = float(pos1) / float(passo);
	float velocidadeMedia2 = float(pos2) / float(passo);

	// --------------------
	// Tela FINAL
	system("cls");
	//Passos
	desenhar(pos1, VERDE);
	desenhar(pos2, AZUL);
	ajustarCor(PRETO, AMARELO);
	cout << " Passos  ";
	resetCor();
	ajustarCor(AMARELO, PRETO);
	cout << " "; cout.width(3); cout << passo << " " << endl;
	ajustarCor(PRETO, VERDE);

	//Posição e velocidade média do 1° carro
	printCarInfo(VERDE, pos1, velocidadeMedia1);

	//Posição e velocidade média do 2° carro
	printCarInfo(AZUL, pos2, velocidadeMedia2);
	// --------------------
}

//Função para desenhar os carros e a pista.
void desenhar(unsigned short posicao, unsigned short cor) {
	ajustarCor(cor, PRETO);
	cout << "\n\n\n";
	espacos(posicao); cout << "\xDB\xDC\xDB\xDB\xDB\xDB\xDB\xDC\n";
	espacos(posicao); cout << "\xDFO\xDF\xDF\xDF\xDFO\xDF\xDF\n";
	cout << "---------------------------------------------------------------------------------------------------|--------------------";
	cout.width(101); cout << "100" << endl; resetCor();
}

//Função para fazer os carros andarem.
void espacos(int qtd) { 
	while (qtd-- > 0) cout << ' '; 
}

void printCarInfo(int corPrincipal, int pos, int velocidadeMedia, int corSecundaria = PRETO) {
	cout << " Posição ";
	resetCor();
	ajustarCor(corPrincipal, corSecundaria);
	cout << " "; cout.width(3); cout << pos << " ";
	resetCor();
	ajustarCor(corSecundaria, corPrincipal);
	cout << " Velocidade média ";
	resetCor();
	ajustarCor(corPrincipal, corSecundaria);
	cout << " " << velocidadeMedia << " " << endl;
	resetCor();
}
