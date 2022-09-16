#include "commodity.hpp"
#include <string>

const double sales_tax_percent = 25;

Commodity::Commodity(std::string name_, int id_, double price_) : name(name_), id(id_), price(price_) {}

std::string Commodity::get_name() {
    return name;
}

int Commodity::get_id() {
    return id;
}

double Commodity::get_price() {
    return price;
}

double Commodity::get_price(double amount) {
    return price * amount;
}

void Commodity::set_price(double price_) {
    price = price_;
};

double Commodity::get_price_with_sales_tax(double amount) {
    return price * (1 + sales_tax_percent/100) * amount;
}

