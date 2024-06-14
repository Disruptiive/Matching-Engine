#include <catch2/catch_test_macros.hpp>
#include "rbtree.h"

TEST_CASE("RBTree_Remove", "[Remove No black leaves 1]") {
    RBTree<int> n (3);
    n.insert(2);
    n.insert(5);

    n.deleteNode(5);

    REQUIRE(n.getRoot()->val == 3);
    REQUIRE(n.getRoot()->left->val == 2);
    REQUIRE(n.getRoot()->right == nullptr);
}

TEST_CASE("RBTree_Remove", "[Remove No black leaves 2]") {
    RBTree<int> n (3);
    n.insert(2);
    n.insert(5);
    n.insert(4);
    n.insert(6);

    n.deleteNode(5);

    REQUIRE(n.getRoot()->val == 3);
    REQUIRE(n.getRoot()->left->val == 2);
    REQUIRE(n.getRoot()->right->val == 6);
    REQUIRE(n.getRoot()->right->left->val == 4);
}

TEST_CASE("RBTree_Remove", "[Remove No black leaves 3]") {
    RBTree<int> n (3);
    n.insert(2);
    n.insert(5);
    n.insert(4);

    n.deleteNode(5);

    REQUIRE(n.getRoot()->val == 3);
    REQUIRE(n.getRoot()->left->val == 2);
    REQUIRE(n.getRoot()->right->val == 4);
}

TEST_CASE("RBTree_Remove", "[Remove black leaves 1]") {
    RBTree<int> n (5);
    n.insert(2);
    n.insert(8);
    n.insert(10);

    n.deleteNode(2);

    REQUIRE(n.getRoot()->val == 8);
    REQUIRE(n.getRoot()->left->val == 5);
    REQUIRE(n.getRoot()->right->val == 10);
}

TEST_CASE("RBTree_Remove", "[Remove black leaves 2]") {
    RBTree<int> n (5);
    n.insert(2);
    n.insert(8);
    n.insert(10);

    n.deleteNode(2);

    n.insert(35);
    n.insert(24);

    n.deleteNode(5);

    REQUIRE(n.getRoot()->val == 24);
    REQUIRE(n.getRoot()->left->val == 8);
    REQUIRE(n.getRoot()->left->c == Color::black);
    REQUIRE(n.getRoot()->left->right->val == 10);
    REQUIRE(n.getRoot()->left->right->c == Color::red);
    REQUIRE(n.getRoot()->right->val == 35);
    REQUIRE(n.getRoot()->right->c == Color::black);
}

TEST_CASE("RBTree_Remove", "[Remove black leaves 3]") {
    RBTree<int> n (100);
    n.insert(50);
    n.insert(150);

    n.deleteNode(100);

    REQUIRE(n.getRoot()->val == 150);
    REQUIRE(n.getRoot()->left->val == 50);
    REQUIRE(n.getRoot()->left->c == Color::red);

}


TEST_CASE("RBTree_Remove", "[Remove black leaves 4]") {
    RBTree<int> n (100);
    n.insert(50);
    n.insert(150);

    n.deleteNode(100);

    n.insert(200);
    n.insert(160);
    n.insert(80);
    n.insert(60);
    n.insert(190);

    n.deleteNode(160);

    REQUIRE(n.getRoot()->val == 150);
    REQUIRE(n.getRoot()->left->val == 60);
    REQUIRE(n.getRoot()->left->c == Color::black);

    REQUIRE(n.getRoot()->right->val == 190);
    REQUIRE(n.getRoot()->right->c == Color::black);

    REQUIRE(n.getRoot()->right->right->val == 200);
    REQUIRE(n.getRoot()->right->right->c == Color::red);
}


