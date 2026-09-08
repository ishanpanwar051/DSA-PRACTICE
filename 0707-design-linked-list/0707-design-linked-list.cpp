class MyLinkedList {
public:

    struct Node {
        int val;
        Node* next;

        Node(int x) {
            val = x;
            next = NULL;
        }
    };

    Node* dummy;
    int size;

    // Constructor
    MyLinkedList() {
        dummy = new Node(0);
        size = 0;
    }

    // Get
    int get(int index) {

        if (index < 0 || index >= size)
            return -1;

        Node* curr = dummy->next;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        return curr->val;
    }

    // Add at Head
    void addAtHead(int val) {

        Node* newNode = new Node(val);

        newNode->next = dummy->next;
        dummy->next = newNode;

        size++;
    }

    // Add at Tail
    void addAtTail(int val) {

        Node* curr = dummy;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = new Node(val);

        size++;
    }

    // Add at Index
    void addAtIndex(int index, int val) {

        if (index < 0 || index > size)
            return;

        Node* curr = dummy;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        Node* newNode = new Node(val);

        newNode->next = curr->next;
        curr->next = newNode;

        size++;
    }

    // Delete at Index
    void deleteAtIndex(int index) {

        if (index < 0 || index >= size)
            return;

        Node* curr = dummy;

        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }

        Node* temp = curr->next;

        curr->next = curr->next->next;

        delete temp;

        size--;
    }
};