#include "algox.h"
#include<iostream>
// Matrix data structure

Node::Node(){
    up    = nullptr;
    down  = nullptr;
    right = nullptr;
    left  = nullptr;
    columno = nullptr;
}



Dlink::Dlink(){
    root.right = &root;
    root.left = &root;
}
Dlink::~Dlink(){}
void Dlink::add_row(){}

void Dlink::add_column(std::string name) {
    HeaderNode* new_header_node = new HeaderNode();
    new_header_node->name = name;

    // There are no columns
    if (root.right == &root && root.left == &root)
    {
        root.right = new_header_node;
        root.left  = new_header_node;

        new_header_node->right = &root;
        new_header_node->left  = &root;
    }
    else
    {
        Node* last = root.left;
        last->right = new_header_node;
        new_header_node->left = last;
        new_header_node->right = &root;
        root.left = new_header_node;
    }
}


void Dlink::print_headers()
{
    Node* current_node = root.right;
    while (current_node != &root)
    {
        HeaderNode* header = static_cast<HeaderNode*>(current_node);
        std::cout << header->name << std::endl;
        current_node = current_node->right;
    }
}
