#ifdef CARDENZA_TARGET
// The precompiled SDK advertises PSRAM even when the board has none.
// Arduino probes it before setup(); stop that separate-TU call at the linker.
extern "C" bool __wrap_psramInit(void) { return false; }
#endif
