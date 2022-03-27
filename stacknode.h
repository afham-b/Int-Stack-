#pragma once

// StackNode - A node in the linked list structure
template <typename T>
struct StackNode {
	T info; // The data stored in the node
	StackNode *pNext; // Points to next node
};

// Stack - A linked-list implementation of a stack
template <typename T>
class Stack {
private:
	StackNode<T> *pTop; // Points to top node
public:
	Stack (); // Initialize the stack
	~Stack (); // Destroy the stack
	bool empty () const; // Check if stack is empty
	void pop (); // Pop the stack (remove top item)
	void push (const T& item); // Push item onto stack
	T& top (); // Access item on top of stack
};

template <typename T>
Stack<T>::Stack () {
	// Initialize top pointer to NULL to
	//	indidate stack is initially empty
	pTop = nullptr;
}

template <typename T>
Stack<T>::~Stack () {
	// Pop all items from the stack
	while (!empty())
		pop();
}

template <typename T>
bool Stack<T>::empty () const {
	// Stack is empty if the top pointer is NULL
	return pTop == nullptr;
}

template <typename T>
void Stack<T>::pop () {
	// Pop the stack (remove top item)
	// Save pointer to current top
	StackNode<T> *p = pTop;
	// Set top pointer to current top's next pointer
	pTop = p->pNext;
	// Destroy former top node
	delete p;
}

template <typename T>
void Stack<T>::push (const T& item) {
	// Push an item onto the stack
	// Create a new node
	StackNode<T> *p = new StackNode<T>;
	// Set new node's info item
	p->info = item;
	// Set new node's next pointer to current top
	p->pNext = pTop;
	// Set new top of stack to the new node
	pTop = p;
}

template <typename T>
T& Stack<T>::top () {
	// Return a reference to the info in top node
	return pTop->info;
}