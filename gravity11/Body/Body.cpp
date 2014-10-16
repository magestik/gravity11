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

namespace gravity11
{

/**
 * @brief Body::Body
 * @param v
 */
Body::Body(const vec2 & v)
: m_vPosition(v)
, m_vVelocity(0.0f, 0.0f)
, m_vForces(0.0f, 0.0f)
, m_fMass(1.0f)
, m_flags(DYNAMIC | SIMULATING)
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
 * @brief Body::applyLinearImpulse
 * @param f
 */
void Body::applyLinearImpulse(float x, float y)
{
	if (m_flags & DYNAMIC)
	{
		m_vVelocity = m_vVelocity + vec2(x, y);
		m_flags |= SIMULATING;
	}
}

}
