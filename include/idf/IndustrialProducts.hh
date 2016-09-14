/*
PURPOSE:
LIBRARY DEPENDENCIES: (
(idf/IndustrialProducts.cpp)
)
*/

/**
 * @trick_parse{everything}
 * @trick_link_dependency{idf/IndustrialProducts.cpp}
 */

#ifndef INDUSTRIAL_PRODUCTS_HH
#define INDUSTRIAL_PRODUCTS_HH

#include "idf/InputLayout.hh"
#include "idf/SingleInput.hh"

namespace idf {

/**
 * %IndustrialProducts hand controller's input layout
 *
 * @author Derek Bankieris
 */
class IndustrialProducts : public virtual InputLayout {

    public:

    /** constructor */
    IndustrialProducts();

    /** destructor */
    virtual ~IndustrialProducts() {};

    /** forward-backward pivoting */
    SingleInput forwardBackwardPivot;

    /** left-right pivoting */
    SingleInput leftRightPivot;

    /** twisting */
    SingleInput twist;

    /** the trigger button */
    SingleInput trigger;

    /** the digital hat's northern trigger */
    SingleInput hatNorth;

    /** the digital hat's eastern trigger */
    SingleInput hatEast;

    /** the digital hat's southern trigger */
    SingleInput hatSouth;

    /** the digital hat's western trigger */
    SingleInput hatWest;

    /** the upper trigger of the switch */
    SingleInput switchUp;

    /** the lower trigger of the switch */
    SingleInput switchDown;

    /** up-down pivoting of the analog hat */
    SingleInput hatUpDownPivot;

    /** left-right pivoting of the analog hat */
    SingleInput hatLeftRightPivot;

    protected:

    virtual const std::vector<Configurable>& getConfigurables();
};

}

#endif
