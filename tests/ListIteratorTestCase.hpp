#ifndef LISTITERATORTESTCASE_HPP
# define LISTITERATORTESTCASE_HPP

# include <iostream>
# include <string>
# include "TestCase.hpp"
# include <algorithm>
# include <list>

# include "../list/list.hpp"
class ListIteratorTestCase : public TestCase
{
	public:
        static void run();
	protected:
        static void initTests();
    private:
        ListIteratorTestCase();
		ListIteratorTestCase( ListIteratorTestCase const & src );
		~ListIteratorTestCase();
		ListIteratorTestCase &		operator=( ListIteratorTestCase const & rhs );
        
        //support type
        class TestClass
        {
            public:
            int value;
        };
        //Test functions
        static void testIteratorsOfTwoListsWithSameSequencesMustNotBeEqual();
        static void testCopyConstructionMustProduceEqualIterators();
        static void testAssignationMustProduceEqualIterators();
        static void testIteratorYieldsCorrectValueWhenDereferenced();
        static void testIteratorYieldsCorrectValueWhenDereferencedWithArrow();
        static void testMutableIteratorAllowsToCorrectlySetListValue();
        static void testPrefixPlusPlusSetsIteratorToCorrectPosition();
        static void testPrefixPlusPlusReturnValueMustBeValueAfterOpCall();
        static void testPostfixPlusPlusSetsIteratorToCorrectPosition();
        static void testPrefixMinuMinusSetsIteratorToCorrectPosition();
        static void testPostfixMinuMinusSetsIteratorToCorrectPosition();

        static void testConstIteratorsOfTwoListsWithSameSequencesMustNotBeEqual();
        static void testCopyConstructionMustProduceEqualConstIterators();
        static void testAssignationMustProduceEqualConstIterators();
        static void testConstIteratorYieldsCorrectValueWhenDereferenced();
        static void testConstIteratorYieldsCorrectValueWhenDereferencedWithArrow();
        static void testPrefixPlusPlusSetsConstIteratorToCorrectPosition();
        static void testPostfixPlusPlusSetsConstIteratorToCorrectPosition();
        static void testPrefixMinusMinusSetsConstIteratorToCorrectPosition();
        static void testPostfixMinusMinusSetsConstIteratorToCorrectPosition();
        
        static void testTwoListsOfIntsFromOneToNineMustCompareEqual();
        static void testTwoDifferentListsOfIntsMustNotCompareEqual();
        static void testIfStablePartitionAlgorithmSortsOddsToTheLeftInSequenseFromOneToNine();
        static bool IsOdd (int i) { return (i%2)==1; }

        static void testReversedSequensFromOneToNineObtainedWithReverseIteratorsMustBeEqualToSequenceFromNineToOne();
};

#endif /* ************************************************ ListIteratorTestCase_H */