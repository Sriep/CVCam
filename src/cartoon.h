#ifndef CARTOON_H
#define CARTOON_H
#include <QQuickItem>
// Include OpenCV's C++ Interface
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

class Cartoon : public QQuickItem
{
    Q_OBJECT
public:
    enum ToonFormat { Unchanged = 0, Sketch, Toon, Evil, Alian, NumFormats };
    //Cartoon(QQuickItem *parent = 0);
    Q_ENUM(ToonFormat)
    Q_INVOKABLE void toonify(QString path, int toonFormat);
    static void cartoonifyImage(Mat srcColor, Mat dst, bool sketchMode, bool alienMode, bool evilMode, int debugType);
private:
    static void changeFacialSkinColor(Mat smallImgBGR, Mat bigEdges, int debugType);
    static void removePepperNoise(Mat &mask);
    static void drawFaceStickFigure(Mat dst);
};

#endif // CARTOON_H
