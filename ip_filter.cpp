#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <array>

using position = std::string::size_type;

auto get_ip(std::string& line)
{
	position	begin{0};
	position	end{line.find_first_of('\t')};

	return line.substr(begin, end - begin);
}

class my_ip {
private:
	// std::array<int, 4> numbers;

public:
	std::array<int, 4> numbers;

	my_ip() = delete;

	my_ip(const std::string& ip) {
		position	begin{0};
		position	end{0};
		int			index{0};

		end = ip.find_first_of('.');
		while (end != std::string::npos) {
			numbers[index] = std::stoi(ip.substr(begin, end - begin));

			begin = end + 1;
			end = ip.find_first_of('.', begin);
			index++;
		}

		numbers[index] = std::stoi(ip.substr(begin, end - begin));

		assert(numbers.size() == 4);
	};

	const int& operator[](int index) const {
		assert(index >= 0 && index < 4);
		return numbers[index];
	};

	bool operator<(const my_ip& ip) const {
		return numbers < ip.numbers;
	}

	friend std::ostream& operator<< (std::ostream& os, const my_ip& ip);
};

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
	try {
		std::vector<my_ip>	ips;

		for (std::string line; std::getline(std::cin, line);) {
			ips.push_back(get_ip(line));
		}
		std::sort(ips.rbegin(), ips.rend());

		std::for_each(ips.begin(), ips.end(), 
			[](const my_ip& ip){
					std::cout << ip << std::endl;
			} 
		);
		// return 0;
		// std::cout << "====================== ip[0] == 1 ===================" << std::endl;
		std::for_each(ips.begin(), ips.end(), 
			[](const my_ip& ip){
				if (ip[0] == 1) {
					std::cout << ip << std::endl;
				}
			} 
		);
		// std::cout << "====================== ip[0] == 46 && ip[1] == 70 ===================" << std::endl;
		std::for_each(ips.begin(), ips.end(), 
			[](const my_ip& ip){
				if (ip[0] == 46 && ip[1] == 70) {
					std::cout << ip << std::endl;
				}
			} 
		);
		// std::cout << "====================== ip[0] == 46 || ip[1] == 46 || ip[2] == 46 || ip[3] == 46 ===================" << std::endl;
		std::for_each(ips.begin(), ips.end(), 
			[](const my_ip& ip){
				if (ip[0] == 46 || ip[1] == 46 || ip[2] == 46 || ip[3] == 46) {
					std::cout << ip << std::endl;
				}
			} 
		);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
