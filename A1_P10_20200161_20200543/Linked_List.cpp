#include "Linked_List.h"

template <class T>
LinkedList<T>::Iterator::Iterator (Node* node){
    iterator_ = node;
}
template <class T>
T& LinkedList<T>:: Iterator:: operator * () {
    return this->iterator_->value_;
}
template <class T>
bool LinkedList<T>::Iterator:: operator == (const Iterator& rhs) {
    return (iterator_ == rhs.iterator_);
}

template <class T>
bool LinkedList<T>::Iterator:: operator != (const Iterator& rhs) {
    return (iterator_ != rhs.iterator_);
}
template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator:: operator ++ (int) {

    if(iterator_ -> next == NULL)
        throw string("out of list exception");

    Iterator temp = *this;
    iterator_ = iterator_-> next;

    return temp;
}
template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator:: operator -- (int) {

    if(iterator_-> previous == NULL)
        throw string("out of list exception");

    Iterator temp = *this;
    iterator_ = iterator_-> previous;


    return temp;
}

template <class T>
LinkedList<T>::LinkedList () {
    end_ = new Node;
    head_ = tail_ = end_;
    size_ = 0;
}

template <class T>
LinkedList<T>::LinkedList (T value, int size) {
    end_ = new Node;
    head_ = tail_ = end_;
    size_ = 0;
    for (int i = 0; i < size; i++)
        push_front (value);
}

template <class T>
LinkedList<T>& LinkedList<T>:: operator = (const LinkedList& rhs) {
    end_ = new Node;
    head_ = tail_ = end_;
    size_ = 0;
    Node* current = rhs.head_;
    push_back(current -> value_);
    while (current -> next != rhs.end_) {
        current = current->next;
        push_back(current -> value_);
    }
    return *this;
}

template<class T>
int LinkedList<T>:: size () {
    return size_;
}

template<class T>
typename LinkedList<T>::Iterator LinkedList<T>:: begin (void) const {
    Iterator headIterator(head_);
    return headIterator;
}
template<class T>
typename LinkedList<T>::Iterator LinkedList<T>:: end (void) const {
    Iterator tailIterator(end_);
    return tailIterator;
}

template <class T>
void LinkedList<T>:: pop_front (void) {
    if (head_ == end_) {return;}
    head_ = head_ -> next;
    delete (head_-> previous);
    head_ -> previous = NULL;
    size_--;
}

template <class T>
void LinkedList<T>:: pop_back (void) {
    if (tail_ == end_) {return;}
    tail_ = end_ -> previous -> previous;
    end_ = end_ -> previous;
    delete (end_ -> next);
    end_ -> next = NULL;
    size_--;
    if (tail_ == NULL) {tail_ = end_;}
}

template<class T>
typename LinkedList<T>::Iterator LinkedList<T>:: erase (Iterator &position) {
    if (position == end_){
        throw string("Error Out of bounds erase");
    }

    if (position == head_) {
        position++;
        pop_front ();
        return head_;
    }
    else if (position == tail_) {
        position--;
        pop_back ();
        return position;
    }
    else {
        Node* current = head_;
        for (int i = 0; i < size_ - 1; i++) {
            if (position == current -> next) {
                position++;
                current ->next = current->next->next;
                delete current->next->previous;
                current ->next->previous = current;
                break;
            }
            current = current->next;
        }
        size_--;
        return (current -> next);
    }
}


template <class T>
void LinkedList<T>:: push_back (T value) {
    end_ -> next = new Node;
    end_ -> next -> previous = end_;
    end_ = end_ -> next;
    tail_ = end_ -> previous;
    tail_ -> value_ = value;
    size_++;
}

template <class T>
void LinkedList<T>:: push_front (T value) {
    head_ -> previous = new Node;//create and back link
    head_ -> previous -> value_ = value;//assign
    head_ -> previous -> next = head_;// link back
    head_ = head_ -> previous;//shift head and leave dummy
    size_++;
}

template <class T>
void LinkedList<T>:: insert (T value, Iterator& position) {

    if(position == head_){
        push_front(value);
        position--;
    }else if(position == tail_){
        push_back(value);
    }else{
        Node* current = head_;
        for (int i = 0; i < size_ - 1; i++) {
            if (position == current -> next) {
                current -> next -> previous = NULL;
                current -> next -> previous = new Node;// create Node_front link
                current -> next -> previous -> next = current -> next;//back link
                current -> next -> previous -> previous = current;//back link to current
                current -> next = current -> next ->previous;
                current -> next -> value_ = value;// front link to new node
                break;
            }
            current = current->next;
        }
        size_++;
        current = NULL;
        position--;
    }
}

template<class T>
LinkedList<T>:: ~LinkedList () {
    for (int i  = 0; i < size_; i++)
        pop_front ();
}

//Not Required for the Assignment this overload is to help show the list.
template<class T2>
ostream& operator << (ostream& out, LinkedList<T2>& rhs) {
    typename LinkedList<T2>::Node *current = rhs.head_;
    cout << "printing the linked list...\n" << '[';
    for (int i = 0; i < rhs.size_; i++) {
        out << current -> value_;
        if (i < rhs.size_ - 1)
            out << "] <--> [";
        current = current -> next;
    }
    out << "]\n";
    return out;
}
