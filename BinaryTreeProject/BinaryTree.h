#pragma once
struct Node
{
	Node* parent = nullptr;
	int value;
	Node* leftChild = nullptr;
	Node* rightChild = nullptr;
};

class BinaryTree
{
private:
	int size;
	Node* root;

	void AddReqNode(int value, Node* node);
	void ListReq(Node* node);

public:
	BinaryTree() : size{ 0 }, root{ nullptr } {}
	~BinaryTree() {}

	Node* Root();

	void AddLoop(int value);
	void AddReq(int value);

	Node* Find(int keyValue);

	void Delete(Node* node);

	Node* Min(Node* node);
	Node* Max(Node* node);

	void List();
};

