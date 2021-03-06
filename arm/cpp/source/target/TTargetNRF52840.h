/*
 *   file: TTargetNRF52840.h
 * author: ShpakovDmitry
 *   date: 2020-12-04
 */

#ifndef T_TARGET_NRF52840_H
#define T_TARGET_NRF52840_H

#include "TSystemClock.h"
#include "TNvic.h"
#include "TSysTick.h"

class TTargetNRF52840 {
public:
    void reset();
    void initSystemClock();
    void initSystemIRq();
    void initSysTick();
    TTargetNRF52840();
    ~TTargetNRF52840() { reset(); }
private:
    TSystemClock _systemClock;
    TNvic _nvic;
    TSysTick _sysTick;
};

#endif  // T_TARGET_NRF52840_H
