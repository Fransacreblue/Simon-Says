#define LED_L RB0
#define LED_R RB3
#define LED_T RB1
#define LED_B RB2
#define BUT_L RB4
#define BUT_R RA1
#define BUT_T RB5
#define BUT_B RA0

#define ACONF 0xFF
#define BCONF 0x0F

// this can only be from one to sixteen
#define MAXSEQ 16
#define SEED 0x42

#define _delay_ms(ms) _delay(ms * 1000)
#define GET2(val, i) ((val >> (i << 1)) & 3)
#define SET2(val1, i, val2) (val1 |= (3 << (i << 1))); (val1 &= (val2 << (i << 1)))

int main(void);
void fail(void);
void win(void);
