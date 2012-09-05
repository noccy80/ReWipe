#include "../framework.h"

void WorldObject::setPosition(double x, double y, double z) {
	this->px = x;
	this->py = y;
	this->pz = z;
}

void WorldObject::setRotation(float x, float y, float z) {
	this->rx = x;
	this->ry = y;
	this->rz = z;
}

void MobileObject::setVelocity(float x, float y, float z) {
	this->vx = x;
	this->vy = y;
	this->vz = z;
}

void MobileObject::setSpin(float x, float y, float z) {
	this->sx = x;
	this->sy = y;
	this->sz = z;
}
