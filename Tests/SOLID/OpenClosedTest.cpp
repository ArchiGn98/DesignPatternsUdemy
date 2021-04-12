#include "../../Source/SOLID/Open-Closed.h"
#include <gtest/gtest.h>
#include <vector>

/* 
 * Open-Closed Principle(OCP)
 * software entities (classes, modules, functions, etc.)
 * should be open for extension, but closed for modification
 */

TEST(SOLIDOpenClosed, ProductFilterTest)
{
    Product apple{ "Apple", Color::green, Size::small };
    Product tree{ "Tree", Color::green, Size::large };
    Product house{ "House", Color::blue, Size::large };

    vector<Product*> products{ &apple, &tree, &house };
    vector<Product*> expected_products{ &apple, &tree };

    ProductFilter pf;
    auto green_products = pf.by_color(products, Color::green);
    
    EXPECT_EQ(green_products, expected_products);
}

TEST(SOLIDOpenClosed, BetterFilterTest)
{
    Product apple{ "Apple", Color::green, Size::small };
    Product tree{ "Tree", Color::green, Size::large };
    Product house{ "House", Color::blue, Size::large };

    vector<Product*> products{ &apple, &tree, &house };
    vector<Product*> expected_products{ &tree };

    BetterFilter bf;
    ColorSpecification green{ Color::green };
    SizeSpecification large{ Size::large };
    AndSpecification<Product> green_and_large{ green, large };

    auto green_large_products = bf.filter(products, green_and_large);

    EXPECT_EQ(green_large_products, expected_products);
}

float poww(int a, int s)
{

    if (s < 0) 
    {
        return 1.0 / poww(a, std::abs(s));
    } 

    float rez = 1.f;
    for (int i = 0; i < s; ++i)
    {
        rez *= a;
    }
    return rez;
}

TEST(PowTest, PositiveExponentiation)
{
    int inputNumber = 2;
    std::vector<int> inputPowers{ 1, 2, 3, 4, 5, 6, 7 };
    std::vector<int> expected { 2, 4, 8, 16, 32, 64, 128 };
    std::vector<int> result;
    for (auto power : inputPowers)
    {
        result.push_back(poww(inputNumber, power));
    }


    EXPECT_EQ(result, expected);
}

TEST(PowTest, NegativeExponentiation)
{
    int inputNumber = 2;
    std::vector<int> inputPowers{ -1, -2, -3, -4 };
    std::vector<float> expected{ 0.5f, 0.25f, 0.125f, 0.0625f };
    std::vector<float> result;
    for (auto power : inputPowers)
    {
        result.push_back(poww(inputNumber, power));
    }


    EXPECT_EQ(result, expected);
}

TEST(PowTest, ZeroExponentiation)
{
    int inputNumber = 2;
    int inputPower = 0;
    int expected = 1;
    int result = poww(inputNumber, inputPower);

    EXPECT_EQ(result, expected);
}
