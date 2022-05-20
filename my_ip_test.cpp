#include <gtest/gtest.h>
#include "my_ip.h"

TEST(MyIp, Create_1_2_3_4) {
	my_ip	ip{"1.2.3.4"};

	EXPECT_EQ(ip.numbers.size(), 4);
	EXPECT_EQ(ip.numbers[0], 1);
	EXPECT_EQ(ip.numbers[1], 2);
	EXPECT_EQ(ip.numbers[2], 3);
	EXPECT_EQ(ip.numbers[3], 4);
}

TEST(MyIp, Create_1_2_3) {
	my_ip	ip{"1.2.3"};

	EXPECT_EQ(ip.numbers.size(), 4);
	EXPECT_EQ(ip.numbers[0], 1);
	EXPECT_EQ(ip.numbers[1], 2);
	EXPECT_EQ(ip.numbers[2], 3);
	EXPECT_EQ(ip.numbers[3], -1);
}

TEST(MyIp, Create_empty) {
//	EXPECT_THROW(my_ip{""}, std::invalid_argument);
	EXPECT_NO_THROW(my_ip{""});
}

int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
