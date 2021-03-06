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

/* 
 * File:   PhysicalTypes.h
 * Author: jucemar
 *
 * Created on 29 de Outubro de 2015, 13:29
 */

#ifndef PHYSICALDESIGN_PHYSICALTYPES_H
#define PHYSICALDESIGN_PHYSICALTYPES_H

#include <cstdint>


//! @file PhysicalTypes.h 
//! @brief This file aggregates all Enum definitions for Rsyn::PhysicalDesign.

namespace Rsyn {

//! @brief Enum type associated to the Database Units of the LEF and DEF resolutions.

enum DBUType : std::int8_t {
	/*! \brief Only used for Rsyn internal control. */
	INVALID_DBU = -1,
	/*! \brief Database Units (DBU) defined on LEF technology Library. */
	LIBRARY_DBU = 0,
	/*! \brief Database Units (DBU) defined on DEF.  */
	DESIGN_DBU = 1,
	/*! \brief LEF_DBU = DEF_DBU * DEF_MULT, e.g. 2000 = 1000 x 2. 
	 * LEF/DEF rules allow only integer multiple between LEF and DEF DBU resolutions.*/
	MULT_FACTOR_DBU = 2,
	/*! \brief Only used for Rsyn internal control.*/
	NUM_DBU = 3
}; // end enum 

// -----------------------------------------------------------------------------

//! @brief Enum type associated to the Rsyn::PhysicalInstance.

enum PhysicalType : std::int8_t {
	//! @brief Only used for Rsyn internal control.
	INVALID_PHYSICAL_TYPE = -1,
	//! @brief A Rsyn::PhysicalInstance is defined as fixed.
	PHYSICAL_FIXED = 0,
	//! @brief A Rsyn::PhysicalInstance is defined as movable.
	PHYSICAL_MOVABLE = 1,
	//! @brief A Rsyn::PhysicalInstance is defined as block.
	PHYSICAL_BLOCK = 2,
	//! @brief A Rsyn::PhysicalInstance is defined as port.
	PHYSICAL_PORT = 3,
	//! @brief A Rsyn::PhysicalInstance is defined as fixed bounds.
	PHYSICAL_FIXEDBOUNDS = 4,
	//! @brief A Rsyn::PhysicalInstance is defined as placeable.
	PHYSICAL_PLACEABLE = 5,
	/*! \brief Only used for Rsyn internal control.*/
	NUM_PHYSICAL_TYPES = 6
}; // end enum 

// -----------------------------------------------------------------------------

//! @brief Layer type. 

enum PhysicalLayerType : std::int8_t {
	/*! \brief Only used for Rsyn internal control.*/
	INVALID_PHY_LAYER_TYPE = -1,
	//! @brief Layer is defined as Routing type.
	ROUTING = 0,
	//! @brief Layer is defined as cut type.
	CUT = 1,
	//! @brief Layer is defined as overlap type.
	OVERLAP = 2,
	//! @brief Layer is defined as master slice type . They are typically polysilicon. 
	MASTERSLICE = 3,
	//! @brief Layer is defined as implant type.
	IMPLANT = 4,
	/*! \brief Only used for Rsyn internal control.*/
	NUM_PHY_LAYER = 5
};

//! @brief Layer direction. 

enum PhysicalLayerDirection : std::int8_t {
	/*! \brief Only used for Rsyn internal control.*/
	INVALID_PHY_LAYER_DIRECTION = -1,
	//! @brief Layer preference direction is defined as horizontal. 
	HORIZONTAL = 0,
	//! @brief Layer preference direction is defined as vertical.
	VERTICAL = 1,
	/*! \brief Only used for Rsyn internal control.*/
	NUM_PHY_LAYER_DIRECTION = 2
};

// -----------------------------------------------------------------------------

//! @brief Class types of the sites.

enum PhysicalSiteClass : std::int8_t {
	/*! \brief Only used for Rsyn internal control.*/
	INVALID_SITECLASS = -1,
	//! @brief The site is defined as PAD type. Sites are typically used in rows. 
	PAD = 0,
	//! @brief The site is defined as Core type. Sites are typically used in rows. 
	CORE = 1,
	/*! \brief Only used for Rsyn internal control.*/
	NUM_PHY_SITECLASS = 2
};

// -----------------------------------------------------------------------------

//! @brief Pin direction

enum PhysicalPinDirection : std::int8_t {
	//! @brief Only used for Rsyn internal control.
	PIN_INVALID_DIRECTION = -1,
	//! @brief Pin direction is input. 
	PIN_INPUT = 0,
	//! @brief Pin direction is output. 
	PIN_OUTPUT = 1,
	//! @brief Only used for Rsyn internal control.
	NUM_PHY_PIN_DIRECTION = 2
};

// -----------------------------------------------------------------------------

//! @brief  The class type of macros.

enum PhysicalMacroClass : std::int8_t {
	/*! \brief Only used for Rsyn internal control.*/
	MACRO_INVALID_CLASS = -1,
	//! @brief Macro is Cover class.
	MACRO_COVER = 0,
	//! @brief Macro is Ring class.
	MACRO_RING = 1,
	//! @brief  Macro is Block class. It may have a subtype of PhysicalMacroBlockClass
	MACRO_BLOCK = 2,
	//! @brief Macro is Pad class.
	MACRO_PAD = 3,
	//! @brief Macro is Core class.
	MACRO_CORE = 4,
	//! @brief Macro is Endcap class.
	MACRO_ENDCAP = 5,
	/*! \brief Only used for Rsyn internal control.*/
	NUM_PHY_MACRO_CLASS = 6
};

// -----------------------------------------------------------------------------

//! @brief The subtype of MACRO_BLOCK type from PhysicalMacroClass.

enum PhysicalMacroBlockClass : std::int8_t {
	/*! \brief Only used for Rsyn internal control.*/
	MACRO_INVALID_BLOCK_CLASS = -1,
	//! @brief The Block is defined as black block.
	MACRO_BLOCK_BLACKBOX = 0,
	//! @brief The Block is defined as soft block.
	MACRO_BLOCK_SOFT = 1,
	/*! \brief Only used for Rsyn internal control.*/
	NUM_MACRO_BLOCK_CLASS = 2
};

// -----------------------------------------------------------------------------

//! @brief Orientation based on compass rose.
//! @details The default orientation is "vertically and face up" - N (North). 
//!        Rotate by 90deg clockwise to get E, S and W, flip to get FN, FE, 
//!        FS and FW. (think of a dial).		
//!        Source: http://vlsicad.ucsd.edu/GSRC/bookshelf/Slots/Placement/plFormats.html
//! @note  This orientations are compatible with LEF/DEF and OpenAccess.

enum PhysicalOrientation : std::int8_t {
	/*! \brief Only used for Rsyn internal control.*/
	ORIENTATION_INVALID = -1,
	
