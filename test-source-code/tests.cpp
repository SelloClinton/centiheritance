#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../game-source-code/Position.h"
#include "../game-source-code/Entity.h"
#include "../game-source-code/Enums.h"
#include "../game-source-code/Mover.h"
#include "../game-source-code/Player.h"
#include "../game-source-code/Constants.h"


#include <memory>
#include <vector>
using namespace std;

//***********************Position tests*******************************
TEST_CASE("Position cannot be less that zero"){
	
	CHECK_THROWS_AS(Position(-150,350),NegativePosition);
	CHECK_THROWS_AS(Position(150,-350),NegativePosition);
	CHECK_THROWS_AS(Position(-150,-350),NegativePosition);
}//1
//
TEST_CASE("Position cannot be greater than screen dimensions"){
	
	CHECK_THROWS_AS(Position(Constants::DISPLAY_WIDTH_+5,Constants::DISPLAY_HEIGHT_),OutOfBounds);
	CHECK_THROWS_AS(Position(Constants::DISPLAY_WIDTH_,Constants::DISPLAY_HEIGHT_+10),OutOfBounds);
	CHECK_THROWS_AS(Position(Constants::DISPLAY_WIDTH_+1,Constants::DISPLAY_HEIGHT_+1),OutOfBounds);

}//2
//
TEST_CASE("x position getter returns expected value"){
	auto x = 800.0f;
	auto y = 600.0f;
	Position position(x,y);
	auto x_position = position.getXPosition();

	CHECK(doctest::Approx(x_position) == x);
	CHECK_FALSE(x_position == y);
}//3
TEST_CASE("y position getter returns expected value"){
	auto x = 250.0f;
	auto y = 350.0f;
	Position position(x,y);
	auto y_position = position.getYPosition();

	CHECK(doctest::Approx(y_position) == y);
	CHECK_FALSE(doctest::Approx(y_position) == x);
}//4
TEST_CASE("xy position function returns expected values"){
	auto x = 150.0f;
	auto y = 500.0f;
	Position position(x,y);	
	auto[x_position,y_position] = position.getXYPosition();

	CHECK(doctest::Approx(x) == x_position);
	CHECK(doctest::Approx(y) == y_position);
	CHECK_FALSE(doctest::Approx(x)== y_position);
	CHECK_FALSE(doctest::Approx(y) == x_position);
	
}//5
//
TEST_CASE("x position Setter function effective"){

	auto x = 550.0f;
	auto y = 550.0f;
	Position set_position(x,y);
	auto x_position = set_position.getXPosition();
	auto x_set = 250.0f;
	set_position.setXPosition(x_set);
	auto new_x_position = set_position.getXPosition();
	CHECK(doctest::Approx(new_x_position) == x_set);
	CHECK_FALSE(doctest::Approx(new_x_position) == x_position);
}//6
TEST_CASE("y position Setter function effective"){

	auto x = 650.0f;
	auto y = 350.0f;
	Position set_position(x,y);
	auto y_position = set_position.getXPosition();
	auto y_set = 150.0f;
	set_position.setXPosition(y_set);
	auto new_y_position = set_position.getXPosition();
	CHECK(doctest::Approx(new_y_position) == y_set);
	CHECK_FALSE(doctest::Approx(new_y_position) == y_position);
}//7
//
TEST_CASE("xy position setter function effective"){
	auto x = 650.0f;
	auto y = 350.0f;
	Position set_position(x,y);
	auto[x_position,y_position] = set_position.getXYPosition();
	auto x_set = 150.0f;
	auto y_set = 450.0f;
	set_position.setXYPosition(x_set,y_set);
	auto[new_x_position,new_y_position] = set_position.getXYPosition();
	CHECK(doctest::Approx(new_x_position) == x_set);
	CHECK(doctest::Approx(new_y_position) == y_set);
	CHECK_FALSE(doctest::Approx(new_x_position) == x_position);
	CHECK_FALSE(doctest::Approx(new_y_position) == y_position);
}//8
TEST_CASE("Default position is origin"){
		Position origin;
		
		auto[x_pos,y_pos] = origin.getXYPosition();
		auto x = 0.0f;
		auto y = 0.0f;
		CHECK(doctest::Approx(x) == x_pos);
		CHECK(doctest::Approx(y) == y_pos);
}//9
////*************************end of Position tests(9 tests)*********************************
//
//***************************Entity Tests************************************************
TEST_CASE("position returns expcted results"){
	auto x = 250.0f;
	auto y = 350.0f;
	auto player_id = EntityID::PLAYER;
	auto entity = make_unique<Entity>(x,y,player_id);
	auto [x_position,y_position] = entity->position()->getXYPosition();
	
	CHECK(doctest::Approx(x_position) == x);
	CHECK(doctest::Approx(y_position) == y);
}//10

