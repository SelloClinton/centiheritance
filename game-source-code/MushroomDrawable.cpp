#include "MushroomDrawable.h"

MushroomDrawable::MushroomDrawable(const EntityID& drawableID):
				Drawable(drawableID)
				{}
				
void MushroomDrawable::createDrawable(){
	
	switch(drawable_id_){
			case EntityID::STRONG_MUSHROOM:
				sprite_->setTextureRect(sf::IntRect(68,72,8,8));
				break;
			case EntityID::WEAK_MUSHROOM:
				sprite_->setTextureRect(sf::IntRect(77,72,8,8));
				break;
			case EntityID::WEAKER_MUSHROOM:
				sprite_->setTextureRect(sf::IntRect(86,72,8,8));
				break;
			case EntityID::WEAKEST_MUSHROOM:
				sprite_->setTextureRect(sf::IntRect(95,72,8,8));
				break;
			default:
				assert(false);
	}
}