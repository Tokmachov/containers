
#ifndef LISTTESTCASE_HPP
# define LISTTESTCASE_HPP

# include <iostream>
# include <string>
# include "TestCase.hpp"
# include <list>
# include <algorithm>

# include "../list/list.hpp"

class ListTestCase : public TestCase
{
	public:
        static void run();
	protected:
        static void initTests();
    private:
        ListTestCase();
		ListTestCase( ListTestCase const & src );
		~ListTestCase();
		ListTestCase &		operator=( ListTestCase const & rhs );
        
        //support type
        class TestClass
        {
            public:
            int value;
        };
        //Test functions
        static void testFillConstructorCreatesListEqualToListOfTenIntsWithOneValue();
        static void testRangeConstructorInitializesListWithRangeStrings();
        static void testCopyConstructedListIsEqualToSourceList();
        static void testCopyConstructedListsBecomesDifferentAfterElementsOfSourceAreChanged();
        static void testListAfterAssignationIsEqualInSizeAndElementsToSourceList();
        static void testListCreatedByAssignationBecomesDefferentToSourceAfterSourceIsChanged();
        static void testListsEmptyReturnsTrueAfterCreationWithDefaultInitializer();
        static void testListEmptyMethodReturnsFalseAfterAdditionOfOneElementToEmptyList();
        static void testGetFrontElemenWhichIsStringHello();
        static void testSetFirstElementFromStringHelloToGoodbye();
        static void testBackMethodSetLastElementToFiveAndCheckItIsFive();
        
        static void test_AssignRange_AssignSameRangeToSTDListAndFTList_ListsEqualInSizeAndElements();
        static void test_AssignRange_AssignEmptyRangeToSTDListAndFTList_ListsEqualInSIzeAndElements();
        static void test_AssignRange_AssignRangeWichIsBiggerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements();
        static void test_AssignRange_AssignRangeWichIsSmallerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements();

        static void test_AssignFill_AssignSameRangeToSTDListAndFTList_ListsEqualInSizeAndElements();
        static void test_AssignFill_AssignEmptyRangeToSTDListAndFTList_ListsEqualInSIzeAndElements();
        static void test_AssignFill_AssignRangeWichIsBiggerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements();
        static void test_AssignFill_AssignRangeWichIsSmallerThenTargetLstsToSTDListAndFTList_ListsEqualInSIzeAndElements();
        static void testPushFront_CreateListAddOneElement_SizeIncreasesByOneAndFrontMethodReturnsAddedElement();
        static void testPopFront_CreateListRemoveOneElement_SizeDecreasesbyOneAndFrontElemenIsDfferent();
        static void testPushBack_AddOneElementToList_SizeIncreasesByOneAndLastElementBecomesTheOneAdded();
        static void testPopBack_PopOneElement_SizeMustDecreaseByOneBackElementMustBeEqualToElementBeforeLast();
        static void testPopBack_PopAllElementsFromListInALoop_ResultListMustBeEmpty();
        
        static void testIsertSingleElement_RusultListAndRetrnValueMustBeTheSameAsOfSTDList();
        static void testInsertSingleElement_InsertMultipleElementsInLoop_ResultListIsEqualToStdListEffectedBySameActions();
        static void testInsertFill_InsertMultipleElemens_ResultListMustBeEqualToStdListEffectedBySameActions();
        static void testIsertRange_InsertRange_ResultListMustBeEqualToStdListEffectedBySameActions();

        static void testEraseSingleElement_RemoveElement_ResulFtListMustIsEqualToStdListEffectedByTheSameActions();
        static void testEraseSingleElement_RemoveAllElementsFromListInALoop_ResultFtListMustIsEqualToStdListEffectedByTheSameActionsAndBothListsAreZeroSized();
        static void testEraseSingleElement_RemoveLastElementFromList_RetunIsEndIterator();
        
