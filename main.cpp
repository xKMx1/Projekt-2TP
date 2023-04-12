#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    char value;
    bool visited;
    int id;
};

vector<vector<Node>> collection;

void makeVector(Node *Tab, int k) {
    fstream fs;

    fs.open("graph.txt", ios::in);
    if (!fs) {
        cerr << "Failed to open the file" << endl;
        exit(1);
    }
    string line;
    int n = 0;

    for (int i = 0; i < k; i++) { // for wypełniająy po koeli id wierzchołków
        Tab[i].id = n;
        Tab[i].visited = false;
        n++;
    }
    n = 0; // zerujemy n do ponownego użycia

    while (getline(fs, line)) { // przelatujemy przez cały plik linia po lini i uzupełniamy value wierchołków w głownej tablicy
        for (int i = 0; i < line.size(); i++) {
            if(i == 0){
                Tab[n].value = line[i];
            }
        }
        n++;
    }

    fs.clear();           // dwie linijki które umożliwiają nam pownowną iterację po całym pliku
    fs.seekg(0, fs.beg);

    while(getline(fs, line)){    // iterujemy po pliku linia po liniu i zapełniamy małe wektory
        vector<Node> nodeVector;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] != ' ' && i > 1) {
                for(int j = 0; j < k; j++){
                    if(Tab[j].value == line[i]){
                        nodeVector.push_back(Tab[j]);
                    }
                }
            }
        }
        collection.push_back(nodeVector);
        nodeVector.clear();
    }

//    cout << "-------Wczytywanie-------" << endl;
//    for (const auto& row : collection) {
//        for (const auto& node : row) {
//            cout << node.value << " ";
//        }
//        cout << endl;
//    }
//    cout << "-------------------------" << endl;
    fs.close();
}


void bfs(vector<vector<Node>>& graph, Node start, Node *Tab, int k) {
    queue<Node> q;

    // dodanie startowego wierzchołka do kolejki i oznaczenie go jako odwiedzony
    q.push(start);
    for(int j = 0; j < k; j++){      // przeszukujemy główną tablicę i oznaczamy startowy wierzchołek jako odwiedzony
        if(Tab[j].id == start.id){
            Tab[j].visited = true;
        }
    }

    while (!q.empty()) {
        // pobranie pierwszego wierzchołka z kolejki
        Node current = q.front();
        q.pop();

        cout << current.value << " ";

        // dla każdego nieodwiedzonego sąsiada aktualnego wierzchołka
        for (Node& neighbor : collection[current.id]) {
            for(int j = 0; j < k; j++){
                if(Tab[j].id == neighbor.id && Tab[j].visited == false){
                    q.push(Tab[j]);
                    Tab[j].visited = true;
                }
            }
        }
    }
}

int main() {
    int k;
    cout << "Ile wierzcholkow ma graf: "; // tworzymy dynamiczną tablicę Nodeów
    cin >> k;
    Node *Tab = new Node[k];

    makeVector(Tab, k);
    bfs(collection, Tab[0], Tab, k);
    return 0;
}