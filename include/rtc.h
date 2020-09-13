#ifndef RTC_H
#define RTC_H

typedef enum { RTC_0 = 0, RTC_1, RTC_2 } RtcModule;

void startCounterRtc(RtcModule rtcModule);
void stopCounterRtc(RtcModule rtcModule);
void clearCounterRtc(RtcModule rtcModule);
void setTrigOvrFlw(RtcModule rtcModule);

bool eventTickRtc(RtcModule rtcModule);
bool eventOvrflwRtc(RtcModule rtcModule);

#endif  // RTC_H