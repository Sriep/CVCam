#ifndef CARTOON_H
#define CARTOON_H

// Include OpenCV's C++ Interface
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;

class Cartoon
{
public:
    Cartoon();

    // Convert the given photo into a cartoon-like or painting-like image.
    // Set sketchMode to true if you want a line drawing instead of a painting.
    // Set alienMode to true if you want alien skin instead of human.
    // Set evilMode to true if you want an "evil" character instead of a "good" character.
    // Set debugType to 1 to show where skin color is taken from, and 2 to show the skin mask in a new window (for desktop).
    static void cartoonifyImage(Mat srcColor, Mat dst, bool sketchMode, bool alienMode, bool evilMode, int debugType);
    static void cartoonifyImage(Mat srcColor, Mat dst);

private:
    static void changeFacialSkinColor(Mat smallImgBGR, Mat bigEdges, int debugType);
    static void removePepperNoise(Mat &mask);
    static void drawFaceStickFigure(Mat dst);
};

#endif // CARTOON_H
