#include <assert.h>

#include "linked_list.hpp"
#include "utility.hpp"

namespace
{

void check_reverse()
{
	linked_list<int> l1(1);
	utility::reverse(l1);
	assert((l1 == linked_list<int>(1)));
	linked_list<int> l2{1, 2, 3, 4};
	utility::reverse(l2);
	assert((l2 == linked_list<int>{4, 3, 2, 1}));
}

void check_remove()
{
	linked_list<int> l1{2, 1, 2, 3, 4, 2, 5, 1, 2};
	utility::remove(l1, 2);
	assert((l1 == linked_list<int>{1, 3, 4, 5, 1}));
	linked_list<int> l2{2};
	utility::remove(l2, 2);
	assert((l2 == linked_list<int>()));
	linked_list<int> l3{1, 2, 3, 2, 2, 1};
	utility::remove(l3, 1);
	assert((l3 == linked_list<int>{2, 3, 2, 2}));
}

void check_middle_element()
{
	linked_list<int> l1{1, 2, 3, 4, 5};
	assert(3 == utility::get_middle_element(l1));
	linked_list<int> l2{1, 2, 3, 4, 5, 6};
	assert(3 == utility::get_middle_element(l2));
	linked_list<int> l3{1, 2, 3};
	assert(2 == utility::get_middle_element(l3));
}

void check_k_to_last()
{
	linked_list<int> l{2, 3, 4, 5, 6, 2, 1, 9};
	assert(9 == utility::get_k_to_last(l, 1));
	assert(1 == utility::get_k_to_last(l, 2));
	assert(6 == utility::get_k_to_last(l, 4));
}

}

namespace test
{

void run()
{
	check_reverse();
	check_remove();
	check_middle_element();
	check_k_to_last();
}

}
