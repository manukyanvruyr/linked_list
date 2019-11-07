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

template <typename T>
T get_middle_element(const linked_list<T>& l);

template <typename T>
T get_k_to_last(const linked_list<T>& l, int k);

}

#include "utility.h"
