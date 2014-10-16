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

namespace gravity11
{

class Solver;
class World;

class Body
{

friend class Solver;
friend class World;

public:

	explicit	Body	(const vec2 & v);

	void		setStatic		(void);
	void		setDynamic		(void);

	void		applyLinearImpulse	(float x, float y);

	vec2 & getPosition() { return(m_vPosition); }
private:

	// first bit
	enum ETypeFlags
	{
		STATIC		= 0x0,
		DYNAMIC		= 0x1,
	};

	// second bit
	enum EStateFlags
	{
		SIMULATING	= 0x2,
		SLEEPING	= 0x4,
	};

	vec2 m_vPosition;
	vec2 m_vVelocity;
	vec2 m_vForces;
	float m_fMass;

	int m_flags;

	Body * m_pNextBody;
};

}
