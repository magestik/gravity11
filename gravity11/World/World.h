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
class Body;

class World
{

friend Solver;

public:

	struct iterator
	{
		explicit iterator(Body * b) : m_pBody(b) { /* ... */ }
		Body * operator * () { return(m_pBody); }
		iterator & operator ++ () { m_pBody = m_pBody->m_pNextBody; return(*this); }
		bool operator != (const iterator & it) { return(m_pBody != it.m_pBody); }

	private:
		Body * m_pBody;
	};

	explicit	World		(const vec2 & gravity);

	void		update		(float dt);

	Body *		CreateBody	(float x, float y);

	iterator begin() { return(iterator(m_pFirstBody)); }
	iterator end() { return(iterator(nullptr)); }

private:

	vec2 m_vGravity;

	float m_fTimeRemaining;
	float m_fTimeStepDuration;

	unsigned int m_iCount;
	Body * m_pFirstBody;
	Body * m_pLastBody;

	Solver * m_pSolver;
};

}
