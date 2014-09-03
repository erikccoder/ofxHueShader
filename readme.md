ofxHueShader
======================

how to use
------
		ofxHueShader::beginShader(hue);
		//        hueShader.begin(hue);
						tex.draw(0, 0);
		//        hueShader.end();
		ofxHueShader::endShader();
		
		or
		
		ofxHueShader hueShader;		
		hueShader.begin(hue);
						tex.draw(0, 0);
		hueShader.end();
