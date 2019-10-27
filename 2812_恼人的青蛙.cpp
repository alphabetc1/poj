#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

typedef struct PLANT{
	int x;
	int y;
};
PLANT plants[5001];
int r, c, n;

int compare(const void *p1, const void *p2)
{
	PLANT *plant1 = (PLANT *)p1;
	PLANT *plant2 = (PLANT *)p2;
	if (plant1->x == plant2->x)	return plant1->y - plant2->y;
	return plant1->x - plant2->x;
}

int searchPath(PLANT secPLANT, int dx, int dy)
{
	int steps = 2;
	PLANT plant;
	plant.x = secPLANT.x + dx;
	plant.y = secPLANT.y + dy;
	while (plant.x <= r && plant.x >= 1 && plant.y <= c && plant.y >= 1)
	{
		if (!bsearch(&plant, plants, n, sizeof(PLANT), compare))
		{
			steps = 0;
			break;
		}
		plant.x += dx;
		plant.y += dy;
		steps++;
	}
	return steps;
}

int main()
{
	int  i, j, dx, dy, px, py, steps, max = 2;
	scanf("%d%d%d", &r, &c, &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &plants[i].x, &plants[i].y);
	}
	qsort(plants, n, sizeof(PLANT), compare);
	for (i = 0; i < n - 2; i++)
	{
		for (j = i + 1; j < n - 1; j++)
		{
			dx = plants[j].x - plants[i].x;
			dy = plants[j].y - plants[i].y;
			px = plants[i].x - dx;
			py = plants[i].y - dy;
			if (px <= r && px >= 1 && py <= c && py >= 1)	//上一个点在界外
				continue;
			if (plants[i].x + max * dx > r)
				break;
			py = plants[i].y + max * dy;
			if (py < 1 || py > c)
				continue;
			steps = searchPath(plants[j], dx, dy);
			if (steps > max)	max = steps;
		}
	}
	if (max == 2)	max = 0;
	printf("%d\n", max);
	system("pause");
	return 0;
}