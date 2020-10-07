/*! @file
 *
 *  @brief Routines to generate random numbers on the TWR-K70F120M.
 *
 *  This contains the functions for operating the RNG.
 *
 *  @author Anuraag
 *  @date 2015-10-18
 */

#ifndef SOURCES_RNG_H_
#define SOURCES_RNG_H_

// new types
#include "types.h"
#include "MK70F12.h"

/*! @brief Sets up the RNG before first use.
 *
 *  @return BOOL - TRUE if the RNG was successfully initialized.
 */
BOOL RNG_Init();

/*! @brief Gets a random number.
 *
 *  @return uint32_t - random number
 *  @note Assumes that RNG_Init has been called.
 */
uint32_t RNG_Get();

/*! @brief Poll the RNG status register to try and receive the random number.
 *
 *  @return void
 *  @note Assumes that UART_Init has been called.
 */
BOOL RNG_Poll();


#endif /* SOURCES_RNG_H_ */
