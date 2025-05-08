#pragma once
#include "const.h"
#include "utils.h"

position MovimientoReina(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
position MovimientoRei(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
position MovimientoCaball(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
position MovimientoAlfil(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
position MovimientoTorre(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
position MovimientoPeon(char chessBoard[TAMANY_TAULELL][TAMANY_TAULELL], position userGetPice, position setPiceByUser);
