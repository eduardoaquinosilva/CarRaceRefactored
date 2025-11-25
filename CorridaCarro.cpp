#include <iostream>
#include "Cor.h"
#include "Rede.h"
#include "Carro.h"
using namespace std;

void mostrarPassos(int, int = PRETO, int = AMARELO, int = VERDE);

int main() {
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout.precision(2);
	srand(unsigned(time(NULL)));

	Carro* carro1 = new Carro(0, 0, VERDE, 0);
	Carro* carro2 = new Carro(0, 0, AZUL, 0);

	int passo = 0;

	do {
		system("cls");
		carro1->desenharCarro();
		carro2->desenharCarro();
	
		carro1->atualizaVelocidade();
		carro1->atualizaDerrapagem();

		carro2->atualizaVelocidade();
		carro2->atualizaDerrapagem();
	
		Rede::transmitirDadosParaRede(passo, carro1);
		carro1->Posicao(Rede::gerarNovaPosicao(Rede::printarInformacoesNoTerminal()));

		Rede::transmitirDadosParaRede(passo, carro2);
		carro2->Posicao(Rede::gerarNovaPosicao(Rede::printarInformacoesNoTerminal()));

		system("pause > NULL");
	
		passo = passo + 1;
	} while (carro1->Posicao() <= 100 && carro2->Posicao() <= 100);
	
	carro1->atualizaVelocidadeMedia(passo);
	carro2->atualizaVelocidadeMedia(passo);

	system("cls");

	carro1->desenharCarro();
	carro2->desenharCarro();

	mostrarPassos(passo);

	carro1->printCarInfo(VERDE);
	carro2->printCarInfo(AZUL);
	
	delete carro1;
	delete carro2;
}

void mostrarPassos(int passo, int corPrimeira, int corSecundaria, int corTerciaria) {
	ajustarCor(corPrimeira, corSecundaria);
	cout << " Passos  ";
	resetCor();
	ajustarCor(corSecundaria, corPrimeira);
	cout << " "; cout.width(3); cout << passo << " " << endl;
	ajustarCor(corPrimeira, corTerciaria);
}
