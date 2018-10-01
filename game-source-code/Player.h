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
using std::unique_ptr;
using std::make_unique;

using Lasers = list<shared_ptr<Laser>>;
class WrongEntityID{};

class Player : public Entity {
	
public:
		Player(float x_position, float y_position, EntityID id, float speed);
		void move(Direction direction);
		void shoot();
		void updateLasers();
		Lasers& getLasers(); 
//		void updateLasersCapacity();
		virtual ~Player();
private:
		unique_ptr<Mover> mover_;
		Lasers lasers_;
//		Lasers::iterator lasers_iterator_;
};
#endif 
