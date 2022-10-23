add_library(
    _imodel
    include/IModel.h
    src/IModel.cpp
)

target_include_directories(_imodel PUBLIC
    include/
)

target_link_libraries(
    _imodel PUBLIC
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui # must be removed from here QIcon!!!
)
