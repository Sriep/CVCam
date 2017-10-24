CONFIG += v-play
TEMPLATE=app
TARGET=CVCam

QT += quick qml multimedia

HEADERS += cartoon.h \
    opencvfilter.h \
    opencvrunnable.h \
    rgbframehelper.h
SOURCES += \
    qmlcamera.cpp\
    cartoon.cpp \
    opencvfilter.cpp \
    opencvrunnable.cpp

RESOURCES += declarative-camera.qrc

android {
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
    OTHER_FILES += android/AndroidManifest.xml
}

ios {
    QMAKE_INFO_PLIST = ios/Project-Info.plist
    OTHER_FILES += $$QMAKE_INFO_PLIST
}

# ********************************* OpenCV ********************************
win32 {
    INCLUDEPATH += E:\OpenCV\opencv\build\include
    INCLUDEPATH += E:\OpenCV\opencv\build\include\opencv2
    INCLUDEPATH += E:\OpenCV\opencv\build\include\opencv
    LIBS += E:\OpenCV\opencv\build\bin\libopencv_core330.dll
    LIBS += E:\OpenCV\opencv\build\bin\libopencv_highgui330.dll
    LIBS += E:\OpenCV\opencv\build\bin\libopencv_imgcodecs330.dll
    LIBS += E:\OpenCV\opencv\build\bin\libopencv_imgproc330.dll
    LIBS += E:\OpenCV\opencv\build\bin\libopencv_features2d330.dll
    LIBS += E:\OpenCV\opencv\build\bin\libopencv_calib3d330.dll
    LIBS += E:\OpenCV\opencv\build\bin\libopencv_videoio330.dll
}
# ********************************* OpenCV ********************************

android{
    INCLUDEPATH += $$_PRO_FILE_PWD_/opencv-android-sdk-static/sdk/native/jni/include
    INCLUDEPATH += $$_PRO_FILE_PWD_/opencv-android-sdk-static/sdk/native/jni/include/opencv
    INCLUDEPATH += $$_PRO_FILE_PWD_/opencv-android-sdk-static/sdk/native/jni/include/opencv2
    # Order of includes is IMPORTANT!!!
    LIBS += \
        -L"$$_PRO_FILE_PWD_/opencv-android-sdk-static/sdk/native/3rdparty/libs/armeabi-v7a"\
        -L"$$_PRO_FILE_PWD_/opencv-android-sdk-static/sdk/native/libs/armeabi-v7a"\
        -lopencv_calib3d\
        -lopencv_core\
        -lopencv_dnn\
        -lopencv_features2d\
        -lopencv_flann\
        -lopencv_highgui\
        -lopencv_imgcodecs\
        -lopencv_imgproc\
        -lopencv_java3\
        -lopencv_ml\
        -lopencv_objdetect\
        -lopencv_photo\
        -lopencv_shape\
        -lopencv_stitching\
        -lopencv_superres\
        -lopencv_video\
        -lopencv_videoio\
        -lopencv_videostab  \
        -lcpufeatures\
        -llibprotobuf\
        -llibjpeg\
        -llibwebp\
        -llibpng\
        -llibtiff\
        -llibjasper\
        -lIlmImf\
        -ltegra_hal\
        -ltbb

    DISTFILES += \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_calib3d.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_core.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_dnn.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_features2d.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_flann.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_highgui.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_imgcodecs.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_imgproc.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_ml.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_objdetect.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_photo.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_shape.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_stitching.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_superres.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_video.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_videoio.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_videostab.a \
        opencv-android-sdk-static/sdk/native/libs/armeabi-v7a/libopencv_java3.so \
        opencv-android-sdk-static/sdk/native/3rdparty/libs/armeabi-v7a/libcpufeatures.a \
        opencv-android-sdk-static/sdk/native/3rdparty/libs/armeabi-v7a/libIlmImf.a \
        opencv-android-sdk-static/sdk/native/3rdparty/libs/armeabi-v7a/liblibjasper.a \
        opencv-android-sdk-static/sdk/native/3rdparty/libs/armeabi-v7a/liblibjpeg.a \
        opencv-android-sdk-static/sdk/native/3rdparty/libs/armeabi-v7a/liblibpng.a \
        opencv-android-sdk-static/sdk/native/3rdparty/libs/armeabi-v7a/liblibprotobuf.a \
        opencv-android-sdk-static/sdk/native/3rdparty/libs/armeabi-v7a/liblibtiff.a \
        opencv-android-sdk-static/sdk/native/3rdparty/libs/armeabi-v7a/liblibwebp.a \
        opencv-android-sdk-static/sdk/native/3rdparty/libs/armeabi-v7a/libtbb.a \
        opencv-android-sdk-static/sdk/native/3rdparty/libs/armeabi-v7a/libtegra_hal.a
}

DISTFILES += \
    qml/config.json \
    win/app_icon.ico \
    macx/app_icon.icns \
    win/app_icon.rc \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

