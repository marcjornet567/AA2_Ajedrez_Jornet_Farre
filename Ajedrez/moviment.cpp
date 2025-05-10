#include "const.h"
#include "utils.h"

//Funcion de eliminacion de la pieza
void eliminarPieza(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position posicio) {
    chessBoard[posicio.x][posicio.y] = ESPAI; // Elimina la pieza
}
// Función para mover la reina
position MovimentReina(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
    // Validar movimiento en línea recta o diagonal
    if (userGetPice.x != setPiceByUser.x && userGetPice.y != setPiceByUser.y &&
        abs(userGetPice.x - setPiceByUser.x) != abs(userGetPice.y - setPiceByUser.y)) {
        return userGetPice; // Movimiento inválido
    }

    // Verificar obstáculos en el camino
    int dx = (setPiceByUser.x > userGetPice.x) - (setPiceByUser.x < userGetPice.x);
    int dy = (setPiceByUser.y > userGetPice.y) - (setPiceByUser.y < userGetPice.y);
    int x = userGetPice.x + dx, y = userGetPice.y + dy;

    while (x != setPiceByUser.x || y != setPiceByUser.y) {
        if (chessBoard[x][y] != ESPAI) {
            return userGetPice; // Hay un obstáculo en el camino
        }
        x += dx;
        y += dy;
    }

    // Verificar que la casilla destino no esté ocupada por una pieza del mismo color
    if (chessBoard[setPiceByUser.x][setPiceByUser.y] != ESPAI &&
        (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) == isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
        return userGetPice; // No se puede mover a una casilla ocupada por una pieza del mismo color
    }

	// Si hay una pieza enemiga en la casilla destino, eliminarla
    if (chessBoard[setPiceByUser.x][setPiceByUser.y] != ESPAI &&
        (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
        eliminarPieza(chessBoard, setPiceByUser); // Eliminar la pieza enemiga
    }

    // Realizar el movimiento
    chessBoard[setPiceByUser.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
    chessBoard[userGetPice.x][userGetPice.y] = ESPAI;

    return setPiceByUser;
}

// Función para mover el rey
position MovimentRei(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
    // Validar que el movimiento sea de una casilla en cualquier dirección
    if (abs(userGetPice.x - setPiceByUser.x) <= 1 && abs(userGetPice.y - setPiceByUser.y) <= 1) {
        
        // Verificar que la casilla destino no esté ocupada por una pieza del mismo color
        if (chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI || (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
			
            // Si hay una pieza enemiga en la casilla destino, eliminarla
            if (chessBoard[setPiceByUser.x][setPiceByUser.y] != ESPAI &&
                (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
                eliminarPieza(chessBoard, setPiceByUser); // Eliminar la pieza enemiga
            }
            // Realizar el movimiento
            chessBoard[setPiceByUser.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
            chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
            return setPiceByUser;
        }
    }
    return userGetPice; // Si el movimiento no es válido, regresar la posición original
}


// Función para mover el caballo
position MovimentCavall(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
    int dx = abs(userGetPice.x - setPiceByUser.x);
    int dy = abs(userGetPice.y - setPiceByUser.y);
    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {
        // Verificar que la casilla destino no esté ocupada por pieza del mismo color
        if (chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI ||
            (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
			
            // Si hay una pieza enemiga en la casilla destino, eliminarla
            if (chessBoard[setPiceByUser.x][setPiceByUser.y] != ESPAI &&
                (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
                eliminarPieza(chessBoard, setPiceByUser); // Eliminar la pieza enemiga
            }
            
            // Realizar movimiento
            chessBoard[setPiceByUser.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
            chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
            return setPiceByUser;
        }
    }
    return userGetPice;
}

// Función para mover el alfil
position MovimentAlfil(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
    int dx = setPiceByUser.x - userGetPice.x;
    int dy = setPiceByUser.y - userGetPice.y;
    if (abs(dx) == abs(dy)) {
        int stepX = (dx > 0) ? 1 : -1;
        int stepY = (dy > 0) ? 1 : -1;
        int x = userGetPice.x + stepX;
        int y = userGetPice.y + stepY;
        while (x != setPiceByUser.x && y != setPiceByUser.y) {
            if (chessBoard[x][y] != ESPAI) return userGetPice; // Hay obstáculo
            x += stepX;
            y += stepY;
        }

        if (chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI ||
            (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {

			// Si hay una pieza enemiga en la casilla destino, eliminarla
            if (chessBoard[setPiceByUser.x][setPiceByUser.y] != ESPAI &&
                (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
                eliminarPieza(chessBoard, setPiceByUser); // Eliminar la pieza enemiga
            }
			// Realizar movimiento
            chessBoard[setPiceByUser.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
            chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
            return setPiceByUser;
        }
    }
    return userGetPice;
}

// Función para mover la torre
position MovimentTorre(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
    int dx = setPiceByUser.x - userGetPice.x;
    int dy = setPiceByUser.y - userGetPice.y;
    if (dx == 0 || dy == 0) {
        int stepX = (dx > 0) - (dx < 0);
        int stepY = (dy > 0) - (dy < 0);
        int x = userGetPice.x + stepX;
        int y = userGetPice.y + stepY;
        while (x != setPiceByUser.x || y != setPiceByUser.y) {
            if (chessBoard[x][y] != ESPAI) return userGetPice; // Obstáculo
            x += stepX;
            y += stepY;
        }
		// Verificar que la casilla destino no esté ocupada por una pieza del mismo color
        if (chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI ||
            (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
			// Si hay una pieza enemiga en la casilla destino, eliminarla
			if (chessBoard[setPiceByUser.x][setPiceByUser.y] != ESPAI &&
				(isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
				eliminarPieza(chessBoard, setPiceByUser); // Eliminar la pieza enemiga
			}
			// Realizar movimiento
            chessBoard[setPiceByUser.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
            chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
            return setPiceByUser;
        }
    }
    return userGetPice;
}

// Función para mover el peón
position MovimentPeon(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser, int color) {
    // color = 1 para blanco, -1 para negro
    int direction = color == 1 ? -1 : 1; // filas decrecen para blancas, crecen para negras

    // Movimiento hacia adelante (sin captura)
    if (setPiceByUser.y == userGetPice.y) {
        // Un paso adelante
        if (setPiceByUser.x == userGetPice.x + direction && chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI) {
            chessBoard[setPiceByUser.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
            chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
            return setPiceByUser;
        }
        // Dos pasos adelante desde la posición inicial
        int inicioFila = (color == 1) ? (TAMANY_TAULELL - 2) : 1;
        if (userGetPice.x == inicioFila &&
            setPiceByUser.x == userGetPice.x + 2 * direction &&
            chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI &&
            chessBoard[userGetPice.x + direction][userGetPice.y] == ESPAI) {
            chessBoard[setPiceByUser.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
            chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
            return setPiceByUser;
        }
    }
    // Captura diagonal
    if (abs(setPiceByUser.y - userGetPice.y) == 1 && setPiceByUser.x == userGetPice.x + direction) {
        if (chessBoard[setPiceByUser.x][setPiceByUser.y] != ESPAI &&
            (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
			// Si hay una pieza enemiga en la casilla destino, eliminarla
			eliminarPieza(chessBoard, setPiceByUser); // Eliminar la pieza enemiga
			// Realizar movimiento
            chessBoard[setPiceByUser.x][setPiceByUser.y] = chessBoard[userGetPice.x][userGetPice.y];
            chessBoard[userGetPice.x][userGetPice.y] = ESPAI;
            return setPiceByUser;
        }
    }
    return userGetPice;
}

position MoverPieza(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
    // Obtener la pieza seleccionada    
    char pieza = chessBoard[userGetPice.x][userGetPice.y];
    position nuevaPos;
    // Determinar el movimiento según el tipo de pieza
    
	//Utilitzo "tolower" per evitar fer el switch amb majuscules i minuscules
	//Tambe utilitzem el "isupper" per saber si es blanca o negra
    switch (tolower(pieza)) {
    case 'p': // Peón
        nuevaPos = MovimentPeon(chessBoard, userGetPice, setPiceByUser, isupper(pieza) ? 1 : -1);
        break;
    case 't': // Torre
        nuevaPos = MovimentTorre(chessBoard, userGetPice, setPiceByUser);
        break;
    case 'b': // Alfil
        nuevaPos = MovimentAlfil(chessBoard, userGetPice, setPiceByUser);
        break;
    case 'h': // Caballo
        nuevaPos = MovimentCavall(chessBoard, userGetPice, setPiceByUser);
        break;
    case 'q': // Reina
        nuevaPos = MovimentReina(chessBoard, userGetPice, setPiceByUser);
        break;
    case 'k': // Rey
        nuevaPos = MovimentRei(chessBoard, userGetPice, setPiceByUser);
        break;
    default: // Movimiento inválido
        nuevaPos = userGetPice; // No se mueve
        break;
    }
    return nuevaPos; // Devuelve la nueva posición (o la original si el movimiento fue inválido)
}



