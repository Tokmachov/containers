#include <string>
# include "ListIteratorTestCase.hpp"
# include "ListTestCase.hpp"
# include "VectorTestCase.hpp"
# include <unistd.h>

template <typename T>
void printVector(ft::vector<T> &v)
{
    for (int i = 0; i < v.capacity(); i++)
    {
        std::cout << " |" << v[i] << "|" << std::endl;
    }
    std::cout << std::endl;
}

void test()
{
    //Arrange
    ft::vector<int> vec;
    //Act
    vec.push_back(1);
    printVector(vec);
    vec.push_back(2);
    printVector(vec);
    vec.push_back(3);
    printVector(vec);
}

int main(void)
{
    //ListIteratorTestCase::run();
    //ListTestCase::run();
    VectorTestCase::run();
    return 0;
}








