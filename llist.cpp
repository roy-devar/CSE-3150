#include "llist.h"

Node::Node(const Node& source) {
    data = source.data;
    if (source.next) {
        next = new Node(*source.next);
    } else {
        next = nullptr;
    }
}

Node::~Node() {
    while (next) {
        Node* toDelete = next;
        next = next->next;
        toDelete->next = nullptr;
        delete toDelete;
    }
}

Node* createList(const std::vector<int>& items) {
    if (items.empty()) return nullptr;

    Node* start = new Node(items[0]);
    Node* end = start;

    for (size_t i = 1; i < items.size(); ++i) {
        end->next = new Node(items[i]);
        end = end->next;
    }

    return start;
}

void showList(const Node* start) {
    const Node* ptr = start;
    while (ptr) {
        std::cout << ptr->data << " --> ";
        ptr = ptr->next;
    }
    std::cout << "null" << std::endl;
}

void wipeList(Node*& start) {
    while (start) {
        Node* discard = start;
        start = start->next;
        discard->next = nullptr;
        delete discard;
    }
}

int fetchValue(const Node* start, int index) {
    const Node* seeker = start;
    int pos = 0;

    while (seeker) {
        if (pos == index) {
            return seeker->data;
        }
        seeker = seeker->next;
        ++pos;
    }

    throw std::out_of_range("Index exceeds list length");
}

void removeNode(Node*& start, int index) {
    if (!start) return;

    if (index == 0) {
        Node* discard = start;
        start = start->next;
        discard->next = nullptr;
        delete discard;
        return;
    }

    Node* prior = start;
    for (int i = 0; i < index - 1 && prior; ++i) {
        prior = prior->next;
    }

    if (!prior || !prior->next) {
        throw std::out_of_range("Index exceeds list length");
    }

    Node* discard = prior->next;
    prior->next = discard->next;
    discard->next = nullptr;
    delete discard;
}
