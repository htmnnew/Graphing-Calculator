TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    token.h \
    queue.h \
    LinkedListClass.h \
    LinkedListFuncs.h \
    mystack.h \
    node.h \
    constants.h \
    evaluatelower.h \
    childnumbers.h \
    childoperators.h \
    childfunctions.h \
    childvariables.h \
    childpLarentasis.h \
    childpRarentasis.h \
    shunting_yard.h \
    coordinates.h



include(deployment.pri)
qtcAddDeployment()


LIBS += -L"C:\Users\nerse\Desktop\Htmnnew\C++\SFML\lib"
LIBS += -L"C:\Users\nerse\Desktop\Htmnnew\C++\SFML\bin"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window #ORDER MATTERS!
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

INCLUDEPATH += "C:\Users\nerse\Desktop\Htmnnew\C++\SFML\include"
DEPENDPATH += "C:\Users\nerse\Desktop\Htmnnew\C++\SFML\include"
