#include "DrawablesLoader.h"

DrawablesLoader::DrawablesLoader(list<shared_ptr<Entity>>& entities, int numberOfDrawables)

{
	drawables_.resize(numberOfDrawables);
	initiateDrawables(entities);
}

Drawables& DrawablesLoader::loadDrawables(){
	return drawables_;
}

void DrawablesLoader::initiateDrawables(list<shared_ptr<Entity>>& entities){
	
	auto entities_iterator = begin(entities);
	
	while(entities_iterator != end(entities)){
		auto drawable_id = (*entities_iterator)->getEntityID();
		
		if(drawable_id == EntityID::LASER){
			inititeLaserDrawable(entities_iterator,drawable_id);
		}
		else if(drawable_id == EntityID::PLAYER){
			inititePlayerDrawable(entities_iterator,drawable_id);
		}
		else if((drawable_id == EntityID::STRONG_MUSHROOM)||
				(drawable_id == EntityID::WEAK_MUSHROOM)||
				(drawable_id == EntityID::WEAKER_MUSHROOM)||
				(drawable_id == EntityID::WEAKEST_MUSHROOM)){
			initiateMushroomDrawable(entities_iterator, drawable_id);
		}
		else if((drawable_id == EntityID::HEAD_SEGMENT_FACING_DOWN)||
				(drawable_id == EntityID::HEAD_SEGMENT_FACING_UP)||
				(drawable_id == EntityID::HEAD_SEGMENT_FACING_LEFT)||
				(drawable_id == EntityID::HEAD_SEGMENT_FACING_RIGHT)||
				(drawable_id == EntityID::MID_SEGMENT_FACING_DOWN)||
				(drawable_id == EntityID::MID_SEGMENT_FACING_UP)||
				(drawable_id == EntityID::MID_SEGMENT_FACING_LEFT)||
				(drawable_id == EntityID::MID_SEGMENT_FACING_RIGHT)){
			initiateSegmentDrawable(entities_iterator,drawable_id);
		}
		++entities_iterator;
	}
	
}

void DrawablesLoader::inititePlayerDrawable(list<shared_ptr<Entity>>::iterator entity_iter, const EntityID& drawable_id){
	auto player_drawable = make_shared<PlayerDrawable>(drawable_id);
	shared_ptr<Drawable> drawable = player_drawable;
	drawables_.push_back(drawable);	
}
void DrawablesLoader::inititeLaserDrawable(list<shared_ptr<Entity>>::iterator entity_iter,const EntityID& drawable_id){
	auto laser_drawable = make_shared<LaserDrawable>(drawable_id);
	shared_ptr<Drawable> drawable = laser_drawable;
//	drawables_.insert(entity_iter,drawable);
	drawables_.push_back(drawable);	
}
void DrawablesLoader::initiateSegmentDrawable(list<shared_ptr<Entity>>::iterator entity_iter,const EntityID& drawable_id){
	auto segment_drawable = make_shared<SegmentDrawable>(drawable_id);
	shared_ptr<Drawable> drawable = segment_drawable;
//	drawables_.insert(entity_iter,drawable);
	drawables_.push_back(drawable);
}
void DrawablesLoader::initiateMushroomDrawable(list<shared_ptr<Entity>>::iterator entity_iter,const EntityID& drawable_id){
	auto player_drawable = make_shared<MushroomDrawable>(drawable_id);
	shared_ptr<Drawable> drawable = player_drawable;
//	drawables_.insert(entity_iter,drawable);
	drawables_.push_back(drawable);
}