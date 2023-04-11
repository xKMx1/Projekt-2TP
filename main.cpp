#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

struct remember {
    int index;
    char node;
};

class Node {
public:
    char value;
    bool visited;
};

queue<Node> q;
vector<vector<Node>> collection;
vector<Node> nodeVector;
vector<remember> neighbours;

void makeNodeVisited(Node root)
{
    for (int j = 0; j < collection.size(); j++)
    {
        for (int k = 0; k < collection[j].size(); k++)
        {
            if (nodeVector[k].value == root.value)
            {
                nodeVector[k].visited = true;
            }
        }
    }
}

void pushToQueue(int currentIndex)
{
    for (int j = 0; j < collection.size(); j++)
    {
        for (int k = 0; k < collection[currentIndex].size(); k++)
        {
            if (j == currentIndex)
            {
                if (!nodeVector[k].visited)
                {
                    q.push(nodeVector[k]);
                }
            }
        }
    }
}

void queueSearch(Node root)
{
    int currentIndex = 0;
    Node firstInQueue{};
    q.push(root);

    for (int i = 0; i < neighbours.size(); i++)
    {
        if (neighbours[i].node == root.value)
        {
            currentIndex = neighbours[i].index;
        }
    }

    int iterator = 0;

    firstInQueue = q.front();
    cout << firstInQueue.value;
    pushToQueue(currentIndex);
    makeNodeVisited(root);
    q.pop();
    root = q.front();
}

void makeVector() {
    int level = 0;
    fstream fs;

    fs.open("graph.txt", ios::in);
    if (!fs) {
        cerr << "Failed to open the file" << endl;
        exit(1);
    }

    Node currentChar{};
    while (fs >> noskipws >> currentChar.value)
    {
        if (currentChar.value == '\n') {
            collection.push_back(nodeVector);
            nodeVector.clear();
            level = 0;
        }
        else if (currentChar.value == ' ') {
            level = 1;
        }
        else if (level == 0)
        {
            remember currentNode{};
            currentNode.index= collection.size();
            currentNode.node= currentChar.value;
            neighbours.push_back(currentNode);
        }
        else {
            nodeVector.push_back(currentChar);
        }
    }
    for (const auto& row : collection) {
        for (const auto& node : row) {
            cout << node.value << " ";
        }
        cout << endl;
    }
    fs.close();
}


int main() {
    makeVector();
    Node root{};
    cout << "od ktorego wierzcholka chcesz zaczac przeszukiwanie?" << endl;
    cin >> root.value;
    queueSearch(root);
    return 0;
}