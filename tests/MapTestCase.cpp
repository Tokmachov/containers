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
    ft::map<int, std::string> m;
    m.insert(std::pair<int, std::string>(5, "Hello"));
    m.insert(std::pair<int, std::string>(10, "Hello"));
    ft::map<int, std::string>::iterator it = m.begin();
    ft::map<int, std::string>::const_iterator const_it = it;
    it->second = "asdfasdfa"; 
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
    ft::map<int, int>::iterator itBegin = m.begin();
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

/* ************************************************************************** */
