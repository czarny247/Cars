#include "Car.hpp"
#include <iostream>
#include "Exceptions.hpp"


void Car::turnLeft()         { std::cout << __FUNCTION__ << std::endl; }
void Car::turnRight()  	     { std::cout << __FUNCTION__ << std::endl; }
void Car::brake()           
{ 
    std::cout << __FUNCTION__ << std::endl; 
    velocity = 0;
} 
void Car::accelerateErr()            { std::cout << __FUNCTION__ << std::endl; }
void Car::accelerate(int speed)
{ 
    if (speed < 0)
        accelerateErr();
    else    
    {
        std::cout << __FUNCTION__ << std::endl; 
        velocity += speed;
    }
}
void Car::changeGear(int gear)
{
    if(currentGear == gear)
    {
        return;
    }
    
    try
    {
        if( currentGear > 0 && gear == -1 )
            throw InvalidGear();
        currentGear = gear;
        std::cout << "Current gear: " << currentGear << std::endl;
    }
    catch (InvalidGear &error)
    {
        std::cout << error.what() << std::endl;
    }

}
