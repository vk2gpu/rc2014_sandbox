#ifndef IO_H_
#define IO_H_

static void out(uint8_t port, uint8_t value) __naked
{
#asm
        pop     af
        pop     de      ;e = value
        pop     bc      ;c = port
        out (c), e
        push    bc
        push    de
        push    af
end:
        ret
#endasm
}

#endif // #ifndef IO_H_
