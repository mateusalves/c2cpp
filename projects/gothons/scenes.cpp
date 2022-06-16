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
        std::cout << "The container clicks open and the seal breaks, letting" << std::endl;
        std::cout << "gas out. You grab the neutron bomb and run as fast as" << std::endl;
        std::cout << "you can to the bridge where you must place it in the" << std::endl;
        std::cout << "right spot." << std::endl;
        return "the_bridge";
    }
    else
    {
        std::cout << "The lock buzzes one last time and then you hear a" << std::endl;
        std::cout << "sickening melting sound as the mechanism is fused" << std::endl;
        std::cout << "together. You decide to sit there, and finally the" << std::endl;
        std::cout << "Gothons blow up the ship from their ship and you die." << std::endl;
        return "death";
    }
}

TheBridge::TheBridge()
{
    name = "the_bridge";
}

std::string TheBridge::enter()
{
    std::cout << "You burst onto the Bridge with the netron destruct bomb" << std::endl;
    std::cout << "under your arm and surprise 5 Gothons who are trying to" << std::endl;
    std::cout << "take control of the ship. Each of them has an even uglier" << std::endl;
    std::cout << "clown costume than the last. They haven't pulled their" << std::endl;
    std::cout << "weapons out yet, as they see the active bomb under your" << std::endl;
    std::cout << "arm and don't want to set it off." << std::endl;

    std::cout << "> ";
    std::cin >> action;

    if(action == "throw the bomb")
    {
        std::cout << "In a panic you throw the bomb at the group of Gothons" << std::endl;
        std::cout << "and make a leap for the door. Right as you drop it a" << std::endl;
        std::cout << "Gothon shoots you right in the back killing you. As" << std::endl;
        std::cout << "you die you see another Gothon frantically try to" << std::endl;
        std::cout << "disarm the bomb. You die knowing they will probably" << std::endl;
        std::cout << "blow up when it goes off." << std::endl;
        return "death";
    }
    else if(action == "slowly place the bomb")
    {

        std::cout << "You point your blaster at the bomb under your arm and" << std::endl;
        std::cout << "the Gothons put their hands up and start to sweat." << std::endl;
        std::cout << "You inch backward to the door, open it, and then" << std::endl;
        std::cout << "carefully place the bomb on the floor, pointing your" << std::endl;
        std::cout << "blaster at it. You then jump back through the door," << std::endl;
        std::cout << "punch the close button and blast the lock so the" << std::endl;
        std::cout << "Gothons can't get out. Now that the bomb is placed" << std::endl;
        std::cout << "you run to the escape pod to get off this tin can" << std::endl;
        return "escape_pod";
    }
    else
    {
        std::cout << "DOES NOT COMPUTE!" << std::endl;
        return "the_bridge";
    }
}

EscapePod::EscapePod()
{
    name = "escape_pod";
}

std::string EscapePod::enter()
{

    std::cout << "You rush through the ship desperately trying to make it to" << std::endl;
    std::cout << "the escape pod before the whole ship explodes. It seems" << std::endl;
    std::cout << "like hardly any Gothons are on the ship, so your run is" << std::endl;
    std::cout << "clear of interference. You get to the chamber with the" << std::endl;
    std::cout << "escape pods, and now need to pick one to take. Some of" << std::endl;
    std::cout << "them could be damaged but you don't have time to look." << std::endl;
    std::cout << "There's 5 pods, which one do you take?" << std::endl;

    good_pod = 3; //Not really random
    std::cout << "[pod #]> ";
    std::cin >> guess;

    if (guess != good_pod)
    {
        std::cout << "You jump into pod {guess} and hit the eject button" << std::endl;
        std::cout << "The pod escapes out into the void of space, then" << std::endl;
        std::cout << "implodes as the hull ruptures, crushing your body into" << std::endl;
        std::cout << "jam jelly." << std::endl;
        return "death";
    }
    else
    {
        std::cout << "You jump into pod " << guess << " and hit the eject button." << std::endl;
        std::cout << "The pod easily slides out into space heading to the" << std::endl;
        std::cout << "planet below. As it flies to the planet, you look" << std::endl;
        std::cout << "back and see your ship implode then explode like a" << std::endl;
        std::cout << "bright star, taking out the Gothon ship at the same" << std::endl;
        std::cout << "time. You won!" << std::endl;
        return "finished";
    }
}

Finished::Finished()
{
    name = "finished";
}

std::string Finished::enter()
{
    print("You won! Good job!")
    return "finished";
}
