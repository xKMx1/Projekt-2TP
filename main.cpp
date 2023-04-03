#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

class Node{
public:
    int value;
    bool visited;
};

queue<int> q;

int main() {
    fstream fs;
    fs.open(R"(C:/Users/kamil/Desktop/projekt_Techniki_Programowania/Projekt-2TP/graph.txt)", ios::in);
    if (!fs) {
        cerr << "Failed to open the file"<< endl;
        exit(1);
    }

    while(fs.is_open()){
        char dane[100];
        while(fs >> dane){
            cout << dane;
        }
    }



    fs.close();
    return 0;
}