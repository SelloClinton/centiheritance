#ifndef DRAWABLESLOADER_H
#define DRAWABLESLOADER_H
 
#include "Enums.h"
#include "Entity.h"
#include "Drawable.h"
#include "PlayerDrawable.h"
#include "MushroomDrawable.h"
#include "SegmentDrawable.h"
#include "LaserDrawable.h"

#include <list>
using std::list;
#include <memory>
using std::shared_ptr;
using std::make_shared;

//using Drawables = list<shared_ptr<Drawable>>;

class DrawablesLoader{
	
public:
	DrawablesLoader();
	shared_ptr<Drawable> loadDrawable(const EntityID& drawable_id);
//	Drawables& loadDrawables();
private:
//	int number_of_drawables_;
//	Drawables drawables_;
	shared_ptr<Drawable> drawable_;
	shared_ptr<Drawable> getDrawable();
	
	shared_ptr<Drawable> identityDrawable(const EntityID& drawable_id);
	
	bool isPlayer(const EntityID& drawable_id);
	bool isLaser(const EntityID& drawable_id);
	bool isSegment(const EntityID& drawable_id);
	bool isMushroom(const EntityID& drawable_id);
	
//	shared_ptr<Drawable> initiateDrawables(const EntityID& drawable_id);
	void createPlayerDrawable(const EntityID& drawable_id);
	void createLaserDrawable(const EntityID& drawable_id);
	void createSegmentDrawable(const EntityID& drawable_id);
	void createMushroomDrawable(const EntityID& drawable_id);
	

};
#endif