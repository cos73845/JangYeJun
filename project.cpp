// struct(구조체) 사용법
/*
#include <stdio.h>

typedef struct Points
{
	int a; // 초기화 안해줘도 됨

}Pt; // Pt로 재정의를 하겠다, typedef 와의 결합 ㅇㅇ


void main()
{
	
	Pt p = { 10 };
	Pt* pp = &p;
	printf("P.a = %d \n", p.a); // 일반 변수로 선언하면 이렇게
	printf("Pt->p = %d \n", pp->a); // 포인터 변수로 선언하면 이렇게 
	//	Points p = { 10 };
}


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define X 10
#define Y 10

typedef struct PlayerPos
{
	int pxPos;
	int pyPos;
}Ppos;

typedef struct PlayerMap
{
	int map[Y][X] // X Y 순서에 유의,  Y가 우선 
		= {
			{1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,1}
		};
}Pm;

void MapSpace(PlayerPos, int(*)[X]);
void AutoMove(PlayerPos, int(*)[X], int);


void main()
{
	srand(time(NULL));

	Ppos p = { 1,1 }; // struct 만들어놓은 순서대로
	Pm pm; // 초기화가 이미 되어있음


	int controls = 0;// 메인함수 변수선언은 좋지 않음, 실제로 내가 만들땐 구조체로 빼기
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (p.pyPos == y && p.pxPos == x) {
				printf("P ");

			}
			else {
				switch (pm.map[y][x])
				{
				case 0:
					printf("  ");
					break;
				case 1:
					printf("■");
					break;



				}
			}
		}



		controls = (rand() % 4) + 1; // 상하좌우니까 4개
		MapSpace(p, pm.map);
		AutoMove(p, pm.map, controls);

	}
}

void Mapspace(PlayerPos ppos, int(*p)[X])
{
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (ppos.pyPos == y && ppos.pxPos == x) {
				printf("P ");

			}
			else {
				switch (p[y][x])
				{
				case 0:
					printf("  ");
					break;
				case 1:
					printf("■");
					break;
				}
			}
		}

	}
}

void AutoMove(PlayerPos ppos, int(*)[X], int ct1)
{
	switch (ct1)
	{
		case UP:
			if (p[ppos.pyPos][ppos.pxPos] == 1)
			{
				ppos.pyPos--;
			}
			ppos.pyPos++;
			break;
		case DOWN:
			if (p[ppos.pyPos][ppos.pxPos] == 1)
			{
				ppos.pyPos++;
			}
			ppos.pyPos--;
			break;
		case LEFT:
			if (p[ppos.pyPos][ppos.pxPos] == 1)
			{
				ppos.pxPos++;
			}
			ppos.pxPos--;
			break;

		case RIGHT:
			if (p[ppos.pyPos][ppos.pxPos] == 1)
			{
				ppos.pxPos--;
			}
			ppos.pxPos++;
			break;


	}


}
// 구조체를 일반 변수 형태로 사용하고 있기때문에 지역변수의 성격을 뜀. 따라서 함수를 이용하면 모든값이 사라짐 , 전역변수가 필요, 이는 포인터로
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>



#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4



#define X 10
#define Y 10

typedef struct PlayerPos

{
	int pXPos;
	int pYPos;
}Ppos;



typedef struct PlayerMap

{

	int map[Y][X]

		= {
			{1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,1}
	};

}Pm;



void MapSpace(PlayerPos, int(*)[X]);
void AutoMove(PlayerPos, int(*)[X], int);



void main()

{
	srand(time(NULL));

	Ppos p = { 1,1 };
	Pm pm;

	int controls = 0;

	controls = (rand() % 4) + 1;
	MapSpace(p, pm.map);
	AutoMove(p, pm.map, controls);
}



void MapSpace(PlayerPos ppos, int(*p)[X])

{

	for (int y = 0; y < Y; y++)

	{

		for (int x = 0; x < X; x++)

		{

			if (ppos.pYPos == y && ppos.pXPos == x) {

				printf("P ");

			}

			else {

				switch (p[y][x])

				{

				case 0:

					printf("  ");

					break;

				case 1:

					printf("■");

					break;

				}

			}

		}

		printf("\n");

	}

}



void AutoMove(PlayerPos ppos, int(*p)[X], int ctl)

{
	switch (ctl)
	{
	case UP:
		if (p[ppos.pYPos][ppos.pXPos] == 1)

		{

			ppos.pYPos--;

		}

		ppos.pYPos++;

		break;



	case DOWN:

		if (p[ppos.pYPos][ppos.pXPos] == 1)

		{

			ppos.pYPos++;

		}

		ppos.pYPos--;

		break;



	case LEFT:

		if (p[ppos.pYPos][ppos.pXPos] == 1)

		{

			ppos.pXPos++;

		}

		ppos.pXPos--;

		break;



	case RIGHT:

		if (p[ppos.pYPos][ppos.pXPos] == 1)

		{

			ppos.pXPos--;

		}

		ppos.pXPos++;

		break;

	}

}

*/
/*
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>



#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4



#define X 10
#define Y 10

typedef struct PlayerPos

{
	int pXPos;
	int pYPos;
}Ppos;



typedef struct PlayerMap

{

	int map[Y][X]

		= {
			{1,1,1,1,1,1,1,1,1,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,0,0,0,0,0,0,0,0,1},
			{1,1,1,1,1,1,1,1,1,1}
	};

}Pm;



void MapSpace(PlayerPos, int(*)[X]);
void AutoMove(PlayerPos, int(*)[X], int);



void main()

{
	srand(time(NULL));

	Ppos p = { 1,1 };
	Pm pm;

	int controls = 0;

	controls = (rand() % 4) + 1;
	AutoMove(&p, pm.map, controls);
	MapSpace(&p, pm.map);
	
}



void MapSpace(PlayerPos *ppos, int(*p)[X])

{

	for (int y = 0; y < Y; y++)

	{

		for (int x = 0; x < X; x++)

		{

			if (ppos->pYPos == y && ppos->pXPos == x) {

				printf("P ");

			}

			else {

				switch (p[y][x])

				{

				case 0:

					printf("  ");

					break;

				case 1:

					printf("■");

					break;

				}

			}

		}

		printf("\n");

	}

}



void AutoMove(PlayerPos *ppos, int(*p)[X], int ctl)

{
	switch (ctl)
	{
	case UP:
		if (p[ppos->pYPos][ppos->pXPos] == 1)

		{

			ppos->pYPos--;

		}

		ppos->pYPos++;

		break;



	case DOWN:

		if (p[ppos->pYPos][ppos->pXPos] == 1)

		{

			ppos->pYPos++;

		}

		ppos->pYPos--;

		break;



	case LEFT:

		if (p[ppos->pYPos][ppos->pXPos] == 1)

		{

			ppos->pXPos++;

		}

		ppos->pXPos--;

		break;



	case RIGHT:

		if (p[ppos->pYPos][ppos->pXPos] == 1)

		{

			ppos->pXPos--;

		}

		ppos->pXPos++;

		break;

	}

}

*/

