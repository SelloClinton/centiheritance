#include "Player.h"

Player::Player(float x_position, float y_position, EntityID id, float speed):
		Entity(x_position, y_position,id)
		,mover_(make_shared<Mover>(x_position,y_position,speed))
//		,speed_(speed)
{
	auto lasersSize = 5;
	lasers_.resize(lasersSize);	
	lasers_iterator_ = begin(lasers_);
}

void Player::move(Direction direction){
		switch(direction){
				case Direction::RIGHT:
					mover_->moveRight();
					break;
				case Direction::LEFT:
					mover_->moveLeft();
					break;
				case Direction::UP:
					mover_->moveUp();
					break;
				case Direction::DOWN:
					mover_->moveDown();
					break;
				default:
					assert(false);
		}
}
//shared_ptr<Mover> Player::attribute(){
//        return attribute_;
//}
//shared_ptr<Position> Player::position(){
//		return attribute_->position();
//}
//
//void Player::moveUp(){
//	
//	
//	
//	for(auto i = 0; i != speed_; i++){
//		if(auto y_position = position()->getYPosition();y_position >= Constants::PLAYER_VERTICAL_LIMIT_)
//			position()->setYPosition(y_position-getSpeed());
//	}
//		if(get<1>(attribute_->position()->getPosition()) > Constants::PLAYER_VERTICAL_LIMIT)
//			attribute_->move(Direction::UP);
//}
//void Player::moveDown(){
//	
//
//	auto y_limit = 584;
//	for(auto i = 0; i != speed_; i++){
//		if(	auto y_position = position()->getYPosition();  y_position <= y_limit)
//			position()->setYPosition(y_position+getSpeed());
//	}
//	attribute_->move(Direction::DOWN);
//}
//void Player::moveLeft(){
//
//	auto y_limit = 0;
//	for(auto i = 0; i != speed_; i++){
//		if(	auto y_position = position()->getXPosition();  y_position >= y_limit)
//			position()->setYPosition(y_position-getSpeed());
//	}
//	attribute_->move(Direction::LEFT);
//}
//void Player::moveRight(){
//	
//
//	auto y_limit = 774;
//	
//	for(auto i = 0; i != speed_; i++){
//		if(	auto y_position = position()->getXPosition();  y_position <= y_limit)
//			position()->setYPosition(y_position+getSpeed());
//	}
//	attribute_->move(Direction::RIGHT);
//}
//
//float Player::getSpeed()const{
//		return speed_;
//}
void Player::shoot(){
	
	if (lasers_iterator_ != end(lasers_)){
       auto[x_position,y_position] = position()->getXYPosition();
	   auto laser = make_shared<Laser>(x_position,y_position,EntityID::LASER,Constants::LASER_SPEED_);
		lasers_.insert(lasers_iterator_,laser);
		lasers_iterator_++;
	}
}

void Player::updateLaser(){
	
    for(auto& laser:lasers_){
        laser->move();
    }
}

Lasers& Player::getLasers(){
		return lasers_;
}

void Player::updateLasersCapacity(){
	--lasers_iterator_;	
}