TEST_CASE("islive returns correct state"){
	auto x = 150.0f;
	auto y = 425.0f;
	auto segment_id = EntityID::HEAD_SEGMENT;
	auto entity = make_unique<Entity>(x,y,segment_id);
	CHECK(entity->isLive());
}//11

TEST_CASE("an entity can be destroyed"){
	auto x = 150.0f;
	auto y = 425.0f;
	auto mushroom_id = EntityID::MUSHROOM;
	auto mushroom = make_unique<Entity>(x,y,mushroom_id);
	CHECK(mushroom->isLive());
	mushroom->destroy();
	CHECK_FALSE(mushroom->isLive());
}//12

TEST_CASE("A correct entity id is returned"){
	auto x = 325.0f;
	auto y = 425.0f;
	auto laser_id = EntityID::LASER;
	auto laser = make_unique<Entity>(x,y,laser_id);
	auto wrong_laser_id = EntityID::PLAYER;
	CHECK(laser_id == laser->getEntityID());
	CHECK_FALSE(laser_id == wrong_laser_id);
	
}//13

TEST_CASE("EntityID is set correctly"){
	auto x = 315.0f;
	auto y = 250.0f;	
	auto head_segment = EntityID::HEAD_SEGMENT;
	Entity head(x,y,head_segment);
	auto mid_segment = EntityID::MID_SEGMENT;
	head.setEntityID(mid_segment);
	CHECK(mid_segment == head.getEntityID());
	
}//14
//**************************************************************************
//**************************Mover Tests**************************************

TEST_CASE("Speed cannot be less than or equal to zero"){
	
		auto x = 350.0f;
		auto y = 300.0f;
		auto negative_speed = -10.0f;
		CHECK_THROWS_AS(Mover(x,y,negative_speed),NegativeZeroSpeed);
		auto zero_speed = 0.0;
		CHECK_THROWS_AS(Mover(x,y,zero_speed),NegativeZeroSpeed);
}//15

TEST_CASE("Mover can move left"){
		auto x = 450.0f;
		auto y = 100.0f;
		auto speed = 4.0f;
		auto mover = make_unique<Mover>(x,y,speed);
		auto x_initial = mover->position()->getXPosition();
		mover->moveLeft();
		auto x_final = mover->position()->getXPosition();
		CHECK(doctest::Approx(x_final) == (x-speed));
		CHECK_FALSE(doctest::Approx(x_initial) == x_final);
}//16

TEST_CASE("Mover cannot left when at left border"){
	auto x = 0.0f;
	auto y = 100.0f;
	auto speed = 5.0f;
	auto mover = make_unique<Mover>(x,y,speed);
	auto x_i = mover->position()->getXPosition();
	mover->moveLeft();
	auto x_f = mover->position()->getXPosition();
	CHECK(doctest::Approx(x_i) == x_f);
	
}//17

TEST_CASE("Mover can move right"){
	auto x = 50.0f;
	auto y = 100.0f;
	auto speed = 4.0f;
	auto mover = make_unique<Mover>(x,y,speed);
	auto x_i = mover->position()->getXPosition();
	mover->moveRight();
	auto x_f = mover->position()->getXPosition();
	CHECK(doctest::Approx(x_f) == (x_i+speed));	
	CHECK_FALSE(doctest::Approx(x_i) == x_f);
}//18

TEST_CASE("Mover cannot move right when at rightmost screen border"){
	auto x = 784.0f;
	auto y = 150.0f;
	auto speed = 4.0f;
	auto mover = make_unique<Mover>(x,y,speed);
	auto x_i = mover->position()->getXPosition();
	mover->moveRight();
	auto x_f = mover->position()->getXPosition();
	CHECK(doctest::Approx(x_i) == (x_f));	

}//19

