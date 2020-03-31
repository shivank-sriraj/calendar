#include<iostream>  //For cout, cin, etc.
#include<iomanip>  //For setw().

#include "declaration_file.h"  //Declarations of functions included.

using namespace std;
long int yd, y, m, md, rem, i, j, k, count1, leap, count2, a;
int main()                                           //Main function. Beginning of the program.
{
	do
	{
		count1 = 0;
		count2 = 0;
		system("cls");
		for (i = 30; i <= 80; i++)
		{
			gotoxy(i, 4); cout << ".";
			gotoxy(i, 15); cout << ".";
		}                                                                //Bordering of the front interface.
		for (i = 4; i <= 15; i++)
		{
			gotoxy(30, i); cout << ".";
			gotoxy(80, i); cout << ".";
		}
		gotoxy(40,6); cout << "...........CALENDAR...........";          //Front interface to enter year and month.
		gotoxy(40,11); cout << "Enter Year : ";
		gotoxy(40,13); cout << "Enter Month : ";
		gotoxy(53, 11); y=getIntegerInput();
		gotoxy(54, 13); m=getIntegerInput();
		design();
		try{
			if(y>=1 && y<=10000 && m>=1 && m<=12) {
				
				leapcount();
				for (i = 1; i < y; i++)
				{
					if (((i % 100 == 0) && (i % 400 == 0)) || ((i % 100 != 0) && (i % 4 == 0)))            //Count the no. of leap years between 1 to inputted year.
						count2++;
				}
				yd = (y - 1) * 365 + count2;                 //No. of days from 1 to inputted year(including all leap years).
				switch (m)
				{
				case 1: md = yd + 0;
					break;
				case 2: md = yd + 31;
					break;
				case 3: if (leap == 1)
					md = yd + 60;
					  else
					md = yd + 59;
					break;
				case 4: if (leap == 1)
					md = yd + 91;
					  else
					md = yd + 90;
					break;
				case 5: if (leap == 1)                     //After how many days does the given month starts in that year.
					md = yd + 121;
					  else
					md = yd + 120;
					break;
				case 6: if (leap == 1)
					md = yd + 152;
					  else
					md = yd + 151;
					break;
				case 7: if (leap == 1)
					md = yd + 182;
					  else
					md = yd + 181;
					break;
				case 8: if (leap == 1)
					md = yd + 213;
					  else
					md = yd + 212;
					break;
				case 9: if (leap == 1)
					md = yd + 244;
					  else
					md = yd + 243;
					break;
				case 10: if (leap == 1)
					md = yd + 274;
					   else
					md = yd + 273;
					break;
				case 11: if (leap == 1)
					md = yd + 305;
					   else
					md = yd + 304;
					break;
				case 12: if (leap == 1)
					md = yd + 335;
					   else
					md = yd + 334;
					break;
				}
				rem = md % 7;                                   //To check whether month starts from Sunday/Monday, etc. Considering 1/01/001 was Monday.
				format();
				switch (rem)
				{
				case 0: gotoxy(20, 8); k = 1;
					a=printcal();
					break;
				case 1: gotoxy(20, 8); cout << setw(10) << " ";
					k = 2;
					a=printcal();
					break;
				case 2: gotoxy(20, 8); cout << setw(20) << " ";
					k = 3;
					a=printcal();
					break;                                               //Which day to start calendar from.
				case 3: gotoxy(20, 8); cout << setw(30) << " ";
					k = 4;
					a=printcal();
					break;
				case 4: gotoxy(20, 8); cout << setw(40) << " ";
					k = 5;
					a=printcal();
					break;
				case 5: gotoxy(20, 8); cout << setw(50) << " ";
					k = 6;
					a=printcal();
					break;
				case 6: gotoxy(20, 8); cout << setw(60) << " ";
					k = 7;
					a=printcal();
					break;
				}
			}
			else {
				throw y;
			}
		}
		catch(...){
			y=0;
			m=0;
			gotoxy(20, 5); cout<<"Invalid year/month";
			gotoxy(19, 6); cout<<"....................";
			a=devinfo();
		}
	}while (a);                                                 //To print calendar for another year.
	return 0;
}                                                                  //End of the program.

