#include <DS1302.h>
#include <stdio.h>

const int CLK = 12;
const int DAT = 11;
const int RST = 10;

DS1302 rtc(RST, DAT, CLK);

String dayAsString(const Time::Day day){
  switch(day){
    case Time::kSunday: return "Sunday";
    case Time::kMonday: return "Monday";
    case Time::kTuesday: return "Tuesday";
    case Time::kWednesday: return "Wednesday";
    case Time::kThursday: return "Thursday";
    case Time::kFriday: return "Friday";
    case Time::kSaturday: return "Saturday";
  }
  return "(unknown day)";
}

void printTime(){
  Time t = rtc.time();
  const String day = dayAsString(t.day);

  char buf[50];
  snprintf(buf, sizeof(buf), "%04d-%02d-%02d  %02d:%02d:%02d %s", t.yr, t.mon, t.date, t.hr, t.min, t.sec, day.c_str());
  Serial.println(buf);
}

void setup() {
  Serial.begin(9600);
  rtc.halt(false);
  rtc.writeProtect(false);

  Time t(2021, 7, 21, 13, 19, 00, Time::kWednesday);
  rtc.time(t);
}

void loop() {
  printTime();
  delay(1000);

}
