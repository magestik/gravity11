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
		case Shape::BOX:
		{
			BodyPtr<Box> pTypedBody(b1);
			collision = handleIntersection(pTypedBody, b2);
		}
		break;

		case Shape::CIRCLE:
		{
			BodyPtr<Circle> pTypedBody(b1);
			collision = handleIntersection(pTypedBody, b2);
		}
		break;

		case Shape::SEGMENT:
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
		case Shape::BOX:
		{
			BodyPtr<Box> pTypedBody2(b2);
			collision = handleIntersection(pTypedBody1, pTypedBody2);
		}
		break;

		case Shape::CIRCLE:
		{
			BodyPtr<Circle> pTypedBody2(b2);
			collision = handleIntersection(pTypedBody1, pTypedBody2);
		}
		break;

		case Shape::SEGMENT:
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
	return(false);
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
	return(false);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pCircle
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Circle> & pCircle, BodyPtr<Circle> & pShape)
{
	return(false);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pCircle
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Circle> & pCircle, BodyPtr<Segment> & pShape)
{
	return(false);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pSegment
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Segment> & pSegment, BodyPtr<Box> & pShape)
{
	return(false);
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

