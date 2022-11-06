/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/8/20
*/

#pragma once

#include "IControllable.h"
#include "CLocationSave.h"

/**
 * Materialization of custom-defined location
 */
class CLocation : public IControllable {
public:
    CLocation() = delete;

    explicit CLocation(const CLocationSave &location);


    std::string getName() const {
        return mName;
    }

    std::string getDescription() const {
        return mDescription;
    }

    std::shared_ptr<std::map<std::string, std::shared_ptr<CAction> > > getActions() override;

private:
    std::string mName;
    std::string mDescription;
    std::shared_ptr<std::map<std::string, std::shared_ptr<CAction> > > mOptions;
};


