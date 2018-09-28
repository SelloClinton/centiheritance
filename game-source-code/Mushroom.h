#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "Position.h"
#include "Entity.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
using std::shared_ptr;
using std::make_shared;

class Mushroom : public Entity{

public:	
		Mushroom(float x_pos, float y_pos, EntityID id, float speed);
		void weaken();
private:
		int number_of_lives;
		float speed_;
};
#endif