TEST_CASE("Mover can move down"){
	auto x = 150.0f;
	auto y = 350.0f;
	auto speed = 4.0f;
	auto mover = make_unique<Mover>(x,y,speed);
	auto y_i = mover->position()->getYPosition();
	mover->moveDown();
	auto y_f = mover->position()->getYPosition();
	CHECK(doctest::Approx(y_f) == (y_i+speed));	
	CHECK_FALSE(doctest::Approx(y_i) == y_f);
}//20

TEST_CASE("Mover cannot move down when at the bottom of the screen"){
	
	auto x = 284.0f;
	auto y = 584.0f;
	auto speed = 4.0f;
	auto mover = make_unique<Mover>(x,y,speed);
	auto y_i = mover->position()->getYPosition();
	mover->moveDown();
	auto y_f = mover->position()->getYPosition();
	CHECK(doctest::Approx(y_i) == (y_f));	

}//21

TEST_CASE("Mover can move up"){
	auto x = 150.0f;
	auto y = 550.0f;
	auto speed = 4.0f;
	auto mover = make_unique<Mover>(x,y,speed);
	auto y_i = mover->position()->getYPosition();
	mover->moveUp();
	auto y_f = mover->position()->getYPosition();
	CHECK(doctest::Approx(y_f) == (y_i-speed));	
	CHECK_FALSE(doctest::Approx(y_i) == y_f);
}//22

