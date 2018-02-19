#pragma once

#include "linked_list.hpp"

namespace utility
{

template <typename T>
void print(const linked_list<T>& l);

template <typename T>
void reverse(linked_list<T>& l);

template <typename T>
void remove(linked_list<T>& l, const T& k);

}
#include "utility.h"
