// stack definition code

// top of stack
extern unsigned __stacktop;
extern unsigned Image$$RO$$Base;

// initial stack pointer is first address of program
__attribute__((section(".stack"), used)) unsigned *__stack_init = &__stacktop;
__attribute__((section(".header"), used)) unsigned *__image_base = &Image$$RO$$Base;
