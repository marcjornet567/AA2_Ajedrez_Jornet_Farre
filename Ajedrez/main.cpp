#include "const.h"
#include "taulell.h"
#include "utils.h"


int main() {
	//Creacio de Taulell
	char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL];
	bool gameOver = false;
	bool isWhiteTrue = true;
	IniciarTablero(chessBoard);

	do
	{
		PrinteoTablero(chessBoard);

		position userGetPice, setPiceByUser;

		userGetPice = getPiceByUser();


		system("cls");
	} while (gameOver);

	
	
}