#ifndef TESTCASE_HPP
# define TESTCASE_HPP

# include <iostream>
# include <string>
# include <vector>

# define RED "\033[31m" /* Red */
# define GREEN "\033[32m" /* Green */
# define RESET "\033[0m"
# define MAGENTA "\033[35m" /* Magenta */

class TestCase
{
    public:
        TestCase();
		~TestCase();
        static void run();
    protected:
        struct TestNameAndFunc
        {
            std::string name;
            void (*testFunctionPtr) (void);
        };
        static std::vector<TestNameAndFunc> allTests;
        static void initTests();
        static void startTestLoop();
        template <typename T>
        static void assertEqual(T expected, T actual)
        {
            if (expected == actual)
                std::cout << GREEN << "--- Success" << RESET << std::endl;
            else
                std::cout << RED << "--- Failed" << RESET << std::endl;
        }
        static void assertTrue(bool result);
        static void assertFalse(bool result);
        template<typename InputIterator1, typename InputIterator2>
        static bool areEqualInSizeAndElements
        ( 
            InputIterator1 first1, 
            InputIterator1 last1, 
            InputIterator2 first2, 
            InputIterator2 last2 
        )
        {
            bool equal1 = std::equal(first1, last1, first2);
            bool equal2 = std::equal(first2, last2, first1);
            return equal1 && equal2;
        }
    private:
        TestCase( TestCase const & src );
		TestCase &		operator=( TestCase const & rhs );
        
        //startTests();
        static void showTestsMenu();
        static void readUserChoice(int &choice);
        static void runTest(const TestNameAndFunc &testNameAndFunc);
        static void runAllTests();
};

#endif /* ******************************************************** TESTCASE_H */