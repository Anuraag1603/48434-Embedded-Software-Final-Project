/*
 * TSI.h
 *
 *  Created on: 19 Oct 2015
 *      Author: 12029866
 */

#ifndef SOURCES_TSI_H_
#define SOURCES_TSI_H_

// new types
#include "types.h"
#include "MK70F12.h"
#include "LEDs.h"
#include "Cpu.h"

/*! @brief Sets up the TSI before first use.
 *
 *  @return BOOL - TRUE if the TSI was successfully initialized.
 */
BOOL TSI_Init();

/*! @brief Gets the Channel Value.
 *
 *  @param channel - The desired channel to get value
 *  @return uint16_t - return the channel value.
 */
uint16_t TSI_get_channelValue(int channel);

/*! @brief Self Calibration for the touch buttons.
 *
 *  @return void
 */
void TSI_SelfCalibration();

/*! @brief Start the TSI
 *
 *  @return void
 */
void TSI_StartApplication();

/*! @brief interrupts for TSI
 *
 *  @return void
 */
void __attribute__ ((interrupt)) TSI_ISR(void);

#endif /* SOURCES_TSI_H_ */
