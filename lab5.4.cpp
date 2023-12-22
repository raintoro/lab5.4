#include <iostream>
#include <math.h>

//Проверка есть ли цифра g в числе N
bool is_number(int N, int g)
{
	while (N > 0)
	{
		if (N % 10 == g)
			return true;
		N /= 10;
	}
	return false;
}

// Является ли чило N - простым?
bool is_prost(int N) {
	if (N == 2)
		return true;
	for (int i = 2; i < (sqrt(N) + 1); i++)
	{
		if (N % i == 0)
			return false;
	}
	return true;

}

int main()
{
	int M[20000];
	short n;
	std::cin >> n;

	for (short i = 0; i < n; i++)
		std::cin >> M[i];

	{
		// удаление из массива чисел
		for (short i = 0; i < n; i++)
		{
			if (is_number(M[i], 7)) {
				//sdvig massiva vlevo do i
				for (int j = i; j < n - 1; j++)
				{
					M[j] = M[j + 1];
				}
				i--;
				n--;
			}
		}
		//Вывод массива до дубл
		std::cout << "mas without: ";
		for (short i = 0; i < n; i++)
			std::cout << M[i] << " ";
		std::cout << "\n";


		//дубл прост числ
		short h = n;
		for (short i = 0; i < h; i++)
		{
			if (is_prost(M[i]))
			{
				h++;
				for (short j = h; j > i; j--)
				{
					M[j] = M[j - 1];
				}
				i++;
			}
		}
		n = h;
	}
	std::cout << "end mas: ";
	for (short i = 0; i < n; i++)
		std::cout << M[i] << " ";

}
//10 7 67 7 11 11 7 11 707 88 7
//10 757 7623 555 13 10 67 74 37 99 7