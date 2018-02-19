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
    Node<int>* prev = nullptr;
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

}
