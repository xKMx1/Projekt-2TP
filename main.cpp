#include <iostream>
#include<fstream>
#include <queue>
#include <vector>

using namespace std;

queue<int> q;

void openFile(fstream *fs){
    fs.open(graf.txt, ios::in);

    if (!fs) {
        cerr << "Failed to open the file"<< endl;
        exit(1);
    }
}

int main() {
    fstream fs;
    openFile(fs);

    cout << fs.read();

    fs.close();
    return 0;
}