TEST_CASE("RBTree_Remove", "[Remove black leaves 5]") {
    RBTree<int> n (100);
    n.insert(50);
    n.insert(150);

    n.deleteNode(100);

    n.insert(200);
    n.insert(160);
    n.insert(80);
    n.insert(60);
    n.insert(190);

    n.deleteNode(160);

    n.insert(240);

    n.deleteNode(240);

    n.insert(160);
    n.insert(170);

    n.deleteNode(200);
    n.deleteNode(160);
    REQUIRE(n.getRoot()->val == 150);
    REQUIRE(n.getRoot()->left->val == 60);
    REQUIRE(n.getRoot()->left->c == Color::black);

    REQUIRE(n.getRoot()->right->val == 170);
    REQUIRE(n.getRoot()->right->c == Color::black);

    REQUIRE(n.getRoot()->right->right->val == 190);
    REQUIRE(n.getRoot()->right->right->c == Color::red);

}

TEST_CASE("RBTree_Remove", "[Remove black leaves 6]") {
    RBTree<int> n (100);
    n.insert(50);
    n.insert(150);

    n.deleteNode(100);

    n.insert(200);
    n.insert(160);
    n.insert(80);
    n.insert(60);
    n.insert(190);

    n.deleteNode(160);

    n.insert(240);

    n.deleteNode(240);

    n.insert(160);
    n.insert(170);

    n.deleteNode(200);
    n.deleteNode(160);

    n.insert(200);
    n.insert(300);
    n.insert(195);

    n.deleteNode(170);
    REQUIRE(n.getRoot()->val == 150);
    REQUIRE(n.getRoot()->left->val == 60);
    REQUIRE(n.getRoot()->left->c == Color::black);

    REQUIRE(n.getRoot()->right->val == 200);
    REQUIRE(n.getRoot()->right->c == Color::red);

    REQUIRE(n.getRoot()->right->right->val == 300);
    REQUIRE(n.getRoot()->right->right->c == Color::black);

    REQUIRE(n.getRoot()->right->left->val == 190);
    REQUIRE(n.getRoot()->right->left->c == Color::black);

    REQUIRE(n.getRoot()->right->left->right->val == 195);
    REQUIRE(n.getRoot()->right->left->right->c == Color::red);

}

TEST_CASE("RBTree_Remove", "[Remove black leaves 7]") {
    RBTree<int> n (100);
    n.insert(50);
    n.insert(150);

    n.deleteNode(100);

    n.insert(200);
    n.insert(160);
    n.insert(80);
    n.insert(60);
    n.insert(190);

    n.deleteNode(160);

    n.insert(240);

    n.deleteNode(240);

    n.insert(160);
    n.insert(170);

    n.deleteNode(200);
    n.deleteNode(160);

    n.insert(200);
    n.insert(300);
    n.insert(195);

    n.deleteNode(170);

    n.insert(197);
    n.insert(198);
    REQUIRE(n.getRoot()->val == 195);
    REQUIRE(n.getRoot()->left->val == 150);
    REQUIRE(n.getRoot()->left->c == Color::red);

    REQUIRE(n.getRoot()->right->val == 200);
    REQUIRE(n.getRoot()->right->c == Color::red);

    REQUIRE(n.getRoot()->left->right->val == 190);
    REQUIRE(n.getRoot()->left->right->c == Color::black);

    REQUIRE(n.getRoot()->left->left->val == 60);
    REQUIRE(n.getRoot()->left->left->c == Color::black);

    REQUIRE(n.getRoot()->left->left->left->val == 50);
    REQUIRE(n.getRoot()->left->left->left->c == Color::red);

    REQUIRE(n.getRoot()->left->left->right->val == 80);
    REQUIRE(n.getRoot()->left->left->right->c == Color::red);

}

