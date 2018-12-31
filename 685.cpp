#include <iostream>
#include <string>
#include <vector>
const int Base = 131;
std::vector<std::string> ninjas;
std::string T;
unsigned long long hash(const std::string &s)
{
	unsigned long long ans = 0;
	for (int i = 0; i < s.size(); ++i)
		ans = ans * Base + static_cast<unsigned long long>(s[i]);
	return ans;
}
int main()
{
	while (std::cin >> T)
		ninjas.push_back(T);
	T = ninjas.back();
	ninjas.pop_back();

}