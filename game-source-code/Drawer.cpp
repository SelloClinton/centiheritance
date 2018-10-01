#include "Drawer.h"

Drawer::Drawer(shared_ptr<sf::RenderWindow> window):
//		data_(make_unique<DataBank>()),
		window_(window)	//,
//		object_sprites_(data_->getSprites())
		
{
	if(window_ == nullptr) throw WindowNotCreated();
}

void Drawer::drawGameObjects(list<shared_ptr<Entity>>& entities){
//	auto numberOfEntities = entities.size();
//	auto drawables_loader = make_unique<DrawablesLoader>(entities,numberOfEntities);
//	auto drawables = drawables_loader->loadDrawables();
//	
//	auto entities_iterator = begin(entities);
//	auto drawables_iterator = begin(drawables);
	
	
	for(auto& entity:entities){
		auto drawable_loader = make_shared<DrawablesLoader>();
		auto drawable = drawable_loader->loadDrawable(entity->getEntityID());
		auto[drawable_x_position,drawable_y_position] = entity->position()->getXYPosition();
		drawable->setPosition(drawable_x_position,drawable_y_position);
		drawable->createDrawable();
		window_->draw(*(drawable->getDrawable()));
	}
//	while((entities_iterator != end(entities)&&(drawables_iterator != end(drawables)))){
//		(*drawables_iterator)->createDrawable();
//		auto[x,y] = (*entities_iterator)->position()->getXYPosition();
//		(*drawables_iterator)->setPosition(x,y);
////		window_->draw(*((*drawables_iterator)->getDrawable()));
//		window_->draw(*(*drawables_iterator)->getDrawable());
//		
//	}
	
//	for(auto& drawable:drawables){
//		drawable->createDrawable();
//		window_->draw(*(drawable->getDrawable()));
//	}
	
}

//void Drawer::drawPlayer(shared_ptr<Player> player){
//	
//	auto[x_position,y_position] = player->attribute()->position()->getPosition();
//	
//	auto player_sprite = make_shared<DrawableLoader>(Object::PLAYER);
//	player_sprite->setPosition(x_position,y_position);
//	window_->draw(*(player_sprite->getDrawable()));
//}

//void Drawer::drawCentipede(shared_ptr<Centipede> centipede){
//    
//	auto segments = centipede->getCentipede();
//
//	for(const auto& segment:segments){
//			drawSegment(segment);
//	}
//        
//}

//void Drawer::drawBullets(shared_ptr<Player>player){
//    
//    auto bullets = player->getBullets();
//    
//    for(const auto& bullet:bullets){
//            drawBullet(bullet);
//    }	
//		
//}
//void Drawer::drawField(shared_ptr<Field> field){
//	
//	auto mushrooms = field->getMushrooms();
//
//	for(const auto& mushroom:mushrooms){
//			drawMushroom(mushroom);
//		}
//}

//void Drawer::drawPauseMessage(){
//	
//	sf::Text text;
//	auto font = data_->getFont();
//	text.setFillColor(sf::Color::Green);
//	text.setFont(font);
//	text.setCharacterSize(25);
//	text.setString("GAME PAUSED .... PRESS   P   TO RESUME");
//	text.setPosition(100,250);
//	window_->draw(text);
//
//	
//}

//void Drawer::drawGameOverMessage(const string& wonOrLost){
//	sf::Text text;
//	auto font = data_->getFont();
//	text.setFont(font);
//	text.setFillColor(sf::Color::Green);
//	text.setCharacterSize(25);
//	if (auto str = "won"; wonOrLost == str)
//		text.setString("YOU WON!...PRESS ESCAPE TO GO TO MAIN MENU");
//	else{
//	text.setFillColor(sf::Color::Red);
//	text.setString("YOU LOST!...PRESS ESCAPE TO GO TO MAIN MENU");
//	}
//	text.setPosition(50,250);
//	window_->draw(text);
//
//}

//void Drawer::drawSegment(shared_ptr<Segment> segment){
//	
//	auto[x_position,y_position] = segment->attribute()->position()->getPosition();
//	auto segment_sprite = make_shared<DrawableLoader>(Object::SEGMENT);//object_sprites_.at(1);
//	segment_sprite->setPosition(x_position,y_position);
//	window_->draw(*(segment_sprite->getDrawable()));
//
//}

//void Drawer::drawBullet(shared_ptr<Bullet>bullet){
//	auto[x_position,y_position] = bullet->attribute()->position()->getPosition();
//	auto bullet_sprite = make_shared<DrawableLoader>(Object::BULLET);
//	bullet_sprite->setPosition(x_position,y_position);
//	window_->draw(*(bullet_sprite->getDrawable()));
//
//}

//void Drawer::drawMushroom(shared_ptr<Mushroom> mushroom){
//	auto[x_position,y_position] = mushroom->position()->getPosition();
//	auto mushroom_sprite = make_shared<DrawableLoader>(Object::MUSHROOM);
//	mushroom_sprite->setPosition(x_position,y_position); //setPosition(x_position,y_position);
//	window_->draw(*(mushroom_sprite->getDrawable()));
//}