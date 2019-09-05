#include <iostream>
#include <algorithm>

int main()
{
	int n;
	int * data = new int [n];
	
	std::cin >> n;
	int i = 0;
	for (i = 0; i < n; i++)
	{
		std::cin >> data[i];
	}
	std::sort(data, data + i);
	
	i = 0;
	int count = 0, j = n - 1;
	while(i < j)
	{
		if(data[i] + data[j] > 0)
		{
			j--;
		}
		else if(data[i] + data[j] < 0)
		{
			i++;
		}
		else
		{
			count++, i++, j--;
		}
	}
	
	std::cout << count;
	
	delete [] data;
	return 0;
}
 
