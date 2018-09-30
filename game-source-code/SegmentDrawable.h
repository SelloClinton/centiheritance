#ifndef SEGMENTDRAWABLE_H
#define SEGMENTDRAWABLE_H

#include "Drawable.h"

class SegmentDrawable : public Drawable{
public:
	SegmentDrawable(const EntityID& drawableID);
	virtual void createDrawable()override;
private:
	
};
#endif