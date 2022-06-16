#pragma once
#include <vector>
#include <iostream>

class Scene
{
    public:
        std::string name;
        std::string action;
        //virtual std::string enter() = 0;
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
        std::string enter() override;
};

class LaserWeaponArmory: public Scene
{
    public:
        LaserWeaponArmory();
        std::string enter() override;
    private:
        int code;
        int guess;
        int guesses;
};

class TheBridge: public Scene
{
    public:
        TheBridge();
        std::string enter() override;
};

class EscapePod: public Scene
{
    public:
        EscapePod();
        std::string enter() override;

    private:
        int good_pod;
        int guess;
};

class Finished: public Scene
{
    public:
        Finished();
        std::string enter() override;
};
