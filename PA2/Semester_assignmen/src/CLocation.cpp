/**
* @author Yana Paluyan <paluyyan@fit.cvut.cz>
* @date 5/8/20
*/

#include "CLocation.h"
#include "COption.h"

std::shared_ptr<std::map<std::string, std::shared_ptr<CAction> > > CLocation::getActions() {
    return mOptions;
}

CLocation::CLocation(const CLocationSave &location)
        : mName(location.mName),
          mDescription(location.mDescription),
          mOptions(new std::map<std::string, std::shared_ptr<CAction> >()) {
    for (auto &vOp: location.mOptions) {
        std::shared_ptr<CAction> vAction = COption::getOption(vOp);
        mOptions->emplace(std::make_pair(vAction->getCommand(), vAction));
    }

}


