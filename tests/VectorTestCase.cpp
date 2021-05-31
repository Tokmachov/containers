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



/* ************************************************************************** */