#include<stdio.h>

#include<stdlib.h>

#include<time.h>

#include<Windows.h>



#define UP 1

#define DOWN 2

#define LEFT 3

#define RIGHT 4



#define X 10

#define Y 10



typedef struct PlayerPos

{

	int pXPos;

	int pYPos;

}Ppos;



typedef struct PlayerMap

{

	int map[Y][X]

		= {

			{1,1,1,1,1,1,1,1,1,1},

			{1,0,0,0,0,0,0,0,0,1},

			{1,0,0,0,0,0,0,0,0,1},

			{1,0,0,0,0,0,0,0,0,1},

			{1,0,0,0,0,0,0,0,0,1},

			{1,0,0,0,0,0,0,0,0,1},

			{1,0,0,0,0,0,0,0,0,1},

			{1,0,0,0,0,0,0,0,0,1},

			{1,0,0,0,0,0,0,0,0,1},

			{1,1,1,1,1,1,1,1,1,1}

	};

}Pm;



void MapSpace(PlayerPos*, int(*)[X]);

void AutoMove(PlayerPos*, int(*)[X], int);



void main()

{


	srand(time(NULL));



	Ppos p = { 1,1 };

	Pm pm;



	int controls = 0;


	while (1)
	{
		controls = (rand() % 4) + 1;
		AutoMove(&p, pm.map, controls);
		MapSpace(&p, pm.map);
		Sleep(500);
		system("cls");
	}
	


}



void MapSpace(PlayerPos* ppos, int(*p)[X])

{


	for (int y = 0; y < Y; y++)

	{

		for (int x = 0; x < X; x++)

		{
			
			if (ppos->pYPos == y && ppos->pXPos == x) {

				printf("P ");

			}

			else {

				switch (p[y][x])

				{

				case 0:

					printf("  ");

					break;

				case 1:

					printf("■");

					break;

				}

			}

		}

		printf("\n");

	}

}



void AutoMove(PlayerPos* ppos, int(*p)[X], int ctl)

{
		printf("ctl = %d\n", ctl);
		switch (ctl)

		{

		case UP:
			ppos->pYPos--;
			if (p[ppos->pYPos][ppos->pXPos] == 1)


			{

				ppos->pYPos++;

			}

			

			break;



		case DOWN:
			ppos->pYPos++;
			if (p[ppos->pYPos][ppos->pXPos] == 1)

			{

				ppos->pYPos--;

			}

			

			break;



		case LEFT:
			ppos->pXPos++;
			if (p[ppos->pYPos][ppos->pXPos] == 1)

			{

				ppos->pXPos--;

			}

			

			break;



		case RIGHT:
			ppos->pXPos--;
			if (p[ppos->pYPos][ppos->pXPos] == 1)

			{

				ppos->pXPos++;

			}

			

			break;

		}
	

}