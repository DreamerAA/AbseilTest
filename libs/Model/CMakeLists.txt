add_library(
    _model
    include/Model.h
    src/Model.cpp
)

target_include_directories(_model PUBLIC
    include/
)

target_link_libraries(
    _model PUBLIC
    _imodel
)
