#pragma once
#include <string>

class Commodity {
private:
    std::string name;
    int id;
    double price;
public:
    Commodity(std::string name_, int id_, double price_);

    std::string get_name();
    int get_id(); 
    double get_price(); 
    double get_price(double amount); 
    void set_price(double price_);
    double get_price_with_sales_tax(double amount);

};
