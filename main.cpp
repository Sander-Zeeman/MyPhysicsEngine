#include "Model/World.h"
#include "View/Screen.h"
#include "Controller/Brain.h"

int main(int argc, char *argv[]) {
    (void) argc;
    (void) argv;
    
    World *world = new World();
    Screen *screen = new Screen("My Physics Engine", 1080, 720);
    Brain *brain = new Brain(world, screen);

    screen->setWorld(world);
    brain->start();

    delete world;
    delete screen;
    delete brain;
    return 0;
}