TEST_CASE("Mover cannot move up after reaching a certain set limit"){
	
	auto x = 284.0f;
	auto y = 450.0f;
	auto speed = 4.0f;
	auto mover = make_unique<Mover>(x,y,speed);
	auto y_i = mover->position()->getYPosition();
	mover->moveUp();
	auto y_f = mover->position()->getYPosition();
	CHECK(doctest::Approx(y_i) == (y_f));	

}//23
//***********************************************************************************
//*****************************Laser Tests*******************************************
TEST_CASE("Laser cannot have speed <= 0"){
	CHECK_THROWS_AS(Laser(250,550,EntityID::LASER,0),NegativeZeroLaserSpeed);
	CHECK_THROWS_AS(Laser(350,495,EntityID::LASER,-4.0),NegativeZeroLaserSpeed);
}//41
TEST_CASE("Laser can move up"){
	auto laser_x_position = 350.0f;
	auto laser_y_position = 550.0f;
	auto laser_entityID = EntityID::LASER;
	auto laser_speed = 4.0f;
	auto laser = make_unique<Laser>(laser_x_position,laser_y_position,laser_entityID,laser_speed);
	
	laser->move();
	auto returned_y_f = laser->position()->getYPosition();
	auto y_f = laser_y_position-laser_speed;
	
	CHECK(doctest::Approx(returned_y_f) == y_f);
}//42
TEST_CASE("only y-coordinate of Laser changes when it moves"){
	auto laser_x_position = 350.0f;
	auto laser_y_position = 550.0f;
	auto laser_entityID = EntityID::LASER;
	auto laser_speed = 4.0f;
	auto laser = make_unique<Laser>(laser_x_position,laser_y_position,laser_entityID,laser_speed);
	
	
	auto x_i = laser->position()->getXPosition();
	laser->move();
	auto x_f = laser->position()->getXPosition();
	auto false_x_f = x_i+laser_speed;
	auto false_x_f_2 = x_i-laser_speed;
	
	CHECK(doctest::Approx(x_i) == x_f);
	CHECK_FALSE(doctest::Approx(x_f) == false_x_f);
	CHECK_FALSE(doctest::Approx(x_f) == false_x_f_2);
	
	
}//43
TEST_CASE("Laser cannot move beyond screen borders"){
	auto laser_x_position = 350.0f;
	auto laser_y_position = 7.0f; //set border
	auto laser_entityID = EntityID::LASER;
	auto laser_speed = 4.0f;
	auto laser = make_unique<Laser>(laser_x_position,laser_y_position,laser_entityID,laser_speed);	
	auto laser_y_i = laser->position()->getYPosition();
	laser->move();
	auto laser_y_f = laser->position()->getYPosition();
	CHECK(doctest::Approx(laser_y_i) == laser_y_f);
}//44
TEST_CASE("Laser gets destroyed when it goes out of bound"){
	auto laser_x_position = 350.0f;
	auto laser_y_position = 7.0f;
	auto laser_entityID = EntityID::LASER;
	auto laser_speed = 4.0f;
	auto laser = make_unique<Laser>(laser_x_position,laser_y_position,laser_entityID,laser_speed);	
	CHECK(laser->isLive());
	laser->move();
	CHECK_FALSE(laser->isLive());
}//45
TEST_CASE("Correct Position is returned when Laser is subtituted with Entity instance"){
	auto laser_x_position = 350.0f;
	auto laser_y_position = 550.0f;
	auto laser_entityID = EntityID::LASER;
	auto laser_speed = 4.0f;
	auto laser = make_shared<Laser>(laser_x_position,laser_y_position,laser_entityID,laser_speed);

	auto[laser_x,laser_y] = laser->position()->getXYPosition();
	shared_ptr<Entity>parent_laser = laser;
	auto[parent_x,parent_y] = parent_laser->position()->getXYPosition();
	CHECK(doctest::Approx(laser_x) == parent_x);
	CHECK(doctest::Approx(laser_y) == parent_y);
}//46
TEST_CASE("Parent instance subtitute returns correct life state"){
	auto laser_x_position = 350.0f;
	auto laser_y_position = 550.0f;
	auto laser_entityID = EntityID::LASER;
	auto laser_speed = 4.0f;
	auto laser = make_shared<Laser>(laser_x_position,laser_y_position,laser_entityID,laser_speed);
	
	laser->destroy();
	shared_ptr<Entity>parent_laser = laser;
	auto laser_life = laser->isLive();
	auto parent_life = parent_laser->isLive();
	CHECK(laser_life == parent_life);
}//47
TEST_CASE("Parent instance substitute returns correct EntityID"){
	auto laser_x_position = 350.0f;
	auto laser_y_position = 550.0f;
	auto laser_entityID = EntityID::LASER;
	auto laser_speed = 4.0f;
	auto laser = make_shared<Laser>(laser_x_position,laser_y_position,laser_entityID,laser_speed);
	shared_ptr<Entity>parent_laser = laser;
	
	auto returned_laser_entityID = laser->getEntityID();
	auto parent_laser_id = parent_laser->getEntityID();
	CHECK(returned_laser_entityID == parent_laser_id);
	
}//48
//***********************************************************************************
//*****************************Player Tests*******************************************
TEST_CASE("Player can move left"){
	auto player_x_position = 400.0f;
	auto player_y_position = 580.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);
	
	auto x_initial = player->position()->getXPosition();
	
	player->move(Direction::LEFT);

	auto x_final = player->position()->getXPosition();
	
	
	CHECK(doctest::Approx(x_final) == (x_initial-player_speed));
	CHECK_FALSE(doctest::Approx(x_initial) == x_final);
}//24

TEST_CASE("Player cannot move left when at left screen border"){
	auto player_x_position = 0.0f;
	auto player_y_position = 580.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);
	
	auto x_initial = player->position()->getXPosition();
	
	player->move(Direction::LEFT);

	auto x_final = player->position()->getXPosition();
	
	
	CHECK(doctest::Approx(x_final) == (x_initial));
		
}//25

TEST_CASE("Player can move right"){
	auto player_x_position = 400.0f;
	auto player_y_position = 580.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);
	
	auto x_initial = player->position()->getXPosition();
	
	player->move(Direction::RIGHT);

	auto x_final = player->position()->getXPosition();
	
	
	CHECK(doctest::Approx(x_final) == (x_initial+player_speed));
	CHECK_FALSE(doctest::Approx(x_initial) == x_final);
}//26

TEST_CASE("Player cannot move right when at right screen border"){
	auto player_x_position = 784.0f;
	auto player_y_position = 580.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);
	
	auto x_initial = player->position()->getXPosition();
	
	player->move(Direction::RIGHT);

	auto x_final = player->position()->getXPosition();
	
	
	CHECK(doctest::Approx(x_final) == (x_initial));
		
}//27

