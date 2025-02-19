#include<string>

struct Node{
    Node* up;
    Node* down;
    Node* right;
    Node* left;
    Node* columno; // Pointer to column object

    Node();

};
struct HeaderNode : Node{
    int one_count;
    std::string name;
};

//struct ElementNode : Node{};

// Main circular linked list class
class Dlink
{
private:
    Node root;
public:
    Dlink();
    ~Dlink();
    void add_row();
    void add_column(std::string name);
    void print_headers();
};
