#include "asteroid.h"
#include "window.h"

const static int totalAstroids = 15;
Asteroid collection[totalAstroids];

//should move towards vectors later and probably will shift into a "AsteroidCluster" class
void addAstroid(Asteroid a)
{
	static int count = 0;
	collection[count] = a;
	count++;
}

//incomplete asteroid generation
Asteroid generate(Asteroid others[])
{
	Asteroid obj((double)(rand() % 80) + 20);
	Vector2f location;
	bool isAwayFromOthers = false;
	int trials = 0;

	while (!isAwayFromOthers)
	{
		//temporary limits
		location.x = rand() % W_WIDTH;
		location.y = rand() % W_HEIGHT;
		obj.body.setPosition(location);

		bool safeX = true;
		bool safeY = true;
		for (int j = 0; j < totalAstroids; j++)
		{
			//Create Y data
			Vector2f jY(collection[j].body.getPosition().y - collection[j].size,
						collection[j].body.getPosition().y + collection[j].size);
			Vector2f iY(obj.body.getPosition().y - obj.size,
						obj.body.getPosition().y + obj.size);

			//Create X data
			Vector2f jX(collection[j].body.getPosition().x - collection[j].size,
				collection[j].body.getPosition().x + collection[j].size);
			Vector2f iX(obj.body.getPosition().x - obj.size,
				obj.body.getPosition().x + obj.size);

			//Check for Y shared space
			if ((jY.x < iY.x && iY.x < jY.y) || (jY.x < iY.y && iY.y < jY.y))
			{
				safeY = false;
			}
			//Check for X shared space
			if ((jX.x < iX.x && iX.x < jX.y) || (jX.x < iX.y && iX.y < jX.y))
			{
				safeX = false;
			}
			
			//Helping visualization for data
			//https://imgur.com/gallery/rIVsCLJ
		}

		//avoiding getting stuck
		if (safeX == true && safeY == true)
		{
			isAwayFromOthers = true;
		}
		else if (trials % 200 == 0)
		{
			//reattempt randomness
			srand(time(NULL));
		}
		else if (trials > 1000)
		{
			//force exit if no solution can be found via brute force
			printf_s("forced\n");
			break;
		}

		trials++;
	}
	return obj;
}