TEST_CASE("Player can move up"){
	auto player_x_position = 400.0f;
	auto player_y_position = 580.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);
	
	auto y_initial = player->position()->getYPosition();
	
	player->move(Direction::UP);

	auto y_final = player->position()->getYPosition();
	
	
	CHECK(doctest::Approx(y_final) == (y_initial-player_speed));
	CHECK_FALSE(doctest::Approx(y_initial) == y_final);
}//28

TEST_CASE("Player cannot move up when at right screen border"){
	auto player_x_position = 300.0f;
	auto player_y_position = 450.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);
	
	auto y_initial = player->position()->getYPosition();
	
	player->move(Direction::UP);

	auto y_final = player->position()->getYPosition();
	
	
	CHECK(doctest::Approx(y_final) == (y_initial));
		
}//29

TEST_CASE("Player can move down"){
	auto player_x_position = 400.0f;
	auto player_y_position = 350.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);
	
	auto y_initial = player->position()->getYPosition();
	
	player->move(Direction::DOWN);

	auto y_final = player->position()->getYPosition();
	
	
	CHECK(doctest::Approx(y_final) == (y_initial+player_speed));
	CHECK_FALSE(doctest::Approx(y_initial) == y_final);
}//30

TEST_CASE("Player cannot move up when at right screen border"){
	auto player_x_position = 300.0f;
	auto player_y_position = 584.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);
	
	auto y_initial = player->position()->getYPosition();
	
	player->move(Direction::DOWN);

	auto y_final = player->position()->getYPosition();
	
	
	CHECK(doctest::Approx(y_final) == (y_initial));
		
}//31

TEST_CASE("Lasers container is initialy empty"){
	auto player_x_position = 300.0f;
	auto player_y_position = 584.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);
	
	auto initial_size = player->getLasers().size();
	auto size = 0;
	CHECK(initial_size == size);
	
}//32

TEST_CASE("Player's shoot function populates Lasers container"){
	auto player_x_position = 300.0f;
	auto player_y_position = 584.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);	
	
	auto initial_size = player->getLasers().size();
	player->shoot();
	auto final_size = player->getLasers().size();
	auto empty_size = 0;
	auto loaded_size = 1;
	CHECK(initial_size == empty_size);
	CHECK(final_size == loaded_size);
	CHECK_FALSE(initial_size == final_size);
	
}//33

TEST_CASE("Player cannot shoot more than five bullets at a time"){
	auto player_x_position = 300.0f;
	auto player_y_position = 584.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);

	for(auto i = 0; i != 15; i++)
		player->shoot();
	auto real_size = 5;
	auto false_size = 16;
	auto shot_size = player->getLasers().size();
	CHECK(real_size == shot_size);
	CHECK_FALSE(shot_size == false_size);
}//34
TEST_CASE("Player's Lasers container returns correct number of lasers"){
	auto player_x_position = 300.0f;
	auto player_y_position = 584.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);
	player->shoot();
	player->shoot();
	player->shoot();
	auto size = 3;
	auto lasers = player->getLasers().size();
	CHECK(lasers == size);
		
}//35
TEST_CASE("Player's Lasers container does not return incorrect number of lasers"){
	auto player_x_position = 300.0f;
	auto player_y_position = 584.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);
	
	player->shoot();
	auto false_size = 5;
	auto lasers_size = player->getLasers().size();
	CHECK_FALSE(lasers_size == false_size);
	
}//36

TEST_CASE("a Shot laser can move"){
	auto player_x_position = 300.0f;
	auto player_y_position = 584.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_unique<Player>(player_x_position,player_y_position,player_entity,player_speed);
	
	player->shoot();
	auto laser_iterator = begin(player->getLasers());
	auto laser_y_initial = (*laser_iterator)->position()->getYPosition();
	auto y_i = player_y_position-Constants::PLAYER_HEIGHT_;
	CHECK(laser_y_initial == y_i);
	player->updateLasers();
	auto laser_y_final = (*laser_iterator)->position()->getYPosition();
	auto laser_speed = 4.0;
	auto y_f = y_i-laser_speed;
	CHECK(doctest::Approx(laser_y_final) == y_f);
	
}//37

