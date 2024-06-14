#include <catch2/catch_test_macros.hpp>
#include "rbtree.h"

TEST_CASE("RBTree_Insertion", "[Insert 3 Values No Rotates]") {
    RBTree<double> n (3.14);
    n.insert(2.7);
    n.insert(5.4);
    //(n.getRoot())->left->right = std::make_shared<Node<double>>(3.1,n.getRoot()->left);
    REQUIRE(n.getRoot()->val == 3.14);
    REQUIRE(n.getRoot()->left->val == 2.7);
    REQUIRE(n.getRoot()->right->val == 5.4);
}


TEST_CASE("RBTree_Insertion", "[Insert 3 Values Outer Rotate Left]") {
    RBTree<int> n (1);
    n.insert(2);
    n.insert(3);
    //(n.getRoot())->left->right = std::make_shared<Node<double>>(3.1,n.getRoot()->left);
    REQUIRE(n.getRoot()->val == 2);
    REQUIRE(n.getRoot()->left->val == 1);
    REQUIRE(n.getRoot()->right->val == 3);
}

TEST_CASE("RBTree_Insertion", "[Insert 3 Values Outer Rotate Right]") {
    RBTree<int> n{};
    
    n.insert(3);
    n.insert(2);
    n.insert(1);
    
    n.insert(0);
    //(n.getRoot())->left->right = std::make_shared<Node<double>>(3.1,n.getRoot()->left);
    REQUIRE(n.getRoot()->val == 2);
    REQUIRE(n.getRoot()->left->val == 1);
    REQUIRE(n.getRoot()->right->val == 3);
    REQUIRE(n.getRoot()->left->left->val == 0);
}

TEST_CASE("RBTree_Insertion", "[Insert 3 Values Double Rotate]") {
    RBTree<int> n (1);
    n.insert(3);
    n.insert(2);
    //(n.getRoot())->left->right = std::make_shared<Node<double>>(3.1,n.getRoot()->left);
    REQUIRE(n.getRoot()->val == 2);
    REQUIRE(n.getRoot()->left->val == 1);
    REQUIRE(n.getRoot()->right->val == 3);
}

TEST_CASE("RBTree_Insertion", "[Insert 5 values]") {
    RBTree<int> n (1);
    n.insert(2);
    n.insert(3);
    n.insert(4);
    n.insert(5);
    //(n.getRoot())->left->right = std::make_shared<Node<double>>(3.1,n.getRoot()->left);
    REQUIRE(n.getRoot()->val == 2);
    REQUIRE(n.getRoot()->left->val == 1);
    REQUIRE(n.getRoot()->right->val == 4);
    REQUIRE(n.getRoot()->right->left->val == 3);
    REQUIRE(n.getRoot()->right->right->val == 5);
}


TEST_CASE("RBTree_Insertion", "[Insert 7 values]") {
    RBTree<int> n (1);
    n.insert(2);
    n.insert(3);
    n.insert(4);
    n.insert(5);
    n.insert(8);
    n.insert(10);
    //(n.getRoot())->left->right = std::make_shared<Node<double>>(3.1,n.getRoot()->left);
    REQUIRE(n.getRoot()->val == 2);
    REQUIRE(n.getRoot()->left->val == 1);
    REQUIRE(n.getRoot()->right->val == 4);
    REQUIRE(n.getRoot()->right->left->val == 3);
    REQUIRE(n.getRoot()->right->right->val == 8);
    REQUIRE(n.getRoot()->right->right->left->val == 5);
    REQUIRE(n.getRoot()->right->right->right->val == 10);

    REQUIRE(n.getRoot()->right->c == Color::red);
    REQUIRE(n.getRoot()->left->c == Color::black);

    REQUIRE(n.getRoot()->right->right->right->c == Color::red);
    REQUIRE(n.getRoot()->right->right->c == Color::black);
}

TEST_CASE("RBTree_Insertion", "[Left Tree Insertions]") {
    RBTree<int> n (100);
    n.insert(99);
    n.insert(98);
    n.insert(97);
    n.insert(96);
    n.insert(95);
    n.insert(94);
    n.insert(93);
    //(n.getRoot())->left->right = std::make_shared<Node<double>>(3.1,n.getRoot()->left);
    REQUIRE(n.getRoot()->val == 97);
    REQUIRE(n.getRoot()->left->val == 95);
    REQUIRE(n.getRoot()->right->val == 99);
    REQUIRE(n.getRoot()->right->left->val == 98);
    REQUIRE(n.getRoot()->right->right->val == 100);
    REQUIRE(n.getRoot()->left->left->val == 94);
    REQUIRE(n.getRoot()->left->right->val == 96);
    REQUIRE(n.getRoot()->left->left->left->val == 93);
}