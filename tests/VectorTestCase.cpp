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
}

void VectorTestCase::run()
{
    initTests();
    startTestLoop();
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
    assertTrue(actual.capacity() == 1);
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
    assertTrue(actual.capacity() == 4);
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
	//assertTrue();
	//assertFalse();
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








/* ************************************************************************** */
