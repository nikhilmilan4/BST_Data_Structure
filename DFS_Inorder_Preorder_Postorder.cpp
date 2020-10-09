#include <iostream>
#include <queue>

using namespace std;

/*
Output:
Enter the number of nodes you want: 6

Enter the data of node: 50
50 
Enter the data of node: 10
50 10 
Enter the data of node: 40
50 10 40 
Enter the data of node: 20
50 10 40 20 
Enter the data of node: 05
50 10 5 40 20 
Enter the data of node: 01
50 10 5 40 1 20  
-----------------
50 10 5 40 1 20  

Preorder Traversal: 50 10 5 1 40 20
Inorder Traversal: 1 5 10 20 40 50
Postorder Traversal: 1 5 20 40 10 50

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

void Preorder_Traversal(BST* root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    Preorder_Traversal(root->left);
    Preorder_Traversal(root->right); 

}

void Inorder_Traversal(BST* root)
{
    if(root == NULL)
    {
       return;
    }

    Inorder_Traversal(root->left);
    cout << root->data << " ";
    Inorder_Traversal(root->right); 

}

void Postorder_Traversal(BST* root)
{
    if(root == NULL)
    {
        return;
    }

    Postorder_Traversal(root->left);
    Postorder_Traversal(root->right); 
    cout << root->data << " ";
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

    cout <<endl;
    cout<< "\nPreorder Traversal: ";
    Preorder_Traversal(root);
    cout <<"\nInorder Traversal: ";
    Inorder_Traversal(root);
    cout<< "\nPostorder Traversal: ";
    Postorder_Traversal(root);

    return 0;
}

