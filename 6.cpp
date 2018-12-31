#include <iostream>
const int N = 10;
char matrix[N][N];
bool ill[N][N];
int n = 5;
int main()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			std::cin >> matrix[i][j], ill[i][j] = matrix[i][j] == 'A';
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (ill[i][j])
				matrix[i - 1][j] = matrix[i + 1][j] = matrix[i][j - 1] = matrix[i][j + 1] = 'A';
	for (int i = 1; i <= n; ++i, std::cout << std::endl)
		for (int j = 1; j <= n; ++j)
			std::cout << matrix[i][j];
	return 0;
}