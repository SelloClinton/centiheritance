#ifndef LASER_H
#define LASER_H

//#include "Mover.h"
#include "Constants.h"
#include "Enums.h"
#include "Entity.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;
#include <tuple>
using std::get;


class NegativeZeroLaserSpeed{};

class Laser : public Entity{
	
public:
		Laser(float x_pos, float y_pos, EntityID id, float speed);
        void move();
		virtual ~Laser();
private:
		float speed_;
		float getSpeed()const;
};

#endif