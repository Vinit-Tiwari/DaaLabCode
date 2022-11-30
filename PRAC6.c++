#include <bits/stdc++.h>
using namespace std;
struct MinHeapNode
{
    char d;
    unsigned f;
    MinHeapNode *left, *right;
    MinHeapNode(char d, unsigned f)
    {
        left = NULL;
        right = NULL;
        this->d = d;
        this->f = f;
    }
};
struct compare
{
    bool operator()(MinHeapNode *l, MinHeapNode *r)
    {
        return (l->f, r->f);
    }
};
void printCodes(struct MinHeapNode *root, string str)
{
    if (!root)
    {
        return;
    }

    if (root->d != '$')
    {
        cout << root->d << ": " << str << "\n";
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
void Huffman_Coding(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare>
        minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new MinHeapNode('$', left->f + right->f);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}
int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    Huffman_Coding(arr, freq, size);
}
s