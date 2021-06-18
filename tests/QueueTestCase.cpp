#include "QueueTestCase.hpp"

QueueTestCase::QueueTestCase() {}

QueueTestCase::QueueTestCase( const QueueTestCase & src ){ (void)src; }

QueueTestCase::~QueueTestCase() {}

QueueTestCase &QueueTestCase::operator=( QueueTestCase const & rhs )
{
	(void)rhs;
    return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
//Configure init function so it fills allTests var properly with your test funcitons
//and funciton names
void QueueTestCase::initTests()
{
    TestNameAndFunc t1 = 
    { 
        "testQueueEmpty_CreateQueueWithEnptyListAndCallEmpty_True", 
        testQueueEmpty_CreateQueueWithEnptyListAndCallEmpty_True
    };
    QueueTestCase::allTests.push_back(t1);
	TestNameAndFunc t2 =
	{
		"testQueueEmpty_CreateQueueFromNoEmptyListAndCallEmpty_True", 
		testQueueEmpty_CreateQueueFromNoEmptyListAndCallEmpty_True
	};
	QueueTestCase::allTests.push_back(t2);
	TestNameAndFunc t3 =
	{
		"testQueueSize_CreateQueueFromEmptyListAndCallSize_Zero", 
		testQueueSize_CreateQueueFromEmptyListAndCallSize_Zero
	};
	QueueTestCase::allTests.push_back(t3);
	TestNameAndFunc t4 =
	{
		"testQueueSize_CreateQueueFromListFilledWithTwoElements_Two", 
		testQueueSize_CreateQueueFromListFilledWithTwoElements_Two
	};
	QueueTestCase::allTests.push_back(t4);
}

void QueueTestCase::run()
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

void QueueTestCase::testQueueEmpty_CreateQueueWithEnptyListAndCallEmpty_True()
{
    //Arrange
    ft::queue<int, ft::list<int> > s;
    //act
    bool result = s.empty();
    //Assert
    assertTrue(result);
}
void QueueTestCase::testQueueEmpty_CreateQueueFromNoEmptyListAndCallEmpty_True()
{
	//Arrange
    ft::list<int> v(5, 10);
    ft::queue<int, ft::list<int> > q(v);
    //act
    bool result = q.empty();
    //Assert
    assertFalse(result);
}
void QueueTestCase::testQueueSize_CreateQueueFromEmptyListAndCallSize_Zero()
{
	//Arrange
    ft::list<int> l;
    ft::queue<int, ft::list<int> > q(l);
    //act
    int result = l.size();
    //Assert
    assertTrue(result == 0);
}
void QueueTestCase::testQueueSize_CreateQueueFromListFilledWithTwoElements_Two()
{
	//Arrange
    ft::list<int> l(2, 5);
    ft::queue<int, ft::list<int> > q(l);
    //act
    int result = q.size();
    //Assert
    assertTrue(result == 2);
}



/* ************************************************************************** */
