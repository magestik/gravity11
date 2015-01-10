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

#include "CollisionManager.h"

namespace gravity11
{

class Solver
{

public:

	Solver(World & world);

	void simulate(float dt);

protected:

	void applyResponse(Body * pBody, const vec2 & relative, const Collision & result);
	void applyForcesOnBody(Body * pBody, float dt);
	void applyVelocitiesOnBody(Body * pBody, float dt);

private:

	World & m_World;

	CollisionManager m_CollisionManager;
};

}
