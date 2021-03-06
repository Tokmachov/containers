#include "VectorTestCase.hpp"

VectorTestCase::VectorTestCase() {}

VectorTestCase::VectorTestCase( const VectorTestCase & src ){ (void)src; }

VectorTestCase::~VectorTestCase() {}

VectorTestCase &VectorTestCase::operator=( VectorTestCase const & rhs )
{
	(void)rhs;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
//Configure init function so it fills allTests var properly with your test funcitons
//and funciton names
void VectorTestCase::initTests()
{
    TestNameAndFunc t1 = 
    { 
        "testPushBack_PushBackOneElementToEmptyVector_SizeIsOneCapacityIsOneElementAddedCanBeRetreivedWithIndexZero", 
        testPushBack_PushBackOneElementToEmptyVector_SizeIsOneCapacityIsOneElementAddedCanBeRetreivedWithIndexZero
    };
    VectorTestCase::allTests.push_back(t1);
    TestNameAndFunc t2 = 
    { 
        "testPushBack_PushBackTwoElementsToEmptyVEctor_SizeIsTwoCapacityIsTwoElementAddedLastIsAccessibleAtIndexOne", 
        testPushBack_PushBackTwoElementsToEmptyVEctor_SizeIsTwoCapacityIsTwoElementAddedLastIsAccessibleAtIndexOne
    };
    VectorTestCase::allTests.push_back(t2);
    TestNameAndFunc t3 = 
    { 
        "testPushBack_PushBackThreeElementsToEmptyVector_SizeIsThreeCapacityIsFourElementAddedLastIsAccessibleAtIndexTwo", 
        testPushBack_PushBackThreeElementsToEmptyVector_SizeIsThreeCapacityIsFourElementAddedLastIsAccessibleAtIndexTwo
    };
    VectorTestCase::allTests.push_back(t3);
	TestNameAndFunc t4 =
	{
		"testVectorIterator_VectorOfIntsIsPassedToRandomShuffleAlgorithm_RestltVectorIsOfSizeAsBeforeShuffleButElementsAreInDifferentOrder", 
		testVectorIterator_VectorOfIntsIsPassedToRandomShuffleAlgorithm_RestltVectorIsOfSizeAsBeforeShuffleButElementsAreInDifferentOrder
	};
	VectorTestCase::allTests.push_back(t4);
	    
    TestNameAndFunc t5 =
	{
		"testVectorIterator_SortVectorOfRandomIntsFromOneToFive_SortedVectorOfIntsFromOneTwoFive", 
		testVectorIterator_SortVectorOfRandomIntsFromOneToFive_SortedVectorOfIntsFromOneTwoFive
	};
    VectorTestCase::allTests.push_back(t5);


    TestNameAndFunc t6 =
	{
		"testVectorIterator_SortTenInts_SortedVectorOfInts", 
		testVectorIterator_SortTenInts_SortedVectorOfInts
	};
    
    VectorTestCase::allTests.push_back(t6);
	TestNameAndFunc t7 =
	{
		"testVectorIterator_SortTenIntsWithSortHeap_SortedVectorOfInts", 
		testVectorIterator_SortTenIntsWithSortHeap_SortedVectorOfInts
	};
	VectorTestCase::allTests.push_back(t7);
	TestNameAndFunc t8 =
	{
		"testVectorIteratorReverse_PlusPlusPrefix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues", 
		testVectorIteratorReverse_PlusPlusPrefix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues
	};
	VectorTestCase::allTests.push_back(t8);
	TestNameAndFunc t9 =
	{
		"testVectorIteratorReverse_CallPlusPlusPostfix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues", 
		testVectorIteratorReverse_CallPlusPlusPostfix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues
	};
	VectorTestCase::allTests.push_back(t9);
	TestNameAndFunc t10 =
	{
		"testVectorIteratorReverse_CallMinusMinusPostfix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues", 
		testVectorIteratorReverse_CallMinusMinusPostfix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues
	};
	VectorTestCase::allTests.push_back(t10);
	TestNameAndFunc t11 =
	{
		"testVectorIteratorReverse_CallMinusMinusPrefix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues", 
		testVectorIteratorReverse_CallMinusMinusPrefix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues
	};
	VectorTestCase::allTests.push_back(t11);
	TestNameAndFunc t12 =
	{
		"testVectorIteratorReverse_AddIteratorAndTwo_ProducesIteratorSimilarToStdIteratorUnderSameOperations", 
		testVectorIteratorReverse_AddIteratorAndTwo_ProducesIteratorSimilarToStdIteratorUnderSameOperations
	};
	VectorTestCase::allTests.push_back(t12);
	TestNameAndFunc t13 =
	{
		"testVectorIterator_OffsetPlusIterator_IteratorPointsToElementOffsetByOffsetValueForward", 
		testVectorIterator_OffsetPlusIterator_IteratorPointsToElementOffsetByOffsetValueForward
	};
	VectorTestCase::allTests.push_back(t13);
	TestNameAndFunc t14 =
	{
		"testVectorIteratorReverse_OnePlusIterator_IteratorPointingOnePositionCloserToVectorBeginning", 
		testVectorIteratorReverse_OnePlusIterator_IteratorPointingOnePositionCloserToVectorBeginning
	};
	VectorTestCase::allTests.push_back(t14);
	TestNameAndFunc t15 =
	{
		"testVectorIteratorReverse_IteratorMinusOne_IteratorPointingToElementOnePositionCloserToVectorsEnd", 
		testVectorIteratorReverse_IteratorMinusOne_IteratorPointingToElementOnePositionCloserToVectorsEnd
	};
	VectorTestCase::allTests.push_back(t15);
	TestNameAndFunc t16 =
	{
		"testVectorIteratorReverse_LeftIteratorMinusThreePositionsRighterIterator_PositiveThree", 
		testVectorIteratorReverse_LeftIteratorMinusThreePositionsRighterIterator_PositiveThree
	};
	VectorTestCase::allTests.push_back(t16);
	TestNameAndFunc t17 =
	{
		"testVectorIteratorReverse_RightIteratorMinusThreePositionsLefterIterator_NegativeThree", 
		testVectorIteratorReverse_RightIteratorMinusThreePositionsLefterIterator_NegativeThree
	};
	VectorTestCase::allTests.push_back(t17);
	TestNameAndFunc t18 =
	{
		"testVectotIteratorReversed_IterPositionedCloserToVectorBeginingIsGreaterThenIterPositionedCloserToEnd_true", 
		testVectotIteratorReversed_IterPositionedCloserToVectorBeginingIsGreaterThenIterPositionedCloserToEnd_true
	};
	VectorTestCase::allTests.push_back(t18);
	TestNameAndFunc t19 =
	{
		"testVectorIteratorRevered_IteratorPositionedCloserToVectorEndIsLessThenIteratorPositionCloserToVectorBeginning_true", 
		testVectorIteratorRevered_IteratorPositionedCloserToVectorEndIsLessThenIteratorPositionCloserToVectorBeginning_true
	};
	VectorTestCase::allTests.push_back(t19);
	TestNameAndFunc t20 =
	{
		"testVectorRend_CallRend_IteratorPointingAtElementBeforVectorTrueBeginning", 
		testVectorRend_CallRend_IteratorPointingAtElementBeforVectorTrueBeginning
	};
	VectorTestCase::allTests.push_back(t20);
	TestNameAndFunc t21 =
	{
		"testVectorReverseIter_AssignReverseIterToConstReverseIterVar_ReverseIteratorIsConvertedToConstReverseAndProgramDoesntCrash", 
		testVectorReverseIter_AssignReverseIterToConstReverseIterVar_ReverseIteratorIsConvertedToConstReverseAndProgramDoesntCrash
	};
	VectorTestCase::allTests.push_back(t21);
	TestNameAndFunc t22 =
	{
		"testVectorFillConstructor_FillConstructorWithParamsNEqualFiveAndValEqualTwo_VectorOfSizeFiveAndEachValueIsEqualToTwo", 
		testVectorFillConstructor_FillConstructorWithParamsNEqualFiveAndValEqualTwo_VectorOfSizeFiveAndEachValueIsEqualToTwo
	};
	VectorTestCase::allTests.push_back(t22);
	TestNameAndFunc t23 =
	{
		"testVectorFillConstructor_CallFillConstructorWithParamsNEqualZeroAndValEqualTwo_VectorOfSizeZero", 
		testVectorFillConstructor_CallFillConstructorWithParamsNEqualZeroAndValEqualTwo_VectorOfSizeZero
	};
	VectorTestCase::allTests.push_back(t23);
	TestNameAndFunc t24 =
	{
		"testVectorRangeConstructor_CallRangeConstructorWithIntsArrayFromOneToFiveStartAndEnd_VectorContainsElementsFromOneToFiveAndItsSizeIsFour", 
		testVectorRangeConstructor_CallRangeConstructorWithIntsArrayFromOneToFiveStartAndEnd_VectorContainsElementsFromOneToFiveAndItsSizeIsFour
	};
	VectorTestCase::allTests.push_back(t24);
	TestNameAndFunc t25 =
	{
		"testVectorCopyConstructor_ConstructVectorWithCopyConstructorFromAnotherVector_SrcVectorIsEqualInSizeAndElementsToResultVector", 
		testVectorCopyConstructor_ConstructVectorWithCopyConstructorFromAnotherVector_SrcVectorIsEqualInSizeAndElementsToResultVector
	};
	VectorTestCase::allTests.push_back(t25);
	TestNameAndFunc t26 =
	{
		"testVectorAssignment_AssignOneVectorWithMultipleElementsToAnotherVectorWithMultipleElemnts_SrcVectorAndResultVectorAreEqualInSizeAndElements", 
		testVectorAssignment_AssignOneVectorWithMultipleElementsToAnotherVectorWithMultipleElemnts_SrcVectorAndResultVectorAreEqualInSizeAndElements
	};
	VectorTestCase::allTests.push_back(t26);
	TestNameAndFunc t27 =
	{
		"testVectorSize_CreateVectorOfFiveIntsWithFillConstructor_SizeYieldsFive", 
		testVectorSize_CreateVectorOfFiveIntsWithFillConstructor_SizeYieldsFive
	};
	VectorTestCase::allTests.push_back(t27);
	TestNameAndFunc t28 =
	{
		"testVectoSize_AddOneELementToVectorOfFiveELement_SizeYieldsSix", 
		testVectoSize_AddOneELementToVectorOfFiveELement_SizeYieldsSix
	};
	VectorTestCase::allTests.push_back(t28);
	TestNameAndFunc t29 =
	{
		"testVectorResize_ResizeToParamNLessThenSize_SizeIsEqualToN", 
		testVectorResize_ResizeToParamNLessThenSize_SizeIsEqualToN
	};
	VectorTestCase::allTests.push_back(t29);
	TestNameAndFunc t30 =
	{
		"testVectorResize_ResizeToNThatIsGreaterByThreeThenSizeAndValueIsProvided_ResultVectorIsEqualInSizeAndElementsToVectorAsIfCreatedFromInitialVectorByPushingBackThreeTimesElementsEqualToValueParameterOfResize", 
		testVectorResize_ResizeToNThatIsGreaterByThreeThenSizeAndValueIsProvided_ResultVectorIsEqualInSizeAndElementsToVectorAsIfCreatedFromInitialVectorByPushingBackThreeTimesElementsEqualToValueParameterOfResize
	};
	VectorTestCase::allTests.push_back(t30);
	TestNameAndFunc t31 =
	{
		"testVectorResize_ResizeToNThatExceedsCapacity_ResultVectorMustBeEqualToInitialVectorAsIfItWasPushBackedWithValParamOfResizeNMinusSizeAndResultCapacityIsGreaterThenInitialCapacity", 
		testVectorResize_ResizeToNThatExceedsCapacity_ResultVectorMustBeEqualToInitialVectorAsIfItWasPushBackedWithValParamOfResizeNMinusSizeAndResultCapacityIsGreaterThenInitialCapacity
	};
	VectorTestCase::allTests.push_back(t31);
	TestNameAndFunc t32 =
	{
		"testVectorCapacity_AddElementToEmtyVector_CapacityIsTwo", 
		testVectorCapacity_AddElementToEmtyVector_CapacityIsTwo
	};
	VectorTestCase::allTests.push_back(t32);
	TestNameAndFunc t33 =
	{
		"testVectorCapacity_CreateEmptyVector_CapacityIsZero", 
		testVectorCapacity_CreateEmptyVector_CapacityIsZero
	};
	VectorTestCase::allTests.push_back(t33);
	TestNameAndFunc t34 =
	{
		"testVectorCapacity_VectorOfSizeOneAndCapcityTwoPushBackedWithTwoElements_CapcityIsInitialCapcityIncreaseByOneAndThenDoubled", 
		testVectorCapacity_VectorOfSizeOneAndCapcityTwoPushBackedWithTwoElements_CapcityIsInitialCapcityIncreaseByOneAndThenDoubled
	};
	VectorTestCase::allTests.push_back(t34);
	TestNameAndFunc t35 =
	{
		"testVectorEmpty_VectorCreatedWithDefaultConstructorNoElementsAdded_EmptyEqualsTrue", 
		testVectorEmpty_VectorCreatedWithDefaultConstructorNoElementsAdded_EmptyEqualsTrue
	};
	VectorTestCase::allTests.push_back(t35);
	TestNameAndFunc t36 =
	{
		"testVectorEmpty_AddOneElementToEmtyVector_EmptyEqualsFalse", 
		testVectorEmpty_AddOneElementToEmtyVector_EmptyEqualsFalse
	};
	VectorTestCase::allTests.push_back(t36);
	TestNameAndFunc t37 =
	{
		"testVectorReserve_CallReserveWithNParamGreaterThenVectorCapacity_ResutlVectorCapacityIsEqualToNParam", 
		testVectorReserve_CallReserveWithNParamGreaterThenVectorCapacity_ResutlVectorCapacityIsEqualToNParam
	};
	VectorTestCase::allTests.push_back(t37);
	TestNameAndFunc t38 =
	{
		"testVectorReserve_CallReserveWithNParamEqualToVectorCapacity_ResultVectorCapacityEqualsInitialCapacity", 
		testVectorReserve_CallReserveWithNParamEqualToVectorCapacity_ResultVectorCapacityEqualsInitialCapacity
	};
	VectorTestCase::allTests.push_back(t38);
	TestNameAndFunc t39 =
	{
		"testVectorReserve_CallReserveWithNParamLessThenVectorCapacity_ResultVectorCapacityEqualsInitialCapacity", 
		testVectorReserve_CallReserveWithNParamLessThenVectorCapacity_ResultVectorCapacityEqualsInitialCapacity
	};
	VectorTestCase::allTests.push_back(t39);
	TestNameAndFunc t40 =
	{
		"testVectorReverse_CallReserveWithNParamGreaterThenMaxSize_ExceptionIsThrown", 
		testVectorReverse_CallReserveWithNParamGreaterThenMaxSize_ExceptionIsThrown
	};
	VectorTestCase::allTests.push_back(t40);
	TestNameAndFunc t41 =
	{
		"testVectorIndexOperator_IterateOverZeroToVectorSizeMinusOneIndexAndCreateNewVectorFromObtainedElements_NewVectorIsEqualToInitialVector", 
		testVectorIndexOperator_IterateOverZeroToVectorSizeMinusOneIndexAndCreateNewVectorFromObtainedElements_NewVectorIsEqualToInitialVector
	};
	VectorTestCase::allTests.push_back(t41);
	TestNameAndFunc t42 =
	{
		"testVectorIndexOperator_CreateTwoVectorsThatAreDifferentInFirstElementThenSetWithIndexOpFirstElementOfSecondToFirstElementOfFirst_TwoVectorsAreEqualInSizeAndElements", 
		testVectorIndexOperator_CreateTwoVectorsThatAreDifferentInFirstElementThenSetWithIndexOpFirstElementOfSecondToFirstElementOfFirst_TwoVectorsAreEqualInSizeAndElements
	};
	VectorTestCase::allTests.push_back(t42);
	TestNameAndFunc t43 =
	{
		"testVectorAtNonConstMethod_CallAtWithValueEqualOrGreaterThenVectorSize_ExceptionIsThrown", 
		testVectorAtNonConstMethod_CallAtWithValueEqualOrGreaterThenVectorSize_ExceptionIsThrown
	};
	VectorTestCase::allTests.push_back(t43);
	TestNameAndFunc t44 =
	{
		"testVectorAtConstMethod_CallAtWithValueEqualOrGreaterThenVectorSize_ExceptionIsThrown", 
		testVectorAtConstMethod_CallAtWithValueEqualOrGreaterThenVectorSize_ExceptionIsThrown
	};
	VectorTestCase::allTests.push_back(t44);
	TestNameAndFunc t45 =
	{
		"testVectorAtConstMethod_IterateOverZeroToVectorSizeMinusOneIndexAndCreateNewVectorFromObtainedElements_NewVectorIsEqualToInitialVector", 
		testVectorAtConstMethod_IterateOverZeroToVectorSizeMinusOneIndexAndCreateNewVectorFromObtainedElements_NewVectorIsEqualToInitialVector
	};
	VectorTestCase::allTests.push_back(t45);
	TestNameAndFunc t46 =
	{
		"testVectorAtNonConstMethod_CreateTwoVectorsThatAreDifferentInFirstElementThenSetWithAtMethodFirstElementOfSecondToCopyOfFirstElementOfFirstVector_TwoVectorsAreEqualInSizeAndElements", 
		testVectorAtNonConstMethod_CreateTwoVectorsThatAreDifferentInFirstElementThenSetWithAtMethodFirstElementOfSecondToCopyOfFirstElementOfFirstVector_TwoVectorsAreEqualInSizeAndElements
	};
	VectorTestCase::allTests.push_back(t46);
	TestNameAndFunc t47 =
	{
		"testVectorFrontMethod_CreateEmptyVectorAndPushBackFiveAndCallFront_ReturnedValueIsFive", 
		testVectorFrontMethod_CreateEmptyVectorAndPushBackFiveAndCallFront_ReturnedValueIsFive
	};
	VectorTestCase::allTests.push_back(t47);
	TestNameAndFunc t48 =
	{
		"testVectorBackMethod_CreateVectorWithThreeDifferentStringsAndCallBackMethd_ReturnedValueIsThirdAddedString", 
		testVectorBackMethod_CreateVectorWithThreeDifferentStringsAndCallBackMethd_ReturnedValueIsThirdAddedString
	};
	VectorTestCase::allTests.push_back(t48);
	TestNameAndFunc t49 =
	{
		"testVectorAssignRangeMethod_AssignSrcVectorToTargetVectorWhichIsInitiallyDifferentFromSrcVectorInElementsAndSize_SrcVectorEqualsTargetVectorInElementsAndSize", 
		testVectorAssignRangeMethod_AssignSrcVectorToTargetVectorWhichIsInitiallyDifferentFromSrcVectorInElementsAndSize_SrcVectorEqualsTargetVectorInElementsAndSize
	};
	VectorTestCase::allTests.push_back(t49);
	TestNameAndFunc t50 =
	{
		"testVectorAssignRangeMethod_AssignSrcNonEmptyVectorToTargetEmptyVector_SrcVectorEqualsTargetVectorInElementsAndSize", 
		testVectorAssignRangeMethod_AssignSrcNonEmptyVectorToTargetEmptyVector_SrcVectorEqualsTargetVectorInElementsAndSize
	};
	VectorTestCase::allTests.push_back(t50);
	TestNameAndFunc t51 =
	{
		"testVectorAssignRangeMethod_AssignSrcEmptyVectorToTargetNonEmptyVector_SrcVectorEqualsTargetVectorInElementsAndSize", 
		testVectorAssignRangeMethod_AssignSrcEmptyVectorToTargetNonEmptyVector_SrcVectorEqualsTargetVectorInElementsAndSize
	};
	VectorTestCase::allTests.push_back(t51);
	TestNameAndFunc t52 =
	{
		"testVectorAssignRangeMethod_AssignSrcVectorThatHasSizeMoreThenTargetVectorCapacity_SrcVectorEqualsTargetVectorInElementsAndSizeAndTargetVectorCapacityIsGreaterThenInitialTargetVectorCapacity", 
		testVectorAssignRangeMethod_AssignSrcVectorThatHasSizeMoreThenTargetVectorCapacity_SrcVectorEqualsTargetVectorInElementsAndSizeAndTargetVectorCapacityIsGreaterThenInitialTargetVectorCapacity
	};
	VectorTestCase::allTests.push_back(t52);
	TestNameAndFunc t53 =
	{
		"testVectorAssignRangeMethod_AssignToTargetOfSizeFiveSrcOfSizeTwo_TargetOfSizeTwo", 
		testVectorAssignRangeMethod_AssignToTargetOfSizeFiveSrcOfSizeTwo_TargetOfSizeTwo
	};
	VectorTestCase::allTests.push_back(t53);
	TestNameAndFunc t54 =
	{
		"testVectorAssignRangeMethod_AssignToEmptyTargetSrcOfSizeTwo_TargetOfSizeTwo", 
		testVectorAssignRangeMethod_AssignToEmptyTargetSrcOfSizeTwo_TargetOfSizeTwo
	};
	VectorTestCase::allTests.push_back(t54);
	TestNameAndFunc t55 =
	{
		"testVectorAssignRangeMethod_AssignToTargetOfSizeFiveEmptySrc_EmptyTarget", 
		testVectorAssignRangeMethod_AssignToTargetOfSizeFiveEmptySrc_EmptyTarget
	};
	VectorTestCase::allTests.push_back(t55);
	TestNameAndFunc t56 =
	{
		"testVectorAssignFillMethod_AssignFillTargetWithElementsDifferentFromTargetAndQtyIsLessThenTargetSize_TargetSizeIsEqualToQtyTargerElementsAreEqualToFillElements", 
		testVectorAssignFillMethod_AssignFillTargetWithElementsDifferentFromTargetAndQtyIsLessThenTargetSize_TargetSizeIsEqualToQtyTargerElementsAreEqualToFillElements
	};
	VectorTestCase::allTests.push_back(t56);
	TestNameAndFunc t57 =
	{
		"testVectorAssignFillMethod_AssignFillFiveElementsToEmtpyTarget_TargetIsFilledWithFiveElements", 
		testVectorAssignFillMethod_AssignFillFiveElementsToEmtpyTarget_TargetIsFilledWithFiveElements
	};
	VectorTestCase::allTests.push_back(t57);
	TestNameAndFunc t58 =
	{
		"testVectorAssignFillMethod_AssignFillZeroElementsToTargetWithSizeFive_TargetIsEmpty", 
		testVectorAssignFillMethod_AssignFillZeroElementsToTargetWithSizeFive_TargetIsEmpty
	};
	VectorTestCase::allTests.push_back(t58);
	TestNameAndFunc t59 =
	{
		"testPopBack_PopBackOnVectorWithThreeElements_VectorWithTwoElemtsAndBackReturnsSecondElement", 
		testPopBack_PopBackOnVectorWithThreeElements_VectorWithTwoElemtsAndBackReturnsSecondElement
	};
	VectorTestCase::allTests.push_back(t59);
	TestNameAndFunc t60 =
	{
		"testPopBack_PopBackOnEmptyVector_DoesNothingMustNotCrash", 
		testPopBack_PopBackOnEmptyVector_DoesNothingMustNotCrash
	};
	VectorTestCase::allTests.push_back(t60);
	TestNameAndFunc t61 =
	{
		"testInsertSingleElement_InsertFiveIntoVectorOfOneTwoAndThreeWithIteratorPointingAtTwo_VectorOfOneFiveTwoAndThree", 
		testInsertSingleElement_InsertFiveIntoVectorOfOneTwoAndThreeWithIteratorPointingAtTwo_VectorOfOneFiveTwoAndThree
	};
	VectorTestCase::allTests.push_back(t61);
	TestNameAndFunc t62 =
	{
		"testInsertSingleElement_IsertFiveIntoVectorOfOneTwoThreeWithIteratorPointingToPastTheEndPosition_VectorOfOneTwoThreeFive", 
		testInsertSingleElement_IsertFiveIntoVectorOfOneTwoThreeWithIteratorPointingToPastTheEndPosition_VectorOfOneTwoThreeFive
	};
	VectorTestCase::allTests.push_back(t62);
	TestNameAndFunc t63 =
	{
		"testInsertSingleElement_IsertFiveIntoVectorOfOneTwoThreeWithIteratorPointingToBeginPosition_VectorOfFiveOneTwoThree", 
		testInsertSingleElement_IsertFiveIntoVectorOfOneTwoThreeWithIteratorPointingToBeginPosition_VectorOfFiveOneTwoThree
	};
	VectorTestCase::allTests.push_back(t63);
	TestNameAndFunc t64 =
	{
		"testInsertSingleElement_InsertFiveIntoVectorOfOneTwoAndThreeWithIteratorPointingAtTwo_ReturnIteratorPointsAtElementInserted", 
		testInsertSingleElement_InsertFiveIntoVectorOfOneTwoAndThreeWithIteratorPointingAtTwo_ReturnIteratorPointsAtElementInserted
	};
	VectorTestCase::allTests.push_back(t64);
	TestNameAndFunc t65 =
	{
		"testInsertSingleElement_InsertThreeIntoVectorOfOneTwoWithIteratorPoiningAtTwo_VectorOfOneFiveTwoWithSizeThreeAndCapacitySix", 
		testInsertSingleElement_InsertThreeIntoVectorOfOneTwoWithIteratorPoiningAtTwo_VectorOfOneThreeTwoWithSizeThreeAndCapacitySix
	};
	VectorTestCase::allTests.push_back(t65);
	TestNameAndFunc t66 =
	{
		"testInsertFill_InVectorOfOneTwoInsertThreeFivesBeforTwo_VectorOfOneFiveFiveFiveTwo", 
		testInsertFill_InVectorOfOneTwoInsertThreeFivesBeforTwo_VectorOfOneFiveFiveFiveTwo
	};
	VectorTestCase::allTests.push_back(t66);
	TestNameAndFunc t67 =
	{
		"testInsertFill_InVectorOfSixElementInsertFiveElements_VectorCapacityIsEleven", 
		testInsertFill_InVectorOfSixElementInsertFiveElements_VectorCapacityIsEleven
	};
	VectorTestCase::allTests.push_back(t67);
	TestNameAndFunc t68 =
	{
		"testInsertRange_InVectorOfOneTwoInsertVectorOfThreeFourFiveWithIteratorPointingAtTwo_VectorOfOneThreeFourFiveTwoWithSizeFiveAndCapacityOfFive", 
		testInsertRange_InVectorOfOneTwoInsertVectorOfThreeFourFiveWithIteratorPointingAtTwo_VectorOfOneThreeFourFiveTwoWithSizeFiveAndCapacityOfFive
	};
	VectorTestCase::allTests.push_back(t68);
	TestNameAndFunc t69 =
	{
		"testInsertRange_InVectorOfOneTwoInsertVectorOfFiveFiveWithIteratorPointingAtOne_vectorOfFiveFiveOneTwoWithSizeFourAndCapacityFour", 
		testInsertRange_InVectorOfOneTwoInsertVectorOfFiveFiveWithIteratorPointingAtOne_vectorOfFiveFiveOneTwoWithSizeFourAndCapacityFour
	};
	VectorTestCase::allTests.push_back(t69);
	TestNameAndFunc t70 =
	{
		"testInsertRange_InVectorOfOneTwoInsertVectotOfFiveFiveWithIteratorPointingAtPastTheEndPosition_VectorOfFiveFiveOneTwoWithSizeFourAndCapacityFour", 
		testInsertRange_InVectorOfOneTwoInsertVectotOfFiveFiveWithIteratorPointingAtPastTheEndPosition_VectorOfFiveFiveOneTwoWithSizeFourAndCapacityFour
	};
	VectorTestCase::allTests.push_back(t70);
	TestNameAndFunc t71 =
	{
		"testEraseSingle_EraseTwoInVectorOfOneTwoThree_VectorOfOneThreeWithSizeTwo", 
		testEraseSingle_EraseTwoInVectorOfOneTwoThree_VectorOfOneThreeWithSizeTwo
	};
	VectorTestCase::allTests.push_back(t71);
	TestNameAndFunc t72 =
	{
		"testEraseSingle_EraseTheOnlyElementFromVectorOfOneElement_EmptyVector", 
		testEraseSingle_EraseTheOnlyElementFromVectorOfOneElement_EmptyVector
	};
	VectorTestCase::allTests.push_back(t72);
	TestNameAndFunc t73 =
	{
		"testEraseSingle_EraseLastElement_VectorEqualToInitialVectorWithoutLastElement", 
		testEraseSingle_EraseLastElement_VectorEqualToInitialVectorWithoutLastElement
	};
	VectorTestCase::allTests.push_back(t73);
	TestNameAndFunc t74 =
	{
		"testEraseSingle_EraseLastElement_ReturnedIteratorPoiningToPastTheEndElementOfContainer", 
		testEraseSingle_EraseLastElement_ReturnedIteratorPoiningToPastTheEndElementOfContainer
	};
	VectorTestCase::allTests.push_back(t74);
	TestNameAndFunc t75 =
	{
		"testEraseRange_EraseTwoAndThreeFromVectorOfOneTwoThreeFour_VectorOfOneFour", 
		testEraseRange_EraseTwoAndThreeFromVectorOfOneTwoThreeFour_VectorOfOneFour
	};
	VectorTestCase::allTests.push_back(t75);
	TestNameAndFunc t76 =
	{
		"testEraseRange_EraseAllElements_EmptyVectorReturnedIteratorPointsToPastTheEnd", 
		testEraseRange_EraseAllElements_EmptyVectorReturnedIteratorPointsToPastTheEnd
	};
	VectorTestCase::allTests.push_back(t76);
	TestNameAndFunc t77 =
	{
		"testSwap_SwapNonEmptyVectors_ThisEqualsToCopyOfXMadeBeforSwapAndXIsEqualToCopyOfThisMadeBeforeSwap", 
		testSwap_SwapNonEmptyVectors_ThisEqualsToCopyOfXMadeBeforSwapAndXIsEqualToCopyOfThisMadeBeforeSwap
	};
	VectorTestCase::allTests.push_back(t77);
	TestNameAndFunc t78 =
	{
		"testClear_CallClearOnVectorContainingSeveralElements_VectorWhichIsEmpty", 
		testClear_CallClearOnVectorContainingSeveralElements_VectorWhichIsEmpty
	};
	VectorTestCase::allTests.push_back(t78);
	TestNameAndFunc t79 =
	{
		"testGlobalEqual_CompareTwoVectorsEqualInSizeAndElements_true", 
		testGlobalEqual_CompareTwoVectorsEqualInSizeAndElements_true
	};
	VectorTestCase::allTests.push_back(t79);
	TestNameAndFunc t80 =
	{
		"testGlobalEqualOp_CompareTwoEmptyVectors_true", 
		testGlobalEqualOp_CompareTwoEmptyVectors_true
	};
	VectorTestCase::allTests.push_back(t80);
	TestNameAndFunc t81 =
	{
		"testGlobalOp_ComparevectorsOfDifferentSize_false", 
		testGlobalOp_ComparevectorsOfDifferentSize_false
	};
	VectorTestCase::allTests.push_back(t81);
	TestNameAndFunc t82 =
	{
		"testGlobalStrictlyLessOp_CompereOneTwoAnsOneTwoThree_true", 
		testGlobalStrictlyLessOp_CompereOneTwoAnsOneTwoThree_true
	};
	VectorTestCase::allTests.push_back(t82);
	TestNameAndFunc t83 =
	{
		"testGlobalStrictLessOp_CompareOneTwoAndOneTwo_false", 
		testGlobalStrictLessOp_CompareOneTwoAndOneTwo_false
	};
	VectorTestCase::allTests.push_back(t83);
	TestNameAndFunc t84 =
	{
		"testGlobalStrictlyLessOp_CompareOneTwoThreeAndOneTwo_false", 
		testGlobalStrictlyLessOp_CompareOneTwoThreeAndOneTwo_false
	};
	VectorTestCase::allTests.push_back(t84);
}

void VectorTestCase::run()
{   
    allTests.clear();
    initTests();
    printTestName("Vector");
    runAllTests();
    runLeaks();
}

/*
** --------------------------------- TEST_FUNCTIONS ----------------------------
*/
//write here definitions of test functions
//after fucnction proves to work correctly, change "CONSTRUCTION" to "DONE"
//RED
void VectorTestCase::testPushBack_PushBackOneElementToEmptyVector_SizeIsOneCapacityIsOneElementAddedCanBeRetreivedWithIndexZero()
{
    //Arrange
    ft::vector<int> actual;
    //Act
    actual.push_back(1);
    //Assert
    assertTrue(actual[0] == 1);
    assertTrue(actual.capacity() == 2);
    assertTrue(actual.size() == 1);
}
void VectorTestCase::testPushBack_PushBackTwoElementsToEmptyVEctor_SizeIsTwoCapacityIsTwoElementAddedLastIsAccessibleAtIndexOne()
{
    //Arrange
    ft::vector<int> actual;
    //Act
    actual.push_back(1);
    actual.push_back(2);
    //Assert
    assertTrue(actual.capacity() == 2);
    assertTrue(actual.size() == 2);
    assertTrue(actual[1] == 2);
}
void VectorTestCase::testPushBack_PushBackThreeElementsToEmptyVector_SizeIsThreeCapacityIsFourElementAddedLastIsAccessibleAtIndexTwo()
{
    //Arrange
    ft::vector<int> actual;
    //Act
    actual.push_back(1);
    actual.push_back(2);
    actual.push_back(3);
    //Assert
    assertTrue(actual.size() == 3);
    assertTrue(actual.capacity() == 6);
    assertTrue(actual[2] == 3);
}
void VectorTestCase::testVectorIterator_VectorOfIntsIsPassedToRandomShuffleAlgorithm_RestltVectorIsOfSizeAsBeforeShuffleButElementsAreInDifferentOrder()
{
	//Arrange
    ft::vector<int> actual;
    actual.push_back(1);
	actual.push_back(2);
    actual.push_back(3);
    actual.push_back(4);
    actual.push_back(5);
    ft::vector<int> actual_copy;
    actual_copy.push_back(1);
	actual_copy.push_back(2);
    actual_copy.push_back(3);
    actual_copy.push_back(4);
    actual_copy.push_back(5);
    //Act
    std::random_shuffle(actual.begin(), actual.end());
	//Assert
	// assertTrue();
	// assertFalse();
	for (ft::vector<int>::iterator it = actual.begin(); it < actual.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;
    assertEqual(actual.size(), actual_copy.size());
    bool elementsCompareResult = std::equal(actual.begin(), actual.end(), actual_copy.begin());
    assertFalse(elementsCompareResult);
}
void VectorTestCase::testVectorIterator_SortVectorOfRandomIntsFromOneToFive_SortedVectorOfIntsFromOneTwoFive()
{
	//Arrange
    
    ft::vector<int> actual;
	actual.push_back(2);
    actual.push_back(3);
    actual.push_back(5);
    actual.push_back(1);
    actual.push_back(4);
    ft::vector<int> expected;
    expected.push_back(1);
	expected.push_back(2);
    expected.push_back(3);
    expected.push_back(4);
    expected.push_back(5);
	//Act
    std::sort(actual.begin(), actual.end());
    //Assert
	assertTrue(areEqualInSizeAndElements(actual.begin(), actual.end(), expected.begin(), expected.end()));
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorIterator_SortTenInts_SortedVectorOfInts()
{
	//Arrange
    ft::vector<int> actual;
    actual.push_back(9);
	actual.push_back(2);
    actual.push_back(3);
    actual.push_back(5);
    actual.push_back(1);
    actual.push_back(6);
    actual.push_back(7);
    actual.push_back(4);
    actual.push_back(8);
    ft::vector<int> expected;
    expected.push_back(1);
	expected.push_back(2);
    expected.push_back(3);
    expected.push_back(4);
    expected.push_back(5);
	expected.push_back(6);
    expected.push_back(7);
    expected.push_back(8);
    expected.push_back(9);
    //Act
    std::sort(actual.begin(), actual.end());
    //Assert
	assertTrue(areEqualInSizeAndElements(actual.begin(), actual.end(), expected.begin(), expected.end()));
}
void VectorTestCase::testVectorIterator_SortTenIntsWithSortHeap_SortedVectorOfInts()
{
	//Arrange
    ft::vector<int> actual;
	actual.push_back(2);
    actual.push_back(4);
    actual.push_back(3);
    actual.push_back(6);
    actual.push_back(5);
    actual.push_back(8);
    actual.push_back(7);
    actual.push_back(9);
    actual.push_back(1);
    std::make_heap(actual.begin(), actual.end());
    ft::vector<int> expected;
    expected.push_back(1);
	expected.push_back(2);
    expected.push_back(3);
    expected.push_back(4);
    expected.push_back(5);
	expected.push_back(6);
    expected.push_back(7);
    expected.push_back(8);
    expected.push_back(9);
    //Act
    std::sort_heap(actual.begin(), actual.end());
    for (ft::vector<int>::iterator it = actual.begin(); it < actual.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;
    //Assert
	assertTrue(areEqualInSizeAndElements(actual.begin(), actual.end(), expected.begin(), expected.end()));
}
void VectorTestCase::testVectorIteratorReverse_PlusPlusPrefix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues()
{
	//Arrange
    ft::vector<int> actual;
    actual.push_back(1);
	actual.push_back(2);
    actual.push_back(3);
    ft::vector<int>::reverse_iterator itFtReverse = actual.rbegin();
    
    std::vector<int> expected;
    expected.push_back(1);
	expected.push_back(2);
    expected.push_back(3);
    std::vector<int>::reverse_iterator itStdReverse = expected.rbegin();
    //Act
    ft::vector<int>::reverse_iterator itFtReceived = ++itFtReverse;
    std::vector<int>::reverse_iterator itStdReceived = ++itStdReverse;

    assertEqual(*itFtReceived, *itStdReceived);
    assertEqual(*itFtReverse, *itStdReverse);
}
void VectorTestCase::testVectorIteratorReverse_CallPlusPlusPostfix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues()
{
	//Arrange
    ft::vector<int> actual;
    actual.push_back(1);
	actual.push_back(2);
    actual.push_back(3);
    ft::vector<int>::reverse_iterator itFtReverse = actual.rbegin();
    
    std::vector<int> expected;
    expected.push_back(1);
	expected.push_back(2);
    expected.push_back(3);
    std::vector<int>::reverse_iterator itStdReverse = expected.rbegin();
    //Act
    ft::vector<int>::reverse_iterator itFtReceived = itFtReverse++;
    std::vector<int>::reverse_iterator itStdReceived = itStdReverse++;

    assertEqual(*itFtReceived, *itStdReceived);
    assertEqual(*itFtReverse, *itStdReverse);
}
void VectorTestCase::testVectorIteratorReverse_CallMinusMinusPostfix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues()
{
	//Arrange
    ft::vector<int> ftVector;
    ftVector.push_back(1);
	ftVector.push_back(2);
    ftVector.push_back(3);
    ft::vector<int>::reverse_iterator itFtReverse = ftVector.rbegin();
    
    std::vector<int> stdVector;
    stdVector.push_back(1);
	stdVector.push_back(2);
    stdVector.push_back(3);
    std::vector<int>::reverse_iterator itStdReverse = stdVector.rbegin();
    //Act
    itFtReverse++;
    itFtReverse++;
    itStdReverse++;
    itStdReverse++;
    ft::vector<int>::reverse_iterator itFtReceived = itFtReverse--;
    std::vector<int>::reverse_iterator itStdReceived = itStdReverse--;

    assertEqual(*itFtReceived, *itStdReceived);
    assertEqual(*itFtReverse, *itStdReverse);
}
void VectorTestCase::testVectorIteratorReverse_CallMinusMinusPrefix_ReturnsAndChangesIteratorSimilarlyToStdIteratorWithTheSameValues()
{
	//Arrange
    ft::vector<int> ftVector;
    ftVector.push_back(1);
	ftVector.push_back(2);
    ftVector.push_back(3);
    ft::vector<int>::reverse_iterator itFtReverse = ftVector.rbegin();
    
    std::vector<int> stdVector;
    stdVector.push_back(1);
	stdVector.push_back(2);
    stdVector.push_back(3);
    std::vector<int>::reverse_iterator itStdReverse = stdVector.rbegin();
    //Act
    itFtReverse++;
    itStdReverse++;
    ft::vector<int>::reverse_iterator itFtReceived = --itFtReverse;
    std::vector<int>::reverse_iterator itStdReceived = --itStdReverse;

    assertEqual(*itFtReceived, *itStdReceived);
    assertEqual(*itFtReverse, *itStdReverse);
}
void VectorTestCase::testVectorIteratorReverse_AddIteratorAndTwo_ProducesIteratorSimilarToStdIteratorUnderSameOperations()
{
	//Arrange
    ft::vector<int> ftVector;
    ftVector.push_back(1);
	ftVector.push_back(2);
    ftVector.push_back(3);
    ft::vector<int>::reverse_iterator itFtReverse = ftVector.rbegin();
    
    std::vector<int> stdVector;
    stdVector.push_back(1);
	stdVector.push_back(2);
    stdVector.push_back(3);
    std::vector<int>::reverse_iterator itStdReverse = stdVector.rbegin();
    //Act
    size_t n = 1;
    ft::vector<int>::reverse_iterator itFtReceived = itFtReverse + n;
    std::vector<int>::reverse_iterator itStdReceived = itStdReverse + n;

    assertEqual(*itFtReceived, *itStdReceived);
}
void VectorTestCase::testVectorIterator_OffsetPlusIterator_IteratorPointsToElementOffsetByOffsetValueForward()
{
	//Arrange
    ft::vector<int> vec;
    vec.push_back(1);
	vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    ft::vector<int>::iterator it = vec.begin();
	//Act
    size_t n = 3;
    it = n + it;
    //Assert
    assertTrue(*it == 4);
}
void VectorTestCase::testVectorIteratorReverse_OnePlusIterator_IteratorPointingOnePositionCloserToVectorBeginning()
{
	//Arrange
    ft::vector<int> vec;
    vec.push_back(1);
	vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    ft::vector<int>::reverse_iterator it = vec.rbegin();
	//Act
    size_t n = 1;
    it = n + it;
    //Assert
    assertTrue(*it == 4);
}
void VectorTestCase::testVectorIteratorReverse_IteratorMinusOne_IteratorPointingToElementOnePositionCloserToVectorsEnd()
{
	//Arrange
    ft::vector<int> vec;
    vec.push_back(1);
	vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    ft::vector<int>::reverse_iterator it = vec.rbegin();
	//Act
    it++;
    size_t n = 1;
    it = it - n;
    //Assert
    assertTrue(*it == 5);
}

void VectorTestCase::testVectorIteratorReverse_LeftIteratorMinusThreePositionsRighterIterator_PositiveThree()
{
	//Arrange
    ft::vector<int> vec;
    vec.push_back(1);
	vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    ft::vector<int>::reverse_iterator leftIt = vec.rbegin();
	leftIt++;
    leftIt++;
    leftIt++;
    ft::vector<int>::reverse_iterator rightIt = vec.rbegin();
    //Act
    int result = leftIt - rightIt;
    //Assert
    assertTrue(result == 3);
}
void VectorTestCase::testVectorIteratorReverse_RightIteratorMinusThreePositionsLefterIterator_NegativeThree()
{
	//Arrange
    ft::vector<int> vec;
    vec.push_back(1);
	vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    ft::vector<int>::reverse_iterator leftIt = vec.rbegin();
	leftIt++;
    leftIt++;
    leftIt++;
    ft::vector<int>::reverse_iterator rightIt = vec.rbegin();
    //Act
    int result = rightIt - leftIt;
    //Assert
    assertTrue(result == -3);
}
void VectorTestCase::testVectotIteratorReversed_IterPositionedCloserToVectorBeginingIsGreaterThenIterPositionedCloserToEnd_true()
{
	//Arrange
    ft::vector<int> vec;
    vec.push_back(1);
	vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    ft::vector<int>::reverse_iterator leftIt = vec.rbegin();
	leftIt++;
    leftIt++;
    leftIt++;
    ft::vector<int>::reverse_iterator rightIt = vec.rbegin();
    //Act
    
    //Assert
    assertTrue(rightIt < leftIt);
}
void VectorTestCase::testVectorIteratorRevered_IteratorPositionedCloserToVectorEndIsLessThenIteratorPositionCloserToVectorBeginning_true()
{
	//Arrange
    ft::vector<int> vec;
    vec.push_back(1);
	vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    ft::vector<int>::reverse_iterator leftIt = vec.rbegin();
	leftIt++;
    leftIt++;
    leftIt++;
    ft::vector<int>::reverse_iterator rightIt = vec.rbegin();
    //Act
    
    //Assert
    assertTrue(leftIt > rightIt);
}
void VectorTestCase::testVectorRend_CallRend_IteratorPointingAtElementBeforVectorTrueBeginning()
{
	//Arrange
    ft::vector<int> vec;
    vec.push_back(1);
	vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    //Act
    ft::vector<int>::reverse_iterator itRend = vec.rend();
    ft::vector<int>::iterator itBeforBeginning = vec.begin();
    itBeforBeginning--;    
    //Assert
    assertTrue(&(*itRend) == &(*itBeforBeginning));
}
void VectorTestCase::testVectorReverseIter_AssignReverseIterToConstReverseIterVar_ReverseIteratorIsConvertedToConstReverseAndProgramDoesntCrash()
{
	//Arrange
    ft::vector<int> vec;
    vec.push_back(1);
	vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    //Act
    ft::vector<int>::reverse_iterator nonConstReverseIter = vec.rbegin();
    ft::vector<int>::const_reverse_iterator constReverseIter = nonConstReverseIter;
    (void)constReverseIter;
    //Assert
    assertTrue(true);
}
void VectorTestCase::testVectorFillConstructor_FillConstructorWithParamsNEqualFiveAndValEqualTwo_VectorOfSizeFiveAndEachValueIsEqualToTwo()
{
	//Arrange
    size_t n = 5;
    int val = 2;
    
    //Act
    ft::vector<int> vec(n, val);

    //Assert
    bool areAllElementsEqualVal = true;
    for (ft::vector<int>::const_iterator it = vec.begin(); it < vec.end(); it++)
    {
        if (*it != val)
            areAllElementsEqualVal = false;
    }
    //Assert
    assertTrue(vec.size() == n);
    assertTrue(areAllElementsEqualVal);
}
void VectorTestCase::testVectorFillConstructor_CallFillConstructorWithParamsNEqualZeroAndValEqualTwo_VectorOfSizeZero()
{
	//Arrange
    size_t n = 0;
    int val = 2;
    
    //Act
    ft::vector<int> vec(n, val);

    //Assert
    bool areAllElementsEqualVal = true;
    for (ft::vector<int>::const_iterator it = vec.begin(); it < vec.end(); it++)
    {
        if (*it != val)
            areAllElementsEqualVal = false;
    }
    //Assert
    assertTrue(vec.size() == n);
    assertTrue(areAllElementsEqualVal);
}
void VectorTestCase::testVectorRangeConstructor_CallRangeConstructorWithIntsArrayFromOneToFiveStartAndEnd_VectorContainsElementsFromOneToFiveAndItsSizeIsFour()
{
	//Arrange
    int arr[] = {1, 2, 3, 4, 5};

    //Act
    ft::vector<int> vec(arr, arr + 5);
    
    //Assert
    assertTrue(areEqualInSizeAndElements(vec.begin(), vec.end(), arr, arr + 5));
}
void VectorTestCase::testVectorCopyConstructor_ConstructVectorWithCopyConstructorFromAnotherVector_SrcVectorIsEqualInSizeAndElementsToResultVector()
{
	//Arrange
    int arr[] = {1, 2, 3, 4, 5};
    ft::vector<int> srcVector(arr, arr + 5);

    //Act
    ft::vector<int> resultVector(srcVector);
    //Assert
    assertTrue(areEqualInSizeAndElements(srcVector.begin(), srcVector.end(), resultVector.begin(), resultVector.end()));
}
void VectorTestCase::testVectorAssignment_AssignOneVectorWithMultipleElementsToAnotherVectorWithMultipleElemnts_SrcVectorAndResultVectorAreEqualInSizeAndElements()
{
	//Arrange
    int arr[] = {1, 2, 3, 4, 5};
    ft::vector<int> srcVector(arr, arr + 5);
    
    ft::vector<int> resultVector;
    resultVector.push_back(1);
    resultVector.push_back(1);
    //Act
    resultVector = srcVector;
    //Assert
    assertTrue(areEqualInSizeAndElements(srcVector.begin(), srcVector.end(), resultVector.begin(), resultVector.end()));
}
void VectorTestCase::testVectorSize_CreateVectorOfFiveIntsWithFillConstructor_SizeYieldsFive()
{
	//Arrange
    size_t n = 5;
    int val = 2;
    
    //Act
    ft::vector<int> vec(n, val);
    ft::vector<int>::size_type size = vec.size();
    
    //Assert
    assertTrue(size == n);
}
void VectorTestCase::testVectoSize_AddOneELementToVectorOfFiveELement_SizeYieldsSix()
{
	//Arrange
    size_t n = 5;
    int val = 2;
    ft::vector<int> vec(n, val);
    vec.push_back(22);
    
    //Act
    ft::vector<int>::size_type size = vec.size();
    
    //Assert
    assertTrue(size == 6);
}
void VectorTestCase::testVectorResize_ResizeToParamNLessThenSize_SizeIsEqualToN()
{
	//Arrange
    ft::vector<int> vec(10, 5);
    
    //Act
    size_t n = 3;
    vec.resize(n);
    
    //Assert
    assertTrue(vec.size() == n);
}
void VectorTestCase::testVectorResize_ResizeToNThatIsGreaterByThreeThenSizeAndValueIsProvided_ResultVectorIsEqualInSizeAndElementsToVectorAsIfCreatedFromInitialVectorByPushingBackThreeTimesElementsEqualToValueParameterOfResize()
{
	//Arrange
    int val = 111;
    ft::vector<int> actual(3, 5);
    ft::vector<int> expected(3, 5);
    expected.push_back(val);
    expected.push_back(val);
    expected.push_back(val);
    //Act
    size_t n = 6;
    actual.resize(n, val);
    
    //Assert
    assertTrue(areEqualInSizeAndElements(actual.begin(), actual.end(), expected.begin(), expected.end()));
}
void VectorTestCase::testVectorResize_ResizeToNThatExceedsCapacity_ResultVectorMustBeEqualToInitialVectorAsIfItWasPushBackedWithValParamOfResizeNMinusSizeAndResultCapacityIsGreaterThenInitialCapacity()
{
	//Arrange
    int resizeVal = 111;
    ft::vector<int> actual(10, 5);
    ft::vector<int>::size_type prevCapacity = actual.capacity();
    int resizeN = actual.capacity() + 1;
    ft::vector<int> expected = actual;
    for (size_t i = 0; i < (resizeN - actual.size()); i++)
        expected.push_back(resizeVal);
    //Act
    actual.resize(resizeN, resizeVal);
    
    //Assert
    assertTrue(areEqualInSizeAndElements(actual.begin(), actual.end(), expected.begin(), expected.end()));
    assertTrue(actual.capacity() > prevCapacity);
}
void VectorTestCase::testVectorCapacity_AddElementToEmtyVector_CapacityIsTwo()
{
	//Arrange
    ft::vector<int> vec;
    size_t expectedCapacity = 2;
    //Act
    vec.push_back(1);
	//Assert
	assertTrue(vec.capacity() == expectedCapacity);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorCapacity_CreateEmptyVector_CapacityIsZero()
{
	//Arrange
    ft::vector<int> vec;
	size_t expectedCapacity = 0;
    //Act
    size_t receivedCapacity = vec.capacity();
	//Assert
	assertTrue(expectedCapacity == receivedCapacity);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorCapacity_VectorOfSizeOneAndCapcityTwoPushBackedWithTwoElements_CapcityIsInitialCapcityIncreaseByOneAndThenDoubled()
{
	//Arrange
    ft::vector<int> vec(1,111);
	size_t initialCapacity = vec.capacity();
    size_t expectedCapacity = (initialCapacity + 1) * 2;
    //Act
    vec.push_back(2);
    vec.push_back(3);
	size_t actualCapacity = vec.capacity();
    //Assert
	assertTrue(expectedCapacity == actualCapacity);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorEmpty_VectorCreatedWithDefaultConstructorNoElementsAdded_EmptyEqualsTrue()
{
	//Arrange
    ft::vector<int> vec;
    //Act
    
	//Assert
	assertTrue(vec.empty());
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorEmpty_AddOneElementToEmtyVector_EmptyEqualsFalse()
{
	//Arrange
    ft::vector<int> vec;
    vec.push_back(1);
    //Act
    
	//Assert
	assertFalse(vec.empty());
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorReserve_CallReserveWithNParamGreaterThenVectorCapacity_ResutlVectorCapacityIsEqualToNParam()
{
	//Arrange
    ft::vector<int> vec(1000, 999);
    size_t n = vec.capacity() * 2;
	//Act
    vec.reserve(n);
	//Assert
	assertTrue(vec.capacity() == n);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorReserve_CallReserveWithNParamEqualToVectorCapacity_ResultVectorCapacityEqualsInitialCapacity()
{
	//Arrange
    ft::vector<int> vec(1000, 999);
    ft::vector<int>::size_type initialCapacity = vec.capacity();
    size_t n = vec.capacity();
	//Act
    vec.reserve(n);
	//Assert
	assertTrue(vec.capacity() == initialCapacity);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorReserve_CallReserveWithNParamLessThenVectorCapacity_ResultVectorCapacityEqualsInitialCapacity()
{
	//Arrange
    ft::vector<int> vec(1000, 999);
    ft::vector<int>::size_type initialCapacity = vec.capacity();
    size_t n = 1;
	//Act
    vec.reserve(n);
	//Assert
	assertTrue(vec.capacity() == initialCapacity);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorReverse_CallReserveWithNParamGreaterThenMaxSize_ExceptionIsThrown()
{
	//Arrange
    ft::vector<int> vec(1000, 999);
    ft::vector<int>::size_type n = vec.max_size() + 1;
	bool isExceptionThrown = false;
    //Act
    try
    {
        vec.reserve(n);
    }
	catch (const std::length_error &er)
    {
        std::cerr << er.what() << std::endl;
        isExceptionThrown = true;
    }
    //Assert
	assertTrue(isExceptionThrown);
	//assertFalse();
	//assertEqual(,);
}

void VectorTestCase::testVectorIndexOperator_IterateOverZeroToVectorSizeMinusOneIndexAndCreateNewVectorFromObtainedElements_NewVectorIsEqualToInitialVector()
{
	//Arrange
    ft::vector<int> initialVec(10, 999);
	ft::vector<int> newVector;
    //Act
    for (size_t i = 0; i < initialVec.size(); i++)
    {
        newVector.push_back(initialVec[i]);
    }
	//Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            initialVec.begin(), 
            initialVec.end(),
            newVector.begin(),
            newVector.end()
        )
    );
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorIndexOperator_CreateTwoVectorsThatAreDifferentInFirstElementThenSetWithIndexOpFirstElementOfSecondToFirstElementOfFirst_TwoVectorsAreEqualInSizeAndElements()
{
	//Arrange
    ft::vector<int> first(2, 999);
	ft::vector<int> second;
    second.push_back(888);
    second.push_back(999);
    //Act
    second[0] = 999;
	//Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            first.begin(),
            first.end(),
            second.begin(),
            second.end()
        )
    );
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorAtNonConstMethod_CallAtWithValueEqualOrGreaterThenVectorSize_ExceptionIsThrown()
{
	//Arrange
    ft::vector<int> vec(10, 999);
	bool isExceptionThrown = false;
    //Act
    try
    {
        vec.at(vec.size() + 1);
    }
	catch (const std::out_of_range &ex)
    {
        std::cerr << ex.what() << std::endl;
        isExceptionThrown = true;
    }
    //Assert
	assertTrue(isExceptionThrown);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorAtConstMethod_CallAtWithValueEqualOrGreaterThenVectorSize_ExceptionIsThrown()
{
//Arrange
    const ft::vector<int> vec(10, 999);
	bool isExceptionThrown = false;
    //Act
    try
    {
        vec.at(vec.size() + 1);
    }
	catch (const std::out_of_range &ex)
    {
        std::cerr << ex.what() << std::endl;
        isExceptionThrown = true;
    }
    //Assert
	assertTrue(isExceptionThrown);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorAtConstMethod_IterateOverZeroToVectorSizeMinusOneIndexAndCreateNewVectorFromObtainedElements_NewVectorIsEqualToInitialVector()
{
	//Arrange
    ft::vector<int> initialVec(10, 999);
	ft::vector<int> newVector;
    //Act
    for (size_t i = 0; i < initialVec.size(); i++)
    {
        newVector.push_back(initialVec.at(i));
    }
	//Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            initialVec.begin(), 
            initialVec.end(),
            newVector.begin(),
            newVector.end()
        )
    );
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorAtNonConstMethod_CreateTwoVectorsThatAreDifferentInFirstElementThenSetWithAtMethodFirstElementOfSecondToCopyOfFirstElementOfFirstVector_TwoVectorsAreEqualInSizeAndElements()
{
	//Arrange
    ft::vector<int> first(2, 999);
	ft::vector<int> second;
    second.push_back(888);
    second.push_back(999);
    //Act
    second.at(0) = 999;
	//Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            first.begin(),
            first.end(),
            second.begin(),
            second.end()
        )
    );
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorFrontMethod_CreateEmptyVectorAndPushBackFiveAndCallFront_ReturnedValueIsFive()
{
	//Arrange
    ft::vector<int> vec;
    vec.push_back(5);
    //Act
    int returnedValue = vec.front();
	//Assert
	assertTrue(returnedValue == 5);
	//assertFalse();
	//assertEqual(,);
}

void VectorTestCase::testVectorBackMethod_CreateVectorWithThreeDifferentStringsAndCallBackMethd_ReturnedValueIsThirdAddedString()
{
	//Arrange
    ft::vector<std::string> v;
    v.push_back("Ook.");
    v.push_back("Ook!");
    v.push_back("Ook?");
    //Act
    std::string returnedValue = v.back();
	//Assert
	assertTrue(returnedValue == std::string("Ook?"));
	// assertFalse();
	// assertEqual(,);
}
void VectorTestCase::testVectorAssignRangeMethod_AssignSrcVectorToTargetVectorWhichIsInitiallyDifferentFromSrcVectorInElementsAndSize_SrcVectorEqualsTargetVectorInElementsAndSize()
{
	//Arrange
    ft::vector<std::string> target(5, "jj");
    ft::vector<std::string> src(10, "zepher");
	//Act
    target.assign(src.begin(), src.end());
    //Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            target.begin(), 
            target.end(), 
            src.begin(), 
            src.end()
        )
    );
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorAssignRangeMethod_AssignSrcNonEmptyVectorToTargetEmptyVector_SrcVectorEqualsTargetVectorInElementsAndSize()
{
	//Arrange
    ft::vector<std::string> target;
    ft::vector<std::string> src(10, "zepher");
	//Act
    target.assign(src.begin(), src.end());
    //Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            target.begin(), 
            target.end(), 
            src.begin(), 
            src.end()
        )
    );
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorAssignRangeMethod_AssignSrcEmptyVectorToTargetNonEmptyVector_SrcVectorEqualsTargetVectorInElementsAndSize()
{
	//Arrange
    ft::vector<std::string> target(10, "cliff");
    ft::vector<std::string> src;
	//Act
    target.assign(src.begin(), src.end());
    //Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            target.begin(), 
            target.end(), 
            src.begin(), 
            src.end()
        )
    );
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorAssignRangeMethod_AssignSrcVectorThatHasSizeMoreThenTargetVectorCapacity_SrcVectorEqualsTargetVectorInElementsAndSizeAndTargetVectorCapacityIsGreaterThenInitialTargetVectorCapacity()
{
	//Arrange
    ft::vector<int> target(10, 888);
    ft::vector<int> src(100, 999);
    size_t initialCapacity = target.capacity();
    //Act
    target.assign(src.begin(), src.end());
	//Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            target.begin(), 
            target.end(), 
            src.begin(), 
            src.end()
        )
    );
	assertTrue(target.capacity() > initialCapacity);
    //assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorAssignRangeMethod_AssignToTargetOfSizeFiveSrcOfSizeTwo_TargetOfSizeTwo()
{
	//Arrange
    ft::vector<std::string> target(5, "Hello");
	ft::vector<std::string> src(2, "Goodby");
    //Act
    target.assign(src.begin(), src.end());
	//Assert
	assertTrue(target.size() == 2);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorAssignRangeMethod_AssignToEmptyTargetSrcOfSizeTwo_TargetOfSizeTwo()
{
	//Arrange
    ft::vector<std::string> target;
	ft::vector<std::string> src(2, "Goodby");
    //Act
    target.assign(src.begin(), src.end());
	//Assert
	assertTrue(target.size() == 2);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testVectorAssignRangeMethod_AssignToTargetOfSizeFiveEmptySrc_EmptyTarget()
{
	//Arrange
    ft::vector<std::string> target(5, "uni");
	ft::vector<std::string> src;
    //Act
    target.assign(src.begin(), src.end());
	//Assert
	assertTrue(target.empty());
	//assertFalse();

	//assertEqual(,);
}
void VectorTestCase::testVectorAssignFillMethod_AssignFillTargetWithElementsDifferentFromTargetAndQtyIsLessThenTargetSize_TargetSizeIsEqualToQtyTargerElementsAreEqualToFillElements()
{
	//Arrange
    ft::vector<std::string> target(5, "uni");
    //Act
    target.assign(3, "multy");
    ft::vector<std::string> expectedTarget(3, "multy");
    //Assert
	assertTrue(target.size() == 3);
	assertTrue
    (
        areEqualInSizeAndElements(
            target.begin(),
            target.end(),
            expectedTarget.begin(),
            expectedTarget.end()
        )
    );
    //assertFalse();

	//assertEqual(,);
}
void VectorTestCase::testVectorAssignFillMethod_AssignFillFiveElementsToEmtpyTarget_TargetIsFilledWithFiveElements()
{
	//Arrange
    ft::vector<std::string> target;
    //Act
    target.assign(5, "multy");
    ft::vector<std::string> expectedTarget(5, "multy");
    //Assert
	assertTrue(target.size() == 5);
	assertTrue
    (
        areEqualInSizeAndElements(
            target.begin(),
            target.end(),
            expectedTarget.begin(),
            expectedTarget.end()
        )
    );
    //assertFalse();

	//assertEqual(,);
}
void VectorTestCase::testVectorAssignFillMethod_AssignFillZeroElementsToTargetWithSizeFive_TargetIsEmpty()
{
	//Arrange
    ft::vector<std::string> target(5, "multy");
    //Act
    target.assign(0, "multy");
    ft::vector<std::string> expectedTarget;
    //Assert
	assertTrue(target.empty());
	assertTrue
    (
        areEqualInSizeAndElements(
            target.begin(),
            target.end(),
            expectedTarget.begin(),
            expectedTarget.end()
        )
    );
    //assertFalse();

	//assertEqual(,);
}
void VectorTestCase::testPopBack_PopBackOnVectorWithThreeElements_VectorWithTwoElemtsAndBackReturnsSecondElement()
{
	//Arrange
    ft::vector<std::string> v;
    v.push_back("A");
    v.push_back("B");
    v.push_back("C");
    //Act
    v.pop_back();
    //Assert
    assertTrue(v.back() == std::string("B"));
	assertTrue(v.size() == 2);
    //assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testPopBack_PopBackOnEmptyVector_DoesNothingMustNotCrash()
{
	//Arrange
    ft::vector<std::string> v;
    //Act
    v.pop_back();
    //Assert
    assertTrue(true);
    //assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testInsertSingleElement_InsertFiveIntoVectorOfOneTwoAndThreeWithIteratorPointingAtTwo_VectorOfOneFiveTwoAndThree()
{
	//Arrange
    ft::vector<int> vectorOfOneTwoThree;
    vectorOfOneTwoThree.push_back(1);
	vectorOfOneTwoThree.push_back(2);
    vectorOfOneTwoThree.push_back(3);
    ft::vector<int>::iterator iteratorPointingAtTwo = vectorOfOneTwoThree.begin();
    iteratorPointingAtTwo++;
    ft::vector<int> vectorOfOneFiveTwoThree;
    vectorOfOneFiveTwoThree.push_back(1);
	vectorOfOneFiveTwoThree.push_back(5);
    vectorOfOneFiveTwoThree.push_back(2);
    vectorOfOneFiveTwoThree.push_back(3);
    //Act
    vectorOfOneTwoThree.insert(iteratorPointingAtTwo, 5);
	//Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            vectorOfOneTwoThree.begin(), 
            vectorOfOneTwoThree.end(),
            vectorOfOneFiveTwoThree.begin(),
            vectorOfOneFiveTwoThree.end()
        )
    );
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testInsertSingleElement_IsertFiveIntoVectorOfOneTwoThreeWithIteratorPointingToPastTheEndPosition_VectorOfOneTwoThreeFive()
{
	//Arrange
    ft::vector<int> vectorOfOneTwoThree;
    vectorOfOneTwoThree.push_back(1);
	vectorOfOneTwoThree.push_back(2);
    vectorOfOneTwoThree.push_back(3);
    ft::vector<int>::iterator itEnd = vectorOfOneTwoThree.end();
    ft::vector<int> vectorOfOneTwoThreeFive;
    vectorOfOneTwoThreeFive.push_back(1);
    vectorOfOneTwoThreeFive.push_back(2);
    vectorOfOneTwoThreeFive.push_back(3);
	vectorOfOneTwoThreeFive.push_back(5);
    //Act
    vectorOfOneTwoThree.insert(itEnd, 5);
	//Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            vectorOfOneTwoThree.begin(), 
            vectorOfOneTwoThree.end(),
            vectorOfOneTwoThreeFive.begin(),
            vectorOfOneTwoThreeFive.end()
        )
    );
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testInsertSingleElement_IsertFiveIntoVectorOfOneTwoThreeWithIteratorPointingToBeginPosition_VectorOfFiveOneTwoThree()
{
	//Arrange
    ft::vector<int> vectorOfOneTwoThree;
    vectorOfOneTwoThree.push_back(1);
	vectorOfOneTwoThree.push_back(2);
    vectorOfOneTwoThree.push_back(3);
    ft::vector<int>::iterator itBegin = vectorOfOneTwoThree.begin();
    ft::vector<int> vectorOfFiveOneTwoThree;
	vectorOfFiveOneTwoThree.push_back(5);
    vectorOfFiveOneTwoThree.push_back(1);
    vectorOfFiveOneTwoThree.push_back(2);
    vectorOfFiveOneTwoThree.push_back(3);
    //Act
    vectorOfOneTwoThree.insert(itBegin, 5);
	//Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            vectorOfOneTwoThree.begin(), 
            vectorOfOneTwoThree.end(),
            vectorOfFiveOneTwoThree.begin(),
            vectorOfFiveOneTwoThree.end()
        )
    );
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testInsertSingleElement_InsertFiveIntoVectorOfOneTwoAndThreeWithIteratorPointingAtTwo_ReturnIteratorPointsAtElementInserted()
{
	//Arrange
    ft::vector<int> vectorOfOneTwoThree;
    vectorOfOneTwoThree.push_back(1);
	vectorOfOneTwoThree.push_back(2);
    vectorOfOneTwoThree.push_back(3);
    ft::vector<int>::iterator iteratorPointingAtTwo = vectorOfOneTwoThree.begin();
    iteratorPointingAtTwo++;
    ft::vector<int> vectorOfOneFiveTwoThree;
    vectorOfOneFiveTwoThree.push_back(1);
	vectorOfOneFiveTwoThree.push_back(5);
    vectorOfOneFiveTwoThree.push_back(2);
    vectorOfOneFiveTwoThree.push_back(3);
    //Act
    ft::vector<int>::iterator returnedIt = vectorOfOneTwoThree.insert(iteratorPointingAtTwo, 5);
	//Assert
	assertTrue(*returnedIt == 5);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testInsertSingleElement_InsertThreeIntoVectorOfOneTwoWithIteratorPoiningAtTwo_VectorOfOneThreeTwoWithSizeThreeAndCapacitySix()
{
	//Arrange
    ft::vector<int> vectorOfOneTwo;
    vectorOfOneTwo.push_back(1);
	vectorOfOneTwo.push_back(2);
    
    ft::vector<int>::iterator iteratorPointingAtTwo = vectorOfOneTwo.begin();
    iteratorPointingAtTwo++;
    ft::vector<int> vectorOfOneThreeTwo;
    vectorOfOneThreeTwo.push_back(1);
    vectorOfOneThreeTwo.push_back(3);
    vectorOfOneThreeTwo.push_back(2);
    //Act
    vectorOfOneTwo.insert(iteratorPointingAtTwo, 3);
    //Assert
	assertTrue(
        areEqualInSizeAndElements(
            vectorOfOneTwo.begin(),
            vectorOfOneTwo.end(),
            vectorOfOneThreeTwo.begin(),
            vectorOfOneThreeTwo.end()
        )
    );
	assertTrue(vectorOfOneTwo.size() == 3);
    assertTrue(vectorOfOneTwo.capacity() == 6);
}
void VectorTestCase::testInsertFill_InVectorOfOneTwoInsertThreeFivesBeforTwo_VectorOfOneFiveFiveFiveTwo()
{
	//Arrange
    ft::vector<int> vectorOfoneTwo;
    vectorOfoneTwo.push_back(1);
	vectorOfoneTwo.push_back(2);
    ft::vector<int>::iterator position = vectorOfoneTwo.begin();
    position++;
    ft::vector<int> vectorOfOneFiveFiveFiveTwo;
    vectorOfOneFiveFiveFiveTwo.push_back(1);
    vectorOfOneFiveFiveFiveTwo.push_back(5);
    vectorOfOneFiveFiveFiveTwo.push_back(5);
    vectorOfOneFiveFiveFiveTwo.push_back(5);
    vectorOfOneFiveFiveFiveTwo.push_back(2);
    //Act
    vectorOfoneTwo.insert(position, 3, 5);
	//Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            vectorOfoneTwo.begin(),
            vectorOfoneTwo.end(),
            vectorOfOneFiveFiveFiveTwo.begin(),
            vectorOfOneFiveFiveFiveTwo.end()
        )
    );
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testInsertFill_InVectorOfSixElementInsertFiveElements_VectorCapacityIsEleven()
{
	//Arrange
    ft::vector<int> vectorOfSixElements(6, 99);
    ft::vector<int>::iterator position = vectorOfSixElements.begin();
    position++;
    ft::vector<int> expectedVector;
    expectedVector.push_back(99);
    expectedVector.push_back(66);
    expectedVector.push_back(66);
    expectedVector.push_back(66);
    expectedVector.push_back(66);
    expectedVector.push_back(66);
    expectedVector.push_back(99);
    expectedVector.push_back(99);
    expectedVector.push_back(99);
    expectedVector.push_back(99);
    expectedVector.push_back(99);
    //Act
    vectorOfSixElements.insert(position, 5, 66);
	//Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            vectorOfSixElements.begin(),
            vectorOfSixElements.end(),
            expectedVector.begin(),
            expectedVector.end()
        )
    );
	assertTrue(vectorOfSixElements.size() == 11);
    assertTrue(vectorOfSixElements.capacity() == 11);
    //assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testInsertRange_InVectorOfOneTwoInsertVectorOfThreeFourFiveWithIteratorPointingAtTwo_VectorOfOneThreeFourFiveTwoWithSizeFiveAndCapacityOfFive()
{
	//Arrange
    ft::vector<int> vOneTwo;
    vOneTwo.push_back(1);
	vOneTwo.push_back(2);
    ft::vector<int> vThreeFourFive;
    vThreeFourFive.push_back(3);
	vThreeFourFive.push_back(4);
    vThreeFourFive.push_back(5);
    ft::vector<int>::iterator position = vOneTwo.begin();
    position++;
    ft::vector<int> vOneThreeFourFiveTwo;
    vOneThreeFourFiveTwo.push_back(1);
    vOneThreeFourFiveTwo.push_back(3);
    vOneThreeFourFiveTwo.push_back(4);
    vOneThreeFourFiveTwo.push_back(5);
    vOneThreeFourFiveTwo.push_back(2);
    //Act
    vOneTwo.insert(position, vThreeFourFive.begin(), vThreeFourFive.end());
    
    //Assert
	assertTrue
    (
        areEqualInSizeAndElements
        (
            vOneTwo.begin(),
            vOneTwo.end(),
            vOneThreeFourFiveTwo.begin(),
            vOneThreeFourFiveTwo.end()
        )
    );
	assertTrue(vOneTwo.size() == 5);
    assertTrue(vOneTwo.capacity() == 5);
    //assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testInsertRange_InVectorOfOneTwoInsertVectorOfFiveFiveWithIteratorPointingAtOne_vectorOfFiveFiveOneTwoWithSizeFourAndCapacityFour()
{
	//Arrange
    ft::vector<int> vOneTwo;
    vOneTwo.push_back(1);
	vOneTwo.push_back(2);
    ft::vector<int> vFiveFive(2, 5);
    
    ft::vector<int>::iterator position = vOneTwo.begin();
    
    ft::vector<int> vFiveFiveOneTwo;
    vFiveFiveOneTwo.push_back(5);
    vFiveFiveOneTwo.push_back(5);
    vFiveFiveOneTwo.push_back(1);
    vFiveFiveOneTwo.push_back(2);
    //Act
    vOneTwo.insert(position, vFiveFive.begin(), vFiveFive.end());
    
    //Assert
	assertTrue
    (
        areEqualInSizeAndElements
        (
            vOneTwo.begin(),
            vOneTwo.end(),
            vFiveFiveOneTwo.begin(),
            vFiveFiveOneTwo.end()
        )
    );
	assertTrue(vOneTwo.size() == 4);
    assertTrue(vOneTwo.capacity() == 4);
    //assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testInsertRange_InVectorOfOneTwoInsertVectotOfFiveFiveWithIteratorPointingAtPastTheEndPosition_VectorOfFiveFiveOneTwoWithSizeFourAndCapacityFour()
{
	//Arrange
    ft::vector<int> vOneTwo;
    vOneTwo.push_back(1);
	vOneTwo.push_back(2);
    ft::vector<int> vFiveFive(2, 5);
    
    ft::vector<int>::iterator position = vOneTwo.end();
    
    ft::vector<int> vFiveFiveOneTwo;
    vFiveFiveOneTwo.push_back(1);
    vFiveFiveOneTwo.push_back(2);
    vFiveFiveOneTwo.push_back(5);
    vFiveFiveOneTwo.push_back(5);
    //Act
    vOneTwo.insert(position, vFiveFive.begin(), vFiveFive.end());
    
    //Assert
	assertTrue
    (
        areEqualInSizeAndElements
        (
            vOneTwo.begin(),
            vOneTwo.end(),
            vFiveFiveOneTwo.begin(),
            vFiveFiveOneTwo.end()
        )
    );
	assertTrue(vOneTwo.size() == 4);
    assertTrue(vOneTwo.capacity() == 4);
    //assertFalse();
	//assertEqual(,);
}

void VectorTestCase::testEraseSingle_EraseTwoInVectorOfOneTwoThree_VectorOfOneThreeWithSizeTwo()
{
	//Arrange
    ft::vector<int> vOneTwoThree;
    vOneTwoThree.push_back(1);
    vOneTwoThree.push_back(2);
    vOneTwoThree.push_back(3);
    ft::vector<int>::iterator it = vOneTwoThree.begin();
    it++;
    ft::vector<int> vOneThree;
    vOneThree.push_back(1);
    vOneThree.push_back(3);
    //Act
    vOneTwoThree.erase(it);
    //Assert
    assertTrue
    (
        areEqualInSizeAndElements
        (
            vOneTwoThree.begin(),
            vOneTwoThree.end(),
            vOneThree.begin(),
            vOneThree.end()
        )
    );
    assertTrue(vOneTwoThree.size() == 2);
}
void VectorTestCase::testEraseSingle_EraseTheOnlyElementFromVectorOfOneElement_EmptyVector()
{
	//Arrange
    ft::vector<int> v;
    v.push_back(1);
    ft::vector<int>::iterator it = v.begin();
    //Act
    v.erase(it);
    //Assert
    assertTrue(v.empty() == true);
}
void VectorTestCase::testEraseSingle_EraseLastElement_VectorEqualToInitialVectorWithoutLastElement()
{
	//Arrange
    ft::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    ft::vector<int>::iterator it = v.end();
    it--;
    ft::vector<int> expected;
    expected.push_back(1);
    expected.push_back(2);
    expected.push_back(3);
    //Act
    v.erase(it);
    //Assert
    assertTrue(
        areEqualInSizeAndElements
        (
            v.begin(),
            v.end(),
            expected.begin(),
            expected.end()
        )
    );
}
void VectorTestCase::testEraseSingle_EraseLastElement_ReturnedIteratorPoiningToPastTheEndElementOfContainer()
{
	//Arrange
    ft::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    ft::vector<int>::iterator position = v.end();
    position--;
    //Act
    ft::vector<int>::iterator actualReturnedIterator = v.erase(position);
    ft::vector<int>::iterator expectedReturnIterator = v.end();
    //Assert
    assertTrue(expectedReturnIterator == actualReturnedIterator);
}
void VectorTestCase::testEraseRange_EraseTwoAndThreeFromVectorOfOneTwoThreeFour_VectorOfOneFour()
{
	//Arrange
    ft::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    ft::vector<int>::iterator first = v.begin();
    ft::vector<int>::iterator last = v.begin();
    first++;
    last++;
    last++;
    last++;
    ft::vector<int> expectedVector;
    expectedVector.push_back(1);
    expectedVector.push_back(4);
    //Act
    ft::vector<int>::iterator actualReturnedIterator = v.erase(first, last);
    //Assert
    assertTrue(
        areEqualInSizeAndElements
        (
            v.begin(),
            v.end(),
            expectedVector.begin(),
            expectedVector.end()
        )
    );
    assertTrue(*actualReturnedIterator == 4);
}
void VectorTestCase::testEraseRange_EraseAllElements_EmptyVectorReturnedIteratorPointsToPastTheEnd()
{
	//Arrange
    ft::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    ft::vector<int>::iterator first = v.begin();
    ft::vector<int>::iterator last = v.end();
    ft::vector<int> expectedVector;
    //Act
    ft::vector<int>::iterator actualReturnedIterator = v.erase(first, last);
    ft::vector<int>::iterator expectedRerurnedIterator = v.end();
    //Assert
    assertTrue(
        areEqualInSizeAndElements
        (
            v.begin(),
            v.end(),
            expectedVector.begin(),
            expectedVector.end()
        )
    );
    assertTrue(expectedRerurnedIterator == actualReturnedIterator);
}
void VectorTestCase::testSwap_SwapNonEmptyVectors_ThisEqualsToCopyOfXMadeBeforSwapAndXIsEqualToCopyOfThisMadeBeforeSwap()
{
	//Arrange
    ft::vector<std::string> v(3, "One");
    ft::vector<std::string> x(5, "two");

    ft::vector<std::string> copyOfV = v;
    ft::vector<std::string> copyOfX = x;
	//Act
    v.swap(x);
	//Assert
	assertTrue
    (
        areEqualInSizeAndElements
        (
            v.begin(),
            v.end(),
            copyOfX.begin(),
            copyOfX.end()
        )
    );
	assertTrue
    (
        areEqualInSizeAndElements
        (
            x.begin(),
            x.end(),
            copyOfV.begin(),
            copyOfV.end()
        )
    );
    //assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testClear_CallClearOnVectorContainingSeveralElements_VectorWhichIsEmpty()
{
	//Arrange
    ft::vector<std::string> v(3, "One");
	//Act
    v.clear();
	//Assert
	assertTrue(v.empty());
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testGlobalEqual_CompareTwoVectorsEqualInSizeAndElements_true()
{
	//Arrange
    ft::vector<std::string> v1(3, "One");
	ft::vector<std::string> v2(3, "One");
    //Act
	//Assert
	assertTrue(v1 == v2);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testGlobalEqualOp_CompareTwoEmptyVectors_true()
{
	//Arrange
    ft::vector<std::string> v1;
	ft::vector<std::string> v2;
    //Act
	//Assert
	assertTrue(v1 == v2);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testGlobalOp_ComparevectorsOfDifferentSize_false()
{
	//Arrange
    ft::vector<std::string> v1(1, "Hello");
	ft::vector<std::string> v2(2, "Hello");
    //Act
	//Assert
	assertFalse(v1 == v2);
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testGlobalStrictlyLessOp_CompereOneTwoAnsOneTwoThree_true()
{
	//Arrange
    ft::vector<int> v1;
    ft::vector<int> v2;
    v1.push_back(1);
	v1.push_back(2);
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    //Act
    assertTrue(v1 < v2);
	//Assert
	//assertTrue();
	//assertFalse();
	//assertEqual(,);
}
void VectorTestCase::testGlobalStrictLessOp_CompareOneTwoAndOneTwo_false()
{
	//Arrange
    ft::vector<int> v1;
    ft::vector<int> v2;
    v1.push_back(1);
	v1.push_back(2);
    v2.push_back(1);
    v2.push_back(2);
    //Act
    assertFalse(v1 < v2);
	//Assert
	//assertTrue();
	//assertFalse();
	//assertEqual(,);
}

void VectorTestCase::testGlobalStrictlyLessOp_CompareOneTwoThreeAndOneTwo_false()
{
	//Arrange
    ft::vector<int> v1;
    ft::vector<int> v2;
    v1.push_back(1);
	v1.push_back(2);
    v1.push_back(3);
    v2.push_back(1);
    v2.push_back(2);
    //Act
    assertFalse(v1 < v2);
	//Assert
	//assertTrue();
	//assertFalse();
	//assertEqual(,);
}









/* ************************************************************************** */
