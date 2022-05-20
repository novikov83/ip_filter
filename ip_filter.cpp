#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <array>
#include "my_ip.h"

auto get_ip(std::string& line)
{
	position	begin{0};
	position	end{line.find_first_of('\t')};

	return line.substr(begin, end - begin);
}

std::ostream& operator<< (std::ostream& os, const my_ip& ip)
{
	bool	is_first = true;
	for (auto& n : ip.numbers) {
		if (!is_first) {
			os << ".";
		}
		os << n;
		is_first = false;
	}
	return os;
}
int main(int, char**)
{
	std::vector<my_ip>	ips;
	ips.reserve(100);

	for (std::string line; std::getline(std::cin, line);) {
		ips.push_back(get_ip(line));
	}
	std::sort(ips.rbegin(), ips.rend());

	std::for_each(ips.begin(), ips.end(), 
		[](const my_ip& ip){
				std::cout << ip << std::endl;
		} 
	);

	std::for_each(ips.begin(), ips.end(), 
		[](const my_ip& ip){
			if (ip[0] == 1) {
				std::cout << ip << std::endl;
			}
		} 
	);

	std::for_each(ips.begin(), ips.end(), 
		[](const my_ip& ip){
			if (ip[0] == 46 && ip[1] == 70) {
				std::cout << ip << std::endl;
			}
		} 
	);

	std::for_each(ips.begin(), ips.end(), 
		[](const my_ip& ip){
			if (ip[0] == 46 || ip[1] == 46 || ip[2] == 46 || ip[3] == 46) {
				std::cout << ip << std::endl;
			}
		} 
	);

	return 0;
}
