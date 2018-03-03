#ifndef AISDI_MAPS_TREEMAP_H
#define AISDI_MAPS_TREEMAP_H

#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <utility>

namespace aisdi
{

template <typename KeyType, typename ValueType>
class TreeMap
{
public:
    using key_type = KeyType;
    using mapped_type = ValueType;
    using value_type = std::pair<const key_type, mapped_type>;
    using size_type = std::size_t;
    using reference = value_type&;
    using const_reference = const value_type&;

    class ConstIterator;
    class Iterator;
    using iterator = Iterator;
    using const_iterator = ConstIterator;

private:
    struct Node
    {
        value_type value;
        int Height;
        Node *left, *right, *parent;
        Node(key_type key, mapped_type mapped)
            : value(std::make_pair( key, mapped )), Height(1), left(nullptr), right(nullptr), parent(nullptr) {}

        Node(value_type it) : Node(it.first, it.second) {}

        ~Node()
        {
            delete left;
            delete right;
        }
    };


    Node* root;
    size_type length;

public:
    TreeMap() : root(nullptr), length(0) {}

    TreeMap(std::initializer_list<value_type> list) : TreeMap()
    {
        for (auto it = list.begin(); it != list.end(); ++it)
            insert( new Node(*it) );
    }

    TreeMap(const TreeMap& other) : TreeMap()
    {
        *this = other;
    }

    TreeMap(TreeMap&& other) : TreeMap()
    {
        *this = std::move(other);
    }

    ~TreeMap()
    {
        erase();
    }

    TreeMap& operator=(const TreeMap& other)
    {
        if(this != &other)
        {
            erase();
            for (auto it = other.begin(); it != other.end(); ++it)
                insert( new Node(*it) );
        }

        return *this;
    }

    TreeMap& operator=(TreeMap&& other)
    {
        if(this != &other)
        {
            erase();
            root = other.root;
            length = other.length;

            other.root = nullptr;
            other.length = 0;
        }

        return *this;
    }

    bool isEmpty() const
    {
        return !length;
    }

    mapped_type& operator[](const key_type& key)
    {
        Node* current = findNode(key);
        if( current == nullptr )
        {
            current = new Node(key, mapped_type());
            insert( current );
        }

        return current->value.second;
    }

    const mapped_type& valueOf(const key_type& key) const
    {
        const Node* current = findNode(key);
        if(current == nullptr)
            throw std::out_of_range("Out of range!!! for const");

        return current->value.second;
    }

    mapped_type& valueOf(const key_type& key)
    {
        Node* current = findNode(key);
        if(current == nullptr)
            throw std::out_of_range("Out of range!!!");

        return current->value.second;
    }

    const_iterator find(const key_type& key) const
    {
        return const_iterator(this, findNode(key));
    }

    iterator find(const key_type& key)
    {
        return iterator(this, findNode(key));
    }

    void remove(const key_type& key)
    {
        remove( find(key) );
    }

    void remove(const const_iterator& it)
    {
        if(this != it.tree || it == end())
            throw std::out_of_range ("Out of range!!!- for remove");
        remove( it.node );
    }

    size_type getSize() const
    {
        return length;
    }

    bool operator==(const TreeMap& other) const
    {
        if( length != other.length )
            return false;

        for(auto it = begin(), it2 = other.begin(); it != end(); ++it, ++it2)
        {
            if(*it != *it2)
                return false;
        }

        return true;
    }

    bool operator!=(const TreeMap& other) const
    {
        return !(*this == other);
    }

    iterator begin()
    {
        return iterator(this, Node_Smallest_Value(root));
    }

    iterator end()
    {
        return iterator(this);
    }

    const_iterator cbegin() const
    {
        return const_iterator(this, Node_Smallest_Value(root));
    }

    const_iterator cend() const
    {
        return const_iterator(this);
    }

    const_iterator begin() const
    {
        return cbegin();
    }

    const_iterator end() const
    {
        return cend();
    }

private:
    void erase()
    {
        delete root;
        root = nullptr;
        length = 0;
    }

