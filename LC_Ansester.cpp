#include <iostream>
#include <queue>

using namespace std;

/*
Output:
Enter the number of nodes you want: 9

Enter the character data for node: N
N 
Enter the character data for node: I
N I 
Enter the character data for node: K
N I K 
Enter the character data for node: H
N I H K 
Enter the character data for node: I
N I H K I 
Enter the character data for node: L
N I H K I L 
Enter the character data for node: K
N I H K I K L 
Enter the character data for node: U
N I U H K I K L 
Enter the character data for node: M
N I U H K I K L M 
Enter your choice: 
0. Exit.
1. Lowest commom Ancester.
1
Enter nodes to find Lowest Commom Ancester from tree: 
M I
LCA of M and I is I .
*/

class BST
{
public:
    char data;
    BST *left;
    BST *right;
};

BST *root;

BST* GetNewNode(char data)
{
    BST *newNode = new BT();
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

BST *Insert(BST *root, char data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
        return root;
    }
    else if (data > root->data)
    {
        root->right = Insert(root->right, data);
    }
    else
    {
        root->left = Insert(root->left, data);
    }
    return root;
}

void BFS_Traverse(BST *root)
{
    if (root == NULL)
    {
        cout << "\nTree is empty" << endl;
    }
    queue<BST *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        BST *current = Q.front();
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

bool Search_Element(BST *root, char data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data < root->data)
    {
        return Search_Element(root->left, data);
    }
    else
    {
        return Search_Element(root->right, data);
    }
}

BST *Lowest_Common_Ancester(BST *root, char a, char b)
{
    if(root == NULL)
    {
        return NULL;
    }
    else if (root->data > a && root->data > b) //If both are small then LCA will be on left.
    {
        return Lowest_Common_Ancester(root->left, a, b);
    }
    else if (root->data < a && root->data < b) //If both are greater then LCA will be on right.
    {
        return Lowest_Common_Ancester(root->right, a, b);
    }
    return root;
}

int main()
{
    root = NULL;
    int choice, n;
    char data;

    cout << "Enter the number of nodes you want: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the character data for node: ";
        cin >> data;
        root = Insert(root, data);

        BFS_Traverse(root); // prints BST after user input.
    }
    cout << endl;

    do
    {
        cout << "Enter your choice: " << endl;
        cout << "0. Exit." << endl
             << "1. Lowest commom Ancester." << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            char a, b;
            cout << "Enter nodes to find Lowest Commom Ancester from tree: " << endl;
            cin >> a >> b;
            if (Search_Element(root, a) && Search_Element(root, b))
            {
                BST *temp = Lowest_Common_Ancester(root, a, b);
                cout << "LCA of " << a << " and " << b << " is " << temp->data << " ." << endl;

            }
            else
            {
                cout << "Element not found in BST" << endl;
            }
            break;

        default:
            break;
        }

    } while (choice == 0);
}
