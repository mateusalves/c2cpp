#include <iostream>
#include "engine.h"

Engine::Engine(Map map): eng_map(map)
{
    std::cout << "Engine constructor" << std::endl;
}

void Engine::play()
{
    std::cout << "Engine play" << std::endl;
    current_scene = eng_map.opening_scene();
    last_scene = eng_map.next_scene("finished");

    while(current_scene.name != last_scene.name)
    {
        next_scene_name = current_scene.enter();
        current_scene = eng_map.next_scene(next_scene_name);
    }

    //To print out last scene
    current_scene.enter();
}

Engine::~Engine()
{

}
