struct Node {
    string data;
    struct Node* next;
    struct Node* prev;
};

class BrowserHistory {
public:
    Node* head = new Node;

    BrowserHistory(string homepage) {
        head->data = homepage;
        head->prev = NULL;
        head->next = NULL;
    }
    
    void visit(string url) {
        Node* temp = new Node;
        temp->data = url;
        temp->prev = head;
        temp->next = NULL;
        head->next = temp;
        head = temp;
    }
    
    string back(int steps) {
        Node* temp3 = head;
        while (steps >= 1) {
            if (temp3->prev == NULL) return temp3->data;
            temp3 = temp3->prev;
            head = temp3;
            steps--;
        }
        return temp3->data;
    }
    
    string forward(int steps) {
        Node* temp4 = head;
        while (steps >= 1) {
            if (temp4->next == NULL) return temp4->data;
            temp4 = temp4->next;
            head = temp4;
            steps--;
        }
        return temp4->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */