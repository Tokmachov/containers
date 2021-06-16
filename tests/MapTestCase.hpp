
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
};

#endif /* ************************************************ MapTestCase_H */