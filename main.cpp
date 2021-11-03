#include <stdio.h>
#include <stdlib.h>
#include "SFML/Graphics.hpp"

int main(int argc, char ** argv) {
  sf::RenderWindow renderWindow(sf::VideoMode(800, 600), "Testage SFML");

  while (true) {
    renderWindow.clear();
    renderWindow.display();
  }
  return 0;
}