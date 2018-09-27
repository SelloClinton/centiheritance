#include "Entity.h"

Entity::Entity(float x_position, float y_position,EntityID id):
		position_(make_shared<Position>(x_position,y_position))
		,entity_id_(id)
		,live_(true)
		{}
		
shared_ptr<Position> Entity::position(){
		return position_;
}

bool Entity::isLive()const{
		return live_;
}

void Entity::destroy(){
		live_ = false;
}

EntityID Entity::getEntityID()const{
		return entity_id_;
}

void Entity::setEntityID(id){
		entity_id_ = id;
}