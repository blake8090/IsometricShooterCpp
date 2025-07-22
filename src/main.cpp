#include <fmt/core.h>
#include <iostream>
#include <raylib.h>
#include "engine.h"

using namespace std;

int main() {
    Engine engine("Isometric Shooter");
    
    engine.start();
    
    while (engine.is_running()) {
        engine.update();
    }

    engine.shutdown();
}
