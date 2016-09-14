/*
PURPOSE:
LIBRARY DEPENDENCIES: (
(idf/XBox.cpp)
)
*/

/**
 * @trick_parse{everything}
 * @trick_link_dependency{idf/XBox.cpp}
 */

#ifndef XBOX_HH
#define XBOX_HH

#include "idf/InputLayout.hh"
#include "idf/SingleInput.hh"

namespace idf {

/**
 * Microsoft XBox360 hand controller's input layout
 *
 * @author Derek Bankieris
 */
class XBox : public virtual InputLayout {

    public:

    /** constructor */
    XBox();

    /** destructor */
    virtual ~XBox() {};

    /** upper-left analog pad left-right pivot */
    SingleInput leftAnalogLeftRightPivot;

    /** upper-left analog pad up-down pivot */
    SingleInput leftAnalogUpDownPivot;

    /** pushing in of the upper-left analog pad */
    SingleInput leftAnalogIn;

    /** lower-right analog pad left-right pivot */
    SingleInput rightAnalogLeftRightPivot;

    /** lower-right analog pad up-down pivot */
    SingleInput rightAnalogUpDownPivot;

    /** pushing in of the lower-right analog pad */
    SingleInput rightAnalogIn;

    /** up on the directional pad */
    SingleInput directionalPadUp;

    /** down on the directional pad */
    SingleInput directionalPadDown;

    /** left on the directional pad */
    SingleInput directionalPadLeft;

    /** right on the directional pad */
    SingleInput directionalPadRight;

    /** the button labeled back */
    SingleInput backButton;

    /** the center XBox button */
    SingleInput xBoxButton;

    /** the button labeled start */
    SingleInput startButton;

    /** the button labeled X */
    SingleInput xButton;

    /** the button labeled Y */
    SingleInput yButton;

    /** the button labeled A */
    SingleInput aButton;

    /** the button labeled B*/
    SingleInput bButton;

    /** the button labeled LB */
    SingleInput leftBumper;

    /** the button labeled RB*/
    SingleInput rightBumper;

    /** the button labeled LT */
    SingleInput leftTrigger;

    /** the button labeled RT */
    SingleInput rightTrigger;

    protected:

    virtual const std::vector<Configurable>& getConfigurables();

};

}

#endif
