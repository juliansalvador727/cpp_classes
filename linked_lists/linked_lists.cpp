#include <iostream>

class Node {
    public:
        Node( double new_value_, Node* new_next );
        double value() const;
        Node* next() const;
    private:
        double value_;
        Node *p_next_node_;
    friend class Singly_Linked_List;
};

class Singly_Linked_List {
    public:
        Singly_Linked_List(std::initializer_list<double> values);
        void insert( double const &item );
        bool empty() const;
    private:
        Node *p_list_head_;
        friend std::ostream& operator<<(std::ostream& out, Singly_Linked_List const& rhs);
};



// Node
// empty constructor
Node::Node( double new_value_, Node* new_next ): value_{ new_value_ }, p_next_node_{ new_next } { };

double Node::value() const {
    return value_;
}

Node* Node::next() const {
    return p_next_node_;
}

// Linked Lists
Singly_Linked_List::Singly_Linked_List( std::initializer_list<double> values ): p_list_head_{ nullptr } { 
    for (const double& item : values) {
        insert(item);
    }
};

bool Singly_Linked_List::empty() const { return p_list_head_ == nullptr; };

void Singly_Linked_List::insert( double const &item ) {
    if (this->empty()) { p_list_head_ = new Node ( item, nullptr ); return; };
    Node* current{ p_list_head_ };
    while ( current->next() != nullptr ) current = current->next();
    current->p_next_node_ = new Node ( item, nullptr );
    return;
}

std::ostream& operator<<(std::ostream& out, Singly_Linked_List const& rhs) {
    out << "{";

    if (!rhs.empty()) {
        out << rhs.p_list_head_->value();

        for (Node* ptr = rhs.p_list_head_->next(); ptr != nullptr; ptr = ptr->next())  out << ", " << ptr->value();
    }

    out << "}";
    return out;
}

int main() {
    Singly_Linked_List list{1, 2, 3, 4, 5};
    std::cout << list << std::endl;
}

class Doubly_Linked_List {
    public:
    private:
        Node *p_list_head_;
};