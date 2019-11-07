#pragma once

#include <iostream>

namespace utility
{

template <typename T>
void print(const linked_list<T>& l)
{
    auto node = l.get_root();
    while (node) {
	std::cout << node->value << " ";
	node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void reverse(linked_list<T>& l)
{
    auto root = l.get_root();
    if (0 == root) {
	return;
    }
    Node<T>* prev = nullptr;
    Node<T>* next = nullptr;
    while (root) {
	next = root->next;
	root->next = prev;
	prev = root;
	root = next;
    }
    l.set_root(prev);
}

template <typename T>
void remove(linked_list<T>& l, const T& k)
{
    auto root = l.get_root();
    auto current = root;
    Node<T>* prev = nullptr;
    while (nullptr != current) {
	if (k == current->value) {
	    if (nullptr == prev) {
		root = current->next;
		current = current->next;
		continue;
	    }
	    prev->next = current->next;
	}
	prev = current;
	current = current->next;
    }
    l.set_root(root);
}

template <typename T>
T get_middle_element(const linked_list<T>& l)
{
    auto single_step = l.get_root();
    auto double_step = l.get_root();
    while (true) {
	if (nullptr == double_step->next || nullptr == double_step->next->next) {
	    break;
	}
	double_step = double_step->next->next;
	single_step = single_step->next;
    }
    return single_step->value;
}

template <typename T>
T get_k_to_last(const linked_list<T>& l, int k) {
    if (k < 1) {
	std::cout << "k should be > 0\n";
	throw "Invalid input";
    }
    int i = 0;
    auto fast = l.get_root();
    while (i < k) {
	if (fast == nullptr) {
	    std::cout << "The linked list length shorter than " << k << std::endl;
	    throw "Invalid input";
	}
	fast = fast->next;
	++i;
    }
    auto current = l.get_root();
    while (fast != nullptr) {
	current = current->next;
	fast = fast->next;
    }
    return current->value;
}

}
