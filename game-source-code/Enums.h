#ifndef ENUMS_H
#define ENUMS_H

enum class EntityID{
		PLAYER,
		LASER,
		HEAD_SEGMENT_FACING_LEFT,
		HEAD_SEGMENT_FACING_RIGHT,
		HEAD_SEGMENT_FACING_UP,
		HEAD_SEGMENT_FACING_DOWN,
		MID_SEGMENT_FACING_RIGHT,
		MID_SEGMENT_FACING_LEFT,
		MID_SEGMENT_FACING_UP,
		MID_SEGMENT_FACING_DOWN,
		STRONG_MUSHROOM,
		WEAK_MUSHROOM,
		WEAKER_MUSHROOM,
		WEAKEST_MUSHROOM
};

enum class Pressed{
		RIGHT,
		LEFT,
		UP,
		DOWN,
		SPACE,
		P,
		S,
		ESCAPE,
		NONE
};
enum class Direction{
		LEFT,
		RIGHT,
		UP,
		DOWN
};
//enum class Body_Part{
//		HEAD,
//		MIDSECTION
//};
//enum class Segment_Heading{
//		UP,
//		DOWN,
//		LEFT,
//		RIGHT
//};

class Enums{
	
};
#endif

