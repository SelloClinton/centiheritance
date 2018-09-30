#ifndef PLAYERDRAWABLE_H
#define PLAYERDRAWABLE_H

#include "Drawable.h"

class PlayerDrawable : public Drawable{
public:
	PlayerDrawable(const EntityID& drawableID);
	virtual void createDrawable();
private:
	
};
#endif