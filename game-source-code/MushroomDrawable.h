#ifndef MUSHROOMDRAWABLE_H
#define MUSHROOMDRAWABLE_H

#include "Drawable.h"

class MushroomDrawable : public Drawable{
public:
	MushroomDrawable(const EntityID& drawableID);
	virtual void createDrawable()override;
private:
};
#endif