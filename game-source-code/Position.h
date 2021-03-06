#ifndef POSITION_H
#define POSITION_H

#include "Constants.h"

#include <tuple>
using std::tuple;

class NegativePosition{};
class OutOfBounds{};

class Position{
public:
	Position(float x_position = 0, float y_position = 0); 
	tuple<float,float>getXYPosition()const;
	float getXPosition();
	float getYPosition();
	void setXYPosition(float x, float y);
	void setXPosition(float x);
	void setYPosition(float y);
private:
	float x_position_;
	float y_position_;
};
#endif // POSITION_H