class MyCircularDeque {
public:
    MyCircularDeque(const int k) {
        elemAtMax = k;
    }
    
    bool insertFront(const int value) {
        if(elements == elemAtMax) return false;
        else
        {
            element* newElement = new element(value, nullptr, first);

            if(elements++) first->prev = newElement;
            else last = newElement;

            first = newElement;

            return true;
        }
    }
    
    bool insertLast(const int value) {
        if(elements == elemAtMax) return false;
        else
        {
            element* newElement = new element(value, last, nullptr);

            if(elements++) last->next = newElement;
            else first = newElement;

            last = newElement;

            return true;
        }
    }
    
    bool deleteFront() {
        if(!first) return false;
        else
        {
            element* tmp = first;
            first = first->next;
            delete tmp;

            if(!--elements) last = nullptr;
            else first->prev = nullptr;

            return true;
        }
    }
    
    bool deleteLast() {
        if(!last) return false;
        else
        {
            element* tmp = last;
            last = last->prev;
            delete tmp;

            if(!--elements) first = nullptr;
            else last->next = nullptr;

            return true;
        }
    }
    
    int getFront() {
        return first ? first->value : -1;
    }
    
    int getRear() {
        return last ? last->value : -1;
    }
    
    bool isEmpty() {
        return !elements;
    }
    
    bool isFull() {
        return elements == elemAtMax;
    }

private:
    struct element{
        int value;
        element* prev;
        element* next;

        element(const int x, element* e1, element* e2)
        {
            value = x;
            prev = e1;
            next = e2;
        }
    };

    int elemAtMax, elements = 0;
    element* first = nullptr;
    element* last = nullptr;
};
