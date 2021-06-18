#include "ListIteratorTestCase.hpp"

ListIteratorTestCase::ListIteratorTestCase() {}

ListIteratorTestCase::ListIteratorTestCase( const ListIteratorTestCase & src ){ (void)src; }

ListIteratorTestCase::~ListIteratorTestCase() {}

ListIteratorTestCase &ListIteratorTestCase::operator=( ListIteratorTestCase const & rhs )
{
	(void)rhs;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ListIteratorTestCase::initTests()
{
    TestNameAndFunc t1 = 
    { 
        "testIteratorsOfTwoListsWithSameSequencesMustNotBeEqual", 
        testCopyConstructionMustProduceEqualIterators
    };
    ListIteratorTestCase::allTests.push_back(t1);
    TestNameAndFunc t2 = 
    { 
        "testCopyConstructionMustProduceEqualIterators", 
        testCopyConstructionMustProduceEqualIterators
    };
    ListIteratorTestCase::allTests.push_back(t2);
    TestNameAndFunc t3 = 
    { 
        "testAssignationMustProduceEqualIterators", 
        testAssignationMustProduceEqualIterators
    };
    ListIteratorTestCase::allTests.push_back(t3);
    TestNameAndFunc t4 = 
    { 
        "testIteratorYieldsCorrectValueWhenDereferenced", 
        testIteratorYieldsCorrectValueWhenDereferenced
    };
    ListIteratorTestCase::allTests.push_back(t4);
    TestNameAndFunc t5 = 
    { 
        "testIteratorYieldsCorrectValueWhenDereferencedWithArrow", 
        testIteratorYieldsCorrectValueWhenDereferencedWithArrow
    };
    ListIteratorTestCase::allTests.push_back(t5);
    TestNameAndFunc t6 = 
    { 
        "testMutableIteratorAllowsToCorrectlySetListValue", 
        testMutableIteratorAllowsToCorrectlySetListValue
    };
    ListIteratorTestCase::allTests.push_back(t6);
    TestNameAndFunc t7 = 
    { 
        "testPrefixPlusPlusSetsIteratorToCorrectPosition", 
        testPrefixPlusPlusSetsIteratorToCorrectPosition
    };
    ListIteratorTestCase::allTests.push_back(t7);
    TestNameAndFunc t8 = 
    { 
        "testPrefixPlusPlusReturnValueMustBeValueAfterOpCall", 
        testPrefixPlusPlusReturnValueMustBeValueAfterOpCall
    };
    ListIteratorTestCase::allTests.push_back(t8);
    TestNameAndFunc t9 = 
    { 
        "testPostfixPlusPlusSetsIteratorToCorrectPosition", 
        testPostfixPlusPlusSetsIteratorToCorrectPosition
    };
    ListIteratorTestCase::allTests.push_back(t9);
    TestNameAndFunc t10 = 
    { 
        "testPrefixMinuMinusSetsIteratorToCorrectPosition", 
        testPrefixMinuMinusSetsIteratorToCorrectPosition
    };
    ListIteratorTestCase::allTests.push_back(t10);
    TestNameAndFunc t11 = 
    { 
        "testPostfixMinuMinusSetsIteratorToCorrectPosition", 
        testPostfixMinuMinusSetsIteratorToCorrectPosition
    };
    ListIteratorTestCase::allTests.push_back(t11);
    TestNameAndFunc t12 = 
    { 
        "testConstIteratorsOfTwoListsWithSameSequencesMustNotBeEqual", 
        testConstIteratorsOfTwoListsWithSameSequencesMustNotBeEqual
    };
    ListIteratorTestCase::allTests.push_back(t12);
    TestNameAndFunc t13 = 
    { 
        "testCopyConstructionMustProduceEqualConstIterators", 
        testCopyConstructionMustProduceEqualConstIterators
    };
    ListIteratorTestCase::allTests.push_back(t13);
    TestNameAndFunc t14 = 
    { 
        "testAssignationMustProduceEqualConstIterators", 
        testAssignationMustProduceEqualConstIterators
    };
    ListIteratorTestCase::allTests.push_back(t14);
    TestNameAndFunc t15 = 
    { 
        "testConstIteratorYieldsCorrectValueWhenDereferenced", 
        testConstIteratorYieldsCorrectValueWhenDereferenced 
    };
    ListIteratorTestCase::allTests.push_back(t15);
    TestNameAndFunc t16 = 
    { 
        "testConstIteratorYieldsCorrectValueWhenDereferencedWithArrow", 
        testConstIteratorYieldsCorrectValueWhenDereferencedWithArrow 
    };
    ListIteratorTestCase::allTests.push_back(t16);
    TestNameAndFunc t17 = 
    { 
        "testPrefixPlusPlusSetsConstIteratorToCorrectPosition", 
        testPrefixPlusPlusSetsConstIteratorToCorrectPosition 
    };
    ListIteratorTestCase::allTests.push_back(t17);
    TestNameAndFunc t18 = 
    { 
        "testPostfixPlusPlusSetsConstIteratorToCorrectPosition", 
        testPostfixPlusPlusSetsConstIteratorToCorrectPosition 
    };
    ListIteratorTestCase::allTests.push_back(t18);
    TestNameAndFunc t19 = 
    { 
        "testPrefixMinusMinusSetsConstIteratorToCorrectPosition", 
        testPrefixMinusMinusSetsConstIteratorToCorrectPosition 
    };
    TestNameAndFunc t20 = 
    { 
        "testPostfixMinusMinusSetsConstIteratorToCorrectPosition", 
        testPostfixMinusMinusSetsConstIteratorToCorrectPosition 
    };
    ListIteratorTestCase::allTests.push_back(t20);
    TestNameAndFunc t21 = 
    { 
        "testTwoListsOfIntsFromOneToNineMustCompareEqual", 
        testTwoListsOfIntsFromOneToNineMustCompareEqual 
    };
    ListIteratorTestCase::allTests.push_back(t21);
    TestNameAndFunc t22 = 
    { 
        "testTwoDifferentListsOfIntsMustNotCompareEqual", 
        testTwoDifferentListsOfIntsMustNotCompareEqual 
    };
    ListIteratorTestCase::allTests.push_back(t22);
    TestNameAndFunc t23 = 
    { 
        "testIfStablePartitionAlgorithmSortsOddsToTheLeftInSequenseFromOneToNine", 
        testIfStablePartitionAlgorithmSortsOddsToTheLeftInSequenseFromOneToNine 
    };
    ListIteratorTestCase::allTests.push_back(t23);
    TestNameAndFunc t24 = 
    { 
        "testReversedSequensFromOneToNineObtainedWithReverseIteratorsMustBeEqualToSequenceFromNineToOne", 
        testReversedSequensFromOneToNineObtainedWithReverseIteratorsMustBeEqualToSequenceFromNineToOne 
    };
    ListIteratorTestCase::allTests.push_back(t24);
}

void ListIteratorTestCase::run()
{
    initTests();
    runAllTests();
    runLeaks();
}

/*
** --------------------------------- TEST_FUNCTIONS ----------------------------
*/
//DONE
void ListIteratorTestCase::testIteratorsOfTwoListsWithSameSequencesMustNotBeEqual()
{
    //Arrange
    ft::list<int> l;
    ft::list<int> l1;
    
    l.push_back(1);
    l1.push_back(1);
    ft::list<int>::iterator it = l.begin();
    ft::list<int>::iterator it1 = l1.begin();
    
    //Act
    int expected = false;
    int actual = (it == it1);
    //Assert
    assertEqual(expected, actual);
}
//DONE
void ListIteratorTestCase::testCopyConstructionMustProduceEqualIterators()
{
    //Arrange
    ft::list<int> l;
    
    l.push_back(1);
    ft::list<int>::iterator it = l.begin();
    ft::list<int>::iterator it_copy(it);
    
    //Act
    int expected = true;
    int actual = (it == it_copy);
    //Assert
    assertEqual(expected, actual);
}
//DONE
void ListIteratorTestCase::testAssignationMustProduceEqualIterators()
{
    //Arrange
    ft::list<int> l;
    
    l.push_back(1);
    ft::list<int>::iterator it = l.begin();
    ft::list<int>::iterator it_copy = it;
    
    //Act
    int expected = true;
    int actual = (it == it_copy);
    //Assert
    assertEqual(expected, actual);
}
//DONE
void ListIteratorTestCase::testIteratorYieldsCorrectValueWhenDereferenced()
{
    //Arrange
    ft::list<int> l;
    
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    ft::list<int>::iterator it = l.begin();
    
    //Act
    int expected1 = 1;
    int expected2 = 2;
    int expected3 = 3;
    int actual1 = *it;
    it++;
    int actual2 = *it;
    it++;
    int actual3 = *it;

    //Assert
    assertEqual(expected1, actual1);
    assertEqual(expected2, actual2);
    assertEqual(expected3, actual3);
}
//DONE
void ListIteratorTestCase::testIteratorYieldsCorrectValueWhenDereferencedWithArrow()
{
    //Arrange
    ft::list<TestClass> l;
    TestClass t;

    t.value = 1;
    l.push_back(t);
    t.value = 2;
    l.push_back(t);
    t.value = 3;
    l.push_back(t);
    ft::list<TestClass>::iterator it = l.begin();
    
    //Act
    int expected1 = 1;
    int expected2 = 2;
    int expected3 = 3;
    int actual1 = it->value;
    it++;
    int actual2 = it->value;
    it++;
    int actual3 = it->value;

    //Assert
    assertEqual(expected1, actual1);
    assertEqual(expected2, actual2);
    assertEqual(expected3, actual3);
}
//DONE
void ListIteratorTestCase::testMutableIteratorAllowsToCorrectlySetListValue()
{
    //Arrange
    ft::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    ft::list<int>::iterator it = l.begin();
    ft::list<int>::iterator it1 = l.begin();

    //Act
    it++;
    *it = 42;
    int expected = 42;
    it1++;
    int actual = *it1;
    
    //Assert
    assertEqual(expected, actual);    
}
//DONE
void ListIteratorTestCase::testPrefixPlusPlusSetsIteratorToCorrectPosition()
{
    //Arrange
    ft::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(10);
    l.push_back(4);
    ft::list<int>::iterator it = l.begin();

    //Act
    ++it;
    ++it;
    int actual = *it;
    int expected = 10;
    
    //Assert
    assertEqual(expected, actual);    
}
//DONE
void ListIteratorTestCase::testPrefixPlusPlusReturnValueMustBeValueAfterOpCall()
{
    //Arrange
    ft::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(10);
    l.push_back(4);
    ft::list<int>::iterator it = l.begin();

    //Act
    ++it;
    int actual = *(++it);
    int expected = 10;
    
    //Assert
    assertEqual(expected, actual);    
}
//DONE
void ListIteratorTestCase::testPostfixPlusPlusSetsIteratorToCorrectPosition()
{
    //Arrange
    ft::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(10);
    l.push_back(4);
    ft::list<int>::iterator it = l.begin();

    //Act
    it++;
    it++;
    int actual = *it;
    int expected = 10;
    
    //Assert
    assertEqual(expected, actual);    
}
//DONE
void ListIteratorTestCase::testPrefixMinuMinusSetsIteratorToCorrectPosition()
{
    //Arrange
    ft::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(10);
    l.push_back(4);
    ft::list<int>::iterator it = l.begin();

    //Act
    it++;
    it++;
    it++;
    --it;
    int actual = *it;
    int expected = 10;
    
    //Assert
    assertEqual(expected, actual);    
}
//DONE
void ListIteratorTestCase::testPostfixMinuMinusSetsIteratorToCorrectPosition()
{
    //Arrange
    ft::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(10);
    l.push_back(4);
    ft::list<int>::iterator it = l.begin();

    //Act
    it++;
    it++;
    it++;
    it--;
    int actual = *it;
    int expected = 10;
    
    //Assert
    assertEqual(expected, actual);    
}
//Done
void ListIteratorTestCase::testConstIteratorsOfTwoListsWithSameSequencesMustNotBeEqual()
{
    //Arrange
    ft::list<int> l;
    ft::list<int> l1;
    
    l.push_back(1);
    l1.push_back(1);
    ft::list<int>::const_iterator it = l.begin();
    ft::list<int>::const_iterator it1 = l1.begin();
    
    //Act
    int expected = false;
    int actual = (it == it1);
    //Assert
    assertEqual(expected, actual);
}
//DONE
void ListIteratorTestCase::testCopyConstructionMustProduceEqualConstIterators()
{
    //Arrange
    ft::list<int> l;
    
    l.push_back(1);
    ft::list<int>::const_iterator it = l.begin();
    ft::list<int>::const_iterator it_copy(it);
    
    //Act
    int expected = true;
    int actual = (it == it_copy);
    //Assert
    assertEqual(expected, actual);
}
//DONE
void ListIteratorTestCase::testAssignationMustProduceEqualConstIterators()
{
    //Arrange
    ft::list<int> l;
    
    l.push_back(1);
    ft::list<int>::const_iterator it = l.begin();
    ft::list<int>::const_iterator it_copy;
    
    //Act
    it_copy = it;
    int expected = true;
    int actual = (it == it_copy);
    //Assert
    assertEqual(expected, actual);
}
//CONSTRUCTION
void ListIteratorTestCase::testConstIteratorYieldsCorrectValueWhenDereferenced()
{
    //Arrange
    ft::list<int> l;
    
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    ft::list<int>::const_iterator it = l.begin();
    
    //Act
    int expected1 = 1;
    int expected2 = 2;
    int expected3 = 3;
    int actual1 = *it;
    it++;
    int actual2 = *it;
    it++;
    int actual3 = *it;

    //Assert
    assertEqual(expected1, actual1);
    assertEqual(expected2, actual2);
    assertEqual(expected3, actual3);
}
//DONE
void ListIteratorTestCase::testConstIteratorYieldsCorrectValueWhenDereferencedWithArrow()
{
    //Arrange
    ft::list<TestClass> l;
    TestClass t;

    t.value = 1;
    l.push_back(t);
    t.value = 2;
    l.push_back(t);
    t.value = 3;
    l.push_back(t);
    ft::list<TestClass>::const_iterator it = l.begin();
    
    //Act
    int expected1 = 1;
    int expected2 = 2;
    int expected3 = 3;
    int actual1 = it->value;
    it++;
    int actual2 = it->value;
    it++;
    int actual3 = it->value;

    //Assert
    assertEqual(expected1, actual1);
    assertEqual(expected2, actual2);
    assertEqual(expected3, actual3);
}
//DONE
void ListIteratorTestCase::testPrefixPlusPlusSetsConstIteratorToCorrectPosition()
{
    //Arrange
    ft::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(10);
    l.push_back(4);
    ft::list<int>::const_iterator it = l.begin();

    //Act
    ++it;
    ++it;
    int actual = *it;
    int expected = 10;
    
    //Assert
    assertEqual(expected, actual);    
}

//DONE
void ListIteratorTestCase::testPostfixPlusPlusSetsConstIteratorToCorrectPosition()
{
    //Arrange
    ft::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(10);
    l.push_back(4);
    ft::list<int>::const_iterator it = l.begin();

    //Act
    it++;
    it++;
    int actual = *it;
    int expected = 10;
    
    //Assert
    assertEqual(expected, actual);    
}
//DONE
void ListIteratorTestCase::testPrefixMinusMinusSetsConstIteratorToCorrectPosition()
{
    //Arrange
    ft::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(10);
    l.push_back(4);
    ft::list<int>::const_iterator it = l.begin();

    //Act
    it++;
    it++;
    it++;
    --it;
    int actual = *it;
    int expected = 10;
    
    //Assert
    assertEqual(expected, actual);    
}
//DONE
void ListIteratorTestCase::testPostfixMinusMinusSetsConstIteratorToCorrectPosition()
{
    //Arrange
    ft::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(10);
    l.push_back(4);
    ft::list<int>::const_iterator it = l.begin();

    //Act
    it++;
    it++;
    it++;
    it--;
    int actual = *it;
    int expected = 10;
    
    //Assert
    assertEqual(expected, actual);    
}

//DONE
void ListIteratorTestCase::testTwoListsOfIntsFromOneToNineMustCompareEqual()
{
    //arrange
    ft::list<int> l1;
    ft::list<int> l2;
    for (int i = 1; i <= 9; i++)
    {
        l1.push_back(i);
        l2.push_back(i);
    }
    //Act
    int result = std::equal(l1.begin(), l1.end(), l2.begin());
    //Assert
    assertTrue(result);
}

//DONE
void ListIteratorTestCase::testTwoDifferentListsOfIntsMustNotCompareEqual()
{
    //arrange
    ft::list<int> l1;
    ft::list<int> l2;
    for (int i = 1; i <= 9; i++)
    {
        l1.push_back(i);
        l2.push_back(i + 5);
    }
    //Act
    int result = std::equal(l1.begin(), l1.end(), l2.begin());
    //Assert
    assertFalse(result);
}

//DONE
void ListIteratorTestCase::testIfStablePartitionAlgorithmSortsOddsToTheLeftInSequenseFromOneToNine()
{
    //Arrange
    ft::list<int> l;
    int i = 0;
    while (++i <= 9)
        l.push_back(i);
    int arr[9] = { 1, 3, 5, 7, 9, 2, 4, 6, 8 };
    ft::list<int>::iterator bound;
    //Act
    bound = std::stable_partition (l.begin(), l.end(), IsOdd);
    int result = std::equal(l.begin(), l.end(), arr);
    //Assert
    assertTrue(result);
}

//DONE
void ListIteratorTestCase::testReversedSequensFromOneToNineObtainedWithReverseIteratorsMustBeEqualToSequenceFromNineToOne()
{
    //Arrange
    ft::list<int> listToTraverseBackwards;
    for (int i = 1; i <= 9; i++)
    {
        listToTraverseBackwards.push_back(i);
    }
    std::list<int> expectedReversedList;
    for (int i = 9; i >= 1; i--) expectedReversedList.push_back(i);

    //Act
    ft::list<int> actualReversedList;
    ft::list<int>::reverse_iterator itRBegin = listToTraverseBackwards.rbegin();
    ft::list<int>::reverse_iterator itREnd = listToTraverseBackwards.rend();
    for (; itRBegin != itREnd; itRBegin++) 
    {
        actualReversedList.push_back(*itRBegin);
    }
    //Assert
    bool result = std::equal(actualReversedList.begin(), actualReversedList.end(), expectedReversedList.begin());
    assertTrue(result);
}

//CONSTRUCTION
// void ListIteratorTestCase::testFuncName()
// {

// }
/* ************************************************************************** */