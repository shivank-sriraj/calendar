#include<iostream>   //For cout, cin, etc.
#include<iomanip>    //For setw().
#include<Windows.h>  //For Sleep(), COORD, gotoxy(), system("cls"), etc.
#include<conio.h>    //For _getch().

#include "declaration_file.h"    //Declarations of functions included.

extern long int yd, y, m, md, rem, i, j, k, count1, leap, count2, a;    //External linking of these datatypes to that in main.cpp file.
using namespace std;
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;                                                           //gotoxy() definition, to be included whenever gotoxy() is used.
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int getIntegerInput()
{
	char ch;
	int num=0;
	do{
		ch=_getch();
		if(ch>=48 && ch<=57) {
			printf("%c", ch);
			num = num*10 + (ch-48);                                           //To accept input only as an integer.
		}
	}while(ch != 13);
	return num;
}

void design()
{
	gotoxy(20, 23);
	for (int i = 0; i <= 70; i++)
	{
		cout << (char)219;
		Sleep(10);                                       //Moving animations of page transition.
	}
	system("cls");
}

void leapcount()
{
	if (((y % 100 == 0) && (y % 400 == 0)) || ((y % 100 != 0) && (y % 4 == 0)))
		leap = 1;                                                                       //To know whether inputted year is leap or not.
	else
		leap = 0;
}

int devinfo()
{
	gotoxy(20, 23); cout << "Developed by Shivank Sriraj.";
	gotoxy(20, 25); cout << "Press any other key to check another year, or press '0' to exit : ";            //Developer information.
	if (_getch()=='0')
		return 0;
	else
		return 1;
}

void month()
{
	switch (m)
	{
	case 1: gotoxy(20, 2); cout<<"January, " << y;
		break;
	case 2: gotoxy(20, 2); cout << "February, " << y;
		break;
	case 3: gotoxy(20, 2); cout << "March, " << y;
		break;
	case 4: gotoxy(20, 2); cout << "April, " << y;
		break;
	case 5: gotoxy(20, 2); cout << "May, " << y;
		break;
	case 6: gotoxy(20, 2); cout << "June, " << y;
		break;
	case 7: gotoxy(20, 2); cout << "July, " << y;
		break;                                                           //Month and year to be printed on top of calendar. gotoxy() specifies the position.
	case 8: gotoxy(20, 2); cout << "August, " << y;
		break;
	case 9: gotoxy(20, 2); cout << "September, " << y;
		break;
	case 10: gotoxy(20, 2); cout << "October, " << y;
		break;
	case 11: gotoxy(20, 2); cout << "November, " << y;
		break;
	case 12: gotoxy(20, 2); cout << "December, " << y;
		break;
	}
}

void format()
{
	month();
	for (i = 20; i <= 100; i++)
	{
		gotoxy(i, 3); cout << ".";
		gotoxy(i, 20); cout << ".";
	}
	for (i = 3; i <= 20; i++)
	{                                                                       //Designing of calendar format.
		gotoxy(19, i); cout << ".";
		gotoxy(100, i); cout << ".";
	}
	gotoxy(20, 5); cout << setw(10) << "MON" << setw(10) << "TUE" << setw(10) << "WED" << setw(10) << "THU" << setw(10) << "FRI" << setw(10) << "SAT" << setw(10) << "SUN";
	gotoxy(20, 6); cout << setw(10) << "---" << setw(10) << "---" << setw(10) << "---" << setw(10) << "---" << setw(10) << "---" << setw(10) << "---" << setw(10) << "---";
}

int printcal()
{
	for (i = 1,y = 10; i <= 6; i++,y+=2)
	{
		for (j = k; j <= 7; j++)
		{
			count1++;
			cout << setw(10) << count1;                                                                                   //Actual printing of calendar days.
			if (((m == 1) || (m == 3) || (m == 5) || (m == 7) || (m == 8) || (m == 10) || (m == 12)) && (count1 == 31))
			{
				a=devinfo();
				return a;
			}
			if ((m == 2) && (leap == 0) && (count1 == 28))
			{
				a=devinfo();
				return a;
			}                                                                        //To stop calendar on 30/31/28 depending on month and year(leap).
			if ((m == 2) && (leap == 1) && (count1 == 29))
			{
				a=devinfo();
				return a;
			}
			if (((m == 4) || (m == 6) || (m == 9) || (m == 11)) && (count1 == 30))
			{
				a=devinfo();
				return a;
			}
		}
		k = 1;
		gotoxy(20, y);
	}
}

