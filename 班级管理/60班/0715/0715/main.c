#include <stdio.h>
#include <time.h>
#include <windows.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Time{
	u8  year;
	u8  mon  : 4;
	u8  mday : 5;
	u8  hour : 5;
	u8  min  : 6;
	u8  sec  : 6;
	u8  wday : 3;
	u16 yday : 9;
}Time;

Time getNowTime(time_t src, u8 utc)
{
	Time nt;
	u16 tmp;
	u8 leapnum;
	int i;
	u8 emday[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	src += utc * 3600;

	nt.sec = src % 60;
	src /= 60;
	nt.min = src % 60;
	src /= 60;
	nt.hour = src % 24;
	src /= 24;

	nt.year = src / 365.25;
	leapnum = (nt.year + 2) / 4;
	tmp = nt.yday = src - nt.year * 365 - leapnum;

	for (i = 1; tmp >= emday[i - 1] && i < 12; i++)
	{
		tmp -= emday[i - 1];
		if (i == 2 && nt.year % 4 == 0)
		{
			tmp--;
		}
	}
	nt.mday = tmp + 1;
	nt.mon = i;

	nt.wday = (src - 3) % 7;

	return nt;
}

void printDate(Time src)
{
	const char * week[7] = { "日", "一", "二", "三", "四", "五", "六" };

	printf("%d-%02d-%02d %02d:%02d:%02d 星期%s", 
			src.year + 1970,
			src.mon,
			src.mday,
			src.hour,
			src.min,
			src.sec,
			week[src.wday]);
}

int _main()
{
	Time nowtime;

	while (1)
	{ 
		nowtime = getNowTime(time(NULL), 8);
		printDate(nowtime);
		Sleep(100);
		system("cls");
	}
	return 0;
}