/*! @file DEM.c
 *
 * /*!
**  @addtogroup DEM_module DEM module documentation
**  @{
*/
/*!
 *  @brief  (DEM) on the TWR-K70F120M.
 *  @date Created: 17 NOV 2015, Last edit: 19 NOV 2015.
 *  @author Anuraag Pardeshi-12029866
 *
 *  MODULE DEM
 */
#include "DEM.h"

uint8_t  DEM_MeteredDays;
uint8_t  DEM_MeteredHours;
uint8_t  DEM_MeteredMinutes;
uint8_t  DEM_MeteredSeconds;

uint8_t DEM_TestMode;

uint16_t DEM_AveragePower;
uint16_t DEM_Energy;
uint16_t DEM_Cost_Dollars;
uint16_t  DEM_Cost_Cents;

uint16_t* Non_ToU2 = (uint16_t*)0x80004;
uint16_t* Non_ToU3 = (uint16_t*)0x80006;
uint16_t* ToU_Peak = (uint16_t*)0x80008;
uint16_t* ToU_Shoulder = (uint16_t*)0x80010;
uint16_t* ToU_Off_Peak = (uint16_t*)0x80012;
uint16_t* DEM_Mode = (uint16_t*)0x80014;
//char string[7];
//char *stringPtr;



BOOL DEM_Int()
{
  RTC_Get(&DEM_MeteredHours,&DEM_MeteredMinutes,&DEM_MeteredSeconds);
  DEM_MeteredDays    = 0;

  DEM_AveragePower = 0;
  DEM_Energy = 0;
  DEM_Cost_Dollars = 0;
  DEM_Cost_Cents = 0;

  // Test mode is initially OFF (FALSE)
  DEM_TestMode = 0;

  if (*DEM_Mode == 0xFFFF)
      Tariff_Set();
  return bTRUE;
}

char *DEM_Metered()
{
  char *string= malloc(7);
  if(!string)
     return NULL;
  RTC_Get(&DEM_MeteredHours,&DEM_MeteredMinutes,&DEM_MeteredSeconds);
  string[0] = (char) DEM_MeteredDays;
  string[1] = (char) DEM_MeteredHours;
  string[2] = (char) DEM_MeteredMinutes;
  string[3] = (char) DEM_MeteredSeconds;
  //stringPtr = string;

  return string;
}

void * DEM_AvP()
{
  char *string= malloc(7);
    if(!string)
       return NULL;
  string[0] = (char) DEM_AveragePower;
  return string;
}

void * DEM_Energy1()
{
  char *string= malloc(7);
    if(!string)
       return NULL;
  string[0] = (char) DEM_Energy;
  return string;
}

void * DEM_Cost()
{
  char *string= malloc(7);
    if(!string)
       return NULL;
  string[0] = (char) DEM_Cost_Dollars;
  string[1] = (char) DEM_Cost_Cents;
  return string;
}

BOOL Tariff_Set()
{
  Flash_Write16(DEM_Mode, 1);
  Flash_Write16(Non_ToU2, 3508);
  Flash_Write16(Non_ToU3, 8397);
  Flash_Write16(ToU_Peak, 45537);
  Flash_Write16(ToU_Shoulder, 9011);
  Flash_Write16(ToU_Off_Peak, 4319);
  return bTRUE;
}

void DEM_Test(uint8_t test)
{
  DEM_TestMode = test;
}

void DEM_Tariff(uint8_t tariff)
{
   DEM_Mode = tariff;
}
void DEM_Time1(uint8_t seconds, uint8_t minutes)
{
  RTC_Get(&DEM_MeteredHours,&DEM_MeteredMinutes,&DEM_MeteredSeconds);
  RTC_Set(DEM_MeteredHours, minutes, seconds);
}

void DEM_Time2(uint8_t hours, uint8_t days)
{
  RTC_Get(&DEM_MeteredHours,&DEM_MeteredMinutes,&DEM_MeteredSeconds);
  RTC_Set(hours, DEM_MeteredMinutes, DEM_MeteredSeconds);
}
void DEM_Power(uint8_t hours, uint8_t days)
{

}
void DEM_Energy_Pro(uint8_t hours, uint8_t days)
{

}
void DEM_Cost_Pro(uint8_t hours, uint8_t days)
{

}
void DEM_Frequency(uint8_t hours, uint8_t days)
{

}
void DEM_Voltage(uint8_t hours, uint8_t days)
{

}
void DEM_Current(uint8_t hours, uint8_t days)
{

}
void DEM_Power_Factor(uint8_t hours, uint8_t days)
{

}
