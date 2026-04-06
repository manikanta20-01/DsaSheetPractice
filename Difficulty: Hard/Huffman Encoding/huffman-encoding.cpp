class Node{
    public:
    char val;
    int sum;
    int idx;
    Node * left, *right;
    Node()
    {
        val = 0;
        sum = 0;
        idx = -1;
        left = NULL;
        right = NULL;
    };
    Node(char v, int s, int i)
    {
        val = v;
        sum = s;
        idx = i;
        left = NULL;
        right = NULL;
    };
    Node(int s, int i)
    {
        val = 0;
        sum = s;
        idx = i;
        left = NULL;
        right = NULL;
    };
};

class Cmp{
    public:
    bool operator()(Node * n1 , Node * n2)
    {
        if(n1->sum != n2->sum)
        return n1->sum > n2->sum;
        else return n1->idx > n2->idx;
    }
};

void preorder(Node * root, string str, vector<string> & res)
{
    if(!root)
    return;
    
    preorder(root->left,  str + '0' , res);
    
    if(root->val!=0)
    res.push_back(str == "" ? "0" : str);
    
    preorder(root->right,  str + '1' , res);
}

class Solution {
  public:
    vector<string> huffmanCodes(string &s, vector<int> f) {
        priority_queue<Node *, vector<Node *>, Cmp> pq;
        for(int i=0;i<s.size();i++)
        pq.push(new Node(s[i], f[i], i));
        
        while(pq.size()!=1)
        {
            Node * t1 = pq.top();
            pq.pop();
            Node * t2 = pq.top();
            pq.pop();
            Node * temp = new Node( (t1->sum) + (t2->sum), min(t1->idx, t2->idx));
            temp->left = t1;
            temp->right = t2;
            pq.push(temp);
        }
        
        vector<string> res;
        
        preorder(pq.top(), "", res);
        
        return res;
    }
};