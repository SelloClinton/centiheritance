#ifndef MOVER_H
#define MOVER_H

#include "Position.h"
#include "Enums.h"

#include <memory>
using std::shared_ptr;
using std::make_shared;

#include <cassert> 

class NegativeZeroSpeed{};
    
class Mover{
    
public:
        Mover(float x_position, float y_position, float speed);
        void moveLeft();
		void moveRight();
		void moveUp();
		void moveDown();
private:
        shared_ptr<Position> position_;
        float speed_;
        float getSpeed()const;
};

#endif 