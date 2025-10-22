#include <iostream>

// Interface for input devices
class IInputDevice {
public:
    virtual std::string getInput() = 0;
    virtual ~IInputDevice() = default;
};

class Keyboard : public IInputDevice {
public:
    std::string getInput() override {
        return "User input from keyboard";
    }
};

class Mouse : public IInputDevice {
public:
    std::string getInput() override {
        return "User input from mouse";
    }
};

// Right now this code assumes that input will come from the keyboard, 
// but we would like to be able to create an InputProcessor that 
// accepts input from the mouse (and potentially other input devices
// in the future). Note that each InputProcessor only needs to deal
// with one device.
class InputProcessor {
public:
  IInputDevice& device;
public:
    void processInput() {
        device device;
        std::string input = device.getInput();
        std::cout << "Processing: " << input;
    }
};

// For demonstration
int main() {
    Keyboard keyboard;
    Mouse mouse;
}
