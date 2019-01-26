#include "SplitsHappenTester.hpp"

#include <iostream>

//! This main simply calls a Tester call in order to test the functionality of the "SplitsHappen" namespace.
int main()
{
    splitshappentester::TestScenarios();

    std::cout << "All tests completed successfully!" << std::endl;

    return 0;
}