/*
PURPOSE:
LIBRARY DEPENDENCIES: (
(idf/CanDevice.cpp)
)
*/

/**
 * @trick_parse{everything}
 * @trick_link_dependency{idf/CanDevice.cpp}
 */

#ifndef CAN_DEVICE_HH
#define CAN_DEVICE_HH

#include "idf/InputDevice.hh"
#include "idf/IOException.hh"
#include "ntcan.h"

namespace idf {

/**
 * abstract base class for all CAN input devices. Subclasses should usually
 * represent a specific physical device (WingMan, SpaceExplorer, etc) and
 * implement logic to fulfill the contract of #open. They should
 * also usually derive from the appropriate class from the %Input Abstraction
 * Layer, as well as be concrete.
 *
 * @author Derek Bankieris
 */
class CanDevice : public InputDevice {

    public:

    /**
     * constructs a new instance
     *
     * @param name the name of this device
     * @param networkId the network number
     * @param flags @copydoc flags
     * @param transmitQueueSize @copydoc transmitQueueSize
     * @param receiveQueueSize @copydoc receiveQueueSize
     * @param transmitTimeout @copydoc transmitTimeout
     * @param receiveTimeout @copydoc receiveTimeout
     */
    CanDevice(const std::string& name, int networkId = 0, uint32_t flags = 0,
      int32_t transmitQueueSize = 1024, int32_t receiveQueueSize = 1024,
      int32_t transmitTimeout = 0, int32_t receiveTimeout = 0);

    /** destructs this instance */
    virtual ~CanDevice() {};

    virtual void open();
    virtual void close();

    protected:

    /** handle to the device */
    NTCAN_HANDLE ntCanHandle;

    private:

    /** the network number */
    const int networkId;

    /**
     * a bitwise OR of the following options:
     * - NTCAN_MODE_OVERLAPPED - overlapped I/O only
     * - NTCAN_MODE_OBJECT - reception is in object mode instead of FIFO mode
     * - NTCAN_MODE_NO_RTR - remote message requests are ignored
     * - NTCAN_MODE_NO_DATA - data frames are ignored
     * - NTCAN_MODE_NO_INTERACTION - messages received via interaction mechanisms are ignored
     * - NTCAN_MODE_MARK_INTERACTION - messages received via interaction mechanisms will be
     *   marked as such in the length field
     */
    const uint32_t flags;

    /** maximum number of messages the Tx queue can hold */
    const int32_t transmitQueueSize;

    /** maximum number of messages the Rx queue can hold */
    const int32_t receiveQueueSize;

    /** transmit timeout in ms */
    const int32_t transmitTimeout;

    /** receive timeout in ms */
    const int32_t receiveTimeout;

    /** this class is not copy-assignable */
    CanDevice& operator=(const CanDevice&);

};

}

#endif
