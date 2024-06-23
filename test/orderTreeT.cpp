#include <catch2/catch_test_macros.hpp>
#include "orderTree.h"
#include "order.h"

TEST_CASE("Order Tree", "[Order Tree Simple Insert]") {
    OrderTree ot;
    ot.addOrder(Order("amazon", 1, 1, 5, 2.14, orderType::buy));

    ot.addOrder(Order("amazon", 1, 2, 10, 2.14, orderType::buy));
    ot.addOrder(Order("amazon", 1, 3, 15, 2.14, orderType::buy));


    auto tree = ot.getTree();


    REQUIRE(tree.getRoot()->val.getValue() == 2.14);

    const auto& ll = tree.getRoot()->val.getList();
    auto it = ll.begin();

    REQUIRE(it->getAmount() == 5);
    std::advance(it,1);
    REQUIRE(it->getAmount() == 10);
    std::advance(it,1);
    REQUIRE(it->getAmount() == 15);

}

TEST_CASE("Order Tree", "[Order Tree Simple Insert Nodes]") {
    OrderTree ot;
    ot.addOrder(Order("amazon", 1, 1, 5, 2.14, orderType::buy));

    ot.addOrder(Order("amazon", 1, 2, 10, 2.14, orderType::buy));
    ot.addOrder(Order("amazon", 1, 3, 15, 2.14, orderType::buy));

    ot.addOrder(Order("amazon", 1, 4, 30, 2.04, orderType::buy));

    ot.addOrder(Order("amazon", 1, 5, 50, 2.34, orderType::buy));



    auto tree = ot.getTree();


    REQUIRE(tree.getRoot()->val.getValue() == 2.14);
    REQUIRE(tree.getRoot()->right->val.getValue() == 2.34);
    REQUIRE(tree.getRoot()->left->val.getValue() == 2.04);

    const auto& ll = tree.getRoot()->val.getList();
    auto it = ll.begin();

    REQUIRE(it->getAmount() == 5);
    std::advance(it,1);
    REQUIRE(it->getAmount() == 10);
    std::advance(it,1);
    REQUIRE(it->getAmount() == 15);

}

TEST_CASE("Order Tree", "[Order Tree Simple Insert Nodes 2]") {
    OrderTree ot;
    ot.addOrder(Order("amazon", 1, 1, 5, 2.14, orderType::buy));

    ot.addOrder(Order("amazon", 1, 2, 10, 2.14, orderType::buy));
    ot.addOrder(Order("amazon", 1, 3, 15, 2.14, orderType::buy));

    ot.addOrder(Order("amazon", 1, 4, 30, 2.04, orderType::buy));

    ot.addOrder(Order("amazon", 1, 5, 50, 2.34, orderType::buy));
    ot.addOrder(Order("amazon", 1, 2, 25, 2.34, orderType::buy));





    auto tree = ot.getTree();


    REQUIRE(tree.getRoot()->val.getValue() == 2.14);
    REQUIRE(tree.getRoot()->right->val.getValue() == 2.34);
    REQUIRE(tree.getRoot()->left->val.getValue() == 2.04);

    const auto& ll = tree.getRoot()->val.getList();
    auto it = ll.begin();

    REQUIRE(it->getAmount() == 5);
    std::advance(it,1);
    REQUIRE(it->getAmount() == 10);
    std::advance(it,1);
    REQUIRE(it->getAmount() == 15);

    const auto& ll2 = tree.getRoot()->right->val.getList();
    auto it2 = ll2.begin();

    REQUIRE(it2->getAmount() == 50);
    std::advance(it2,1);
    REQUIRE(it2->getAmount() == 25);

}

TEST_CASE("Order Tree", "[Order Tree Simple Insert Nodes 3]") {
    OrderTree ot;
    ot.addOrder(Order("amazon", 1, 1, 5, 2.14, orderType::buy));

    ot.addOrder(Order("amazon", 1, 2, 10, 2.14, orderType::buy));
    ot.addOrder(Order("amazon", 1, 3, 15, 2.14, orderType::buy));

    ot.addOrder(Order("amazon", 1, 4, 30, 2.04, orderType::buy));

    ot.addOrder(Order("amazon", 1, 5, 50, 2.34, orderType::buy));
    ot.addOrder(Order("amazon", 1, 2, 25, 2.34, orderType::buy));

    ot.addOrder(Order("amazon", 1, 2, 25, 2.54, orderType::buy));
    ot.addOrder(Order("amazon", 1, 2, 50, 2.54, orderType::buy));
    ot.addOrder(Order("amazon", 1, 2, 25, 2.84, orderType::buy));

    ot.addOrder(Order("amazon", 1, 2, 25, 3.04, orderType::buy));
    ot.addOrder(Order("amazon", 1, 2, 25, 3.44, orderType::buy));

    ot.addOrder(Order("amazon", 1, 2, 25, 3.54, orderType::buy));





    auto tree = ot.getTree();


    REQUIRE(tree.getRoot()->val.getValue() == 2.54);
    REQUIRE(tree.getRoot()->right->val.getValue() == 3.04);
    REQUIRE(tree.getRoot()->left->val.getValue() == 2.14);

    const auto& ll = tree.getRoot()->val.getList();
    auto it = ll.begin();

    REQUIRE(it->getAmount() == 25);
    std::advance(it,1);
    REQUIRE(it->getAmount() == 50);


}