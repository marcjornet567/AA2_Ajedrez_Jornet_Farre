#include "const.h"

void IniciarTablero(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL]) {
	//Funcionament Taulell
	for (int i = 0; i < TAMANY_TAULELL; i++)
	{
		for (int j = 0; j < TAMANY_TAULELL; j++)
		{
			if (j == TAMANY_TAULELL - 2) chessBoard[j][i] = PEON_NEGRE;
			else if (j == 1) chessBoard[j][i] = PEON_BLANC;
			else chessBoard[j][i] = ESPAI;
		}
	}

	const short torreXPosL = 0;
	const short torreXPosR = TAMANY_TAULELL - 1;
	const short caballXPosL = 1;
	const short caballXPosR = TAMANY_TAULELL - 2;
	const short alfilXPosL = 2;
	const short alfilXPosR = TAMANY_TAULELL - 3;
	
	const short reiBlancXPos = 3;
	const short reinaBlanca = TAMANY_TAULELL - 4;
	const short reiNegra = TAMANY_TAULELL - 4;
	const short reinaNegra = 3;

	//print de peces negres
	chessBoard[0][torreXPosL] = TORRE_NEGRE;
	chessBoard[0][torreXPosR] = TORRE_NEGRE;
	chessBoard[0][caballXPosL] = CABALL_NEGRE;
	chessBoard[0][caballXPosR] = CABALL_NEGRE;
	chessBoard[0][alfilXPosL] = ALFIL_NEGRE;
	chessBoard[0][alfilXPosR] = ALFIL_NEGRE;
	chessBoard[0][reiNegra] = REI_NEGRE;
	chessBoard[0][reinaNegra] = REINA_NEGRE;

	//print de peces blanques
	chessBoard[TAMANY_TAULELL - 1][torreXPosL] = TORRE_BLANC;
	chessBoard[TAMANY_TAULELL - 1][torreXPosR] = TORRE_BLANC;
	chessBoard[TAMANY_TAULELL - 1][caballXPosL] = CABALL_BLANC;
	chessBoard[TAMANY_TAULELL - 1][caballXPosR] = CABALL_BLANC;
	chessBoard[TAMANY_TAULELL - 1][alfilXPosL] = ALFIL_BLANC;
	chessBoard[TAMANY_TAULELL - 1][alfilXPosR] = ALFIL_BLANC;
	chessBoard[TAMANY_TAULELL - 1][reiNegra] = REI_BLANC;
	chessBoard[TAMANY_TAULELL - 1][reinaNegra] = REINA_BLANC;

}

void PrinteoTablero(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL]) {
	cout << ' ' << ' ';

	for (int i = 0; i < TAMANY_TAULELL; i++)
	{
		cout << i + 1 << ' ';
	}
	cout << endl;

	for (int i = 0; i < TAMANY_TAULELL; i++)
	{
		cout << TAMANY_TAULELL - i << ' ';

		for (int j = 0; j < TAMANY_TAULELL; j++)
		{
			cout << chessBoard[i][j] << ' ';
		}
		cout << endl;
	}
}