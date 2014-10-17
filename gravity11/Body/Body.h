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
class Shape;

class Body
{

friend class Solver;
friend class World;

public:

    explicit	Body                (const vec2 & v);

    void		setStatic           (void);
    void		setDynamic          (void);

    void        resetForces         (const vec2 & force);

    void        applyForce          (float x, float y);
    void        applyForce          (const vec2 & force);
    void        applyForce          (const vec2 & force, const vec2 & point);
    void        applyTorque         (float torque);

	void		applyLinearImpulse	(float x, float y);
    void		applyAngularImpulse	(float a);

    vec2 &          getPosition(void) { return(m_vPosition); }
    const vec2 &    getPosition(void) const { return(m_vPosition); }
    float           getRotation(void) const { return(m_fRotation); }

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

    vec2    m_vPosition;
    float   m_fRotation;

    vec2    m_vLinearVelocity;
    float   m_fAngularVelocity;

    vec2    m_vAcceleration;
    float   m_fTorque;

    float   m_fLinearMass;
    float   m_fAngularMass;

    int     m_flags;

    Shape * m_pShape;

    Body *  m_pNextBody;
};

}
