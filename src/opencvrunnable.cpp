#include <QDebug>
#include <QColor>
#include <QImage>

#include "opencvrunnable.h"
#include "opencvfilter.h"
#include "opencv2/opencv.hpp"
#include "rgbframehelper.h"
#include "cartoon.h"

using namespace cv;

OpenCVRunnable::OpenCVRunnable(OpenCVFilter *filter)
    :filter(filter)
{
}

/*
SketchVFRunnable::SketchVFRunnable(OpenCVFilter *filter)
    :OpenCVRunnable(filter)
{
}
*/
//https://bugreports.qt.io/browse/QTBUG-47934
//If you refer to Qt source code, specifically, 
//qtmultimedia/examples/multimedia/video/qmlvideofilter_opencl there's a 
//handy function that converts from a QVideoFrame to a QImage.
//See rgbframehelper.h for QImage imageWrapper(const QVideoFrame &frame).
//That implementation demonstrates the OpenGL commands 
//you can use when frame.handleType() == QAbstractVideoBuffer::GLTextureHandle. 
//On the Android devices we've tested this on, this seems to work more 
//reliably than calling QVideoFrame::map().

/*
QVideoFrame SketchVFRunnable::run(QVideoFrame *input
                                , const QVideoSurfaceFormat &surfaceFormat
                                , QVideoFilterRunnable::RunFlags flags)
{
    // Convert the input into a suitable OpenCV image format,
    // then run e.g. cv::CascadeClassifier,
    // and finally store the list of rectangles into a
    // QObject exposing a 'rects' property.

    if (!input->isValid())
        return *input;
    input->map(QAbstractVideoBuffer::ReadWrite);

    QVideoFrame::PixelFormat inputFormat = input->pixelFormat();
    QAbstractVideoBuffer::HandleType handleType = input->handleType();
    qDebug() << "handle type: " << handleType;
    qDebug() << "pixel format: " << inputFormat;
    //QImage::Format imageFormat = QVideoFrame::imageFormatFromPixelFormat(input->pixelFormat());
    QImage::Format imageFormat = QVideoFrame::imageFormatFromPixelFormat(inputFormat);
    //imageFormat = QImage::Format_RGB32;
    qDebug() << "image format: " <<  imageFormat;

    //QImage image;
    //if (QImage::Format_Invalid == imageFormat
    //        && (QAbstractVideoBuffer::NoHandle == handleType
    //            || QAbstractVideoBuffer::GLTextureHandle == handleType))
    //{
    //    image = imageWrapper(*input);
    //}
    //else
    //{
    //    image = QImage(input->bits(), input->width(), input->height(), imageFormat);
    //}
    QImage image(input->bits(), input->width(), input->height(), imageFormat);
    qDebug() << "Width 1: " << image.width();
    cv::Mat inMat = QImageToCvMat(image, false);
    cv::Mat outMat;
    inMat.copySize(outMat);
    //cartoonifyImage(inMat, outMat,true,false,false,false);
    inMat.setTo(cv::Scalar(0, 0, 255));
    outMat.setTo(cv::Scalar(255, 0, 0));

    QColor colour = QColor(0, 255, 0, 127);
    image.fill(colour);
    //image = cvMatToQImage(outMat);
    //image = image.convertToFormat(imageFormat);

    qDebug() << "Width 2: " << outImage.width();
    //QVideoFrame outvf = QVideoFrame(image);

    QImage outImage = cvMatToQImage(outMat);
    outImage = outImage.convertToFormat(imageFormat);
    qDebug() << "Width 2: " << outImage.width();
    QVideoFrame outvf = QVideoFrame(outImage);


    qDebug() << "Is mapped: " << outvf.isMapped();
    if (outvf.isMapped())
        outvf.unmap();
    emit filter->finished();
    return outvf;

  // *input = outvf;

   //if (input->isMapped())
   //     input->unmap();
   // return *input;

}
*/

QVideoFrame OpenCVRunnable::run(QVideoFrame *input
                                , const QVideoSurfaceFormat &
                                , QVideoFilterRunnable::RunFlags )
{
    // Convert the input into a suitable OpenCV image format,
    // then run e.g. cv::CascadeClassifier,
    // and finally store the list of rectangles into a
    // QObject exposing a 'rects' property.
    qDebug() << "In OpenCVRunnable::run, type " << vFRType();

    if (!input->isValid())
        return *input;
    input->map(QAbstractVideoBuffer::ReadWrite);
    QVideoFrame::PixelFormat format = input->pixelFormat();
    //qDebug() << "handle type: " << input->handleType();
    //qDebug() << "pixel format: " << format;
    QImage::Format imageFormat = QVideoFrame::imageFormatFromPixelFormat(input->pixelFormat());
    //qDebug() << "image format: " <<  imageFormat;
    //QImage image(input->bits(), input->width(), input->height(), imageFormat);
    QImage image = imageWrapper(*input);
    //QImage image;
    //if (QImage::Format_Invalid == imageFormat
    //        && (QAbstractVideoBuffer::NoHandle == handleType
    //            || QAbstractVideoBuffer::GLTextureHandle == handleType))
    //{
    //    image = imageWrapper(*input);
    //}
    //else
    //{
    //    image = QImage(input->bits(), input->width(), input->height(), imageFormat);
    //}
    //qDebug() << "Width 1: " << image.width();
    cv::Mat inMat = QImageToCvMat(image, false);
    //inMat.setTo(cv::Scalar(255, 255, 0));
    cv::Mat outMat;
    inMat.copyTo(outMat);
    //outMat.setTo(cv::Scalar(0, 0, 255));

    modifyImage(inMat, outMat);
    outMat.copyTo(inMat);

    QImage outImage = cvMatToQImage(outMat);
    outImage = outImage.convertToFormat(imageFormat);
    //qDebug() << "Width 2: " << outImage.width();
    QVideoFrame outvf = QVideoFrame(outImage);
    //qDebug() << "Is mapped: " << outvf.isMapped();
    if (outvf.isMapped())  outvf.unmap();
    emit filter->finished();
    *input = outvf;
    if (input->isMapped()) input->unmap();
    return *input;
}

void ToonVFRunnable::modifyImage(Mat inMat, Mat outMat)
{
    Cartoon::cartoonifyImage(inMat, outMat, false, false, false, 0);
}
void SketchVFRunnable::modifyImage(Mat inMat, Mat outMat)
{
    Cartoon::cartoonifyImage(inMat, outMat, true, false, false, 0);
}
void EvilVFRunnable::modifyImage(Mat inMat, Mat outMat)
{
    Cartoon::cartoonifyImage(inMat, outMat, false, true, false, 0);
}
void AlianVFRunnable::modifyImage(Mat inMat, Mat outMat)
{
    Cartoon::cartoonifyImage(inMat, outMat, false, false, true, 0);
}
