#include "BinaryTree.h"
#include <iostream>
void BinaryTree::AddReqNode(int value, Node* node)
{
	//if(node)

	if (value <= node->value)
		AddReqNode(value, node->leftChild);
	else
		AddReqNode(value, node->rightChild);
}

void BinaryTree::ListReq(Node* node)
{
	if (node)
	{
		ListReq(node->leftChild);
		std::cout << node->value << " ";
		ListReq(node->rightChild);
	}
}

Node* BinaryTree::Root()
{
	return this->root;
}

void BinaryTree::AddLoop(int value)
{
	Node* nodeNew{ root };
	Node* nodeParent{ nullptr };

	while (nodeNew)
	{
		nodeParent = nodeNew;
		if (value <= nodeNew->value)
			nodeNew = nodeNew->leftChild;
		else
			nodeNew = nodeNew->rightChild;
	}
	
	nodeNew = new Node();
	nodeNew->value = value;
	if (root)
	{
		if (nodeNew->value <= nodeParent->value)
			nodeParent->leftChild = nodeNew;
		else
			nodeParent->rightChild = nodeNew;
		nodeNew->parent = nodeParent;
	}
	else
		root = nodeNew;
	
	size++;
}

void BinaryTree::AddReq(int value)
{
	AddReqNode(value, this->root);
}

Node* BinaryTree::Find(int keyValue)
{
	Node* nodeFind{ root };

	while (nodeFind)
	{
		if (nodeFind->value == keyValue)
		{
			break;
		}
		else
		{
			if (keyValue <= nodeFind->value)
				nodeFind = nodeFind->leftChild;
			else
				nodeFind = nodeFind->rightChild;
		}
	}

	return nodeFind;
}

void BinaryTree::Delete(Node* node)
{
	// delete leaf
	if (!node->leftChild && !node->rightChild)
	{
		if (node == root)
			root = nullptr;
		else
		{
			if (node->parent->leftChild == node)
				node->parent->leftChild = nullptr;
			else
				node->parent->rightChild = nullptr;
		}
		delete node;
		return;
	}
	

	// delete single node
	// (a && !b) || (!a && b)
	if (node->leftChild && !node->rightChild || !node->leftChild && node->rightChild)
	{
		

		Node* child;
		if (node->leftChild)
			child = node->leftChild;
		else
			child = node->rightChild;

		if (root == node)
		{
			root = child;
			child = nullptr;
		}
		else
		{
			if (node == node->parent->leftChild)
				node->parent->leftChild = child;
			else
				node->parent->rightChild = child;
		}
		
		delete node;
		return;
	}

	if (node->leftChild != nullptr && node->rightChild != nullptr)
	{
		Node* nodeMin = Min(node->rightChild);
		node->value = nodeMin->value;
		if (nodeMin->parent != node)
			nodeMin->parent->leftChild = nullptr;
		else
			nodeMin->parent->rightChild = nodeMin->rightChild;
		delete nodeMin;
	}

	
}

Node* BinaryTree::Min(Node* node)
{
	while (node->leftChild)
		node = node->leftChild;
	return node;
}

Node* BinaryTree::Max(Node* node)
{
	while (node->rightChild)
		node = node->rightChild;
	return node;
}

void BinaryTree::List()
{
	ListReq(this->root);
}