TEST_CASE("RBTree_Remove", "[Remove black leaves 8]") {
    RBTree<int> n (100);
    n.insert(50);
    n.insert(150);

    n.deleteNode(100);

    n.insert(200);
    n.insert(160);
    n.insert(80);
    n.insert(60);
    n.insert(190);

    n.deleteNode(160);

    n.insert(240);

    n.deleteNode(240);

    n.insert(160);
    n.insert(170);

    n.deleteNode(200);
    n.deleteNode(160);

    n.insert(200);
    n.insert(300);
    n.insert(195);

    n.deleteNode(170);

    n.insert(197);
    n.insert(198);

    n.insert(40);
    n.insert(55);

    n.deleteNode(190);


    REQUIRE(n.getRoot()->val == 195);

    REQUIRE(n.getRoot()->left->val == 60);
    REQUIRE(n.getRoot()->left->c == Color::black);

    REQUIRE(n.getRoot()->right->val == 200);
    REQUIRE(n.getRoot()->right->c == Color::black);

    REQUIRE(n.getRoot()->left->right->val == 150);
    REQUIRE(n.getRoot()->left->right->c == Color::black);

    REQUIRE(n.getRoot()->left->right->left->val == 80);
    REQUIRE(n.getRoot()->left->right->left->c == Color::red);

    REQUIRE(n.getRoot()->left->left->val == 50);
    REQUIRE(n.getRoot()->left->left->c == Color::black);

    REQUIRE(n.getRoot()->left->left->left->val == 40);
    REQUIRE(n.getRoot()->left->left->left->c == Color::red);

    REQUIRE(n.getRoot()->left->left->right->val == 55);
    REQUIRE(n.getRoot()->left->left->right->c == Color::red);

}

TEST_CASE("RBTree_Remove", "[Remove black leaves 9]") {
    RBTree<int> n (100);
    n.insert(50);
    n.insert(150);

    n.deleteNode(100);

    n.insert(200);
    n.insert(160);
    n.insert(80);
    n.insert(60);
    n.insert(190);

    n.deleteNode(160);

    n.insert(240);

    n.deleteNode(240);

    n.insert(160);
    n.insert(170);

    n.deleteNode(200);
    n.deleteNode(160);

    n.insert(200);
    n.insert(300);
    n.insert(195);

    n.deleteNode(170);

    n.insert(197);
    n.insert(198);

    n.insert(40);
    n.insert(55);

    n.deleteNode(190);

    n.deleteNode(300);

    REQUIRE(n.getRoot()->val == 195);

    REQUIRE(n.getRoot()->left->val == 60);
    REQUIRE(n.getRoot()->left->c == Color::black);

    REQUIRE(n.getRoot()->right->val == 198);
    REQUIRE(n.getRoot()->right->c == Color::black);

    REQUIRE(n.getRoot()->right->left->val == 197);
    REQUIRE(n.getRoot()->right->left->c == Color::black);

    REQUIRE(n.getRoot()->right->right->val == 200);
    REQUIRE(n.getRoot()->right->right->c == Color::black);

    REQUIRE(n.getRoot()->left->right->val == 150);
    REQUIRE(n.getRoot()->left->right->c == Color::black);

    REQUIRE(n.getRoot()->left->right->left->val == 80);
    REQUIRE(n.getRoot()->left->right->left->c == Color::red);

    REQUIRE(n.getRoot()->left->left->val == 50);
    REQUIRE(n.getRoot()->left->left->c == Color::black);

    REQUIRE(n.getRoot()->left->left->left->val == 40);
    REQUIRE(n.getRoot()->left->left->left->c == Color::red);

    REQUIRE(n.getRoot()->left->left->right->val == 55);
    REQUIRE(n.getRoot()->left->left->right->c == Color::red);

}

TEST_CASE("RBTree_Remove", "[Remove black leaves 10]") {
    RBTree<int> n (100);
    n.insert(50);
    n.insert(150);

    n.deleteNode(100);

    n.insert(200);
    n.insert(160);
    n.insert(80);
    n.insert(60);
    n.insert(190);

    n.deleteNode(160);

    n.insert(240);

    n.deleteNode(240);

    n.insert(160);
    n.insert(170);

    n.deleteNode(200);
    n.deleteNode(160);

    n.insert(200);
    n.insert(300);
    n.insert(195);

    n.deleteNode(170);

    n.insert(197);
    n.insert(198);

    n.insert(40);
    n.insert(55);

    n.deleteNode(190);

    n.deleteNode(300);

    n.deleteNode(200);

    REQUIRE(n.getRoot()->val == 195);

    REQUIRE(n.getRoot()->left->val == 60);
    REQUIRE(n.getRoot()->left->c == Color::red);

    REQUIRE(n.getRoot()->right->val == 198);
    REQUIRE(n.getRoot()->right->c == Color::black);

    REQUIRE(n.getRoot()->right->left->val == 197);
    REQUIRE(n.getRoot()->right->left->c == Color::red);

    REQUIRE(n.getRoot()->left->right->val == 150);
    REQUIRE(n.getRoot()->left->right->c == Color::black);

    REQUIRE(n.getRoot()->left->right->left->val == 80);
    REQUIRE(n.getRoot()->left->right->left->c == Color::red);

    REQUIRE(n.getRoot()->left->left->val == 50);
    REQUIRE(n.getRoot()->left->left->c == Color::black);

    REQUIRE(n.getRoot()->left->left->left->val == 40);
    REQUIRE(n.getRoot()->left->left->left->c == Color::red);

    REQUIRE(n.getRoot()->left->left->right->val == 55);
    REQUIRE(n.getRoot()->left->left->right->c == Color::red);

}

