#pragma once
#include <vector>
#include <iostream>

class Scene
{
    public:
        std::string name;
        std::string action;
        virtual std::string enter();
};

class Death: public Scene
{
    public:
        Death();
        std::string enter();
    private:
        std::vector<std::string> quips;
};

class CentralCorridor: public Scene
{
    public:
        CentralCorridor();
        std::string enter();
};

class LaserWeaponArmory: public Scene
{
    public:
        LaserWeaponArmory();
        std::string enter();
    private:
        int code;
        int guess;
        int guesses;
};

class TheBridge: public Scene
{
    public:
        TheBridge();
        std::string enter();
};

class EscapePod: public Scene
{
    public:
        EscapePod();
        std::string enter();
};

class Finished: public Scene
{
    public:
        Finished();
        std::string enter();
};