        static void testEraseRange_RemoveRangeOfElementsFromList_StdContainerEffectedByTheSameActionsIsEqualToFtListInElementsAndSize();
        static void testEraseRange_RemoveRangeOfElementsFromList_ReturnsIteratorIsEqualToLastInputParameter();
        static void testEraseRange_RemoveAllElements_ResultListIsEmpty();
        static void testEraseRange_RemoveAllElements_ReturnIsEndIteratorOfList();

        static void testSwap_SwapTwoDifferentListsOfInts_FirstMustBeEqualCopyOfSecondBeforeSwapAndViceVersa();
        static void testSwap_SwapTwoDifferentListsOfInts_IteratorOfFirstMustNowPointToElementOfSecond();

        static void testResize_ResizeWithNSmallerThenListSize_ListSizeBecomesEqualToN();
        static void testResize_ResizeWithNGreaterThenListSize_ListSizeBecomesEqualToN();
        static void testResize_ResizeWithNGreaterThenListSizeNValueISProvided_AllNewElementsInListEqualToN();
        static void testResize_ResizeWithNEqualToListSize_ListSizeIsEqualToSizeBeforeResize();

        static void testClear_ClearNonEmptyList_ListIsEmpty();

        static void testSpliceAllElements_SpliceOneListIntoAnother_RusultListIsEqualInSizeAndElementsToStdListEffectdBySameActions();
        static void testSpliceAllElements_SpliceOneListIntoAnother_SrcListIsEmpty();
        
        static void testSpliceOneElement_SpliceOneElementToList_SrcListSizeIsDecreasedByOne();
        static void testSpliceOneElement_SpliceOneElementToList_TargetListSizeIsIncreasedByOne();
        static void testSpliceOneElement_SpliceOneElementToList_PositionIteratorDecrementedByOneYeldsElementAdded();
        static void testSpliceOneElement_SpliceOneElementToEmptyList_PositionIteratorDecrementedByOneYeldsElementAdded();
        static void testSpliceOneElement_SpliceOneElementFromThisListRightNextToPosition_PositionIteratorDecrementedByOneYeldsElementAdded();
        
        static void testSpliceRange_SpliceRange_SrcListSizeIsDecreasedByRangeSize();
        static void testSpliceRange_SpliceRange_TargetSizeIsIncreasedByRangeSize(); 
        static void testSpliceRange_SpliceRange_TargetHasExpectedELements();
        static void testSpliceRange_SpliceRangeToEmptyTarget_TargetHasExpectedELements();

        static void testRemove_RemoveOneElementPresentInList_ListSizeIsDecreasedByOne();
        static void testRemove_RemoveValueFromListThatIsPresentedInListSeveralTimes_ResultListIsTheSameAsInitialListButWithoutValuesInIt();
        static void testRemove_RemoveValueThatIsNotInAList_ListMustBeTheSameAsBeforeRemoval();
        static void testRemove_RemoveValueFromListContainingValuesOnly_ListIsEmpty();
        
        static void testRemoveIf_RemoveTheOnlyFiveFromList_ListSizeIsDecreasedByOne();
        static void testRemoveIf_RemoveElementFromListThatIsPresentedInListSeveralTimes_ResultListIsTheSameAsInitialListButWithoutElementsInIt();
        static void testRemoveIf_RemoveElementThatIsNotInAList_ListMustBeTheSameAsBeforeRemoval();
        static void testRemoveIf_RemoveElementsFromListContainingElementsSubjectToRemovalOnly_ListIsEmpty();

        static void testUniqueNoParam_CallUniqueOnSortedList_ListWithUniqueElements();
        static void testUniqueNoParam_CallUniqueOnListFilledWithSameElements_ListWithOneElement();
        static void testUniqueNoParam_CallUniqueOnListWithUniquesElements_ResultListIsEqualToInitialList();

        static void testUniquePredicate_CallUniqueOnSortedList_ListWithUniqueElements();
        static void testUniquePredicate_CallUniqueOnListFilledWithSameElements_ListWithOneElement();
        static void testUniquePredicate_CallUniqueOnListWithUniquesElements_ResultListIsEqualToInitialList();

