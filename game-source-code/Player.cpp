#include "Player.h"

Player::Player(float x_position, float y_position, EntityID id, int speed):
		Entity(x_position, y_position,id)
		,speed_(speed)
{
			
}
		
//shared_ptr<Mover> Player::attribute(){
//        return attribute_;
//}
//shared_ptr<Position> Player::position(){
//		return attribute_->position();
//}

void Player::moveUp(){
	
	auto y_position = position()->getYPosition();
	 auto y_limit = 450;
	for(auto i = 0; i != speed_; i++){
		if(auto incr = 1.0;/*Constants::VERTICAL_PLAYER_LIMIT_;*/y_position > y_limit)
			position()->setYPosition(y_position-incr);
	}
//		if(get<1>(attribute_->position()->getPosition()) > Constants::PLAYER_VERTICAL_LIMIT)
//			attribute_->move(Direction::UP);
}
void Player::moveDown(){
	
	auto y_position = position()->getYPosition();
	auto y_limit = 584;
	for(auto i = 0; i != speed_; i++){
		if(auto incr = 1.0;  y_position <= y_limit)
			position()->setYPosition(y_position+incr);
	}
//	attribute_->move(Direction::DOWN);
}
void Player::moveLeft(){
	auto y_position = position()->getXPosition();
	auto y_limit = 0;
	for(auto i = 0; i != speed_; i++){
		if(auto incr = 1.0;  y_position >= y_limit)
			position()->setYPosition(y_position-incr);
	}
//	attribute_->move(Direction::LEFT);
}
void Player::moveRight(){
	
	auto y_position = position()->getXPosition();
	auto y_limit = 774;
	
	for(auto i = 0; i != speed_; i++){
		if(auto incr = 1.0;  y_position <= y_limit)
			position()->setYPosition(y_position+incr);
	}
//	attribute_->move(Direction::RIGHT);
}

int Player::getSpeed()const{
		return speed_;
}
//void Player::shoot(){
//    auto[x_position,y_position] = attribute_->position()->getPosition();
//    auto bullet_position = make_shared<Position>(x_position+(Constants::PLAYER_WIDTH_),y_position-(Constants::PLAYER_HEIGHT_));
//    auto bullet_mover = make_shared<Mover>(bullet_position,Constants::BULLET_SPEED_);
//    auto bullet = make_shared<Bullet>(bullet_mover);
//    bullets_.push_back(bullet);
//}

//void Player::updateBullet(){
//	
//    for(auto& bullet:bullets_){
//        bullet->move();
//    }
//}