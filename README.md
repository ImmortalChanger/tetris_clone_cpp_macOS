# tetris_clone_cpp_macOS
Tetris clone written in C++ for macOS. It's not mine and based off of the source code [here](https://github.com/GabOnTrash/Tetris_1), which was made following a tutorial from a YouTuber (not sure who it is but you can easily find it). I just made the build for macOS using clang.

Built and tested on macOS Monterey 12.7.6. 

## Notes:

The window is very big on macOS, I couldn't fit it on either monitor (I have two. Integrated is 1440x900 and external is 1280 × 1024). Try modifying the files to reduce the size if you want, but I haven't been successful due to my lack of C++ knowledge. Maybe I'll make it in the near future, or you can do it yourself.

To build using the original source code, make sure to use C++ 11 or later. You also need to modify some files (at least I had to):

* `Tetris.cpp`: modify the line at the top to use "quotes" instead of angled brackets to include `raylib.h` and also line 51 to use `sprintf` instead of `sprintf_l`

* `colori.h` and `griglia.h`: modify the line at the top to use "quotes" instead of angled brackets to include `raylib.h`

Or alternatively use the source code in this repo. If raylib is giving problems download the raylib-cpp wrapper from [here](https://github.com/RobLoach/raylib-cpp/releases/), extract it, then move the files from the folder **include** to the folder containing the source files, and then build. Not a very clean solution, I know, but you can do that if you need to.


![Schermata 2024-10-05 alle 18 19 15](https://github.com/user-attachments/assets/17981465-ada8-47aa-a766-5c44dabe1034)
