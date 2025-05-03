#include "const.h"
#include "utils.h"

void IniciarTablero(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL]) {
	//Funcionament Taulell
	for (int i = 0; i < TAMANY_TAULELL; i++)
	{
		for (int j = 0; j < TAMANY_TAULELL; j++)
		{
			if (j == TAMANY_TAULELL - 2) chessBoard[j][i] = PEON_BLANC;
			else if (j == 1) chessBoard[j][i] = PEON_NEGRE;
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

// Funcio per agafar una peça del taulell
position getPiceByUser(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], bool whiteTurn) {

	position getPiceByUser;
	bool isGettingAPice = true;
	do
	{
		isGettingAPice = true;
		cout << "---------------" << endl;
		cout << "Elige una pieza:" << endl;
		cout << "---------------" << endl;
		cout << "X: ";
		cin >> getPiceByUser.x;
		cout << "Y: ";
		cin >> getPiceByUser.y;

		getPiceByUser.x--;
		getPiceByUser.y--;

		getPiceByUser.y = TAMANY_TAULELL - getPiceByUser.y - 1;

		if (getPiceByUser.x < 0 || getPiceByUser.x > TAMANY_TAULELL - 1 || getPiceByUser.y < 1 || getPiceByUser.y > TAMANY_TAULELL - 1)
		{
			cout << "INPUT INVALID!!!! Fora dels limits" << endl;
			isGettingAPice = false;

		}
		else if (chessBoard[getPiceByUser.x][getPiceByUser.y] == ESPAI)
		{
			cout << "INPUT INVALID!!!! No hi ha cap pesa" << endl;
			isGettingAPice = false;
		}
		else if ((whiteTurn && chessBoard[getPiceByUser.x][getPiceByUser.y] >= 'a' && chessBoard[getPiceByUser.x][getPiceByUser.y] >= 'z') || (whiteTurn && chessBoard[getPiceByUser.x][getPiceByUser.y] >= 'A' && chessBoard[getPiceByUser.x][getPiceByUser.y] >= 'Z'))
		{
			cout << "INPUT INVALID!!!! no pots agafar una pesa del rival" << endl;
			isGettingAPice = false;
		}

	} while (getPiceByUser.x < 1 || getPiceByUser.x > TAMANY_TAULELL || getPiceByUser.y < 1 || getPiceByUser.y > TAMANY_TAULELL);

	return getPiceByUser;
}



// Funcio per posar una peça al taulell
position PutPiceByUser(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], bool whiteTurn) {

	position PutPiceByUser;
	bool isPuttingAPice = true;
	do
	{
		isPutingAPice = true;
		cout << "---------------" << endl;
		cout << "Elige una pieza:" << endl;
		cout << "---------------" << endl;
		cout << "X: ";
		cin >> PutPiceByUser.x;
		cout << "Y: ";
		cin >> PutPiceByUser.y;

		PutPiceByUser.x--;
		PutPiceByUser.y--;

		PutPiceByUser.y = TAMANY_TAULELL - PutPiceByUser.y - 1;

		if (PutPiceByUser.x < 0 || PutPiceByUser.x > TAMANY_TAULELL - 1 || PutPiceByUser.y < 1 || PutPiceByUser.y > TAMANY_TAULELL - 1)
		{
			cout << "INPUT INVALID!!!! Fora dels limits" << endl;
			isPuttingAPice = false;

		}
		else if (chessBoard[PutPiceByUser.x][PutPiceByUser.y] == ESPAI)
		{
			cout << "INPUT INVALID!!!! No hi ha cap pesa" << endl;
			isPuttingAPice = false;
		}
		else if ((whiteTurn && chessBoard[PutPiceByUser.x][PutPiceByUser.y] >= 'a' && chessBoard[PutPiceByUser.x][PutPiceByUser.y] >= 'z') || (whiteTurn && chessBoard[PutPiceByUser.x][getPiceByUser.y] >= 'A' && chessBoard[getPiceByUser.x][getPiceByUser.y] >= 'Z'))
		{
			cout << "INPUT INVALID!!!! no pots agafar una pesa del rival" << endl;
			isPuttingAPice = false;
		}

	} while (PutPiceByUser.x < 1 || PutPiceByUser.x > TAMANY_TAULELL || PutPiceByUser.y < 1 || PutPiceByUser.y > TAMANY_TAULELL);

	return PuticeByUser;
}