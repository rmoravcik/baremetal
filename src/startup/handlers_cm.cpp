/**
 * Handlers setup code for Cortex-M.
 */

extern unsigned Image$$RO$$Base;
extern unsigned Image$$RO$$Limit;
extern unsigned __stacktop;
unsigned *__stack_init2 = &__stacktop;

typedef void (*ptr_func_t)();

// Undefined handler is pointing to this function, this stop MCU.
// This function name must by not mangled, so must be C,
// because alias("..") is working only with C code
extern "C" void __stop() { while (true); }

// Handlers for Cortex-M core.
// These handler are with attribute 'weak' and can be overwritten
// by non-week function, default is __stop() function
__attribute__((weak, alias("__stop"))) void RESET_handler();
__attribute__((weak, alias("__stop"))) void NMI_handler();
__attribute__((weak, alias("__stop"))) void HARDFAULT_handler();
__attribute__((weak, alias("__stop"))) void MEMMANAGE_handler();
__attribute__((weak, alias("__stop"))) void BUSFAULT_handler();
__attribute__((weak, alias("__stop"))) void USAGEFAULT_handler();
__attribute__((weak, alias("__stop"))) void SVCALL_handler();
__attribute__((weak, alias("__stop"))) void DEBUGMONITOR_handler();
__attribute__((weak, alias("__stop"))) void PENDSV_handler();
__attribute__((weak, alias("__stop"))) void SYSTICK_handler();

// Dummy handler (for unused vectors)
__attribute__((weak, alias("__stop"))) void DUMMY_handler();

// Vector table for handlers
// This array will be placed in ".vectors" section defined in linker script.
__attribute__((section("VECTORS"), used)) ptr_func_t __isr_vectors[] = {
    RESET_handler,
    NMI_handler,
    HARDFAULT_handler,
    MEMMANAGE_handler,
    BUSFAULT_handler,
    USAGEFAULT_handler,
    DUMMY_handler,
    DUMMY_handler,
    DUMMY_handler,
    DUMMY_handler,
    SVCALL_handler,
    DEBUGMONITOR_handler,
    DUMMY_handler,
    PENDSV_handler,
    SYSTICK_handler,
};

unsigned *header[] __attribute__((section("HEADER"), used)) = {
    reinterpret_cast<unsigned*> (0x44512000),
    &Image$$RO$$Base,
    &Image$$RO$$Limit,
//    __stacktop,
//    reinterpret_cast<unsigned> (__stack_init2),
    reinterpret_cast<unsigned*> (0xcafecafe),
    reinterpret_cast<unsigned*> (0),
    reinterpret_cast<unsigned*> (0),
    reinterpret_cast<unsigned*> (0),
};