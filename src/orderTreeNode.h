#pragma once

#include <list>
#include <memory>
#include "order.h"

class OrderTreeNode{
private:
    std::list<std::unique_ptr<Order>> ll;
    double value;
public:
    explicit OrderTreeNode(const double val) :  value(val)
    {}

    explicit OrderTreeNode(std::unique_ptr<Order> ord) : value(ord->getPrice())
    {
        insert(std::move(ord));
    }

    void insert(std::unique_ptr<Order> ord){
        ll.push_back(std::move(ord));
    }

    void remove(int amount){
        while (ll.front()->getAmount() <= amount){
            amount -= ll.front()->getAmount();
            ll.pop_front();
        }
        ll.front()->decreaseAmount(amount);
    }

     [[nodiscard]] const std::list<std::unique_ptr<Order>>& getList() const{
        return ll;
    }
};