#include "Segment.h"

Segment::Segment(float x_position, float y_position, EntityID id, float speed):
		 Entity(x_position,y_position,id)
		 ,mover_(make_shared<Mover>(x_position,y_position,speed))
        ,right_flag_(true)
        ,left_flag_(false)
		,down_flag_(true)
		,up_flag_(false)
{
}

void Segment::move(Direction direction){
		switch(direction){
			case Direction::RIGHT:
				mover_->moveRight();
				position()->setXPosition(mover_->position()->getXPosition());
				break;
			case Direction::LEFT:
				mover_->moveLeft();
				position()->setXPosition(mover_->position()->getXPosition());
				break;
			case Direction::UP:
				mover_->moveUp();
				mover_->moveUp();
				mover_->moveUp();
				mover_->moveUp();
				position()->setYPosition(mover_->position()->getYPosition());
				break;
			case Direction::DOWN:
				mover_->moveDown();
				mover_->moveDown();
				mover_->moveDown();
				mover_->moveDown();
				position()->setYPosition(mover_->position()->getYPosition());
			default:
				assert(false);
		}
}
		
//shared_ptr<Mover> Segment::attribute(){
//        return attribute_;
//}
void Segment::faceLeft(){
        right_flag_ = false;
        left_flag_ = true;
}
void Segment::faceRight(){
    right_flag_ = true;
    left_flag_ = false;
}
void Segment::faceDown(){
	down_flag_ = true;
	up_flag_ = false;
}
void Segment::faceUp(){
	down_flag_ = false;
	up_flag_ = true;
}
bool Segment::isFacingLeft(){
    if((!right_flag_)&&(left_flag_))
        return true;
    return false;
}
bool Segment::isFacingRight(){
    if((right_flag_)&&(!left_flag_))
        return true;
    return false;
}
bool Segment::isFacingDown(){
	if ((down_flag_)&&(!up_flag_))
		return true;
	return false;
}
bool Segment::isFacingUp(){
	if ((up_flag_)&&(!down_flag_))
		return true;
	return false;
}
