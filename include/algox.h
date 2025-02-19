#include<string>

struct Node{
    Node* up;
    Node* down;
    Node* right;
    Node* left;
    Node* columno; // Pointer to column object

};
struct HeaderNode : Node{
    int one_count;
    std::string name;
};

//struct ElementNode : Node{};

class Dlink
{
private:
    Node* root;
public:
    Dlink(/* args */);
    ~Dlink();
};

Dlink::Dlink(/* args */)
{
}

Dlink::~Dlink()
{
}
