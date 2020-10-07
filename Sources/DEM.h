/*
 * DEM.h
 *
 *  Created on: 19 Oct 2015
 *      Author: 12029866
 */

#ifndef SOURCES_DEM_H_
#define SOURCES_DEM_H_

// new types
#include "types.h"
#include "Cpu.h"
#include "Flash.h"
#include <string.h>
#include "UART.h"
#include "RTC.h"
#include "stdlib.h"


/*! @brief Sets up the DEM before first use.
 *
 *  @return BOOL - TRUE if the DEM was successfully initialized.
 */
BOOL DEM_Int();

char * DEM_Metered();
void * DEM_AvP();
void * DEM_Energy1();
void * DEM_Cost();
BOOL Tariff_Set();
void DEM_Test(uint8_t test);

void DEM_Tariff(uint8_t tariff);
void DEM_Time1(uint8_t seconds, uint8_t minutes);
void DEM_Time2(uint8_t hours, uint8_t days);
void DEM_Power(uint8_t hours, uint8_t days);
void DEM_Energy_Pro(uint8_t hours, uint8_t days);
void DEM_Cost_Pro(uint8_t hours, uint8_t days);
void DEM_Frequency(uint8_t hours, uint8_t days);
void DEM_Voltage(uint8_t hours, uint8_t days);
void DEM_Current(uint8_t hours, uint8_t days);
void DEM_Power_Factor(uint8_t hours, uint8_t days);

#endif /* SOURCES_DEM_H_ */