    void insert(Node* newNode)
    {
        if(root == nullptr)
            root = newNode;

        else
        {
            Node* current = root;
            while (true)
            {
                if(newNode->value.first < current->value.first && current->left == nullptr)
                {
                    current->left = newNode;
                    newNode->parent = current;
                    break;
                }

                else if(newNode->value.first < current->value.first && current->left != nullptr)
                    current = current->left;


                else if(newNode->value.first > current->value.first && current->right == nullptr)
                {
                    current->right = newNode;
                    newNode->parent = current;
                    break;
                }

                else if(newNode->value.first > current->value.first && current->right != nullptr)
                    current = current->right;

                else
                {
                    delete newNode;
                    return;
                }
            }
            balance_tree(current);
        }
        length++;
        return;
    }

    void replace(Node* First, Node* Second)
    {
        if(First->parent == nullptr)
            root = Second;

        else if(First == First->parent->left)
            First->parent->left = Second;

        else
            First->parent->right = Second;


        if (Second != nullptr)
        {
            Second->parent = First->parent;
            if(First->right != nullptr && First->right != Second)
            {
                Second->right = First->right;
                Second->right->parent = Second;
            }

            if(First->left != nullptr && First->left != Second)
            {
                Second->left = First->left;
                Second->left->parent = Second;
            }
        }

        First->parent = nullptr;
        First->left = nullptr;
        First->right = nullptr;
    }

    void remove(Node* node)
    {
        Node* tmp;
        if(node->left == nullptr)
        {
            tmp = node->right;
            replace(node, tmp);
        }

        else if(node->right == nullptr)
        {
            tmp = node->left;
            replace(node, tmp);
        }

        else
        {
            tmp = node->right;
            while (tmp->left != nullptr)
                tmp = tmp->left;
            replace(tmp, tmp->right);
            replace(node, tmp);
        }

        while (tmp != nullptr)
        {
            change_height(tmp);
            tmp = tmp->parent;
        }

        length--;
        delete node;
    }

    Node* findNode(const key_type& key) const
    {
        Node* node = root;
        while ( node != nullptr )
        {
            if (key > node->value.first)
                node = node->right;

            else if (key < node->value.first)
                node = node->left;

            else
                break;
        }

        return node;
    }

    Node* Node_Smallest_Value(Node* node) const
    {
        if(node != nullptr)
            while(node->left != nullptr)
                node = node->left;

        return node;
    }

    int get_node_height(Node* node) const
    {
        if(node == nullptr)
            return 0;

        return node->Height;
    }

    int max_height(Node* First, Node* Second) const
    {
        return get_node_height(First) > get_node_height(Second) ? get_node_height(First) : get_node_height(Second);
    }

    void change_height(Node* node)
    {
        node->Height = max_height(node->left, node->right) + 1;
    }

    void balance_tree(Node* current)
    {
        while(current != nullptr)
        {
            if(is_balance(current) == false)
            {
                if(get_node_height(current->left) <= get_node_height(current->right))
                {
                    if(get_node_height(current->right->left) <= get_node_height(current->right->right))
                        left_rotation(current);

                    else
                    {
                        right_rotation(current->right);
                        change_height(current->right);
                        left_rotation(current);
                    }
                }

                else
                {
                    if(get_node_height(current->left->left) >= get_node_height(current->left->right))
                        right_rotation(current);

                    else
                    {
                        left_rotation(current->left);
                        change_height(current->left);
                        right_rotation(current);
                    }
                }
            }

            change_height(current);
            current = current->parent;
        }
    }

    bool is_balance(Node* node) const
    {
        if(node == nullptr)
            return false;

        if(get_node_height(node->left) == get_node_height(node->right) || get_node_height(node->left) == get_node_height(node->right) + 1 ||
            get_node_height(node->left) + 1 == get_node_height(node->right) )
            return true;

        return false;
    }

    void right_rotation(Node* node)
    {
        Node *P, *L, *LR;
        P = node->parent;
        L = node->left;
        LR = node->left->right;

        if(P != nullptr)
        {
            if (P->right == node)
                P->right = L;

            else
                P->left = L;
        }

        else
            root = L;

        L->parent = P;
        L->right = node;

        node->parent = L;
        node->left = LR;

        if(LR != nullptr)
            LR->parent = node;

        change_height(node);
    }

