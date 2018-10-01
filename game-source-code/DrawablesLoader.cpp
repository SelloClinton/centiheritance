#include "DrawablesLoader.h"

DrawablesLoader::DrawablesLoader()

{
//	drawables_.resize(numberOfDrawables);
//	initiateDrawables(entities);
}

shared_ptr<Drawable> DrawablesLoader::loadDrawable(const EntityID& drawable_id){
	if(isPlayer(drawable_id))
		createPlayerDrawable(drawable_id);
	else if(isLaser((drawable_id)))
		createLaserDrawable(drawable_id);
	else if(isMushroom(drawable_id))
		createMushroomDrawable(drawable_id);
	else if(isSegment(drawable_id))
		createSegmentDrawable(drawable_id); 
	
	getDrawable();
}

shared_ptr<Drawable> DrawablesLoader::getDrawable(){
		return drawable_;
}

//shared_ptr<Drawable> DrawablesLoader::identityDrawable(const EntityID& drawable_id){
//	
//	if(isPlayer(drawable_id))
//		createPlayerDrawable(drawable_id);
//	else if(isLaser((drawable_id)))
//		createLaserDrawable(drawable_id);
//	else if(isMushroom(drawable_id))
//		createMushroomDrawable(drawable_id);
//	else if(isSegment(drawable_id))
//		createSegmentDrawable(drawable_id);	
//}


bool DrawablesLoader::isPlayer(const EntityID& drawable_id){
	
	if (drawable_id == EntityID::PLAYER)
		return true;
	return false;
	
}
bool DrawablesLoader::isLaser(const EntityID& drawable_id){
	if (drawable_id == EntityID::LASER)
		return true;
	return false;	
}
bool DrawablesLoader::isSegment(const EntityID& drawable_id){
	if((drawable_id == EntityID::HEAD_SEGMENT_FACING_DOWN)||
	   (drawable_id == EntityID::HEAD_SEGMENT_FACING_UP)||
	   (drawable_id == EntityID::HEAD_SEGMENT_FACING_LEFT)||
	   (drawable_id == EntityID::HEAD_SEGMENT_FACING_RIGHT)||
	   (drawable_id == EntityID::MID_SEGMENT_FACING_DOWN)||
	   (drawable_id == EntityID::MID_SEGMENT_FACING_UP)||
	   (drawable_id == EntityID::MID_SEGMENT_FACING_LEFT)||
	   (drawable_id == EntityID::MID_SEGMENT_FACING_RIGHT)) return true;
	else
		return false;
}
bool DrawablesLoader::isMushroom(const EntityID& drawable_id){
	if((drawable_id == EntityID::STRONG_MUSHROOM)||
	   (drawable_id == EntityID::WEAK_MUSHROOM)||
	   (drawable_id == EntityID::WEAKER_MUSHROOM)||
	   (drawable_id == EntityID::WEAKEST_MUSHROOM)) return true;
	else
		return false;
}
//Drawables& DrawablesLoader::loadDrawables(){
//	return drawables_;
//}

//void DrawablesLoader::initiateDrawables(list<shared_ptr<Entity>>& entities){
//	
//	auto entities_iterator = begin(entities);
//	
//	while(entities_iterator != end(entities)){
//		auto drawable_id = (*entities_iterator)->getEntityID();
//		
//		if(drawable_id == EntityID::LASER){
//			inititeLaserDrawable(entities_iterator,drawable_id);
//		}
//		else if(drawable_id == EntityID::PLAYER){
//			inititePlayerDrawable(entities_iterator,drawable_id);
//		}
//		else if((drawable_id == EntityID::STRONG_MUSHROOM)||
//				(drawable_id == EntityID::WEAK_MUSHROOM)||
//				(drawable_id == EntityID::WEAKER_MUSHROOM)||
//				(drawable_id == EntityID::WEAKEST_MUSHROOM)){
//			initiateMushroomDrawable(entities_iterator, drawable_id);
//		}
//		else if((drawable_id == EntityID::HEAD_SEGMENT_FACING_DOWN)||
//				(drawable_id == EntityID::HEAD_SEGMENT_FACING_UP)||
//				(drawable_id == EntityID::HEAD_SEGMENT_FACING_LEFT)||
//				(drawable_id == EntityID::HEAD_SEGMENT_FACING_RIGHT)||
//				(drawable_id == EntityID::MID_SEGMENT_FACING_DOWN)||
//				(drawable_id == EntityID::MID_SEGMENT_FACING_UP)||
//				(drawable_id == EntityID::MID_SEGMENT_FACING_LEFT)||
//				(drawable_id == EntityID::MID_SEGMENT_FACING_RIGHT)){
//			initiateSegmentDrawable(entities_iterator,drawable_id);
//		}
//		++entities_iterator;
//	}
//	
//}

void DrawablesLoader::createPlayerDrawable(const EntityID& drawable_id){
	auto player_drawable = make_shared<PlayerDrawable>(drawable_id);
	drawable_ = player_drawable;
//	return drawable; 
//	drawables_.push_back(drawable);	
}
void DrawablesLoader::createLaserDrawable(const EntityID& drawable_id){
	auto laser_drawable = make_shared<LaserDrawable>(drawable_id);
	drawable_ = laser_drawable;
//	drawables_.insert(entity_iter,drawable);
//	drawables_.push_back(drawable);	
}
void DrawablesLoader::createSegmentDrawable(const EntityID& drawable_id){
	auto segment_drawable = make_shared<SegmentDrawable>(drawable_id);
	drawable_ = segment_drawable;
//	drawables_.insert(entity_iter,drawable);
//	return drawable; 
//	drawables_.push_back(drawable);
}
void DrawablesLoader::createMushroomDrawable(const EntityID& drawable_id){
	auto player_drawable = make_shared<MushroomDrawable>(drawable_id);
	drawable_ = player_drawable;
//	drawables_.insert(entity_iter,drawable);
//	return drawable; 
//	drawables_.push_back(drawable);
}