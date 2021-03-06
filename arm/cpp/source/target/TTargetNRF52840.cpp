/*
 *   file: TTargetNRF52840.cpp
 * author: ShpakovDmitry
 *   date: 2020-12-04
 */

#include "TTargetNRF52840.h"
#include "TCrystalOscillators.h"


void TTargetNRF52840::initSystemClock(void) {
    _systemClock.setDebounceTime(TCrystalOscillators::NX1212AA);
    _systemClock.selectHighFreqSource(TSystemClock::HighFreqSource::HFXO);
    _systemClock.selectLowFreqSource(TSystemClock::LowFreqSource::LFXO);
}

void TTargetNRF52840::initSystemIRq(void) {
    ;
}

void TTargetNRF52840::initSysTick() {
    _sysTick.setReloadPeriod(1000);
    _sysTick.setCurrentValue(0);
    _sysTick.enable();
    _sysTick.enableInterrupt();
}

void TTargetNRF52840::reset() {
    ;
}

TTargetNRF52840::TTargetNRF52840() {
    initSystemClock();
    initSystemIRq();
    initSysTick();
}
