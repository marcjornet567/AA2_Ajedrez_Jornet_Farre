#include "const.h"
#include "utils.h"

//Funcion de eliminacion de la pieza
void eliminarPieza(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position posicio) {
    chessBoard[posicio.x][posicio.y] = ESPAI; // Elimina la pieza
}
// Función para mover la reina
position MovimentReina(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {

	// Validar que el movimiento sea en Horizontal, vertical o diagonal
    if (userGetPice.x != setPiceByUser.x && userGetPice.y != setPiceByUser.y &&
        abs(userGetPice.x - setPiceByUser.x) != abs(userGetPice.y - setPiceByUser.y)) {
        return userGetPice; // Si cumple con todas estas comprovaciones el Movimiento sera inválido
    }
    // Determinar la dirección del movimiento en el eje x
    int dx = (setPiceByUser.x > userGetPice.x) - (setPiceByUser.x < userGetPice.x);
	// Determinar la dirección del movimiento en el eje y
    int dy = (setPiceByUser.y > userGetPice.y) - (setPiceByUser.y < userGetPice.y);
	// Moverse en la dirección determinada
    int x = userGetPice.x + dx, y = userGetPice.y + dy;

	// Comprobar si hay obstáculos en el camino
    while (x != setPiceByUser.x || y != setPiceByUser.y) {
        if (chessBoard[x][y] != ESPAI) {
            return userGetPice; // Obstáculo
        }
        x += dx;
        y += dy;
    }
	// Verificar que la casilla destino no esté ocupada por una pieza del mismo color
	//Verificamos si esta no es un espacio vacio y si la pieza en la posicon de destino es del mismo color que la pieza seleccionada
    if (chessBoard[setPiceByUser.x][setPiceByUser.y] != ESPAI &&
        (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) == isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
        return userGetPice; // Casilla ocupada por pieza del mismo color
    }
    return setPiceByUser; // Movimiento válido
}

// Función para mover el rey
position MovimentRei(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
    // Validar que el movimiento sea de una casilla en cualquier dirección
    if (abs(userGetPice.x - setPiceByUser.x) <= 1 && abs(userGetPice.y - setPiceByUser.y) <= 1) {
        // Verificar que la casilla destino no esté ocupada por una pieza del mismo color
        if (chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI ||
            (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
            return setPiceByUser; // Movimiento válido
        }
    }
    return userGetPice; // Si el movimiento no es válido, regresar la posición original
}

// Función para mover el caballo
position MovimentCavall(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
	// Calcular la diferencia en filas y columnas entre la posición actual y la posición de destino, con el valor absoluto(abs)
    int dx = abs(userGetPice.x - setPiceByUser.x);
    int dy = abs(userGetPice.y - setPiceByUser.y);

    // Un caballo se mueve en forma de "L": 2 casillas en una dirección y 1 casilla en la otra
    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) {

        // Verificar si la casilla de destino está vacía o si contiene una pieza del color opuesto
        if (chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI ||
            (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
			return setPiceByUser; // Movimiento válido
        }
    }
	return userGetPice; // Si el movimiento no es válido, regresar la posición original
}

// Función para mover el alfil
position MovimentAlfil(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
    // Calcular la diferencia en filas y columnas entre la posición actual y la posición de destino
    int dx = setPiceByUser.x - userGetPice.x;
    int dy = setPiceByUser.y - userGetPice.y;
	// Verificar si el movimiento es diagonal
    if (abs(dx) == abs(dy)) {
        int stepX = (dx > 0) ? 1 : -1;
        int stepY = (dy > 0) ? 1 : -1;
        int x = userGetPice.x + stepX;
        int y = userGetPice.y + stepY;
		//Comprobar si hay obstáculos en el camino
        while (x != setPiceByUser.x && y != setPiceByUser.y) {
            if (chessBoard[x][y] != ESPAI) return userGetPice; // Obstáculo
            x += stepX;
            y += stepY;
        }
		// Verificar que la casilla destino no esté ocupada por una pieza del mismo color
        if (chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI ||
            (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
			return setPiceByUser; // Movimiento válido
        }
    }
	return userGetPice; // Si el movimiento no es válido, regresar la posición original
}

// Función para mover la torre
position MovimentTorre(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser) {
	// Calcular la diferencia en filas y columnas entre la posición actual y la posición de destino
    int dx = setPiceByUser.x - userGetPice.x;
    int dy = setPiceByUser.y - userGetPice.y;
    // Verificar si el movimiento es horizontal o vertical (la torre se mueve en línea recta)
    if (dx == 0 || dy == 0) {
        int stepX = (dx > 0) - (dx < 0);
        int stepY = (dy > 0) - (dy < 0);
        int x = userGetPice.x + stepX;
        int y = userGetPice.y + stepY;
		// Comprobar si hay obstáculos en el camino
        while (x != setPiceByUser.x || y != setPiceByUser.y) {
            if (chessBoard[x][y] != ESPAI) return userGetPice; // Obstáculo
            x += stepX;
            y += stepY;
        }
		// Verificar que la casilla destino no esté ocupada por una pieza del mismo color
        if (chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI ||
            (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
			return setPiceByUser; // Movimiento válido
        }
    }
	return userGetPice; // Si el movimiento no es válido, regresar la posición original
}

// Función para mover el peón
position MovimentPeon(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser, int color) {
    int direction = color;

// Determinar la dirección del movimiento según el color
    if (color == 1) {
        direction = -1; // blanco
    }
    else {
        direction = 1; // negro
    }

    // Un paso adelante
    if (setPiceByUser.y == userGetPice.y) {
        if (setPiceByUser.x == userGetPice.x + direction && chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI) {
            return setPiceByUser;
        }
        // Dos pasos adelante desde posición inicial
        int filaInicial = (color == 1) ? (TAMANY_TAULELL - 2) : 1;
        if (userGetPice.x == filaInicial &&
            setPiceByUser.x == userGetPice.x + 2 * direction &&
            chessBoard[setPiceByUser.x][setPiceByUser.y] == ESPAI &&
            chessBoard[userGetPice.x + direction][userGetPice.y] == ESPAI) {
            return setPiceByUser;
        }
    }
    // Captura diagonal
    if (abs(setPiceByUser.y - userGetPice.y) == 1 && setPiceByUser.x == userGetPice.x + direction) {
		// Verificar que la casilla destino no esté ocupada por una pieza del mismo color
        if (chessBoard[setPiceByUser.x][setPiceByUser.y] != ESPAI &&
            (isupper(chessBoard[setPiceByUser.x][setPiceByUser.y]) != isupper(chessBoard[userGetPice.x][userGetPice.y]))) {
            return setPiceByUser;
        }
    }
    return userGetPice;
}



position MoverPieza(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser, int& puntosBlancas, int& puntosNegras) {
    // Obtener la pieza seleccionada    
    char pieza = chessBoard[userGetPice.x][userGetPice.y];
    position nuevaPos;
    // Determinar el movimiento según el tipo de pieza
	
	//Utilitzo "tolower" per evitar fer el switch amb majuscules i minuscules
	//Tambe utilitzem el "isupper (pieza) ? 1 : -1)" per saber si es blanca o negra
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



    // Verificar si el movimiento fue exitoso
    if (nuevaPos.x == userGetPice.x && nuevaPos.y == userGetPice.y) {
        return userGetPice; // No se realizó el movimiento
    }

    // Si hay una pieza enemiga en la casilla destino, eliminarla
    if (chessBoard[nuevaPos.x][nuevaPos.y] != ESPAI &&
        (isupper(chessBoard[nuevaPos.x][nuevaPos.y]) != isupper(pieza))) {

        char piezaCapturada = chessBoard[nuevaPos.x][nuevaPos.y];  // Guardar la pieza capturada antes de eliminar, pq si no no lo tiene en cuenta y soo entraria en el else.

        eliminarPieza(chessBoard, nuevaPos);

        // Actualizar el contador de piezas
        if (isupper(piezaCapturada)) {
            puntosBlancas--;
        }
        else {
            puntosNegras--;
        }
    }

    // Realizar el movimiento
    chessBoard[nuevaPos.x][nuevaPos.y] = chessBoard[userGetPice.x][userGetPice.y];
    chessBoard[userGetPice.x][userGetPice.y] = ESPAI;

    return nuevaPos; // Devuelve la nueva posición o la original si el movimiento fue inválido
}



