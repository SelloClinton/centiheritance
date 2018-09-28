#include "Player.h"

Player::Player(float x_position, float y_position, EntityID id, float speed):
		Entity(x_position, y_position,id)
		,mover_(make_unique<Mover>(x_position,y_position,speed))
{
	
//	auto lasersSize = 5;
//	lasers_.resize(lasersSize);	
//	lasers_iterator_ = begin(lasers_);
	
	
}

void Player::move(Direction direction){
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
					position()->setYPosition(mover_->position()->getYPosition());
					break;
				case Direction::DOWN:
					mover_->moveDown();
					position()->setYPosition(mover_->position()->getYPosition());
					break;
				default:
					assert(false);
		}
}

void Player::shoot(){
	
	auto lasers_max_size = 5;
	if (lasers_.size() < lasers_max_size){
       auto[x_position,y_position] = position()->getXYPosition();
	   auto laser = make_shared<Laser>(x_position,y_position,EntityID::LASER,Constants::LASER_SPEED_);
	   lasers_.push_back(laser);
//		lasers_.insert(lasers_iterator_,laser);
//		lasers_iterator_++;
	}
}

void Player::updateLasers(){
	
    for(auto& laser:lasers_){
        laser->move();
    }
}

Lasers& Player::getLasers(){
		return lasers_;
}

//void Player::updateLasersCapacity(){
//	--lasers_iterator_;	
//}