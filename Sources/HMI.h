/*
 * HMI.h
 *
 *  Created on: 20 Nov 2015
 *      Author: 12029866
 */

#ifndef SOURCES_HMI_H_
#define SOURCES_HMI_H_
#include "types.h"
#include "DEM.h"
#include "UART.h"
#include "stdlib.h"
#include "stdio.h"



BOOL Metering_Time(void);
BOOL Average_Power(void);
BOOL Total_Energy(void);
BOOL Total_Cost(void);
void HMI_Start();

#endif /* SOURCES_HMI_H_ */
