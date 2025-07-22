#include "engine.h"
#include "state.h"
#include "mainmenu.h"

#include <fmt/core.h>
#include <iostream>
#include <raylib.h>

using namespace std;

int main() {
    Engine engine("Isometric Shooter");
    engine.set_state(new MainMenuState(engine));
    engine.start();
    
    while (engine.is_running()) {
        engine.update();
    }

    engine.shutdown();
}
