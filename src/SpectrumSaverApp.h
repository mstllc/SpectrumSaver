//
//  SpectrumSaverApp.h
//  SpectrumSaver
//
//  Created by Max Thorson on 6/2/16.
//
//

#pragma once

#include "cinder/app/AppScreenSaver.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class SpectrumSaverApp : public AppScreenSaver {
public:
    void setup() override;
    void draw() override;
    
    gl::GlslProgRef mLayer1Glsl;
    void drawLayer1();
    
    gl::GlslProgRef mLayer2Glsl;
    void drawLayer2();
};