#include <gravity11.h>

#include <iostream>

int main (int argc, char ** argv)
{
	gravity11::World world(0.0f, -9.8f);

	gravity11::BodyModel model;
	gravity11::BoxAttributes box;

	world.CreateBody(model, box);

	float totalTime = 0.0f;

	for (int i = 0; i < 60 * 4; ++i)
	{
		world.update(0.016f);

		for (gravity11::Body * pBody : world)
		{
            const gravity11::vec2 & position = pBody->getPosition();
			std::cout << position.x << " " << position.y << std::endl;
		}
	}

	return 0;
}
