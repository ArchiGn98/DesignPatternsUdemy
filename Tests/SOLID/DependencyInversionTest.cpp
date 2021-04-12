#include "../../Source/SOLID/DependencyInversion.h"
#include <gtest/gtest.h>

/*
 * Dependency Inversion Principle
 * A High-level modules should not depend on low-level modules.
 *   Both should depend on abstractions
 * B Abstractions should not depend on details.
 *   Details should depend on abstractions
*/

TEST(SOLIDDependencyInversion, test)
{
    Human parent{ "John" };
    Human child1{ "Matt" };
    Human child2{ "Chris" };
    
    Relationships relationships;
    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);
    Research research{ relationships };
    auto result = research.MakeResearch(parent);
    
    std::vector<std::string> expectedResult{ "Matt" , "Chris" };

    EXPECT_EQ(result, expectedResult);
}
