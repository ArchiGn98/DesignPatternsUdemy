#include "../../Source/SOLID/InterfaceSegregation.h"
#include <gtest/gtest.h>


/*
 * Interface Segregation Principle (ISP)
 * Do not create interfaces that are too large
 * or require implementators to implement too much
 */

TEST(SOLIDInterfaceSegregation, test1)
{
    Printer printer;
    Scanner scanner;
    std::string expected_printer = "print";
    std::string expected_scanner = "scan";

    Machine machine(printer, scanner);

    bool bTestPassed = machine.print() == expected_printer && machine.scan() == expected_scanner;

	EXPECT_EQ(bTestPassed, true);
}