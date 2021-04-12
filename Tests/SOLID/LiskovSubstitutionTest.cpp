#include "../../Source/SOLID/LiskovSubstitution.h"
#include <gtest/gtest.h>


/*
 * Liskov substitution principle (LSP)
 * Subtypes should be immediately substitutable for their base types
 */

TEST(SOLIDLiskovSubstitution, RectangleTest)
{
    Rectangle rec{ 3,4 };
    int area = rec.area();
    int expectedArea = 12;

    EXPECT_EQ(area, expectedArea);
}

TEST(SOLIDLiskovSubstitution, SquareTest)
{
    Square sq{ 5 };
    int area = sq.area();
    int expectedArea = 25;

    EXPECT_EQ(area, expectedArea);
}
