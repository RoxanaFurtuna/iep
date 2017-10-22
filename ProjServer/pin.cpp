#include<pin.h>
#include <bcm2835.h>
#include <stdio.h>
#define PIN_NR RPI_GPIO_P1_11
Pin::Pin(uint8_t n,int d,int st)
{
    this->nr = n;
    this->dir = d;
    this->state = st;
}
Pin::~Pin(void){

}
void Pin::set(){
    if(this->dir == 0 && this->state == 0)
        bcm2835_gpio_write(this->nr, LOW);
    else
        if(this->dir == 0 && this->state == 1)
            bcm2835_gpio_write(this->nr, HIGH);
}
uint8_t Pin::get(){
    return bcm2835_gpio_lev(this->nr);
}
void Pin::changeDir(){
    if(this->dir == 0)
        this->dir = 1;
    else
        this->dir = 0;
}
int main(int argc, char **argv)
{
    Pin p = Pin(PIN_NR, 0, 0);
    while(1){
        p.set();
        uint8_t val = p.get();
        printf("read from pin 11: %d\n", val);
        p.changeDir();
        delay(100);
    }
    return 0;

}
