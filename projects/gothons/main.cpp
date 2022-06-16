#include <iostream>
#include <string>
#include "scenes.h"
#include "engine.h"
#include "map.h"

int main(int argc, char **argv)
{
    Map a_map = Map("central_corridor");
    Engine a_game = Engine(a_map);
    a_game.play();
    return 0;
}
