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