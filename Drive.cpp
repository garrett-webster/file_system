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

void Drive::setPath(string &path) {
    // A pretty clunky way to check if the current object is a Drive (and thus cannot have its path changed)
    if (this->path != "/" + this->name) {
        // Maybe throw an error here instead? Honestly, this bit just needs some reworking
        this->path = path + "/" + this->name;
    }

    // Recursively update the paths of the children
    for (auto& child : children) {
        child->setPath(this->path);
    }
}

// I might not need this method. If I update size each time a child is added or deleted, that should work. Might delete later
size_t Drive::calculateSize() {
    size_t size = 0;

    for (auto & child : children) {
        size += child->getSize();
    }

    return size;
}