#include <stdio.h>
#include <stdlib.h>

int main112()
{
	int murder = 0;
	for (murder = 'A'; murder < 'E'; ++murder)
	{
		/*A说：不是我。
			B说：是C。
			C说：是D。
			D说：C在胡说*/
		if ((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D') == 3)
		{
			printf("%c是凶手\n", murder);
		}
	}

	return 0;
}