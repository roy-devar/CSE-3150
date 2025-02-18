#ifndef NODE_LIST_H
#define NODE_LIST_H

#include <iostream>
#include <vector>
#include <stdexcept>

struct Node {
    int data;
    Node* next;

    explicit Node(int value) : data(value), next(nullptr) {}

    Node(const Node& source);

    ~Node();
};

// Utility Functions
Node* createList(const std::vector<int>& items);
void showList(const Node* start);
void wipeList(Node*& start);
int fetchValue(const Node* start, int index);
void removeNode(Node*& start, int index);

#endif
