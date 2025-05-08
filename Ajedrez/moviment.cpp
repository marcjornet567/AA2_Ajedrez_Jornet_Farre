#include "const.h"
#include "utils.h"

position MovimientoReina(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
	
	// Movimiento horizontal

	for (int i = 0; i < TAMANY_TAULELL; i++) {
		if (chessBoard[userGetPice.x][i] == ESPAI) {
			chessBoard[userGetPice.x][i] = chessBoard[userGetPice.x][userGetPice.y];
			chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
		}
	}

	// Movimiento vertical

	for (int i = 0; i < TAMANY_TAULELL; i++) {
		if (chessBoard[i][userGetPice.y] == ESPAI) {
			chessBoard[i][userGetPice.y] = chessBoard[userGetPice.x][userGetPice.y];
			chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
		}
	}
	// Movimiento diagonal

	for (int i = 0; i < TAMANY_TAULELL; i++) {
		if (chessBoard[i][i] == ESPAI) {
			chessBoard[i][i] = chessBoard[userGetPice.x][userGetPice.y];
			chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
		}
	}
	return setPiceByUser;
}

position MovimientoRei(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {

	// Movimiento horizontal
	if (userGetPice.x == setPiceByUser.x && userGetPice.y != setPiceByUser.y) {
		chessBoard[userGetPice.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
		chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
	}
	// Movimiento vertical
	else if (userGetPice.x != setPiceByUser.x && userGetPice.y == setPiceByUser.y) {
		chessBoard[setPiceByUser.x][userGetPice.y] = chessBoard[userGetPice.x][userGetPice.y];
		chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
	}
	// Movimiento diagonal
	else if (abs(userGetPice.x - setPiceByUser.x) == abs(userGetPice.y - setPiceByUser.y)) {
		chessBoard[setPiceByUser.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
		chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
	}
	return setPiceByUser;
}

position MovimientoCaball(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
	// Movimiento en L
	if ((abs(userGetPice.x - setPiceByUser.x) == 2 && abs(userGetPice.y - setPiceByUser.y) == 1) || (abs(userGetPice.x - setPiceByUser.x) == 1 && abs(userGetPice.y - setPiceByUser.y) == 2)) {
		chessBoard[setPiceByUser.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
		chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
	}
	return setPiceByUser;
}

position MovimientoAlfil(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
	// Movimiento diagonal
	if (abs(userGetPice.x - setPiceByUser.x) == abs(userGetPice.y - setPiceByUser.y)) {
		chessBoard[setPiceByUser.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
		chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
	}
	return setPiceByUser;
}

position MovimientoTorre(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
	// Movimiento horizontal
	if (userGetPice.x == setPiceByUser.x && userGetPice.y != setPiceByUser.y) {
		chessBoard[userGetPice.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
		chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
	}
	// Movimiento vertical
	else if (userGetPice.x != setPiceByUser.x && userGetPice.y == setPiceByUser.y) {
		chessBoard[setPiceByUser.x][userGetPice.y] = chessBoard[userGetPice.x][userGetPice.y];
		chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
	}
	return setPiceByUser;
}

position MovimientoPeon(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
	// Movimiento vertical
	if (userGetPice.x == setPiceByUser.x && userGetPice.y != setPiceByUser.y) {
		chessBoard[userGetPice.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
		chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
	}
	// Movimiento diagonal
	else if (abs(userGetPice.x - setPiceByUser.x) == 1 && abs(userGetPice.y - setPiceByUser.y) == 1) {
		chessBoard[setPiceByUser.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
		chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
	}
	return setPiceByUser;
}