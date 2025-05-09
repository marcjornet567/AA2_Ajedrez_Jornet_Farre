#include "const.h"
#include "taulell.h"
#include "utils.h"
#include "moviment.h"
#include "Peca.h"

int main() {

    // Declaración del tablero
    char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL];
    IniciarTablero(chessBoard); // Inicializa el tablero con las piezas en su posición inicial

    bool whiteTurn = false; // Comienza con el turno de las blancas
    bool gameOver = false; // Controla si el juego ha terminado

    // Bucle principal del juego
    while (!gameOver) {
        //system("cls"); // Limpia la pantalla
        PrinteoTablero(chessBoard); // Muestra el tablero

        cout << (whiteTurn ? "Turno de las negras" : "Turno de las blancas") << endl;

        // Seleccionar una pieza
        position userGetPice = getPiceByUser(chessBoard, whiteTurn);

        // Obtener la pieza seleccionada
        char pieza = chessBoard[userGetPice.x][userGetPice.y];

        position setPiceByUser = PutPiceByUser(chessBoard, whiteTurn);

        // Validar y realizar movimiento
        if (esMovimientoValido(chessBoard, userGetPice, setPiceByUser, pieza)) {
            cout << "Movimiento exitoso." << endl;
            whiteTurn = !whiteTurn; // Cambiar turno
        }
        else {
            cout << "Movimiento invalido. Intenta de nuevo." << endl;
        }

        //Aqui podem comprobar si s'ha acabat el joc
        // gameOver = verificarEstadoDelJuego(chessBoard, whiteTurn);
    }

    cout << "¡Fin del juego!" << endl;
    return 0;
}
