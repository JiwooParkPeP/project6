// File: QueueL/QueueL.hpp

#ifndef QueueL_HPP_
#define QueueL_HPP_

#include <iostream> // ostream.

#include "AQueue.hpp"
#include "ListL.hpp"

using namespace std;

// ========= QueueL =========
template<class T>
class QueueL: public AQueue<T> {
private:
    ListL<T> _listL;
    int _length;
    const int _cap;
public:
    QueueL(int cap = 1);
    T dequeue() override;
    void enqueue(T const &val) override;
    T const &headOf() const override;
    bool isEmpty() const override;
    bool isFull() const override;
    void toStream(ostream &os) const override;
};

// ========= Constructor =========
template<class T>
QueueL<T>::QueueL(int cap):
    _listL(),
    _length(0),
    _cap(cap){
}

// ========= dequeue =========
template<class T>
T QueueL<T>::dequeue() {
    if (isEmpty()) {
        cerr << "dequeue precondition violated: Cannot dequeue onto a empty List." << endl;
    } else {
        return _listL.remFirst();
    }
}

// ========= enqueue =========
template<class T>
void QueueL<T>::enqueue(T const &val) {
    if (isFull()) {
        cerr << "enqueue precondition violated: Cannot enqueue onto a full List." << endl;
        throw -1;
    }
    _listL.append(val);
}

// ========= headOf =========
template<class T>
T const &QueueL<T>::headOf() const {
    if (!isEmpty()) {
        return _listL.first();
    }
}

// ========= isEmpty =========
template<class T>
bool QueueL<T>::isEmpty() const {
    return _listL.isEmpty();
}

// ========= isFull =========
template<class T>
bool QueueL<T>::isFull() const {
    return _listL.length() == _cap;
}

// ========= operator<< =========
template<class T>
ostream &operator<<(ostream &os, QueueL<T> const &rhs) {
    rhs.toStream(os);
    return os;
}

// ========= toStream =========
template<class T>
void QueueL<T>::toStream(ostream &os) const {
    _listL.toStream(os);
}

#endif
