#include "Mover.h"

Mover::Mover(float x_position, float y_position, float speed):
        position_(make_shared<Position>(x_position,y_position))
        ,speed_(speed)
{
	if (speed <=0)
		throw NegativeZeroSpeed();
}

void Mover::moveLeft(){
	
	auto x_position = position_->getXPosition();
		if(auto x_left_limit = 4;x_position >= x_left_limit)
			position_->setXPosition(x_position-getSpeed());
}

void Mover::moveRight(){
	auto x_position = position_->getXPosition();
		if(auto x_right_limit = 4; x_position >= x_right_limit)
			position_->setXPosition(x_position-getSpeed());	
}

void Mover::moveUp(){
		if(auto y_position = position_->getYPosition();  y_position >= Constants::PLAYER_VERTICAL_LIMIT_)
			position_->setYPosition(y_position-getSpeed());	
}

void Mover::moveDown(){
	auto y_down_limit = 584;
		if(auto y_position = position_->getYPosition();  y_position >= y_down_limit)
			position_->setYPosition(y_position+getSpeed());
}

float Mover::getSpeed()const{
		return speed_;
}























        
//void Mover::move(Direction direction){
//    
//	auto[x_position,y_position] = position_->getPosition();
//	
//    switch(direction){
//        case Direction::LEFT:
//			if(auto new_x = x_position-getSpeed(); !minXBound(new_x))
//				setPosition(new_x,y_position);
//            break;
//        case Direction::RIGHT:
//			if(auto new_x = x_position+getSpeed(); !maxXBound(new_x))
//				setPosition(new_x,y_position);
//            break;
//        case Direction::DOWN:
//			if(auto new_y = y_position+getSpeed(); !maxYBound(new_y)) 
//			setPosition(x_position,new_y);
//            break;
//        case Direction::UP:
//			if(auto new_y = y_position-getSpeed(); !minXBound(new_y)) 
//				setPosition(x_position,y_position-getSpeed());
//            break;
//		default:
//			assert(false);
//    }
//    
//}
//shared_ptr<Position> Mover::position(){
//        return position_;
//}
//
//bool Mover::isLive(){
//		return live_;
//}
////void Mover::setLive(){
////		live_ = true;
////}
//void Mover::destroy(){
//		live_ = false;
//}
//
//void Mover::setPosition(int x, int y){
//        position_->setPosition(x,y);
//}
//
//int Mover::getSpeed(){
//        return speed_;
//}
//
//bool Mover::minXBound(int x_coord){
//		if(x_coord < Constants::PLAYER_WIDTH_/2)
//			return true;
//		return false;
//}
//
//bool Mover::maxXBound(int x_coord){
//		if(x_coord  >  Constants::DISPLAY_WIDTH_-2*(Constants::PLAYER_WIDTH_))
//			return true;
//		return false;
//}
//
//bool Mover::maxYBound(int y_coord){
//		if(y_coord > Constants::DISPLAY_HEIGHT_-2*(Constants::PLAYER_HEIGHT_))
//			return true;
//		return false;
//}