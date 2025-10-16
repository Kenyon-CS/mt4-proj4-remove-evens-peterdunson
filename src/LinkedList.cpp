#include "LinkedList.hpp"
#include <sstream>

LinkedList::LinkedList() : head_(nullptr) {}
LinkedList::~LinkedList() {
    Node* p = head_;
    while (p) { Node* n = p->next; delete p; p = n; }
}
void LinkedList::push_front(int v) { head_ = new Node(v, head_); }
void LinkedList::remove_evens() {
    while (head_ && head_->value % 2 == 0) {
        Node* tmp = head_;
        head_ = head_->next;
        delete tmp;
    }
    Node* p = head_;
    while (p && p->next) {
        if (p->next->value % 2 == 0) {
            Node* dead = p->next;
            p->next = dead->next;
            delete dead;
        } else {
            p = p->next;
        }
    }
}
std::string LinkedList::to_string() const {
    std::ostringstream oss;
    oss << "[";
    Node* p = head_;
    bool first = true;
    while (p) {
        if (!first) oss << ", ";
        first = false;
        oss << p->value;
        p = p->next;
    }
    oss << "]";
    return oss.str();
}
