#include <TinyEngine/TinyEngine>

#include <TinyEngine/image>
#include <TinyEngine/color>
#include <GLFW/glfw3.h>
int main( int argc, char* args[] ) {
 	// const GLubyte *renderer = glGetString(GL_RENDERER);
    // const GLubyte *version = glGetString(GL_VERSION);
    // std::cout << "Renderer: " << renderer << "\n";
    // std::cout << "OpenGL version supported: " << version << "\n";

	Tiny::window("Shader Effects Example", 1200, 800);

	Tiny::event.handler = [](){ /* ... */ };

	int ind = 0;    //Effect Index
	int res = 100;  //Pixelate Effect
	int bits = 4;   //Bitreduce Effect

	Tiny::view.interface = [&](){
	  ImGui::Text("Shader Effects");
	  ImGui::DragInt("Effect", &ind, 1, 0, 2);
	  ImGui::DragInt("Resolution", &res, 1, 1, 400);
	  ImGui::DragInt("Bits", &bits, 1, 1, 16);
	};

	Texture tex(image::load("canyon.png"));		//Load Texture with Image

	// Comment from Patrick: creating an object of Square2D will eceute it's contructor, 
	// in which a bind function is called. That bind function uses glBindVertexBuffer, which causes a segfault.
	//Square2D flat;														//Create Primitive Model
	Shader effect({"shader/effect.vs", "shader/effect.fs"}, {"in_Quad", "in_Tex"});

	std::string test = "imageTexture";

	Tiny::view.pipeline = [&](){

		Tiny::view.target(color::black);				//Target Main Screen

		effect.use();														//Use Effect Shader
		effect.uniform("index", ind);						//Define Uniforms
		effect.uniform("res", res);
		effect.uniform("bits", bits);
		effect.texture("imageTexture", tex);		//Load Texture
		//effect.uniform("model", flat.model);		//Add Model Matrix
		//flat.render();													//Render Primitive

	};

	Tiny::loop([&](){
		/* Absolutely Nothing! */
	});

	Tiny::quit();

	return 0;
}
