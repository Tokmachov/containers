#include "TestCase.hpp"

TestCase::TestCase() {}

TestCase::TestCase( const TestCase & src ) { (void)src; }

TestCase::~TestCase() {}

TestCase &TestCase::operator=( TestCase const & rhs ) { (void)rhs; return *this; }

/*
** --------------------------------- PUBLIC METHODS ----------------------------
*/

void TestCase::run() {}

/*
** --------------------------------- PROTECTED ---------------------------------
*/

std::vector<TestCase::TestNameAndFunc> TestCase::allTests;

void TestCase::initTests() {}

void TestCase::startTestLoop()
{
    //runAllTests();
    while (true)
    {
        showTestsMenu();
        int choice;
        readUserChoice(choice);
        switch (choice)
        {
            case 1:
                exit(0);
            case 2:
                return ;
            case 3:
                runAllTests();
                break ;
            default:
                std::cout << "Unknown key" << std::endl;
                break ;
        }
    }
}

void TestCase::showTestsMenu()
{
    std::cout << "Chose tests to run:" << std::endl;
    std::cout << "1 - exit test programm" << std::endl;
    std::cout << "2 - skip test case and go to next" << std::endl;
    std::cout << "3 - Run all tests" << std::endl;
}

void TestCase::readUserChoice(int &choice)
{
    std::string ch;

    std::cin >> ch;
    choice = atoi(ch.c_str());
}

void TestCase::runAllTests()
{
    std::vector<TestNameAndFunc>::const_iterator it_begin;
    std::vector<TestNameAndFunc>::const_iterator it_end;
    
    it_begin = TestCase::allTests.begin();
    it_end = TestCase::allTests.end();
    for (; it_begin != it_end; it_begin++)
    {
        runTest(*it_begin);
    }
}

void TestCase::runTest(const TestNameAndFunc &testNameAndFunc)
{
    std::cout << MAGENTA << "--- " << testNameAndFunc.name << RESET << std::endl;
    (*(testNameAndFunc.testFunctionPtr))();
}

void TestCase::assertTrue(bool result)
{
    if (result)
        std::cout << GREEN << "--- Success" << RESET << std::endl;
    else
        std::cout << RED << "--- Failed" << RESET << std::endl;
}

void TestCase::assertFalse(bool result)
{
    if (!result)
        std::cout << GREEN << "--- Success" << RESET << std::endl;
    else
        std::cout << RED << "--- Failed" << RESET << std::endl;
}

/*
** --------------------------------- PROTECTED METHODS -------------------------
*/

/* ************************************************************************** */