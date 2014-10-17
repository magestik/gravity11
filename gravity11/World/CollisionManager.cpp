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

#include <gravity11.h>

#include "CollisionManager.h"

#include "../Body/Shape/Shape.h"
#include "../Body/Shape/Box.h"
#include "../Body/Shape/Circle.h"
#include "../Body/Shape/Segment.h"

namespace gravity11
{

/**
 * @brief CollisionManager::CollisionManager
 */
CollisionManager::CollisionManager(void)
{
	// ...
}

/**
 * @brief CollisionManager::~CollisionManager
 */
CollisionManager::~CollisionManager(void)
{
	// ...
}

/**
 * @brief CollisionManager::handleIntersections
 * @param b1
 * @param b2
 */
bool CollisionManager::handleIntersection(Body * b1, Body * b2)
{
	bool collision = false;

	Shape * pShape = b1->getShape();

	switch (pShape->getType())
	{
		case BOX:
		{
			BodyPtr<Box> pTypedBody(b1);
			collision = handleIntersection(pTypedBody, b2);
		}
		break;

		case CIRCLE:
		{
			BodyPtr<Circle> pTypedBody(b1);
			collision = handleIntersection(pTypedBody, b2);
		}
		break;

		case SEGMENT:
		{
			BodyPtr<Segment> pTypedBody(b1);
			collision = handleIntersection(pTypedBody, b2);
		}
		break;
	}

	return(collision);
}

/**
 *
 */
template<typename T>
bool CollisionManager::handleIntersection(BodyPtr<T> & pTypedBody1, Body * b2)
{
	bool collision = false;

	Shape * pShape = b2->getShape();

	switch (pShape->getType())
	{
		case BOX:
		{
			BodyPtr<Box> pTypedBody2(b2);
			collision = handleIntersection(pTypedBody1, pTypedBody2);
		}
		break;

		case CIRCLE:
		{
			BodyPtr<Circle> pTypedBody2(b2);
			collision = handleIntersection(pTypedBody1, pTypedBody2);
		}
		break;

		case SEGMENT:
		{
			BodyPtr<Segment> pTypedBody2(b2);
			collision = handleIntersection(pTypedBody1, pTypedBody2);
		}
		break;
	}

	return(collision);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pBox
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Box> & pBox, BodyPtr<Box> & pShape)
{
	return(false);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pBox
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Box> & pBox, BodyPtr<Circle> & pShape)
{
	return(handleIntersection(pShape, pBox));
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pBox
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Box> & pBox, BodyPtr<Segment> & pShape)
{
	return(false);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pCircle
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Circle> & pCircle, BodyPtr<Box> & pShape)
{
	const vec2 & pos1	= pCircle.getPosition();
	const vec2 & pos2	= pShape.getPosition();

	float halfWidth		= pShape.getShape()->getHalfWidth();
	float halfHeight	= pShape.getShape()->getHalfHeight();
	float radius		= pCircle.getShape()->getRadius();

	// Test X-distance
	float dx = fabs(pos1.x - pos2.x);

	if (dx > (halfWidth + radius))
	{
		return(false);
	}

	// Test Y-distance
	float dy = fabs(pos1.y - pos2.y);

	if (dy > (halfHeight + radius))
	{
		return(false);
	}

	// Is the collision happening ?
	if (dx <= halfWidth || dy <= halfHeight)
	{
		return(true);
	}

	// Test corner distance
	float cornerDistX = dx - halfWidth;
	float cornerDistY = dy - halfHeight;

	float d = (cornerDistX*cornerDistX) + (cornerDistY*cornerDistY);
	float r = radius * radius;

	return(d < r);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pCircle
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Circle> & pCircle, BodyPtr<Circle> & pShape)
{
	const vec2 & pos1	= pCircle.getPosition();
	const vec2 & pos2	= pShape.getPosition();
	float radius		= pCircle.getShape()->getRadius() + pShape.getShape()->getRadius();

	float dx = fabs(pos1.x - pos2.x);
	float dy = fabs(pos1.x - pos2.x);

	float d = (dx*dx) + (dy*dy);
	float r = radius * radius;

	return(d < r);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pCircle
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Circle> & pCircle, BodyPtr<Segment> & pShape)
{
	return(handleIntersection(pShape, pCircle));
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pSegment
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Segment> & pSegment, BodyPtr<Box> & pShape)
{
	return(handleIntersection(pShape, pSegment));
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pSegment
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Segment> & pSegment, BodyPtr<Circle> & pShape)
{
	return(false);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pSegment
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Segment> & pSegment, BodyPtr<Segment> & pShape)
{
	return(false);
}

}

