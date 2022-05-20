#include <gtest/gtest.h>
#include "my_ip.h"

TEST(MyIp, Create) {
	my_ip	ip{"1.2.3.4"};

	ASSERT_EQ(ip.numbers.size(), 4);
	ASSERT_EQ(ip.numbers[0], 1);
	ASSERT_EQ(ip.numbers[1], 2);
	ASSERT_EQ(ip.numbers[2], 3);
	ASSERT_EQ(ip.numbers[3], 4);
}

TEST(MyIp, Create_1_2_3) {
	my_ip	ip{"1.2.3"};

	ASSERT_EQ(ip.numbers.size(), 4);
	ASSERT_EQ(ip.numbers[0], 1);
	ASSERT_EQ(ip.numbers[1], 2);
	ASSERT_EQ(ip.numbers[2], 3);
	ASSERT_EQ(ip.numbers[3], 0);
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
