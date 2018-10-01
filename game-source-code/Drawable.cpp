#include "Drawable.h"

Drawable::Drawable(const EntityID& drawableID):
		drawable_id_(drawableID)
		,texture_(make_shared<sf::Texture>())
		,sprite_(make_shared<sf::Sprite>())
{
	loadTexture();
	loadSprite();
}
		
shared_ptr<sf::Sprite> Drawable::getDrawable(){
	return sprite_;
}

void Drawable::setPosition(float x, float y){
	sprite_->setPosition(x,y);
}

//void Drawable::createDrawable(){
//		
//}

shared_ptr<sf::Texture> Drawable::getTexture(){
	return texture_;
}

const EntityID& Drawable::getDrawableID()const{
	return drawable_id_;
}

void Drawable::loadTexture(){
	if(!texture_->loadFromFile("centipede_image.png"))
		throw GameImageLoadFailed();
}
void Drawable::loadSprite(){
	sprite_->setTexture(*texture_);
	sprite_->setScale(2.5,2.5);
	sprite_->setTextureRect(sf::IntRect(21,9,8,8));
}