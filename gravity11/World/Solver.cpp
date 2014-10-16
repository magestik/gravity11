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

#include "Solver.h"

namespace gravity11
{

/**
 * @brief Solver
 * @param world
 */
Solver::Solver(World & world)
: m_World(world)
{

}

/**
 * @brief Solver::simulate
 * @param dt
 */
void Solver::simulate(float dt)
{
	for (Body * pBody : m_World)
	{
		applyForcesOnBody(pBody, dt);
	}

	// TODO : detect collisions

	for (Body * pBody : m_World)
	{
		updateBody(pBody, dt);
	}
}

/**
 * @brief Solver::applyForcesOnBody
 * @param pBody : body we want to update forces
 * @param dt
 */
void Solver::applyForcesOnBody(Body * pBody, float dt)
{
	if (pBody->m_flags & Body::DYNAMIC)
	{
		pBody->m_vForces = pBody->m_vForces + m_World.m_vGravity * dt;
	}
}

/**
 * @brief Solver::updateBody
 * @param pBody : body we want to update position/velocity
 */
void Solver::updateBody(Body * pBody, float dt)
{
	if (pBody->m_flags & Body::DYNAMIC)
	{
		vec2 acceleration = pBody->m_vForces / pBody->m_fMass;
		pBody->m_vVelocity = pBody->m_vVelocity + acceleration * dt;
		pBody->m_vPosition = pBody->m_vPosition + pBody->m_vVelocity * dt;

		//onUpdate();
	}
}

}
