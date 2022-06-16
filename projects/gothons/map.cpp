#include <iostream>
#include "map.h"

Map::Map(std::string start_scene): map_start_scene(start_scene)
{
    std::cout << "Map: " << start_scene << std::endl;
    scenes.insert(std::pair<std::string, Scene*>("central_corridor", new CentralCorridor()));
    scenes.insert(std::pair<std::string, Scene*>("laser_weapon_armory", new LaserWeaponArmory()));
    scenes.insert(std::pair<std::string, Scene*>("the_bridge", new TheBridge()));
    scenes.insert(std::pair<std::string, Scene*>("escape_pod", new EscapePod()));
    scenes.insert(std::pair<std::string, Scene*>("death", new Death()));
    scenes.insert(std::pair<std::string, Scene*>("finished", new Finished()));
}

Map::~Map()
{
    for(auto& scene : scenes)
    {
        if(scene.second != nullptr)
        {
            delete scene.second;
        }
    }
}

Scene* Map::next_scene(std::string scene_name)
{
    std::cout << "Map next_scene: " << scene_name << std::endl;
    return scenes[scene_name];
}

Scene* Map::opening_scene()
{
    std::cout << "Map opening_scene" << std::endl;
    return next_scene(map_start_scene);
}

