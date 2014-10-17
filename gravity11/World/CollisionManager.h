/*
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.
 */

#pragma once

#include "../Body/Shape/Shape.h"

namespace gravity11
{

class Body;
class Box;
class Circle;
class Segment;

class CollisionManager
{

	template<typename T>
	struct BodyPtr
	{
		BodyPtr(Body * b) : pBody(b) { /* ... */ }
		BodyPtr(const BodyPtr &) = delete;
		T * getShape() { return((T*)(pBody->getShape())); }
		vec2 & getPosition() { return(pBody->getPosition()); }
		Body * pBody;
	};

public:

	CollisionManager(void);
	~CollisionManager(void);

	bool handleIntersection	(Body * b1,	Body * b2);

	template<typename T>
	bool handleIntersection	(BodyPtr<T> & b1, Body * b2);

	//
	// Real functions starts here
	//

	bool handleIntersection (BodyPtr<Box> & pBox, BodyPtr<Box> & pShape);
	bool handleIntersection (BodyPtr<Box> & pBox, BodyPtr<Circle> & pShape);
	bool handleIntersection (BodyPtr<Box> & pBox, BodyPtr<Segment> & pShape);

	bool handleIntersection (BodyPtr<Circle> & pCircle, BodyPtr<Box> & pShape);
	bool handleIntersection (BodyPtr<Circle> & pCircle, BodyPtr<Circle> & pShape);
	bool handleIntersection (BodyPtr<Circle> & pCircle, BodyPtr<Segment> & pShape);

	bool handleIntersection (BodyPtr<Segment> & pSegment, BodyPtr<Box> & pShape);
	bool handleIntersection (BodyPtr<Segment> & pSegment, BodyPtr<Circle> & pShape);
	bool handleIntersection (BodyPtr<Segment> & pSegment, BodyPtr<Segment> & pShape);
};

}
