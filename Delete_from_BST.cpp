#include <iostream>
#include <queue>

using namespace std;
/*
Enter the number of nodes you want: 9

Enter the data of node: 12
12 
Enter the data of node: 5
12 5 
Enter the data of node: 15
12 5 15 
Enter the data of node: 3
12 5 15 3 
Enter the data of node: 7
12 5 15 3 7 
Enter the data of node: 13
12 5 15 3 7 13 
Enter the data of node: 13
12 5 15 3 7 13 13 
Enter the data of node: 1
12 5 15 3 7 13 1 13 
Enter the data of node: 9
12 5 15 3 7 13 1 9 13 
-----------------
12 5 15 3 7 13 1 9 13 
Enter number to be deleted : 15
Element found in Tree.
12 5 13 3 7 13 1 9
Inorder of tree is: 1 3 5 7 9 12 13 13 
*/

class BST
{
    public:
        int data;
        BST* left; //used to store address of left node.
        BST* right; //used to store address of right node.
};

BST* root; //declared as global so that can be accessed in any function.
void Inorder(BST* root);
BST* Find_Min(BST* root);
BST* Delete_root(BST* root, int data);

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

BST* Find_Min(BST* root)
{
    while(root->left != NULL) 
    {
        root = root->left;
    }
	return root;
}

BST* Delete_root(BST* root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    else if(data < root->data)
    {
        root->left = Delete_root(root->left,data);
    }
    else if(data > root->data)
    {
        root->right = Delete_root(root->right,data);
    }
    // Wohoo... I found you, Get ready to be deleted
    else
    {
        //Case 1: No child
        if (root->left == NULL && root->right == NULL )
        {
            delete root;
            root = NULL;
        }

        //Case 2: One child
        else if(root->left == NULL)
        {
            BST* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            BST* temp = root;
            root = root->left;
            delete temp;
        }

        //Case 3 : 2 childs.
        else
        {
            BST* temp = Find_Min(root->right);
            root->data = temp->data;
            root->right = Delete_root(root->right,temp->data);
        }
    }
    return root;
}

void Inorder(BST* root)
{
    if(root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);

}

int main()
{
    root = NULL;
    int n,data,delete_val;
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

    cout << "\nEnter number to be deleted : ";
    cin >> delete_val;
    if(SearchNode(root,data))
    {
        Delete_root(root,delete_val);
        LevelOrderPrint(root);
        cout << "\nInorder of tree is: ";
        Inorder(root);
    }
    else
    {
        cout << "\nNode is not in Tree"<<endl;
    }
    
    return 0;
}