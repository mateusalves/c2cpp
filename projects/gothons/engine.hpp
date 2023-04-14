#pragma once

#include "map.h"
#include "scenes.h"

class Engine
{
    public:
        Engine(Map& map);
        ~Engine();
        Map& getMap(){return eng_map;};
        void play();
    private:
        Map& eng_map; //NOTE: what is the name convention for this situation?
        Scene* current_scene;
        Scene* last_scene;
        std::string next_scene_name;

};

