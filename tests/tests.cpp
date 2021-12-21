//
// Created by Ivan on 21.12.21.
//

#include <gtest/gtest.h>
#include "../Date.h"
#include "../Rectangle.h."
#include "../RationalNumber.h"
#include "../DateParser.h"
#include "../FileReader.h"

TEST(DateTest, NextDaySample){
    ASSERT_EQ(Date(15,5, 2004).getDay(),Date(14, 5, 2004).NextDay().getDay());
    ASSERT_EQ(Date(15,5, 2004).getMonth(),Date(14, 5, 2004).NextDay().getMonth());
    ASSERT_EQ(Date(15,5, 2004).getYear(),Date(14, 5, 2004).NextDay().getYear());
}
TEST(DateTest, PreviosDaySample){
    ASSERT_EQ(Date(13,5, 2004).getDay(),Date(14, 5, 2004).PreviousDay().getDay());
    ASSERT_EQ(Date(13,5, 2004).getMonth(),Date(14, 5, 2004).PreviousDay().getMonth());
    ASSERT_EQ(Date(13,5, 2004).getYear(),Date(14, 5, 2004).PreviousDay().getYear());
}
TEST(DateTest, IsLeapSample){
    Date a = Date(1, 1, 1602);
    ASSERT_EQ(a.IsLeap(), false);
    a = Date(1, 1, 1600);
    ASSERT_EQ(a.IsLeap(), true);
}
TEST(DateTest, WeekNumberSample){
    Date a = Date(15, 1, 2022);
    ASSERT_EQ(a.WeekNumber(), 2);
}
TEST(DateTest, DaysTillYourBithdaySample){
    Date a = Date(14, 5, 2021);
    ASSERT_EQ(a.DaysTillYourBithday(Date(14,05,2005)),0);
}

TEST(DateTest, DurationSample){
    Date a = Date(14, 5, 2021);
    ASSERT_EQ(a.Duration(Date(16,05,2022)),2);
}
TEST(DateTest, ToStringSample){
    Date a = Date(14, 5, 2021);
    ASSERT_EQ(a.ToString(), "14.5.2021");
}
TEST(RationalNumberTest, ToStringSample){
     RationalNumber a = RationalNumber(5, 20, 14);
     ASSERT_EQ(a.ToString(), "14X(1/4)");
}
TEST(RationalNumberTest, SumSample){
    RationalNumber a = RationalNumber(1, 2, 0);
    RationalNumber b = RationalNumber(1, 2, 1);
    ASSERT_EQ(a.Sum(b).ToString(), "2X(0/1)");
}
TEST(RationalNumberTest, SubtractionSample){
    RationalNumber a = RationalNumber(1, 2, 0);
    RationalNumber b = RationalNumber(1, 2, 1);
    ASSERT_EQ(a.Subtraction(b).ToString(), "-1X(0/1)");
}
TEST(RationalNumberTest, DivisionSample){
    RationalNumber a = RationalNumber(1, 2, 0);
    RationalNumber b = RationalNumber(1, 2, 0);
    ASSERT_EQ(a.Division(b).ToString(), "1X(0/1)");
}
TEST(RationalNumberTest, MultiplicationSample){
    RationalNumber a = RationalNumber(1, 2, 0);
    RationalNumber b = RationalNumber(1, 2, 0);
    ASSERT_EQ(a.Multiplication(b).ToString(), "0X(1/4)");
}
TEST(RectangleTest, Square1Sample){
    Rectangle a = Rectangle(-2, 2, 1, -3);
    Rectangle b = Rectangle(0, 1, 4, 0);
    ASSERT_EQ(a.SquareOfUnion(b), 1);
}
TEST(RectangleTest, Square2Sample){
    Rectangle a = Rectangle(-2, 2, 1, -3);
    Rectangle b = Rectangle(0, 1, 1, -3);
    ASSERT_EQ(a.SquareOfUnion(b), 4);
}

TEST(Date2Test, NextDaySample){
    FileReaderWriter reader;
    std::vector<std::string> col = reader.read("../dates.txt");
    reader.DatesNextDay(col);
}
TEST(Date2Test, DurationSample){
    FileReaderWriter reader;
    std::vector<std::string> col = reader.read("../dates.txt");
    reader.DatesDuration(col);
}



