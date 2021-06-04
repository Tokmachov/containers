#include "TemplateTestCase.hpp"

TemplateTestCase::TemplateTestCase() {}

TemplateTestCase::TemplateTestCase( const TemplateTestCase & src ){ (void)src; }

TemplateTestCase::~TemplateTestCase() {}

TemplateTestCase &TemplateTestCase::operator=( TemplateTestCase const & rhs )
{
	(void)rhs;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
//Configure init function so it fills allTests var properly with your test funcitons
//and funciton names
void TemplateTestCase::initTests()
{
    // TestNameAndFunc t1 = 
    // { 
    //     "testIteratorsOfTwoListsWithSameSequencesMustNotBeEqual", 
    //     testCopyConstructionMustProduceEqualIterators
    // };
    // TemplateTestCase::allTests.push_back(t1);
}

void TemplateTestCase::run()
{
    initTests();
    runAllTests();
}

/*
** --------------------------------- TEST_FUNCTIONS ----------------------------
*/
//write here definitions of test functions
//after fucnction proves to work correctly, change "CONSTRUCTION" to "DONE"
//CONSTRUCTION

// void TemplateTestCase::testFuncName()
// {

// }
/* ************************************************************************** */