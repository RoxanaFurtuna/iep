#include<bcm2835.h>
#include<stdint.h>
class Serial
{
    public:
        virtual uint8_t transfer(uint8_t send_data) = 0;
};
