#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED
#include <iostream>
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;
using std::string;

template <class T>
class LinkedList {
private:
    class Node {
    public:
        T value_;
        Node* next = NULL;
        Node* previous = NULL;
    };
    Node *head_;
    Node *tail_;
    Node *end_;
    int size_;
    void pop_front (void);
public:
    class Iterator {
        private:
        Node* iterator_ = NULL;
        public:
        Iterator (Node*);
        T& operator * ();
        bool operator == (const Iterator&);
        bool operator != (const Iterator&);
        Iterator operator ++ (int);
        Iterator operator -- (int);
    };
    LinkedList ();
    LinkedList (T, int);
    LinkedList &operator = (const LinkedList&);
    int size ();
    Iterator begin (void) const;
    Iterator end (void) const;
    void pop_back (void);
    Iterator erase (Iterator &);
    void push_back (T);
    void push_front (T);
    void insert (T, Iterator&);
    template <class T2>
    friend ostream& operator << (ostream&, LinkedList<T2>&);
    ~ LinkedList ();
};

#endif // LINKED_LIST_H_INCLUDED
