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

#include "Collision.h"

#include "../Body/Shape/Shape.h"
#include "../Body/Shape/Box.h"
#include "../Body/Shape/Circle.h"
#include "../Body/Shape/Line.h"
#include "../Body/Shape/Segment.h"

#define sign(d) ((d > 0) ? 1 : -1)
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
bool CollisionManager::handleIntersection(Body * b1, Body * b2, Collision & result1, Collision & result2)
{
	bool collision = false;

	Shape * pShape = b1->getShape();

	switch (pShape->getType())
	{
		case BOX:
		{
			BodyPtr<Box> pTypedBody(b1);
			collision = handleIntersection(pTypedBody, b2, result2);
		}
		break;

		case CIRCLE:
		{
			BodyPtr<Circle> pTypedBody(b1);
			collision = handleIntersection(pTypedBody, b2, result2);
		}
		break;

		case LINE:
		{
			BodyPtr<Line> pTypedBody(b1);
			collision = handleIntersection(pTypedBody, b2, result2);
		}
		break;
	}

	if (collision)
	{
		result2.invMassTotal		= b1->getInvLinearMass() + b2->getInvLinearMass();
		result2.relativeVelocity	= b2->getLinearVelocity() - b1->getLinearVelocity();

		result1.normal.x			= - result2.normal.x;
		result1.normal.y			= - result2.normal.y;
		result1.relativeVelocity.x	= - result2.relativeVelocity.x;
		result1.relativeVelocity.y	= - result2.relativeVelocity.y;
		result1.invMassTotal		= result2.invMassTotal;
	}

	return(collision);
}

/**
 *
 */
