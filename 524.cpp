#include <iostream>
int main()
{
	unsigned long long a;
	char b;
	std::cin >> a >> b;
	switch (b)
	{
		case 'P':a *= 1024;
		case 'T':a *= 1024;
		case 'G':a *= 1024;
		case 'M':a *= 1024;
		case 'K':a *= 1024;
		case 'B':a *= 8;
	}
	std::cout << a << std::endl;
}