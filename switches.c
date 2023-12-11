#include <msp430.h>
#include "switches.h"
#include "stateMachine.h"

#include "led.h"
#include "buzzer.h"


static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);                          /* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);                         /* if switch down, sense up */
  return p2val;
}

/* setup switch */
void switch_init()
{  
  P2REN |= SWITCHES;                                    /* enables resistors for switches */
  P2IE |= SWITCHES;                                     /* enable interrupts from switches */
  P2OUT |= SWITCHES;                                    /* pull-ups for switches */
  P2DIR &= ~SWITCHES;                                   /* set switches' bits for input */
  
  switch_update_interrupt_sense();
}

void switch_interrupt_handler()
{
    char p2val = switch_update_interrupt_sense();
    if (!(p2val & SW1)) {
        set_state(ALTERNATING);                           // Turn on LED_RED when SW1 is pressed    
    } else if (!(p2val & SW2)) {
        set_state(BLINKING);                          // Turn on LED_GREEN when SW2 is pressed
    } else if (!(p2val & SW3)) {
        set_state(JINGLE);                          // Turn on LED_GREEN when SW2 is pressed
    } 

}








