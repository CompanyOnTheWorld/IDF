/*
PURPOSE:
LIBRARY DEPENDENCIES: (
(idf/UsbSpaceMouse.cpp)
)
*/

/**
 * @trick_parse{everything}
 * @trick_link_dependency{idf/UsbSpaceMouse.cpp}
 */

#ifndef USB_SPACE_MOUSE_HH
#define USB_SPACE_MOUSE_HH

#include "idf/UsbSpaceBase.hh"
#include "idf/SpaceMouse.hh"

namespace idf {

/**
 * USB SpaceMouse hand controller
 *
 * @author Derek Bankieris
 */
class UsbSpaceMouse : public UsbSpaceBase, public SpaceMouse {

    public:

    /** @copydoc UsbChProPedals::UsbChProPedals */
    UsbSpaceMouse(int vendorID = 0x46D, int productID = 0xC62B);

    protected:

    void processButtons(const unsigned char* buttonData);

};

}

#endif
