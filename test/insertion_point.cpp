#include <catch2/catch_test_macros.hpp>
#include "rbtree.h"

TEST_CASE("RBTree_Find_Where_To_Insert", "[Node-FindInsertion_Point]") {
    RBTree<double> n (3.14);
    (n.getRoot())->left = std::make_shared<Node<double>>(2.7,n.getRoot());
    (n.getRoot())->right = std::make_shared<Node<double>>(5.4,n.getRoot());
    (n.getRoot())->left->right = std::make_shared<Node<double>>(3.1,n.getRoot()->left);

    REQUIRE(n.findParent(3.12) == n.getRoot()->left->right );
    REQUIRE(n.findParent(6.1) == n.getRoot()->right );

}