    void left_rotation(Node* node)
    {
        Node *P, *R, *RL;
        P = node->parent;
        R = node->right;
        RL = node->right->left;

        if(P != nullptr)
        {
            if(P->right == node)
                P->right = R;

            else
                P->left = R;
        }

        else
            root = R;

        R->parent = P;
        R->left = node;

        node->parent = R;
        node->right = RL;

        if(RL != nullptr)
            RL->parent = node;

        change_height(node);
    }
};

template <typename KeyType, typename ValueType>
class TreeMap<KeyType, ValueType>::ConstIterator
{
public:
    using reference = typename TreeMap::const_reference;
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = typename TreeMap::value_type;
    using pointer = const typename TreeMap::value_type*;

private:
    const TreeMap *tree;
    Node *node;
    friend void TreeMap<KeyType, ValueType>::remove(const const_iterator&);

public:
    explicit ConstIterator(const TreeMap *tree = nullptr, Node *node = nullptr) : tree(tree), node(node) {}

    ConstIterator(const ConstIterator& other) : ConstIterator(other.tree, other.node) {}

    ConstIterator& operator++()
    {
        if(tree->root == nullptr || node == nullptr)
        {
            throw std::out_of_range("Out of range!!!- for operator++");
        }

        else if( node->right != nullptr )
        {
            node = node->right;
            while(node->left != nullptr)
                node = node->left;
        }

        else
        {
            while(true)
            {
                if(node->parent == nullptr)
                {
                    node = nullptr;
                    break;
                }

                if(node->parent->left == node)
                {
                    node = node->parent;
                    break;
                }
                node = node->parent;
            }
        }

        return *this;
    }

    ConstIterator operator++(int)
    {
        auto result = *this;
        ConstIterator::operator++();
        return result;
    }

    ConstIterator& operator--()
    {
        if(tree->root == nullptr)
        {
            throw std::out_of_range("Out of range!!!- for operator--");
        }

        else if(node == nullptr)
        {
            node = tree->root;
            while(node->right != nullptr)
                node = node->right;
        }

        else if(node->left != nullptr )
        {
            node = node->left;
            while(node->right != nullptr)
                node = node->right;
        }

        else
        {
            while(true)
            {
                if(node->parent == nullptr)
                {
                    throw std::out_of_range("Out of range!!!- for operator--");
                }

                if(node->parent->right == node)
                {
                    node = node->parent;
                    break;
                }
                node = node->parent;
            }
        }

        return *this;
    }

    ConstIterator operator--(int)
    {
        auto result = *this;
        ConstIterator::operator--();
        return result;
    }

    reference operator*() const
    {
        if(tree == nullptr || node == nullptr)
            throw std::out_of_range("Out of range!!!- for operator*");
        return node->value;
    }

    pointer operator->() const
    {
        return &this->operator*();
    }

    bool operator==(const ConstIterator& other) const
    {
        return tree == other.tree && node == other.node;
    }

    bool operator!=(const ConstIterator& other) const
    {
        return !(*this == other);
    }
};

template <typename KeyType, typename ValueType>
class TreeMap<KeyType, ValueType>::Iterator : public TreeMap<KeyType, ValueType>::ConstIterator
{
public:
    using reference = typename TreeMap::reference;
    using pointer = typename TreeMap::value_type*;

    explicit Iterator(TreeMap *tree = nullptr, Node *node = nullptr) : ConstIterator(tree, node) {}

    Iterator(const ConstIterator& other) : ConstIterator(other) {}

    Iterator& operator++()
    {
        ConstIterator::operator++();
        return *this;
    }

    Iterator operator++(int)
    {
        auto result = *this;
        ConstIterator::operator++();
        return result;
    }

    Iterator& operator--()
    {
        ConstIterator::operator--();
        return *this;
    }

    Iterator operator--(int)
    {
        auto result = *this;
        ConstIterator::operator--();
        return result;
    }

    pointer operator->() const
    {
        return &this->operator*();
    }

    reference operator*() const
    {
        // ugly cast, yet reduces code duplication.
        return const_cast<reference>(ConstIterator::operator*());
    }
};

}

#endif /* AISDI_MAPS_MAP_H */
