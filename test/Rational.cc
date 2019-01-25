#include <stdlib.h>
#include <stdio.h>
#include <cmath>
#include <gtest/gtest.h>
#include "bluefairy.h"
#include "math/Rational.h"
#include <iostream>

using bluefairy::math::Rational;

TEST(Rational,DEFAULT_DENOMINATOR){
    Rational<int> a(1);
    EXPECT_EQ(a.getNumerator(),1);
    EXPECT_EQ(a.getDenominator(),1);
}

TEST(Rational,FULL_CONSTRUCTOR){
    Rational<int> a(2, 10);
    EXPECT_EQ(a.getNumerator(),2);
    EXPECT_EQ(a.getDenominator(),10);
}

TEST(Rational,uint_bitReduce) {
    Rational<unsigned int> a(20, 20);
    a.bitReduce();
    EXPECT_EQ(5,a.getNumerator());
    EXPECT_EQ(5,a.getDenominator());
}

TEST(Rational,int_bitReduce) {
    Rational<int> a(20, -20);
    a.bitReduce();
    EXPECT_EQ(5,a.getNumerator());
    EXPECT_EQ(-5,a.getDenominator());
}

TEST(Rational,reduce_equal) {
    Rational<int> a(20, -20);
    a.reduce();
    EXPECT_EQ(1,a.getNumerator());
    EXPECT_EQ(-1,a.getDenominator());
}

TEST(Rational,reduce_prime) {
    Rational<int> a(13,7);
    a.reduce();
    EXPECT_EQ(13,a.getNumerator());
    EXPECT_EQ(7,a.getDenominator());
}

TEST(Rational,multiply) {
    Rational<int> a(1,1) , b(2,2);
    Rational<int> c = a * b;
    EXPECT_EQ(a.getNumerator(),1);
    EXPECT_EQ(b.getNumerator(),2);
    EXPECT_EQ(c.getNumerator(),2);
    EXPECT_EQ(a.getDenominator(),1);
    EXPECT_EQ(b.getDenominator(),2);
    EXPECT_EQ(c.getDenominator(),2);
}

int main(int argc,char ** argv){
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}