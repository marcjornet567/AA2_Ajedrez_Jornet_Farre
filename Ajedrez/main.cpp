#include "const.h"

int main() {
	//Creacio de Taulell
	char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL];
	bool gameOver = false;
	bool isWhiteTrue = true;
	IniciarTablero(chessBoard);

	do
	{
		PrinteoTablero(chessBoard);

		position userGetPice, setPiceByUser; //set pice va despres

		userGetPice = getPiceByUser(chessBoard, isWhiteTrue);

		isWhiteTrue = !isWhiteTrue;

		system("cls");
	} while (gameOver);

	
	
}