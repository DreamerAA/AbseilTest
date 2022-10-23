add_library(
    _network_ilayer
    include/INetworkLayer.h
    include/UpdateCoinsLayer.h
    include/IconLoadLayer.h
    include/NetworkLayerStorage.h
    src/NetworkLayerStorage.cpp
    src/IconLoadLayer.cpp
    src/UpdateCoinsLayer.cpp
    src/INetworkLayer.cpp
)

target_include_directories(_network_ilayer PUBLIC
    include/
)

target_link_libraries(
    _network_ilayer PUBLIC
    _iqt
    _imodel
)
