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
class BodyModel;

class Body
{

friend class Solver;
friend class World;

public:

	explicit	Body                (const BodyModel & v, Shape * pShape);

	bool		fixedPosition		(void) const;
	bool		fixedRotation		(void) const;

	void		fixedPosition		(bool b);
	void		fixedRotation		(bool b);

	void		Sleeping			(bool s);
	bool		Sleeping			(void);

	void        resetForces         (const vec2 & force);

	void        applyForce          (float x, float y);
	void        applyForce          (const vec2 & force);
	void        applyForce          (const vec2 & force, const vec2 & point);
	void        applyTorque         (float torque);

	void		applyLinearImpulse	(float x, float y);
	void		applyLinearImpulse	(const vec2 & impulse);
	void		applyAngularImpulse	(float impulse);

	const vec2 &    getPosition(void) const { return(m_vPosition); }
	float           getRotation(void) const { return(m_fRotation); }

	void            setPosition(const vec2 & pos) { m_vPosition = pos; }
	void            setRotation(float rot) { m_fRotation = rot; }

	const vec2 &    getLinearVelocity(void) const { return(m_vLinearVelocity); }
	float			getAngularVelocity(void) const { return(m_fAngularVelocity); }

	void            setLinearVelocity(const vec2 & vel) { m_vLinearVelocity = vel; }
	void            setAngular(float vel) { m_fAngularVelocity = vel; }

	float           getInvLinearMass(void) const { return(fixedPosition() ? 0.0f : m_fInvLinearMass); }
	float           getInvAngularMass(void) const { return(fixedRotation() ? 0.0f : m_fInvAngularMass); }

	Shape *         getShape(void) { return(m_pShape); }

private:

	enum EFlagsBit
	{
		FIXED_POSITION		= 0x1, // first bit
		FIXED_ROTATION		= 0x2, // second bit
		SLEEPING			= 0x4, // third bit
	};

	vec2    m_vPosition;
	float   m_fRotation;

	vec2    m_vLinearVelocity;
	float   m_fAngularVelocity;

	vec2    m_vAcceleration;
	float   m_fTorque;

	float   m_fInvLinearMass; // inverse of the linear mass
	float   m_fInvAngularMass; // inverse of the angular mass

	int     m_flags;

	Shape * m_pShape;

	Body *  m_pNextBody;
};

}
