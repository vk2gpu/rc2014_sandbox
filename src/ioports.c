#include <stdlib.h>
#include <stdio.h>
#include <games.h>

#include "io.h"
#include "sn7689an.h"

int main(int argc, char* argv[])
{
    uint16_t i;

    psg_write_amp(0, 15);
    psg_write_amp(1, 15);
    psg_write_amp(2, 15);
    psg_write_amp(3, 15);

    psg_write_freq(0, 0);
    psg_write_freq(1, 0);
    psg_write_freq(2, 0);
    psg_write_freq(3, 0);

    psg_write_amp(0, 0);

    for(i = 0; i < 1024; ++i)
    {
        psg_write_freq(0, i);
    }

    psg_write_amp(0, 15);

    psg_write_amp(3, 0);

    for(i = 0; i < 255; ++i)
    {
        psg_write_noise(3, i);
        msleep(150);
    }

    psg_write_amp(3, 15);

    return 0;
}

