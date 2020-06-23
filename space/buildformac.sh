# Compile on Mac OS instructions
# 1. Get brew for macos
# 2. brew install gcc
# 3. brew install sfml
# 4. run this shell

/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
brew install gcc
brew install sfml
g++ -std=c++17 -c main.cpp asteroid.cpp asteroid.hpp camera.cpp camera.hpp event.cpp event.hpp generation.cpp generation.hpp rotation.cpp rotation.hpp ship.cpp ship.hpp window.hpp
g++ -std=c++17 asteroid.o camera.o event.o generation.o main.o rotation.o ship.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
