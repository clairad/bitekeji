#include <stdio.h>

void mktree(char data[][4], char root)
{
	char mystack[26] = { 0 };
	int size = 0;
	char tmp = root;

	while (tmp != '*' || size != 0)
	{
		putchar(tmp);

		if (data[tmp - 'a'][2] != '*')
		{
			mystack[size] = data[tmp - 'a'][2];
			size++;
		}

		if (data[tmp - 'a'][1] != '*')
		{
			tmp = data[tmp - 'a'][1];
		}
		else
		{
			if (size != 0)
			{
				tmp = mystack[size - 1];
				size--;
			}
			else
			{
				tmp = '*';
			}
		}
	}
}

int main()
{
	char data[26][4] = { 0 };
	char tmp;
	char root;
	int n;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		getchar();
		tmp = getchar();
		data[tmp - 'a'][0] = tmp;
		scanf("%s", data[tmp - 'a'] + 1);
		if (i == 0)
		{
			root = tmp;
		}
	}

	mktree(data, root);

	return 0;
}
