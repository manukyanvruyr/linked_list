#include "linked_list.hpp"

int main()
{
	linked_list<int> l1(1);
	l1.print();
	linked_list<int> l2{1, 2, 3, 4};
	l2.print();
	l1.reverse();
	l1.print();
	l2.reverse();
	l2.print();
}
