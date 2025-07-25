#include "engine/engine.h"
#include "engine/state.h"
#include "game/mainmenu.h"

using namespace std;

int main() {
    Engine engine;
    engine.start("Isometric Shooter");
    engine.set_state(new MainMenuState(engine));

    while (engine.running()) {
        engine.update();
    }

    engine.shutdown();
}
