#include <msp430.h>
#include "buzzer.h"
#include "jingleStateMachine.h"
#include <msp430.h>
#include "buzzer.h"

static char play_sound;
static int note;
static int delay;

static const Note jingle_bells_simple[] = {
    {E4, 500, 4},
    {E4, 500, 4},
    {E4, 1000, 4},
    {E4, 500, 4},
    {E4, 500, 4},
    {E4, 1000, 4},
    {E4, 500, 4},
    {G4, 500, 4},
    {D4, 1000, 4},
    {C4, 500, 4},
    {C4, 500, 4},
    {C4, 500, 4},
    {C4, 500, 4},
    {C4, 1000, 4},
    {C4, 500, 4},
    {D4, 500, 4},
    {E4, 1000, 4},
};

void play_jingle_bells()
{
    if (note < sizeof(jingle_bells_simple) / sizeof(jingle_bells_simple[0]))
    {
        if (delay <= 0)
        {
            if (play_sound)
            {
                play_sound = 0;
                buzzer_set_period(0);
                delay = jingle_bells_simple[note].delay;
                note++;
            }
            else
            {
                play_sound = 1;
                buzzer_set_period(jingle_bells_simple[note].key);
                delay = jingle_bells_simple[note].duration;
            }
        }
        delay--;
    }
    else
    {
        note = 0;
        delay = 0;
        play_sound = 0;
        buzzer_set_period(0);
    }
}

void reset_jingle_bells()
{
    play_sound = 0;
    note = 0;
    delay = 0;

    buzzer_set_period(0);
}
