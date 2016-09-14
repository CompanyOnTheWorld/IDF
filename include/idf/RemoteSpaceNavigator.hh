/*
PURPOSE:
LIBRARY DEPENDENCIES: (
(idf/RemoteSpaceNavigator.cpp)
)
*/

/**
 * @trick_parse{everything}
 * @trick_link_dependency{idf/RemoteSpaceNavigator.cpp}
 */

#ifndef REMOTE_SPACE_NAVIGATOR_HH
#define REMOTE_SPACE_NAVIGATOR_HH

#include "idf/SpaceNavigator.hh"
#include "idf/RemoteDeviceServer.hh"
#include "idf/RemoteDeviceClient.hh"

namespace idf {

//class RemoteSpaceNavigator {

//    public:

    /** structure used to serialze commands */
    /** TODO: fix
     * WARNING: This is, in general, a TERRIBLE approach. Doubles are not safe for
     * network transmission. They're used here because this class is part of an
     * emergency (limited-time) development effort.
     */
    struct RemoteSpaceNavigatorCommands {
        double forwardBackwardPivot;
        double leftRightPivot;
        double twist;
        double forwardBackwardTranslation;
        double leftRightTranslation;
        double upDownTranslation;
        double leftButton;
        double rightButton;
    };

#ifdef SWIG
%template (RemoteDeviceServer_RemoteSpaceNavigator) RemoteDeviceServer<RemoteSpaceNavigatorCommands>;
#endif
    /**
     * a server which accepts and manages connections from multiple clients
     *
     * @author Derek Bankieris
     */
    class RemoteSpaceNavigatorServer : public SpaceNavigator, public RemoteDeviceServer<RemoteSpaceNavigatorCommands> {

        public:

        /** @copydoc RemoteDeviceServer::RemoteDeviceServer */
        RemoteSpaceNavigatorServer(unsigned short listenPort = 0);

        void update();

    };

#ifdef SWIG
class RemoteSpaceNavigatorClient;
%template (RemoteDeviceClient_RemoteSpaceNavigator) RemoteDeviceClient<SpaceNavigator, RemoteSpaceNavigatorCommands>;
#endif
    /**
     * transmits commands from a contained SpaceNavigator to a RemoteSpaceNavigatorServer
     *
     * @author Derek Bankieris
     */
    class RemoteSpaceNavigatorClient : public RemoteDeviceClient<SpaceNavigator, RemoteSpaceNavigatorCommands> {

        public:

        /** @copydoc RemoteDeviceClient::RemoteDeviceClient */
        RemoteSpaceNavigatorClient(const SpaceNavigator& sourceController, const std::string hostName, unsigned short hostPort);

        void packCommands(RemoteSpaceNavigatorCommands& commands, const SpaceNavigator& controller);

        using RemoteDeviceClient<SpaceNavigator, RemoteSpaceNavigatorCommands>::packCommands;

        private:

        void operator=(const RemoteSpaceNavigatorClient&);

    };

//};

}

#endif