TEST_CASE("Correct Position is returned when player is substituted with Parent class instance"){
	auto player_x_position = 300.0f;
	auto player_y_position = 584.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_shared<Player>(player_x_position,player_y_position,player_entity,player_speed);
	shared_ptr<Entity>parent_player = player;
	auto[x_i,y_i] = player->position()->getXYPosition();
	auto[parent_x_position,parent_y_position] = parent_player->position()->getXYPosition();
	CHECK(doctest::Approx(x_i) == parent_x_position);
	CHECK(doctest::Approx(y_i) == parent_y_position);
}//38

TEST_CASE("Correct EntityID is returned when Player is substituted with parent class instance"){
	auto player_x_position = 300.0f;
	auto player_y_position = 584.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_shared<Player>(player_x_position,player_y_position,player_entity,player_speed);	
	shared_ptr<Entity>parent_player = player;
	auto parent_entityID = parent_player->getEntityID();
	auto returned_player_entityID = player->getEntityID();
	CHECK(parent_entityID == returned_player_entityID);
	
}//39
TEST_CASE("Correct life state is returned when Player is substituted with parent class instance"){
	auto player_x_position = 300.0f;
	auto player_y_position = 584.0f;
	auto player_speed = 5.0f;
	auto player_entity = EntityID::PLAYER;
	auto player = make_shared<Player>(player_x_position,player_y_position,player_entity,player_speed);	
	shared_ptr<Entity>parent_player = player;
	auto parent_life = parent_player->isLive();
	auto returned_player_life = player->isLive();
	CHECK(parent_life == returned_player_life);
}//40
//*************************************************************************************
////**************************Mover tests********************************************
//TEST_CASE("Speed cannot be less than or equal to zero"){
//	
//		auto position = make_shared<Position>(150,350);
//		auto negative_speed = -10;
//		CHECK_THROWS_AS(Mover(position,negative_speed),NegativeZeroSpeed);
//		auto zero_speed = 0;
//		CHECK_THROWS_AS(Mover(position,zero_speed),NegativeZeroSpeed);
//}
//TEST_CASE("Position attribute returns correct values"){
//
//		auto position = make_shared<Position>(400,300);
//		auto speed = 3;
//		auto position_attribute = make_shared<Mover>(position,speed);
//		auto x = 400;
//		auto y = 300;
//		
//		auto[x_attribute,y_attribute] = position_attribute->position()->getPosition();
//
//		CHECK(x == x_attribute);
//		CHECK(y == y_attribute);
//		CHECK_FALSE(x_attribute == y_attribute);
//}
//
//TEST_CASE("Position attribute changes accordingly when moving left"){
//	
//		auto position = make_shared<Position>(400,300);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::LEFT);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = 395;
//		auto new_y = 300;
//		CHECK(new_x == new_x_pos);
//		CHECK(new_y == new_y_pos);
//		CHECK_FALSE(old_x_pos == new_x_pos);
//}
//
//TEST_CASE("Cannot move left when x position is zero"){
//		auto position = make_shared<Position>((Constants::PLAYER_WIDTH_/2),300);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::LEFT);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = Constants::PLAYER_WIDTH_/2;
//		auto new_y = 300;
//		CHECK(new_x == new_x_pos);
//		CHECK(new_y == new_y_pos);
//		CHECK_FALSE(old_x_pos != new_x_pos);		
//}
//
//TEST_CASE("Position attribute returns correct values after moving right"){
//	
//		auto position = make_shared<Position>(300,400);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::RIGHT);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = 305;
//		auto new_y = 400;
//		CHECK(new_x == new_x_pos);
//		CHECK(new_y == new_y_pos);
//		CHECK_FALSE(old_x_pos == new_x_pos);
//}
//
//TEST_CASE("Cannot move right when x = Display width"){
//		auto position = make_shared<Position>(Constants::DISPLAY_WIDTH_-(Constants::PLAYER_WIDTH_/2),500);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::RIGHT);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = Constants::DISPLAY_WIDTH_-(Constants::PLAYER_WIDTH_/2);
//		auto new_y = 500;
//		CHECK(new_x == new_x_pos);
//		CHECK(new_y == new_y_pos);
//		CHECK_FALSE(old_x_pos != new_x_pos);		
//}
//
//TEST_CASE("Position attribute changes accordingly when moving up"){
//		auto position = make_shared<Position>(300,400);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::UP);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = 300;
//		auto new_y = 395;
//		CHECK(new_x == new_x_pos);
//		CHECK(new_y == new_y_pos);
//		CHECK_FALSE(old_y_pos == new_y_pos);
//}
//
//TEST_CASE("Cannot move up at y = 0"){
//		auto position = make_shared<Position>(300,Constants::PLAYER_HEIGHT_/2);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::UP);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = 300;
//		auto new_y = Constants::PLAYER_HEIGHT_/2;
//		CHECK(new_x == new_x_pos);
//		CHECK(new_y == new_y_pos);
//		CHECK_FALSE(old_y_pos != new_y_pos);
//}
//
//TEST_CASE("Position attributes changes accordingly when moving down"){
//		auto position = make_shared<Position>(200,300);
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::DOWN);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = 200;
//		auto new_y = 305;
//		CHECK(new_x == new_x_pos);
//		CHECK(new_y == new_y_pos);
//		CHECK_FALSE(old_y_pos == new_y_pos);		
//}
//TEST_CASE("Cannot move down when y = screen height"){
//		auto position = make_shared<Position>(300,Constants::DISPLAY_HEIGHT_-(Constants::PLAYER_HEIGHT_/2));
//		auto speed = 5;
//		
//		auto move_attribute = make_shared<Mover>(position,speed);
//		auto[old_x_pos,old_y_pos] = move_attribute->position()->getPosition();
//		move_attribute->move(Direction::DOWN);
//		auto[new_x_pos,new_y_pos] = move_attribute->position()->getPosition();
//		
//		auto new_x = 300;
//		auto new_y = Constants::DISPLAY_HEIGHT_-(Constants::PLAYER_HEIGHT_/2);
//		CHECK(new_x == new_x_pos);
//		CHECK(new_y == new_y_pos);
//		CHECK_FALSE(old_y_pos != new_y_pos);	
//}
////************************end of Mover tests (10 tests)*******************************
//
////***********************Bullet Tests*************************************************
//TEST_CASE("Position attribute of bullet returns correct values upon construction"){
//    
//    auto bullet_position = make_shared<Position>(50,100);
//    auto speed = 5;
//    auto mover = make_shared<Mover>(bullet_position,speed);
//    auto bullet = make_shared<Bullet>(mover);
//    
//    auto[x_position,y_position] = bullet->attribute()->position()->getPosition();
//    auto x = 50;
//    auto y = 100;
//    
//    CHECK(x == x_position);
//    CHECK(y == y_position);
//}
//
//TEST_CASE("Position attribute of bullet returns correct values after using setter function"){
//        
//    auto bullet_setter_position = make_shared<Position>(150,250);
//    auto speed_ = 5;
//    auto mover = make_shared<Mover>(bullet_setter_position,speed_);
//    auto bullet = make_shared<Bullet>(mover);
//    auto[old_x,old_y] = bullet->attribute()->position()->getPosition();
//    bullet->attribute()->position()->setPosition(800,600);
//    auto[new_x,new_y] = bullet->attribute()->position()->getPosition();
//    auto x = 800;
//    auto y = 600;
//    
//    CHECK(x == new_x);
//    CHECK(y == new_y);
//    CHECK_FALSE(new_x == old_x);
//    CHECK_FALSE(new_y == old_y);
//}
//
//TEST_CASE("Move attribute of bullet changes its position as expected when moving"){
//        
//    auto bullet_mover_position = make_shared<Position>(400,300);
//    auto speed = 5;
//    auto bullet_mover = make_shared<Mover>(bullet_mover_position,speed);
//    auto bullet_ = make_shared<Bullet>(bullet_mover);
//    auto[x_initial,y_initial] = bullet_->attribute()->position()->getPosition();
//    bullet_->attribute()->move(Direction::UP);
//    auto[x_final,y_final] = bullet_->attribute()->position()->getPosition();
//    auto y = 295;
//    CHECK(y == y_final);
//    CHECK_FALSE(y_initial == y_final);
//    
//}
//
//TEST_CASE("cannot move bullet when y = 0"){
//        
//        auto position = make_shared<Position>();
//        auto speed = 3;
//        auto mover = make_shared<Mover>(position,speed);
//        auto bullet = make_shared<Bullet>(mover);
//        auto[x_i,y_i] = bullet->attribute()->position()->getPosition();
//        bullet->attribute()->move(Direction::UP);
//        auto[x_f,y_f] = bullet->attribute()->position()->getPosition();
//        CHECK(x_i == x_f);
//        CHECK(y_i == y_f);
//} //maybe its life after testing player...4 bullet tests- total tests = 19
//
////*************************Segment Tests***************************************
//TEST_CASE("Position atttribute of segment behaves correctly (getter)"){
//    
//        auto seg_position = make_shared<Position>(450,550);
//        auto speed = 5;
//        auto seg_mover = make_shared<Mover>(seg_position,speed);
//        auto segment = make_shared<Segment>(seg_mover);
//        auto[x_position,y_position] = segment->attribute()->position()->getPosition(); 
//        auto x = 450;
//        auto y = 550;
//        CHECK(x == x_position);
//        CHECK(y == y_position);
//        
//}//20
//
//TEST_CASE("Segment position attribute (setter)"){
//        
//        auto seg_position = make_shared<Position>();
//        auto speed = 3;
//        auto seg_mover = make_shared<Mover>(seg_position,speed);
//        auto segment = make_shared<Segment>(seg_mover);
//        auto[x_initial,y_initial] = segment->attribute()->position()->getPosition(); 
//        segment->attribute()->position()->setPosition(150,350);
//        auto[x_final,y_final] = segment->attribute()->position()->getPosition();
//        auto x = 150;
//        auto y = 350;
//        CHECK(x == x_final);
//        CHECK(y == y_final);
//        CHECK_FALSE(x_initial == x_final);
//        CHECK_FALSE(y_initial == y_final);
//}//21
//
//TEST_CASE("Segment movement attribute (left and right"){
//    
//        auto position = make_shared<Position>();
//        auto speed = 5;
//        auto mover = make_shared<Mover>(position,speed);
//        auto segment = make_shared<Segment>(mover);
//        auto[x_initial,y_initial] = segment->attribute()->position()->getPosition();
//        segment->attribute()->move(Direction::RIGHT);
//        segment->attribute()->move(Direction::RIGHT);
//        auto[x_final_right,y_final_right] = segment->attribute()->position()->getPosition();
//        auto x = 10;
//        CHECK(x == x_final_right);
//        CHECK(y_initial == y_final_right);
//        segment->attribute()->move(Direction::LEFT);
//        auto[x_final_left,y_final_left] = segment->attribute()->position()->getPosition();
//        auto x2 = 5;
//        CHECK(x2 == x_final_left);
//        CHECK_FALSE(x_final_left == x_final_right);
//        
//}//22
////
//TEST_CASE("Segment movement attribute (up and down)"){
//
//        auto position = make_shared<Position>();
//        auto speed = 5;
//        auto mover = make_shared<Mover>(position,speed);
//        auto segment = make_shared<Segment>(mover);
//        auto[x_initial,y_initial] = segment->attribute()->position()->getPosition();
//        segment->attribute()->move(Direction::DOWN);
//        segment->attribute()->move(Direction::DOWN);
//        auto[x_final_down,y_final_down] = segment->attribute()->position()->getPosition();
//        auto y = 10;
//        CHECK(y == y_final_down);
//        CHECK(x_initial == x_final_down);
//        segment->attribute()->move(Direction::UP);
//        auto[x_final_up,y_final_up] = segment->attribute()->position()->getPosition();
//        auto y2 = 5;
//        CHECK(y2 == y_final_up);
//        CHECK_FALSE(y_final_up == y_final_down);
//        
//}//23********************************end of segment test***********************************
//
////************************************Centipede tests*******************************************
//
//TEST_CASE("Centipede size cannot be <= 0"){
//        const int  centipedeSize = -15;
//        auto centipede = make_shared<Centipede>(centipedeSize);
//        CHECK_THROWS_AS(Centipede(-15),InsufficientCentipedeSize);
//        
//}//24
//
////*********************************centipede tests*****************************************
////TEST_CASE("Centipede knows its size(getCentipede)"){
////    
////        auto centipedeSize = 3;
////        auto centipede = make_shared<Centipede>(centipedeSize);
////        auto  centipede_size = centipede->size();
////        
////        CHECK(centipedeSize = centipede_size);
//////        CHECK(1 == 1);
////}//25
//
////TEST_CASE(""){
////        
////}
