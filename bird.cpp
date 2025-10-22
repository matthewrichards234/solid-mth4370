#include <iostream>

// FlyBehavior defines the "fly" behavior for a bird as an abstract interface.
// CanFly and CannotFly are concrete, specifying whether a bird can fly or not.
class FlyBehavior {
public:
    virtual void fly() = 0;
    virtual ~FlyBehavior() = default;
};

class CanFly : public FlyBehavior {
public:
    void fly() override { std::cout << "Flying\n"; }
};

class CannotFly : public FlyBehavior {
public:
    void fly() override { std::cout << "Can't fly\n"; }
};

class Bird {
public:
    // virtual void fly() {
    //     std::cout << "Bird is flying\n";
    // };
    
    virtual void lay_egg() {
        std::cout << "Egg";
    }
};

class Ostrich : public Bird {
public:
    void fly() override {
        throw std::runtime_error("Ostriches can't fly!");
    }
};

class Eagle: public Bird {};

// For demonstration
int main() {
    Eagle eagle;
    Ostrich ostrich;
    
    eagle.lay_egg();
    eagle.fly();

    ostrich.lay_egg();
    ostrich.fly();
}

