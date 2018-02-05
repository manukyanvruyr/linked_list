#pragma once

#include <iostream>

template <typename T>
struct Node
{
	T value = T();
	Node* next = nullptr;

	Node(T v) : value(v), next(nullptr)
	{}
};

template <typename T>
class linked_list
{
public:
	linked_list(const T& v)
	{
		m_root = new Node<T>(v);
		m_root->value = v;
	}

	linked_list(std::initializer_list<T> list)
	{
		Node<T>** current = &m_root;
		for (auto v : list) {
			*current = new Node<T>(v);
			current = &((*current)->next);
		}
	}

	~linked_list()
	{
		auto node = m_root;
		while (node) {
			auto next = node->next;
			delete node;
			node = next;
		}
	}

public:
	linked_list() = default;
	linked_list(const linked_list&) = delete;
	linked_list(linked_list&&) = delete;
	linked_list& operator=(const linked_list&) = delete;
	linked_list& operator=(linked_list&&) = delete;

public:
	void print() const
	{
		auto node = m_root;
		while (node) {
			std::cout << node->value << " ";
			node = node->next;
		}
		std::cout << std::endl;
	}

	void reverse()
	{
		if (0 == m_root) {
			return;
		}
		Node<T>* prev = nullptr;
		Node<T>* next = nullptr;
		while (m_root) {
			next = m_root->next;
			m_root->next = prev;
			prev = m_root;
			m_root = next;
		}
		m_root = prev;
	}

private:
	Node<T>* m_root;
};
