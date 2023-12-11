#ifndef buzzer_included
#define buzzer_included



#define E4 659
#define D4 587
#define G4 392
#define A4 440
#define C4 523 


typedef struct {
  short key;
  unsigned short duration;
  unsigned short delay;
} Note;

void buzzer_init();
void buzzer_set_period(short cycles);

#endif
