#ifndef DRAWABLE_H
#define DRAWABLE_H


#include "Enums.h"
#include <SFML/Graphics.hpp>
#include <memory>
using std::shared_ptr;
using std::make_shared;

class GameImageLoadFailed{};

class Drawable{
	
public:
	Drawable(const EntityID& drawableID);
	shared_ptr<sf::Sprite> getDrawable();
	void setPosition(float x, float y);
//	virtual void createDrawable() = 0;
	
	virtual ~Drawable(){}
		
protected:
	shared_ptr<sf::Texture> getTexture();
	const EntityID& getDrawableID()const;
	
//	shared_ptr<sf::Texture> texture_;
	shared_ptr<sf::Sprite> sprite_;
	EntityID drawable_id_;
private:
	shared_ptr<sf::Texture> texture_;
//	shared_ptr<sf::Sprite> sprite_;
//	EntityID drawable_id_;
	void loadTexture();
	void loadSprite();
};
#endif