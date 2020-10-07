/*! @file TSI.c
 *
 * /*!
**  @addtogroup TSI_module TSI module documentation
**  @{
*/
/*!
 *  @brief Touch Sense Input (TSI) on the TWR-K70F120M.
 *  @date Created: 19 OCT 2015, Last edit: 19 OCT 2015.
 *  @author Anuraag Pardeshi-12029866 & Nandita Mehta-11671284
 *
 *  MODULE TSI
 */
#include "TSI.h"
static void (*GlobalFunction)(void *);
static void *GlobalArguments;


static uint16_t countChannel5, countChannel7, countChannel8, countChannel9;
static uint16_t value = 0x50;

uint16_t counterChannel_threshold[4] = {0};



BOOL TSI_Init()
{
  SIM_SCGC5 |= SIM_SCGC5_PORTB_MASK;	//! Enable PortB
  SIM_SCGC5 |= SIM_SCGC5_TSI_MASK;	//! Enable TSI
  SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;	//! Enable PortA

  //PORTA_PCR4 = PORT_PCR_MUX(0);         //! Enable ALT0 for portA pin 4
  //PORTB_PCR2 = PORT_PCR_MUX(0); 	//! Enable ALT0 for portB pin 2
  //PORTB_PCR3 = PORT_PCR_MUX(0); 	//! Enable ALT0 for portB pin 3
  //PORTB_PCR16 = PORT_PCR_MUX(0); 	//! Enable ALT0 for portB pin 16

  //Configure the number of scans and enable the interrupt
  TSI0_GENCS |= TSI_GENCS_NSCN(9);
  TSI0_GENCS |= TSI_GENCS_TSIIE_MASK;
  TSI0_GENCS |= TSI_GENCS_PS(2);
  TSI0_GENCS |= TSI_GENCS_ESOR_MASK;
  TSI0_SCANC |= TSI_SCANC_REFCHRG(15);
  TSI0_SCANC |= TSI_SCANC_EXTCHRG(8);
  TSI0_SCANC |= TSI_SCANC_SMOD(10);
  TSI0_SCANC |= TSI_SCANC_AMCLKS(0);
  TSI0_SCANC |= TSI_SCANC_AMPSC(1);
  //Enable the channels desired
  TSI0_PEN   |= (TSI_PEN_PEN5_MASK | TSI_PEN_PEN7_MASK | TSI_PEN_PEN8_MASK | TSI_PEN_PEN9_MASK);
  NVICICPR2 =  (1 << 19);		//!loads the NVIC
  NVICISER2 =  (1 << 19);
  //Enable TSI module
  TSI0_GENCS |= TSI_GENCS_TSIEN_MASK;  //Enables TSI
  return bTRUE;
}

void TSI_StartApplication(void (*userFunction)(void *), void *userArguments)
{
  TSI_Init();
  TSI_SelfCalibration();
  TSI0_GENCS |= TSI_GENCS_STM_MASK;
  TSI0_GENCS |= TSI_GENCS_TSIIE_MASK;
  TSI0_GENCS |= TSI_GENCS_TSIEN_MASK;
  GlobalFunction = userFunction;	//! assigns the callback function to the global function
  GlobalArguments = userArguments;
}

void TSI_SelfCalibration()		//! get the base values for the touch buttons and store it
{
  int Delay = 0xFFFF;
  TSI0_GENCS |= TSI_GENCS_SWTS_MASK;
  while(!(TSI0_GENCS & TSI_GENCS_EOSF_MASK))
  {

  }
  while(Delay--);
  for (int channel = 0; channel < 4; channel++)
  {
    counterChannel_threshold[channel]  = TSI_get_channelValue(channel) + value;
  }
  TSI0_GENCS &= ~TSI_GENCS_TSIEN_MASK;
}

uint16_t TSI_get_channelValue(int channel)	//! get the channel values
{
  uint32union_t channel5_4, channel7_6, channel9_8;
  channel5_4.l = TSI0_CNTR5;
  channel7_6.l = TSI0_CNTR7;
  channel9_8.l = TSI0_CNTR9;
  switch (channel)
  {
    case 0: return channel5_4.s.Hi;
      break;
    case 1: return channel7_6.s.Hi;
      break;
    case 2: return channel9_8.s.Lo;
      break;
    case 3: return channel9_8.s.Hi;
      break;
    default:
      return 0;
  }
}

uint16_t TSI_counterThreshold(int n)		//!
{
  switch(n)
  {
    case 0: return counterChannel_threshold[0]; break;
    case 1: return counterChannel_threshold[1]; break;
    case 2: return counterChannel_threshold[2]; break;
    case 3: return counterChannel_threshold[3]; break;
  }
}



void __attribute__ ((interrupt)) TSI_ISR(void)	//!
{

  TSI0_GENCS |= TSI_GENCS_EOSF_MASK;
  (*GlobalFunction)(GlobalArguments);
}


  /*! END TSI.c */
  /*! END  */
  /*!
  ** @}
  */
