#include <iostream>

int main()
{
	unsigned int size;
	std::cin >> size;

	unsigned int space = size - 1;
	int num = 1;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < space; j++)
		{
			std::cout << " ";
		}

		for (int k = 0; k <= i*2; k++)
		{
			std::cout << num;

			if (k < i * 2)
			{
				if (k >= i && i != 0)
				{
					num++;
				}
				else if (i != 0)
				{
					num--;
				}
			}
		}

		std::cout << std::endl;
		space--;
		num++;
	}

	system("pause");
	return 0;
}