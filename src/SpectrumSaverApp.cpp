//
//  SpectrumSaverApp.cpp
//  SpectrumSaver
//
//  Created by Max Thorson on 6/2/16.
//
//

#include "SpectrumSaverApp.h"
#include "Resources.h"

void SpectrumSaverApp::setup() {
    mLayer1Glsl = gl::GlslProg::create(loadResource(RES_LAYER_1_VERT), loadResource(RES_LAYER_1_FRAG));
    mLayer2Glsl = gl::GlslProg::create(loadResource(RES_LAYER_2_VERT), loadResource(RES_LAYER_2_FRAG));
}

void SpectrumSaverApp::drawLayer1() {
    gl::ScopedGlslProg glslScp(mLayer1Glsl);
    
    mLayer1Glsl->uniform("u_resolution", (vec2)getWindowSize() * getWindowContentScale());
    mLayer1Glsl->uniform("u_time", (float)getElapsedSeconds());
    gl::drawSolidRect(getWindowBounds());
}

void SpectrumSaverApp::drawLayer2() {
    gl::ScopedGlslProg glslScp(mLayer2Glsl);
    
    mLayer2Glsl->uniform("u_resolution", (vec2)getWindowSize() * getWindowContentScale());
    mLayer2Glsl->uniform("u_time", (float)getElapsedSeconds());
    gl::drawSolidRect(getWindowBounds());
}

void SpectrumSaverApp::draw() {
    gl::clear(Color::black());
    
    gl::ScopedBlendAdditive blendScp;
    drawLayer1();
    drawLayer2();
}

void prepareSettings(SpectrumSaverApp::Settings *settings) {
    settings->setHighDensityDisplayEnabled(true);
}

CINDER_APP_SCREENSAVER(SpectrumSaverApp, RendererGl, prepareSettings)