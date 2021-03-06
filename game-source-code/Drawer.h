#ifndef DRAWER_H
#define DRAWER_H

//#include "Player.h"
//#include "Centipede.h"
//#include "Segment.h"
//#include "Position.h"
#include "Display.h"
//#include "DataBank.h"
//#include "Bullet.h"
//#include "Constants.h"
//#include "Mushroom.h"
//#include "Field.h"
//#include "Constants.h"

#include "DrawablesLoader.h"
#include "MushroomDrawable.h"
#include "Entity.h"
#include "Drawable.h"
#include "PlayerDrawable.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>


#include <memory>
using std::shared_ptr;
using std::make_shared;
using std::unique_ptr;
using std::make_unique;
#include <list>
using std::list;
#include <string>
using std::string;


class Drawer{
	
public:
		Drawer(shared_ptr<sf::RenderWindow> window);
//      void drawPlayer(shared_ptr<Player> player);
//      void drawCentipede(shared_ptr<Centipede> centipede);
//		void drawBullets(shared_ptr<Player> player);
//		void drawField(shared_ptr<Field> field);
		void drawGameObjects(list<shared_ptr<Entity>>& entities);

//		void drawPauseMessage();
//		void drawGameOverMessage(const string& wonOrLost);
		
		

private:
//		list<shared_ptr<Drawable> drawables_;
//		unique_ptr<DataBank> data_;
		sf::Text text_;
		shared_ptr<sf::RenderWindow> window_;
//		Sprites object_sprites_;
//		void drawSegment(shared_ptr<Segment> segment); 
//      void drawBullet(shared_ptr<Bullet>bullet);
//		void drawMushroom(shared_ptr<Mushroom> mushroom);
		
};

#endif // DRAWER_H_INCLUDED