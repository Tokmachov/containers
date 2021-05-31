#include <string>
# include "ListIteratorTestCase.hpp"
# include "ListTestCase.hpp"
# include "VectorTestCase.hpp"

# include <vector>

int main(void)
{
    //ListIteratorTestCase::run();
    //ListTestCase::run();
    //VectorTestCase::run();
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    std::vector<int>::reverse_iterator rit = v.rbegin();
    rit++;
    std::cout << *(rit) << std::endl;
    std::cout << *(rit - 1) << std::endl;
    return 0;
}