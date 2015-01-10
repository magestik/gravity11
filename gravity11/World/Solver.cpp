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
void Solver::simulate(float dt_total)
{
	while (dt_total > 0.00001f)
	{
		// TODO : apply continuous collision detection to find dt
		float dt = dt_total;

		for (auto it1 = m_World.begin(), end = m_World.end(); it1 != end; ++it1)
		{
			auto tmp = it1; ++tmp;

			for (auto it2 = tmp; it2 != end; ++it2)
			{
				Collision result;
				bool collided = m_CollisionManager.handleIntersection(*it1, *it2, result);

				if (collided)
				{
					vec2 relative = (*it2)->getLinearVelocity() - (*it1)->getLinearVelocity();

					float tmp = dot(relative, result.normal);

					if (tmp > 0.0f)
					{
						float restitution = 0.9f;
						float J = - ((1.0f + restitution) * tmp) / ((1.0f/(*it1)->getLinearMass()) + (1.0f/(*it2)->getLinearMass()));

						(*it1)->applyLinearImpulse(J * result.normal * -1);
						(*it2)->applyLinearImpulse(J * result.normal);
					}
				}
			}
		}

		for (Body * pBody : m_World)
		{
			applyVelocitiesOnBody(pBody, dt);
			applyForcesOnBody(pBody, dt);
		}

		dt_total -= dt;
	}
}

/**
 * @brief Solver::applyForcesOnBody
 * @param pBody : body we want to update forces
 * @param dt
 */
void Solver::applyForcesOnBody(Body * pBody, float dt)
{
	pBody->resetForces(m_World.m_vGravity);

	// TODO : apply other forces here
}

/**
 * @brief Solver::updateBody
 * @param pBody : body we want to update position/velocity
 * Integration Euler Semi-Implicite (symplectique)
 */
void Solver::applyVelocitiesOnBody(Body * pBody, float dt)
{
	if (!pBody->fixedPosition())
	{
		pBody->m_vLinearVelocity    += pBody->m_vAcceleration * dt;
		pBody->m_vPosition          += pBody->m_vLinearVelocity * dt;
	}

	if (!pBody->fixedRotation())
	{
		pBody->m_fAngularVelocity   = pBody->m_fTorque * dt;
		pBody->m_fRotation          = pBody->m_fAngularVelocity * dt;
	}

	//onUpdate();
}

}
