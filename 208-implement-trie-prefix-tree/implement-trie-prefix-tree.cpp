class Node
{
    public:
    Node* arr[26]={NULL};
    bool flag=false;
    void setFlag()
    {
        flag=true;
    }
    bool checkFlag()
    {
        return flag;
    }
    bool checkChar(char ch)
    {
        return arr[ch-'a']!=NULL;
    }
    Node* getNode(char ch)
    {
        return arr[ch-'a'];
    }
    void insertNode(char ch,Node* n)
    {
        arr[ch-'a']=n;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->checkChar(word[i]))
            {
                temp->insertNode(word[i],new Node());
            }
            temp=temp->getNode(word[i]);
        }
        temp->setFlag();
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
        return temp->checkFlag();
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