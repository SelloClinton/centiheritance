#ifndef ENTITY_H
#define ENTITY_H

#include "Enums.h"
#include "Position.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;
 
class Entity{
public:
	Entity(float x_position, float y_position,EntityID id);
	shared_ptr<Position>& position();
	bool isLive()const;
	void destroy();
	EntityID getEntityID()const;
	void setEntityID(EntityID id);
private:
	shared_ptr<Position> position_;
	EntityID entity_id_;
	bool live_;
};
#endif