template<typename T>
bool CollisionManager::handleIntersection(BodyPtr<T> & pTypedBody1, Body * b2, Collision & result)
{
	bool collision = false;

	Shape * pShape = b2->getShape();

	switch (pShape->getType())
	{
		case BOX:
		{
			BodyPtr<Box> pTypedBody2(b2);
			collision = handleIntersection(pTypedBody1, pTypedBody2, result);
		}
		break;

		case CIRCLE:
		{
			BodyPtr<Circle> pTypedBody2(b2);
			collision = handleIntersection(pTypedBody1, pTypedBody2, result);
		}
		break;

		case LINE:
		{
			BodyPtr<Line> pTypedBody2(b2);
			collision = handleIntersection(pTypedBody1, pTypedBody2, result);
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
bool CollisionManager::handleIntersection(BodyPtr<Box> & pBox, BodyPtr<Box> & pShape, Collision & result)
{
	const vec2 & pos1	= pBox.getPosition();
	const vec2 & pos2	= pShape.getPosition();

	float halfWidth1	= pBox.getShape()->getHalfWidth();
	float halfHeight1	= pBox.getShape()->getHalfHeight();

	float halfWidth2	= pShape.getShape()->getHalfWidth();
	float halfHeight2	= pShape.getShape()->getHalfHeight();

	float dx = pos1.x - pos2.x;
	float dy = pos1.y - pos2.y;

	if (fabsf(dx) > (halfWidth1 + halfWidth2))
	{
		return false;
	}

	if (fabsf(dy) > (halfHeight1 + halfHeight2))
	{
		return false;
	}

	// left/right
	if (fabsf(dx) < halfWidth1+halfWidth2)
	{
		if (fabsf(dy) < halfHeight1)
		{
			result.normal = vec2(sign(dx), 0.0f);
			return(true);
		}
	}

	// top/bottom
	if (fabsf(dy) < halfHeight1+halfHeight2)
	{
		if (fabsf(dx) < halfWidth1)
		{
			result.normal = vec2(0.0f, sign(dy));
			return(true);
		}
	}

	return(false);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pBox
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Box> & pBox, BodyPtr<Circle> & pShape, Collision & result)
{
	bool collided = handleIntersection(pShape, pBox, result);
	result.normal.x = - result.normal.x;
	result.normal.y = - result.normal.y;
	return(collided);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pBox
 * @param pShape
 * @param result
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Box> & pBox, BodyPtr<Line> & pShape, Collision &result)
{
	bool collided = handleIntersection(pShape, pBox, result);
	result.normal.x = - result.normal.x;
	result.normal.y = - result.normal.y;
	return(collided);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pCircle
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Circle> & pCircle, BodyPtr<Box> & pShape, Collision & result)
{
	const vec2 & pos1	= pCircle.getPosition();
	const vec2 & pos2	= pShape.getPosition();

	float halfWidth		= pShape.getShape()->getHalfWidth();
	float halfHeight	= pShape.getShape()->getHalfHeight();
	float radius		= pCircle.getShape()->getRadius();

	float dx = pos1.x - pos2.x;
	float dy = pos1.y - pos2.y;

	if (fabsf(dx) > (halfWidth + radius))
	{
		return(false);
	}

	if (fabsf(dy) > (halfHeight + radius))
	{
		return(false);
	}

	// left/right
	if (fabsf(dx) < halfWidth+radius)
	{
		if (fabsf(dy) < halfHeight)
		{
			result.normal = vec2(sign(dx), 0.0f);
			return(true);
		}
	}

	// top/bottom
	if (fabsf(dy) < halfHeight+radius)
	{
		if (fabsf(dx) < halfWidth)
		{
			result.normal = vec2(0.0f, sign(dy));
			return(true);
		}
	}

	// corners
	float max_distance = (halfWidth*halfWidth) + (halfHeight*halfHeight) + radius;

	if ((dx*dx+dy*dy) < max_distance)
	{
		result.normal = normalize(vec2(sign(dx), sign(dy)));
		return(true);
	}

	return(false);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pCircle
 * @param pShape
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Circle> & pCircle, BodyPtr<Circle> & pShape, Collision & result)
{
	const vec2 & pos1	= pCircle.getPosition();
	const vec2 & pos2	= pShape.getPosition();
	float radius		= pCircle.getShape()->getRadius() + pShape.getShape()->getRadius();

	float dx = fabs(pos1.x - pos2.x);
	float dy = fabs(pos1.y - pos2.y);

	float d = (dx*dx) + (dy*dy);
	float r = radius * radius;

	if (d < r)
	{
		result.normal = normalize(pos1 - pos2);
		return(true);
	}

	return(false);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pCircle
 * @param pShape
 * @param result
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Circle> & pCircle, BodyPtr<Line> & pShape, Collision & result)
{
	bool collided = handleIntersection(pShape, pCircle, result);
	result.normal.x = - result.normal.x;
	result.normal.y = - result.normal.y;
	return(collided);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pLine
 * @param pShape
 * @param result
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Line> & pLine, BodyPtr<Box> & pShape, Collision & result)
{
	const vec2 & pos1	= pLine.getPosition();
	const vec2 & pos2	= pShape.getPosition();

	float halfWidth		= pShape.getShape()->getHalfWidth();
	float halfHeight	= pShape.getShape()->getHalfHeight();

	vec2 n = pLine.getShape()->getNormal();

	if (pos1.x > (pos2.x - halfWidth) && pos1.x < (pos2.x + halfWidth))
	{
		if (0.0f == n.y)
		{
			result.normal = n;
			return(true);
		}
	}

	if (pos1.y > (pos2.y - halfHeight) && pos1.y < (pos2.y + halfHeight))
	{
		if (0.0f == n.x)
		{
			result.normal = n;
			return(true);
		}
	}

	return(false);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pLine
 * @param pShape
 * @param result
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Line> & pLine, BodyPtr<Circle> & pShape, Collision & result)
{
	vec2 QP = pShape.getPosition() - pLine.getPosition();
	const vec2 & n = pLine.getShape()->getNormal();

	float r = pShape.getShape()->getRadius();
	float d = dot(QP, n) / norm(n);

	if (d*d < r*r)
	{
		result.normal = n;
		return(true);
	}

	return(false);
}

/**
 * @brief CollisionManager::handleIntersection
 * @param pLine
 * @param pShape
 * @param result
 * @return
 */
bool CollisionManager::handleIntersection(BodyPtr<Line> & pLine, BodyPtr<Line> & pShape, Collision & result)
{
	// TODO
	return(false);
}

}

