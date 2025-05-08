#include "const.h"
#include "taulell.h"
#include "utils.h"
#include "moviment.h"
#include "Peca.h"

int main() {

    // Declaraci�n del tablero
    char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL];
    IniciarTablero(chessBoard); // Inicializa el tablero con las piezas en su posici�n inicial

    bool whiteTurn = true; // Comienza con el turno de las blancas
    bool gameOver = false; // Controla si el juego ha terminado

    // Bucle principal del juego
    while (!gameOver) {
        //system("cls"); // Limpia la pantalla (en sistemas compatibles)
        PrinteoTablero(chessBoard); // Muestra el tablero

        cout << (whiteTurn ? "Turno de las blancas" : "Turno de las negras") << endl;

        // Seleccionar una pieza
        position userGetPice = getPiceByUser(chessBoard, whiteTurn);

        // Seleccionar la posici�n destino
        position setPiceByUser;
        cout << "Introduce la posici�n destino:" << endl;
        cout << "X: ";
        cin >> setPiceByUser.x;
        cout << "Y: ";
        cin >> setPiceByUser.y;

        cout << " en la posici�n ("
            << userGetPice.x << ", " << TAMANY_TAULELL - userGetPice.y << ")" << endl;
        // Ajustar la posici�n destino (coordenadas de usuario a �ndices del tablero)
        /*setPiceByUser.x--;
        setPiceByUser.y--;
        setPiceByUser.y = TAMANY_TAULELL - setPiceByUser.y - 1;*/

        // Obtener la pieza seleccionada
        char pieza = chessBoard[userGetPice.x][userGetPice.y];

        // Validar y realizar movimiento
        if (esMovimientoValido(chessBoard, userGetPice, setPiceByUser, pieza)) {
            cout << "Movimiento realizado con �xito." << endl;
            whiteTurn = !whiteTurn; // Cambiar turno
        }
        else {
            cout << "Movimiento inv�lido. Intenta de nuevo." << endl;
        }

        // (Aqu� puedes agregar l�gica para verificar jaque, jaque mate o empate)
        // gameOver = verificarEstadoDelJuego(chessBoard, whiteTurn);
    }

    cout << "�Fin del juego!" << endl;
    return 0;
}