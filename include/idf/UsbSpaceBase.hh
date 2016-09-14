/*
PURPOSE:
LIBRARY DEPENDENCIES: (
(idf/UsbSpaceBase.cpp)
)
*/

/**
 * @trick_parse{everything}
 * @trick_link_dependency{idf/UsbSpaceBase.cpp}
 */

#ifndef USB_SPACE_BASE_HH
#define USB_SPACE_BASE_HH

#include "idf/UsbDevice.hh"
#include "idf/SpaceBase.hh"

namespace idf {

/**
 * common aspects of all 3dconnexion controllers
 *
 * @author Derek Bankieris
 */
class UsbSpaceBase : public UsbDevice, public virtual SpaceBase {

    public:

    /**
     * constructs a new instance whose open() will look for a USB device with the @a vendorID and @a productID
     *
     * @param name the name of this device
     * @param vendorID the target USB device's vendorID
     * @param productID the target USB device's productID
     */
    UsbSpaceBase(const std::string& name, int vendorID, int productID);

    /** destructor */
    virtual ~UsbSpaceBase() {};

    void decode(const std::vector<unsigned char>& data);

    protected:

    /**
     * processes the button data and sets the appropriate inputs. This function is called by
     * update() and is where derived classes should address their specific button layouts.
     *
     * @param buttonData the raw button data
     */
    virtual void processButtons(const unsigned char* buttonData) = 0;

};

}

#endif
