#pragma once
//llibreries
#include <iostream>
#include <vector>
#include <time.h>
#include <thread>
#include <chrono>
#include <Windows.h>

//llibreries propies
//#include "keyboard.h"
using namespace std;

//defines
//tauler
#define TAMANY_TAULELL 8
#define ESPAI '*'
//peces blanques
#define PEON_BLANC 'P'
#define TORRE_BLANC 'T'
#define ALFIL_BLANC 'B'
#define CABALL_BLANC 'H'
#define REINA_BLANC 'Q'
#define REI_BLANC 'K'
//peces negres
#define PEON_NEGRE 'p'
#define TORRE_NEGRE 't'
#define ALFIL_NEGRE 'b'
#define CABALL_NEGRE 'h'
#define REINA_NEGRE 'q'
#define REI_NEGRE 'k'