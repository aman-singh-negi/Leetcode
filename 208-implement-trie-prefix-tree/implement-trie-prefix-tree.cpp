class Node
{
    public:
    Node* arr[26];
    bool flag=false;
    Node()
    {
        for(int i=0;i<26;i++)arr[i]=NULL;
    }
    void setFlag()
    {
        flag=true;
    }
    void resetFlag()
    {
        flag=false;
    }
    bool checkFlag()
    {
        return flag;
    }
    bool checkChar(char ch)
    {
        return arr[ch-'a']!=NULL;
    }
    void insertNode(char ch,Node* n)
    {
        arr[ch-'a']=n;
    }
    Node* getNode(char ch)
    {
        return arr[ch-'a'];
    }
};
class Trie {
public:
    Node* root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++)
        {
            if(!node->checkChar(word[i]))
            {
                Node* temp= new Node();
                node->insertNode(word[i],temp);
            }
            node=node->getNode(word[i]);
        }
        node->setFlag();
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->checkChar(word[i]))
            {
                return false;
            }
            temp=temp->getNode(word[i]);
        }
        if(!temp->checkFlag())return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!temp->checkChar(prefix[i]))
            {
                return false;
            }
            temp=temp->getNode(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */