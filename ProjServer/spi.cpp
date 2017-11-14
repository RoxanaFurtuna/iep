#include<spi.h>
#include<bcm2835.h>
Spi::Spi(uint8_t order, uint8_t mode, uint16_t divider, uint8_t cs, uint8_t active){
    bcm2835_spi_setBitOrder(order);
    bcm2835_spi_setDataMode(mode);
    bcm2835_spi_setClockDivider(divider);
    bcm2835_spi_chipSelect(cs);
    bcm2835_spi_setChipSelectPolarity(cs, active);
}
uint8_t Spi::transfer(uint8_t send_data){
    return bcm2835_spi_transfer(send_data);
}
