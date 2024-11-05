#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    char data;
    int freq;
    Node* left;
    Node* right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printNodes(Node* root, string val) {
    if(root == nullptr)
        return;

    if(root->data != '#') 
        cout<<root->data<<":"<<val<<endl;
    
    printNodes(root->left, val + '0');
    printNodes(root->right, val + '1');
}

void huffmanCode(vector<char> data, vector<int> freq, int size) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    for(int i=0; i<size; i++) {
        Node* newNode = new Node(data[i], freq[i]);
        pq.push(newNode);
    }

    while(pq.size() != 1) {
        Node* leftNode = pq.top();
        pq.pop();
        
        Node* rightNode = pq.top();
        pq.pop();

        Node* temp = new Node('#', leftNode->freq + rightNode->freq);
        temp->left = leftNode;
        temp->right = rightNode;

        pq.push(temp);
    }

    printNodes(pq.top(), "");
}

int main() {
    vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    huffmanCode(data, freq, data.size());

    return 0;
}
