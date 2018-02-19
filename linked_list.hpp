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
	Node<T>* get_root() const
	{
		return m_root;
	}

	void set_root(Node<T>* r)
	{
		m_root = r;
	}

public:
	bool operator==(const linked_list& l) const
	{
		auto node = m_root;
		auto lnode = l.m_root;
		while (nullptr != node && nullptr != lnode) {
			if (node->value != lnode->value) {
				return false;
			}
			node = node->next;
			lnode = lnode->next;
		}
		return node == lnode; // == nullptr
	}

private:
	Node<T>* m_root;
};
