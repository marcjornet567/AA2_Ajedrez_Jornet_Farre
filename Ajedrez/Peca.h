#pragma once

#include "const.h"
#include "utils.h"

bool esMovimientoHorizontalValido(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
bool esMovimientoVerticalValido(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
bool esMovimientoDiagonalValido(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
bool esMovimientoPeonValido(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
bool mismoColor(char pieza1, char pieza2);
bool esMovimientoValido(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser, char pieza);