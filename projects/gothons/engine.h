#pragma once

#include "map.h"
#include "scenes.h"

class Engine
{
    public:
        Engine(Map map);
        Map getMap(){return eng_map;};
        void play();
        ~Engine();
    private:
        Map eng_map; //NOTE: what is the name convention for this situation?
        Scene current_scene, last_scene;
        std::string next_scene_name;

};

