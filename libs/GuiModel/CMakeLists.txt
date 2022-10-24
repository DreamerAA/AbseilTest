add_library(
    _gui_model
    include/GuiModel.h
    src/GuiModel.cpp
)

target_include_directories(_gui_model PUBLIC
    include/
)

target_link_libraries(
    _gui_model PUBLIC
    _imodel
)
