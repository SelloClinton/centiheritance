#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Display.h"
#include "Drawer.h"
#include "KeyBoard.h"
#include "Mover.h"
#include "Player.h"
//#include "Position.h"
//#include "SplashScreen.h"
//#include "Centipede.h"
#include "Constants.h"
//#include "Box.h"
//#include "CollisionDetection.h"
//#include "CollisionReaction.h"
#include "Field.h"
#include "Mushroom.h"
//#include "Update.h"

#include "Enums.h"
#include "Laser.h"

#include <memory>
#include <list>
using namespace std;
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;

class GameEngine{
		
public:
	GameEngine();
	void playGame();
private:
	shared_ptr<Display> display_;
	shared_ptr<Drawer> drawer_;
//	shared_ptr<Position> position_;
//    shared_ptr<Position> pos;
//    shared_ptr<Mover> mover;
//    shared_ptr<Mover> mover2;
	shared_ptr<Player> player_;
//	shared_ptr<Centipede> centipede_;
	shared_ptr<Field> field_;
	list<shared_ptr<Entity>> game_objects_;
	Pressed key_;
	bool game_over_;
	bool playing_;
	
	void splashScreen();
	void update();
    void updateCentipede(shared_ptr<Field> field);
	void checkInput();
//	void keyReaction(Pressed key);
	void handleInput();
	void drawObjects();
	void displayPauseMessage();
	void displayGameOverMessage();
	bool checkCollision();
	void checkPlayerCollision();
	void gameStatus();
	void checkBulletMushroomCollision();
};

#endif