/* Copyright 2014-2017 Rsyn
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
 
#ifndef RSYN_FLOATING_POINT_H
#define	RSYN_FLOATING_POINT_H

#include <cmath>
#include <cassert>

enum RoundingStrategy {
	ROUND_DOWN,
	ROUND_UP,
	ROUND_NEAREST
}; // end enum

class FloatingPoint {
private:

	template<typename T, typename R> inline
	static
	R round(const T value, const RoundingStrategy roudingStrategy) {
		switch (roudingStrategy) {
			case ROUND_DOWN:    return (R)           (value);
			case ROUND_UP:      return (R) std::ceil (value);
			case ROUND_NEAREST: return (R) std::round(value);
			default: assert(false); return 0;
		} // end switch
	} // end  function

public:

	template<typename T>
	static bool approximatelyZero(const T a, const T precision = 1e-6f) {
		return std::abs(a) <= precision;
	} // end method	
	
	template<typename T>
	static bool notApproximatelyZero(const T a, const T precision = 1e-6f) {
		return !approximatelyZero(a);
	} // end method		
	
	// Source: The Art of Computer Programming by Knuth

	// [TODO] It seems these functions break down when one operator is zero (0).
	// [TODO] Those function may not work with infinity!

	template<typename T>
	static bool approximatelyEqual(const T a, const T b, const T precision = 1e-6f) {
		return std::abs(a - b) <= 
				((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * precision);
	} // end method	
	
	template<typename T>
	static bool notApproximatelyEqual(const T a, const T b, const T precision = 1e-6f) {
		return !approximatelyEqual(a, b, precision);
	} // end method		
	
	template<typename T>
	static bool definitelyGreaterThan(const T a, const T b, const T precision = 1e-6f) {
		return (a - b) > 
				((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * precision);
	} // end method

	template<typename T> // added by Jucemar. Check if is correct
	static bool definitelyGreaterEqualThan(const T a, const T b, const T precision = 1e-6f) {
		return (a - b) >= 
				((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * precision);
	} // end method
	template<typename T>
	static bool definitelyLessThan(const T a, const T b, const T precision = 1e-6f) {
		return (b - a) > 
				((std::abs(a) < std::abs(b) ? std::abs(b) : std::abs(a)) * precision);
	} // end method

	static int round(const float value, const RoundingStrategy roudingStrategy) {
		return round<float, int>(value, roudingStrategy);
	} // end  function

	static long round(const double value, const RoundingStrategy roudingStrategy) {
		return round<double, long>(value, roudingStrategy);
	} // end  function
}; // end class

#endif

