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

    // Bucle principal del juego
    while (!gameOver) {
        //system("cls"); // Limpia la pantalla
        PrinteoTablero(chessBoard); // Muestra el tablero

        if (whiteTurn)
            cout << "Turno de las Blancas" << endl;
        else
            cout << "Turno de las Negras" << endl;

        // Seleccionar una pieza
        position userGetPice = getPiceByUser(chessBoard, whiteTurn);
        position setPiceByUser = PutPiceByUser(chessBoard, whiteTurn);

        // Intentar mover la pieza
        position nuevaPos = MoverPieza(chessBoard, userGetPice, setPiceByUser);

        // Verificar si el movimiento fue exitoso
        if (nuevaPos.x != userGetPice.x || nuevaPos.y != userGetPice.y) {
            cout << "Movimiento exitoso." << endl;
            whiteTurn = !whiteTurn; // Cambiar turno
        }
        else {
            cout << "Movimiento inválido. Intenta de nuevo." << endl;
        }

        // comprobar si se ha acabado el juego
        // gameOver = verificarEstadoDelJuego(chessBoard, whiteTurn);
    }

    cout << "¡Fin del juego!" << endl;
    return 0;
}