	//! @brief North Orientation (R0)
	ORIENTATION_N,
	//! @brief South orientation (R180)
	ORIENTATION_S,
	//! @brief West orientation (R90)
	ORIENTATION_W,
	//! @brief East orientation  (R270)
	ORIENTATION_E,
	//! @brief Flipped-North orientation (MY)
	ORIENTATION_FN,
	//! @brief Flipped-South orientation (MX)
	ORIENTATION_FS,
	//! @brief Flipped-West orientation (MX90)
	ORIENTATION_FW,
	//! @brief Flipped-East orientation (MY90)
	ORIENTATION_FE,

	//! @brief Number of orientations
	NUM_PHY_ORIENTATION
}; // end enum

// -----------------------------------------------------------------------------

//! @brief Symmetry based on Cartesian coordinate system
//! @details X and Y - allows flips around axis, ROT90 - allows any of 
//!        rotations by 0, 90, 180 or 270 degrees.
//!	   Source: http://vlsicad.ucsd.edu/GSRC/bookshelf/Slots/Fundamental/HGraph/
//! @todo ROT90

enum PhysicalSymmetry : std::int8_t {
	//! @brief Only used for Rsyn internal control.
	SYMMETRY_INVALID = -1,
	//! @brief Defines the symmetry in the abscissa (X).
	SYMMETRY_X = 0,
	//! @brief Defines the symmetry in the ordinate (Y).
	SYMMETRY_Y = 1,
	//! @brief Only used for Rsyn internal control.
	NUM_PHY_SYMMETRY = 2
}; // end enum

// -----------------------------------------------------------------------------

//! @brief Class type for the Pin geometry object. 

enum PhysicalPinGeometryClass : std::int8_t {
	//! @brief Only used for Rsyn internal control.
	PINGEOMETRYCLASS_INVALID = -1,
	//! @brief A pin geometry has none class defined. It is the default geometry class type.
	PINGEOMETRYCLASS_NONE = 0,
	//! @brief A pin geometry has Core class defined. 
	PINGEOMETRYCLASS_CORE = 1,
	//! @brief A pin geometry has Bump class defined. 
	PINGEOMETRYCLASS_BUMP = 2,
	//! @brief Only used for Rsyn internal control.
	NUM_PINGEOMETRYCLASS = 3
}; // end enum 


//! @brief Region type for the Region object.

enum class RegionType : std::int8_t {
	INVALID = -1,
	FENCE = 0,
	GUIDE = 1
}; // end enum class 

//! @brief Layout may be upload in physical design only for Floorplanning, Placement, CTS or Routing. It avoids loading unnecessary data.

enum class PhysicalDesignMode : std::int8_t {
	INVALID = -1,
	ALL = 0,
	FLOORPLANNING = 1,
	PLACEMENT = 2,
	CTS = 3,
	ROUTING = 4,
}; // end enum class 



enum PhysicalEventType {
	PHYSICAL_EVENT_DESTRUCTION,
	PHYSICAL_EVENT_CELL_REMAP,
	//PHYSICAL_EVENT_POST_INSTANCE_CREATE,
	//PHYSICAL_EVENT_PRE_INSTANCE_REMOVE,
	PHYSICAL_EVENT_PRE_INSTANCE_MOVED,
	PHYSICAL_EVENT_POS_INSTANCE_MOVED,
	NUM_PHYSICAL_EVENTS
}; // end enum


} // end namespace 

#endif /* PHYSICALDESIGN_PHYSICALTYPES_H */

