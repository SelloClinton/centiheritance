#ifndef SEGMENTDRAWABLE_H
#define SEGMENTDRAWABLE_H

#include "Drawable.h"

#include <cassert>

class SegmentDrawable : public Drawable{
public:
	SegmentDrawable(const EntityID& drawableID);
	virtual void createDrawable();
private:
	
};
#endif