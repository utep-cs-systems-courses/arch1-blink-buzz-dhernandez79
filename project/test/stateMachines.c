#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"

//static int song_state = 0;


char toggle_red()/* always toggle! */
{
  static char state = 0;
  
  switch (state) {
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }
  return 1;/* always changes an led */
}

char toggle_green()/* only toggle green if red is on!  */
{
  char changed = 0;
  if (red_on) {
    green_on ^= 1;
    changed = 1;
  }
  return changed;
}

void state_advance()/* alternate between toggling red & green */
{
  char changed = 0;
  
  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }

  led_changed = changed;
  led_update();
}

void red_light_on() {
  red_on = 1;
  green_on = 0;
  led_update();
}

void green_light_on() {
  green_on = 1;
  red_on = 0;
  led_update();
}

/* plays police siren/flashing lights */
void play_police() {
  static int cops_note = 0;

  switch(cops_note) {
  case 0:
    buzzer_set_period(1318);
    green_light_on();
    cops_note++;
    break;
  case 1:
    buzzer_set_period(1479);
    red_light_on();
    cops_note++;
    break;
  default:
    cops_note = 0;
  }//end switch

  
}//end jaws


/* plays twinkle twinkle little star */
void play_twinkle() {
  static int curr_beat = 0;

  switch(curr_beat) {
  case 0:
    buzzer_set_period(783); //plays G6
    curr_beat++;
    break;
  case 1:
    buzzer_set_period(0);
    curr_beat++;
    break;
  case 2:
    buzzer_set_period(783); //plays G6
    curr_beat++;
    break;
  case 3:
    buzzer_set_period(783); // plays G6
    curr_beat++;
    break;
  case 4:
    buzzer_set_period(1174); //plays D7
    curr_beat++;
    break;
  case 5:
    buzzer_set_period(0);
    curr_beat++;
    break;
  case 6:
    buzzer_set_period(1174); //plays D7
    curr_beat++;
    break;
  case 7:
    buzzer_set_period(1174); //plays D7
    curr_beat++;
    break;
  case 8:
    buzzer_set_period(1318); //plays E7
    curr_beat++;
    break;
  case 9:
    buzzer_set_period(0);
    curr_beat++;
    break;
  case 10:
    buzzer_set_period(1318); //plays E7
    curr_beat++;
    break;
  case 11:
    buzzer_set_period(1318); //plays E7
      curr_beat++;
    break;
  case 12:
    buzzer_set_period(1174); //plays D7
    curr_beat++;
    break;
  case 13:
    buzzer_set_period(1174); //plays D7
    curr_beat++;
    break;
  case 14:
    buzzer_set_period(0);
    curr_beat++;
    break;
  case 15:
    buzzer_set_period(1046); //plays c7
    curr_beat++;
    break;
  case 16:
    buzzer_set_period(0);
    curr_beat++;
    break;
  case 17:
    buzzer_set_period(1046); //plays c7
    curr_beat++;
    break;
  case 18:
    buzzer_set_period(1046); //plays c7
    curr_beat++;
    break;
  case 19:
    buzzer_set_period(987); //plays b6
    curr_beat++;
    break;
  case 20:
    buzzer_set_period(0);
    curr_beat++;
    break;
  case 21:
    buzzer_set_period(987); //plays b6
    curr_beat++;
    break;
  case 22:
    buzzer_set_period(987); //plays b6
    curr_beat++;
    break;
  case 23:
    buzzer_set_period(880); //plays a6
    curr_beat++;
    break;
  case 24:
    buzzer_set_period(0);
    curr_beat++;
    break;
  case 25:
    buzzer_set_period(880); //plays a6
    curr_beat++;
    break;
  case 26:
    buzzer_set_period(880); //plays a6
    curr_beat++;
    break;
  case 27:
    buzzer_set_period(783); //plays g6
    curr_beat++;
    break;
  case 28:
    buzzer_set_period(783); //plays g6
    curr_beat++;
    break;
  case 29:
    buzzer_set_period(0);
    curr_beat++;
    break;
  case 30:
    buzzer_set_period(0);
    curr_beat++;
    break;
  default:
      curr_beat = 0;
  }//end switch

  

}//end play_song method

