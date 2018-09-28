#include "Position.h"

Position::Position(float x_position, float y_position):
		  x_position_(x_position),
		  y_position_(y_position)
{
	if ((x_position_< 0)||(y_position_ < 0))
		throw NegativePosition();
	if ((x_position_ > Constants::DISPLAY_WIDTH_)||(y_position_ > Constants::DISPLAY_HEIGHT_))
		throw OutOfBounds();
}
tuple<float,float> Position::getXYPosition()const{
		return{x_position_,y_position_};
}

float Position::getXPosition(){
		return x_position_;
}

float Position::getYPosition(){
		return y_position_;
}
void Position::setXYPosition(float x, float y){
		x_position_ = x;
		y_position_ = y;
}

void Position::setXPosition(float x_pos){
		x_position_ = x_pos;
}

void Position::setYPosition(float y_pos){
		y_position_ = y_pos;
}