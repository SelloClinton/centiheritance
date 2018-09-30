#ifndef MUSHROOMDRAWABLE_H
#define MUSHROOMDRAWABLE_H

#include "Drawable.h"

#include <cassert>

class MushroomDrawable : public Drawable{
public:
	MushroomDrawable(const EntityID& drawableID);
	virtual void createDrawable();
private:
};
#endif