#include "const.h"
#include "utils.h"

void IniciarTablero(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL]) {
	//Funcionament Taulell
	for (int i = 0; i < TAMANY_TAULELL; i++)
{
	for (int j = 0; j < TAMANY_TAULELL; j++)
	{
		//Comprovacion de las filas i = 6 y i = 1, para imprimir los peones
		if (i == TAMANY_TAULELL - 2) chessBoard[i][j] = PEON_BLANC;
		else if (i == 1) chessBoard[i][j] = PEON_NEGRE;
		else chessBoard[i][j] = ESPAI;
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
// Funcion para printear el tablero de forma del 1 al 8, horizontalmente y del 8 al 1 verticalmente
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

// Funcion para seleccionar una pieza
position getPiceByUser(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], bool whiteTurn) {
    position selectedPiecePosition;
    bool isGettingAPiece = false; 

    do {
        isGettingAPiece = true;
        cout << "-------------------------------------" << endl;
        cout << "Elige una pieza para mover:" << endl;
        cout << "-------------------------------------" << endl;
        cout << "(1-" << TAMANY_TAULELL << "): ";
        int inputY;
        cin >> inputY;
        cout << "(1-" << TAMANY_TAULELL << "): ";
        int inputX;
        cin >> inputX;

		// Convertir la entrada del usuario a la posición del tablero
        selectedPiecePosition.x = TAMANY_TAULELL - inputX; // Al estar invertida, del 8(arriba) al 1(abajo), se tiene que restarle para hacer la diferencia. 
        selectedPiecePosition.y = inputY - 1; // Para que el usuario pueda obviar el 0.

        //Comprovaciones para un input valido
        //Comprovacion de input fuera de tablero
        if (selectedPiecePosition.x < 0 || selectedPiecePosition.x >= TAMANY_TAULELL ||
            selectedPiecePosition.y < 0 || selectedPiecePosition.y >= TAMANY_TAULELL) {
            cout << "INPUT INVALIDO!!!! Fuera de limites" << endl;
            isGettingAPiece = false;
            continue;
        }
		//Comprovacion de que la pieza seleccionada no es un espacio vacio
        char piezaSeleccionada = chessBoard[selectedPiecePosition.x][selectedPiecePosition.y];
        if (piezaSeleccionada == ESPAI) {
            cout << "INPUT INVALIDO!!!! No hay ninguna pieza en esta posicion" << endl;
            isGettingAPiece = false;
            continue;
        }
        // Verificar que la pieza corresponde al jugador de tu equipo
        if (whiteTurn && islower(piezaSeleccionada)) {
            cout << "INPUT INVALIDO!!!! No puedes escoger una pieza del rival" << endl;
            isGettingAPiece = false;
            continue;
        }
        if (!whiteTurn && isupper(piezaSeleccionada)) {
            cout << "INPUT INVALIDO!!!! No puedes escoger una pieza del rival" << endl;
            isGettingAPiece = false;
            continue;
        }

    } while (!isGettingAPiece);

    return selectedPiecePosition;
}

// Función para seleccionar la posición donde se quiere poner la pieza
position PutPiceByUser(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], bool whiteTurn) {
    position putPiecePosition; 
    bool isPuttingAPiece = false; 

    do {
        isPuttingAPiece = true;
        cout << "---------------------------------------" << endl;
        cout << "Elige una posición para poner tu pieza:" << endl;
        cout << "---------------------------------------" << endl;
        cout << "(1-" << TAMANY_TAULELL << "): ";
        int inputY;
        cin >> inputY;
        cout << "(1-" << TAMANY_TAULELL << "): ";
        int inputX;
        cin >> inputX;

        putPiecePosition.x = TAMANY_TAULELL - inputX;  // fila invertida
        putPiecePosition.y = inputY - 1; // obviar el 0

		//Comprovaciones de donde podemos poner la pieza
        if (putPiecePosition.x < 0 || putPiecePosition.x >= TAMANY_TAULELL ||
            putPiecePosition.y < 0 || putPiecePosition.y >= TAMANY_TAULELL) {
            cout << "INPUT INVALIDO!!!! Fuera de límites" << endl;
            isPuttingAPiece = false;
            continue;
        }

    } while (!isPuttingAPiece);

    return putPiecePosition;
}



