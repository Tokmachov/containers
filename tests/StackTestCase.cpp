#include "StackTestCase.hpp"

StackTestCase::StackTestCase() {}

StackTestCase::StackTestCase( const StackTestCase & src ){ (void)src; }

StackTestCase::~StackTestCase() {}

StackTestCase &StackTestCase::operator=( StackTestCase const & rhs )
{
	(void)rhs;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
//Configure init function so it fills allTests var properly with your test funcitons
//and funciton names
void StackTestCase::initTests()
{
    TestNameAndFunc t1 = 
    { 
        "testStackEmpty_CreateStackWithEnptyListAndCallEmpty_True", 
        testStackEmpty_CreateStackWithEnptyListAndCallEmpty_True
    };
    StackTestCase::allTests.push_back(t1);
	TestNameAndFunc t2 =
	{
		"testStackEmpty_CreateStackFromNoEmptyVectorAndCallEmpry_True", 
		testStackEmpty_CreateStackFromNoEmptyVectorAndCallEmpry_True
	};
	StackTestCase::allTests.push_back(t2);
	TestNameAndFunc t3 =
	{
		"testStackSize_CreateStackFromEmptyVectorAndCallSize_Zero", 
		testStackSize_CreateStackFromEmptyVectorAndCallSize_Zero
	};
	StackTestCase::allTests.push_back(t3);
	TestNameAndFunc t4 =
	{
		"testStackSize_CreateStackFromListFilledWithTwoElements_Two", 
		testStackSize_CreateStackFromListFilledWithTwoElements_Two
	};
	StackTestCase::allTests.push_back(t4);
	TestNameAndFunc t5 =
	{
		"testStackTop_CreateStackFromVectorWithOneElementThatIsFiveAndCallTop_ReturnIsFive", 
		testStackTop_CreateStackFromVectorWithOneElementThatIsFiveAndCallTop_ReturnIsFive
	};
	StackTestCase::allTests.push_back(t5);
	TestNameAndFunc t6 =
	{
		"testStackPush_CreateStackFromEmptyListPushFiveAndCallTop_SizeEqualsOneAndTopReturnsFive", 
		testStackPush_CreateStackFromEmptyListPushFiveAndCallTop_SizeEqualsOneAndTopReturnsFive
	};
	StackTestCase::allTests.push_back(t6);
	TestNameAndFunc t7 =
	{
		"testStackPop_CreateStackPushOneAndFiveCallPop_TopReturnsOneSizeIsOne", 
		testStackPop_CreateStackPushOneAndFiveCallPop_TopReturnsOneSizeIsOne
	};
	StackTestCase::allTests.push_back(t7);
	TestNameAndFunc t8 =
	{
		"testStackEqualOp_CreateTwoStackWithEqualVectors_OperatorReturnsTrue", 
		testStackEqualOp_CreateTwoStackWithEqualVectors_OperatorReturnsTrue
	};
	StackTestCase::allTests.push_back(t8);
	TestNameAndFunc t9 =
	{
		"testStackEqualOp_CreateTwoStackFromNotEqualVectorsAndCompareThemUsingEqualOp_ReturnsFalse", 
		testStackEqualOp_CreateTwoStackFromNotEqualVectorsAndCompareThemUsingEqualOp_ReturnsFalse
	};
	StackTestCase::allTests.push_back(t9);
	TestNameAndFunc t10 =
	{
		"testStackNotEqualOp_CreateTwoStackFromNotEqualListsAndCompareThemUsingNotEqualOp_ReturnsTrue", 
		testStackNotEqualOp_CreateTwoStackFromNotEqualListsAndCompareThemUsingNotEqualOp_ReturnsTrue
	};
	StackTestCase::allTests.push_back(t10);
	TestNameAndFunc t11 =
	{
		"testStackNotEqualOp_CreateTwoStackFromEqualListsAndCompereThemUsingNotEqualOp_MustReturnFalse", 
		testStackNotEqualOp_CreateTwoStackFromEqualListsAndCompereThemUsingNotEqualOp_MustReturnFalse
	};
	StackTestCase::allTests.push_back(t11);
	TestNameAndFunc t12 =
	{
		"testStackLessOp_CompareStackOfOneTwoThreeAndStackOfOneTwoFour_ReturnsTrue", 
		testStackLessOp_CompareStackOfOneTwoThreeAndStackOfOneTwoFour_ReturnsTrue
	};
	StackTestCase::allTests.push_back(t12);
	TestNameAndFunc t13 =
	{
		"testStackLessOp_CompareLhsOneTwoThreeAndRhsOneTwo_MustReturnFalse", 
		testStackLessOp_CompareLhsOneTwoThreeAndRhsOneTwo_MustReturnFalse
	};
	StackTestCase::allTests.push_back(t13);
	TestNameAndFunc t14 =
	{
		"testStackLessOrEqualOp_CompareLhsOneTwoAndRhsOneTwo_MustReturnTrue", 
		testStackLessOrEqualOp_CompareLhsOneTwoAndRhsOneTwo_MustReturnTrue
	};
	StackTestCase::allTests.push_back(t14);
}

void StackTestCase::run()
{
    initTests();
    runAllTests();
    runLeaks();
}

/*
** --------------------------------- TEST_FUNCTIONS ----------------------------
*/
//write here definitions of test functions
//after fucnction proves to work correctly, change "CONSTRUCTION" to "DONE"
//CONSTRUCTION

void StackTestCase::testStackEmpty_CreateStackWithEnptyListAndCallEmpty_True()
{
    //Arrange
    ft::stack<int, ft::list<int> > s;
    //act
    bool result = s.empty();
    //Assert
    assertTrue(result);
}
void StackTestCase::testStackEmpty_CreateStackFromNoEmptyVectorAndCallEmpry_True()
{
	//Arrange
    ft::vector<int> v(5, 10);
    ft::stack<int, ft::vector<int> > s(v);
    //act
    bool result = s.empty();
    //Assert
    assertFalse(result);
}
void StackTestCase::testStackSize_CreateStackFromEmptyVectorAndCallSize_Zero()
{
	//Arrange
    ft::vector<int> v;
    ft::stack<int, ft::vector<int> > s(v);
    //act
    int result = s.size();
    //Assert
    assertTrue(result == 0);
}
void StackTestCase::testStackSize_CreateStackFromListFilledWithTwoElements_Two()
{
	//Arrange
    ft::list<int> l(2, 5);
    ft::stack<int, ft::list<int> > s(l);
    //act
    int result = s.size();
    //Assert
    assertTrue(result == 2);
}
void StackTestCase::testStackTop_CreateStackFromVectorWithOneElementThatIsFiveAndCallTop_ReturnIsFive()
{
	//Arrange
    ft::vector<int> v;
    v.push_back(5);
    ft::stack<int, ft::vector<int> > s(v);
    //act
    int result = s.top();
    //Assert
    assertTrue(result == 5);
}
void StackTestCase::testStackPush_CreateStackFromEmptyListPushFiveAndCallTop_SizeEqualsOneAndTopReturnsFive()
{
	//Arrange
    ft::vector<int> v;
    ft::stack<int, ft::vector<int> > s(v);
    //act
    s.push(5);
    int result = s.top();
    //Assert
    assertTrue(result == 5);
    assertTrue(s.size() == 1);
}
void StackTestCase::testStackPop_CreateStackPushOneAndFiveCallPop_TopReturnsOneSizeIsOne()
{
	//Arrange
    ft::vector<int> v;
    ft::stack<int, ft::vector<int> > s(v);
    s.push(1);
    s.push(5);
    //act
    s.pop();
    //Assert
    assertTrue(s.top() == 1);
    assertTrue(s.size() == 1);
}
void StackTestCase::testStackEqualOp_CreateTwoStackWithEqualVectors_OperatorReturnsTrue()
{
	//Arrange
    ft::vector<int> v1(5, 10);
    ft::vector<int> v2(5, 10);
    ft::stack<int, ft::vector<int> > s1(v1);
    ft::stack<int, ft::vector<int> > s2(v2);
    
    //act
    bool result = (s1 == s2);
    //Assert
    assertTrue(result);
}
void StackTestCase::testStackEqualOp_CreateTwoStackFromNotEqualVectorsAndCompareThemUsingEqualOp_ReturnsFalse()
{
	//Arrange
    ft::vector<int> v1(5, 10);
    ft::vector<int> v2(10, 10);
    ft::stack<int, ft::vector<int> > s1(v1);
    ft::stack<int, ft::vector<int> > s2(v2);
    
    //act
    bool result = (s1 == s2);
    //Assert
    assertFalse(result);
}
void StackTestCase::testStackNotEqualOp_CreateTwoStackFromNotEqualListsAndCompareThemUsingNotEqualOp_ReturnsTrue()
{
	//Arrange
    ft::list<int> v1(5, 10);
    ft::list<int> v2(10, 10);
    ft::stack<int, ft::list<int> > s1(v1);
    ft::stack<int, ft::list<int> > s2(v2);
    
    //act
    bool result = (s1 != s2);
    //Assert
    assertTrue(result);
}
void StackTestCase::testStackNotEqualOp_CreateTwoStackFromEqualListsAndCompereThemUsingNotEqualOp_MustReturnFalse()
{
	//Arrange
    ft::list<int> v1(5, 10);
    ft::list<int> v2(5, 10);
    ft::stack<int, ft::list<int> > s1(v1);
    ft::stack<int, ft::list<int> > s2(v2);
    
    //act
    bool result = (s1 != s2);
    //Assert
    assertFalse(result);
}
void StackTestCase::testStackLessOp_CompareStackOfOneTwoThreeAndStackOfOneTwoFour_ReturnsTrue()
{
	//Arrange
    ft::stack<int, ft::list<int> > s1;
    ft::stack<int, ft::list<int> > s2;
    
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s2.push(1);
    s2.push(2);
    s2.push(4);
    //act
    bool result = (s1 < s2);
    //Assert
    assertTrue(result);
}
void StackTestCase::testStackLessOp_CompareLhsOneTwoThreeAndRhsOneTwo_MustReturnFalse()
{
	//Arrange
    ft::stack<int, ft::vector<int> > s1;
    ft::stack<int, ft::vector<int> > s2;
    
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s2.push(1);
    s2.push(2);
    //act
    bool result = (s1 < s2);
    //Assert
    assertFalse(result);
}
void StackTestCase::testStackLessOrEqualOp_CompareLhsOneTwoAndRhsOneTwo_MustReturnTrue()
{
	//Arrange
    ft::stack<int, ft::vector<int> > s1;
    ft::stack<int, ft::vector<int> > s2;
    
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s2.push(1);
    s2.push(2);
    //act
    bool result = (s1 < s2);
    //Assert
    assertFalse(result);
}













/* ************************************************************************** */
