include("C:/Users/markm/Documents/GitHub/FreeNotes/build/Desktop_Qt_6_9_0_MinGW_64_bit-Release/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/FreeNotes-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE C:/Users/markm/Documents/GitHub/FreeNotes/build/Desktop_Qt_6_9_0_MinGW_64_bit-Release/FreeNotes.exe
    GENERATE_QT_CONF
)
