class Node {
public:
    string name = "";
    vector<Node*> children;
    bool isDead = false;
    Node (string _name, vector<Node*> _children) {
        name = _name, children = _children;
    };
};

class ThroneInheritance {
private:
    Node *root;
    unordered_map<string, Node*> m;
public:
    ThroneInheritance(string kingName) {
        root = new Node(kingName, {});  
        m[kingName] = root;
    };
    
    void birth(string parentName, string childName) {
        Node *node = new Node(childName, {});            
        m[parentName]->children.push_back(node);    
        m[childName] = node;
    };
    
    void death(string name) {
        m[name]->isDead = true;
    };
    
    void dfs(Node *node, vector<string> &order) {
        if (!node->isDead) {
            order.push_back(node->name); 
        };
        for (auto &chNode : node->children) {
            dfs(chNode, order);
        };
    };
    
    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(root, order);
        return order;
    };
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */