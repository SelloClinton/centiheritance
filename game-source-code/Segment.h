#ifndef SEGMENT_H
#define SEGMENT_H

#include "Entity.h"
#include "Mover.h"
#include "Enums.h"
#include <cassert>
#include <memory>
using std::shared_ptr;
using std::make_shared;



class Segment : public Entity{
    
public:
		Segment(float x_position, float y_position, EntityID id, float speed);
		void move(Direction direction);
        void faceLeft();
        void faceRight();
		void faceDown();
		void faceUp();
        bool isFacingLeft();
        bool isFacingRight();
		bool isFacingDown();
		bool isFacingUp();
private:
        shared_ptr<Mover> mover_;
        bool right_flag_;
        bool left_flag_;
		bool down_flag_;
		bool up_flag_;
};

#endif 