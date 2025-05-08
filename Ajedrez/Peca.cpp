#include "const.h"
#include "utils.h"

bool esMovimientoHorizontalValido(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
    if (userGetPice.x == setPiceByUser.x) {
        int step = (setPiceByUser.y > userGetPice.y) ? 1 : -1;
        for (int j = userGetPice.y + step; j != setPiceByUser.y; j += step) {
            if (chessBoard[userGetPice.x][j] != ESPAI) {
                return false; // Hay una pieza bloqueando el camino
            }
        }
        return true;
    }
    return false;
}

bool esMovimientoVerticalValido(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
	if (userGetPice.y == setPiceByUser.y) {
		int step = (setPiceByUser.x > userGetPice.x) ? 1 : -1;
		for (int i = userGetPice.x + step; i != setPiceByUser.x; i += step) {
			if (chessBoard[i][userGetPice.y] != ESPAI) {
				return false; // Hay una pieza bloqueando el camino
			}
		}
		return true;
	}
	return false;
}

bool esMovimientoDiagonalValido(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
    int dx = (setPiceByUser.x > userGetPice.x) ? 1 : -1;
    int dy = (setPiceByUser.y > userGetPice.y) ? 1 : -1;

    int x = userGetPice.x + dx;
    int y = userGetPice.y + dy;

    while (x != setPiceByUser.x && y != setPiceByUser.y) {
        if (chessBoard[x][y] != ESPAI) {
            return false; // Hay una pieza bloqueando el camino
        }
        x += dx;
        y += dy;
    }
    return true;
}


bool esMovimientoPeonValido(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
	int direction = (chessBoard[userGetPice.x][userGetPice.y] == PEON_BLANC) ? 1 : -1;
	if (userGetPice.x + direction == setPiceByUser.x && userGetPice.y == setPiceByUser.y && chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI) {
		return true; // Movimiento hacia adelante
	}
	if (userGetPice.x + direction == setPiceByUser.x && abs(userGetPice.y - setPiceByUser.y) == 1 && chessBoard[setPiceByUser.x][setPiceByUser.y] != ESPAI) {
		return true; // Captura diagonal
	}
	return false;
}
// Verifica si las piezas son del mismo color o si alguna de ellas es un espacio vacío
bool mismoColor(char pieza1, char pieza2) {
	return (pieza1 == pieza2) || (pieza1 == ESPAI) || (pieza2 == ESPAI);
}



// Validacio de la peça
bool esMovimientoValido(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser, char pieza) {
    // Verifica si el movimiento está dentro del tablero
    if (setPiceByUser.x < 0 || setPiceByUser.x >= TAMANY_TAULELL || setPiceByUser.y < 0 || setPiceByUser.y >= TAMANY_TAULELL) {
        return false;
    }

    // Verifica que no haya una pieza del mismo color en la casilla destino
    if (mismoColor(chessBoard[userGetPice.x][userGetPice.y], chessBoard[setPiceByUser.x][setPiceByUser.y])) {
        return false;
    }

    // Dependiendo de la pieza, valida el movimiento
    switch (pieza) {
    case 'K': // Movimiento del Rey
        return abs(userGetPice.x - setPiceByUser.x) <= 1 && abs(userGetPice.y - setPiceByUser.y) <= 1;
    case 'Q': // Movimiento de la Reina
        return esMovimientoDiagonalValido(chessBoard, userGetPice, setPiceByUser) || esMovimientoHorizontalValido(chessBoard, userGetPice, setPiceByUser);
    case 'H': // Movimiento del Caballo
        return (abs(userGetPice.x - setPiceByUser.x) == 2 && abs(userGetPice.y - setPiceByUser.y) == 1) || (abs(userGetPice.x - setPiceByUser.x) == 1 && abs(userGetPice.y - setPiceByUser.y) == 2);
    case 'B': // Movimiento del Alfil
        return esMovimientoDiagonalValido(chessBoard, userGetPice, setPiceByUser);
    case 'T': // Movimiento de la Torre
        return esMovimientoHorizontalValido(chessBoard, userGetPice, setPiceByUser);
    case 'P': // Movimiento del Peón
        return esMovimientoPeonValido(chessBoard, userGetPice, setPiceByUser);
    default:
        return false;
    }
}




