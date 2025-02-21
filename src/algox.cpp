#include "algox.h"
#include <iostream>
#include <vector>

Node::Node() {
    up       = nullptr;
    down     = nullptr;
    right    = nullptr;
    left     = nullptr;
    columno  = nullptr;
    rowIndex = -1;
}

Dlink::Dlink() {
    root.right = &root;
    root.left  = &root;

    colCount         = 0;
    rowCount         = 0;
    currentRowIndex  = 0;
}

Dlink::~Dlink() {
}

void Dlink::add_column(std::string name) {
    HeaderNode* new_header_node = new HeaderNode();
    new_header_node->name      = name;
    new_header_node->colIndex  = colCount++;
    new_header_node->up   = new_header_node;
    new_header_node->down = new_header_node;

    if (root.right == &root && root.left == &root) {
        root.right             = new_header_node;
        root.left              = new_header_node;

        new_header_node->right = &root;
        new_header_node->left  = &root;
    }
    else {
        Node* last             = root.left;
        last->right            = new_header_node;
        new_header_node->left  = last;
        new_header_node->right = &root;
        root.left              = new_header_node;
    }
}


void Dlink::add_row(std::vector<bool> row) {
    Node* colNode = root.right;
    for (std::size_t i = 0; i < row.size() && colNode != &root; i++) {
        if (row[i] == true) {
            Node* new_node  = new Node();
            new_node->rowIndex = currentRowIndex;
            new_node->columno  = colNode;

            new_node->up              = colNode->up;
            new_node->down            = colNode;
            colNode->up->down         = new_node;
            colNode->up               = new_node;

            HeaderNode* hdr = static_cast<HeaderNode*>(colNode);
            hdr->one_count++;
        }
        colNode = colNode->right;
    }
    currentRowIndex++;
}

void Dlink::from_2d_vector(std::vector<std::vector<bool>> matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return;
    }

    rowCount = matrix.size();
    std::size_t numCols = matrix[0].size();
    for (std::size_t c = 0; c < numCols; c++) {
        add_column(std::to_string(c));
    }

    for (std::size_t r = 0; r < matrix.size(); r++) {
        add_row(matrix[r]);
    }
}

void Dlink::print_headers() {
    Node* current_node = root.right;
    while (current_node != &root) {
        HeaderNode* header = static_cast<HeaderNode*>(current_node);
        std::cout 
            << "Column[" << header->colIndex << "] "
            << header->name 
            << " has one_count=" << header->one_count 
            << std::endl;

        current_node = current_node->right;
    }
}

void Dlink::print_matrix() {
    std::vector<std::vector<int>> matrix(rowCount, std::vector<int>(colCount, 0));

    Node* col = root.right;
    while (col != &root) {
        HeaderNode* hcol = static_cast<HeaderNode*>(col);
        Node* n = hcol->down; 
        while (n != col) {
            matrix[n->rowIndex][hcol->colIndex] = 1;
            n = n->down; 
        }
        col = col->right;
    }

    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            std::cout << matrix[r][c] << " ";
        }
        std::cout << "\n";
    }
}
