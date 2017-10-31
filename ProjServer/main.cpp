#include<pin.h>
#include <bcm2835.h>
#include <stdio.h>
#include<pwm.h>
#define PIN_OUT RPI_GPIO_P1_11 //led
#define PIN_IN RPI_GPIO_P1_15 //buton
#define PWM_CHANNEL 0
int main(int argc, char **argv)
{
    bcm2835_set_debug(1);
    Pin *p = new Pin(PIN_IN, 0, 0);
    Pin *pp= new Pin(PIN_OUT, 1, 0);
    p->setInput();
    pp->setOutput();
    uint8_t val;

    Pwm *pw = new Pwm(1024, 1);
    int range = pw->getFrecv();
    int factor = (10 * range) / 100;
    pw->setFact(factor);

    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
    bcm2835_pwm_set_range(PWM_CHANNEL, range);

    int direction = 1; // 1 is increase, -1 is decrease
    int fact;
    while(1){
        pp->set(1);
        val = p->get();
        printf("read from pin 15: %d\n", val);

        fact = pw->getFact();
        if(fact==range){
            pw->setFact(0);
        }

        if(fact == factor)  direction=1;
        else if(fact == range-1) direction=-1;
        fact+=factor;
        pw->setFact(fact);
        bcm2835_pwm_set_data(PWM_CHANNEL, fact);

        delay(100);
        pp->set(0);
    }
    return 0;

}
