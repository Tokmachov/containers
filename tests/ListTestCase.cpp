#include "ListTestCase.hpp"

ListTestCase::ListTestCase() {}

ListTestCase::ListTestCase( const ListTestCase & src ){ (void)src; }

ListTestCase::~ListTestCase() {}

ListTestCase &ListTestCase::operator=( ListTestCase const & rhs )
{
	(void)rhs;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
//Configure init function so it fills allTests var properly with your test funcitons
//and funciton names
void ListTestCase::initTests()
{
    TestNameAndFunc t1 = 
    { 
        "testFillConstructorCreatesListEqualToListOfTenIntsWithOneValue", 
        testFillConstructorCreatesListEqualToListOfTenIntsWithOneValue
    };
    ListTestCase::allTests.push_back(t1);
    
    TestNameAndFunc t2 = 
    { 
        "testRangeConstructorInitializesListWithRangeStrings", 
        testRangeConstructorInitializesListWithRangeStrings
    };
    ListTestCase::allTests.push_back(t2);
    TestNameAndFunc t3 = 
    { 
        "testCopyConstructedListIsEqualToSourceList", 
        testCopyConstructedListIsEqualToSourceList
    };
    ListTestCase::allTests.push_back(t3);
    TestNameAndFunc t4 = 
    { 
        "testCopyConstructedListsBecomesDifferentAfterElementsOfSourceAreChanged", 
        testCopyConstructedListsBecomesDifferentAfterElementsOfSourceAreChanged
    };
    ListTestCase::allTests.push_back(t4);
    TestNameAndFunc t5 =
    { 
        "testListAfterAssignationIsEqualInSizeAndElementsToSourceList", 
        testListAfterAssignationIsEqualInSizeAndElementsToSourceList
    };
    ListTestCase::allTests.push_back(t5);
    TestNameAndFunc t6 =
    { 
        "testListCreatedByAssignationBecomesDefferentToSourceAfterSourceIsChanged", 
        testListCreatedByAssignationBecomesDefferentToSourceAfterSourceIsChanged
    };
    ListTestCase::allTests.push_back(t6);
    TestNameAndFunc t7 =
    { 
        "testListsEmptyReturnsTrueAfterCreationWithDefaultInitializer", 
        testListsEmptyReturnsTrueAfterCreationWithDefaultInitializer
    };
    ListTestCase::allTests.push_back(t7);
    TestNameAndFunc t8 =
    { 
        "testListEmptyMethodReturnsFalseAfterAdditionOfOneElementToEmptyList", 
        testListEmptyMethodReturnsFalseAfterAdditionOfOneElementToEmptyList
    };
    ListTestCase::allTests.push_back(t8);
    TestNameAndFunc t9 =
    { 
        "testGetFrontElemenWhichIsStringHello", 
        testGetFrontElemenWhichIsStringHello
    };
    ListTestCase::allTests.push_back(t9);
    TestNameAndFunc t10 =
    { 
        "testSetFirstElementFromStringHelloToGoodbye", 
        testSetFirstElementFromStringHelloToGoodbye
    };
    ListTestCase::allTests.push_back(t10);
    TestNameAndFunc t11 =
    { 
        "testBackMethodSetLastElementToFiveAndCheckItIsFive", 
        testBackMethodSetLastElementToFiveAndCheckItIsFive
    };
    ListTestCase::allTests.push_back(t11);
    TestNameAndFunc t12 =
    { 
        "test_AssignRange_AssignSameRangeToSTDListAndFTList_ListsEqualInSizeAndElements", 
        test_AssignRange_AssignSameRangeToSTDListAndFTList_ListsEqualInSizeAndElements
    };
    ListTestCase::allTests.push_back(t12);
    TestNameAndFunc t13 =
    { 
        "test_AssignRange_AssignEmptyRangeToSTDListAndFTList_ListsEqualInSIzeAndElements", 
        test_AssignRange_AssignEmptyRangeToSTDListAndFTList_ListsEqualInSIzeAndElements
    };
    ListTestCase::allTests.push_back(t13);
    TestNameAndFunc t14 =
    { 
        "test_AssignRange_AssignRangeWichIsBiggerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements", 
        test_AssignRange_AssignRangeWichIsBiggerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements
    };
    ListTestCase::allTests.push_back(t14);
    TestNameAndFunc t15 =
    { 
        "test_AssignRange_AssignRangeWichIsSmallerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements", 
        test_AssignRange_AssignRangeWichIsSmallerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements
    };
    ListTestCase::allTests.push_back(t15);
    TestNameAndFunc t16 =
    { 
        "test_AssignFill_AssignSameRangeToSTDListAndFTList_ListsEqualInSizeAndElements", 
        test_AssignFill_AssignSameRangeToSTDListAndFTList_ListsEqualInSizeAndElements
    };
    ListTestCase::allTests.push_back(t16);
    TestNameAndFunc t17 =
    { 
        "test_AssignFill_AssignEmptyRangeToSTDListAndFTList_ListsEqualInSIzeAndElements", 
        test_AssignFill_AssignEmptyRangeToSTDListAndFTList_ListsEqualInSIzeAndElements
    };
    ListTestCase::allTests.push_back(t17);
    TestNameAndFunc t18 =
    { 
        "test_AssignFill_AssignRangeWichIsBiggerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements", 
        test_AssignFill_AssignRangeWichIsBiggerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements
    };
    ListTestCase::allTests.push_back(t18);
    TestNameAndFunc t19 =
    { 
        "test_AssignFill_AssignRangeWichIsSmallerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements", 
        test_AssignFill_AssignRangeWichIsSmallerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements
    };
    ListTestCase::allTests.push_back(t19);
    TestNameAndFunc t20 =
    { 
        "testPushFront_CreateListAddOneElement_SizeIncreasesByOneAndFrontMethodReturnsAddedElement", 
        testPushFront_CreateListAddOneElement_SizeIncreasesByOneAndFrontMethodReturnsAddedElement
    };
    ListTestCase::allTests.push_back(t20);
    TestNameAndFunc t21 =
    { 
        "testPopFront_CreateListRemoveOneElement_SizeDecreasesbyOneAndFrontElemenIsDfferent", 
        testPopFront_CreateListRemoveOneElement_SizeDecreasesbyOneAndFrontElemenIsDfferent
    };
    ListTestCase::allTests.push_back(t21);
    TestNameAndFunc t22 =
    { 
        "testPushBack_AddOneElementToList_SizeIncreasesByOneAndLastElementBecomesTheOneAdded", 
        testPushBack_AddOneElementToList_SizeIncreasesByOneAndLastElementBecomesTheOneAdded
    };
    ListTestCase::allTests.push_back(t22);
    TestNameAndFunc t23 =
    { 
        "testPopBack_PopOneElement_SizeMustDecreaseByOneBackElementMustBeEqualToElementBeforeLast", 
        testPopBack_PopOneElement_SizeMustDecreaseByOneBackElementMustBeEqualToElementBeforeLast
    };
    ListTestCase::allTests.push_back(t23);
    TestNameAndFunc t24 =
    { 
        "testPopBack_PopAllElementsFromListInALoop_ResultListMustBeEmpty", 
        testPopBack_PopAllElementsFromListInALoop_ResultListMustBeEmpty
    };
    ListTestCase::allTests.push_back(t24);
    TestNameAndFunc t25 =
    { 
        "testIsertSingleElement_RusultListAndRetrnValueMustBeTheSameAsOfSTDList", 
        testIsertSingleElement_RusultListAndRetrnValueMustBeTheSameAsOfSTDList
    };
    ListTestCase::allTests.push_back(t25);
    TestNameAndFunc t26 =
    { 
        "testInsertSingleElement_InsertMultipleElementsInLoop_ResultListIsEqualToStdListEffectedBySameActions", 
        testInsertSingleElement_InsertMultipleElementsInLoop_ResultListIsEqualToStdListEffectedBySameActions
    };
    ListTestCase::allTests.push_back(t26);
    TestNameAndFunc t27 =
    { 
        "testInsertFill_InsertMultipleElemens_ResultListMustBeEqualToStdListEffectedBySameActions", 
        testInsertFill_InsertMultipleElemens_ResultListMustBeEqualToStdListEffectedBySameActions
    };
    ListTestCase::allTests.push_back(t27);
    TestNameAndFunc t28 =
    { 
        "testIsertRange_InsertRange_ResultListMustBeEqualToStdListEffectedBySameActions", 
        testIsertRange_InsertRange_ResultListMustBeEqualToStdListEffectedBySameActions
    };
    ListTestCase::allTests.push_back(t28);
    TestNameAndFunc t29 =
    { 
        "testEraseSingleElement_RemoveElement_ResultFtListMustIsEqualToStdListEffectedByTheSameActions", 
        testEraseSingleElement_RemoveElement_ResulFtListMustIsEqualToStdListEffectedByTheSameActions
    };
    ListTestCase::allTests.push_back(t29);
    TestNameAndFunc t30 =
    { 
        "testEraseSingleElement_RemoveAllElementsFromListInALoop_ResultFtListMustIsEqualToStdListEffectedByTheSameActionsAndBothListsAreZeroSized", 
        testEraseSingleElement_RemoveAllElementsFromListInALoop_ResultFtListMustIsEqualToStdListEffectedByTheSameActionsAndBothListsAreZeroSized
    };
    ListTestCase::allTests.push_back(t30);
    TestNameAndFunc t31 =
    { 
        "testEraseSingleElement_RemoveLastElementFromList_RetunIsEndIterator", 
        testEraseSingleElement_RemoveLastElementFromList_RetunIsEndIterator
    };
    ListTestCase::allTests.push_back(t31);
    TestNameAndFunc t32 =
    { 
        "testEraseRange_RemoveRangeOfElementsFromList_StdContainerEffectedByTheSameActionsIsEqualToFtListInElementsAndSize", 
        testEraseRange_RemoveRangeOfElementsFromList_StdContainerEffectedByTheSameActionsIsEqualToFtListInElementsAndSize
    };
    ListTestCase::allTests.push_back(t32);
    TestNameAndFunc t33 =
    { 
        "testEraseRange_RemoveRangeOfElementsFromList_ReturnsIteratorIsEqualToLastInputParameter", 
        testEraseRange_RemoveRangeOfElementsFromList_ReturnsIteratorIsEqualToLastInputParameter
    };
    ListTestCase::allTests.push_back(t33);
    TestNameAndFunc t34 =
    { 
        "testEraseRange_RemoveAllElements_ResultListIsEmpty", 
        testEraseRange_RemoveAllElements_ResultListIsEmpty
    };
    ListTestCase::allTests.push_back(t34);
    TestNameAndFunc t35 =
    { 
        "testEraseRange_RemoveAllElements_ReturnIsEndIteratorOfList", 
        testEraseRange_RemoveAllElements_ReturnIsEndIteratorOfList
    };
    ListTestCase::allTests.push_back(t35);
    TestNameAndFunc t36 =
    { 
        "testSwap_SwapTwoDifferentListsOfInts_FirstMustBeEqualCopyOfSecondBeforeSwapAndViceVersa", 
        testSwap_SwapTwoDifferentListsOfInts_FirstMustBeEqualCopyOfSecondBeforeSwapAndViceVersa
    };
    ListTestCase::allTests.push_back(t36);
    TestNameAndFunc t37 =
    { 
        "testSwap_SwapTwoDifferentListsOfInts_IteratorOfFirstMustNowPointToElementOfSecond", 
        testSwap_SwapTwoDifferentListsOfInts_IteratorOfFirstMustNowPointToElementOfSecond
    };
    ListTestCase::allTests.push_back(t37);
    TestNameAndFunc t38 =
    { 
        "testResize_ResizeWithNSmallerThenListSize_ListSizeBecomesEqualToN", 
        testResize_ResizeWithNSmallerThenListSize_ListSizeBecomesEqualToN
    };
    ListTestCase::allTests.push_back(t38);
    TestNameAndFunc t39 =
    { 
        "testResize_ResizeWithNGreaterThenListSize_ListSizeBecomesEqualToN", 
        testResize_ResizeWithNGreaterThenListSize_ListSizeBecomesEqualToN
    };
    ListTestCase::allTests.push_back(t39);
    TestNameAndFunc t40 =
    { 
        "testResize_ResizeWithNGreaterThenListSizeNValueISProvided_AllNewElementsInListEqualToN", 
        testResize_ResizeWithNGreaterThenListSizeNValueISProvided_AllNewElementsInListEqualToN
    };
    ListTestCase::allTests.push_back(t40);
    TestNameAndFunc t41 =
    { 
        "testResize_ResizeWithNEqualToListSize_ListSizeIsEqualToSizeBeforeResize", 
        testResize_ResizeWithNEqualToListSize_ListSizeIsEqualToSizeBeforeResize
    };
    ListTestCase::allTests.push_back(t41);
    TestNameAndFunc t42 =
    { 
        "testClear_ClearNonEmptyList_ListIsEmpty", 
        testClear_ClearNonEmptyList_ListIsEmpty
    };
    ListTestCase::allTests.push_back(t42);
    TestNameAndFunc t43 =
    { 
        "testSpliceAllElements_SpliceOneListIntoAnother_RusultListIsEqualInSizeAndElementsToStdListEffectdBySameActions", 
        testSpliceAllElements_SpliceOneListIntoAnother_RusultListIsEqualInSizeAndElementsToStdListEffectdBySameActions
    };
    ListTestCase::allTests.push_back(t43);
    TestNameAndFunc t44 =
    { 
        "testSpliceAllElements_SpliceOneListIntoAnother_SrcListIsEmpty", 
        testSpliceAllElements_SpliceOneListIntoAnother_SrcListIsEmpty
    };
    ListTestCase::allTests.push_back(t44);
    TestNameAndFunc t45 =
    { 
        "testSpliceOneElement_SpliceOneElementToList_SrcListSizeIsDecreasedByOne", 
        testSpliceOneElement_SpliceOneElementToList_SrcListSizeIsDecreasedByOne
    };
    ListTestCase::allTests.push_back(t45);
    TestNameAndFunc t46 =
    { 
        "testSpliceOneElement_SpliceOneElementToList_TargetListSizeIsIncreasedByOne", 
        testSpliceOneElement_SpliceOneElementToList_TargetListSizeIsIncreasedByOne
    };
    ListTestCase::allTests.push_back(t46);
    TestNameAndFunc t47 =
    { 
        "testSpliceOneElement_SpliceOneElementToList_PositionIteratorDecrementedByOneYeldsElementAdded", 
        testSpliceOneElement_SpliceOneElementToList_PositionIteratorDecrementedByOneYeldsElementAdded
    };
    ListTestCase::allTests.push_back(t47);
    TestNameAndFunc t48 =
    { 
        "testSpliceOneElement_SpliceOneElementToEmptyList_PositionIteratorDecrementedByOneYeldsElementAdded", 
        testSpliceOneElement_SpliceOneElementToEmptyList_PositionIteratorDecrementedByOneYeldsElementAdded
    };
    ListTestCase::allTests.push_back(t48);
    TestNameAndFunc t49 =
    { 
        "testSpliceOneElement_SpliceOneElementFromThisListRightNextToPosition_PositionIteratorDecrementedByOneYeldsElementAdded", 
        testSpliceOneElement_SpliceOneElementFromThisListRightNextToPosition_PositionIteratorDecrementedByOneYeldsElementAdded
    };
    ListTestCase::allTests.push_back(t49);
    TestNameAndFunc t50 =
    { 
        "testSpliceRange_SpliceRange_SrcListSizeIsDecreasedByRangeSize", 
        testSpliceRange_SpliceRange_SrcListSizeIsDecreasedByRangeSize
    };
    ListTestCase::allTests.push_back(t50);
    TestNameAndFunc t51 =
    { 
        "testSpliceRange_SpliceRange_TargetSizeIsIncreasedByRangeSize", 
        testSpliceRange_SpliceRange_TargetSizeIsIncreasedByRangeSize
    };
    ListTestCase::allTests.push_back(t51);
    TestNameAndFunc t52 =
    { 
        "testSpliceRange_SpliceRange_TargetHasExpectedELements", 
        testSpliceRange_SpliceRange_TargetHasExpectedELements
    };
    ListTestCase::allTests.push_back(t52);
    TestNameAndFunc t53 =
    { 
        "testSpliceRange_SpliceRangeToEmptyTarget_TargetHasExpectedELements", 
        testSpliceRange_SpliceRangeToEmptyTarget_TargetHasExpectedELements
    };
    ListTestCase::allTests.push_back(t53);
    TestNameAndFunc t54 =
    { 
        "testRemove_RemoveOneElementPresentInList_ListSizeIsDecreasedByOne", 
        testRemove_RemoveOneElementPresentInList_ListSizeIsDecreasedByOne
    };
    ListTestCase::allTests.push_back(t54);
    TestNameAndFunc t55 =
    { 
        "testRemove_RemoveValueFromListThatIsPresentedInListSeveralTimes_ResultListIsTheSameAsInitialListButWithoutValuesInIt", 
        testRemove_RemoveValueFromListThatIsPresentedInListSeveralTimes_ResultListIsTheSameAsInitialListButWithoutValuesInIt
    };
    ListTestCase::allTests.push_back(t55);
    TestNameAndFunc t56 =
    { 
        "testRemove_RemoveValueThatIsNotInAList_ListMustBeTheSameAsBeforeRemoval", 
        testRemove_RemoveValueThatIsNotInAList_ListMustBeTheSameAsBeforeRemoval
    };
    ListTestCase::allTests.push_back(t56);
    TestNameAndFunc t57 =
    { 
        "testRemove_RemoveValueFromListContainingValuesOnly_ListIsEmpty", 
        testRemove_RemoveValueFromListContainingValuesOnly_ListIsEmpty
    };
    ListTestCase::allTests.push_back(t57);
    TestNameAndFunc t58 =
    { 
        "testRemoveIf_RemoveTheOnlyFiveFromList_ListSizeIsDecreasedByOne", 
        testRemoveIf_RemoveTheOnlyFiveFromList_ListSizeIsDecreasedByOne
    };
    ListTestCase::allTests.push_back(t58);
    TestNameAndFunc t59 =
    { 
        "testRemoveIf_RemoveElementFromListThatIsPresentedInListSeveralTimes_ResultListIsTheSameAsInitialListButWithoutElementsInIt", 
        testRemoveIf_RemoveElementFromListThatIsPresentedInListSeveralTimes_ResultListIsTheSameAsInitialListButWithoutElementsInIt
    };
    ListTestCase::allTests.push_back(t59);
    TestNameAndFunc t60 =
    { 
        "testRemoveIf_RemoveElementThatIsNotInAList_ListMustBeTheSameAsBeforeRemoval", 
        testRemoveIf_RemoveElementThatIsNotInAList_ListMustBeTheSameAsBeforeRemoval
    };
    ListTestCase::allTests.push_back(t60);
    TestNameAndFunc t61 =
    { 
        "testRemoveIf_RemoveElementsFromListContainingElementsSubjectToRemovalOnly_ListIsEmpty", 
        testRemoveIf_RemoveElementsFromListContainingElementsSubjectToRemovalOnly_ListIsEmpty
    };
    ListTestCase::allTests.push_back(t61);
    TestNameAndFunc t62 =
    { 
        "testUniqueNoParam_CallUniqueOnSortedList_ListWithUniqueElements", 
        testUniqueNoParam_CallUniqueOnSortedList_ListWithUniqueElements
    };
    ListTestCase::allTests.push_back(t62);
    TestNameAndFunc t63 =
    { 
        "testUniqueNoParam_CallUniqueOnListFilledWithSameElements_ListWithOneElement", 
        testUniqueNoParam_CallUniqueOnListFilledWithSameElements_ListWithOneElement
    };
    ListTestCase::allTests.push_back(t63);
    TestNameAndFunc t64 =
    { 
        "testUniqueNoParam_CallUniqueOnListWithUniquesElements_ResultListIsEqualToInitialList", 
        testUniqueNoParam_CallUniqueOnListWithUniquesElements_ResultListIsEqualToInitialList
    };
    ListTestCase::allTests.push_back(t64);
    TestNameAndFunc t65 =
    { 
        "testUniquePredicate_CallUniqueOnSortedList_ListWithUniqueElements", 
        testUniquePredicate_CallUniqueOnSortedList_ListWithUniqueElements
    };
    ListTestCase::allTests.push_back(t65);
    TestNameAndFunc t66 =
    { 
        "testUniquePredicate_CallUniqueOnListFilledWithSameElements_ListWithOneElement", 
        testUniquePredicate_CallUniqueOnListFilledWithSameElements_ListWithOneElement
    };
    ListTestCase::allTests.push_back(t66);
    TestNameAndFunc t67 =
    { 
        "testUniquePredicate_CallUniqueOnListWithUniquesElements_ResultListIsEqualToInitialList", 
        testUniquePredicate_CallUniqueOnListWithUniquesElements_ResultListIsEqualToInitialList
    };
    ListTestCase::allTests.push_back(t67);
    TestNameAndFunc t68 =
    { 
        "testMergeNoPredicate_MergeToSortedLists_SourceListIsEmpty", 
        testMergeNoPredicate_MergeToSortedLists_SourceListIsEmpty
    };
    ListTestCase::allTests.push_back(t68);
    TestNameAndFunc t69 =
    { 
        "testMergeNoPredicate_MergeTwoSortedLists_ResultListContainsAllElemenetsFromSourceAndTargetAndElementsAreSorted", 
        testMergeNoPredicate_MergeTwoSortedLists_ResultListContainsAllElemenetsFromSourceAndTargetAndElementsAreSorted
    };
    ListTestCase::allTests.push_back(t69);
    TestNameAndFunc t70 =
    { 
        "testMergeNoPredicate_MergeTwoEmptyLists_ResultListIsEmpty", 
        testMergeNoPredicate_MergeTwoEmptyLists_ResultListIsEmpty
    };
    ListTestCase::allTests.push_back(t70);
    TestNameAndFunc t71 =
    { 
        "testMergeNoPredicate_MergeEmptySourceAnsNonEmptyTarget_ListContainsAllSortedElementsFromSource", 
        testMergeNoPredicate_MergeEmptySourceAnsNonEmptyTarget_ListContainsAllSortedElementsFromSource
    };
    ListTestCase::allTests.push_back(t71);
    TestNameAndFunc t72 =
    { 
        "testMergeNoPredicate_SrcFirstElIsGreaterThenTgtLastEl_ElsOfSrcPlacedAfterAllElsOfTarget", 
        testMergeNoPredicate_SrcFirstElIsGreaterThenTgtLastEl_ElsOfSrcPlacedAfterAllElsOfTarget
    };
    ListTestCase::allTests.push_back(t72);
    TestNameAndFunc t73 =
    { 
        "testMergeNoPredicate_SrcElementsAreEqualtToTargetElements_ListIncludingAllElementsFromSrcAndTgt", 
        testMergeNoPredicate_SrcElementsAreEqualtToTargetElements_ListIncludingAllElementsFromSrcAndTgt
    };
    ListTestCase::allTests.push_back(t73);
    TestNameAndFunc t74 =
    { 
        "testMergeNoPredicate_SrcElementsAreLessTHenTargetElements_ListIncludingWhereFirstGoTargetSrcELementsAndThenTgtElements", 
        testMergeNoPredicate_SrcElementsAreLessTHenTargetElements_ListIncludingWhereFirstGoTargetSrcELementsAndThenTgtElements
    };
    ListTestCase::allTests.push_back(t74);
    TestNameAndFunc t75 =
    { 
        "testMergePredicate_MergeTwoSortedLists_ResultListContainsAllElemenetsFromSourceAndTargetAndElementsAreSorted", 
        testMergePredicate_MergeTwoSortedLists_ResultListContainsAllElemenetsFromSourceAndTargetAndElementsAreSorted
    };
    ListTestCase::allTests.push_back(t75);
    TestNameAndFunc t76 =
    { 
        "testMergePredicate_MergeTwoListsOfStrings_ResultListContainsAllElemenetsFromSourceAndTargetAndElementsAreSorted", 
        testMergePredicate_MergeTwoListsOfStrings_ResultListContainsAllElemenetsFromSourceAndTargetAndElementsAreSorted
    };
    ListTestCase::allTests.push_back(t76);
    TestNameAndFunc t77 =
    { 
        "testSortNoPredicate_AlreadySortedList_ListEqualToUsortedList", 
        testSortNoPredicate_AlreadySortedList_ListEqualToUsortedList
    };
    ListTestCase::allTests.push_back(t77);
    TestNameAndFunc t78 =
    { 
        "testSortNoPredicate_OneElementList_ListEqualToInitialList", 
        testSortNoPredicate_OneElementList_ListEqualToInitialList
    };
    ListTestCase::allTests.push_back(t78);
    TestNameAndFunc t79 =
    { 
        "testSortNoPredicate_SortedListWithOneElAtWrongPosition_AllElementsSorted", 
        testSortNoPredicate_SortedListWithOneElAtWrongPosition_AllElementsSorted
    };
    ListTestCase::allTests.push_back(t79);
    TestNameAndFunc t80 =
    { 
        "testSortNoPredicate_SortedListWithOneElAtWrongPosition_ElementMustBeMovedToFirstPositionListIsSorted", 
        testSortNoPredicate_SortedListWithOneElAtWrongPosition_ElementMustBeMovedToFirstPositionListIsSorted
    };
    ListTestCase::allTests.push_back(t80);
    TestNameAndFunc t81 =
    { 
        "testSortNoPredicate_EmptyList_ListIsUnchanged", 
        testSortNoPredicate_EmptyList_ListIsUnchanged
    };
    ListTestCase::allTests.push_back(t81);
    TestNameAndFunc t82 =
    { 
        "testSortNoPredicate_UnsortedListOfTenElements_SortedListOfTenElements", 
        testSortNoPredicate_UnsortedListOfTenElements_SortedListOfTenElements
    };
    ListTestCase::allTests.push_back(t82);
    
    
    TestNameAndFunc t83 =
    { 
        "testSortPredicate_AlreadySortedList_ListEqualToUsortedList", 
        testSortPredicate_AlreadySortedList_ListEqualToUsortedList
    };
    ListTestCase::allTests.push_back(t83);
    TestNameAndFunc t84 =
    { 
        "testSortPredicate_OneElementList_ListEqualToInitialList", 
        testSortPredicate_OneElementList_ListEqualToInitialList
    };
    ListTestCase::allTests.push_back(t84);
    TestNameAndFunc t85 =
    { 
        "testSortPredicate_SortedListWithOneElAtWrongPosition_AllElementsSorted", 
        testSortPredicate_SortedListWithOneElAtWrongPosition_AllElementsSorted
    };
    ListTestCase::allTests.push_back(t85);
    TestNameAndFunc t86 =
    { 
        "testSortPredicate_SortedListWithOneElAtWrongPosition_ElementMustBeMovedToFirstPositionListIsSorted", 
        testSortPredicate_SortedListWithOneElAtWrongPosition_ElementMustBeMovedToFirstPositionListIsSorted
    };
    ListTestCase::allTests.push_back(t86);
    TestNameAndFunc t87 =
    { 
        "testSortPredicate_EmptyList_ListIsUnchanged", 
        testSortPredicate_EmptyList_ListIsUnchanged
    };
    ListTestCase::allTests.push_back(t87);
    TestNameAndFunc t88 =
    { 
        "testSortPredicate_UnsortedListOfTenElements_SortedListOfTenElements", 
        testSortPredicate_UnsortedListOfTenElements_SortedListOfTenElements
    };
    ListTestCase::allTests.push_back(t88);
    
    TestNameAndFunc t89 =
    { 
        "testReverse_EmptyList_EmptyList", 
        testReverse_EmptyList_EmptyList
    };
    ListTestCase::allTests.push_back(t89);
    TestNameAndFunc t90 =
    { 
        "testReverse_ListOfFiveInts_ReversedListOfFiveInts", 
        testReverse_ListOfFiveInts_ReversedListOfFiveInts
    };
    ListTestCase::allTests.push_back(t90);
    TestNameAndFunc t91 =
    { 
        "testReverse_ListWithTwoInts_ReversedListOfTwoInts", 
        testReverse_ListWithTwoInts_ReversedListOfTwoInts
    };
    ListTestCase::allTests.push_back(t91);
    TestNameAndFunc t92 =
    { 
        "testReverse_ListWithOneInt_UnchangedList", 
        testReverse_ListWithOneInt_UnchangedList
    };
    ListTestCase::allTests.push_back(t92);
    TestNameAndFunc t93 =
    { 
        "testEqualityOpGlobal_ListsOfEqualElementsOnEqualPositionsOfEqualSizes_ReturnsTrue", 
        testEqualityOpGlobal_ListsOfEqualElementsOnEqualPositionsOfEqualSizes_ReturnsTrue
    };
    ListTestCase::allTests.push_back(t93);
    TestNameAndFunc t94 =
    { 
        "testEqualityOpGlobal_ListsOfEqualElementsOnTheSamePostionsButWithDifferentSizes_ReturnFalse", 
        testEqualityOpGlobal_ListsOfEqualElementsOnTheSamePostionsButWithDifferentSizes_ReturnFalse
    };
    ListTestCase::allTests.push_back(t94);
    TestNameAndFunc t95 =
    { 
        "testNotEqualityOpGlobal_ListsOfEqualElementsOnTheSamePostionsButWithDifferentSizes_ReturnTrue", 
        testNotEqualityOpGlobal_ListsOfEqualElementsOnTheSamePostionsButWithDifferentSizes_ReturnTrue
    };
    ListTestCase::allTests.push_back(t95);
    TestNameAndFunc t96 =
    { 
        "testLessOpGlobal_TwoListsEqualExceptLastElmenetsLastOfFirstListIsLess_ReturnsTrue", 
        testLessOpGlobal_TwoListsEqualExceptLastElmenetsLastOfFirstListIsLess_ReturnsTrue
    };
    ListTestCase::allTests.push_back(t95);
    TestNameAndFunc t97 =
    { 
        "testLessOpGlobal_TwoListsHaveSameElementsInOrderAndValueFromStartTillFirsListSizeSecondListIsLonger_ReturnsTrue", 
        testLessOpGlobal_TwoListsHaveSameElementsInOrderAndValueFromStartTillFirsListSizeSecondListIsLonger_ReturnsTrue
    };
    ListTestCase::allTests.push_back(t97);
    TestNameAndFunc t98 =
    { 
        "testLessOpGlobal_TwoListsEqualExceptLastElmenetsLastOfSeconfListIsGreater_ReturnsFalse", 
        testLessOpGlobal_TwoListsEqualExceptLastElmenetsLastOfSeconfListIsGreater_ReturnsFalse
    };
    ListTestCase::allTests.push_back(t98);
    
    
    TestNameAndFunc t99 =
    { 
        "testLessOrEqual_TwoEqualLists_ReturnsTrue", 
        testLessOrEqual_TwoEqualLists_ReturnsTrue
    };
    ListTestCase::allTests.push_back(t99);
    TestNameAndFunc t100 =
    { 
        "testLessOrEqual_FirstListIsLessThenSecond_ReturnsTrue", 
        testLessOrEqual_FirstListIsLessThenSecond_ReturnsTrue
    };
    ListTestCase::allTests.push_back(t100);
    TestNameAndFunc t101 =
    { 
        "testLessOrEqual_FirstListIsGreaterThenSecond_RerurnsFalse", 
        testLessOrEqual_FirstListIsGreaterThenSecond_RerurnsFalse
    };
    ListTestCase::allTests.push_back(t101);
    TestNameAndFunc t102 =
    { 
        "testGlobalSwap_SwapTwoDifferentListsOfInts_FirstMustBeEqualCopyOfSecondBeforeSwapAndViceVersa", 
        testGlobalSwap_SwapTwoDifferentListsOfInts_FirstMustBeEqualCopyOfSecondBeforeSwapAndViceVersa
    };
    ListTestCase::allTests.push_back(t102);
    TestNameAndFunc t103 =
    { 
        "testGlobalSwap_SwapTwoDifferentListsOfInts_IteratorOfFirstMustNowPointToElementOfSecond", 
        testGlobalSwap_SwapTwoDifferentListsOfInts_IteratorOfFirstMustNowPointToElementOfSecond
    };
    ListTestCase::allTests.push_back(t103);
}

void ListTestCase::run()
{
    initTests();
    runAllTests();
}

/*
** --------------------------------- TEST_FUNCTIONS ----------------------------
*/

//DONE
void ListTestCase::testFillConstructorCreatesListEqualToListOfTenIntsWithOneValue()
{
    ft::list<int> actualList(10, 1);
    std::list<int> expectedList(10, 1);

    int result = std::equal(actualList.begin(), actualList.end(), expectedList.begin());
    assertTrue(result);
}

//DONE
void ListTestCase::testRangeConstructorInitializesListWithRangeStrings()
{
    std::list<std::string> rangeSource;
    rangeSource.push_back("one");
    rangeSource.push_back("small");
    rangeSource.push_back("step");
    rangeSource.push_back("for");
    rangeSource.push_back("a");
    rangeSource.push_back("man.");
    std::list<std::string> expectedList(rangeSource.begin(), rangeSource.end());
    ft::list<std::string> actualList(rangeSource.begin(), rangeSource.end());

    bool are_made_of_same_elements = std::equal(actualList.begin(), actualList.end(), expectedList.begin());
    bool are_of_the_same_size = (expectedList.size() == actualList.size());
    assertTrue(are_made_of_same_elements);
    assertTrue(are_of_the_same_size);
}

//DONE
void ListTestCase::testCopyConstructedListIsEqualToSourceList()
{
    ft::list<int> source;
    for (int i = 0; i < 20; i++) source.push_back(i);
    
    ft::list<int> copy(source);
    
    bool are_made_of_same_elements = std::equal(source.begin(), source.end(), copy.begin());
    bool are_of_the_same_size = (source.size() == copy.size());
    assertTrue(are_made_of_same_elements);
    assertTrue(are_of_the_same_size);
}

//DONE
void ListTestCase::testCopyConstructedListsBecomesDifferentAfterElementsOfSourceAreChanged()
{
    ft::list<int> source;
    for (int i = 0; i < 20; i++) source.push_back(i);
    
    ft::list<int> copy(source);
    
    source.push_back(12312);
    *(source.begin()) = 9999;

    bool are_made_of_same_elements = std::equal(source.begin(), source.end(), copy.begin());
    bool are_of_the_same_size = (source.size() == copy.size());
    assertFalse(are_made_of_same_elements);
    assertFalse(are_of_the_same_size);
}

//DONE
void ListTestCase::testListAfterAssignationIsEqualInSizeAndElementsToSourceList()
{
    ft::list<int> source;
    for (int i = 0; i < 20; i++) 
        source.push_back(i);
    
    ft::list<int> copy;
    copy = source;
    bool are_made_of_same_elements = std::equal(source.begin(), source.end(), copy.begin());
    bool are_of_the_same_size = (source.size() == copy.size());
    assertTrue(are_made_of_same_elements);
    assertTrue(are_of_the_same_size);
}

//DONE
void ListTestCase::testListCreatedByAssignationBecomesDefferentToSourceAfterSourceIsChanged()
{
    //create source list
    ft::list<int> source;
    for (int i = 0; i < 20; i++) 
        source.push_back(i);
    
    //create target list by assignation
    ft::list<int> copy;
    copy = source;
    //check if taget list is equal to source after assignation
    bool are_made_of_same_elements_before_change = std::equal(source.begin(), source.end(), copy.begin());
    bool are_of_the_same_size_before_change = (source.size() == copy.size());
    assertTrue(are_made_of_same_elements_before_change);
    assertTrue(are_of_the_same_size_before_change);
    
    //change source list
    source.push_back(12312);
    *(source.begin()) = 9999;
    
    //check if lists are different after source is changed
    bool are_made_of_same_elements_after_change = std::equal(source.begin(), source.end(), copy.begin());
    bool are_of_the_same_size_after_change = (source.size() == copy.size());
    assertFalse(are_made_of_same_elements_after_change);
    assertFalse(are_of_the_same_size_after_change);
}

//DONE
void ListTestCase::testListsEmptyReturnsTrueAfterCreationWithDefaultInitializer()
{
    //check empty() on empty list
    ft::list<std::string> emptyList;
    int result = emptyList.empty();
    assertTrue(result);
}

//DONE
void ListTestCase::testListEmptyMethodReturnsFalseAfterAdditionOfOneElementToEmptyList()
{
    //check empty() on empty list
    ft::list<std::string> emptyList;
    bool resultEmpty = emptyList.empty();
    assertTrue(resultEmpty);
    //check empty() on not empty list
    emptyList.push_back(std::string("Hello"));
    bool resultNotEmpty = emptyList.empty();
    assertFalse(resultNotEmpty);
    std::list<int> l;
    ft::list<int> l1;
}

//DONE
void ListTestCase::testGetFrontElemenWhichIsStringHello()
{
    ft::list<std::string> mylist;
    mylist.push_back("Hello");
    assertEqual(mylist.front(), std::string("Hello"));
}
//DONE
void ListTestCase::testSetFirstElementFromStringHelloToGoodbye()
{
    ft::list<std::string> mylist;
    mylist.push_back("Hello");
    assertEqual(mylist.front(), std::string("Hello"));
    mylist.front() = std::string("Goodbye");
    assertEqual(mylist.front(), std::string("Goodbye"));
}
//DONE
void ListTestCase::testBackMethodSetLastElementToFiveAndCheckItIsFive()
{
    ft::list<int> l;
    l.push_back(123123);
    l.back() = 5;
    assertEqual(l.front(), l.back());
    assertEqual(l.back(), 5);
}
//DONE
void ListTestCase::test_AssignRange_AssignSameRangeToSTDListAndFTList_ListsEqualInSizeAndElements()
{
    int sourceContainer[5] = {2, 3, 5, 1, 2};
    std::list<int> expectedList;
    ft::list<int> actualList;

    expectedList.assign(sourceContainer, sourceContainer + 5);
    actualList.assign(sourceContainer, sourceContainer + 5);

    size_t sizeExpected = expectedList.size();
    size_t sizeActual = actualList.size();
    bool areElementsEqual = std::equal(expectedList.begin(), expectedList.end(), actualList.begin());
    assertEqual(sizeExpected, sizeActual);
    assertTrue(areElementsEqual);
}
//DONE
void ListTestCase::test_AssignRange_AssignEmptyRangeToSTDListAndFTList_ListsEqualInSIzeAndElements()
{
    int sourceContainer[5] = {2, 3, 5, 1, 2};
    std::list<int> expectedList;
    ft::list<int> actualList;

    expectedList.assign(sourceContainer, sourceContainer);
    actualList.assign(sourceContainer, sourceContainer);

    size_t sizeExpected = expectedList.size();
    size_t sizeActual = actualList.size();
    bool areElementsEqual = std::equal(expectedList.begin(), expectedList.end(), actualList.begin());
    assertEqual(sizeExpected, sizeActual);
    assertTrue(areElementsEqual);
}
//DONE
void ListTestCase::test_AssignRange_AssignRangeWichIsBiggerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements()
{
    int sourceContainer[5] = {2, 3, 5, 1, 2};
    std::list<int> expectedList;
    ft::list<int> actualList;

    expectedList.push_back(1);
    expectedList.push_back(1);
    expectedList.push_back(1);
    actualList.push_back(1);
    actualList.push_back(1);
    actualList.push_back(1);
    
    expectedList.assign(sourceContainer, sourceContainer + 5);
    actualList.assign(sourceContainer, sourceContainer + 5);

    size_t sizeExpected = expectedList.size();
    size_t sizeActual = actualList.size();
    bool areElementsEqual = std::equal(expectedList.begin(), expectedList.end(), actualList.begin());
    assertEqual(sizeExpected, sizeActual);
    assertTrue(areElementsEqual);
}
//DONE
void ListTestCase::test_AssignRange_AssignRangeWichIsSmallerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements()
{
    int sourceContainer[5] = {2, 3, 5, 1, 2};
    std::list<int> expectedList;
    ft::list<int> actualList;

    expectedList.push_back(1);
    expectedList.push_back(1);
    expectedList.push_back(1);
    expectedList.push_back(1);
    expectedList.push_back(1);
    expectedList.push_back(1);
    actualList.push_back(1);
    actualList.push_back(1);
    actualList.push_back(1);
    actualList.push_back(1);
    actualList.push_back(1);
    actualList.push_back(1);

    expectedList.assign(sourceContainer, sourceContainer + 5);
    actualList.assign(sourceContainer, sourceContainer + 5);

    size_t sizeExpected = expectedList.size();
    size_t sizeActual = actualList.size();
    bool areElementsEqual = std::equal(expectedList.begin(), expectedList.end(), actualList.begin());
    assertEqual(sizeExpected, sizeActual);
    assertTrue(areElementsEqual);
}

//CONSTRUCTION
void ListTestCase::test_AssignFill_AssignSameRangeToSTDListAndFTList_ListsEqualInSizeAndElements()
{
    std::list<int> expectedList;
    ft::list<int> actualList;

    expectedList.assign(7, 100);
    actualList.assign(7, 100);

    size_t sizeExpected = expectedList.size();
    size_t sizeActual = actualList.size();
    bool areElementsEqual = std::equal(expectedList.begin(), expectedList.end(), actualList.begin());
    assertEqual(sizeExpected, sizeActual);
    assertTrue(areElementsEqual);
}
//CONSTRUCTION
void ListTestCase::test_AssignFill_AssignEmptyRangeToSTDListAndFTList_ListsEqualInSIzeAndElements()
{
    std::list<int> expectedList;
    ft::list<int> actualList;

    expectedList.assign(0, 100);
    actualList.assign(0, 100);

    size_t sizeExpected = expectedList.size();
    size_t sizeActual = actualList.size();
    bool areElementsEqual = std::equal(expectedList.begin(), expectedList.end(), actualList.begin());
    assertEqual(sizeExpected, sizeActual);
    assertTrue(areElementsEqual);
}
//CONSTRUCTION
void ListTestCase::test_AssignFill_AssignRangeWichIsBiggerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements()
{
    std::list<int> expectedList;
    ft::list<int> actualList;

    expectedList.push_back(1);
    expectedList.push_back(1);
    expectedList.push_back(1);
    actualList.push_back(1);
    actualList.push_back(1);
    actualList.push_back(1);
    
    expectedList.assign(7, 100);
    actualList.assign(7, 100);

    size_t sizeExpected = expectedList.size();
    size_t sizeActual = actualList.size();
    bool areElementsEqual = std::equal(expectedList.begin(), expectedList.end(), actualList.begin());
    assertEqual(sizeExpected, sizeActual);
    assertTrue(areElementsEqual);
}
//CONSTRUCTION
void ListTestCase::test_AssignFill_AssignRangeWichIsSmallerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements()
{
    std::list<std::string> expectedList;
    ft::list<std::string> actualList;

    expectedList.push_back("h");
    expectedList.push_back("h");
    expectedList.push_back("h");
    expectedList.push_back("h");
    expectedList.push_back("h");
    expectedList.push_back("h");
    actualList.push_back("h");
    actualList.push_back("h");
    actualList.push_back("h");
    actualList.push_back("h");
    actualList.push_back("h");
    actualList.push_back("h");

    expectedList.assign(3, std::string("Hello"));
    actualList.assign(3, std::string("Hello"));

    size_t sizeExpected = expectedList.size();
    size_t sizeActual = actualList.size();
    bool areElementsEqual = std::equal(expectedList.begin(), expectedList.end(), actualList.begin());
    assertEqual(sizeExpected, sizeActual);
    assertTrue(areElementsEqual);
}

//DONE
void ListTestCase::testPushFront_CreateListAddOneElement_SizeIncreasesByOneAndFrontMethodReturnsAddedElement()
{
    //Arrange
    ft::list<std::string> l(10, std::string("Hello"));
    std::string firstElementBeforePushFront = l.front();
    size_t lengthBeforePushFront = l.size();

    //Act
    l.push_front("Goodbye");
    //Assert
    size_t lengthBeforAfterDifferenceActual = l.size() - lengthBeforePushFront;
    size_t lengthBeforAfterDifferenceExpected = 1;
    assertEqual(lengthBeforAfterDifferenceExpected, lengthBeforAfterDifferenceActual);
    std::string expectedFirstElement = std::string("Goodbye");
    std::string actualFirstElement = l.front();
    assertEqual(expectedFirstElement, actualFirstElement);
}
//DONE
void ListTestCase::testPopFront_CreateListRemoveOneElement_SizeDecreasesbyOneAndFrontElemenIsDfferent()
{
    //Arrange
    ft::list<std::string> l;
    l.push_back("Hello");
    l.push_back("GoodBye");

    //Act
    std::string firstElBeforePop = l.front();
    size_t sizeBeforePop = l.size();
    l.pop_front();

    //Assert
    std::string firstElAfterPop = l.front();
    size_t sizeAfterPop = l.size();
    size_t expectedSizeDecrease = 1;
    assertEqual(expectedSizeDecrease, sizeBeforePop - sizeAfterPop);
    assertFalse(firstElAfterPop == firstElBeforePop);
}

//DONE
void ListTestCase::testPushBack_AddOneElementToList_SizeIncreasesByOneAndLastElementBecomesTheOneAdded()
{
    //Arange
    ft::list<int> l;
    
    size_t sizeBeforPush = l.size();
    
    //Act
    int elementToAdd = 999;
    l.push_back(elementToAdd);
    size_t sizeAfterPush = l.size();
    assertTrue((sizeAfterPush - sizeBeforPush) == 1);
    assertTrue(l.back() == elementToAdd);
}
//CONSTRUCTION
void ListTestCase::testPopBack_PopOneElement_SizeMustDecreaseByOneBackElementMustBeEqualToElementBeforeLast()
{
    //arrange
    ft::list<int> l;
    int elementBeforeLast = 20;
    l.push_back(elementBeforeLast);
    l.push_back(30);
    size_t sizeBeforePop = l.size();

    //Act
    l.pop_back();
    assertTrue((sizeBeforePop - l.size()) == 1);
    assertEqual(elementBeforeLast, l.back());
}
//DONE
void ListTestCase::testPopBack_PopAllElementsFromListInALoop_ResultListMustBeEmpty()
{
    //arrange
    ft::list<int> l;
    size_t numberOfElementsToAddToList = 100;
    for (size_t i = 0; i < numberOfElementsToAddToList; i++)
        l.push_back(i);
    size_t sizeBeforePop = l.size();
    //Act
    for (;l.size() != 0;)
        l.pop_back();
    //assert
    assertTrue(sizeBeforePop == numberOfElementsToAddToList);
    assertTrue(l.size() == 0);
}
//DONE
void ListTestCase::testIsertSingleElement_RusultListAndRetrnValueMustBeTheSameAsOfSTDList()
{
    //arrange
    ft::list<int> ftList;
    std::list<int> stdList;
    for (int i = 0; i < 20; i++)
    {
        ftList.push_back(i);
        stdList.push_back(i);
    }
    bool areStdAndFtListsEqualBeforeInsert = std::equal(stdList.begin(), stdList.end(), ftList.begin());
    ft::list<int>::iterator ftInsertPositionIt = ftList.begin();
    std::list<int>::iterator stdInsertPositionIt = stdList.begin();
    ftInsertPositionIt++;
    ftInsertPositionIt++;
    ftInsertPositionIt++;
    stdInsertPositionIt++;
    stdInsertPositionIt++;
    stdInsertPositionIt++;
    bool areFtAndStdInsertPosisionIteratorsAtTheSamePosition = (*ftInsertPositionIt == *stdInsertPositionIt);
    //Act
    int elementToIsert = 999;
    ft::list<int>::iterator ftItreturn = ftList.insert(ftInsertPositionIt, elementToIsert);
    std::list<int>::iterator stdItreturn = stdList.insert(stdInsertPositionIt, elementToIsert);
    //Assert
    bool areFtAndStdListsEqualAfterInsert = std::equal(stdList.begin(), stdList.end(), ftList.begin());
    assertTrue(areStdAndFtListsEqualBeforeInsert);
    assertTrue(areFtAndStdInsertPosisionIteratorsAtTheSamePosition);
    assertTrue(areFtAndStdListsEqualAfterInsert);
    assertEqual(*ftItreturn, *stdItreturn);
}
//DONE
void ListTestCase::testInsertSingleElement_InsertMultipleElementsInLoop_ResultListIsEqualToStdListEffectedBySameActions()
{
    //Arrange
    ft::list<int> ftList;
    std::list<int> stdList;
    //Act
    for (int i = 0; i < 100; i++)
    {
        ftList.insert(ftList.end(), i);
        stdList.insert(stdList.end(), i);
    }
    //Assert
    assertTrue(std::equal(ftList.begin(), ftList.end(), stdList.begin()));
}
//DONE
void ListTestCase::testInsertFill_InsertMultipleElemens_ResultListMustBeEqualToStdListEffectedBySameActions()
{
    //Arrange
    ft::list<int> ftList;
    std::list<int> stdList;
    //Act
    size_t numberOfElementsToFill = 100;
    int fillElement = 999;
    for (int i = 0; i < 100; i++)
    {
        ftList.insert(ftList.end(), numberOfElementsToFill, fillElement);
        stdList.insert(stdList.end(), numberOfElementsToFill, fillElement);
    }
    //Assert
    assertTrue(std::equal(ftList.begin(), ftList.end(), stdList.begin()));
}
//DONE
void ListTestCase::testIsertRange_InsertRange_ResultListMustBeEqualToStdListEffectedBySameActions()
{
    //Arrange
    ft::list<int> ftList;
    std::list<int> stdList;
    int srcOfRange[5] = {1, 5, 2, 3, 3};
    //Act
    ftList.insert(ftList.end(), srcOfRange, srcOfRange + 5);
    stdList.insert(stdList.end(), srcOfRange, srcOfRange + 5);
    //Assert
    assertTrue(std::equal(stdList.begin(), stdList.end(), ftList.begin()));
    assertEqual(ftList.size(), stdList.size());
}
//DONE
void ListTestCase::testEraseSingleElement_RemoveElement_ResulFtListMustIsEqualToStdListEffectedByTheSameActions()
{
    //Arrange
    std::list<int> stdList;
    ft::list<int> ftList;

    stdList.push_back(132);
    stdList.push_back(2);
    stdList.push_back(10);
    ftList.push_back(132);
    ftList.push_back(2);
    ftList.push_back(10);
    
    std::list<int>::iterator stdIt = stdList.begin();
    ft::list<int>::iterator  ftIt = ftList.begin();
    stdIt++;
    ftIt++;
    
    //Act
    stdList.erase(stdIt);
    ftList.erase(ftIt);
    
    //Assert
    assertTrue(std::equal(stdList.begin(), stdList.end(), ftList.begin()));
    assertEqual(stdList.size(), ftList.size());
}
//DONE
void ListTestCase::testEraseSingleElement_RemoveAllElementsFromListInALoop_ResultFtListMustIsEqualToStdListEffectedByTheSameActionsAndBothListsAreZeroSized()
{
    //Arrange
    std::list<int> stdList(10, 999);
    ft::list<int> ftList(10, 999);
    
    std::list<int>::iterator stdIt = stdList.begin();
    ft::list<int>::iterator  ftIt = ftList.begin();
    //Act
    while (stdList.size() != 0 && ftList.size() != 0)
    {
        stdIt = stdList.erase(stdIt);
        ftIt = ftList.erase(ftIt);
    }
    //Assert
    assertTrue(std::equal(ftList.begin(), ftList.end(), stdList.begin()));
    assertEqual(stdList.size(), ftList.size());
    assertTrue(stdList.empty());
    assertTrue(ftList.empty());
}
//DONE
void ListTestCase::testEraseSingleElement_RemoveLastElementFromList_RetunIsEndIterator()
{
    //Arrange
    ft::list<int> l;
    l.push_back(1);
    ft::list<int>::iterator itBegin = l.begin();
    ft::list<int>::iterator itEnd = l.end();
    //Act
    ft::list<int>::iterator itReturn = l.erase(itBegin);
    //Assert
    assertEqual(itReturn, itEnd); 
}
//DONE
void ListTestCase::testEraseRange_RemoveRangeOfElementsFromList_StdContainerEffectedByTheSameActionsIsEqualToFtListInElementsAndSize()
{
    //Arrange
    //crate to similar lists:: std ans ft
    size_t elementsNum = 99;
    int element = 10;
    std::list<int> stdList(elementsNum, element);
    ft::list<int> ftList(elementsNum, element);
    
    //create first and last iterators for std
    size_t positionOfFirstIt = 10;
    size_t positoinOfLastIt = 40;
    std::list<int>::iterator stdItFirst = stdList.begin();
    std::list<int>::iterator stdItLast = stdItFirst; 
    std::advance(stdItFirst, positionOfFirstIt);
    std::advance(stdItLast, positoinOfLastIt);
    
    //create first and last iterators for ft
    ft::list<int>::iterator ftItFirst = ftList.begin();
    ft::list<int>::iterator ftItLast = ftItFirst;
    std::advance(ftItFirst, positionOfFirstIt);
    std::advance(ftItLast, positoinOfLastIt);

    //Act
    stdList.erase(stdItFirst, stdItLast);
    ftList.erase(ftItFirst, ftItLast);

    //Assert
    assertTrue(std::equal(ftList.begin(), ftList.end(), stdList.begin()));
    assertEqual(ftList.size(), stdList.size());
}
//DONE
void ListTestCase::testEraseRange_RemoveRangeOfElementsFromList_ReturnsIteratorIsEqualToLastInputParameter()
{
    //Arrange
    size_t elementsNum = 99;
    int element = 10;
    ft::list<int> ftList(elementsNum, element);
    
    //create first and last iterators for ft
    size_t positionOfFirstIt = 10;
    size_t positoinOfLastIt = 40;
    ft::list<int>::iterator ftItFirst = ftList.begin();
    ft::list<int>::iterator ftItLast = ftItFirst;
    std::advance(ftItFirst, positionOfFirstIt);
    std::advance(ftItLast, positoinOfLastIt);

    //Act
    ft::list<int>::iterator ftItReturned = ftList.erase(ftItFirst, ftItLast);

    //Assert
    assertEqual(ftItReturned, ftItLast);
}
//DONE
void ListTestCase::testEraseRange_RemoveAllElements_ResultListIsEmpty()
{
    //Arrange
    size_t elementsNum = 99;
    int element = 10;
    ft::list<int> ftList(elementsNum, element);
    
    //create first and last iterators for ft
    ft::list<int>::iterator ftItFirst = ftList.begin();
    ft::list<int>::iterator ftItLast = ftItFirst;
    std::advance(ftItLast, elementsNum);

    //Act
    ftList.erase(ftItFirst, ftItLast);

    //Assert
    assertTrue(ftList.empty());
}
//DONE
void ListTestCase::testEraseRange_RemoveAllElements_ReturnIsEndIteratorOfList()
{
    //Arrange
    size_t elementsNum = 99;
    int element = 10;
    ft::list<int> ftList(elementsNum, element);
    
    //create first and last iterators for ft
    ft::list<int>::iterator ftItFirst = ftList.begin();
    ft::list<int>::iterator ftItLast = ftItFirst;
    std::advance(ftItLast, elementsNum);

    //Act
    ft::list<int>::iterator ftItReturned = ftList.erase(ftItFirst, ftItLast);

    //Assert
    assertEqual(ftItReturned, ftList.end());
}
//DONE
void ListTestCase::testSwap_SwapTwoDifferentListsOfInts_FirstMustBeEqualCopyOfSecondBeforeSwapAndViceVersa()
{
    //Aarange
    //create lists to swap
    ft::list<int> first(10, 99);
    ft::list<int> second(5, 66);
    //Create copies of lists to compare check results after swap
    ft::list<int> first_cpy = first;
    ft::list<int> second_cpy = second;
    //Act
    first.swap(second);
    //assert
    assertTrue(std::equal(first.begin(), first.end(), second_cpy.begin()));
    assertEqual(first.size(), second_cpy.size());
    assertTrue(std::equal(second.begin(), second.end(), first_cpy.begin()));
    assertEqual(second.size(), first_cpy.size());
}

//DONE
void ListTestCase::testSwap_SwapTwoDifferentListsOfInts_IteratorOfFirstMustNowPointToElementOfSecond()
{
    //Arrange
    //create lists to swap
    ft::list<std::string> first;
    first.push_back("one");
    first.push_back("two");
    first.push_back("three");
    ft::list<std::string> second;
    //create iterator to check if it is invalidated
    ft::list<std::string>::iterator it = first.begin();
    it++; // now points to "two"
    //Act
    first.swap(second);
    it++;
    //Assert
    assertEqual(*it, std::string("three"));
}
//GREEN
void ListTestCase::testResize_ResizeWithNSmallerThenListSize_ListSizeBecomesEqualToN()
{
    //Arrange
    ft::list<std::string> l(10, std::string("one"));
    size_t n = 5;
    //Act
    l.resize(n);
    //Assert
    assertEqual(l.size(), n);
}
//GREEN
void ListTestCase::testResize_ResizeWithNGreaterThenListSize_ListSizeBecomesEqualToN()
{
    //Arrange
    ft::list<std::string> l(10, std::string("one"));
    size_t n = 15;
    //Act
    l.resize(n);
    //Assert
    assertEqual(l.size(), n);
}

//GREEN
void ListTestCase::testResize_ResizeWithNGreaterThenListSizeNValueISProvided_AllNewElementsInListEqualToN()
{
    //Arrange
    size_t initialSize = 10;
    std::string fillValue = std::string("one");
    ft::list<std::string> l(initialSize, "two");
    size_t n = 15;
    //Act
    l.resize(n, fillValue);
    //Assert
    ft::list<std::string>::iterator it = l.begin();
    std::advance(it, initialSize);
    assertTrue(l.size() == n);
    for (; it != l.end(); it++)
        assertEqual(*it, fillValue);
}
//GREEN
void ListTestCase::testResize_ResizeWithNEqualToListSize_ListSizeIsEqualToSizeBeforeResize()
{
    //Arrange
    ft::list<std::string> l(10, std::string("one"));
    size_t listSizeBeforeResize = l.size();
    size_t n = 10;
    //Act
    l.resize(n);
    size_t listSizeAfterResize = l.size();
    //Assert
    assertEqual(listSizeBeforeResize, listSizeAfterResize);
}
//GREEN
void ListTestCase::testClear_ClearNonEmptyList_ListIsEmpty()
{
    //Arrange
    ft::list<int> l(10, 999);
    
    //Act
    l.clear();
    
    //Assert
    assertTrue(l.empty());
}
//RED
void ListTestCase::testSpliceAllElements_SpliceOneListIntoAnother_RusultListIsEqualInSizeAndElementsToStdListEffectdBySameActions()
{
    //Arrange
    std::list<int> stdList(10, 99);
    ft::list<int> ftList(10, 99);

    std::list<int> stdListSrc(5, 11);
    ft::list<int> ftListSrc(5, 11);

    //Act 
    stdList.splice(stdList.begin(), stdListSrc);
    ftList.splice(ftList.begin(), ftListSrc);
    //Assert
    assertEqual(stdList.size(), ftList.size());
    assertTrue(std::equal(stdList.begin(), stdList.end(), ftList.begin()));
}
//GREEN
void ListTestCase::testSpliceAllElements_SpliceOneListIntoAnother_SrcListIsEmpty()
{
    //Arrange
    ft::list<int> ftList(10, 99);

    ft::list<int> ftListSrc(5, 11);

    //Act 
    ftList.splice(ftList.begin(), ftListSrc);
    //Assert
    assertTrue(ftListSrc.empty());
}
//GREEN
void ListTestCase::testSpliceOneElement_SpliceOneElementToList_SrcListSizeIsDecreasedByOne()
{
    //Arrange
    ft::list<int> ftList(10, 99);

    ft::list<int> ftListSrc(5, 11);
    size_t initialSrcSize = ftListSrc.size();
    //Act 
    ftList.splice(++ftList.begin(), ftListSrc, ftListSrc.begin());
    //Assert
    assertTrue((initialSrcSize - ftListSrc.size()) == 1);
}
//GREEN
void ListTestCase::testSpliceOneElement_SpliceOneElementToList_TargetListSizeIsIncreasedByOne()
{
    //Arrange
    ft::list<int> ftList(10, 99);

    ft::list<int> ftListSrc(5, 11);
    size_t initialLstSize = ftList.size();
    //Act
    ftList.splice(++ftList.begin(), ftListSrc, ftListSrc.begin());
    //Assert
    assertTrue((ftList.size() - initialLstSize) == 1);
}
//GREEN
void ListTestCase::testSpliceOneElement_SpliceOneElementToList_PositionIteratorDecrementedByOneYeldsElementAdded()
{
    //Arrange
    ft::list<int> ftList(10, 99);

    ft::list<int> ftListSrc(5, 11);
    
    //Act
    ft::list<int>::iterator itSrc = ftListSrc.begin();
    ft::list<int>::iterator itPosition = ftList.begin();
    std::advance(itPosition, 3);
    ftList.splice(itPosition, ftListSrc, itSrc);
    //Assert
    assertTrue(*(--itPosition) == 11);
}
//GREEN
void ListTestCase::testSpliceOneElement_SpliceOneElementToEmptyList_PositionIteratorDecrementedByOneYeldsElementAdded()
{
    //Arrange
    ft::list<int> ftList;

    ft::list<int> ftListSrc(5, 11);
    
    //Act
    ft::list<int>::iterator itSrc = ftListSrc.begin();
    ft::list<int>::iterator itPosition = ftList.begin();
    ftList.splice(itPosition, ftListSrc, itSrc);
    //Assert
    assertTrue(*(--itPosition) == 11);
}
//GREEN
void ListTestCase::testSpliceOneElement_SpliceOneElementFromThisListRightNextToPosition_PositionIteratorDecrementedByOneYeldsElementAdded()
{
    //Arrange
    std::list<std::string> ftList;
    ftList.push_back("one");
    ftList.push_back("two");
    ftList.push_back("three");
    
    //Act
    std::list<std::string>::iterator itPosition = ftList.begin();
    std::advance(itPosition, 1);
    std::string el = *itPosition;
    std::list<std::string>::iterator itSrc = ftList.begin();
    ftList.splice(itPosition, ftList, itSrc);
    //Assert
    assertTrue(*(--itPosition) == std::string("one"));
    std::cout << std::endl;
}
//GREEN
void ListTestCase::testSpliceRange_SpliceRange_SrcListSizeIsDecreasedByRangeSize()
{
    //arange
    ft::list<int> target(10, 999);
    ft::list<int> source(10, 555);
    size_t srcSizeBeforeSplice = source.size();
    ft::list<int>::iterator first = source.begin();
    first++;
    ft::list<int>::iterator last = source.end();
    last--;
    ft::list<int>::iterator position = target.begin();
    std::advance(position, 3);
    size_t rangeSize = std::distance(first, last);
    //act
    target.splice(position, source, first, last);
    //Assert
    assertEqual(source.size(), srcSizeBeforeSplice - rangeSize);
}
//GREEN
void ListTestCase::testSpliceRange_SpliceRange_TargetSizeIsIncreasedByRangeSize()
{
    //arange
    ft::list<int> target(10, 999);
    ft::list<int> source(10, 555);
    size_t targetSizeBeforeSplice = target.size();
    ft::list<int>::iterator first = source.begin();
    first++;
    ft::list<int>::iterator last = source.end();
    last--;
    ft::list<int>::iterator position = target.begin();
    std::advance(position, 3);
    size_t rangeSize = std::distance(first, last);
    //act
    target.splice(position, source, first, last);
    //Assert
    assertEqual(target.size(), targetSizeBeforeSplice + rangeSize);
}
//GREEN
void ListTestCase::testSpliceRange_SpliceRange_TargetHasExpectedELements()
{
    //Arrange
    ft::list<std::string> target;
    target.push_back("one");
    target.push_back("two");
    target.push_back("three");
    ft::list<std::string> source;
    source.push_back("A");
    source.push_back("B");
    source.push_back("C");
    ft::list<std::string>::iterator first = source.begin();
    ft::list<std::string>::iterator last = source.end();
    ft::list<std::string>::iterator position = ++target.begin();
    ft::list<std::string> expectedTarget;
    expectedTarget.push_back("one");
    expectedTarget.push_back("A");
    expectedTarget.push_back("B");
    expectedTarget.push_back("C");
    expectedTarget.push_back("two");
    expectedTarget.push_back("three");
    //Act
    target.splice(position, source, first, last);
    //Assert
    assertEqual(expectedTarget.size(), target.size());
    assertTrue(std::equal(expectedTarget.begin(), expectedTarget.end(), target.begin()));
}
//GREEN
void ListTestCase::testSpliceRange_SpliceRangeToEmptyTarget_TargetHasExpectedELements()
{
    //Arrange
    ft::list<std::string> target;
    ft::list<std::string> source;
    source.push_back("A");
    source.push_back("B");
    source.push_back("C");
    ft::list<std::string>::iterator first = source.begin();
    ft::list<std::string>::iterator last = source.end();
    ft::list<std::string>::iterator position = target.begin();
    ft::list<std::string> expectedTarget;
    expectedTarget.push_back("A");
    expectedTarget.push_back("B");
    expectedTarget.push_back("C");
    //Act
    target.splice(position, source, first, last);
    //Assert
    assertEqual(expectedTarget.size(), target.size());
    assertTrue(std::equal(expectedTarget.begin(), expectedTarget.end(), target.begin()));
}
//GREEN
void ListTestCase::testRemove_RemoveOneElementPresentInList_ListSizeIsDecreasedByOne()
{
    //Arrange
    ft::list<int> l(1, 99);
    l.push_back(11);
    size_t sizeBeforeRemoval = l.size();
    //Act
    l.remove(99);
    //Assert
    size_t sizeDecrease = sizeBeforeRemoval - l.size();
    assertTrue(sizeDecrease == 1);
}
//GREEN
void ListTestCase::testRemove_RemoveValueFromListThatIsPresentedInListSeveralTimes_ResultListIsTheSameAsInitialListButWithoutValuesInIt()
{
    //Arrange
    ft::list<std::string> actualList;
    actualList.push_back("one");
    actualList.push_back("two");
    actualList.push_back("two");
    actualList.push_back("two");
    actualList.push_back("three");
    ft::list<std::string> expectedList;
    expectedList.push_back("one");
    expectedList.push_back("three");
    std::string valueToRemove("two");
    //Act
    actualList.remove(valueToRemove);
    //Assert
    bool result = 
    areEqualInSizeAndElements
    (
        actualList.begin(), actualList.end(), expectedList.begin(), expectedList.end()
    );
    assertTrue(result);
}
//GREEN
void ListTestCase::testRemove_RemoveValueThatIsNotInAList_ListMustBeTheSameAsBeforeRemoval()
{
    //Arrange
    ft::list<std::string> actualList;
    actualList.push_back("one");
    actualList.push_back("three");
    ft::list<std::string> expectedList;
    expectedList.push_back("one");
    expectedList.push_back("three");
    std::string valueToRemove("notInAListValue");
    //Act
    actualList.remove(valueToRemove);
    //Assert
    bool result = 
    areEqualInSizeAndElements
    (
        actualList.begin(), actualList.end(), expectedList.begin(), expectedList.end()
    );
    assertTrue(result);
}
//GREEN
void ListTestCase::testRemove_RemoveValueFromListContainingValuesOnly_ListIsEmpty()
{
    //Arrange
    ft::list<std::string> actualList;
    actualList.push_back("one");
    actualList.push_back("one");
    actualList.push_back("one");
    std::string valueToRemove("one");
    //Act
    actualList.remove(valueToRemove);
    //Assert
    assertTrue(actualList.empty());
}

static bool isFive(int n)
{
    return n == 5;
}
static bool isOdd(int n)
{
    return n % 2;
}
static bool hasIChar(const std::string &str)
{
    return str.find("i") != std::string::npos;
}

//GREEN
void ListTestCase::testRemoveIf_RemoveTheOnlyFiveFromList_ListSizeIsDecreasedByOne()
{
    //Arrange
    ft::list<int> l;
    l.push_back(11);
    l.push_back(5);
    l.push_back(12);
    size_t sizeBeforeRemoval = l.size();
    //Act
    l.remove_if(isFive);
    //Assert
    size_t sizeDecrease = sizeBeforeRemoval - l.size();
    assertTrue(sizeDecrease == 1);
}

//GREEN
void ListTestCase::testRemoveIf_RemoveElementFromListThatIsPresentedInListSeveralTimes_ResultListIsTheSameAsInitialListButWithoutElementsInIt()
{
    //Arrange
    ft::list<std::string> actual;
    actual.push_back("Life");
    actual.push_back("smile");
    actual.push_back("flower");
    ft::list<std::string> expected;
    expected.push_back("flower");
    //Act
    actual.remove_if(hasIChar);
    //Assert
    int result = areEqualInSizeAndElements(actual.begin(), actual.end(), expected.begin(), expected.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testRemoveIf_RemoveElementThatIsNotInAList_ListMustBeTheSameAsBeforeRemoval()
{
    //Arrange
    ft::list<int> actual;
    actual.push_back(1);
    actual.push_back(2);
    actual.push_back(3);
    ft::list<int> expected;
    expected.push_back(1);
    expected.push_back(2);
    expected.push_back(3);
    //Act
    actual.remove_if(isFive);
    //Assert
    int result = areEqualInSizeAndElements(actual.begin(), actual.end(), expected.begin(), expected.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testRemoveIf_RemoveElementsFromListContainingElementsSubjectToRemovalOnly_ListIsEmpty()
{
    //Arrange
    ft::list<int> actual;
    actual.push_back(1);
    actual.push_back(3);
    actual.push_back(5);
    //Act
    actual.remove_if(isOdd);
    //Assert
    assertTrue(actual.empty());
}
//GREEN
void ListTestCase::testUniqueNoParam_CallUniqueOnSortedList_ListWithUniqueElements()
{
    //Arrange
    ft::list<int> actual;
    actual.push_back(1);
    actual.push_back(1);
    actual.push_back(1);
    actual.push_back(2);
    actual.push_back(2);
    actual.push_back(5);
    actual.push_back(5);
    actual.push_back(5);
    ft::list<int> expectedList;
    expectedList.push_back(1);
    expectedList.push_back(2);
    expectedList.push_back(5);
    //Act
    actual.unique();
    //Assert
    bool result = areEqualInSizeAndElements(actual.begin(), actual.end(), expectedList.begin(), expectedList.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testUniqueNoParam_CallUniqueOnListFilledWithSameElements_ListWithOneElement()
{
    //Arrange
    ft::list<std::string> actual(5, std::string("Hello"));
    //Act
    actual.unique();
    //Assert
    assertTrue(actual.size() == 1);
}
//GREEN
void ListTestCase::testUniqueNoParam_CallUniqueOnListWithUniquesElements_ResultListIsEqualToInitialList()
{
    //Arrange
    ft::list<int> actual;
    actual.push_back(1);
    actual.push_back(2);
    actual.push_back(5);
    ft::list<int> expectedList;
    expectedList.push_back(1);
    expectedList.push_back(2);
    expectedList.push_back(5);
    //Act
    actual.unique();
    //Assert
    bool result = areEqualInSizeAndElements(actual.begin(), actual.end(), expectedList.begin(), expectedList.end());
    assertTrue(result);
}
static bool equal(int n1, int n2)
{
    return n1 == n2;
}
static bool bothStrStartWithSameChar(std::string s1, std::string s2)
{
    return (s1[0] == s2[0]);
}
//GREEN
void ListTestCase::testUniquePredicate_CallUniqueOnSortedList_ListWithUniqueElements()
{
    //Arrange
    ft::list<int> actual;
    actual.push_back(1);
    actual.push_back(1);
    actual.push_back(1);
    actual.push_back(2);
    actual.push_back(2);
    actual.push_back(5);
    actual.push_back(5);
    actual.push_back(5);
    ft::list<int> expectedList;
    expectedList.push_back(1);
    expectedList.push_back(2);
    expectedList.push_back(5);
    //Act
    actual.unique(equal);
    //Assert
    bool result = areEqualInSizeAndElements(actual.begin(), actual.end(), expectedList.begin(), expectedList.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testUniquePredicate_CallUniqueOnListFilledWithSameElements_ListWithOneElement()
{
    //Arrange
    ft::list<std::string> actual;
    actual.push_back("hello");
    actual.push_back("high");
    actual.push_back("hind");
    //Act
    actual.unique(bothStrStartWithSameChar);
    //Assert
    assertTrue(actual.size() == 1);
}
//GREEN
void ListTestCase::testUniquePredicate_CallUniqueOnListWithUniquesElements_ResultListIsEqualToInitialList()
{
    //Arrange
    ft::list<std::string> actual;
    actual.push_back("Hello");
    actual.push_back("bell");
    actual.push_back("slope");
    ft::list<std::string> expected = actual;
    //Act
    actual.unique(bothStrStartWithSameChar);
    //Assert
    int result = areEqualInSizeAndElements(actual.begin(), actual.end(), expected.begin(), expected.end());
    assertTrue(result);
}   
//GREEN
void ListTestCase::testMergeNoPredicate_MergeToSortedLists_SourceListIsEmpty()
{
    //Arrange
    ft::list<int> target;
    ft::list<int> source;
    source.push_back(1);
    source.push_back(2);
    source.push_back(3);
    target.push_back(5);
    target.push_back(5);
    target.push_back(5);
    //Act
    target.merge(source);
    //Assert
    assertTrue(source.empty());
}
//GREEN
void ListTestCase::testMergeNoPredicate_MergeTwoSortedLists_ResultListContainsAllElemenetsFromSourceAndTargetAndElementsAreSorted()
{
    //Arrange
    ft::list<int> target;
    ft::list<int> source;
    source.push_back(1);
    source.push_back(2);
    source.push_back(3);
    target.push_back(5);
    target.push_back(5);
    target.push_back(5);
    ft::list<int> expected;
    expected.push_back(1);
    expected.push_back(2);
    expected.push_back(3);
    expected.push_back(5);
    expected.push_back(5);
    expected.push_back(5);
    //Act
    target.merge(source);
    //Assert
    bool result = areEqualInSizeAndElements(target.begin(), target.end(), expected.begin(), expected.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testMergeNoPredicate_MergeTwoEmptyLists_ResultListIsEmpty()
{
    //Arrange
    ft::list<int> target;
    ft::list<int> source;
    //Act
    target.merge(source);
    //Assert
    assertTrue(target.empty());
}
//GREEN
void ListTestCase::testMergeNoPredicate_MergeEmptySourceAnsNonEmptyTarget_ListContainsAllSortedElementsFromSource()
{
    //Arrange
    ft::list<int> target;
    ft::list<int> source;
    target.push_back(5);
    target.push_back(5);
    target.push_back(5);
    ft::list<int> expected;
    expected.push_back(5);
    expected.push_back(5);
    expected.push_back(5);
    //Act
    target.merge(source);
    //Assert
    bool result = areEqualInSizeAndElements(target.begin(), target.end(), expected.begin(), expected.end());
    assertTrue(result);
}

//GREEN
void ListTestCase::testMergeNoPredicate_SrcFirstElIsGreaterThenTgtLastEl_ElsOfSrcPlacedAfterAllElsOfTarget()
{
    //Arrange
    ft::list<int> target;
    target.push_back(1);
    target.push_back(2);
    target.push_back(3);
    ft::list<int> source;
    source.push_back(6);
    source.push_back(7);
    source.push_back(8);
    ft::list<int> expected;
    expected.push_back(1);
    expected.push_back(2);
    expected.push_back(3);
    expected.push_back(6);
    expected.push_back(7);
    expected.push_back(8);
    //Act
    target.merge(source);
    //Assert
    bool result = areEqualInSizeAndElements(target.begin(), target.end(), expected.begin(), expected.end());
    assertTrue(result);
}

//GREEN
void ListTestCase::testMergeNoPredicate_SrcElementsAreEqualtToTargetElements_ListIncludingAllElementsFromSrcAndTgt()
{
    //Arrange
    ft::list<int> target;
    target.push_back(1);
    target.push_back(1);
    ft::list<int> source;
    source.push_back(1);
    source.push_back(1);
    ft::list<int> expected;
    expected.push_back(1);
    expected.push_back(1);
    expected.push_back(1);
    expected.push_back(1);
    //Act
    target.merge(source);
    //Assert
    bool result = areEqualInSizeAndElements(target.begin(), target.end(), expected.begin(), expected.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testMergeNoPredicate_SrcElementsAreLessTHenTargetElements_ListIncludingWhereFirstGoTargetSrcELementsAndThenTgtElements()
{
    //Arrange
    ft::list<int> target;
    target.push_back(2);
    target.push_back(2);
    ft::list<int> source;
    source.push_back(1);
    source.push_back(1);
    ft::list<int> expected;
    expected.push_back(1);
    expected.push_back(1);
    expected.push_back(2);
    expected.push_back(2);
    //Act
    target.merge(source);
    //Assert
    bool result = areEqualInSizeAndElements(target.begin(), target.end(), expected.begin(), expected.end());
    assertTrue(result);
}

//GREEN
bool isLeftLessThenRight(int left, int right)
{
    return (left < right);
}
void ListTestCase::testMergePredicate_MergeTwoSortedLists_ResultListContainsAllElemenetsFromSourceAndTargetAndElementsAreSorted()
{
    //Arrange
    ft::list<int> target;
    target.push_back(1);
    target.push_back(2);
    target.push_back(3);
    ft::list<int> source;
    source.push_back(6);
    source.push_back(7);
    source.push_back(8);
    ft::list<int> expected;
    expected.push_back(1);
    expected.push_back(2);
    expected.push_back(3);
    expected.push_back(6);
    expected.push_back(7);
    expected.push_back(8);
    //Act
    target.merge(source, isLeftLessThenRight);
    //Assert
    bool result = areEqualInSizeAndElements(target.begin(), target.end(), expected.begin(), expected.end());
    assertTrue(result);
}
static bool isLeftLessThenRightStr(const std::string &left, const std::string &right)
{
    return left < right;
}
//GREEN
void ListTestCase::testMergePredicate_MergeTwoListsOfStrings_ResultListContainsAllElemenetsFromSourceAndTargetAndElementsAreSorted()
{
    //Arrange
    ft::list<std::string> target;
    target.push_back("A");
    target.push_back("C");
    target.push_back("E");
    ft::list<std::string> source;
    source.push_back("B");
    source.push_back("D");
    source.push_back("F");
    
    ft::list<std::string> expected;
    expected.push_back("A");
    expected.push_back("B");
    expected.push_back("C");
    expected.push_back("D");
    expected.push_back("E");
    expected.push_back("F");
    //Act
    target.merge(source, isLeftLessThenRightStr);
    //Assert
    bool result = areEqualInSizeAndElements(target.begin(), target.end(), expected.begin(), expected.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testSortNoPredicate_AlreadySortedList_ListEqualToUsortedList()
{
    //Arrange
    ft::list<int> initialList;
    initialList.push_back(1);
    initialList.push_back(2);
    initialList.push_back(3);
    initialList.push_back(4);
    initialList.push_back(5);
    ft::list<int> sortedList = initialList;
    //Act
    sortedList.sort();
    //Assert
    bool result = areEqualInSizeAndElements(initialList.begin(), initialList.end(), sortedList.begin(), sortedList.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testSortNoPredicate_OneElementList_ListEqualToInitialList()
{
    //Arrange
    ft::list<int> initialList;
    initialList.push_back(1);
    ft::list<int> sortedList = initialList;
    //Act
    sortedList.sort();
    //Assert
    bool result = areEqualInSizeAndElements(initialList.begin(), initialList.end(), sortedList.begin(), sortedList.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testSortNoPredicate_SortedListWithOneElAtWrongPosition_AllElementsSorted()
{
    //Arrange
    ft::list<int> initialList;
    initialList.push_back(1);
    initialList.push_back(2);
    initialList.push_back(4);
    initialList.push_back(5);
    initialList.push_back(3);
    ft::list<int> expectedList;
    expectedList.push_back(1);
    expectedList.push_back(2);
    expectedList.push_back(3);
    expectedList.push_back(4);
    expectedList.push_back(5);
    //Act
    initialList.sort();
    //Assert
    bool result = areEqualInSizeAndElements(initialList.begin(), initialList.end(), expectedList.begin(), expectedList.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testSortNoPredicate_SortedListWithOneElAtWrongPosition_ElementMustBeMovedToFirstPositionListIsSorted()
{
    //Arrange
    ft::list<int> initialList;
    initialList.push_back(2);
    initialList.push_back(3);
    initialList.push_back(4);
    initialList.push_back(5);
    initialList.push_back(1);
    ft::list<int> expectedList;
    expectedList.push_back(1);
    expectedList.push_back(2);
    expectedList.push_back(3);
    expectedList.push_back(4);
    expectedList.push_back(5);
    //Act
    initialList.sort();
    //Assert
    bool result = areEqualInSizeAndElements(initialList.begin(), initialList.end(), expectedList.begin(), expectedList.end());
    assertTrue(result);
    assertTrue(initialList.front() == 1);
}
//GREEN
void ListTestCase::testSortNoPredicate_EmptyList_ListIsUnchanged()
{
    //Arrange
    ft::list<int> initialList;
    ft::list<int> expectedList = initialList;
    //Act
    initialList.sort();
    //Assert
    bool result = areEqualInSizeAndElements(initialList.begin(), initialList.end(), expectedList.begin(), expectedList.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testSortNoPredicate_UnsortedListOfTenElements_SortedListOfTenElements()
{
    //Arrange
    ft::list<int> initialList;
    initialList.push_back(2);
    initialList.push_back(3);
    initialList.push_back(4);
    initialList.push_back(5);
    initialList.push_back(8);
    initialList.push_back(2);
    initialList.push_back(1);
    initialList.push_back(1);
    initialList.push_back(7);
    initialList.push_back(2);
    ft::list<int> expectedList;
    expectedList.push_back(1);
    expectedList.push_back(1);
    expectedList.push_back(2);
    expectedList.push_back(2);
    expectedList.push_back(2);
    expectedList.push_back(3);
    expectedList.push_back(4);
    expectedList.push_back(5);
    expectedList.push_back(7);
    expectedList.push_back(8);
    //Act
    initialList.sort();
    //Assert
    bool result = areEqualInSizeAndElements(initialList.begin(), initialList.end(), expectedList.begin(), expectedList.end());
    assertTrue(result);
}

static bool isLeftStrictlyLessThenRight(int left, int right)
{
    return left < right;
}

//GREEN
void ListTestCase::testSortPredicate_AlreadySortedList_ListEqualToUsortedList()
{
    //Arrange
    ft::list<int> initialList;
    initialList.push_back(1);
    initialList.push_back(2);
    initialList.push_back(3);
    initialList.push_back(4);
    initialList.push_back(5);
    ft::list<int> sortedList = initialList;
    //Act
    sortedList.sort(isLeftStrictlyLessThenRight);
    //Assert
    bool result = areEqualInSizeAndElements(initialList.begin(), initialList.end(), sortedList.begin(), sortedList.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testSortPredicate_OneElementList_ListEqualToInitialList()
{
    //Arrange
    ft::list<int> initialList;
    initialList.push_back(1);
    ft::list<int> sortedList = initialList;
    //Act
    sortedList.sort(isLeftStrictlyLessThenRight);
    //Assert
    bool result = areEqualInSizeAndElements(initialList.begin(), initialList.end(), sortedList.begin(), sortedList.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testSortPredicate_SortedListWithOneElAtWrongPosition_AllElementsSorted()
{
    //Arrange
    ft::list<int> initialList;
    initialList.push_back(1);
    initialList.push_back(2);
    initialList.push_back(4);
    initialList.push_back(5);
    initialList.push_back(3);
    ft::list<int> expectedList;
    expectedList.push_back(1);
    expectedList.push_back(2);
    expectedList.push_back(3);
    expectedList.push_back(4);
    expectedList.push_back(5);
    //Act
    initialList.sort(isLeftStrictlyLessThenRight);
    //Assert
    bool result = areEqualInSizeAndElements(initialList.begin(), initialList.end(), expectedList.begin(), expectedList.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testSortPredicate_SortedListWithOneElAtWrongPosition_ElementMustBeMovedToFirstPositionListIsSorted()
{
    //Arrange
    ft::list<int> initialList;
    initialList.push_back(2);
    initialList.push_back(3);
    initialList.push_back(4);
    initialList.push_back(5);
    initialList.push_back(1);
    ft::list<int> expectedList;
    expectedList.push_back(1);
    expectedList.push_back(2);
    expectedList.push_back(3);
    expectedList.push_back(4);
    expectedList.push_back(5);
    //Act
    initialList.sort(isLeftStrictlyLessThenRight);
    //Assert
    bool result = areEqualInSizeAndElements(initialList.begin(), initialList.end(), expectedList.begin(), expectedList.end());
    assertTrue(result);
    assertTrue(initialList.front() == 1);
}
//GREEN
void ListTestCase::testSortPredicate_EmptyList_ListIsUnchanged()
{
    //Arrange
    ft::list<int> initialList;
    ft::list<int> expectedList = initialList;
    //Act
    initialList.sort(isLeftStrictlyLessThenRight);
    //Assert
    bool result = areEqualInSizeAndElements(initialList.begin(), initialList.end(), expectedList.begin(), expectedList.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testSortPredicate_UnsortedListOfTenElements_SortedListOfTenElements()
{
    //Arrange
    ft::list<int> initialList;
    initialList.push_back(2);
    initialList.push_back(3);
    initialList.push_back(4);
    initialList.push_back(5);
    initialList.push_back(8);
    initialList.push_back(2);
    initialList.push_back(1);
    initialList.push_back(1);
    initialList.push_back(7);
    initialList.push_back(2);
    ft::list<int> expectedList;
    expectedList.push_back(1);
    expectedList.push_back(1);
    expectedList.push_back(2);
    expectedList.push_back(2);
    expectedList.push_back(2);
    expectedList.push_back(3);
    expectedList.push_back(4);
    expectedList.push_back(5);
    expectedList.push_back(7);
    expectedList.push_back(8);
    //Act
    initialList.sort(isLeftStrictlyLessThenRight);
    //Assert
    bool result = areEqualInSizeAndElements(initialList.begin(), initialList.end(), expectedList.begin(), expectedList.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testReverse_EmptyList_EmptyList()
{
    //Arrange
    ft::list<int> actual;
    ft::list<int> expected;
    //Act
    actual.reverse();
    //Assert
    bool result = areEqualInSizeAndElements(actual.begin(), actual.end(), expected.begin(), expected.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testReverse_ListOfFiveInts_ReversedListOfFiveInts()
{
    //Arrange
    ft::list<int> actual;
    actual.push_back(1);
    actual.push_back(2);
    actual.push_back(3);
    actual.push_back(4);
    actual.push_back(5);
    ft::list<int> expected;
    expected.push_back(5);
    expected.push_back(4);
    expected.push_back(3);
    expected.push_back(2);
    expected.push_back(1);
    //Act
    actual.reverse();
    //Assert
    bool result = areEqualInSizeAndElements(actual.begin(), actual.end(), expected.begin(), expected.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testReverse_ListWithTwoInts_ReversedListOfTwoInts()
{
    //Arrange
    ft::list<int> actual;
    actual.push_back(1);
    actual.push_back(2);
    ft::list<int> expected;
    expected.push_back(2);
    expected.push_back(1);
    //Act
    actual.reverse();
    //Assert
    bool result = areEqualInSizeAndElements(actual.begin(), actual.end(), expected.begin(), expected.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testReverse_ListWithOneInt_UnchangedList()
{
    //Arrange
    ft::list<int> actual;
    actual.push_back(1);
    ft::list<int> expected;
    expected.push_back(1);
    //Act
    actual.reverse();
    //Assert
    bool result = areEqualInSizeAndElements(actual.begin(), actual.end(), expected.begin(), expected.end());
    assertTrue(result);
}
//GREEN
void ListTestCase::testEqualityOpGlobal_ListsOfEqualElementsOnEqualPositionsOfEqualSizes_ReturnsTrue()
{
    //Arrange
    ft::list<int> lhs;
    lhs.push_back(1);
    lhs.push_back(2);
    lhs.push_back(3);
    lhs.push_back(4);
    lhs.push_back(5);
    ft::list<int> rhs;
    rhs.push_back(1);
    rhs.push_back(2);
    rhs.push_back(3);
    rhs.push_back(4);
    rhs.push_back(5);
    //Act
    int result = (lhs == rhs);
    //Assert
    assertTrue(result);
}

//GREEN
void ListTestCase::testEqualityOpGlobal_ListsOfEqualElementsOnTheSamePostionsButWithDifferentSizes_ReturnFalse()
{
    //Arrange
    ft::list<int> lhs;
    lhs.push_back(1);
    lhs.push_back(2);
    lhs.push_back(3);
    ft::list<int> rhs;
    rhs.push_back(1);
    rhs.push_back(2);
    rhs.push_back(3);
    rhs.push_back(4);
    rhs.push_back(5);
    //Act
    int result = (lhs == rhs);
    //Assert
    assertFalse(result);
}
//GREEN
void ListTestCase::testNotEqualityOpGlobal_ListsOfEqualElementsOnTheSamePostionsButWithDifferentSizes_ReturnTrue()
{
    //Arrange
    ft::list<int> lhs;
    lhs.push_back(1);
    lhs.push_back(2);
    lhs.push_back(3);
    ft::list<int> rhs;
    rhs.push_back(1);
    rhs.push_back(2);
    rhs.push_back(3);
    rhs.push_back(4);
    rhs.push_back(5);
    //Act
    int result = (lhs != rhs);
    //Assert
    assertTrue(result);
}
//GREEN
void ListTestCase::testLessOpGlobal_TwoListsEqualExceptLastElmenetsLastOfFirstListIsLess_ReturnsTrue()
{
    //Arrange
    ft::list<int> lhs;
    lhs.push_back(1);
    lhs.push_back(2);
    lhs.push_back(3);
    ft::list<int> rhs;
    rhs.push_back(1);
    rhs.push_back(2);
    rhs.push_back(4);
    //Act
    int result = (lhs < rhs);
    //Assert
    assertTrue(result);
}
//GREEN
void ListTestCase::testLessOpGlobal_TwoListsHaveSameElementsInOrderAndValueFromStartTillFirsListSizeSecondListIsLonger_ReturnsTrue()
{
    //Arrange
    ft::list<int> lhs;
    lhs.push_back(1);
    lhs.push_back(2);
    lhs.push_back(3);
    ft::list<int> rhs;
    rhs.push_back(1);
    rhs.push_back(2);
    rhs.push_back(3);
    rhs.push_back(4);
    rhs.push_back(5);
    //Act
    int result = (lhs < rhs);
    //Assert
    assertTrue(result);
}
//GREEN
void ListTestCase::testLessOpGlobal_TwoListsEqualExceptLastElmenetsLastOfSeconfListIsGreater_ReturnsFalse()
{
    //Arrange
    ft::list<int> lhs;
    lhs.push_back(1);
    lhs.push_back(2);
    lhs.push_back(3);
    lhs.push_back(5);
    ft::list<int> rhs;
    rhs.push_back(1);
    rhs.push_back(2);
    rhs.push_back(3);
    rhs.push_back(4);
    //Act
    int result = (lhs < rhs);
    //Assert
    assertFalse(result);
}
//RED
void ListTestCase::testLessOrEqual_TwoEqualLists_ReturnsTrue()
{
    //Arrange
    ft::list<int> lhs;
    lhs.push_back(1);
    lhs.push_back(2);
    lhs.push_back(3);
    lhs.push_back(4);
    ft::list<int> rhs;
    rhs.push_back(1);
    rhs.push_back(2);
    rhs.push_back(3);
    rhs.push_back(4);
    //Act
    int result = (lhs <= rhs);
    //Assert
    assertTrue(result);
}
//GREEN
void ListTestCase::testLessOrEqual_FirstListIsLessThenSecond_ReturnsTrue()
{
    //Arrange
    ft::list<int> lhs;
    lhs.push_back(1);
    lhs.push_back(2);
    lhs.push_back(3);
    lhs.push_back(3);
    ft::list<int> rhs;
    rhs.push_back(1);
    rhs.push_back(2);
    rhs.push_back(3);
    rhs.push_back(4);
    //Act
    int result = (lhs <= rhs);
    //Assert
    assertTrue(result);
}
//GREEN
void ListTestCase::testLessOrEqual_FirstListIsGreaterThenSecond_RerurnsFalse()
{
    //Arrange
    ft::list<int> lhs;
    lhs.push_back(1);
    lhs.push_back(2);
    lhs.push_back(3);
    lhs.push_back(6);
    ft::list<int> rhs;
    rhs.push_back(1);
    rhs.push_back(2);
    rhs.push_back(3);
    rhs.push_back(5);
    //Act
    int result = (lhs <= rhs);
    //Assert
    assertFalse(result);
}
//GREEN
void ListTestCase::testGlobalSwap_SwapTwoDifferentListsOfInts_FirstMustBeEqualCopyOfSecondBeforeSwapAndViceVersa()
{
    //Aarange
    //create lists to swap
    ft::list<int> first(10, 99);
    ft::list<int> second(5, 66);
    //Create copies of lists to compare check results after swap
    ft::list<int> first_cpy = first;
    ft::list<int> second_cpy = second;
    //Act
    swap(first, second);
    //assert
    assertTrue(std::equal(first.begin(), first.end(), second_cpy.begin()));
    assertEqual(first.size(), second_cpy.size());
    assertTrue(std::equal(second.begin(), second.end(), first_cpy.begin()));
    assertEqual(second.size(), first_cpy.size());
}
//GREEN
void ListTestCase::testGlobalSwap_SwapTwoDifferentListsOfInts_IteratorOfFirstMustNowPointToElementOfSecond()
{
    //Arrange
    //create lists to swap
    ft::list<std::string> first;
    first.push_back("one");
    first.push_back("two");
    first.push_back("three");
    ft::list<std::string> second;
    //create iterator to check if it is invalidated
    ft::list<std::string>::iterator it = first.begin();
    it++; // now points to "two"
    //Act
    swap(first, second);
    it++;
    //Assert
    assertEqual(*it, std::string("three"));
}
/* ************************************************************************** */