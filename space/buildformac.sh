# Compile on Mac OS instructions
# 1. Get brew for macos
# 2. brew install gcc
# 3. brew install sfml
# 4. run this shell

/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)"
brew install gcc
brew install sfml
g++ -std=c++17 -c *.cpp *.hpp
g++ -std=c++17 *.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
