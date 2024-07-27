#ifndef INIT_PLAY_H
#define INIT_PLAY_H

#include <stdint.h>
#include "players.h"

void init_money(uint32_t *initMoney);
void select_players(Players *players, int *selected_players, int num_players, uint32_t init_money);

#endif