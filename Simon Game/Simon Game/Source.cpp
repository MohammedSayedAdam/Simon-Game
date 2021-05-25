#include <iostream>
#include <string>
#include <stdio.h>
#include <list>
#include <iterator>
#include <stdlib.h>
#include <Windows.h>
#include <mmsystem.h>
#include <time.h>
#include <conio.h>
#pragma comment(lib, "Winmm.lib")
using namespace std;
int score = 0;
void Generat_Random_Pattern(string &Simonpattern,int &Simoncount,int Key_First)
{
	if (Key_First == 0)
	{
		srand(time(0));
		for (int i = 0; i < Simoncount; i++)
		{
			int x = rand() % 4;
			if(x == 0)
				Simonpattern += '1';
			else if (x == 1)
				Simonpattern += '2';
			else if (x == 2)
				Simonpattern += '3';
			else if (x == 3)
				Simonpattern += '4';
		}
			
	}
	else
	{
		int x = rand() % 4;
		if (x == 0)
			Simonpattern += '1';
		else if (x == 1)
			Simonpattern += '2';
		else if (x == 2)
			Simonpattern += '3';
		else if (x == 3)
			Simonpattern += '4';
		
	}
		
}
void gotoxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}
void InitiallyMap()
{
	//system("Color 06");//yellow
	//system("Color 02");//green
	//system("Color 01");//Blue
	//system("Color 04");//red
	//up
	gotoxy(40, 0);
	cout << "Yellow" << endl;

	//down
	gotoxy(40, 15);
	cout << "Green" << endl;

	//right
	gotoxy(80, 10);
	cout << "Red" << endl;

	//left
	gotoxy(0, 10);
	cout << "Blue" << endl;


	//score and information
	gotoxy(0, 16);
	cout << "To Start the Game Press Enter" << endl;
	cout << "Use Arrows to follow Computer's Pattern if you want to Exit Press ESC" << endl;
	cout << "Score: " << score << endl;

}
void Excute_Simoin_Pattern(string Simonpattern)
{
	for (int i = 0; i < Simonpattern.length(); i++)
	{
		if (Simonpattern[i] == '1')
		{
			system("Color 06");//yellow
			PlaySound(TEXT("up.wav"), GetModuleHandle(NULL), SND_FILENAME);
			gotoxy(40, 0);
			cout << "Yellow" << endl;
			
		}
		else if (Simonpattern[i] == '2')
		{
			system("Color 02");//green
			PlaySound(TEXT("down.wav"), GetModuleHandle(NULL), SND_FILENAME);
			gotoxy(40, 15);
			cout << "Green" << endl;
		}
		else if (Simonpattern[i] == '3')
		{
			/*gotoxy(2, 0);
			cout << "b" << endl;*/
			system("Color 01");//Blue
			PlaySound(TEXT("left.wav"), GetModuleHandle(NULL), SND_FILENAME);
			gotoxy(0, 10);
			cout << "Blue" << endl;
		}
		else if (Simonpattern[i] == '4')
		{
			/*gotoxy(3, 0);
			cout << "r" << endl;*/
			system("Color 04");//red
			PlaySound(TEXT("right.wav"), GetModuleHandle(NULL), SND_FILENAME);
			gotoxy(80, 10);
			cout << "Red" << endl;
		}
	}
	gotoxy(0, 0); cout << Simonpattern << endl;
}
void main()
{
	InitiallyMap();
	cin.get();
	if (GetAsyncKeyState(VK_RETURN))
	{
		string Simonpattern = "", Userpattern = "";
		int Simoncount = 4;
		Generat_Random_Pattern(Simonpattern, Simoncount, 0);//0 means it's the first time to generate four colors
		Excute_Simoin_Pattern(Simonpattern);
		while (!GetAsyncKeyState(VK_ESCAPE))
		{
			if (GetAsyncKeyState(VK_UP))
			{
				Userpattern += '1';
				system("Color 0E");//light yellow
				PlaySound(TEXT("up.wav"), GetModuleHandle(NULL), SND_FILENAME);
				gotoxy(40, 0);
				cout << "Yellow" << endl;
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				Userpattern += '2';
				system("Color 0A");//light Green
				PlaySound(TEXT("down.wav"), GetModuleHandle(NULL), SND_FILENAME);
				gotoxy(40, 15);
				cout << "Green" << endl;
			}
			else if (GetAsyncKeyState(VK_LEFT))
			{
				Userpattern += '3';
				system("Color 09");//light Blue
				PlaySound(TEXT("left.wav"), GetModuleHandle(NULL), SND_FILENAME);
				gotoxy(0, 10);
				cout << "Blue" << endl;
			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{
				Userpattern += '4';
				system("Color 0C");//light Red
				PlaySound(TEXT("right.wav"), GetModuleHandle(NULL), SND_FILENAME);
				gotoxy(80, 10);
				cout << "Red" << endl;
			}
			else if (GetAsyncKeyState(VK_ESCAPE))
			{
				//show score and ending message and break
				break;
			}

			if (Userpattern == Simonpattern)
			{
				score++;
				Userpattern = "";
				system("cls");
				InitiallyMap();
				Generat_Random_Pattern(Simonpattern, Simoncount, 1);
				Excute_Simoin_Pattern(Simonpattern);
			}
			else if (Userpattern.length() == Simonpattern.length()&& Userpattern != Simonpattern)
			{
				system("cls");
				cout << "you are loose the game you can try again" << endl;
				break;
			}
		}
	}
	

	system("pause");
}