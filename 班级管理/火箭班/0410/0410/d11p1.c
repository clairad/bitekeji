#include <stdio.h>

int checkRank(int * player, int n)
{
	int i, res = 0;
	for (i = 0; i < n; i++)
	{
		res |= 1 << player[i];
	}
	return res == 0x3e;
}

int main111()
{
	int player[5] = { 0 };

	for (player[0] = 1; player[0] <= 5; player[0]++)
	{
		for (player[1] = 1; player[1] <= 5; player[1]++)
		{
			for (player[2] = 1; player[2] <= 5; player[2]++)
			{
				for (player[3] = 1; player[3] <= 5; player[3]++)
				{
					for (player[4] = 1; player[4] <= 5; player[4]++)
					{
						/*
						A选手说：B第二，我第三；
						B选手说：我第二，E第四；
						C选手说：我第一，D第二；
						D选手说：C最后，我第三；
						E选手说：我第四，A第一；
						*/
						if ((player[0] == 3) + (player[1] == 2) == 1 &&
							(player[1] == 2) + (player[4] == 4) == 1 &&
							(player[2] == 1) + (player[3] == 2) == 1 &&
							(player[2] == 5) + (player[3] == 3) == 1 &&
							(player[4] == 4) + (player[0] == 1) == 1 &&
							checkRank(player, 5))
						{
							printf("a是第%d\n" \
								"b是第%d\n" \
								"c是第%d\n" \
								"d是第%d\n" \
								"e是第%d\n",
								player[0], player[1], player[2], player[3], player[4]);
						}
					}
				}
			}
		}
	}

	return 0;
}