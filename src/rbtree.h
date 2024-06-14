#pragma once
#include <memory>
#include <iostream>

enum class Color{
    red=0,
    black=1,
};

template <typename T>
struct Node{
    T val;
    std::shared_ptr<Node<T>> left;
    std::shared_ptr<Node<T>> right;
    std::weak_ptr<Node<T>> parent;
    Color c;

    Node(const T& value) : val(value), left(nullptr), right(nullptr), parent(), c(Color::red)
    {}

    Node(const T& value, std::shared_ptr<Node<T>> left_, std::shared_ptr<Node<T>> right_, std::weak_ptr<Node<T>> parent_) : val(value), left(left_), right(right_), parent(parent_), c(Color::red)
    {}

    Node(const T& value, std::weak_ptr<Node<T>> parent_) : val(value), left(nullptr), right(nullptr), parent(parent_), c(Color::red)
    {}

    void addLeft(const T& val){
        left = std::make_shared<Node<T>>(val);
    }

    void addLeft(const T& value, std::weak_ptr<Node<T>> parent_){
        left = std::make_shared<Node<T>>(value, parent_);
    }

    void addLeft(const T& value, std::shared_ptr<Node<T>> left_, std::shared_ptr<Node<T>> right_, std::weak_ptr<Node<T>> parent_){
        left = std::make_shared<Node<T>>(value,left_,right_, parent_);
    }



    void addRight(const T& val){
        right = std::make_shared<Node<T>>(val);
    }

    void addRight(const T& val, std::weak_ptr<Node<T>> parent_){
        right = std::make_shared<Node<T>>(val,parent_);
    }

    void addRight(const T& value, std::shared_ptr<Node<T>> left_, std::shared_ptr<Node<T>> right_, std::weak_ptr<Node<T>> parent_){
        right = std::make_shared<Node<T>>(value, left_, right_, parent_);
    }


    void swapColor(){
        c = c == Color::red ? Color::black : Color::red;
    }

    inline bool isRoot(){
        return parent;
    }
    
};


template <typename T>
class RBTree{
public:
    RBTree(T val) : root(std::make_shared<Node<T>>(val))
    {}

    RBTree() : root(nullptr)
    {}

    std::shared_ptr<Node<T>> find(T key){
        auto node = root;
        while(node && node->val != key){
            if (node->val > key) node = node->left;
            else node = node->right;
        }
        if (node) return node;
        else return nullptr;
    }

    std::shared_ptr<Node<T>> findParent(const T& val){
        auto node = root;
        while(node){
            if (node->val > val && !node->left ) return node;
            else if (node->val > val && node->left) node = node->left;
            else if (node->val < val && !node->right ) return node;
            else if (node->val < val && node->right) node = node->right;
            else if (node->val == val) return nullptr;
            else return nullptr;
        }
        return nullptr;
    }

    std::shared_ptr<Node<T>> max(){
        auto node = root;
        while(node->right) node = node->right;
        return node;
    }

    std::shared_ptr<Node<T>> min(){
        auto node = root;
        while(node->left) node = node->left;
        return node;
    }

    std::shared_ptr<Node<T>> getRoot(){
        return root;
    }

    void rotateRight(std::shared_ptr<Node<T>> P){
        auto G = P->parent.lock();
        auto S = P->left;
        assert(S);
        auto C = S->right;

        P->left = C;
        if (C) C->parent = P;

        S->right = P;
        P->parent = S;

        S->parent = G;

        if(G && G->left == P)        G->left = S;
        else if (G && G->right == P) G->right = S;
        else                         root = S;
    }

    void rotateLeft(std::shared_ptr<Node<T>> P){
        auto G = P->parent.lock();
        auto S = P->right;
        assert(S);
        auto C = S->left;

        P->right = C;
        if (C) C->parent = P;

        S->left = P;
        P->parent = S;

        S->parent = G;

        if(G && G->left == P)        G->left = S;
        else if (G && G->right == P) G->right = S;
        else                         root = S;
    }

