/*
 * HMI.c
 *
 *  Created on: 20 Nov 2015
 *      Author: 12029866
 */
#include "HMI.h"

char MeteringTime[7];
int state = 1;
char Print_Out[80];
int TimeOut = 0;

void HMI_Start()
{
  TimeOut++;
  if(TimeOut>5)
    state = 0;
  switch (state)
  {
    case 0:
    break;
    case 1:
      Metering_Time();
    break;
    case 2:
      Average_Power();
    break;
    case 3:
      Total_Energy();
    break;
    case 4:
      Total_Cost();
    break;
    default:
    break;
  }
}

BOOL Metering_Time(void)
{
  char *returned_str = DEM_Metered();
  MeteringTime[0] = returned_str[0];
  MeteringTime[1] = returned_str[1];
  MeteringTime[2] = returned_str[2];
  MeteringTime[3] = returned_str[3];
  if(MeteringTime[0] >= 100)
    sprintf( Print_Out, "%n Metering Time: xx:xx:xx:xx");
  else
    sprintf( Print_Out, "/nMetering Time: %d:%d:%d:%d", MeteringTime[0], MeteringTime[1], MeteringTime[2], MeteringTime[3]);
  free(returned_str);
  UART_OutStr(Print_Out);
return bTRUE;
}

BOOL Average_Power(void)
{
  char *returned_str = DEM_Metered();
    MeteringTime[0] = returned_str[0];
    sprintf( Print_Out, "%n Average Power: %d", MeteringTime[0]);
    free(returned_str);
    UART_OutStr(Print_Out);
  return bTRUE;
}

BOOL Total_Energy(void)
{
  char *returned_str = DEM_Metered();
      MeteringTime[0] = returned_str[0];
      sprintf( Print_Out, "%n Total Energy: %d", MeteringTime[0]);
      free(returned_str);
      UART_OutStr(Print_Out);
    return bTRUE;
}

BOOL Total_Cost(void)
{
  char *returned_str = DEM_Metered();
      MeteringTime[0] = returned_str[0];
      MeteringTime[1] = returned_str[1];
      sprintf( Print_Out, "%n Total Cost: $%d.%d", MeteringTime[0], MeteringTime[1]);
      free(returned_str);
      UART_OutStr(Print_Out);
    return bTRUE;
}

void HMI_Plus()
{
  TimeOut = 0;
  state++;
  if(state >= 5)
    state = 1;
}

void HMI_zero()
{
  state = 0;
}
