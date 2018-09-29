#include "Laser.h"

Laser::Laser(float x_pos,float y_pos,EntityID id, float speed):
		Entity(x_pos,y_pos,id)
		,speed_(speed)
{
	if (speed <= 0)
		throw NegativeZeroLaserSpeed();
}
		

void Laser::move(){
	
        if(auto y_position = position()->getYPosition(); y_position > Constants::LASER_HEIGHT_)
            position()->setYPosition(y_position-getSpeed());
        else
            destroy();
}

float Laser::getSpeed()const{
	return speed_;
}

