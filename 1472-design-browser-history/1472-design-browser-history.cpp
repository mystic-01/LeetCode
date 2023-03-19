struct Node {
    string data;
    struct Node* next;
    struct Node* prev;
};

class BrowserHistory {
public:
    Node* head = new Node;

    BrowserHistory(string homepage) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        head->data = homepage;
        head->prev = NULL;
        head->next = NULL;
    }
    
    void visit(string url) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        Node* temp = new Node;
        temp->data = url;
        temp->prev = head;
        temp->next = NULL;
        head->next = temp;
        head = temp;
    }
    
    string back(int steps) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        while (steps >= 1) {
            if (head->prev == NULL) return head->data;
            head = head->prev;
            steps--;
        }
        return head->data;
    }
    
    string forward(int steps) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        while (steps >= 1) {
            if (head->next == NULL) return head->data;
            head = head->next;
            steps--;
        }
        return head->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */