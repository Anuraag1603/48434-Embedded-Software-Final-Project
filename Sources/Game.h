/*
 * Game.h
 *
 *  Created on: 19 Oct 2015
 *      Author: 12029866
 */

#ifndef SOURCES_Game_H_
#define SOURCES_Game_H_

// new types
#include "types.h"
#include "MK70F12.h"
#include "LEDs.h"
#include "Cpu.h"
#include "TSI.h"
#include "RNG.h"

int Random_Num[256];
int High;

/*! @brief Toggle the appropriate LED
 *
 *  @return void
 *  @note Assumes that LEDs_Init has been called.
 */
void Touch_Toggle();

/*! @brief Memory game
 *
 *  @return void
 *  @note Assumes that LEDs_Init has been called.
 */
void Memory_Game();

/*! @brief sort numbers
 *
 *  @return void
 *  @note Assumes that RNG_Init has been called.
 */
void Sort_Numbers();

/*! @brief Blink the appropriate LED
 *
 *  @return void
 *  @note Assumes that LEDs_Init has been called.
 */
void Blink(int LED_Nub);

/*! @brief Delay
 *
 *  @return void
 */
void delay (int i);

#endif /* SOURCES_GAME_H_ */
