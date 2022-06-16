#pragma once
#include <string>
#include <map>
#include "scenes.h"

class Map
{
    public:
        Map(std::string start_scene);
        Scene next_scene(std::string scene_name);
        Scene opening_scene();
        ~Map();
    private:
        std::string map_start_scene;
        std::map<std::string, Scene> scenes;
};
