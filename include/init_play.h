#ifndef INIT_PLAY_H
#define INIT_PLAY_H

#include "players.h"
#include <stdint.h>


/**
 * @brief Initializes the money for the game
 *
 * @param initMoney Pointer to the variable that will store the initial money
 */
void init_money(uint32_t *initMoney);

/**
 * @brief Selects the players for the game
 *
 * @param players Pointer to the players struct
 * @param selected_players Pointer to the array that will store the selected
 * players
 * @param num_players Number of players
 * @param init_money Initial money for the game
 */
void selectPlayers(uint32_t *initMoney);
void initialize_Players();
const char *getPlayerColor(const char *name);
void printPlayerName(const char *name);

#endif