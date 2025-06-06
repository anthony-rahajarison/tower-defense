#include "MainMenu.hpp"

int main() {
    try {
        Menu menu;
        menu.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
