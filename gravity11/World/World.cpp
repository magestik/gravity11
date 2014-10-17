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

#include "World.h"

#include "Solver.h"

namespace gravity11
{

/**
 * @brief World::World
 * @param gravity
 */
World::World(float x, float y)
: m_vGravity(x, y)
, m_fTimeRemaining(0.0f)
, m_fTimeStepDuration(1.0f / 60.0f)
, m_iCount(0)
, m_pFirstBody(nullptr)
, m_pLastBody(nullptr)
{
	m_pSolver = new Solver(*this);
}

/**
 * @brief World::update
 * @param dt
 */
void World::update(float dt)
{
	m_fTimeRemaining += dt;

	unsigned int step (m_fTimeRemaining / m_fTimeStepDuration);

	m_fTimeRemaining -= step * m_fTimeStepDuration;

	for (int i = 0; i < step; ++i)
	{
		m_pSolver->simulate(m_fTimeStepDuration);
	}
}

/**
 * @brief World::CreateBody
 * @param position
 * @return
 */
Body * World::CreateBody(float x, float y)
{
	vec2 position (x,y);

	Body * b = new Body(position);

	if (0 == m_iCount++)
	{
		m_pFirstBody = b;
		m_pLastBody = b;
	}
	else
	{
		m_pLastBody->m_pNextBody = b;
		m_pLastBody = b;
	}

	return(b);
}

}
