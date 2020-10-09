#include <iostream>
#include <queue>

using namespace std;

/*
Output:
Enter number of elements of 1st Tree: 10

Enter the element of 1st Tree: 1
1 
Enter the element of 1st Tree: 2
1 2 
Enter the element of 1st Tree: 3
1 2 3 
Enter the element of 1st Tree: 4
1 2 3 4 
Enter the element of 1st Tree: 5
1 2 3 4 5 
Enter the element of 1st Tree: 6
1 2 3 4 5 6 
Enter the element of 1st Tree: 7
1 2 3 4 5 6 7 
Enter the element of 1st Tree: 8
1 2 3 4 5 6 7 8 
Enter the element of 1st Tree: 9
1 2 3 4 5 6 7 8 9 
Enter the element of 1st Tree: 1
1 2 3 4 5 6 7 8 9 1 
Enter number of elements of 2nd Tree: 6

Enter the element of 2nd Tree: 6
6 
Enter the element of 2nd Tree: 5
6 5 
Enter the element of 2nd Tree: 4
6 5 4 
Enter the element of 2nd Tree: 3
6 5 4 3 
Enter the element of 2nd Tree: 2
6 5 4 3 2 
Enter the element of 2nd Tree: 1
6 5 4 3 2 1 
Overlapped Binary Tree is: 6 5 4 3 2 1 7 8 9 1
PS H:\PROGRAMMING_LANGUAGE\C.C++\Programs\Practice\Data_Structure\BST> 
*/

class BT
{
    public:
        char data;
        BT *left;
        BT *right;
};

BT *root1;
BT *root2;
BT *root3;

BT* GetNewNode(char data)
{
    BT *newnode = new BT();
    newnode->data = data;
    newnode->left = newnode->right = NULL;

    return newnode;
}

BT* Insert(BT *root,char data)
{
    if(root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if(root->left == NULL)
    {
        root->left = Insert(root->left,data);
    }
    else
    {
        root->right = Insert(root->right,data);
    }
    return root;
}

void BFS_Traverse(BT *root)
{
    if (root == NULL)
    {
        cout << "\nTree is empty" << endl;
    }
    queue<BT *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        BT *current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL)
        {
            Q.push(current->left);
        }
        if (current->right != NULL)
        {
            Q.push(current->right);
        }
        Q.pop();
    }
}

BT* Overlapping(BT* root1,BT* root2)
{
    if(!root1)
    {
        return root2;
    }
    if(!root2)
    {
        return root1;
    }
    root1->data = root2->data;
    root1->left = Overlapping(root1->left,root2->left);
    root1->right = Overlapping(root1->right,root2->right);

    return root1;
}

int main()
{
    root1 = NULL;
    root2 = NULL;
    root3 = NULL;
    int n;
    char data;

    cout << "Enter number of elements of 1st Tree: ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout <<"\nEnter the element of 1st Tree: ";
        cin >> data;
        root1 = Insert(root1,data);
        BFS_Traverse(root1);
    }

    cout << "\nEnter number of elements of 2nd Tree: ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout <<"\nEnter the element of 2nd Tree: ";
        cin >> data;
        root2 = Insert(root2,data);
        BFS_Traverse(root2);
    }

    root3 = Overlapping(root1,root2);
    cout << "\nOverlapped Binary Tree is: ";
    BFS_Traverse(root3);
    return 0;
}