#include "TestCase.hpp"

TestCase::TestCase() {}

TestCase::TestCase( const TestCase & src ) { (void)src; }

TestCase::~TestCase() {}

TestCase &TestCase::operator=( TestCase const & rhs ) { (void)rhs; return *this; }

/*
** --------------------------------- PUBLIC METHODS ----------------------------
*/

void TestCase::run() {}

/*
** --------------------------------- PROTECTED ---------------------------------
*/

std::vector<TestCase::TestNameAndFunc> TestCase::allTests;

void TestCase::initTests() {}

void TestCase::runAllTests()
{
    std::vector<TestNameAndFunc>::const_iterator it_begin;
    std::vector<TestNameAndFunc>::const_iterator it_end;
    
    it_begin = TestCase::allTests.begin();
    it_end = TestCase::allTests.end();
    for (; it_begin != it_end; it_begin++)
    {
        _runTest(*it_begin);
    }
}

void TestCase::_runTest(const TestNameAndFunc &testNameAndFunc)
{
    std::cout << MAGENTA << "--- " << testNameAndFunc.name << RESET << std::endl;
    (*(testNameAndFunc.testFunctionPtr))();
}

void TestCase::assertTrue(bool result)
{
    if (result)
        std::cout << GREEN << "--- Success" << RESET << std::endl;
    else
    {
        std::cout << RED << "--- Failed" << RESET << std::endl;
        exit(0);
    }
}

void TestCase::assertFalse(bool result)
{
    if (!result)
        std::cout << GREEN << "--- Success" << RESET << std::endl;
    else
    {
        std::cout << RED << "--- Failed" << RESET << std::endl;
        exit(0);
    }
}
static std::vector<std::string> splitPathVar(char *val)
{
    std::vector<std::string> dirs;
    std::string path(val);
    size_t semicolonPos;
    while ((semicolonPos = path.find(":", 0)) != std::string::npos)
    {
        dirs.push_back(path.substr(0, semicolonPos));
        path.replace(0, semicolonPos + 1, "");
    }
    return dirs;
}
static bool hasLeaksUtility(const std::string &dirPath)
{
    DIR *dir = opendir(dirPath.c_str());
    if (dir == 0)
    {
        std::cerr << "Error: failed to open dir for reading. Memory check can\
            not run" << std::endl;
        exit(1);
    }
    struct dirent *entry;
    bool hasLeaksUtility = false;
    while ((entry = readdir(dir)))
    {
        if (strcmp(entry->d_name, "leaks") == 0)
            hasLeaksUtility = true;
    }
    closedir(dir);
    return hasLeaksUtility;
}
std::string TestCase::_getLeaksUtilityOSPath()
{
    char *pathVar = getenv("PATH");
    if (pathVar == 0) 
    {
        std::cerr << "Error: failed to get env var PATH. Memory check can\
            not run" << std::endl;
        exit(1);
    }
    std::vector<std::string> dirs = splitPathVar(pathVar);
    for (std::vector<std::string>::iterator it = dirs.begin(); it < dirs.end(); it++)
    {
        if (hasLeaksUtility(*it))
            return *it + std::string("/leaks");
    }
    return std::string("");
}

void TestCase::runLeaks()
{
    std::string path = _getLeaksUtilityOSPath();
    if (path == "")
    {
        std::cerr << "Error: failed to locate leaks in OS. Memory check can\
            not run" << std::endl;
        exit(1);
    }
    char *args[3];
    args[0] = const_cast<char*>(path.c_str());
    args[1] = const_cast<char*>(std::string("a.out").c_str());
    args[2] = 0;
    pid_t pid = fork();
    if (pid == 0)
    {
        execve(args[0] ,args, NULL);
    }
    wait(NULL);
}
/*
** --------------------------------- PROTECTED METHODS -------------------------
*/

/* ************************************************************************** */