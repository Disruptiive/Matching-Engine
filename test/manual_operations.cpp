#include <catch2/catch_test_macros.hpp>
#include "rbtree.h"

TEST_CASE("RBTree_Manual_Insertion", "[Insert 4 Values]") {
    RBTree<double> n (3.14);
    (n.getRoot())->left = std::make_shared<Node<double>>(2.7,n.getRoot());
    (n.getRoot())->right = std::make_shared<Node<double>>(5.4,n.getRoot());
    (n.getRoot())->left->right = std::make_shared<Node<double>>(3.1,n.getRoot()->left);
    REQUIRE(n.getRoot()->left->right->val == 3.1);
    REQUIRE(n.getRoot()->left->right->parent.lock()->parent.lock()->val == 3.14);
}

TEST_CASE("RBTree_Manual_Rotate_Left", "[Insert and Rotate L]") {
    RBTree<int> n (1);
    (n.getRoot())->right = std::make_shared<Node<int>>(2,n.getRoot());
    (n.getRoot())->right->right = std::make_shared<Node<int>>(3,n.getRoot()->right);

    n.rotateLeft((n.getRoot()));

    REQUIRE(n.getRoot()->val == 2);
    REQUIRE(n.getRoot()->left->val == 1);
    REQUIRE(n.getRoot()->right->val == 3);
  
}

TEST_CASE("RBTree_Manual_Rotate_Right", "[Insert and Rotate R]") {
    RBTree<int> n (6);
    (n.getRoot())->left = std::make_shared<Node<int>>(4,n.getRoot());
    (n.getRoot())->left->left = std::make_shared<Node<int>>(2,n.getRoot()->left);

    n.rotateRight((n.getRoot()));

    REQUIRE(n.getRoot()->val == 4);
    REQUIRE(n.getRoot()->left->val == 2);
    REQUIRE(n.getRoot()->right->val == 6);
  
}

TEST_CASE("RBTree_Manual_Rotate_Right", "[Insert and Rotate L]") {
    RBTree<int> n (6);
    (n.getRoot())->right = std::make_shared<Node<int>>(8,n.getRoot());
    (n.getRoot())->right->right = std::make_shared<Node<int>>(10,n.getRoot()->right);

    n.rotateLeft((n.getRoot()));

    REQUIRE(n.getRoot()->val == 8);
    REQUIRE(n.getRoot()->left->val == 6);
    REQUIRE(n.getRoot()->right->val == 10);
  
}