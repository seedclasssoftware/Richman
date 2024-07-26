#ifndef EARTHUP_H
#define EARTHUP_H
#include "map.h"
#include "players.h"
#include <stdio.h>

void earth_up(pPlayers player, Cell *cells);
int is_your_earth(Players player, Cell *cells);

#endif