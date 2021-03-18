// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends


/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

/*you are required to
complete this function */
Node *a[10];
int c;
void start(Node *T,int x)
{
    if(T==NULL)
    return ;
    if(T->data==x)
    a[c++]=T;
    
    start(T->left,x);
    start(T->right,x);
    return;
    
}
bool check(Node *T,Node *S)
{
    if(T==NULL&&S==NULL)
    return true;
    if((T==NULL&&S!=NULL)||(T!=NULL&&S==NULL)||(T->data!=S->data))
    return false;
    return check(T->left,S->left)&&check(T->right,S->right);
}
bool isSubTree(Node* T, Node* S) {
    c=0;
    start(T,S->data);
    for(int i=0;i<c;i++)
    {
        
    
        Node *go=a[i];
        if(check(go,S))
        return true;
    }
    return false;
    
        
        
    // Your code here
    // return 1 if S is subtree of T else 0
}


// { Driver Code Starts.

int main() {
    #ifndef o
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string strT, strS;
        getline(cin, strT);
        Node *rootT = buildTree(strT);
        getline(cin, strS);
        Node *rootS = buildTree(strS);
        cout << isSubTree(rootT, rootS) << "\n";

    }


    return 0;
}  // } Driver Code Ends
