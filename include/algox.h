#ifndef ALGOX_H
#define ALGOX_H

#include <string>
#include <vector>

struct Node;
struct HeaderNode;

struct Node {
    Node* up;
    Node* down;
    Node* left;
    Node* right;
    Node* columno;
    int rowIndex;
    Node();
};

struct HeaderNode : public Node {
    std::string name;   
    int one_count;       
    int colIndex;        
    HeaderNode() {
        one_count = 0;
        colIndex  = -1;
    }
};

class Dlink {
public:
    Node root;
    int colCount;
    int rowCount;
    int currentRowIndex;

public:
    Dlink();
    ~Dlink();
    void add_column(std::string name);
    void add_row(std::vector<bool> row);
    void from_2d_vector(std::vector<std::vector<bool>> matrix);
    void print_headers();
    void print_matrix();
};

#endif
