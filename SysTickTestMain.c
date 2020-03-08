

// PF2 is an output for debugging

#include "SysTick.h"
#include "PLL.h"

#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define SYSCTL_RCGC2_R          (*((volatile unsigned long *)0x400FE108))
#define SYSCTL_RCGC2_GPIOF      0x00000020  // port F Clock Gating Control

int main(void){
   SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; // activate port F
  PLL_Init();               // set system clock to 50 MHz
  SysTick_Init();           // initialize SysTick timer
  GPIO_PORTF_DIR_R |= 0x0e; // make PF2 out (built-in blue LED)
  GPIO_PORTF_AFSEL_R &= ~0x0e;// disable alt funct on PF2
  GPIO_PORTF_DEN_R |= 0x0e; // enable digital I/O on PF2
                            // configure PF2 as GPIO
  GPIO_PORTF_PCTL_R = (GPIO_PORTF_PCTL_R&0xFFFFF0FF)+0x00000000;
  GPIO_PORTF_AMSEL_R = 0;   // disable analog functionality on PF  
  GPIO_PORTF_DATA_R=0;
	while(1){
     GPIO_PORTF_DATA_R=0;
		SysTick_Wait10ms(30);
    GPIO_PORTF_DATA_R= 0x02; // toggle PF2
     SysTick_Wait10ms(30);    // approximately 10 ms
		 GPIO_PORTF_DATA_R= 0x04; // toggle PF2
     SysTick_Wait10ms(30);    // approximately 10 ms
		 GPIO_PORTF_DATA_R= 0x06; // toggle PF2
     SysTick_Wait10ms(30);    // approximately 10 ms
		 GPIO_PORTF_DATA_R= 0x08; // toggle PF2
     SysTick_Wait10ms(30);    // approximately 10 ms
		 GPIO_PORTF_DATA_R= 0x0A; // toggle PF2
     SysTick_Wait10ms(30);    // approximately 10 ms
		 GPIO_PORTF_DATA_R= 0x0c; // toggle PF2
     SysTick_Wait10ms(30);    // approximately 10 ms
		 GPIO_PORTF_DATA_R= 0x0E; // toggle PF2
     SysTick_Wait10ms(30);    // approximately 10 ms
		 
  }
}
