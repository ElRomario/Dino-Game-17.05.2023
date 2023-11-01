
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;

bool gameOver, jumped, falling;
int width = 40, height = 10;
int x, y, kX, kY, frames, score, sleepInt = 40;

void Draw()
{
	system("cls");
	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}

	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
				cout << "#";
			else if (i == y && j == x)
				cout << "D";
			else if (i == kY && j == kX)
				cout << "K";
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	cout << endl;
	cout << "frames: " << frames << endl;
	cout << "score: " << score << endl;
}
void Setup()
{
	srand(time(NULL));
	jumped = false;
	gameOver = false;
	score = 0;
	x = (width / 2) - 5;
	y = height-1;
	kY = height-1;
	kX = (width / 2) + 13;

}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w': jumped = true; frames = 0; break;
		default: break;
		}
	}
}
void Logic()
{
	    kX--;
		if (jumped == true)
		{
			y--;
			if (frames >= 5)
			{
				jumped = false;
				falling = true;
				frames = 0;
			}
		}
		if (falling == true)
		{
			y++;
			if (frames >= 5)
			{
				falling = false;
			}

		}
		if (kX == x && kY == y)
			gameOver = true;
		if (kX == 0)
		{
			kX = (width / 2) + 15;
		}
		if (x == kX + 1)
		{
			score++;
			if (!(sleepInt - 5 < 5))
				sleepInt -= 5;
		}
		
}
void GameOver()
{
	for (int k = 0; k < 5; k++)
	{
		Sleep(10);
		system("cls");
		for (int i = 0; i < width; i++)
		{
			cout << "#";
		}

		cout << endl;
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j == 0 || j == width - 1)
					cout << "#";
				else if (i == k && j == (width / 2) - 5)
				{
					cout << "Game Over";
					cout << "               #";
					break;
				}
				else if (i == y && j == x)
					cout << "D";
				else if (i == y && j == x+1)
					cout << "K";
				else
				{
					cout << " ";
				}
			}
			cout << endl;
		}

		for (int i = 0; i < width; i++)
		{
			cout << "#";
		}
		cout << endl;
		cout << "frames: " << frames << endl;
		cout << "score: " << score;
	}
}

int main()
{
	
	Setup();
	while (!gameOver)
	{

		//Setup();
	    Draw();
		Input();
		Logic();
		Sleep(sleepInt);
		frames++;
	}
	GameOver();
     
	 

	
}


