#ifndef _Vector_
#define _Vector_

namespace SAT {

	class Vector {
	public :

		float x, y;
		Vector();
		Vector( float xInit, float yInit );
		Vector( const Vector& v );

		void set( const Vector& v );
		void set( float xs, float ys );
		Vector clone();

		void perp();
		void rotate( float angle );

		void add( Vector& v );
		void subtract( Vector& v );
		void scale( float s );
		void divide( float s );

		void normalize();
		float length();
		float length2();

		float dot( Vector& v );
		float cross( Vector& v );
		float distance( Vector v );
		void project(Vector v);
		void projectN(Vector v);
	    void reflect( Vector v );
	    void reverse();

		Vector operator+ ( const Vector& v ) const;
		Vector operator- ( const Vector& v ) const;
		Vector operator* ( const float s ) const;
		float operator* ( const Vector& v ) const; //dot product
		float operator^ ( const Vector& v ) const; //cross product
		Vector operator/ ( const float s ) const;
		Vector operator/ ( const Vector& v ) const;
		bool operator== ( const Vector& v ) const;
		void operator= ( const Vector& v );
		void operator+= ( const Vector& v );
		void operator-= ( const Vector& v );
		void operator*= ( const float s );
		void operator/= ( const float s );
		float operator[] ( int i );

	};

}

#endif
