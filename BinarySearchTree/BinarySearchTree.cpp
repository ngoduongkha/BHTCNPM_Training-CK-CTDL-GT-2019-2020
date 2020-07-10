#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
    int Data;
    node* ptrLeft;
    node* ptrRight;
};

typedef struct node TNode;
typedef struct node* Tree;

void initTree(Tree& Root);
TNode* getTNode(int data);
int insertTNode(Tree& Root, int data);
void NLR(const Tree& Root);
void NRL(const Tree& Root);
void LNR(const Tree& Root);
void RNL(const Tree& Root);
void LRN(const Tree& Root);
void RLN(const Tree& Root);
TNode* searchTNode(const Tree& Root, int data);
TNode* getMaxTNode(const Tree& Root);
TNode* getMinTNode(const Tree& Root);
void deleteTNode(Tree& Root, int data);
int heightOfTree(const Tree& Root);
int countTNode(const Tree& Root);
void printGivenLevel(const Tree& Root, int level);

int main()
{
    Tree Root;
    initTree(Root);
    int data;
    cout << "Nhap gia tri cac node cua cay (Nhap -1 de thoat): ";
    do
    {
        cin >> data;
        if (data != -1)
            insertTNode(Root, data);
    } while (data != -1);

    cout << "Node-Left-Right: "; NLR(Root); cout << "\n";
    cout << "Node-Right-Left: "; NRL(Root); cout << "\n";
    cout << "Left-Node-Right: "; LNR(Root); cout << "\n";
    cout << "Right-Node-Left: "; RNL(Root); cout << "\n";
    cout << "Left-Right-Node: "; LRN(Root); cout << "\n";
    cout << "Right-Left-Node: "; RLN(Root); cout << "\n";

    cout << "TNode co gia tri max: " << getMaxTNode(Root)->Data << "\n";
    cout << "TNode co gia tri min: " << getMinTNode(Root)->Data << "\n";

    cout << "Chieu cao cua cay: " << heightOfTree(Root) - 1 << "\n";

    cout << "So TNode cua cay: " << countTNode(Root) << "\n";

    return 0;
}

// Hàm khởi tạo cây
void initTree(Tree& Root)
{
    Root = NULL;
}

// Hàm khởi tạo một TNode
TNode* getTNode(int data)
{
    TNode* tmp = new TNode;
    if (tmp == NULL)
        return NULL;
    tmp->Data = data;
    tmp->ptrLeft = NULL;
    tmp->ptrRight = NULL;
    return tmp;
}

// Hàm thêm TNode vào cây
int insertTNode(Tree& Root, int data)
{
    if (Root != NULL)
    {
        if (data > Root->Data)
            return insertTNode(Root->ptrRight, data);
        else if (data < Root->Data)
            return insertTNode(Root->ptrLeft, data);
        else
            return 0;
    }
    else
    {
        Root = new TNode;
        if (Root == NULL)
            return -1;
        Root->Data = data;
        Root->ptrLeft = Root->ptrRight = NULL;
        return 1;
    }
}

// Duyệt Node-Left-Right
void NLR(const Tree& Root)
{
    if (Root != NULL)
    {
        cout << Root->Data << " ";
        NLR(Root->ptrLeft);
        NLR(Root->ptrRight);
    }
}

// Duyệt Node-Right-Left
void NRL(const Tree& Root)
{
    if (Root != NULL)
    {
        cout << Root->Data << " ";
        NRL(Root->ptrRight);
        NRL(Root->ptrLeft);
    }
}

// Duyệt Left-Node-Right
void LNR(const Tree& Root)
{
    if (Root != NULL)
    {
        LNR(Root->ptrLeft);
        cout << Root->Data << " ";
        LNR(Root->ptrRight);
    }
}

// Duyệt Right-Node-Left
void RNL(const Tree& Root)
{
    if (Root != NULL)
    {
        RNL(Root->ptrRight);
        cout << Root->Data << " ";
        RNL(Root->ptrLeft);
    }
}

// Duyệt Left-Right-Node
void LRN(const Tree& Root)
{
    if (Root != NULL)
    {
        LRN(Root->ptrLeft);
        LRN(Root->ptrRight);
        cout << Root->Data << " ";
    }
}

// Duyệt Right-Left-Node
void RLN(const Tree& Root)
{
    if (Root != NULL)
    {
        RLN(Root->ptrRight);
        RLN(Root->ptrLeft);
        cout << Root->Data << " ";
    }
}

// Hàm tìm TNode
TNode* searchTNode(const Tree& Root, int data)
{
    TNode* tmp = Root;
    while (tmp != NULL)
    {
        if (tmp->Data > data)
            tmp = tmp->ptrRight;
        else if (tmp->Data < data)
            tmp = tmp->ptrLeft;
        else
            return tmp;
    }
    return NULL;
}

// Hàm tìm TNode có giá trị max
TNode* getMaxTNode(const Tree& Root)
{
    if (Root != NULL)
    {
        if (Root->ptrRight != NULL)
            return getMaxTNode(Root->ptrRight);
        else
            return Root;
    }
    else
        return NULL;
}

// Hàm tìm TNode có giá trị min
TNode* getMinTNode(const Tree& Root)
{
    if (Root != NULL)
    {
        if (Root->ptrLeft != NULL)
            return getMinTNode(Root->ptrLeft);
        else
            return Root;
    }
    else
        return NULL;
}

// Hàm xóa một TNode
void deleteTNode(Tree& Root, int data)
{
    if (Root != NULL)
    {
        if (data < Root->Data)
            deleteTNode(Root->ptrLeft, data);
        else if (data > Root->Data)
            deleteTNode(Root->ptrRight, data);
        else
        {
            if (Root->ptrLeft == NULL)
                Root = Root->ptrRight;
            else if (Root->ptrRight == NULL)
                Root = Root->ptrLeft;
            else
            {
                TNode* TheMang = getMaxTNode(Root->ptrLeft);
                Root->Data = TheMang->Data;
                deleteTNode(Root->ptrLeft, TheMang->Data);
                delete TheMang;
            }
        }
    }
}

// Hàm tìm chiều cao của cây
int heightOfTree(const Tree& Root)
{
    if (Root != NULL)
    {
        int Left = heightOfTree(Root->ptrLeft);
        int Right = heightOfTree(Root->ptrRight);
        return 1 + max(Left, Right);
    }
    else
        return 0;
}

// Hàm đếm số TNode của cây
int countTNode(const Tree& Root)
{
    if (Root != NULL)
        return 1 + countTNode(Root->ptrLeft) + countTNode(Root->ptrRight);
    else
        return 0;
}

// Hàm in TNode theo mức
void printGivenLevel(const Tree& Root, int level)
{
    if (Root == NULL)
        return;
    if (level == 1)
        cout << Root->Data << " ";
    else if (level > 1)
    {
        printGivenLevel(Root->ptrLeft, level - 1);
        printGivenLevel(Root->ptrRight, level - 1);
    }
}