    void insert(const T& val){
        auto P = findParent(val);
        if (!P){
            root = std::make_shared<Node<T>>(val); //CASE 2
            return;
        }

        auto N = std::make_shared<Node<T>>(val, P);
        if (P->val > val) P->left  = N;
        else              P->right = N;


        while(P){
            if (P->c == Color::black) return; // CASE 1

            auto G = P->parent.lock();
            if (!G){ //CASE 4
                P->c = Color::black;
                return;
            }

            auto U = G->left == P ? G->right : G->left;
            if (!U || U->c == Color::black){
                if ((P == G->left && N == P->right) || (P == G->right && N == P->left)){
                    if (N == P->right){
                        rotateLeft(P);
                        N = P;
                        P = G->left;
                    }
                    else{
                        rotateRight(P);
                        N = P;
                        P = G->right;
                    }
                }
                if (P == G->left){
                    rotateRight(G);
                }
                else{
                    rotateLeft(G);
                }
                P->c = Color::black;
                G->c = Color::red;

                return;
            }
            P->c = Color::black;
            U->c = Color::black;
            G->c = Color::red;
            N = G;
            P = N->parent.lock(); 
        }
    }

    void deleteNode(const T& val){
        auto N = find(val);
        
        if (!N) return;

        if (N->left && N->right){
            auto node = N->right;
            while (node->left){
                node = node->left;
            }
            N->val = node->val;
            if (node->parent.lock()->left == node) node->parent.lock()->left = nullptr;
            else node->parent.lock()->right = nullptr;
        }

        else if (N->left && !N->right){
            N->val = N->left->val;
            N->left = nullptr;
            N->c = Color::black;
        }

        else if (!N->left && N->right){
            N->val = N->right->val;
            N->right = nullptr;
            N->c = Color::black;
        }

        else{
            if (N == getRoot()) root = nullptr;
            else if (N->c == Color::red){
                if (N->parent.lock()->right == N) N->parent.lock()->right = nullptr;
                else N->parent.lock()->left = nullptr;
            }
            else{
                deleteBlackLeaf(N);
            }
        }
    }

    void deleteBlackLeaf(std::shared_ptr<Node<T>> N) {        
        auto P = N->parent.lock();
        int left_right {0};
        bool calculated {true};
        if (P->left->val == N->val){
            P->left  = nullptr;
            left_right = 0;
        }
        else{
            P->right = nullptr;
            left_right = 1;
        }                       
        
        while(P){
            std::shared_ptr<Node<T>> S,C,D;

            if (!calculated) left_right = P->left->val == N->val ? 0 : 1;
            else calculated = false;

            if (left_right == 0){
                S = P->right;
                if (S){
                    D = S->right;
                    C = S->left;
                }
            }
            else{
                S = P->left;
                if (S){
                    D = S->left;
                    C = S->right;
                }
            }


            if (S && S->c == Color::red){
                if (left_right == 0) rotateLeft(P);
                else                 rotateRight(P);
                P->c = Color::red;
                S->c = Color::black;
                S = C;
                if (left_right == 0) D = S->right;
                else                 D = S->left;

                if (D  && D->c == Color::red){
                    if (left_right == 0) rotateLeft(P);
                    else                 rotateRight(P);
                    S->c = P->c;
                    P->c = Color::black;
                    D->c = Color::black;
                    return;      
                }
                if (left_right == 0) C = S->left;
                else                 C = S->right;

                if (C  && C->c == Color::red){
                    if (left_right == 0) rotateRight(S);
                    else                 rotateLeft(S);
                    S->c = Color::red;
                    C->c = Color::black;
                    D = S;
                    S = C;
                    if (left_right == 0) rotateLeft(P);
                    else                 rotateRight(P);
                    S->c = P->c;
                    P->c = Color::black;
                    D->c = Color::black;
                    return;     
                }
                S->c = Color::red;
                P->c = Color::black;
                return;
            }

            if (D && D->c == Color::red){
                if (left_right == 0) rotateLeft(P);
                else                 rotateRight(P);
                S->c = P->c;
                P->c = Color::black;
                D->c = Color::black;
                return;    
            }
            if (C && C->c == Color::red){
                if (left_right == 0) rotateRight(S);
                else                 rotateLeft(S);
                S->c = Color::red;
                C->c = Color::black;
                D = S;
                S = C;
                std::cout << " reached this without segfault\n";
                if (left_right == 0) rotateLeft(P);
                else                 rotateRight(P);
                S->c = P->c;
                P->c = Color::black;
                D->c = Color::black;
                return;     
            }
            if (P->c == Color::red){
                S->c = Color::red;
                P->c = Color::black;
                return;
            }
            S->c = Color::red;
            N = P;
            P = N->parent.lock();
        }
    }
    

private:
    std::shared_ptr<Node<T>> root;
};