/*
PURPOSE:
*/

/* @trick_parse{everything} */

#ifndef STATE_CHANGE_LISTENER_HH
#define STATE_CHANGE_LISTENER_HH

namespace idf {

class Controller;

/**
 * abstract base class representing an interface for receiving
 * notification of state changes of {@link Controller}s
 *
 * @author Derek Bankieris
 */
class StateChangeListener {

    public:

    /** destructor */
    virtual ~StateChangeListener() {}

    /**
     * called in response to a change in state of a Controller for which this instance is registered
     *
     * @param controller the controller whose state has changed
     */
    virtual void stateChanged(Controller& controller) = 0;

};

}

#endif
