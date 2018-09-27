#ifndef PLAYER_H
#define PLAYER_H

//#include "Mover.h"
#include "Position.h"
//#include "Laser.h"
#include "Constants.h"
#include "Enums.h"
#include "Entity.h"

#include <tuple>
using std::tuple;
#include <list>
#include <iostream>
using namespace std;
#include <memory>
using std::shared_ptr;
using std::make_shared;

//using Bullets = list<shared_ptr<Laser>>;

class Player : public Entity {
	
public:
		Player(float x_position, float y_position, EntityID id, int speed);
		void moveUp();
		void moveDown();
		void moveLeft();
		void moveRight();
		int getSpeed()const;
		void shoot();
		void updateBullet();
//		Bullets& getBullets(){return bullets_;}
private:
//		Bullets bullets_;
		int speed_;
};
#endif // PLAYER_H
