class Node{
    public:
            int val;
            int key,freq;
            Node*prev,*next;

            Node(int k ,int v){
                key = k;
                val = v;
                freq = 1;
                prev = next = nullptr;

            }
        }; 
 
 class List{
            public:
            int size;
            Node *head,*tail;

            List(){
                size = 0;

                head = new Node(-1,-1);
                tail = new  Node(-1,-1);

                head ->next =tail;
                tail->prev= head;

            }

            void addFront(Node* node){
                Node* temp = head->next;

                node->next =temp;
                node->prev = head;

                head->next = node;
                temp->prev = node;

                size++;
            }
            void removeNode(Node* node){
                Node* prevNode = node->prev;
                Node* nextNode = node->next;

                prevNode->next = nextNode;
                nextNode->prev = prevNode;

                size--;
            }
        };



class LFUCache {
public:
    
        

            int capacity;
            int currSize;
            int minfreq;


            unordered_map<int,Node*>keyNode;
            unordered_map<int,List*>freqList;


            LFUCache(int capacity){

                this->capacity = capacity;
                currSize = 0;
                minfreq =0;


            }
            void updatefreq(Node* node){
                int oldfreq = node->freq;

                freqList[oldfreq]->removeNode(node);

                if(oldfreq == minfreq && freqList[oldfreq]->size ==0){
                    minfreq++;
                }

                node->freq++;

                if(freqList.find(node->freq)==freqList.end()){
                    freqList[node->freq] = new List();


                }

                freqList[node->freq]->addFront(node);
            }

        
    
    
    int get(int key) {
        if(keyNode.find(key)== keyNode.end()) return -1;

        Node* node = keyNode[key];

        updatefreq(node);

        return node->val;
    }
    
    void put(int key, int value) {
        if(capacity == 0) return;

        if(keyNode.find(key)!= keyNode.end()){
            Node* node = keyNode[key];

            node->val =value;

            updatefreq(node);
            return;
        }
        if(currSize == capacity){
            List* list = freqList[minfreq];
            Node* nodeToDelete = list->tail->prev;
            list->removeNode(nodeToDelete);

            keyNode.erase(nodeToDelete->key);
            delete nodeToDelete;

            currSize--;
        }
        currSize++;

        minfreq =1;

        Node* newNode = new Node(key,value);

        if(freqList.find(1) == freqList.end()){
            freqList[1] = new List();
        }

        freqList[1]->addFront(newNode);
        keyNode[key] = newNode;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */