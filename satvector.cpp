#include "satvector.h"
#include <math.h>

namespace SAT {
	Vector::Vector() {
		x = 0;
		y = 0;
	}

	Vector::Vector( float xInit, float yInit ) {
		x = xInit;
		y = yInit;
	}

	Vector::Vector( const Vector& v ) {
		set(v);
	}

	void Vector::set( const Vector& v ) {
		x = v.x;
		y = v.y;
	}

	void Vector::set( float xs, float ys ) {
		x = xs;
		y = ys;
	}

	Vector Vector::clone() {
		return Vector( x, y );
	}

	void Vector::perp() {
		float temp = x;
	    x = y;
	    y = -temp;
	}

	void Vector::add( Vector& v ) {
		x += v.x;
		y += v.y;
	}

	void Vector::subtract( Vector& v ) {
		x -= v.x;
		y -= v.y;
	}

	void Vector::scale( float s ) {
		x *= s;
		y *= s;
	}

	void Vector::divide( float d ) {
		x /= d;
		y /= d;
	}

	void Vector::normalize() {
		float length = sqrt(x*x+y*y);
	    if( length == 0 ) y = 1;
		x /= length;
		y /= length;
	}

	float Vector::length() {
	   return sqrt(x*x + y*y);
	}

	float Vector::length2() {
	   return x*x + y*y;
	}

	void Vector::rotate( float angle ) {
		float oldx = x;
	    float oldy = y;
	    x = oldx * cos(angle) - oldy * sin(angle);
	    y = oldx * sin(angle) + oldy * cos(angle);
	}

	float Vector::dot( Vector& v ) {
		return x * v.x + y * v.y;
	}

	float Vector::cross( Vector& v ) {
		return (x * v.y) - (y * v.x);
	}

	float Vector::distance( Vector v ) {
		Vector distanceVector = Vector(v.x - x, v.y - y );
		return distanceVector.length();
	}

	void Vector::project(Vector v) {
		float amt = this->dot(v) / v.length2();
	    x = amt * v.x;
	    y = amt * v.y;
	}

	void Vector::projectN(Vector v) {
		float amt = this->dot(v);
	    x = amt * v.x;
	    y = amt * v.y;
	}

	void Vector::reflect( Vector v ) {
		float oldx = x;
	    float oldy = y;
	    this->project(v);
		this->scale(2);
	    x -= oldx;
	    y -= oldy;
	}

	void Vector::reverse() {
	    x = -x;
	    y = -y;
	}


	//OPERATORS

	Vector Vector::operator+ ( const Vector& v ) const {
		return Vector( x + v.x, y + v.y );
	}

	Vector Vector::operator- ( const Vector& v ) const {
		return Vector( x - v.x, y - v.y );
	}

	Vector Vector::operator* ( const float s ) const {
		return Vector( x * s, y * s );
	}

	//dot product
	float Vector::operator* ( const Vector& v ) const {
	    return (x * v.x + y * v.y);
	}

	//cross product
	float Vector::operator^ ( const Vector& v ) const {
		return (x * v.y) - (y * v.x);
	}

	Vector Vector::operator/ ( const float s ) const {
		return Vector( x / s, y / s );
	}

	Vector Vector::operator/ ( const Vector& v ) const {
		return Vector( x / v.x, y / v.y );
	}

	bool Vector::operator== ( const Vector& v ) const {
		return ( x == v.x && y == v.y );
	}

	void Vector::operator= ( const Vector& v ) {
		x = v.x;
		y = v.y;
	}

	void Vector::operator+= ( const Vector& v ) {
		x += v.x;
		y += v.y;
	}

	void Vector::operator-= ( const Vector& v ) {
		x -= v.x;
		y -= v.y;
	}

	void Vector::operator*= ( const float s ) {
		x *= s;
		y *= s;
	}

	void Vector::operator/= ( const float s ) {
		x /= s;
		y /= s;
	}

	float Vector::operator[] ( int i ) {
		if ( i == 0 ) return x;
	    else return y;
	}
}
