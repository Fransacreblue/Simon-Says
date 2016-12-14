#pragma config CP=OFF,OSC=RC,WDT=OFFLINE
#device 16F877A
#include <xc.h>
#include "rand.h"
#include "main.h"

unsigned char sequence[MAXSEQ >> 2];
struct {
  unsigned char len : 4;
  unsigned char   l : 1;
  unsigned char   r : 1;
  unsigned char   t : 1;
  unsigned char   b : 1;
} buttons;

int main(void)
{
  // configurar como entrada y salida
  PORTA = 0x00;
  TRISA = ACONF;
  PORTB = 0x00;
  TRISB = BCONF;

  srand(SEED);

  buttons.len = 0;
  while(1) {
    if(buttons.len == MAXSEQ-1) {
      win();
    restart:
      buttons.len = 0;
    }
    unsigned char num = rand() >> 6;
    SET2(sequence[buttons.len >> 2], buttons.len, num);
    ++buttons.len;
    for(unsigned char i=0;i<buttons.len;++i) {
      switch(GET2(sequence[i >> 2], i&3)) {
      case 0:
	LED_L = 1;
	break;
      case 1:
	LED_R = 1;
	break;
      case 2:
	LED_T = 1;
	break;
      case 3:
	LED_B = 1;
	break;
      }
      _delay_ms(200);
      // función cuando los 4 leds  están en el mismo Puerto
      PORTB = 0x00;
      _delay_ms(200);
    }
    unsigned char pos = 0;
    while(pos < buttons.len) {
      unsigned char left = BUT_L;
      if(buttons.l && !left) {
	if(GET2(sequence[pos >> 2], pos&3) != 0) {
	  fail();
	  goto restart;
	}
	++pos;
      }
      buttons.l = left;
      unsigned char right = BUT_R;
      if(buttons.r && !right) {
	if(GET2(sequence[pos >> 2], pos&3) != 1) {
	  fail();
	  goto restart;
	}
	++pos;
      }
      buttons.r = right;
      unsigned char top = BUT_T;
      if(buttons.t && !top) {
	if(GET2(sequence[pos >> 2], pos&3) != 2) {
	  fail();
	  goto restart;
	}
	++pos;
      }
      buttons.t = top;
      unsigned char bot = BUT_B;
      if(buttons.b && !bot) {
	if(GET2(sequence[pos >> 2], pos&3) != 3) {
	  fail();
	  goto restart;
	}
	++pos;
      }
      buttons.b = bot;
    }
  }
}

void fail(void)
{
  ;
}

void win(void)
{
  ;
}
