/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtMultimedia 5.4

//qmlRegisterType<SketchVFilter>("CoolCamera", 1, 0, "SketchVFilter");
import CoolCamera 1.0

Rectangle {
    id : cameraUI

    width: 800
    height: 480

    color: "black"
    state: "PhotoCapture"
    property int displayMode: 1

    states: [
        State {
            name: "PhotoCapture"
            StateChangeScript {
                script: {
                    //camera.captureMode = Camera.CaptureStillImage
                    camera.captureMode = Camera.CaptureVideo
                    camera.start()
                }
            }
        },
        State {
            name: "PhotoPreview"
        },
        State {
            name: "VideoCapture"
            StateChangeScript {
                script: {
                    camera.captureMode = Camera.CaptureVideo
                    camera.start()
                }
            }
        },
        State {
            name: "VideoPreview"
            StateChangeScript {
                script: {
                    camera.stop()
                }
            }
        }
    ]
    Cartoon{
        id: cartoon
    }

    Camera {
        id: camera
        //captureMode: Camera.CaptureStillImage
        captureMode: Camera.CaptureVideo
        imageCapture {
            onImageCaptured: {                
                //preview = ":/images/camera_flash_off.png"
                photoPreview.source = preview
                var p = preview;
                console.log("capture requestId", requestId)
                console.log("capture preview", preview)
                console.log("capture last image", camera.capturedImagePath)
                cartoon.toonify(preview, cameraUI.displayMode);
                stillControls.previewAvailable = true
                cameraUI.state = "PhotoPreview"
            }
        }

        videoRecorder {
             resolution: "640x480"
             frameRate: 30
        }
    }

    PhotoPreview {
        id : photoPreview
        anchors.fill : parent
        onClosed: cameraUI.state = "PhotoCapture"
        visible: cameraUI.state == "PhotoPreview"
        focus: visible
    }

    VideoPreview {
        id : videoPreview
        anchors.fill : parent
        onClosed: cameraUI.state = "VideoCapture"
        visible: cameraUI.state == "VideoPreview"
        focus: visible

        // don't load recorded video if preview is invisible
        source: visible ? camera.videoRecorder.actualLocation : ""
    }

    VideoOutput {
        id: viewfinder
        visible: cameraUI.state == "PhotoCapture" || cameraUI.state == "VideoCapture"

        x: 0
        y: 0
        width: parent.width - stillControls.buttonsPanelWidth
        height: parent.height
        filters:[ mode2Filter(cameraUI.displayMode)]

        source: camera
        autoOrientation: true
    }

    PhotoCaptureControls {
        id: stillControls
        anchors.fill: parent
        camera: camera
        visible: cameraUI.state == "PhotoCapture"
        onPreviewSelected: cameraUI.state = "PhotoPreview"
        onVideoModeSelected: cameraUI.state = "VideoCapture"
    }

    VideoCaptureControls {
        id: videoControls
        anchors.fill: parent
        camera: camera
        visible: cameraUI.state == "VideoCapture"
        onPreviewSelected: cameraUI.state = "VideoPreview"
        onPhotoModeSelected: cameraUI.state = "PhotoCapture"
    }

    UnchangedVFilter {
        id: unchangedFilter
    }
    ToonVFilter {
        id: toonFilter
    }
    SketchVFilter {
        id: sketchFilter
        onFinished: {
            // onFinished: console.log("results of the computation: " + result)
        }
    }
    EvilVFilter {
        id: evilFilter
    }
    AlienVFilter {
        id: alienFilter
    }
    function mode2Filter(mode) {
        console.log("Change filter mode to", mode);
        switch (mode) {
          case 0:
            return unchangedFilter;
          case 1:
            return sketchFilter;
          case 2:
            return toonFilter;
          case 3:
            return evilFilter;
          case 4:
            return alienFilter;
          default:
            return unchangedFilter;
        }
    }
}


