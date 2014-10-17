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

namespace gravity11
{

/**
 * @brief Body::Body
 * @param v
 */
Body::Body(const vec2 & v)
: m_vPosition(v)
, m_fRotation(0.0f)
, m_vLinearVelocity(0.0f, 0.0f)
, m_fAngularVelocity(0.0f)
, m_vAcceleration(0.0f, 0.0f)
, m_fTorque(0.0f)
, m_fLinearMass(1.0f)
, m_fAngularMass(1.0f)
, m_flags(DYNAMIC | SIMULATING)
, m_pShape(nullptr)
, m_pNextBody(nullptr)
{

}

/**
 * @brief Body::setStatic
 */
void Body::setStatic(void)
{
	m_flags &= ~DYNAMIC;
}

/**
 * @brief Body::setDynamic
 */
void Body::setDynamic(void)
{
    m_flags |= DYNAMIC;
}

/**
 * @brief Body::resetForces
 * @param force
 */
void Body::resetForces(const vec2 & force)
{
    if (m_flags & DYNAMIC)
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
    if (m_flags & DYNAMIC)
    {
        m_vAcceleration = m_vAcceleration + (force / m_fLinearMass);
        m_flags |= SIMULATING;
    }
}

/**
 * @brief Body::applyForce
 * @param force
 * @param position
 */
void Body::applyForce(const vec2 & force, const vec2 & point)
{
    if (m_flags & DYNAMIC)
    {
        float torque = cross(point - m_vPosition, force);
        applyTorque(torque);
        applyForce(force.x, force.y);
        m_flags |= SIMULATING;
    }
}

/**
 * @brief Body::applyTorque
 * @param torque
 */
void Body::applyTorque(float torque)
{
    if (m_flags & DYNAMIC)
    {
        m_fTorque = m_fTorque + (torque / m_fAngularMass);
        m_flags |= SIMULATING;
    }
}

/**
 * @brief Body::applyLinearImpulse
 * @param f
 */
void Body::applyLinearImpulse(float x, float y)
{
	if (m_flags & DYNAMIC)
	{
        m_vLinearVelocity = m_vLinearVelocity + vec2(x, y);
		m_flags |= SIMULATING;
	}
}

/**
 * @brief Body::applyAngularImpulse
 * @param f
 */
void Body::applyAngularImpulse(float a)
{
    if (m_flags & DYNAMIC)
    {
        m_fAngularVelocity = m_fAngularVelocity + a;
        m_flags |= SIMULATING;
    }
}

}
