#ifndef SN7689AN_H_
#define SN7689AN_H_

#include "io.h"

#ifndef PSG_REG
#define PSG_REG 0xc0
#endif

#ifndef PSG_CLOCK
#define PSG_CLOCK 2457000
#endif

static void psg_write_amp(uint8_t ch, uint8_t val)
{
    ch <<= 5;
    out(PSG_REG, 0b10010000 | ch | (val & 0xf));
}

static psg_write_freq(uint8_t ch, uint16_t freq)
{
    uint16_t pitch = (PSG_CLOCK / freq) / 32;
    ch <<= 5;
    out(PSG_REG, 0b10000000 | ch | (pitch & 0xf));
    out(PSG_REG, (pitch >> 4) & 0b00111111);
}

static void psg_write_noise(uint8_t ch, uint8_t freq)
{
    ch <<= 5;
    out(PSG_REG, 0b10000000 | ch | (freq & 0xf));
}

#endif // #ifndef SN7689AN_H_
