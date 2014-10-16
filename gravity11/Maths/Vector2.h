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

struct vec2
{
	explicit vec2(void) : x(0.0f), y(0.0f) { /* ... */ }
	explicit vec2(float _x, float _y) : x(_x), y(_y) { /* ... */ }

	float x;
	float y;
};

#include "Vector2.inl"

}

