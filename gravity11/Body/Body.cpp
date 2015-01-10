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

#include "Body.h"

#include <assert.h>

namespace gravity11
{

/**
 * @brief Body::Body
 * @param v
 */
Body::Body(const BodyModel & model, Shape * pShape)
: m_vPosition(model.position)
, m_fRotation(model.rotation)
, m_vLinearVelocity(0.0f, 0.0f)
, m_fAngularVelocity(0.0f)
, m_vAcceleration(0.0f, 0.0f)
, m_fTorque(0.0f)
, m_fLinearMass(1.0f)
, m_fAngularMass(1.0f)
, m_flags(0)
, m_pShape(pShape)
, m_pNextBody(nullptr)
{
	assert(nullptr != m_pShape);

	fixedPosition(!model.dynamic);
	fixedRotation(!model.dynamic);
}

/**
 * @brief Body::staticPosition
 * @return
 */
bool Body::fixedPosition(void) const
{
	return(m_flags & FIXED_POSITION);
}

/**
 * @brief Body::staticRotation
 * @return
 */
bool Body::fixedRotation(void) const
{
	return(m_flags & FIXED_ROTATION);
}

/**
 * @brief Body::staticPosition
 * @param b
 */
void Body::fixedPosition(bool b)
{
	if (b)
	{
		m_flags |= FIXED_POSITION;
	}
	else
	{
		m_flags &= ~FIXED_POSITION;
	}
}

/**
 * @brief Body::staticRotation
 * @param b
 */
void Body::fixedRotation(bool b)
{
	if (b)
	{
		m_flags |= FIXED_ROTATION;
	}
	else
	{
		m_flags &= ~FIXED_ROTATION;
	}
}

/**
 * @brief Body::resetForces
 * @param force
 */
void Body::resetForces(const vec2 & force)
{
	if (!fixedPosition())
	{
		m_vAcceleration = (force / m_fLinearMass);
	}
}

/**
 * @brief Body::applyForce
 * @param force
 */
void Body::applyForce(float x, float y)
{
	applyForce(vec2(x, y));
}

/**
 * @brief Body::applyForce
 * @param force
 */
void Body::applyForce(const vec2 & force)
{
	if (!fixedPosition())
	{
		m_vAcceleration = m_vAcceleration + (force / m_fLinearMass);
		m_flags &= ~SLEEPING;
	}
}

/**
 * @brief Body::applyForce
 * @param force
 * @param position
 */
void Body::applyForce(const vec2 & force, const vec2 & point)
{
	if (!fixedPosition())
	{
		float torque = cross(point - m_vPosition, force);
		applyTorque(torque);
		applyForce(force.x, force.y);
		m_flags &= ~SLEEPING;
	}
}

/**
 * @brief Body::applyTorque
 * @param torque
 */
void Body::applyTorque(float torque)
{
	if (!fixedRotation())
	{
		m_fTorque = m_fTorque + (torque / m_fAngularMass);
		m_flags &= ~SLEEPING;
	}
}

/**
 * @brief Body::applyLinearImpulse
 * @param f
 */
void Body::applyLinearImpulse(float x, float y)
{
	applyLinearImpulse(vec2(x, y));
}

/**
 * @brief Body::applyLinearImpulse
 * @param f
 */
void Body::applyLinearImpulse(const vec2 & impulse)
{
	if (!fixedPosition())
	{
		m_vLinearVelocity = m_vLinearVelocity + (impulse / m_fLinearMass);
		m_flags &= ~SLEEPING;
	}
}


/**
 * @brief Body::applyAngularImpulse
 * @param f
 */
void Body::applyAngularImpulse(float impulse)
{
	if (!fixedRotation())
	{
		m_fAngularVelocity = m_fAngularVelocity + (impulse / m_fAngularMass);
		m_flags &= ~SLEEPING;
	}
}

}
