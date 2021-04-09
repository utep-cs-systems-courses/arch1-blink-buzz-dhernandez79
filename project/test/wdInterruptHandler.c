#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

char button_state = 0;

void
__interrupt_vec(WDT_VECTOR) WDT(){/* 250 interrupts/sec */
  static char blink_count = 0;
  
  if (++blink_count == 125 && button_state == 0) {
    state_advance();
    blink_count = 0;
    buzzer_set_period(1000);
  }
  else if (++blink_count == 0 && button_state == 1) {
    play_police(); //plays police siren
    blink_count = 0;
  }
  else if (++blink_count == 0 && button_state == 2) {
    play_twinkle();//plays twinkle twinkle little star
    blink_count++;
  }
  //if last button is pressed it will freeze on the current state
  



  
}
