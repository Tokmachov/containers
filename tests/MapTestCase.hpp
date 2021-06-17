
#ifndef MAPTESTCASE_HPP
# define MAPTESTCASE_HPP

# include <iostream>
# include <string>
# include "TestCase.hpp"
# include "../map/map.hpp"
# include "stdlib.h"
# include <map>
# include "../utils.hpp"
class MapTestCase : public TestCase
{
	public:
        static void run();
	protected:
        static void initTests();
    private:
        MapTestCase();
		MapTestCase( MapTestCase const & src );
		~MapTestCase();
		MapTestCase &		operator=( MapTestCase const & rhs );
        
        //support type
        class TestClass
        {
            public:
            int value;
        };
        //Test functions
        //Please write declaration of test functions here
        static void testMap_CompileMap_MustNotCrash();
        static void testInsert_InsertTenInsts_MapIsEqualToSortedVectorWithTheSameInst();
        static void testEndIterator_TraversAllElementsFromBeginToEnd_AllElementsReceivedFromItetatorAreEqualToElementsReceivedFromEqualSTDMap();
        static void testIsert_InsertElementAlreadyPresentInContainer_SizeRemainsTheSameReturnIsPairOfPairWithFirstEqualToInsertElementAndSecondEqualsToFalse();
        static void testInsertRange_InsertTwoThreeFourIntoMapOfOneFive_MapOfOneTwoThreeFourFive();
        static void testConstructorRange_CreateMapFromRangeTakenFromHoleLengthOfVector_MapIsEqualToVector();
        static void testConstructCopy_CreateMapFromAnotherMapWithCopyConstuctor_MapEquaToSrcMap();
        static void testAssignment_AssignSrcMapToDstMap_DstMapEqualSrcMap();
        static void testInsertRange_InsertHoleVectorIntoMap_MapHasInitialElementsPlusElementsOfVector();
        static void testMapIterator_IterateBackwardsFromLastToFirstElement_ElementsReveivedFromIterationFormReversedSequenceOfMapELements();
        static void testMapIteratorPostfixMinus_InMapOfOneTwoTreeCallMinusMinusOnIteratorPointingAtTwo_IteratorPointingAtOne();
        static void testMapIteratorPreficPlusPlus_InMapWithKeysOneTwoThreeIncrementBeginIterator_ReturnValueIsIteratorPointingAtKeyTwoAndResultIteratorIsPointingAtKeyTwo();
        static void testMapIteratorPostfixPlusPlus_InMapWithKeysOneTwoThreeIncrementBeginIterator_ReturnValueIsBeginIteratorAndResultIteratorIsPointingAtKeyTwo();
        static void testMapEnd_IterateMapBackwardsUsingIterFromEndMethod_ElementsReceivedFromIteratorFormBackwardSequence();  
        static void testMapReversIt_IterateOverMapUsingReverseIter_ElementsReceivedFromIteratorFormBackwardSequence();  
        static void testMapEmpty_CallEmptyOnMapWithNoElements_True();
        static void testMapEmpty_AddElementToMapWithNoElementsAndCallEmpty_false();
        static void testMapIndex_CallIndexWithKeyThatDoesntMatchAnyELementInContainer_SizeIsIncreaseByOneElementWithKeyCanBeFoundInContainer();
        static void testMapInsdex_CallIndexWithKeyPresentInContainerAndAssignNewValue_SizeDoesntChangeElementWithKeyUsedIsFoundInContainerWithNewMappedValue();
        static void testMapEraseIterator_EraseElementWithKeyPresentInMap_SizeDecrementedByOneElementIsAbsentInContainer();
        static void testMapEraseKey_EraseElementPresentInMap_SizeIsDecreasedByOneElementIsAbsentInMapReturnedValueIsOne();
        static void testMapEraseRange_EraseAllElementsFromMap_MapIsEmpty();
        static void testMapSwap_MakeCopyOfTwoMapsAndThenSwapThem_ResultMapsAreEqualToTheCopiesOfTheirSwapPartners();
        static void testMapClear_ClearMap_MapIsEmpty();
        static void testMapClear_ClearMapAndAddThreeNewElements_MapIsEqualInSizeAndElementsToVectorContainingSameElementsAddedToMap();
        static void testMapFind_FindElementPresentInMap_RetunIsIteratorToFoundObject();
        static void testMapFind_FindElementAbsentInMap_ReturnIsEndIterator();
        static void testMapCount_CallCountWithKeyPresentInMap_OneIsReturned();
};

#endif /* ************************************************ MapTestCase_H */