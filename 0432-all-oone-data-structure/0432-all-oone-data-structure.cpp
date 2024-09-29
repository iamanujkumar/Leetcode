#include <unordered_map>
#include <unordered_set>
#include <string>

class Node {
public:
    Node* next;
    Node* prev;
    int freq;
    std::unordered_set<std::string> keys;
    
    Node(int f) {
        next = nullptr;
        prev = nullptr;
        freq = f;
        keys = std::unordered_set<std::string>();
    }
};

class AllOne {
    std::unordered_map<std::string, Node*> map;
    Node* head;
    Node* tail;

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        map = std::unordered_map<std::string, Node*>();
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(std::string key) {
        Node* cur = head;
        int newFreq = 1;
        if(map.find(key) != map.end()){
            cur = map[key];
            newFreq = cur->freq + 1;
            cur->keys.erase(key);
        }
        if(cur->next->freq == newFreq){
            cur->next->keys.insert(key);
        }else{ // insert a node with newFreq
            Node* node = new Node(newFreq);
            node->keys.insert(key);
            Node* nextNode = cur->next;
            node->next = nextNode;
            nextNode->prev = node;
            cur->next = node;
            node->prev = cur;
        }
        map[key] = cur->next;
        if(cur->keys.empty() && cur != head){
            removeNode(cur);
        }
    }
    
    void dec(std::string key) {
        Node* cur = map[key];
        int newFreq = cur->freq - 1;
        cur->keys.erase(key);
        if(newFreq == 0){
            if(cur->keys.empty()){
                removeNode(cur);
            }
            map.erase(key);
            return;
        }
    
        if(cur->prev->freq == newFreq){
            cur->prev->keys.insert(key);
        }else{ // insert a node with newFreq
            Node* node = new Node(newFreq);
            node->keys.insert(key);
            Node* prevNode = cur->prev;
            node->prev = prevNode;
            prevNode->next = node;
            node->next = cur;
            cur->prev = node;
        }
        map[key] = cur->prev;
        if(cur->keys.empty() && cur != head){
            removeNode(cur);
        }
    }
    
    std::string getMaxKey() {
        if(tail->prev == head){
            return "";
        }
        return *(tail->prev->keys.begin());
    }
    
    std::string getMinKey() {
        if(head->next == tail){
            return "";
        }
        return *(head->next->keys.begin());
    }

private:
    void removeNode(Node* cur){
        Node* nextNode = cur->next;
        Node* prevNode = cur->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        delete cur;
    }
};
