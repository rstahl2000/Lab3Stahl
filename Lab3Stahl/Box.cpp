/*
 * Box.cpp
 *
 *  Created on: Sep 19, 2019
 *      Author: Robert Stahl and Chris Tiso
 */

#include "Box.hpp"
Box::Box(double l, double b, double h)
{
 length = l;
 breadth = b;
 height = h;
}
double Box::getVolume() {
 return length * breadth * height;
}
bool Box::operator==(Box b){
	if(length==b.length&&breadth==b.breadth&&height==b.height){
		return true;
	}
	else{
		return false;
	}
}


