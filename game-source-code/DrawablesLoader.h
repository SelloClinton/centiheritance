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

using Drawables = list<shared_ptr<Drawable>>;

class DrawablesLoader{
	
public:
	DrawablesLoader(list<shared_ptr<Entity>> entities,int numberOfDrawables);
	Drawables& loadDrawables();
private:
	int number_of_drawables_;
	Drawables drawables_;
	void initiateDrawables(list<shared_ptr<Entity>> entities);
	void inititePlayerDrawable(list<shared_ptr<Entity>>::iterator, const EntityID& drawable_id);
	void inititeLaserDrawable(list<shared_ptr<Entity>>::iterator, const EntityID& drawable_id);
	void initiateSegmentDrawable(list<shared_ptr<Entity>>::iterator, const EntityID& drawable_id);
	void initiateMushroomDrawable(list<shared_ptr<Entity>>::iterator, const EntityID& drawable_id);
};
#endif