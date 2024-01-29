#include "LPC17xx.h"

void EINT2_init ()
{
	LPC_PINCON->PINSEL4|=(0x01 << 24); //To make pin2.12 as EINT2
	LPC_SC->EXTMODE|=(1<<2); 						//To make edge sensetive
	LPC_SC->EXTPOLAR|=(~(1<<2)); 				//To make falling edge 
	NVIC_SetPriority(EINT2_IRQn,1);
	NVIC_EnableIRQ(EINT2_IRQn);
}

void EINT3_init ()
{
	LPC_PINCON->PINSEL4  |= (0x01 << 26); //To make pin2.13 as EINT3
	LPC_SC->EXTMODE|=(1<<3); 						//To make edge sensetive
	LPC_SC->EXTPOLAR|=(1<<3);					  //To make rising edge 
	NVIC_SetPriority(EINT1_IRQn,1);
	NVIC_EnableIRQ(EINT1_IRQn);
}

void EINT2_IRQHandler(){
	LPC_SC->PCONP=(0<<22);			//To power off(Timer2)
	LPC_SC->EXTINT=(1<<2);    //To clear flag
}
void EINT3_IRQHandler(){
	LPC_SC->PCONP=(1<<22);       //To power on(Timer2)
	LPC_SC->EXTINT=(2);      //To clear flag
}

int main()
{
	EINT3_init();
	EINT2_init();
	while(1){}	
}