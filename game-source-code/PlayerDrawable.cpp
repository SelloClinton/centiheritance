#include "PlayerDrawable.h"

PlayerDrawable::PlayerDrawable(const EntityID& drawableID):
				Drawable(drawableID)
				{}
void PlayerDrawable::createDrawable(){
		sprite_->setTextureRect(sf::IntRect(21,9,8,8));
}