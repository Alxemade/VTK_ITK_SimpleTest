QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle


QT += widgets

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp


SysStatus = $$system(if exist %windir%/SysWOW64 echo x64)  ## if contains SysWOW64 prove the windows is 64 bit

win32 {
    ## Windows common build here
    !contains(SysStatus, x64) {
        message("x86 build ")
        ## Windows x86 (32bit) specific build here

    } else {
        message("x86_64 build")
        ## Windows x64 (64bit) specific build here
        ##LABMR_PREFIX = E:\XC\itk\Bin\lib
        ## TOOLS_PREFIX = quote(C:/Program Files)
    }
}
##ITK INCLUDEPATH Starts
INCLUDEPATH += $$quote(E:/XC/itk/Bin/include/ITK-4.13)
##ITK Ends

CONFIG(debug, debug|release) {

## ITK Debug LIB Starts
LIBS += $$quote(E:/XC/itk/Bin/lib/itk*.lib)
LIBS += $$quote(E:/XC/itk/Bin/lib/ITK*.lib)
## ITK Debug LIB Ends

} else {

## VTK Release LIB Starts
##LIBS += $${LABMR_PREFIX}/Release/vtk*.lib
## VTK Release LIB Ends

}
