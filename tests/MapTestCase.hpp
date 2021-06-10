
#ifndef MAPTESTCASE_HPP
# define MAPTESTCASE_HPP

# include <iostream>
# include <string>
# include "TestCase.hpp"
# include "../map/map.hpp"

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
};

#endif /* ************************************************ MapTestCase_H */