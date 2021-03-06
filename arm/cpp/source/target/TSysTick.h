/*
 *   file: TSysTick.h
 * author: ShpakovDmitry
 *   date: 2020-12-14
 */

#ifndef T_SYSTICK_H
#define T_SYSTICK_H

#include <cstdint>

class TSysTick {
public:
    bool setReloadPeriod(uint32_t periodMicroSec);
    bool setCurrentValue(uint32_t value);
    void enable(void);
    void disable(void);
    bool isEnabled(void);
    void enableInterrupt(void);
    void disableInterrupt(void);
    bool isInterruptEnabled(void);
    void setInterruptCallback(void (*cb)(void));
private:
};

#endif  // T_SYSTICK_H
