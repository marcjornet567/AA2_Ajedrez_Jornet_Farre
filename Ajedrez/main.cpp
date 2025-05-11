#include "const.h"
#include "taulell.h"
#include "utils.h"
#include "moviment.h"

int main() {
    // Declaración del tablero
    char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL];
    IniciarTablero(chessBoard); // Inicializa el tablero con las piezas en su posición inicial

    bool whiteTurn = true; // Comienza con el turno de las blancas
    bool gameOver = false; // Controla si el juego ha terminado
    
    // Contador de las 16 Piezas(Alternativa mas simple que el JAQUE MATE) 
    int puntosBlancas = 16;
    int puntosNegras = 16;

    // Bucle principal del juego
    while (!gameOver) {
        //system("cls"); // Limpia la pantalla
        PrinteoTablero(chessBoard); // Muestra el tablero
		cout << "BLANCAS(mayus): " << puntosBlancas << endl;
		cout << "NEGRAS(min): " << puntosNegras << endl;

        if (whiteTurn)
            cout << endl << "TURNO: Blancas" << endl;
        else
            cout << "TURNO: Negras" << endl;

        // Seleccionar una pieza
        position userGetPice = getPiceByUser(chessBoard, whiteTurn);
        position setPiceByUser = PutPiceByUser(chessBoard, whiteTurn);

        // Intentar mover la pieza
        position nuevaPos = MoverPieza(chessBoard, userGetPice, setPiceByUser, puntosBlancas, puntosNegras);

        // Verificar si el movimiento fue exitoso
        if (nuevaPos.x != userGetPice.x || nuevaPos.y != userGetPice.y) {
            cout << "Movimiento exitoso." << endl;
            whiteTurn = !whiteTurn; // Cambiar turno
        }
        else {
            cout << "Movimiento invalido. Intenta de nuevo." << endl;
        }

        // Verificar CONDICION de victoria
        if (puntosBlancas <= 0) {
            cout << "¡Fin del juego!, GANADOR: Negras!" << endl;
            gameOver = true;
        }
        else if (puntosNegras <= 0) {
            cout << "¡Fin del juego!, GANADOR: Blancas!" << endl;
            gameOver = true;
        }
    }
    return 0;
}
