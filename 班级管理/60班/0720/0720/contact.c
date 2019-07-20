#include "contact.h"
#include <string.h>
#include <stdio.h>

/*
void searchData(char * find, int * searchres)
{
	int i, flag;
	char age[4] = { 0 };
	char * ret;
	for (i = 0; i < g_count; i++)
	{
		do{
			flag = 1;
			ret = strstr(g_allMsg[i].name, find);
			if (ret)
			{
				break;
			}

			ret = strstr(g_allMsg[i].telnum, find);
			if (ret)
			{
				break;
			}

			sprintf(age, "%d", g_allMsg[i].age);
			if (!strcmp(age, find))
			{
				break;
			}

			ret = strstr(g_allMsg[i].addr, find);
			if (ret)
			{
				break;
			}

			flag = 0;
		} while (0);

		if (flag)
		{
			searchres[0]++;
			searchres[searchres[0]] = i;
		}
	}
}
*/

void fillData(Contact * src, char * name, char sex, char age, char * pn, char * addr)
{
	if (src == NULL)
	{ 
		return;
	}

	strcpy(src->name, name);
	src->sex = sex;
	src->age = age;
	strcpy(src->phonenum, pn);
	strcpy(src->address, addr);
}

int Contactcmp(Contact c1, Contact c2)
{
	return strcmp(c1.name, c2.name);
}

Contact createData()
{
	Contact ret;

	scanf("%[^\n]", ret.name);
	getchar();
	scanf("%c", &ret.sex);
	scanf("%d", &ret.age);
	scanf("%s", ret.phonenum);
	getchar();
	scanf("%[^\n]", ret.address);
	getchar();
}

void printData(Contact data)
{
	printf("%15s %c %2d %12s %s\n",
			data.name,
			data.sex,
			data.age,
			data.phonenum,
			data.address);
}