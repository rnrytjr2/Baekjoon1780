
// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
using namespace std;
struct confettivalue
{
	int minus=0;
	int zero=0;
	int plus=0;
};
int confettis[3000][3000];
confettivalue AddConfettiValueTripple(confettivalue a, confettivalue b, confettivalue c)
{
	confettivalue temp = a;
	temp.minus += b.minus + c.minus;
	temp.plus += b.plus + c.plus;
	temp.zero += b.zero + c.zero;
	return temp;
}
confettivalue Cut(int startx, int starty, int size)
{
	int startvalue = confettis[starty][startx];
	confettivalue temp;
	if (size == 1)
	{
		if (startvalue == -1)
		{
			temp.minus = 1;
		}
		else if (startvalue == 0)
		{
			temp.zero = 1;
		}
		else
		{
			temp.plus = 1;
		}
	}
	else
	{
		bool samechecker = true;
		for (int i = starty; i < starty + size; i++)
		{
			for (int j = startx; j < startx + size; j++)
			{
				if (startvalue != confettis[i][j])
				{
					samechecker = false;
					break;
				}
			}
			if (!samechecker)
			{
				break;
			}
		}
		if (samechecker)
		{
			if (startvalue == -1)
			{
				temp.minus = 1;
			}
			else if (startvalue == 0)
			{
				temp.zero = 1;
			}
			else
			{
				temp.plus = 1;
			}
		}
		else
		{
			temp = AddConfettiValueTripple(AddConfettiValueTripple(Cut(startx, starty, size / 3), Cut(startx + size / 3, starty, size / 3), Cut(startx + (size / 3) * 2, starty, size / 3)),
				AddConfettiValueTripple(Cut(startx, starty + size / 3, size / 3), Cut(startx + size / 3, starty + size / 3, size / 3), Cut(startx + (size / 3) * 2, starty + size / 3, size / 3)),
				AddConfettiValueTripple(Cut(startx, starty + (size / 3) * 2, size / 3), Cut(startx + size / 3, starty + (size / 3) * 2, size / 3), Cut(startx + (size / 3) * 2, starty + (size / 3) * 2, size / 3)));
		}
	}
	return temp;
}
int main()
{
	int size;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> confettis[i][j];
		}
	}
	confettivalue answer = Cut(0, 0, size);
	cout << answer.minus << '\n' << answer.zero << '\n' << answer.plus;
}

