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
    assertTrue(true);
}
/* ************************************************************************** */