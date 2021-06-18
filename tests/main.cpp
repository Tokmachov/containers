# include "ListIteratorTestCase.hpp"
# include "ListTestCase.hpp"
# include "VectorTestCase.hpp"
# include "MapTestCase.hpp"
# include "StackTestCase.hpp"
# include "QueueTestCase.hpp"

# include <iostream>

int	main()
{
	while (true)
	{
		std::cout << "Chose test to run" << std::endl;
		std::cout << "1 - list\n";
		std::cout << "2 - vector\n";
		std::cout << "3 - map\n";
		std::cout << "4 - stack\n";
		std::cout << "5 - queue\n";
		std::cout << "0 - exit\n";
		std::string chose;
		std::cin >> chose;
		switch (atoi(chose.c_str()))
		{
			case 0:
				exit(0);
				break;
			case 1:
				ListIteratorTestCase::run();
				ListTestCase::run();
				break;
			case 2:
				VectorTestCase::run();
				break;
			case 3:
				MapTestCase::run();
				break;
			case 4:
				StackTestCase::run();
				break;
			case 5:
				QueueTestCase::run();
				break;
		}
	}
	return 0;
}