#include "GameEngine.h"

GameEngine::GameEngine():
			display_(make_shared<Display>())
			,drawer_(make_shared<Drawer>(display_->getWindow()))
//			,position_(make_shared<Position>(Constants::DISPLAY_WIDTH_/2,(Constants::DISPLAY_HEIGHT_-50)))
//            ,mover(make_shared<Mover>(position_,5))
			,player_(make_shared<Player>(Constants::DISPLAY_WIDTH_/2,(Constants::DISPLAY_HEIGHT_-50),EntityID::PLAYER,5.0))
//            ,centipede_(make_shared<Centipede>(Constants::INITIAL_SIZE_OF_CENTIPEDE_))
			,field_(make_shared<Field>(Constants::NUMBER_OF_MUSHROOMS))
			,playing_(true)
			,game_over_(false)
{
		if (display_== nullptr) throw WindowNotCreated();
}

void GameEngine::playGame(){
//	splashScreen();
	
	while(display_->isOpen()){
			
		if((playing_)&&(!game_over_)){//playing
			checkInput();
			update();
			drawObjects();
			display_->display();
			display_->clear();
					
		}
		else if ((!playing_)&&(!game_over_)){//paused
			checkInput();
			drawObjects();
//			displayPauseMessage();
		}
		else if(game_over_){//game over
			checkInput();
			drawObjects();
//			displayGameOverMessage();

		}
	}
}

//void GameEngine::splashScreen(){
//	SplashScreen welcome_screen(display_->getWindow());
//	welcome_screen.drawSplashScreen();
//}

void GameEngine::update(){
//		auto updator = make_shared<Update>();
//		updator->updateGame(player_,key_,centipede_,field_);	
//		gameStatus();

	switch(key_){
			case Pressed::RIGHT:
				player_->move(Direction::RIGHT);
				break;
			case Pressed::LEFT:
				player_->move(Direction::LEFT);
				break;
			case Pressed::UP:
				player_->move(Direction::UP);
				break;
			case Pressed::DOWN:
				player_->move(Direction::DOWN);
				break;
			case Pressed::SPACE:
				player_->shoot();
				break;
		
	}
	player_->updateLasers();

		
		

}

void GameEngine::checkInput(){
	
	KeyBoard key_read;
	key_ = key_read.readKey(display_->getWindow());
	
	if(key_ == Pressed::P)
		playing_ = !playing_;
	else if(key_ == Pressed::ESCAPE)
		display_->close();
}

void GameEngine::drawObjects(){

//	drawer_->drawField(field_);
//    drawer_->drawPlayer(player_);
//    drawer_->drawCentipede(centipede_);
//	drawer_->drawBullets(player_);

	shared_ptr<Entity>game_object = player_;
	game_objects_.push_back(game_object);
	
	for(auto& laser:player_->getLasers()){
		game_object = laser;
		game_objects_.push_back(game_object);
	}
	for(auto& mushroom:field_->getMushrooms()){
		game_object = mushroom;
		game_objects_.push_back(game_object);
	}
	
	drawer_->drawGameObjects(game_objects_);
	

}
//void GameEngine::displayPauseMessage(){
//	drawer_->drawPauseMessage();
//	display_->display();
//	display_->clear();
//}
//void GameEngine::displayGameOverMessage(){
//	if(auto over = "won";player_->attribute()->isLive()){
//		drawer_->drawGameOverMessage(over);
//		display_->display();
//		display_->clear();
//	}
//	else if(auto over = "lost";!player_->attribute()->isLive()){
//		drawer_->drawGameOverMessage(over);
//		display_->display();
//		display_->clear();
//	}
//}




//void GameEngine::gameStatus(){
//		if ((!player_->attribute()->isLive())||(centipede_->getCentipede().empty())){
//						game_over_ = true;
//						playing_ = false;
//			
//		}
//}
//
