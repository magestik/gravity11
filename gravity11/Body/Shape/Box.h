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

class BoxAttributes;

class Box : public Shape
{

public:

	explicit Box(const BoxAttributes & attr);
	virtual ~Box(void);

	virtual ShapeType getType(void) { return(BOX); }

	float getHalfWidth(void) const { return(m_vSize.x); }
	float getHalfHeight(void) const { return(m_vSize.y); }

private:

	vec2 m_vSize;

};

}
