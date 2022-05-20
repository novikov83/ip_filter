using position = std::string::size_type;

class my_ip {
public:
	std::array<int, 4> numbers {0, 0, 0, 0};

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
