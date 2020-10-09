#include <iostream>
#include <queue>

using namespace std;

/*
Output:
Enter the number of nodes you want: 6

Enter the data of node: 100
100 
Enter the data of node: 70
100 70 
Enter the data of node: 90
100 70 90 
Enter the data of node: 40
100 70 40 90 
Enter the data of node: 50
100 70 40 90 50         
Enter the data of node: 110
100 70 110 40 90 50 
-----------------   
100 70 110 40 90 50 
*/

class BST
{
    public:
        int data;
        BST* left; //used to store address of left node.
        BST* right; //used to store address of right node.
};

BST* root; //declared as global so that can be accessed in any function.

BST* GetNewNode(int data)
{
    BST* newNode = new BST();  //creates new node of BSTNode class structure.
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

BST* InsertNode(BST* root,int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if(data > root->data) // if data value is greater than node then go right.
    {
        root->right = InsertNode(root->right,data);
    }
    else  // if data value is lesser than node then go left.
    {
        root->left = InsertNode(root->left,data);
    }
    return root;
}

void LevelOrderPrint(BST* root)
{
    if (root == NULL)
    {
        cout <<"Tree is empty."<<endl;
    }
    queue<BST* > Q;
    Q.push(root);
    while(!Q.empty()) // while there is atleast one node.
    {
        BST* current = Q.front();
        cout << current->data << " ";
        if(current->left != NULL)
        {
            Q.push(current->left);
        }
        if(current->right != NULL )
        {
            Q.push(current->right);
        }
        Q.pop(); //removing the element at front of queue.
    }
}

bool SearchNode(BST* root,int data)
{
    if (root == NULL)
    {
        cout << "Tree is empty." <<endl;
        return false;
    }
    else if(root->data == data)
    {
        cout << "Element found in Tree." << endl;
        return true;
    }
    else if(data < root->data)
    {
       return SearchNode(root->left,data);
    }
    else
    {
        return SearchNode(root->right,data);
    }
}


int main()
{
    root = NULL;
    int n,data;
    cout << "Enter the number of nodes you want: ";
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cout << "\nEnter the data of node: ";
        cin >> data;
        root = InsertNode(root,data);
    
        LevelOrderPrint(root);
    }

    cout << "\n-----------------"<<endl;
    LevelOrderPrint(root);

    return 0;
}