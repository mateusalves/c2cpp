#include <string>
#include "scenes.h"

std::string Scene::enter()
{
    //NOTE: is virtual function a way to force using the derived class implementation, right?
    std::cout << "This scene is not yet configured." << std::endl;
    std::cout << "Subclass it and implement enter()." << std::endl;
    exit(1);
}

Death::Death()
{
    name = "death";
    quips.push_back("You died. You kinda suck at this.");
    quips.push_back("Your Mom would be proud... if she were smarter.");
    quips.push_back("Suck a luser.");
    quips.push_back("I have a small puppy that's better at this.");
    quips.push_back("You're worse than your Dad's jokes.");
}

std::string Death::enter()
{
    std::cout << quips[rand()%quips.size()] << std::endl;;
    exit(1);
    return "not really returning it";
}

CentralCorridor::CentralCorridor()
{
    name = "central_corridor";
}

std::string CentralCorridor::enter()
{
    std::cout << "The Gothons of Planet Percal #25 have invaded your ship and" << std::endl;
    std::cout << "destroyed your entire crew. You are the last surviving" << std::endl;
    std::cout << "member and your last mission is to get the neutron destruct" << std::endl;
    std::cout << "bomb from the Weapons Armory, put it in the bridge, and" << std::endl;
    std::cout << "blow the ship up after getting into an escape pod.\n" << std::endl;
    std::cout << "You're running down the central corridor to the Weapons" << std::endl;
    std::cout << "Armory when a Gothon jumps out, red scaly skin, dark grimy" << std::endl;
    std::cout << "teeth, and evil clown costume flowing around his hate" << std::endl;
    std::cout << "filled body. He's blocking the door to the Armory and" << std::endl;
    std::cout << "about to pull a weapon to blast you." << std::endl;

    std::cin >> action;

    if(action == "shoot!")
    {
        std::cout << "Quick on the draw you yank out your blaster and fire" << std::endl;
        std::cout << "it at the Gothon. His clown costume is flowing and" << std::endl;
        std::cout << "moving around his body, which throws off you aim." << std::endl;
        std::cout << "Your laser hits his costume but misses him entirely." << std::endl;
        std::cout << "This completely ruins his brand new costume his mother" << std::endl;
        std::cout << "bought him, which makes him fly into an insange rage" << std::endl;
        std::cout << "and blast you repeatedly in the face until you are" << std::endl;
        std::cout << "dead. Then he eats you." << std::endl;
        return "death";
    }
    else if(action == "dodge!")
    {
        std::cout << "Like a world class boxer you dodge, weave, slip and" << std::endl;
        std::cout << "slide right as the Gothon's blaster cranks a laser" << std::endl;
        std::cout << "past your head. In the middle of your artful dodge" << std::endl;
        std::cout << "your foot slips and you bang your head on the metal" << std::endl;
        std::cout << "wall and pass out. You wake up shortly after only to" << std::endl;
        std::cout << "die as the Gothon stomps on your head and eats you." << std::endl;
        return "death";
    }
    else if(action == "tell a joke")
    {
        std::cout << "Lucky for you they made you learn Gothon insults in" << std::endl;
        std::cout << "the academy. You tell the one Gothon joke you know." << std::endl;
        std::cout << "Lbhe zbgure vf fb sng, jura fur fvgf nebhaq gur ubhfr," << std::endl;
        std::cout << "fur fvgf nebhaq gur ubhfr. The Gothon stops, tries" << std::endl;
        std::cout << "not to laugh, then busts out laughing and can't move." << std::endl;
        std::cout << "While he's laughing you run up and shoot him square in" << std::endl;
        std::cout << "the head putting him down, them jump through the" << std::endl;
        std::cout << "Weapon Armory door." << std::endl;
        return "laser_weapon_armory";
    }
    else
    {
        std::cout << "DOES NOT COMPUTE!" << std::endl;
        return "central_corridor";
    }
}

LaserWeaponArmory::LaserWeaponArmory()
{
    name = "laser_weapon_armory";
}

std::string LaserWeaponArmory::enter()
{
    std::cout << "You do a diver roll into the Weapon Armory, crouch and scan" << std::endl;
    std::cout << "the room for more Gothons that might be hiding. It's dead" << std::endl;
    std::cout << "quiet, too quiet. You stand up and run to the far side of" << std::endl;
    std::cout << "the room and find the neutron bomb in its container." << std::endl;
    std::cout << "There's a keypad lock on the box and you need the code to" << std::endl;
    std::cout << "get the bomb out. If you get the code wrong 10 times then" << std::endl;
    std::cout << "the lock closes forever and you can't get the bomb." << std::endl;
    std::cout << "the code is 3 digits." << std::endl;

    code = 123; //not really random
    std::cout << "[keypad]> ";
    std::cin >> guess;

    while(guess != code && guesses < 10)
    {
        std::cout << "BZZZZZEDDD!" << std::endl;
        guesses++;
        std::cout << "[keypad]> ";
        std::cin >> guess;
    }

    if(guess == code)
    {
        std::cout << "" << std::endl;
        return "central_corridor";
    }
    else
    {

    }
}

TheBridge::TheBridge()
{
    name = "the_bridge";
}

std::string TheBridge::enter()
{
    return "hahaha";
}

EscapePod::EscapePod()
{
    name = "escape_pod";
}

std::string EscapePod::enter()
{
    return "hahaha";
}

Finished::Finished()
{
    name = "finished";
}

std::string Finished::enter()
{
    return "hahaha";
}
