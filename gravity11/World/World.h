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

class BoxAttributes;
class CircleAttributes;
class SegmentAttributes;

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

	explicit	World		(float x, float y);

	void		update		(float dt);

	Body *		CreateBody	(const BodyModel & model, const BoxAttributes & attr, int count = 1);
	Body *		CreateBody	(const BodyModel & model, const CircleAttributes attr, int count = 1);
	Body *		CreateBody	(const BodyModel & model, const SegmentAttributes & attr, int count = 1);

	iterator	begin(void)	{ return(iterator(m_pFirstBody)); }
	iterator	end(void)	{ return(iterator(nullptr)); }

protected:

	Body *		CreateBody	(const BodyModel & model, Shape * pShape, int count = 1);

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
