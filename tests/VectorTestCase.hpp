
#ifndef VECTORTESTCASE_HPP
# define VECTORTESTCASE_HPP

# include <iostream>
# include <string>
# include <algorithm>
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
        static void testPushBack_PushBackOneElementToEmptyVector_SizeIsOneCapacityIsOneElementAddedCanBeRetreivedWithIndexZero();
        static void testPushBack_PushBackTwoElementsToEmptyVEctor_SizeIsTwoCapacityIsTwoElementAddedLastIsAccessibleAtIndexOne();
        static void testPushBack_PushBackThreeElementsToEmptyVector_SizeIsThreeCapacityIsFourElementAddedLastIsAccessibleAtIndexTwo();
        static void testVectorIterator_VectorOfIntsIsPassedToRandomShuffleAlgorithm_RestltVectorIsOfSizeAsBeforeShuffleButElementsAreInDifferentOrder();
        static void testVectorIterator_SortVectorOfRandomIntsFromOneToFive_SortedVectorOfIntsFromOneTwoFive();
        static void testVectorIterator_SortTenInts_SortedVectorOfInts();
        static void testVectorIterator_SortTenIntsWithSortHeap_SortedVectorOfInts();
        //Reverse ++it
        static void testVectorIteratorReverse_PlusPlusPrefix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues();
        //Reverse it++
        static void testVectorIteratorReverse_CallPlusPlusPostfix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues();
        //Reverse it--
        static void testVectorIteratorReverse_CallMinusMinusPostfix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues();
        //Reverse --it
        static void testVectorIteratorReverse_CallMinusMinusPrefix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues();
        //Reverse it + n
        static void testVectorIteratorReverse_AddIteratorAndTwo_ProducesIteratorSimilarToStdIteratorUnderSameOperations();
        //VectorIterator n + it
        static void testVectorIterator_OffsetPlusIterator_IteratorPointsToElementOffsetByOffsetValueForward();
        //VectorIteratorReverse n + it
        static void testVectorIteratorReverse_OnePlusIterator_IteratorPointingOnePositionCloserToVectorBeginning();
        //it - n
        static void testVectorIteratorReverse_IteratorMinusOne_IteratorPointingToElementOnePositionCloserToVectorsEnd();
        //it - it1
        static void testVectorIteratorReverse_LeftIteratorMinusThreePositionsRighterIterator_PositiveThree();
        static void testVectorIteratorReverse_RightIteratorMinusThreePositionsLefterIterator_NegativeThree();
        //it < it1
        static void testVectotIteratorReversed_IterPositionedCloserToVectorBeginingIsGreaterThenIterPositionedCloserToEnd_true();
        //it > it1
        static void testVectorIteratorRevered_IteratorPositionedCloserToVectorEndIsLessThenIteratorPositionCloserToVectorBeginning_true();
        static void testVectorRend_CallRend_IteratorPointingAtElementBeforVectorTrueBeginning();
        static void testVectorReverseIter_AssignReverseIterToConstReverseIterVar_ReverseIteratorIsConvertedToConstReverseAndProgramDoesntCrash();
};

#endif /* ************************************************ TemplateTestCase_H */