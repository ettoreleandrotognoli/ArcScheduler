#include <gtest/gtest.h>
#include "bluefairy.h"
#include "math/math.h"
#include <iostream>

using namespace bluefairy::math;

TEST(Math,uint_greatestCommonDivisor){
    EXPECT_EQ(greatestCommonDivisor(1,1),1);
    EXPECT_EQ(greatestCommonDivisor(2,1),1);
    EXPECT_EQ(greatestCommonDivisor(4,2),2);
    EXPECT_EQ(greatestCommonDivisor(10,5),5);
    EXPECT_EQ(greatestCommonDivisor(13,7),1);
    EXPECT_EQ(greatestCommonDivisor(7,13),1);
}

TEST(Math,int_greatestCommonDivisor){
    EXPECT_EQ(greatestCommonDivisor(1,-1),1);
    EXPECT_EQ(greatestCommonDivisor(2,-1),1);
    EXPECT_EQ(greatestCommonDivisor(4,-2),2);
    EXPECT_EQ(greatestCommonDivisor(10,-5),5);
    EXPECT_EQ(greatestCommonDivisor(13,-7),1);
    EXPECT_EQ(greatestCommonDivisor(7,-13),1);
    EXPECT_EQ(greatestCommonDivisor(-1,1),1);
    EXPECT_EQ(greatestCommonDivisor(-2,1),1);
    EXPECT_EQ(greatestCommonDivisor(-4,2),2);
    EXPECT_EQ(greatestCommonDivisor(-10,5),5);
    EXPECT_EQ(greatestCommonDivisor(-13,7),1);
    EXPECT_EQ(greatestCommonDivisor(-7,13),1);
}

int main(int argc,char ** argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}