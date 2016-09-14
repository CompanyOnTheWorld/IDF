/*
PURPOSE:
LIBRARY DEPENDENCIES: (
(idf/Gravis.cpp)
)
*/

/**
 * @trick_parse{everything}
 * @trick_link_dependency{idf/Gravis.cpp}
 */

#ifndef GRAVIS_HH
#define GRAVIS_HH

#include "idf/InputLayout.hh"
#include "idf/SingleInput.hh"

namespace idf {

/**
 * %Gravis hand controller's input layout
 *
 * @author Derek Bankieris
 */
class Gravis : public virtual InputLayout {

    public:

    /** constructor */
    Gravis();

    /** destructor */
    virtual ~Gravis() {};

    /** up on the directional pad */
    SingleInput directionalPadUp;

    /** down on the directional pad */
    SingleInput directionalPadDown;

    /** left on the directional pad */
    SingleInput directionalPadLeft;

    /** right on the directional pad */
    SingleInput directionalPadRight;

    /** the button labeled select */
    SingleInput selectButton;

    /** the button labeled start */
    SingleInput startButton;

    /** the north (blue) button */
    SingleInput northButton;

    /** the east (green) button */
    SingleInput eastButton;

    /** the south (yellow) button */
    SingleInput southButton;

    /** the west (red) button */
    SingleInput westButton;

    /** the button labeled 1 above the side labeled L */
    SingleInput leftBumper1;

    /** the button labeled 2 above the side labeled L */
    SingleInput leftBumper2;

    /** the button labeled 1 above the side labeled R */
    SingleInput rightBumper1;

    /** the button labeled 2 above the side labeled R */
    SingleInput rightBumper2;

};

}

#endif
