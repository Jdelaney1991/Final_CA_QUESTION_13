#include "mbed.h"
// Include the header for PinNames
#include "PinNames.h"
DigitalOut myled(LED1);
// Use USBTX and USBRX for the onboard ST-LINK Virtual COM port
Serial pc(USBTX, USBRX);
// Use D1 and D0 for serial communication
Serial dev (P_9, P_10); //Corrected pinout 
void dev_recv() {
    while 
        if(dev.readable()) {
        pc.putc(dev.getc());
    }
}
 
void pc_recv() {
    while 
      if (pc.readable()){  
        dev.putc(pc.getc()); //missing c
    }
    }

int main() {
     while (1) { // While loop 
    pc.baud(9600); // baud rate
    dev.baud(9600); // the  variable name was changed  from "device1" to "dev" 
    pc.attach(&pc_recv);
    dev.attach(&dev_recv); // "attach"
    pc.printf("Hello!! \r\n");
 
    myled = 1;
    thread_sleep_for(1000); //  "wait" - "thread_sleep_for"
    myled = 0;
    thread_sleep_for(1000); //  "wait" - "thread_sleep_for"
    }
}