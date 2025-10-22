#include <string>
#include <iostream>

class DiscountCalculator {
public:
    double calculate(DiscountPrice discount, double amount) {
        return discount.getDiscountedPrice(amount);
    }
};

class DiscountPrice {
public:
    virtual double getDiscountedPrice(double amount) = 0;
    virtual ~DiscountPrice() = default;
};

// Concrete discounts
class LoyalDiscount : public DiscountPrice {
public:
    double getDiscountedPrice(double amount) override { return amount * 0.95; }
};

class VIPDiscount : public DiscountPrice {
public:
    double getDiscountedPrice(double amount) override { return amount * 0.90; }
};

class NoDiscount : public DiscountPrice {
public:
    double getDiscountedPrice(double amount) override { return amount; }
};

// Included for demonstration
int main() {
    double price = 1000;
    DiscountCalculator calc;

    LoyalDiscount loyal;
    VIPDiscount vip;
    NoDiscount other;

    std::cout << "VIP Customer Price: " << calc.calculate(vip, price) << "\n";
    std::cout << "Loyal Customer Price: " << calc.calculate(loyal, price) << "\n";
    std::cout << "Other Customer Price: " << calc.calculate(other, price) << "\n";
}
