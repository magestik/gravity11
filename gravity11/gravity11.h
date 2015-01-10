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

#include "Maths/Vector2.h"

#include "Body/Body.h"

#include "World/World.h"

namespace gravity11
{
	enum ShapeType
	{
		BOX,
		CIRCLE,
		LINE,
		SEGMENT
	};

	struct BodyModel
	{
		vec2 position = vec2(0.0f, 0.0f);
		float rotation = 0.0f;

		float linearMass = 1.0f;
		float angularMass = 1.0f;

		bool dynamic = true;
	};

	struct BoxAttributes
	{
		float width = 1.0f;
		float height = 1.0f;
	};

	struct CircleAttributes
	{
		float radius = 1.0f;
	};

	struct LineAttributes
	{
		vec2 normal;
	};

	struct SegmentAttributes
	{
		float length = 1.0f;
		vec2 point;
		vec2 normal;
	};
}