        static void testMergeNoPredicate_MergeToSortedLists_SourceListIsEmpty();
        static void testMergeNoPredicate_MergeTwoSortedLists_ResultListContainsAllElemenetsFromSourceAndTargetAndElementsAreSorted();
        static void testMergeNoPredicate_MergeTwoEmptyLists_ResultListIsEmpty();
        static void testMergeNoPredicate_MergeEmptySourceAnsNonEmptyTarget_ListContainsAllSortedElementsFromSource();
        static void testMergeNoPredicate_SrcFirstElIsGreaterThenTgtLastEl_ElsOfSrcPlacedAfterAllElsOfTarget();
        static void testMergeNoPredicate_SrcElementsAreEqualtToTargetElements_ListIncludingAllElementsFromSrcAndTgt();
        static void testMergeNoPredicate_SrcElementsAreLessTHenTargetElements_ListIncludingWhereFirstGoTargetSrcELementsAndThenTgtElements();
        
        static void testMergePredicate_MergeTwoSortedLists_ResultListContainsAllElemenetsFromSourceAndTargetAndElementsAreSorted();
        static void testMergePredicate_MergeTwoListsOfStrings_ResultListContainsAllElemenetsFromSourceAndTargetAndElementsAreSorted();
        
        static void testSortNoPredicate_AlreadySortedList_ListEqualToUsortedList();
        static void testSortNoPredicate_OneElementList_ListEqualToInitialList();
        static void testSortNoPredicate_SortedListWithOneElAtWrongPosition_AllElementsSorted();
        static void testSortNoPredicate_SortedListWithOneElAtWrongPosition_ElementMustBeMovedToFirstPositionListIsSorted();
        static void testSortNoPredicate_EmptyList_ListIsUnchanged();
        static void testSortNoPredicate_UnsortedListOfTenElements_SortedListOfTenElements();

        static void testSortPredicate_AlreadySortedList_ListEqualToUsortedList();
        static void testSortPredicate_OneElementList_ListEqualToInitialList();
        static void testSortPredicate_SortedListWithOneElAtWrongPosition_AllElementsSorted();
        static void testSortPredicate_SortedListWithOneElAtWrongPosition_ElementMustBeMovedToFirstPositionListIsSorted();
        static void testSortPredicate_EmptyList_ListIsUnchanged();
        static void testSortPredicate_UnsortedListOfTenElements_SortedListOfTenElements();

        static void testReverse_EmptyList_EmptyList();
        static void testReverse_ListOfFiveInts_ReversedListOfFiveInts();
        static void testReverse_ListWithTwoInts_ReversedListOfTwoInts();
        static void testReverse_ListWithOneInt_UnchangedList();

        static void testEqualityOpGlobal_ListsOfEqualElementsOnEqualPositionsOfEqualSizes_ReturnsTrue();
        static void testEqualityOpGlobal_ListsOfEqualElementsOnTheSamePostionsButWithDifferentSizes_ReturnFalse();
        static void testNotEqualityOpGlobal_ListsOfEqualElementsOnTheSamePostionsButWithDifferentSizes_ReturnTrue();

        static void testLessOpGlobal_TwoListsEqualExceptLastElmenetsLastOfFirstListIsLess_ReturnsTrue();
        static void testLessOpGlobal_TwoListsHaveSameElementsInOrderAndValueFromStartTillFirsListSizeSecondListIsLonger_ReturnsTrue();
        static void testLessOpGlobal_TwoListsEqualExceptLastElmenetsLastOfSeconfListIsGreater_ReturnsFalse();
        static void testLessOrEqual_TwoEqualLists_ReturnsTrue();
        static void testLessOrEqual_FirstListIsLessThenSecond_ReturnsTrue();
        static void testLessOrEqual_FirstListIsGreaterThenSecond_RerurnsFalse();

        static void testGlobalSwap_SwapTwoDifferentListsOfInts_FirstMustBeEqualCopyOfSecondBeforeSwapAndViceVersa();
        static void testGlobalSwap_SwapTwoDifferentListsOfInts_IteratorOfFirstMustNowPointToElementOfSecond();
};

#endif /* ************************************************ ListTestCase_H */

