
#ifndef VECTORTESTCASE_HPP
# define VECTORTESTCASE_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include "TestCase.hpp"
# include "../vector/vector.hpp"
# include <list>

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
        static void testVectorFillConstructor_FillConstructorWithParamsNEqualFiveAndValEqualTwo_VectorOfSizeFiveAndEachValueIsEqualToTwo();
        static void testVectorFillConstructor_CallFillConstructorWithParamsNEqualZeroAndValEqualTwo_VectorOfSizeZero();
        static void testVectorRangeConstructor_CallRangeConstructorWithIntsArrayFromOneToFiveStartAndEnd_VectorContainsElementsFromOneToFiveAndItsSizeIsFour();
        static void testVectorCopyConstructor_ConstructVectorWithCopyConstructorFromAnotherVector_SrcVectorIsEqualInSizeAndElementsToResultVector();
        static void testVectorAssignment_AssignOneVectorWithMultipleElementsToAnotherVectorWithMultipleElemnts_SrcVectorAndResultVectorAreEqualInSizeAndElements();
        static void testVectorSize_CreateVectorOfFiveIntsWithFillConstructor_SizeYieldsFive();
        static void testVectoSize_AddOneELementToVectorOfFiveELement_SizeYieldsSix();
        static void testVectorResize_ResizeToParamNLessThenSize_SizeIsEqualToN();
        static void testVectorResize_ResizeToNThatIsGreaterByThreeThenSizeAndValueIsProvided_ResultVectorIsEqualInSizeAndElementsToVectorAsIfCreatedFromInitialVectorByPushingBackThreeTimesElementsEqualToValueParameterOfResize();
        static void testVectorResize_ResizeToNThatExceedsCapacity_ResultVectorMustBeEqualToInitialVectorAsIfItWasPushBackedWithValParamOfResizeNMinusSizeAndResultCapacityIsGreaterThenInitialCapacity();
        static void testVectorCapacity_AddElementToEmtyVector_CapacityIsTwo();
        static void testVectorCapacity_CreateEmptyVector_CapacityIsZero();
        static void testVectorCapacity_VectorOfSizeOneAndCapcityTwoPushBackedWithTwoElements_CapcityIsInitialCapcityIncreaseByOneAndThenDoubled();
        static void testVectorEmpty_VectorCreatedWithDefaultConstructorNoElementsAdded_EmptyEqualsTrue();
        static void testVectorEmpty_AddOneElementToEmtyVector_EmptyEqualsFalse();
        static void testVectorReserve_CallReserveWithNParamGreaterThenVectorCapacity_ResutlVectorCapacityIsEqualToNParam();
        static void testVectorReserve_CallReserveWithNParamEqualToVectorCapacity_ResultVectorCapacityEqualsInitialCapacity();
        static void testVectorReserve_CallReserveWithNParamLessThenVectorCapacity_ResultVectorCapacityEqualsInitialCapacity();
        static void testVectorReverse_CallReserveWithNParamGreaterThenMaxSize_ExceptionIsThrown();
        static void testVectorIndexOperator_IterateOverZeroToVectorSizeMinusOneIndexAndCreateNewVectorFromObtainedElements_NewVectorIsEqualToInitialVector();
        static void testVectorIndexOperator_CreateTwoVectorsThatAreDifferentInFirstElementThenSetWithIndexOpFirstElementOfSecondToFirstElementOfFirst_TwoVectorsAreEqualInSizeAndElements();
        static void testVectorAtNonConstMethod_CallAtWithValueEqualOrGreaterThenVectorSize_ExceptionIsThrown();
        static void testVectorAtConstMethod_CallAtWithValueEqualOrGreaterThenVectorSize_ExceptionIsThrown();
        static void testVectorAtConstMethod_IterateOverZeroToVectorSizeMinusOneIndexAndCreateNewVectorFromObtainedElements_NewVectorIsEqualToInitialVector();
        static void testVectorAtNonConstMethod_CreateTwoVectorsThatAreDifferentInFirstElementThenSetWithAtMethodFirstElementOfSecondToCopyOfFirstElementOfFirstVector_TwoVectorsAreEqualInSizeAndElements();
        static void testVectorFrontMethod_CreateEmptyVectorAndPushBackFiveAndCallFront_ReturnedValueIsFive();
        static void testVectorBackMethod_CreateVectorWithThreeDifferentStringsAndCallBackMethd_ReturnedValueIsThirdAddedString();
        
        static void testVectorAssignRangeMethod_AssignSrcVectorToTargetVectorWhichIsInitiallyDifferentFromSrcVectorInElementsAndSize_SrcVectorEqualsTargetVectorInElementsAndSize();
        static void testVectorAssignRangeMethod_AssignSrcNonEmptyVectorToTargetEmptyVector_SrcVectorEqualsTargetVectorInElementsAndSize();
        static void testVectorAssignRangeMethod_AssignSrcEmptyVectorToTargetNonEmptyVector_SrcVectorEqualsTargetVectorInElementsAndSize();
        static void testVectorAssignRangeMethod_AssignSrcVectorThatHasSizeMoreThenTargetVectorCapacity_SrcVectorEqualsTargetVectorInElementsAndSizeAndTargetVectorCapacityIsGreaterThenInitialTargetVectorCapacity();
        static void testVectorAssignRangeMethod_AssignToTargetOfSizeFiveSrcOfSizeTwo_TargetOfSizeTwo();
        static void testVectorAssignRangeMethod_AssignToEmptyTargetSrcOfSizeTwo_TargetOfSizeTwo();
        static void testVectorAssignRangeMethod_AssignToTargetOfSizeFiveEmptySrc_EmptyTarget();

        static void testVectorAssignFillMethod_AssignFillTargetWithElementsDifferentFromTargetAndQtyIsLessThenTargetSize_TargetSizeIsEqualToQtyTargerElementsAreEqualToFillElements();
        static void testVectorAssignFillMethod_AssignFillFiveElementsToEmtpyTarget_TargetIsFilledWithFiveElements();
        static void testVectorAssignFillMethod_AssignFillZeroElementsToTargetWithSizeFive_TargetIsEmpty();

        static void testPopBack_PopBackOnVectorWithThreeElements_VectorWithTwoElemtsAndBackReturnsSecondElement();
        static void testPopBack_PopBackOnEmptyVector_DoesNothingMustNotCrash();
        static void testInsertSingleElement_InsertFiveIntoVectorOfOneTwoAndThreeWithIteratorPointingAtTwo_VectorOfOneFiveTwoAndThree();
        static void testInsertSingleElement_IsertFiveIntoVectorOfOneTwoThreeWithIteratorPointingToPastTheEndPosition_VectorOfOneTwoThreeFive();
        static void testInsertSingleElement_IsertFiveIntoVectorOfOneTwoThreeWithIteratorPointingToBeginPosition_VectorOfFiveOneTwoThree();
        static void testInsertSingleElement_InsertFiveIntoVectorOfOneTwoAndThreeWithIteratorPointingAtTwo_ReturnIteratorPointsAtElementInserted();
        static void testInsertSingleElement_InsertThreeIntoVectorOfOneTwoWithIteratorPoiningAtTwo_VectorOfOneThreeTwoWithSizeThreeAndCapacitySix();
        static void testInsertFill_InVectorOfOneTwoInsertThreeFivesBeforTwo_VectorOfOneFiveFiveFiveTwo();
        static void testInsertFill_InVectorOfSixElementInsertFiveElements_VectorCapacityIsEleven();
        static void testInsertRange_InVectorOfOneTwoInsertVectorOfThreeFourFiveWithIteratorPointingAtTwo_VectorOfOneThreeFourFiveTwoWithSizeFiveAndCapacityOfFive();
        static void testInsertRange_InVectorOfOneTwoInsertVectorOfFiveFiveWithIteratorPointingAtOne_vectorOfFiveFiveOneTwoWithSizeFourAndCapacityFour();
        static void testInsertRange_InVectorOfOneTwoInsertVectotOfFiveFiveWithIteratorPointingAtPastTheEndPosition_VectorOfFiveFiveOneTwoWithSizeFourAndCapacityFour();
        
        static void testEraseSingle_EraseTwoInVectorOfOneTwoThree_VectorOfOneThreeWithSizeTwo();
        static void testEraseSingle_EraseTheOnlyElementFromVectorOfOneElement_EmptyVector();
        static void testEraseSingle_EraseLastElement_VectorEqualToInitialVectorWithoutLastElement();
        static void testEraseSingle_EraseLastElement_ReturnedIteratorPoiningToPastTheEndElementOfContainer();
        static void testEraseRange_EraseTwoAndThreeFromVectorOfOneTwoThreeFour_VectorOfOneFour();
        static void testEraseRange_EraseAllElements_EmptyVectorReturnedIteratorPointsToPastTheEnd();

        static void testSwap_SwapNonEmptyVectors_ThisEqualsToCopyOfXMadeBeforSwapAndXIsEqualToCopyOfThisMadeBeforeSwap();

        static void testClear_CallClearOnVectorContainingSeveralElements_VectorWhichIsEmpty();
        static void testGlobalEqual_CompareTwoVectorsEqualInSizeAndElements_true();
        static void testGlobalEqualOp_CompareTwoEmptyVectors_true();
        static void testGlobalOp_ComparevectorsOfDifferentSize_false();
        
        static void testGlobalStrictlyLessOp_CompereOneTwoAnsOneTwoThree_true();
        static void testGlobalStrictLessOp_CompareOneTwoAndOneTwo_false();
        static void testGlobalStrictlyLessOp_CompareOneTwoThreeAndOneTwo_false();
    
};


#endif /* ************************************************ TemplateTestCase_H */