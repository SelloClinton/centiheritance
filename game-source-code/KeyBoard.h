#ifndef KEYBOARD_H
#define KEYBOARD_H


#include "Enums.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
using std::shared_ptr;


class KeyBoard{
	
public:
	Pressed readKey(shared_ptr<sf::RenderWindow> window);
		
};

#endif 