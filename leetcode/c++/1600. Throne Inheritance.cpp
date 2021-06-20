// 多叉树的前序遍历 + 哈希表
// 时间复杂度：O(n)
// 空间复杂度：O(n)

class Node {
public:
    string val;
    vector<Node *> children;
    bool alive = true;

    Node() {}

    Node(string _val) {
        val = _val;
    }

    Node(string _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class ThroneInheritance {
public:
    Node *king;
    unordered_map<string, Node *> hashmap;

    ThroneInheritance(string kingName) {
        king = new Node(kingName);
        hashmap[kingName] = king;

    }

    void preOrder(Node *root, vector <string> &record) {
        if (!root) return;
        if (root->alive) record.push_back(root->val);
        for (int i = 0; i < root->children.size(); i++) {
            preOrder(root->children[i], record);
        }
    }

    void birth(string parentName, string childName) {
        Node *parent = hashmap[parentName];
        Node *child = new Node(childName);
        hashmap[childName] = child;
        parent->children.push_back(child);
    }

    void death(string name) {
        Node *parent = hashmap[name];
        parent->alive = false;
    }

    vector <string> getInheritanceOrder() {
        vector <string> record;
        preOrder(king, record);
        return record;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */