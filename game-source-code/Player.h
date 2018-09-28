#ifndef PLAYER_H
#define PLAYER_H

#include "Mover.h"
#include "Position.h"
#include "Laser.h"
#include "Constants.h"
#include "Enums.h"
#include "Entity.h"

#include <cassert>
#include <tuple>
using std::tuple;
#include <list>
#include <iostream>
using namespace std;
#include <memory>
using std::shared_ptr;
using std::make_shared;

using Lasers = list<shared_ptr<Laser>>;

class Player : public Entity {
	
public:
		Player(float x_position, float y_position, EntityID id, float speed);
		void move(Direction direction);
		void shoot();
		void updateLaser();
		Lasers& getLasers(); 
		void updateLasersCapacity();
private:
		shared_ptr<Mover> mover_;
		Lasers lasers_;
//		float speed_;
		Lasers::iterator lasers_iterator_;
//		float getSpeed()const;
};
#endif // PLAYER_H
