#include "LaserDrawable.h"

LaserDrawable::LaserDrawable(const EntityID& drawableID):
			Drawable(drawableID)
			{}
			
void LaserDrawable::createDrawable()override{
	sprite_->setTextureRect(sf::IntRect(24,1,1,7));	
}