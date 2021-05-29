
#ifndef VECTORTESTCASE_HPP
# define VECTORTESTCASE_HPP

# include <iostream>
# include <string>
# include "TestCase.hpp"

# include "../vector/vector.hpp"

class VectorTestCase : public TestCase
{
	public:
        static void run();
	protected:
        static void initTests();
    private:
        VectorTestCase();
		VectorTestCase( VectorTestCase const & src );
		~VectorTestCase();
		VectorTestCase &		operator=( VectorTestCase const & rhs );
        
        //support type
        class TestClass
        {
            public:
            int value;
        };
        //Test functions
        //Please write declaration of test functions here
        //static void testIteratorsOfTwoListsWithSameSequencesMustNotBeEqual();
};

#endif /* ************************************************ TemplateTestCase_H */