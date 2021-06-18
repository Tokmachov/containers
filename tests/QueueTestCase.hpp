
#ifndef QUEUETESTCASE_HPP
# define QUEUETESTCASE_HPP

# include <iostream>
# include <string>
# include "TestCase.hpp"
# include "../queue/queue.hpp"

class QueueTestCase : public TestCase
{
	public:
        static void run();
	protected:
        static void initTests();
    private:
        QueueTestCase();
		QueueTestCase( QueueTestCase const & src );
		~QueueTestCase();
		QueueTestCase &		operator=( QueueTestCase const & rhs );
        
        //support type
        class TestClass
        {
            public:
            int value;
        };
        //Test functions
        //Please write declaration of test functions here
        static void testQueueEmpty_CreateQueueWithEnptyListAndCallEmpty_True();
        static void testQueueEmpty_CreateQueueFromNoEmptyListAndCallEmpty_True();
        static void testQueueSize_CreateQueueFromEmptyListAndCallSize_Zero();
        static void testQueueSize_CreateQueueFromListFilledWithTwoElements_Two();
        static void testQueueFront_CreateQueueFromListOfOneTwoThreeAndCallFront_ReturnIsEqualToFirstElementOfList();
        static void testQueueBack_CreateQueueFromListOfOneTwoThreeAndCallBack_ReturnIsThree();
        static void testQueueBack_CreateQueueAndPushThreeThenTwoThenOneAndCallFrontAndBack_FrontReturnsThreeAndBackReturnsOne();
        static void testQueuePop_PushOneTwoThreeFourCallPop_FrontReturnsTwo();
};

#endif /* ************************************************ QueueTestCase_H */