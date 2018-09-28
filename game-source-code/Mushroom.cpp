#include "Mushroom.h"

Mushroom::Mushroom(float x_pos, float y_pos, EntityID id, float speed):
		  Entity(x_pos,y_pos,id)
		  ,number_of_lives(4)
		  {}
		  
void Mushroom::weaken(){
	if(number_of_lives > 1)
		--number_of_lives;
	else
		destroy();
}