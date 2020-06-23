# Compile on Linux instructions
# 1. Check if you have gcc, if not install
# 2. Check if you have sfml, if not install
# 3. Run this shell

sudo apt-get install gcc
sudo apt-get install libsfml-dev
g++ -std=c++17 -c main.cpp asteroid.cpp asteroid.hpp camera.cpp camera.hpp event.cpp event.hpp generation.cpp generation.hpp rotation.cpp rotation.hpp ship.cpp ship.hpp window.hpp
g++ -std=c++17 asteroid.o camera.o event.o generation.o main.o rotation.o ship.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
