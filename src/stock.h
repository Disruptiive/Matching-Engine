#pragma once

#include <iostream>
#include <string>
#include <utility>
#include "orderTree.h"
#include "order.h"

class Stock{
private:
    std::string stock_n{};
    std::string stock_ticker{};
    OrderTree buyTree{};
    OrderTree sellTree{};


public:
    Stock(std::string stock_name, std::string ticker):stock_n(std::move(stock_name)), stock_ticker(std::move(ticker))
    {}

    void addOrder(Order order, const orderType ot) {

        if (ot == orderType::buy) addBuy (std::move(order));
        else                      addSell(std::move(order));
    }

    void addBuy(Order order) {
        while(sellTree.getTree().getRoot() && order.getAmount() >= sellTree.getTree().max()->val.getAmount() && order.getPrice() <= sellTree.getMax()) {
            order.decreaseAmount(sellTree.getTree().max()->val.getAmount());
            sellTree.deleteOrderNode(sellTree.getMax());
        }

        if (order.getAmount() > 0 && sellTree.getTree().getRoot() && order.getPrice() <= sellTree.getMax()) {
            sellTree.getTree().max()->val.remove(order.getAmount());
        }
        else {
            buyTree.addOrder(order);
        }


    }

    void addSell(Order order) {
        while(buyTree.getTree().getRoot() && order.getAmount() >= buyTree.getTree().min()->val.getAmount() && order.getPrice() >= buyTree.getMin()) {
            order.decreaseAmount(buyTree.getTree().min()->val.getAmount());
            buyTree.deleteOrderNode(buyTree.getMin());
        }

        if (order.getAmount() > 0 && buyTree.getTree().getRoot() && order.getPrice() >= buyTree.getMin()) {
            buyTree.getTree().min()->val.remove(order.getAmount());
        }
        else {
            sellTree.addOrder(order);
        }

    }

    RBTree<OrderTreeNode,double> getBuyTree(){
        return buyTree.getTree();
    }

    RBTree<OrderTreeNode,double> getSellTree(){
        return sellTree.getTree();
    }
};