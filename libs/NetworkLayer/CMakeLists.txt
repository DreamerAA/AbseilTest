add_library(
    _network_ilayer
    include/INetworkWorker.h
    include/UpdateCoinsWorker.h
    include/IconLoadWorker.h
    include/NetworkWorkerStorage.h
    include/NetworkLayer.h
    src/NetworkLayer.cpp
    src/NetworkWorkerStorage.cpp
    src/IconLoadWorker.cpp
    src/UpdateCoinsWorker.cpp
    src/INetworkWorker.cpp
)

target_include_directories(_network_ilayer PUBLIC
    include/
)

target_link_libraries(
    _network_ilayer PUBLIC
    _iqt
    _imodel
    _gui_model
)
