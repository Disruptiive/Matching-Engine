#include <catch2/catch_test_macros.hpp>

#include "orderTreeNode.h"
#include "order.h"

TEST_CASE("Linked List Check", "[Linked List Init]") {
    OrderTreeNode ot {2.14};
    ot.insert(std::make_unique<Order>("amazon", 1, 1, 5, 2.14, orderType::buy));
    ot.insert(std::make_unique<Order>("amazon", 2, 15, 10, 2.14, orderType::buy));
    ot.insert(std::make_unique<Order>("amazon", 3, 20, 100, 2.14, orderType::buy));


    const auto& ll = ot.getList();

    auto it = ll.begin();

    REQUIRE(it->get()->getAmount() == 5);
    std::advance(it,1);
    REQUIRE(it->get()->getAmount() == 10);
    std::advance(it,1);
    REQUIRE(it->get()->getAmount() == 100);
}

TEST_CASE("Linked List Check", "[Linked List Remove]") {
    OrderTreeNode ot {2.14};
    ot.insert(std::make_unique<Order>("amazon", 1, 1, 5, 2.14, orderType::buy));
    ot.insert(std::make_unique<Order>("amazon", 2, 15, 10, 2.14, orderType::buy));
    ot.insert(std::make_unique<Order>("amazon", 3, 20, 100, 2.14, orderType::buy));

    ot.remove(15);
    const auto& ll = ot.getList();

    const auto it = ll.begin();

    REQUIRE(it->get()->getAmount() == 100);
}

TEST_CASE("Linked List Check", "[Linked List Remove 2]") {
    OrderTreeNode ot {2.14};
    ot.insert(std::make_unique<Order>("amazon", 1, 1, 5, 2.14, orderType::buy));
    ot.insert(std::make_unique<Order>("amazon", 2, 15, 10, 2.14, orderType::buy));
    ot.insert(std::make_unique<Order>("amazon", 3, 20, 100, 2.14, orderType::buy));

    ot.remove(17);
    const auto& ll = ot.getList();

    const auto it = ll.begin();
    REQUIRE(it->get()->getAmount() == 98);
}
