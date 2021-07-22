#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>
modbusDevice regBank;
modbusSlave slave;

unsigned long count=0;
unsigned long current = 0;

void setup(){
  regBank.setId(1);
  regBank.add(40001);
  regBank.add(40002);
  slave._device = &regBank;
  slave.setBaud(9600);
  pinMode(13,OUTPUT);   
}

void loop(){
    regBank.set(40001, (word) count);
    int a = regBank.get(40002);
    if(a){
      digitalWrite(13,HIGH);
    }
    else digitalWrite(13,LOW); 
    
    slave.run();
    if(millis()-current > 1000){
      count++;
      current = millis();
    }
}
