#include "SegmentDrawable.h"

SegmentDrawable::SegmentDrawable(const EntityID& drawableID):
				Drawable(drawableID)
				{}
				
void SegmentDrawable::createDrawable(){
		switch(drawable_id_){
			case EntityID::HEAD_SEGMENT_FACING_RIGHT:
				sprite_->setTextureRect(sf::IntRect(4,18,8,8));
				sprite_->setRotation(180);
				break;
			case EntityID::HEAD_SEGMENT_FACING_LEFT:
				sprite_->setTextureRect(sf::IntRect(4,18,8,8));
				break;
			case EntityID::HEAD_SEGMENT_FACING_DOWN:
				sprite_->setTextureRect(sf::IntRect(72,28,8,8));
				break;
			case EntityID::HEAD_SEGMENT_FACING_UP:
				sprite_->setTextureRect(sf::IntRect(72,28,8,8));
				sprite_->setRotation(180);
				break;
			case EntityID::MID_SEGMENT_FACING_RIGHT:
				sprite_->setTextureRect(sf::IntRect(4,36,8,8));
				sprite_->setRotation(180);
				break;
			case EntityID::MID_SEGMENT_FACING_LEFT:
				sprite_->setTextureRect(sf::IntRect(4,36,8,8));
				break;
			case EntityID::MID_SEGMENT_FACING_DOWN:
				sprite_->setTextureRect(sf::IntRect(72,46,8,8));
				break;
			case EntityID::MID_SEGMENT_FACING_UP:
				sprite_->setTextureRect(sf::IntRect(72,46,8,8));
				sprite_->setRotation(180);
				break;
			default:
				assert(false);
			
		}
}