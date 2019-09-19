/*
 * Box.hpp
 *
 *  Created on: Sep 19, 2019
 *      Author: Robert Stahl and Chris Tiso
 */

#ifndef BOX_HPP_
#define BOX_HPP_


class Box {
 double length;
 double breadth;
 double height;
 public:
 Box (double l, double b, double);
 double getVolume();
 bool operator==(Box b);
};


#endif /* BOX_HPP_ */
