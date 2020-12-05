#include <iostream>

using namespace std;

struct Node {
    double x;
    double y;
    double z;
    std::string tag;

    Node *left;
    Node *rigth;

    Node (double x_, double y_, double z)
};

class KDTree {
    
    Node* root;
    


public:
    KDTree() {
        root = nullptr;
    }
    ~KDTree() {

    }


};


