#include "Laser.h"

Laser::Laser(float x_pos,float y_pos,EntityID id, int speed):
		Entity(x_pos,y_pos,id)
		,speed_(speed)
{
}
		

void Laser::move(){
	
        if(auto y_positon = position()->getYPosition(); y_position > Constants::LASER_HEIGHT_)
            position()->setYPosition(y_position-getSpeed())
        else
            destroy();
}

