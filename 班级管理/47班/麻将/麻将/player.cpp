#include "player.h"

void Player::insertmj(int n)
{
	int i;
	char tmp = m_Hand[n];

	for (i = n; i > 0 && m_Hand[i - 1] > tmp; i--)
	{
		m_Hand[i] = m_Hand[i - 1];
	}

	m_Hand[i] = tmp;
}

void Player::deletemj(int n)
{
	int i;

	for (i = n; i < m_size - 1; i++)
	{
		m_Hand[i] = m_Hand[i + 1];
	}

	m_size--;
}

void Player::getmj(char mj)
{
	if (mj < 0)
	{
		return;
	}
	m_Hand[m_size] = mj;
	m_size++;
	
	if (m_size == 14)
	{
		showmj();
		int tmp;
		cin >> tmp;
		deletemj(tmp);
		if (tmp != 13)
		{
			insertmj(m_size - 1);
		}
	}
	else
	{
		insertmj(m_size - 1);
	}
}

void Player::showmj()
{
	int i, j;

	char * type[] = { "万", "饼", "条" };
	char * num[] = { "", "一", "二", "三", "四", "五", "六", "七", "八", "九" };
	char * word1[] = { "", "东", "南", "西", "北", "白", "发", "红" };
	char * word2[] = { "", "风", "风", "风", "风", "板", "财", "中" };
	int flag = 0;

	if (m_size == 14)
	{
		flag = 1;
	}

	printf("%s的手牌：\n", m_name);
	for (i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			printf("┌");
			for (j = 0; j < m_size - 1 - flag; j++)
			{
				printf("──┬");
			}
			printf("──┐");

			if (flag)
			{
				printf("　┌──┐");
			}
		}
		else if (i == 3)
		{
			printf("└");
			for (j = 0; j < m_size - 1 - flag; j++)
			{
				printf("──┴");
			}
			printf("──┘");

			if (flag)
			{
				printf("　└──┘");
			}
		}
		else
		{
			printf("│");
			for (j = 0; j < m_size - flag; j++)
			{
				if (m_Hand[j] < 0)
				{
					printf("　│");
					continue;
				}

				if (m_Hand[j] / 10 < 3)
				{
					printf("%s│", i - 1 ? type[m_Hand[j] / 10] : num[m_Hand[j] % 10]);
				}
				else
				{
					printf("%s│", i - 1 ? word2[m_Hand[j] % 10] : word1[m_Hand[j] % 10]);
				}
			}

			if (flag)
			{
				if (m_Hand[j] / 10 < 3)
				{
					printf("　│%s│", i - 1 ? type[m_Hand[j] / 10] : num[m_Hand[j] % 10]);
				}
				else
				{
					printf("　│%s│", i - 1 ? word2[m_Hand[j] % 10] : word1[m_Hand[j] % 10]);
				}
			}
		}
		putchar('\n');
	}
}