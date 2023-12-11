#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

int main(void) {
    configureClocks();
    enableWDTInterrupts();
    switch_init();
    led_init();
    buzzer_init();
    
    //switch_interrupt_handler();

    or_sr(0x18);
}



