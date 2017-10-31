#include<pwm.h>
#include <stdio.h>
Pwm::Pwm(int frecv, int fact)
{
    this->frecv = frecv;
    this->fact = fact;
}
Pwm::~Pwm(void){

}
void Pwm::setFrecv(int frecv){
    this->frecv = frecv;
}
void Pwm::setFact(int fact){
    this->fact = fact;
}
int Pwm::getFrecv(){
    return this->frecv;
}
int Pwm::getFact(){
    return this->fact;
}
