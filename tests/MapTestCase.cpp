#include "MapTestCase.hpp"

MapTestCase::MapTestCase() {}

MapTestCase::MapTestCase( const MapTestCase & src ){ (void)src; }

MapTestCase::~MapTestCase() {}

MapTestCase &MapTestCase::operator=( MapTestCase const & rhs )
{
	(void)rhs;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
//Configure init function so it fills allTests var properly with your test funcitons
//and funciton names
void MapTestCase::initTests()
{
    TestNameAndFunc t1 = 
    { 
        "testMap_CompileMap_MustNotCrash", 
        testMap_CompileMap_MustNotCrash
    };
    MapTestCase::allTests.push_back(t1);
	TestNameAndFunc t2 =
	{
		"testInsert_InsertTenInsts_MapIsEqualToSortedVectorWithTheSameInst", 
		testInsert_InsertTenInsts_MapIsEqualToSortedVectorWithTheSameInst
	};
	MapTestCase::allTests.push_back(t2);
	TestNameAndFunc t3 =
	{
		"testEndIterator_TraversAllElementsFromBeginToEnd_AllElementsReceivedFromItetatorAreEqualToElementsReceivedFromEqualSTDMap", 
		testEndIterator_TraversAllElementsFromBeginToEnd_AllElementsReceivedFromItetatorAreEqualToElementsReceivedFromEqualSTDMap
	};
	MapTestCase::allTests.push_back(t3);
	TestNameAndFunc t4 =
	{
		"testIsert_InsertElementAlreadyPresentInContainer_SizeRemainsTheSameReturnIsPairOfPairWithFirstEqualToInsertElementAndSecondEqualsToFalse", 
		testIsert_InsertElementAlreadyPresentInContainer_SizeRemainsTheSameReturnIsPairOfPairWithFirstEqualToInsertElementAndSecondEqualsToFalse
	};
	MapTestCase::allTests.push_back(t4);
	TestNameAndFunc t5 =
	{
		"testInsertRange_InsertTwoThreeFourIntoMapOfOneFive_MapOfOneTwoThreeFourFive", 
		testInsertRange_InsertTwoThreeFourIntoMapOfOneFive_MapOfOneTwoThreeFourFive
	};
	MapTestCase::allTests.push_back(t5);
	TestNameAndFunc t6 =
	{
		"testConstructorRange_CreateMapFromRangeTakenFromHoleLengthOfVector_MapIsEqualToVector", 
		testConstructorRange_CreateMapFromRangeTakenFromHoleLengthOfVector_MapIsEqualToVector
	};
	MapTestCase::allTests.push_back(t6);
	TestNameAndFunc t7 =
	{
		"testConstructCopy_CreateMapFromAnotherMapWithCopyConstuctor_MapEquaToSrcMap", 
		testConstructCopy_CreateMapFromAnotherMapWithCopyConstuctor_MapEquaToSrcMap
	};
	MapTestCase::allTests.push_back(t7);
	TestNameAndFunc t8 =
	{
		"testAssignment_AssignSrcMapToDstMap_DstMapEqualSrcMap", 
		testAssignment_AssignSrcMapToDstMap_DstMapEqualSrcMap
	};
	MapTestCase::allTests.push_back(t8);
	TestNameAndFunc t9 =
	{
		"testInsertRange_InsertHoleVectorIntoMap_MapHasInitialElementsPlusElementsOfVector", 
		testInsertRange_InsertHoleVectorIntoMap_MapHasInitialElementsPlusElementsOfVector
	};
	MapTestCase::allTests.push_back(t9);
	TestNameAndFunc t10 =
	{
		"testMapIterator_IterateBackwardsFromLastToFirstElement_ElementsReveivedFromIterationFormReversedSequenceOfMapELements", 
		testMapIterator_IterateBackwardsFromLastToFirstElement_ElementsReveivedFromIterationFormReversedSequenceOfMapELements
	};
	MapTestCase::allTests.push_back(t10);
	TestNameAndFunc t11 =
	{
		"testMapIteratorPostfixMinus_InMapOfOneTwoTreeCallMinusMinusOnIteratorPointingAtTwo_IteratorPointingAtOne", 
		testMapIteratorPostfixMinus_InMapOfOneTwoTreeCallMinusMinusOnIteratorPointingAtTwo_IteratorPointingAtOne
	};
	MapTestCase::allTests.push_back(t11);
	TestNameAndFunc t12 =
	{
		"testMapIteratorPreficPlusPlus_InMapWithKeysOneTwoThreeIncrementBeginIterator_ReturnValueIsIteratorPointingAtKeyTwoAndResultIteratorIsPointingAtKeyTwo", 
		testMapIteratorPreficPlusPlus_InMapWithKeysOneTwoThreeIncrementBeginIterator_ReturnValueIsIteratorPointingAtKeyTwoAndResultIteratorIsPointingAtKeyTwo
	};
	MapTestCase::allTests.push_back(t12);
	TestNameAndFunc t13 =
	{
		"testMapIteratorPostfixPlusPlus_InMapWithKeysOneTwoThreeIncrementBeginIterator_ReturnValueIsBeginIteratorAndResultIteratorIsPointingAtKeyTwo", 
		testMapIteratorPostfixPlusPlus_InMapWithKeysOneTwoThreeIncrementBeginIterator_ReturnValueIsBeginIteratorAndResultIteratorIsPointingAtKeyTwo
	};
	MapTestCase::allTests.push_back(t13);
	TestNameAndFunc t14 =
	{
		"testMapEnd_IterateMapBackwardsUsingIterFromEndMethod_ElementsReceivedFromIteratorFormBackwardSequence", 
		testMapEnd_IterateMapBackwardsUsingIterFromEndMethod_ElementsReceivedFromIteratorFormBackwardSequence
	};
	MapTestCase::allTests.push_back(t14);
	TestNameAndFunc t15 =
	{
		"testMapReversIt_IterateOverMapUsingReverseIter_ElementsReceivedFromIteratorFormBackwardSequence", 
		testMapReversIt_IterateOverMapUsingReverseIter_ElementsReceivedFromIteratorFormBackwardSequence
	};
	MapTestCase::allTests.push_back(t15);
	TestNameAndFunc t16 =
	{
		"testMapEmpty_CallEmptyOnMapWithNoElements_True", 
		testMapEmpty_CallEmptyOnMapWithNoElements_True
	};
	MapTestCase::allTests.push_back(t16);
	TestNameAndFunc t17 =
	{
		"testMapEmpty_AddElementToMapWithNoElementsAndCallEmpty_false", 
		testMapEmpty_AddElementToMapWithNoElementsAndCallEmpty_false
	};
	MapTestCase::allTests.push_back(t17);
	TestNameAndFunc t18 =
	{
		"testMapIndex_CallIndexWithKeyThatDoesntMatchAnyELementInContainer_SizeIsIncreaseByOneElementWithKeyCanBeFoundInContainer", 
		testMapIndex_CallIndexWithKeyThatDoesntMatchAnyELementInContainer_SizeIsIncreaseByOneElementWithKeyCanBeFoundInContainer
	};
	MapTestCase::allTests.push_back(t18);
	TestNameAndFunc t19 =
	{
		"testMapInsdex_CallIndexWithKeyPresentInContainerAndAssignNewValue_SizeDoesntChangeElementWithKeyUsedIsFoundInContainerWithNewMappedValue", 
		testMapInsdex_CallIndexWithKeyPresentInContainerAndAssignNewValue_SizeDoesntChangeElementWithKeyUsedIsFoundInContainerWithNewMappedValue
	};
	MapTestCase::allTests.push_back(t19);
	TestNameAndFunc t20 =
	{
		"testMapEraseIterator_EraseElementWithKeyPresentInMap_SizeDecrementedByOneElementIsAbsentInContainer", 
		testMapEraseIterator_EraseElementWithKeyPresentInMap_SizeDecrementedByOneElementIsAbsentInContainer
	};
	MapTestCase::allTests.push_back(t20);
	TestNameAndFunc t21 =
	{
		"testMapEraseKey_EraseElementPresentInMap_SizeIsDecreasedByOneElementIsAbsentInMapReturnedValueIsOne", 
		testMapEraseKey_EraseElementPresentInMap_SizeIsDecreasedByOneElementIsAbsentInMapReturnedValueIsOne
	};
	MapTestCase::allTests.push_back(t21);
	TestNameAndFunc t22 =
	{
		"testMapEraseRange_EraseAllElementsFromMap_MapIsEmpty", 
		testMapEraseRange_EraseAllElementsFromMap_MapIsEmpty
	};
	MapTestCase::allTests.push_back(t22);
	TestNameAndFunc t23 =
	{
		"testMapSwap_MakeCopyOfTwoMapsAndThenSwapThem_ResultMapsAreEqualToTheCopiesOfTheirSwapPartners", 
		testMapSwap_MakeCopyOfTwoMapsAndThenSwapThem_ResultMapsAreEqualToTheCopiesOfTheirSwapPartners
	};
	MapTestCase::allTests.push_back(t23);
	TestNameAndFunc t24 =
	{
		"testMapClear_ClearMap_MapIsEmpty", 
		testMapClear_ClearMap_MapIsEmpty
	};
	MapTestCase::allTests.push_back(t24);
	TestNameAndFunc t25 =
	{
		"testMapClear_ClearMapAndAddThreeNewElements_MapIsEqualInSizeAndElementsToVectorContainingSameElementsAddedToMap", 
		testMapClear_ClearMapAndAddThreeNewElements_MapIsEqualInSizeAndElementsToVectorContainingSameElementsAddedToMap
	};
	MapTestCase::allTests.push_back(t25);
	TestNameAndFunc t26 =
	{
		"testMapFind_FindElementPresentInMap_RetunIsIteratorToFoundObject", 
		testMapFind_FindElementPresentInMap_RetunIsIteratorToFoundObject
	};
	MapTestCase::allTests.push_back(t26);
	TestNameAndFunc t27 =
	{
		"testMapFind_FindElementAbsentInMap_ReturnIsEndIterator", 
		testMapFind_FindElementAbsentInMap_ReturnIsEndIterator
	};
	MapTestCase::allTests.push_back(t27);
	TestNameAndFunc t28 =
	{
		"testMapCount_CallCountWithKeyPresentInMap_OneIsReturned", 
		testMapCount_CallCountWithKeyPresentInMap_OneIsReturned
	};
	MapTestCase::allTests.push_back(t28);
	TestNameAndFunc t29 =
	{
		"testMapCount_CallCountWithKeyAbsentInMap_ZeroIsReturned", 
		testMapCount_CallCountWithKeyAbsentInMap_ZeroIsReturned
	};
	MapTestCase::allTests.push_back(t29);
	TestNameAndFunc t30 =
	{
		"testMapCount_CallCountOnEmptyMap_ZeroIsReturned", 
		testMapCount_CallCountOnEmptyMap_ZeroIsReturned
	};
	MapTestCase::allTests.push_back(t30);
	TestNameAndFunc t31 =
	{
		"testMapLowerBound_InMapWithKeysOneTwoThreeCallLowerBoundForKeyTwo_IteratorPointingAtThree", 
		testMapLowerBound_InMapWithKeysOneTwoThreeCallLowerBoundForKeyTwo_IteratorPointingAtThree
	};
	MapTestCase::allTests.push_back(t31);
	TestNameAndFunc t32 =
	{
		"testMapUpperBound_InMapWithKeysabcdeFindUpperBoundFord_IteratorPointingToe", 
		testMapUpperBound_InMapWithKeysabcdeFindUpperBoundFord_IteratorPointingToe
	};
	MapTestCase::allTests.push_back(t32);
	TestNameAndFunc t33 =
	{
		"testEqualRange_InMapWithKeysabcCallEqualRangeForb_FirstIteratorPointingTobAndSecondIteratorPointingToc", 
		testEqualRange_InMapWithKeysabcCallEqualRangeForb_FirstIteratorPointingTobAndSecondIteratorPointingToc
	};
	MapTestCase::allTests.push_back(t33);
}

void MapTestCase::run()
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

void MapTestCase::testMap_CompileMap_MustNotCrash()
{
    std::map<int, int> m1;
    m1.lower_bound(10);
    ft::map<int, std::string> m;
    m.insert(std::pair<int, std::string>(5, "Hello"));
    m.insert(std::pair<int, std::string>(10, "no no"));
    m.insert(std::pair<int, std::string>(11, "asdasd"));
    m.insert(std::pair<int, std::string>(12, "asdasd"));
    m.insert(std::pair<int, std::string>(13, "asdasd"));
    m.insert(std::pair<int, std::string>(14, "asdasd"));
    m.insert(std::pair<int, std::string>(15, "asdasd"));
    m.insert(std::pair<int, std::string>(16, "asdasd"));
    m.insert(std::pair<int, std::string>(17, "asdasd"));
    ft::map<int, std::string>::iterator it = m.begin();
    it--;
    it--;
    it++;
    it++;
    assertTrue(true);
}
void MapTestCase::testInsert_InsertTenInsts_MapIsEqualToSortedVectorWithTheSameInst()
{
	//Arrange
    ft::map<int, int> m;
    m.insert(std::pair<int, int>(7, 10));
    m.insert(std::pair<int, int>(2, 10));
    m.insert(std::pair<int, int>(3, 10));
    m.insert(std::pair<int, int>(9, 10));
    m.insert(std::pair<int, int>(0, 10));    
    m.insert(std::pair<int, int>(4, 10));
    m.insert(std::pair<int, int>(8, 10));
	m.insert(std::pair<int, int>(1, 10));
    m.insert(std::pair<int, int>(6, 10));
    m.insert(std::pair<int, int>(5, 10));
    
    std::vector<int> v;
    v.push_back(0);    
	v.push_back(1);    
    v.push_back(2);    
    v.push_back(3);    
    v.push_back(4);    
    v.push_back(5);    
    v.push_back(6);    
    v.push_back(7);    
    v.push_back(8);    
    v.push_back(9);
    
    //Act

	//Assert
	ft::map<int, int>::iterator it = m.begin();
    bool result = true;
    for (int i = 0; i < 10; i++)
    {
        if ((*it).first != v[i])
        {
            result = false;
            break ;
        }
        ++it;
    }
    assertTrue(result);
	//assertFalse();
	//assertEqual(,);
}

void MapTestCase::testEndIterator_TraversAllElementsFromBeginToEnd_AllElementsReceivedFromItetatorAreEqualToElementsReceivedFromEqualSTDMap()
{
	//Arrange
    ft::map<int, int> ftMap;
    ftMap.insert(std::pair<int, int>(7, 10));
    ftMap.insert(std::pair<int, int>(2, 10));
    ftMap.insert(std::pair<int, int>(3, 10));
    ftMap.insert(std::pair<int, int>(9, 10));
    ftMap.insert(std::pair<int, int>(0, 10));    
    ftMap.insert(std::pair<int, int>(4, 10));
    ftMap.insert(std::pair<int, int>(8, 10));
	ftMap.insert(std::pair<int, int>(1, 10));
    ftMap.insert(std::pair<int, int>(6, 10));
    ftMap.insert(std::pair<int, int>(5, 10));
    
    std::map<int, int> stdMap;
    stdMap.insert(std::pair<int, int>(7, 10));
    stdMap.insert(std::pair<int, int>(2, 10));
    stdMap.insert(std::pair<int, int>(3, 10));
    stdMap.insert(std::pair<int, int>(9, 10));
    stdMap.insert(std::pair<int, int>(0, 10));    
    stdMap.insert(std::pair<int, int>(4, 10));
    stdMap.insert(std::pair<int, int>(8, 10));
	stdMap.insert(std::pair<int, int>(1, 10));
    stdMap.insert(std::pair<int, int>(6, 10));
    stdMap.insert(std::pair<int, int>(5, 10));
    
    //Act

	//Assert
	ft::map<int, int>::iterator ftIt = ftMap.begin();
    std::map<int, int>::iterator stdIt = stdMap.begin();
    bool result = true;
    for (;ftIt != ftMap.end(); ++ftIt, stdIt++)
    {
        if ((*ftIt).first != (*stdIt).first)
        {
            result = false;
            break ;
        }
    }
    assertTrue(result);
	assertTrue(stdIt == stdMap.end());
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testIsert_InsertElementAlreadyPresentInContainer_SizeRemainsTheSameReturnIsPairOfPairWithFirstEqualToInsertElementAndSecondEqualsToFalse()
{
	//Arrange
    ft::map<int, int> ftMap;
    ftMap.insert(std::pair<int, int>(7, 10));
    ftMap.insert(std::pair<int, int>(2, 10));
    ftMap.insert(std::pair<int, int>(3, 10));
    ftMap.insert(std::pair<int, int>(9, 10));
    ftMap.insert(std::pair<int, int>(0, 10));    
    ftMap.insert(std::pair<int, int>(4, 10));
    ftMap.insert(std::pair<int, int>(8, 10));
	ftMap.insert(std::pair<int, int>(1, 10));
    ftMap.insert(std::pair<int, int>(6, 10));
    ftMap.insert(std::pair<int, int>(5, 10));
    size_t sizeBeforeInsert = ftMap.size();
    //Act
	typedef ft::map<int, int>::iterator iterator;
    std::pair<iterator, bool> result = ftMap.insert(std::pair<int, int>(7, 10));

	//Assert
    assertTrue((*(result.first)).first == 7);
	assertTrue(result.second == false);
    assertTrue(ftMap.size() == sizeBeforeInsert);
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testInsertRange_InsertTwoThreeFourIntoMapOfOneFive_MapOfOneTwoThreeFourFive()
{
	//Arrange
    ft::map<int, int> ftMap;
    ftMap.insert(std::pair<int, int>(1, 10));
    ftMap.insert(std::pair<int, int>(5, 10));

    std::map<int, int> stdMap;
    stdMap.insert(std::pair<int, int>(1, 10));
    stdMap.insert(std::pair<int, int>(2, 10));
    stdMap.insert(std::pair<int, int>(3, 10));
    stdMap.insert(std::pair<int, int>(4, 10));
    stdMap.insert(std::pair<int, int>(5, 10));
    
    //Act
	ftMap.insert(std::pair<int, int>(2, 10));
    ftMap.insert(std::pair<int, int>(3, 10));
	ftMap.insert(std::pair<int, int>(4, 10));
    //Assert
    assertTrue
    (
        areEqualInSizeAndElements
        (
            ftMap.begin(),
            ftMap.end(),
            stdMap.begin(),
            stdMap.end()
        )
    );
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testConstructorRange_CreateMapFromRangeTakenFromHoleLengthOfVector_MapIsEqualToVector()
{
	//Arrange
    
    std::vector<std::pair<const int, int> > v;
    v.push_back(std::pair<const int, int>(1, 10));
    v.push_back(std::pair<const int, int>(2, 10));
    v.push_back(std::pair<const int, int>(3, 10));
    v.push_back(std::pair<const int, int>(4, 10));
    v.push_back(std::pair<const int, int>(5, 10));
    
    //Act
	ft::map<int, int> ftMap(v.begin(), v.end());
    
    //Assert
    assertTrue
    (
        areEqualInSizeAndElements
        (
            ftMap.begin(),
            ftMap.end(),
            v.begin(),
            v.end()
        )
    );
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testConstructCopy_CreateMapFromAnotherMapWithCopyConstuctor_MapEquaToSrcMap()
{
    //Arrange
    ft::map<int, int> srcMap;
    srcMap.insert(std::pair<int, int>(1, 10));
    srcMap.insert(std::pair<int, int>(5, 10));
    
    //Act
	ft::map<int, int> resultMap(srcMap);
    //Assert
    assertTrue
    (
        areEqualInSizeAndElements
        (
            srcMap.begin(),
            srcMap.end(),
            resultMap.begin(),
            resultMap.end()
        )
    );
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testAssignment_AssignSrcMapToDstMap_DstMapEqualSrcMap()
{
	//Arrange
    ft::map<int, int> srcMap;
    srcMap.insert(std::pair<int, int>(1, 10));
    srcMap.insert(std::pair<int, int>(5, 10));
    

    ft::map<int, int> dstMap;
    srcMap.insert(std::pair<int, int>(11, 10));
    srcMap.insert(std::pair<int, int>(22, 10));
    srcMap.insert(std::pair<int, int>(33, 10));
    //Act
	dstMap = srcMap;
    //Assert
    assertTrue
    (
        areEqualInSizeAndElements
        (
            srcMap.begin(),
            srcMap.end(),
            dstMap.begin(),
            dstMap.end()
        )
    );
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testInsertRange_InsertHoleVectorIntoMap_MapHasInitialElementsPlusElementsOfVector()
{
	//Arrange
    ft::map<int, int> ftMap;
    ftMap.insert(std::pair<int, int>(1, 10));
    ftMap.insert(std::pair<int, int>(5, 10));

    std::map<int, int> stdMap;
    stdMap.insert(std::pair<int, int>(2, 10));
    stdMap.insert(std::pair<int, int>(3, 10));
    stdMap.insert(std::pair<int, int>(4, 10));
    
    std::map<int, int> expectedMap;
    expectedMap.insert(std::pair<int, int>(1, 10));
    expectedMap.insert(std::pair<int, int>(2, 10));
    expectedMap.insert(std::pair<int, int>(3, 10));
    expectedMap.insert(std::pair<int, int>(4, 10));
    expectedMap.insert(std::pair<int, int>(5, 10));
    
    //Act
	ftMap.insert(stdMap.begin(), stdMap.end());
    //Assert
    assertTrue
    (
        areEqualInSizeAndElements
        (
            ftMap.begin(),
            ftMap.end(),
            expectedMap.begin(),
            expectedMap.end()
        )
    );
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapIterator_IterateBackwardsFromLastToFirstElement_ElementsReveivedFromIterationFormReversedSequenceOfMapELements()
{
	//Arrange
    ft::map<int, int> ftMap;
    ftMap.insert(std::pair<int, int>(1, 10));
    ftMap.insert(std::pair<int, int>(2, 10));
    ftMap.insert(std::pair<int, int>(3, 10));
    ftMap.insert(std::pair<int, int>(4, 10));
    ftMap.insert(std::pair<int, int>(5, 10));
    ftMap.insert(std::pair<int, int>(6, 10));
    ftMap.insert(std::pair<int, int>(7, 10));
    ftMap.insert(std::pair<int, int>(8, 10));
    ft::map<int, int>::iterator lastIt = ftMap.begin();
    for (int i = 0; i < 7; i++)
        lastIt++;

    std::vector<std::pair<const int, int> > v;
    v.push_back(std::pair<int, int>(8, 10));
    v.push_back(std::pair<int, int>(7, 10));
    v.push_back(std::pair<int, int>(6, 10));
    v.push_back(std::pair<int, int>(5, 10));
    v.push_back(std::pair<int, int>(4, 10));
    v.push_back(std::pair<int, int>(3, 10));
    v.push_back(std::pair<int, int>(2, 10));
    v.push_back(std::pair<int, int>(1, 10));
    std::vector<std::pair<const int, int> >::iterator vIt = v.begin();

    //Act
    bool result = true;
    for (; lastIt != ftMap.end(); --lastIt, vIt++)
    {
        if (*lastIt != *vIt)
            result = false;
    }
    //Assert
    assertTrue(result);
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapIteratorPostfixMinus_InMapOfOneTwoTreeCallMinusMinusOnIteratorPointingAtTwo_IteratorPointingAtOne()
{
	//Arrange
    ft::map<int, int> m;

    m.insert(std::pair<int, int>(1, 1));
    m.insert(std::pair<int, int>(2, 1));
    m.insert(std::pair<int, int>(3, 1));
    ft::map<int, int>::iterator it = m.begin();

    //Act
    it++;
    it++;
    it--;
    
    //Assert
    assertTrue(it->first == 2);    
}
void MapTestCase::testMapIteratorPreficPlusPlus_InMapWithKeysOneTwoThreeIncrementBeginIterator_ReturnValueIsIteratorPointingAtKeyTwoAndResultIteratorIsPointingAtKeyTwo()
{
	//Arrange
    ft::map<int, int> m;

    m.insert(std::pair<int, int>(1, 1));
    m.insert(std::pair<int, int>(2, 1));
    m.insert(std::pair<int, int>(3, 1));
    ft::map<int, int>::iterator it = m.begin();
    //Act
    ft::map<int, int>::iterator returnValue = ++it;
    
    //Assert
    assertTrue(it->first == 2);
    assertTrue(returnValue->first == 2);
}
void MapTestCase::testMapIteratorPostfixPlusPlus_InMapWithKeysOneTwoThreeIncrementBeginIterator_ReturnValueIsBeginIteratorAndResultIteratorIsPointingAtKeyTwo()
{
	//Arrange
    ft::map<int, int> m;

    m.insert(std::pair<int, int>(1, 1));
    m.insert(std::pair<int, int>(2, 1));
    m.insert(std::pair<int, int>(3, 1));
    ft::map<int, int>::iterator it = m.begin();
    ft::map<int, int>::iterator itBegin = m.begin();
    //Act
    ft::map<int, int>::iterator returnValue = it++;
    
    //Assert
    assertTrue(returnValue == itBegin);
    assertTrue(it->first == 2);
}
void MapTestCase::testMapEnd_IterateMapBackwardsUsingIterFromEndMethod_ElementsReceivedFromIteratorFormBackwardSequence()
{
	//Arrange
    ft::map<int, int> ftMap;
    ftMap.insert(std::pair<int, int>(1, 10));
    ftMap.insert(std::pair<int, int>(2, 10));
    ftMap.insert(std::pair<int, int>(3, 10));
    ftMap.insert(std::pair<int, int>(4, 10));
    ftMap.insert(std::pair<int, int>(5, 10));
    ftMap.insert(std::pair<int, int>(6, 10));
    ftMap.insert(std::pair<int, int>(7, 10));
    ftMap.insert(std::pair<int, int>(8, 10));
    ft::map<int, int>::iterator lastIt = ftMap.end();
    lastIt--;
    
    std::vector<std::pair<const int, int> > v;
    v.push_back(std::pair<int, int>(8, 10));
    v.push_back(std::pair<int, int>(7, 10));
    v.push_back(std::pair<int, int>(6, 10));
    v.push_back(std::pair<int, int>(5, 10));
    v.push_back(std::pair<int, int>(4, 10));
    v.push_back(std::pair<int, int>(3, 10));
    v.push_back(std::pair<int, int>(2, 10));
    v.push_back(std::pair<int, int>(1, 10));
    std::vector<std::pair<const int, int> >::iterator vIt = v.begin();

    //Act
    bool result = true;
    for (; lastIt != ftMap.end(); --lastIt, vIt++)
    {
        if (*lastIt != *vIt)
            result = false;
    }
    //Assert
    assertTrue(result);
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapReversIt_IterateOverMapUsingReverseIter_ElementsReceivedFromIteratorFormBackwardSequence()
{
	//Arrange
    ft::map<int, int> ftMap;
    ftMap.insert(std::pair<int, int>(1, 10));
    ftMap.insert(std::pair<int, int>(2, 10));
    ftMap.insert(std::pair<int, int>(3, 10));
    ftMap.insert(std::pair<int, int>(4, 10));
    ftMap.insert(std::pair<int, int>(5, 10));
    ftMap.insert(std::pair<int, int>(6, 10));
    ftMap.insert(std::pair<int, int>(7, 10));
    ftMap.insert(std::pair<int, int>(8, 10));
    ft::map<int, int>::reverse_iterator ItRev = ftMap.rbegin();
    
    std::vector<std::pair<const int, int> > v;
    v.push_back(std::pair<int, int>(8, 10));
    v.push_back(std::pair<int, int>(7, 10));
    v.push_back(std::pair<int, int>(6, 10));
    v.push_back(std::pair<int, int>(5, 10));
    v.push_back(std::pair<int, int>(4, 10));
    v.push_back(std::pair<int, int>(3, 10));
    v.push_back(std::pair<int, int>(2, 10));
    v.push_back(std::pair<int, int>(1, 10));
    std::vector<std::pair<const int, int> >::iterator vIt = v.begin();

    //Act
    bool result = true;
    for (; ItRev != ftMap.rend(); ItRev++, vIt++)
    {
        if (*ItRev != *vIt)
            result = false;
    }
    //Assert
    assertTrue(result);
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapEmpty_CallEmptyOnMapWithNoElements_True()
{
	//Arrange
    ft::map<int, int> ftMap;

	//Act
    bool result = ftMap.empty();
	//Assert
	assertTrue(result);
	//assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapEmpty_AddElementToMapWithNoElementsAndCallEmpty_false()
{
	//Arrange
    ft::map<int, int> ftMap;

	//Act
    ftMap.insert(std::pair<const int, int>(1, 1));
    bool result = ftMap.empty();
	//Assert
	assertFalse(result);
	//assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapIndex_CallIndexWithKeyThatDoesntMatchAnyELementInContainer_SizeIsIncreaseByOneElementWithKeyCanBeFoundInContainer()
{
	//Arrange
    ft::map<int, int> ftMap;
    ftMap.insert(std::pair<int, int>(1, 10));
    ftMap.insert(std::pair<int, int>(2, 10));
    ftMap.insert(std::pair<int, int>(3, 10));
    ftMap.insert(std::pair<int, int>(4, 10));
    ftMap.insert(std::pair<int, int>(5, 10));
    ftMap.insert(std::pair<int, int>(6, 10));
    ftMap.insert(std::pair<int, int>(7, 10));
    ftMap.insert(std::pair<int, int>(8, 10));
    size_t prevSize = ftMap.size();
	
    //Act
    ftMap[22];
	size_t newSize = ftMap.size();
    //Assert
    bool isNewElementInMap = false;
    ft::map<int, int>::const_reverse_iterator itRev = ftMap.rbegin();
    for(; itRev != ftMap.rend(); itRev++)
    {
        if (itRev->first == 22)
            isNewElementInMap = true;
    }
    assertTrue(newSize == prevSize + 1);
	assertTrue(isNewElementInMap);
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapInsdex_CallIndexWithKeyPresentInContainerAndAssignNewValue_SizeDoesntChangeElementWithKeyUsedIsFoundInContainerWithNewMappedValue()
{
	//Arrange
    ft::map<int, int> ftMap;
    ftMap.insert(std::pair<int, int>(1, 10));
    ftMap.insert(std::pair<int, int>(2, 10));
    ftMap.insert(std::pair<int, int>(3, 10));
    ftMap.insert(std::pair<int, int>(4, 10));
    ftMap.insert(std::pair<int, int>(5, 10));
    ftMap.insert(std::pair<int, int>(6, 10));
    ftMap.insert(std::pair<int, int>(7, 10));
    ftMap.insert(std::pair<int, int>(8, 10));
    printTree(ftMap.getRoot(), ftMap.getEmptyNode());
    size_t prevSize = ftMap.size();
	
    //Act
    ftMap[8] = 999;
	size_t newSize = ftMap.size();
    //Assert
    bool isNewValue = false;
    ft::map<int, int>::const_reverse_iterator itRev = ftMap.rbegin();
    for(; itRev != ftMap.rend(); itRev++)
    {
        if (itRev->first == 8 && itRev->second == 999)
            isNewValue = true;
    }
    assertTrue(newSize == prevSize);
	assertTrue(isNewValue);
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapEraseIterator_EraseElementWithKeyPresentInMap_SizeDecrementedByOneElementIsAbsentInContainer()
{
	//Arrange
    ft::map<int, int> ftMap;
    ftMap.insert(std::pair<int, int>(1, 10));
    ftMap.insert(std::pair<int, int>(2, 10));
    ftMap.insert(std::pair<int, int>(3, 10));
    printTree(ftMap.getRoot(), ftMap.getEmptyNode());
    size_t oldSize = ftMap.size();
	
    //Act
    ft::map<int, int>::iterator removePosition = ftMap.begin();
    ftMap.erase(removePosition);
    size_t newSize = ftMap.size();
    printTree(ftMap.getRoot(), ftMap.getEmptyNode());
    
    //Assert
    bool isElementPresent = false;
    ft::map<int, int>::const_reverse_iterator itRev = ftMap.rbegin();
    for(; itRev != ftMap.rend(); itRev++)
    {
        if (itRev->first == 1 && itRev->second == 10)
            isElementPresent = true;
    }
    assertTrue(newSize == oldSize - 1);
	assertFalse(isElementPresent);
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapEraseKey_EraseElementPresentInMap_SizeIsDecreasedByOneElementIsAbsentInMapReturnedValueIsOne()
{
	//Arrange
    ft::map<int, int> ftMap;
    ftMap.insert(std::pair<int, int>(1, 10));
    ftMap.insert(std::pair<int, int>(2, 10));
    ftMap.insert(std::pair<int, int>(3, 10));
    printTree(ftMap.getRoot(), ftMap.getEmptyNode());
    size_t oldSize = ftMap.size();
	
    //Act
    size_t returnValue = ftMap.erase(2);
    size_t newSize = ftMap.size();
    printTree(ftMap.getRoot(), ftMap.getEmptyNode());
    
    //Assert
    bool isElementPresent = false;
    ft::map<int, int>::const_reverse_iterator itRev = ftMap.rbegin();
    for(; itRev != ftMap.rend(); itRev++)
    {
        if (itRev->first == 2 && itRev->second == 10)
            isElementPresent = true;
    }
    assertTrue(newSize == oldSize - 1);
	assertFalse(isElementPresent);
    assertTrue(returnValue);
    //assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapEraseRange_EraseAllElementsFromMap_MapIsEmpty()
{
	//Arrange
    ft::map<int, int> ftMap;
    ftMap.insert(std::pair<int, int>(1, 10));
    ftMap.insert(std::pair<int, int>(2, 10));
    ftMap.insert(std::pair<int, int>(3, 10));
    printTree(ftMap.getRoot(), ftMap.getEmptyNode());
	ft::map<int, int>::iterator itBegin = ftMap.begin();
    ft::map<int, int>::iterator itEnd = ftMap.end();
    
    //Act
    ftMap.erase(itBegin, itEnd);
    printTree(ftMap.getRoot(), ftMap.getEmptyNode());
    //Assert
    assertTrue(ftMap.empty());
}
void MapTestCase::testMapSwap_MakeCopyOfTwoMapsAndThenSwapThem_ResultMapsAreEqualToTheCopiesOfTheirSwapPartners()
{
	//Arrange
    ft::map<int, int> ftMap1;
    ftMap1.insert(std::pair<int, int>(1, 10));
    ftMap1.insert(std::pair<int, int>(2, 10));
    ftMap1.insert(std::pair<int, int>(3, 10));
    
    ft::map<int, int> ftMap2;
    ftMap2.insert(std::pair<int, int>(-1, 10));
    ftMap2.insert(std::pair<int, int>(-2, 10));
    ftMap2.insert(std::pair<int, int>(-3, 10));

	ft::map<int, int> ftMap1Copy = ftMap1;
    ft::map<int, int> ftMap2Copy = ftMap2;
    
    
    //Act
    ftMap1.swap(ftMap2);
    //Assert
    assertTrue
    (
        areEqualInSizeAndElements
        (
            ftMap1.begin(),
            ftMap1.end(),
            ftMap2Copy.begin(),
            ftMap2Copy.end()
        )
    );
    assertTrue
    (
        areEqualInSizeAndElements
        (
            ftMap2.begin(),
            ftMap2.end(),
            ftMap1Copy.begin(),
            ftMap1Copy.end()
        )
    );
}
void MapTestCase::testMapClear_ClearMap_MapIsEmpty()
{
	//Arrange
    //Arrange
    ft::map<int, int> ftMap1;
    ftMap1.insert(std::pair<int, int>(1, 10));
    ftMap1.insert(std::pair<int, int>(2, 10));
    ftMap1.insert(std::pair<int, int>(3, 10));
	//Act
    ftMap1.clear();
	//Assert
	assertTrue(ftMap1.empty());
	//assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapClear_ClearMapAndAddThreeNewElements_MapIsEqualInSizeAndElementsToVectorContainingSameElementsAddedToMap()
{
	//Arrange
    ft::map<int, int> ftMap1;
    ftMap1.insert(std::pair<int, int>(1, 10));
    ftMap1.insert(std::pair<int, int>(2, 10));
    ftMap1.insert(std::pair<int, int>(3, 10));
	
    std::vector<std::pair<const int, int> > v;
    v.push_back(std::pair<int, int>(1, 10));
    v.push_back(std::pair<int, int>(2, 10));
    v.push_back(std::pair<int, int>(3, 10));
    //Act
    ftMap1.clear();
	ftMap1.insert(std::pair<int, int>(1, 10));
    ftMap1.insert(std::pair<int, int>(2, 10));
    ftMap1.insert(std::pair<int, int>(3, 10));
    //Assert
	assertTrue(
        areEqualInSizeAndElements
        (
            ftMap1.begin(),
            ftMap1.end(),
            v.begin(),
            v.end()
        )
    );
	//assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapFind_FindElementPresentInMap_RetunIsIteratorToFoundObject()
{
	//Arrange
    ft::map<int, int> ftMap1;
    ftMap1.insert(std::pair<int, int>(1, 10));
    ftMap1.insert(std::pair<int, int>(2, 10));
    ftMap1.insert(std::pair<int, int>(3, 10));
	//Act
    ft::map<int, int>::iterator returnedIterator = ftMap1.find(2);
	//Assert
	assertTrue(returnedIterator->first == 2);
	//assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapFind_FindElementAbsentInMap_ReturnIsEndIterator()
{
	//Arrange
    ft::map<int, int> ftMap1;
    ftMap1.insert(std::pair<int, int>(1, 10));
    ftMap1.insert(std::pair<int, int>(2, 10));
    ftMap1.insert(std::pair<int, int>(3, 10));
	//Act
    ft::map<int, int>::iterator returnedIterator = ftMap1.find(5);
	//Assert
	assertTrue(returnedIterator == ftMap1.end());
	//assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapCount_CallCountWithKeyPresentInMap_OneIsReturned()
{
	//Arrange
    ft::map<std::string, int> ftMap1;
    ftMap1.insert(std::pair<std::string, int>("Yellow", 10));
    ftMap1.insert(std::pair<std::string, int>("Green", 10));
    ftMap1.insert(std::pair<std::string, int>("White", 10));
	//Act
    size_t result = ftMap1.count("White");
	//Assert
	assertTrue(result == 1);
	//assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapCount_CallCountWithKeyAbsentInMap_ZeroIsReturned()
{
	//Arrange
    ft::map<std::string, int> ftMap1;
    ftMap1.insert(std::pair<std::string, int>("Yellow", 10));
    ftMap1.insert(std::pair<std::string, int>("Green", 10));
    ftMap1.insert(std::pair<std::string, int>("White", 10));
	//Act
    size_t result = ftMap1.count("Black");
	//Assert
	assertTrue(result == 0);
	//assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapCount_CallCountOnEmptyMap_ZeroIsReturned()
{
	//Arrange
    ft::map<std::string, int> ftMap1;
    ftMap1.insert(std::pair<std::string, int>("Yellow", 10));
    ftMap1.insert(std::pair<std::string, int>("Green", 10));
    ftMap1.insert(std::pair<std::string, int>("White", 10));
	ftMap1.clear();
    //Act
    size_t result = ftMap1.count("Black");
	//Assert
	assertTrue(result == 0);
	//assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapLowerBound_InMapWithKeysOneTwoThreeCallLowerBoundForKeyTwo_IteratorPointingAtThree()
{
    //Arrange
    ft::map<int, int> ftMap1;
    ftMap1.insert(std::pair<int, int>(1, 10));
    ftMap1.insert(std::pair<int, int>(2, 10));
    ftMap1.insert(std::pair<int, int>(3, 10));
	
    ft::map<int, int>::iterator expectedIterator = ftMap1.end();
    --expectedIterator;
    --expectedIterator;
    //Act
    ft::map<int, int>::iterator returnedIterator = ftMap1.lower_bound(2);
	
    //Assert
	assertTrue(returnedIterator == expectedIterator);
	//assertFalse();
	//assertEqual(,);
}
void MapTestCase::testMapUpperBound_InMapWithKeysabcdeFindUpperBoundFord_IteratorPointingToe()
{
	//Arrange
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator itup;
    
    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    //act
    itup=mymap.upper_bound ('d');   // itup points to e (not d!)
    //assert
    assertTrue(itup->first == 'e');
}
void MapTestCase::testEqualRange_InMapWithKeysabcCallEqualRangeForb_FirstIteratorPointingTobAndSecondIteratorPointingToc()
{
	//Arrange
    ft::map<char,int> mymap;
    ft::map<char,int>::iterator itup;
    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    std::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> range;

    //act
    range = mymap.equal_range('b');
    //assert
    assertTrue(range.first->first == 'b');
    assertTrue(range.second->first == 'c');
}









/* ************************************************************************** */
