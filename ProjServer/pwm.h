#include<bcm2835.h>
#include<stdint.h>
class Pwm
{
    private:
        int frecv; //frecventa
        int fact; //factor de umpler
    public:
        Pwm(int frecv, int fact);
        ~Pwm();
        void setFrecv(int frecv);
        void setFact(int fact);
        int getFrecv();
        int getFact();
};
