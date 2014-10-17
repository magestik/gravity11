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

#include "CollisionManager.h"

namespace gravity11
{

/**
 * @brief CollisionManager::CollisionManager
 */
CollisionManager::CollisionManager(void)
{
    // ...
}

/**
 * @brief CollisionManager::~CollisionManager
 */
CollisionManager::~CollisionManager(void)
{
    // ...
}

/**
 * @brief CollisionManager::handleIntersections
 * @param b1
 * @param b2
 */
void CollisionManager::handleIntersections(Body * b1, Body * b2)
{
    Shape * s1 = b1->getShape();
    Shape * s2 = b2->getShape();

    //s1->getType()
}

}

