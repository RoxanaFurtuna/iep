#include<pin.h>
#include <bcm2835.h>
#include <stdio.h>
#define PIN_OUT RPI_GPIO_P1_11 //led
#define PIN_IN RPI_GPIO_P1_15 //buton
Pin::Pin(uint8_t n,int d, int st)
{
    this->nr = n;
    this->dir = d;
    this->state = st;
}
Pin::~Pin(void){

}
void Pin::set(int st){
    if(this->dir == 1 && st == 0){
        bcm2835_gpio_write(this->nr, LOW);
        this->state = 0;
    }
    else
        if(this->dir == 1 && st == 1){
            bcm2835_gpio_write(this->nr, HIGH);
            this->state = 1;
        }
}
uint8_t Pin::get(){
    if(this->dir == 0)
     return bcm2835_gpio_lev(this->nr);
    return -1;
}
void Pin::changeDir(){
    if(this->dir == 0){
        this->dir = 1;
        this->setOutput();
    }
    else{
        this->dir = 0;
        this->setInput();
    }
}
void Pin::setInput(){
     this->dir = 0;
     bcm2835_gpio_fsel(PIN_IN, BCM2835_GPIO_FSEL_INPT);
     bcm2835_gpio_set_pud(PIN_IN, BCM2835_GPIO_PUD_UP);
}
void Pin::setOutput(){
    this->dir = 1;
    bcm2835_gpio_fsel(PIN_OUT, BCM2835_GPIO_FSEL_OUTP);
}