TEST_CASE("RBTree_Remove", "[Remove black leaves 11]") {
    RBTree<int> n (100);
    n.insert(50);
    n.insert(150);

    n.deleteNode(100);

    n.insert(200);
    n.insert(160);
    n.insert(80);
    n.insert(60);
    n.insert(190);

    n.deleteNode(160);

    n.insert(240);

    n.deleteNode(240);

    n.insert(160);
    n.insert(170);

    n.deleteNode(200);
    n.deleteNode(160);

    n.insert(200);
    n.insert(300);
    n.insert(195);

    n.deleteNode(170);

    n.insert(197);
    n.insert(198);

    n.insert(40);
    n.insert(55);

    n.deleteNode(190);

    n.deleteNode(300);

    n.deleteNode(200);

    n.deleteNode(198);
    n.deleteNode(197);

    REQUIRE(n.getRoot()->val == 60);

    REQUIRE(n.getRoot()->left->val == 50);
    REQUIRE(n.getRoot()->left->c == Color::black);

    REQUIRE(n.getRoot()->right->val == 150);
    REQUIRE(n.getRoot()->right->c == Color::red);

    REQUIRE(n.getRoot()->right->left->val == 80);
    REQUIRE(n.getRoot()->right->left->c == Color::black);

    REQUIRE(n.getRoot()->right->right->val == 195);
    REQUIRE(n.getRoot()->right->right->c == Color::black);

    REQUIRE(n.getRoot()->left->right->val == 55);
    REQUIRE(n.getRoot()->left->right->c == Color::red);

    REQUIRE(n.getRoot()->left->left->val == 40);
    REQUIRE(n.getRoot()->left->left->c == Color::red);


}

TEST_CASE("RBTree_Remove", "[Remove black leaves 12]") {
    RBTree<int> n (100);
    n.insert(50);
    n.insert(150);

    n.deleteNode(100);

    n.insert(200);
    n.insert(160);
    n.insert(80);
    n.insert(60);
    n.insert(190);

    n.deleteNode(160);

    n.insert(240);

    n.deleteNode(240);

    n.insert(160);
    n.insert(170);

    n.deleteNode(200);
    n.deleteNode(160);

    n.insert(200);
    n.insert(300);
    n.insert(195);

    n.deleteNode(170);

    n.insert(197);
    n.insert(198);

    n.insert(40);
    n.insert(55);

    n.deleteNode(190);

    n.deleteNode(300);

    n.deleteNode(200);

    n.deleteNode(198);
    n.deleteNode(197);
    n.deleteNode(80);
    n.deleteNode(150);
    REQUIRE(n.getRoot()->val == 60);

    REQUIRE(n.getRoot()->left->val == 50);
    REQUIRE(n.getRoot()->left->c == Color::black);

    REQUIRE(n.getRoot()->right->val == 195);
    REQUIRE(n.getRoot()->right->c == Color::black);

    REQUIRE(n.getRoot()->left->right->val == 55);
    REQUIRE(n.getRoot()->left->right->c == Color::red);

    REQUIRE(n.getRoot()->left->left->val == 40);
    REQUIRE(n.getRoot()->left->left->c == Color::red);


}