#pragma once

#include <list>
#include <compare>
#include <optional>
#include "order.h"

class OrderTreeNode{
private:
    std::list<Order> ll;
    double value{};
    int curr_amount{};
public:
    explicit OrderTreeNode(const double val) :  value(val)
    {}

    explicit OrderTreeNode(const Order& ord) : value(ord.getPrice())
    {
        insert(ord);
    }

    void insert(Order ord){
        curr_amount += ord.getAmount();
        ll.push_back(std::move(ord));
    }

    std::optional<int> remove(int amount){
        while (!ll.empty() && ll.front().getAmount() <= amount) {
            curr_amount -= ll.front().getAmount();
            amount -= ll.front().getAmount();
            ll.pop_front();
        }
        if (ll.empty() && amount > 0) {
            curr_amount = 0;
            return amount;
        }
        else if (!ll.empty() && ll.front().getAmount() > amount) {
            curr_amount -= amount;
            ll.front().decreaseAmount(amount);
            return {};
        }
        else {
            return {};
        }
    }

     [[nodiscard]] const std::list<Order>& getList() const{
        return ll;
    }

    [[nodiscard]] int getAmount() const {
        return curr_amount;
    }

    auto operator<=>(const OrderTreeNode& rhs) const {
        return value <=> rhs.value;
    }

    bool operator==(const OrderTreeNode& rhs) const {
        return value == rhs.value;
    }

    auto operator<=>(double rhs) const {
        return value <=> rhs;
    }

    bool operator==(double rhs) const {
        return value == rhs;
    }

    [[nodiscard]] double getValue() const {
        return value;
    }
};