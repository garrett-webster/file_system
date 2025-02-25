#include "Drive.h"

#include "ContainerEntity.h"

// Constructor definition
Drive::Drive(const string& name) : ContainerEntity(name) {}

bool Drive::hasChildWithName(string name) {
    for (auto & child : children) {
        if (child->getName() == name) {
            return true;
        }
    }
    return false;
}

// I might not need this method. If I update size each time a child is added or deleted, that should work. Might delete later
size_t Drive::calculateSize() {
    size_t size = 0;

    for (auto & child : children) {
        size += child->getSize();
    }

    return size;
}