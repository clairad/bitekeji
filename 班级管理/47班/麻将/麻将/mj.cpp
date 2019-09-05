#include "mj.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

MJMontain::MJMontain() :
	m_getFlag(0)
{
	srand((unsigned int)time(NULL));
}

void MJMontain::fillRandNum()
{
	int num[MJNUM] = { 0 };
	int i;
	for (i = 0; i < MJNUM; i++)
	{
		num[i] = i;
	}

	int j;
	for (j = 0; j < MJNUM; j++)
	{
		i = rand() % MJNUM;
		while (1)
		{
			if (num[i] >= 0)
			{
				m_allmj[j] = num[i] / 4 + 1;
				num[i] = -1;
				if (m_allmj[j] >= 10)
				{
					m_allmj[j]++;
				}

				if (m_allmj[j] >= 20)
				{
					m_allmj[j]++;
				}

				if (m_allmj[j] >= 30)
				{
					m_allmj[j]++;
				}
				break;
			}
			else
			{
				i++;
				if (i == MJNUM)
				{
					i = 0;
				}
			}
		}
	}
}

void MJMontain::createMontain()
{
	fillRandNum();
}

void MJMontain::outputMontain()
{
	char * type[] = { "万", "饼", "条" };
	char * num[] = { "", "一", "二", "三", "四", "五", "六", "七", "八", "九" };
	char * word[] = { "", "东风", "南风", "西风", "北风", "白板", "发财", "红中" };

	int j = 0;
	for (auto & i : m_allmj)
	{
		if (i < 0)
		{
			printf("     ");
		}

		if (i / 10 < 3)
		{
			printf("%s%s ", num[i % 10], type[i / 10]);
		}
		else
		{
			printf("%s ", word[i % 10]);
		}
		j++;
		if (j % (MJNUM / 4) == 0)
		{
			putchar('\n');
		}
	}
}

void MJMontain::shootCrap()
{
	int num = rand() % 11 + 2;

	m_getFlag = (num - 1) % 4 * (MJNUM / 4) + num * 2;
}

char MJMontain::sendmj()
{
	char tmp = m_allmj[m_getFlag];

	m_allmj[m_getFlag] = -1;
	m_getFlag++;
	if (m_getFlag == MJNUM)
	{
		m_getFlag = 0;
	}

	return tmp;
}

ostream & operator << (ostream & os, MJMontain & data)
{
	int i, j, k;

	char * type[] = { "万", "饼", "条" };
	char * num[] = { "", "一", "二", "三", "四", "五", "六", "七", "八", "九" };
	char * word1[] = { "", "东", "南", "西", "北", "白", "发", "红" };
	char * word2[] = { "", "风", "风", "风", "风", "板", "财", "中" };
	char * home[] = { "东家", "南家", "西家", "北家" };

	for (i = 0; i < 4; i++)
	{ 
		printf("%s面前牌：\n", home[i]);
		for (j = 0; j < 8; j++)
		{ 
			if (j % 4 == 0)
			{
				printf("┌");
				for (k = 0; k < MJNUM / 8 - 1; k++)
				{
					printf("──┬");
				}
				printf("──┐\n");
			}
			else if (j % 4 == 3)
			{
				printf("└");
				for (k = 0; k < MJNUM / 8 - 1; k++)
				{
					printf("──┴");
				}
				printf("──┘\n");
			}
			else
			{ 
				printf("│");
				for (k = j / 4 + i * (MJNUM / 4); k < MJNUM / 4 + i * (MJNUM / 4); k += 2)
				{
					if (data.m_allmj[k] < 0)
					{
						printf("　│");
						continue;
					}

					if (data.m_allmj[k] / 10 < 3)
					{
						printf("%s│", (j - 1) % 4 ? type[data.m_allmj[k] / 10] : num[data.m_allmj[k] % 10]);
					}
					else
					{
						printf("%s│", (j - 1) % 4 ? word2[data.m_allmj[k] % 10] : word1[data.m_allmj[k] % 10]);
					}
				}
				putchar('\n');
			}
		}
	}
	return os;
}