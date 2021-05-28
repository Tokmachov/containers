
#ifndef TEMPLATETESTCASE_HPP
# define TEMPLATETESTCASE_HPP

# include <iostream>
# include <string>
# include "TestCase.hpp"

class TemplateTestCase : public TestCase
{
	public:
        static void run();
	protected:
        static void initTests();
    private:
        TemplateTestCase();
		TemplateTestCase( TemplateTestCase const & src );
		~TemplateTestCase();
		TemplateTestCase &		operator=( TemplateTestCase const & rhs );
        
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