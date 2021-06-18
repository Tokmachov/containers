#ifndef STACKTESTCASE_HPP
# define STACKTESTCASE_HPP

# include <iostream>
# include <string>
# include "TestCase.hpp"
# include "../stack/stack.hpp"
# include "../list/list.hpp"
# include "../vector/vector.hpp"

class StackTestCase : public TestCase
{
	public:
        static void run();
	protected:
        static void initTests();
    private:
        StackTestCase();
		StackTestCase( StackTestCase const & src );
		~StackTestCase();
		StackTestCase &		operator=( StackTestCase const & rhs );
        
        //support type
        class TestClass
        {
            public:
            int value;
        };
        //Test functions
        //Please write declaration of test functions here
        static void testStackEmpty_CreateStackWithEnptyListAndCallEmpty_True();
        static void testStackEmpty_CreateStackFromNoEmptyVectorAndCallEmpry_True();
        static void testStackSize_CreateStackFromEmptyVectorAndCallSize_Zero();
        static void testStackSize_CreateStackFromListFilledWithTwoElements_Two();
        static void testStackTop_CreateStackFromVectorWithOneElementThatIsFiveAndCallTop_ReturnIsFive();
        static void testStackPush_CreateStackFromEmptyListPushFiveAndCallTop_SizeEqualsOneAndTopReturnsFive();
        static void testStackPop_CreateStackPushOneAndFiveCallPop_TopReturnsOneSizeIsOne();
        static void testStackEqualOp_CreateTwoStackWithEqualVectors_OperatorReturnsTrue();
        static void testStackEqualOp_CreateTwoStackFromNotEqualVectorsAndCompareThemUsingEqualOp_ReturnsFalse();
        static void testStackNotEqualOp_CreateTwoStackFromNotEqualListsAndCompareThemUsingNotEqualOp_ReturnsTrue();
        static void testStackNotEqualOp_CreateTwoStackFromEqualListsAndCompereThemUsingNotEqualOp_MustReturnFalse();
        static void testStackLessOp_CompareStackOfOneTwoThreeAndStackOfOneTwoFour_ReturnsTrue();
        static void testStackLessOp_CompareLhsOneTwoThreeAndRhsOneTwo_MustReturnFalse();
        static void testStackLessOrEqualOp_CompareLhsOneTwoAndRhsOneTwo_MustReturnTrue();
};

#endif /* ************************************************ TemplateTestCase_H */