#ifndef LASERDRAWABLE_H
#define LASERDRAWABLE_H

#include "Drawable.h"

class LaserDrawable : public Drawable{
public:
	LaserDrawable(const EntityID& drawableID);
	virtual void createDrawable();
private:	
};
#endif