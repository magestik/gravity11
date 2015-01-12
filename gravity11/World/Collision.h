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

struct Collision
{
	explicit Collision(void) : normal(0.0, 0.0f), relativeVelocity(0.0f, 0.0f), invMassTotal(0.0f) { /* ... */ }

	vec2 normal;
	vec2 relativeVelocity;
	float invMassTotal;
};

}
