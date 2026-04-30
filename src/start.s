        .global start, stack_top // stack_top defined in t.ld
start:
        ldr sp, =stack_top // set SVC mode stack pointer
        bl tomato // call tomato() in C
        b . // if tomato() returns, just loop
        