#include <iostream>
#include <queue>

using namespace std;

/*
Output:
Enter size of 1st tree: 6

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
Enter size of 2nd tree: 6

Enter the character data for node: P
P 
Enter the character data for node: R
P R 
Enter the character data for node: A
P A R 
Enter the character data for node: T
P A R T 
Enter the character data for node: I
P A R I T 
Enter the character data for node: K
P A R I T K 
0. Exit.
1. Inorder of BST1.
2. Inorder of BST2.
3. Merge two BST.
Enter your choice: 3
Merged BST is: 
K I N A I K R H I L P T
0. Exit.
1. Inorder of BST1.
2. Inorder of BST2.
3. Merge two BST.
Enter your choice: 1
Inorder of BST1 is: 
H I I K L N
0. Exit.
1. Inorder of BST1.
2. Inorder of BST2.
3. Merge two BST.
Enter your choice: 2
Inorder of BST2 is: 
A I K P R T
0. Exit.
1. Inorder of BST1.
2. Inorder of BST2.
3. Merge two BST.
Enter your choice: 0
*/

class BST
{
public:
    char data;
    BST *left;
    BST *right;
};

BST *root1;
BST *root2;
BST *root3;
void storeInorder(BST *root, int inorder[], int *index_ptr);
BST *sortedArrayToBST(int arr[], int start, int end);
int *merge(int arr1[], int arr2[], int m, int n);

BST *GetNewNode(char data)
{
    BST *newNode = new BST();
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

BST *mergeTrees(BST *root1, BST *root2, int m, int n)
{
    // Store inorder traversal of
    // first tree in an array arr1[]
    int *arr1 = new int[m];
    int i = 0;
    storeInorder(root1, arr1, &i);

    // Store inorder traversal of second
    // tree in another array arr2[]
    int *arr2 = new int[n];
    int j = 0;
    storeInorder(root2, arr2, &j);

    // Merge the two sorted array into one
    int *mergedArr = merge(arr1, arr2, m, n);

    // Construct a tree from the merged
    // array and return root of the tree
    return sortedArrayToBST(mergedArr, 0, m + n - 1);
}

void PrintInorder(BST *root)
{
    if (root == NULL)
    {
        return;
    }

    PrintInorder(root->left); /* first recur on left child */
    cout << root->data << " ";
    PrintInorder(root->right); /* now recur on right child */
}

void storeInorder(BST *root, int inorder[], int *index_ptr)
{
    if (root == NULL)
    {
        return;
    }

    storeInorder(root->left, inorder, index_ptr); /* first recur on left child */

    inorder[*index_ptr] = root->data;
    (*index_ptr)++; // increase index for next entry

    storeInorder(root->right, inorder, index_ptr);
}

int *merge(int arr1[], int arr2[], int m, int n)
{
    // mergedArr[] is going to contain result
    int *mergedArr = new int[m + n];
    int i = 0, j = 0, k = 0;

    // Traverse through both arrays
    while (i < m && j < n)
    {
        // Pick the smaler element and put it in mergedArr
        if (arr1[i] < arr2[j])
        {
            mergedArr[k] = arr1[i];
            i++;
        }
        else
        {
            mergedArr[k] = arr2[j];
            j++;
        }
        k++;
    }

    // If there are more elements in first array
    while (i < m)
    {
        mergedArr[k] = arr1[i];
        i++;
        k++;
    }

    // If there are more elements in second array
    while (j < n)
    {
        mergedArr[k] = arr2[j];
        j++;
        k++;
    }

    return mergedArr;
}

BST *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    BST *temp = GetNewNode(arr[mid]);

    temp->left = sortedArrayToBST(arr, start, mid - 1);

    temp->right = sortedArrayToBST(arr, mid + 1, end);

    return temp;
}

int main()
{
    root1 = NULL;
    root2 = NULL;
    root3 = NULL;
    int choice, m, n;
    char data;

    cout << "\nEnter size of 1st tree: ";
    cin >> m;
    for (int j = 0; j < m; j++)
    {
        cout << "\nEnter the character data for node: ";
        cin >> data;
        root1 = Insert(root1, data);

        BFS_Traverse(root1); // prints BST after user input.
    }

    cout << "\nEnter size of 2nd tree: ";
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        cout << "\nEnter the character data for node: ";
        cin >> data;
        root2 = Insert(root2, data);

        BFS_Traverse(root2); // prints BST after user input.
    }

    cout << endl;
    do
    {
        cout << "0. Exit." << endl
             << "1. Inorder of BST1." << endl
             << "2. Inorder of BST2." << endl
             << "3. Merge two BST." << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Inorder of BST1 is: " << endl;
            PrintInorder(root1);
            cout << endl;
            break;

        case 2:
            cout << "Inorder of BST2 is: " << endl;
            PrintInorder(root2);
            cout << endl;
            break;

        case 3:
            cout << "Merged BST is: " << endl;
            root3 = mergeTrees(root1, root2, m, n);
            BFS_Traverse(root3);
            cout << endl;
            break;

        default:
            break;
        }

    } while (choice != 0);
    return 0;
}
