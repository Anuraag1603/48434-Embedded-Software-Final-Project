/*! @file Game.c
 *
 * /*!
**  @addtogroup Game_module Game module documentation
**  @{
*/
/*!
 *  @brief Simon game (Game) on the TWR-K70F120M.
 *  @date Created: 26 OCT 2015, Last edit: 28 OCT 2015.
 *  @author Anuraag Pardeshi-12029866 & Nandita Mehta-11671284
 *
 *  MODULE Game
 */

#include "Game.h"
#include "LEDs.h"


void Touch_Toggle()
{
  switch (TSI_Number())
  {
  case 1:LEDs_Toggle(LED_ORANGE);
    break;
  case 2:LEDs_Toggle(LED_YELLOW);
    break;
  case 3:LEDs_Toggle(LED_GREEN);
    break;
  case 4:LEDs_Toggle(LED_BLUE);
    break;
  default:
    break;
  }
}
void Memory_Game()
{
  Sort_Numbers();		//! sort 32 bit random numbers into 1, 2, 3 or 4.
  for (int i=0; i<32; i++)	//! Run 32 times (32 levels)
    {
	  Blink(Random_Num[i]);
    }

}

void Sort_Numbers()
{
  for (int i=0; i<32; i++)  // sort the array into 1, 2, 3, or 4
      {
        Random_Num[i] = RNG_Get();
        if (Random_Num[i] <= 0x40000000)
          Random_Num[i] = 1;
	if (Random_Num[i] > 0x40000000 && Random_Num[i] <= 0x80000000 )
	  Random_Num[i] = 2;
	if (Random_Num[i] > 0x80000000 && Random_Num[i] <= 0xC0000000 )
	  Random_Num[i] = 3;
	if (Random_Num[i] > 0xC0000000)
	  Random_Num[i] = 4;
      }
}

void Blink(int LED_Nub)
{
  switch (LED_Nub)		// blink the appropriate LED
    {
    case 1:LEDs_On(LED_ORANGE);
      delay(1000);
      LEDs_Off(LED_ORANGE);
      break;
    case 2:LEDs_On(LED_YELLOW);
      delay(1000);
      LEDs_Off(LED_YELLOW);
      break;
    case 3:LEDs_On(LED_GREEN);
      delay(1000);
      LEDs_Off(LED_GREEN);
      break;
    case 4:LEDs_On(LED_BLUE);
      delay(1000);
      LEDs_Off(LED_BLUE);
      break;
    default:
      break;
    }
}

void delay (int i)		// delay
{
  for (int j=0; j<(i*10000); j++)
    {

    }
}
