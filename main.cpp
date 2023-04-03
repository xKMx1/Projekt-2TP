#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

class Node{
public:
    char value;
    bool visited;
};

queue<int> q;
vector<vector<Node>> collection;
vector<Node> nodeVector;


int main() {
    fstream fs;
    fs.open("graph.txt", ios::in);
    if (!fs) {
        cerr << "Failed to open the file"<< endl;
        exit(1);
    }
    Node currentChar{};
    while(fs >> currentChar.value){
        fs >> currentChar.value;

        if(currentChar.value == ']'){
            collection.push_back(nodeVector);
            nodeVector.clear();
        }
        else if(currentChar.value == '[' or currentChar.value == ','){
        }
        else{
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
    return 0;
}