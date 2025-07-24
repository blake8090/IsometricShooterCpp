#include "engine/engine.h"
#include "engine/state.h"
#include "game/mainmenu.h"

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
