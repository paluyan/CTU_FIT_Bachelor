#include "CApplication.h"
#include "IOManager.h"
#include "CController.h"
#include "CFileManager.h"

int main() {

    srand((unsigned long) time(nullptr));

    auto &vApp = CApplication::getInstance();

    vApp.setController(std::make_shared<CController>());
    vApp.setFileManager(std::make_shared<CFileManager>());

    vApp.runApp();

    CApplication::clearInstance();
    IOManager::Print("See you!");

    return 0;
}
