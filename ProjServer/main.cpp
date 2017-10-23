#include<pin.h>
#include <bcm2835.h>
#include <stdio.h>
#define PIN_OUT RPI_GPIO_P1_11 //led
#define PIN_IN RPI_GPIO_P1_15 //buton
int main(int argc, char **argv)
{
    Pin *p = new Pin(PIN_IN, 0, 0);
    Pin *pp= new Pin(PIN_OUT, 1, 0);
    p->setInput();
    pp->setOutput();
    uint8_t val;
    while(1){
        pp->set(1);
        val = p->get();
        printf("read from pin 15: %d\n", val);
        delay(100);
        pp->set(0);
    }
    return 0;

}
