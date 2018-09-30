#include "Drawable.h"

Drawable::Drawable(const EntityID& drawableID):
		drawable_id_(drawableID)
		{}
		
shared_ptr<sf::Sprite> Drawable::getDrawable(){
	return sprite_;
}

void Drawable::setPosition(float x, float y){
	sprite_->setPosition(x,y);
}

shared_ptr<sf::Texture> Drawable::getTexture(){
	return texture_;
}

const EntityID& Drawable::getDrawableID()const{
	return drawable_id_;
}