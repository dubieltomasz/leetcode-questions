class CustomStack {
public:
    CustomStack(const int maxSize) {
        maxStackSize = maxSize;        
    }
    
    void push(const int x) {
        if(elements < maxStackSize)
        {
            head = new element(x, head);

            ++elements;
        }
    }
    
    int pop() {
        if(elements)
        {
            int tmp1 = head->value;
            element* tmp2 = head;

            head = head->prev;
            delete tmp2;
            --elements;

            return tmp1;
        }
        else return -1;
    }
    
    void increment(int k, const int val) {
        int i = elements - k;
        element* tmp = head;

        while(i-- > 0 && tmp)
            tmp = tmp->prev;

        while(k-- && tmp)
        {
            tmp->value += val;
            tmp = tmp->prev;
        }
    }

private:
    struct element{
        int value;
        element* prev;

        element(int x, element* e)
        {
            value = x;
            prev = e;
        }
    };

    int maxStackSize, elements = 0;
    element* head = nullptr;
};
