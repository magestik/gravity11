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

#include <gravity11.h>

#include "Shape.h"
#include "Segment.h"

namespace gravity11
{

/**
 * @brief Segment::Segment
 */
Segment::Segment(const SegmentAttributes & attr)
: m_fLength(attr.length)
, m_vNormal(1.0f, 0.0f)
{
	// ...
}

/**
 * @brief Segment::~Segment
 */
Segment::~Segment(void)
{
	// ...
}

}
