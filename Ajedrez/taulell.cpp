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