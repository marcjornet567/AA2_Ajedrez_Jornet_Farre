#include "const.h"

void IniciarTablero(char chessBoard[][]) {
	//Funcionament Taulell
	for (int i = 0; i < ; i++)
	{
		for (int j = 0; j < ; j++)
		{
			chessBoard[i][j] = '*';
		}
	}
}

void PrinteoTablero(char chessBoard[][]){
	cout << '  ';
	for (int i = 0; i < ; i++)
	{
		cout << i+1 << ' ';
	}
	cout << endl;
	for (int i = 0; i < ; i++)
	{
		cout << 8-i << ' ';
		for (int j = 0; j < ; j++)
		{
			cout << chessBoard[i][j] = '*';
		}
		cout << endl;
	}
}

int main() {
	//Creacio de Taulell
	char chessBoard[][];
	iniciarTablero(chessBoard);
	PrinteoTablero(chessBoard);
}