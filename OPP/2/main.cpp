
#include "tree.h"

int main()
{
	unsigned int action;
	btree q;
	node* z;
    int key;
	while (true)
	{
		std::cout << "================" << std::endl;
		std::cout << "Menu:" << std::endl;
		std::cout << "1) Add figure" << std::endl;
		std::cout << "2) Delete figure" << std::endl;
		std::cout << "3) Print" << std::endl;
		std::cout << "0) Quit" << std::endl;
		std::cin >> action;

		if (action == 0)
			break;

		if (action > 3)
		{
			std::cout << "Error: invalid action" << std::endl;

			continue;
		}

		switch (action)
		{
			case 1:
			{
                 std::cout << "Enter key" << std::endl;
		        std::cin >> key;
				Square square(std::cin);
				q.insert(square,key);
				break;
			}

			case 2:
			{
                 std::cout << "Enter key" << std::endl;
		        std::cin >> key; 
                z=q.search(key);
                std::cout << z->value->getSquare();
				break;
			}

			case 3:
			{
			std::cout << q;

				break;
			}
		}
	}
	
	return 0;
}
