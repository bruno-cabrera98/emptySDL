#include <SDL.h>
#include <SDL_opengl.h>
#include <FreeImage.h>
#include <iostream>

// MAGIA
extern "C" { FILE __iob_func[3] = { *stdin,*stdout,*stderr }; }
#ifdef main
#undef main
#endif

int main(int argc, char* argv[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "There was an error\n";
		exit(1);
	}

	// Flags for SDL (Double buffer, Hardware instead of Software, OPENGL)
	Uint32 flags = SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_OPENGL;

	if (SDL_SetVideoMode(640, 480, 32, flags) == NULL) {
		std::cerr << "There was an error\n :(";
		exit(1);
	}

	glClearColor(0.3, 0.3, 0.3, 1);

	SDL_Event event;

	do {
		glClear(GL_COLOR_BUFFER_BIT);
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
				return 0;
			}
		}
		SDL_GL_SwapBuffers();
	} while (true);

	return 0;
}
