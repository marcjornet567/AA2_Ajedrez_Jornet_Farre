#pragma once
#include "const.h"
#include "utils.h"


void IniciarTablero(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL]);
void PrinteoTablero(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL]);

position getPiceByUser(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], bool whiteTurn);
position PutPiceByUser(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], bool whiteTurn);