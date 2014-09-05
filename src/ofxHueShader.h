//
//  ofxHueShader.h
//
//
//  Created by erikccoder on 9/3/14.
//
//

#pragma once

#include "ofMain.h"

class ofxHueShader
{
private:
    
    ofShader shader;
    
    void setup()
    {
        
#define STRINGIFY(x) #x
        string HueShaderSrc = STRINGIFY(
                                        
                uniform sampler2DRect inputTexture;
                uniform float   hueAdjust;
                uniform float   alpha;
                void main ()
                {
                    const vec4  kRGBToYPrime = vec4 (0.299, 0.587, 0.114, 0.0);
                    const vec4  kRGBToI     = vec4 (0.596, -0.275, -0.321, 0.0);
                    const vec4  kRGBToQ     = vec4 (0.212, -0.523, 0.311, 0.0);
                    
                    const vec4  kYIQToR   = vec4 (1.0, 0.956, 0.621, 0.0);
                    const vec4  kYIQToG   = vec4 (1.0, -0.272, -0.647, 0.0);
                    const vec4  kYIQToB   = vec4 (1.0, -1.107, 1.704, 0.0);
                    
                    
                    vec4    color   = texture2DRect(inputTexture, gl_TexCoord [ 0 ].xy);
                    
                    float   YPrime  = dot (color, kRGBToYPrime);
                    float   I      = dot (color, kRGBToI);
                    float   Q      = dot (color, kRGBToQ);
                    
                    float   hue     = atan (Q, I);
                    float   chroma  = sqrt (I * I + Q * Q);
                    
                    hue += hueAdjust;
                    
                    Q = chroma * sin (hue);
                    I = chroma * cos (hue);
                    
                    vec4    yIQ   = vec4 (YPrime, I, Q, 0.0);
                    color.r = dot (yIQ, kYIQToR);
                    color.g = dot (yIQ, kYIQToG);
                    color.b = dot (yIQ, kYIQToB);
                    if(color.a > alpha)
                    {
                        color.a = alpha;
                    }
                    gl_FragColor = color;
                }
);        
        shader.setupShaderFromSource(GL_FRAGMENT_SHADER, HueShaderSrc);
        shader.linkProgram();
#undef STRINGIFY
        
    }
    
public:
    
    ofxHueShader()
    {
        setup();
    }
    ~ofxHueShader()
    {
        cout << "~ofxHueShader()" << endl;
    }
    
    void begin(float _hue, float _alpha = 1)
    {
        _alpha = ofClamp(_alpha, 0.0, 1.0);
        shader.begin();
        shader.setUniform1f("hueAdjust", _hue);
        shader.setUniform1f("alpha", _alpha);
        //            hueShader.setUniformTexture("inputTexture", tex.getTextureReference(), 0);
    }
    
    void end(){
        shader.end();
    }
    
    
    static void beginShader(float _hue, float alpha = 1){
        instance()->begin(_hue, alpha);
    }
    static void endShader(){
        instance()->end();
    }
    
    static ofPtr<ofxHueShader> instance()
    {
        
        static ofPtr<ofxHueShader>factory = ofPtr<ofxHueShader>(new ofxHueShader());
        return factory;
    }
    
};

/* EOF */
