#pragma once
#include <iostream>

template <class Type>
class Cnode {
	Type data;
	Cnode<Type>* Left;
	Cnode<Type>* Right;

public:
	Cnode(Type data1) {
		data = data1;
		Left = nullptr;
		Right = nullptr;
	}

	void SetLeft(Cnode<Type>* newNode) {
		Left = newNode;
	}

	void SetRight(Cnode<Type>* newNode) {
		Right = newNode;
	}

	Type GetData() {
		return data;
	}

	Cnode<Type>* GetLeft() { return Left; }
	Cnode<Type>* GetRight() { return Right; }

	Cnode operator=(const Cnode right) {
		this->data = right.data;
		this->Left = right.Left;
		this->Right = right.Right;
	}
};


template <class Type>
class Tree
{
	Cnode<Type>* root;

public:
	Tree() {
		root = nullptr;
	}

	Tree(Type root1) {
		Cnode<Type> newroot(root1);
		root = newroot;
	}

	void Push(Type newElement);
	void DelElement(Type element);
};

template <class Type>
class FindTree : Tree
{
	Cnode<Type>* root;
public:
	void Push(Type newElement) override
	{
		Cnode<Type>* Copy = root;
		Cnode<Type>* NewNode(newElement);
		if (root == nullptr) root = NewNode;
		else {
			while (Copy->GetLeft != NewNode && Copy->GetRight != NewNode) {
				if (Copy->GetData() < newElement) {
					if (Copy->GetLeft() != nullptr) { Copy = Copy->GetLeft; }
					else Copy->SetLeft(NewNode);
				}
				else {
					if (Copy->GetRight() != nullptr) { Copy = Copy->GetRight; }
					else Copy->SetRight(NewNode);
				}
			}
		}
	}

	Cnode<Type>* Find(Type FindElement) {
		Cnode<Type>* Copy = root;
		while (Copy->GetLeft != nullptr && Copy->GetRight != nullptr) {
			if (Copy->GetData() == FindElement) return Copy;
			if (Copy->GetData() > FindElement) Copy = Copy->GetLeft();
			else Copy = Copy->GetRight();
		}
		return nullptr;
	}

	void DelElement(Type element) override {
		Cnode<Type>* Copy = Find(element);
		bool flag = true;
		if (Copy != nullptr) {
			Cnode<Type>* Copy2 = root;
			while (Copy2->GetLeft() != Copy && Copy2->GetRight() != Copy)
			{
				if (Copy2->GetData() > Copy->GetData()) {
					Copy2 = Copy2->GetLeft();
					flag = true
				}
				else
				{
					Copy2 = Copy2->GetRight();
					flag = false;
				}
			}
			if (Copy->Left->GetData > Copy->Right->GetData()) {
				if (flag) Copy2->SetLeft(Copy->Left);
				else Copy2->SetLeft(Copy->Left);
			}
			else {
				if (flag) Copy2->SetLeft(Copy->Right);
				else Copy2->SetLeft(Copy->Right);
			}
			while (Copy->GetLeft != NewNode && Copy->GetRight != NewNode) {
				if (Copy->GetData() < newElement) {
					if (Copy->GetLeft() != nullptr) { Copy = Copy->GetLeft; }
					else Copy->SetLeft(NewNode);
				}
				else {
					if (Copy->GetRight() != nullptr) { Copy = Copy->GetRight; }
					else Copy->SetRight(NewNode);
				}
			}
				
		}
	}
};

