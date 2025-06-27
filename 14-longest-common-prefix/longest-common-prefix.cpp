class Node {
public:
    Node* arr[26];
    bool flag = false;
    int pass = 0;

    Node() {
        for (int i = 0; i < 26; i++) arr[i] = nullptr;
    }

    bool getFlag() { return flag; }
    void incPass() { pass++; }
    int getPass() { return pass; }
    void setFlag() { flag = true; }
    void insertNode(char ch, Node* n) { arr[ch - 'a'] = n; }
    Node* getNode(char ch) { return arr[ch - 'a']; }
    bool checkChar(char ch) { return arr[ch - 'a'] != nullptr; }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string s) {
        Node* temp = root;
        temp->incPass();
        for (char ch : s) {
            if (!temp->checkChar(ch)) {
                temp->insertNode(ch, new Node());
            }
            temp = temp->getNode(ch);
            temp->incPass();
        }
        temp->setFlag();
    }

    string getLCP(int totalWords, string reference) {
        Node* temp = root;
        string ans = "";

        for (char ch : reference) {
            if (!temp->checkChar(ch)) break;
            temp = temp->getNode(ch);
            if (temp->getPass() < totalWords) break; // only continue if all strings pass through
            ans += ch;
        }

        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie* t = new Trie();
        for (string& s : strs) {
            t->insert(s);
        }

        return t->getLCP(strs.size(), strs[0]);
    }
};
