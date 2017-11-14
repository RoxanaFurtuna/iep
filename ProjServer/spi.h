#include<bcm2835.h>
#include<stdint.h>
#include<serial.h>
class Spi : public Serial
{
    public:
        Spi(uint8_t order, uint8_t mode, uint16_t divider, uint8_t cs, uint8_t active);
        uint8_t transfer(uint8_t send_data);
};
