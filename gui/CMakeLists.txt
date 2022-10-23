add_library(
    _gui
    include/MainWindow.h
    include/ChartView.h
    include/SettingsWidget.h
    include/WidgetUtils.h
    src/WidgetUtils.cpp
    src/SettingsWidget.cpp
    src/ChartView.cpp
    src/MainWindow.cpp
    resources/tools.qrc
)

target_include_directories(_gui PUBLIC include/)
target_link_libraries(_gui PUBLIC
    _iqt
    _imodel
    _network_ilayer
)
