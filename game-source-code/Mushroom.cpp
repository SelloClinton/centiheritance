#include "Mushroom.h"

Mushroom::Mushroom(float x_pos, float y_pos, EntityID id):
		  Entity(x_pos,y_pos,id)
		  ,number_of_lives(4)
		  {}
		  
void Mushroom::weaken(){
	
	if(auto strong_state = 4; number_of_lives == strong_state){
		--number_of_lives;
		setEntityID(EntityID::WEAK_MUSHROOM);
	}
		
	else if(auto weak_state = 3; number_of_lives == weak_state){
		--number_of_lives;
		setEntityID(EntityID::WEAKER_MUSHROOM);
		
	}
	else if(auto weaker_state = 2; number_of_lives == weaker_state){
			--number_of_lives;
			setEntityID(EntityID::WEAKEST_MUSHROOM);
			
	}
	
	else
		destroy();
}

