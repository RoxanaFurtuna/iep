#include<bcm2835.h>
#include<stdint.h>
class Pin
{
    public:
        Pin(uint8_t n,int d,int st);
        ~Pin(void);
        uint8_t nr;
        int dir;
        int state;
        void set();
        uint8_t get();
        void changeDir();
};
