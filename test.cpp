#include <assert.h>

#include "linked_list.hpp"
#include "utility.hpp"

namespace
{
	void check_reverse()
	{
		linked_list<int> l1(1);
		utility::reverse(l1);
		assert(l1 == linked_list<int>(1));
		linked_list<int> l2{1, 2, 3, 4};
		utility::reverse(l2);
		assert((l2 == linked_list<int>{4, 3, 2, 1}));
	}

	void check_remove()
	{
		linked_list<int> l{2, 1, 2, 3, 4, 2, 5, 1, 2};
		utility::remove(l, 2);
		assert((l == linked_list<int>{1, 3, 4, 5, 1}));
	}
}

namespace test
{

void run()
{
	check_reverse();
	check_remove();
}

}
