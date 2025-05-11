#pragma once
#include "const.h"
#include "utils.h"

void eliminarPieza(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position posicio);
position MovimentReina(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
position MovimentRei(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
position MovimentCavall(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
position MovimentAlfil(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
position MovimentTorre(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
position MovimentPeon(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser, int color);
position MoverPieza(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser, int& puntosBlancas, int& puntosNegras);
