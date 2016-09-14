/*
PURPOSE:
LIBRARY DEPENDENCIES: (
(idf/Deadbandable.cpp)
)
*/

/**
 * @trick_parse{everything}
 * @trick_link_dependency{idf/Deadbandable.cpp}
 */

#ifndef DEADBANDABLE_HH
#define DEADBANDABLE_HH

#include <vector>
#include "idf/Deadband.hh"

namespace idf {

/**
 * this is a mixin class that provides the adopting class with Deadband support
 *
 * @author Derek Bankieris
 */
class Deadbandable {

    public:

    /** destructor */
    ~Deadbandable() {}

    /**
     * adds @a deadband to the list of filters.
     * Adding a deadband that is already applied to this instance has no effect.
     *
     * @param deadband the deadband to add
     */
    void addDeadband(const Deadband& deadband);

    /**
     * remove @a deadband from the list of filters.
     * Removing a deadband that is not applied to this instance has no effect.
     *
     * @param deadband the deadband to remove
     */
    void removeDeadband(const Deadband& deadband);

    /** removes all deadbands applied to this instance */
    void clearDeadbands();

    /**
     * returns the deadbands applied to this instance
     *
     * @return the current deadbands
     */
    const std::vector<Deadband>& getDeadbands() const;

    protected:

    /**
     * applies all Deadbands to @a value
     *
     * @param value the value to filter
     *
     * @return the filtered value
     */
    double applyDeadbands(double value) const;

    /** deadband filters */
    std::vector<Deadband> deadbands;

};

}

#endif
