#include "const.h"
#include "taulell.h"
#include "utils.h"
#include "moviment.h"
#include "Peca.h"

int main() {

    // Declaración del tablero
    char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL];
    IniciarTablero(chessBoard); // Inicializa el tablero con las piezas en su posición inicial

    bool whiteTurn = true; // Comienza con el turno de las blancas
    bool gameOver = false; // Controla si el juego ha terminado

    // Bucle principal del juego
    while (!gameOver) {
        //system("cls"); // Limpia la pantalla (en sistemas compatibles)
        PrinteoTablero(chessBoard); // Muestra el tablero

        cout << (whiteTurn ? "Turno de las blancas" : "Turno de las negras") << endl;

        // Seleccionar una pieza
        position userGetPice = getPiceByUser(chessBoard, whiteTurn);

        // Seleccionar la posición destino
        position setPiceByUser;
        cout << "Introduce la posición destino:" << endl;
        cout << "X: ";
        cin >> setPiceByUser.x;
        cout << "Y: ";
        cin >> setPiceByUser.y;

        cout << " en la posición ("
            << userGetPice.x << ", " << TAMANY_TAULELL - userGetPice.y << ")" << endl;
        // Ajustar la posición destino (coordenadas de usuario a índices del tablero)
        /*setPiceByUser.x--;
        setPiceByUser.y--;
        setPiceByUser.y = TAMANY_TAULELL - setPiceByUser.y - 1;*/

        // Obtener la pieza seleccionada
        char pieza = chessBoard[userGetPice.x][userGetPice.y];

        // Validar y realizar movimiento
        if (esMovimientoValido(chessBoard, userGetPice, setPiceByUser, pieza)) {
            cout << "Movimiento realizado con éxito." << endl;
            whiteTurn = !whiteTurn; // Cambiar turno
        }
        else {
            cout << "Movimiento inválido. Intenta de nuevo." << endl;
        }

        // (Aquí puedes agregar lógica para verificar jaque, jaque mate o empate)
        // gameOver = verificarEstadoDelJuego(chessBoard, whiteTurn);
    }

    cout << "¡Fin del juego!" << endl;
    return 0;
}