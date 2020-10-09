#include <iostream>
#include <queue>

using namespace std;

/*
Output:
Enter number of elements of 1st Tree: 6

Enter the element of 1st Tree: N
N 
Enter the element of 1st Tree: I
N I 
Enter the element of 1st Tree: K
N I K 
Enter the element of 1st Tree: H
N I H K 
Enter the element of 1st Tree: I
N I H K I 
Enter the element of 1st Tree: L
N I H K I L 
Enter number of elements of 2nd Tree: 6

Enter the element of 2nd Tree: P
P 
Enter the element of 2nd Tree: R
P R 
Enter the element of 2nd Tree: A
P A R 
Enter the element of 2nd Tree: T
P A R T 
Enter the element of 2nd Tree: I
P A R I T 
Enter the element of 2nd Tree: K
P A R I T K 
Overlapped Binary Tree is: P A R H I T I K
*/

class Bst
{
    public:
        char data;
        Bst *left;
        Bst *right;

};

Bst *root1;
Bst *root2;

Bst* InsertNewNode(Bst *root,char data);

Bst* GetNewNode(char data)
{
    Bst *newNode = new Bst();
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

Bst* InsertNewNode(Bst *root,char data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if (data > root->data)
    {
        root->right = InsertNewNode(root->right, data);
    }
    else
    {
        root->left = InsertNewNode(root->left, data);
    }
    return root;
}

void BFS_Traverse(Bst *root)
{
    if (root == NULL)
    {
        cout << "\nTree is empty" << endl;
    }
    queue<Bst *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        Bst *current = Q.front();
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

Bst* Overlapping(Bst* root1,Bst* root2)
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
    int n;
    char data;

    cout << "Enter number of elements of 1st Tree: ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout <<"\nEnter the element of 1st Tree: ";
        cin >> data;
        root1 = InsertNewNode(root1,data);
        BFS_Traverse(root1);
    }

    cout << "\nEnter number of elements of 2nd Tree: ";
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cout <<"\nEnter the element of 2nd Tree: ";
        cin >> data;
        root2 = InsertNewNode(root2,data);
        BFS_Traverse(root2);
    }

    root1 = Overlapping(root1,root2);
    cout << "\nOverlapped Binary Tree is: ";
    BFS_Traverse(root1);
    return 0;
}