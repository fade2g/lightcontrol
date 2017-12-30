Control RGD LED with potentiometer
=== 

## Basic Idea
Use one or more potentiometers to control an aray of RGD LEDs.

Can be changing color oder color change mode. Can be brightness, can be a lot
of stuff. I'll see as I go.

The idea behind it, is to play with physical things, make something colorful and
get familiar with the technologies. 

### Technologies:
* use PlatformIO
* use attiny85
* use CLion

## My Personal Learning Path
### General
I will not consolidate my conclusions but rather try just to note down, what I did. The hope is, that 
I will not wait documenting it until I understood what I did (what will maybe never happen), but rather
document "on time".


### Phase 1: Initial tooling
* use platformio to initialize the project:
  * `platformio init -b attiny85 --ide clion -d lightcontrol`
  * Turn off virus scanner while initializing the project. Scary, but...
* platformio will output he following useful commands:
  * `platformio run` - process/build project from the current directory
  * `platformio run --target upload` or `platformio run -t upload` - upload firmware to embedded board
  * `platformio run --target clean` - clean project (remove compiled files)
  * `platformio run --help` - additional information

* Add some sourcefile to the `src` folder

* Open project in CLion
  * CLion will open the project an greet with build errors
  * This actually comes from definitions in CMakeListPrivate.txt that have two ##.
  * I have no plan, what they do and so forth, but I just "escaped" them by replacing `##` with `\#`
  * Of course I'm keeping the original file, as I have no idea, what this is for and what not
  * After this change, the platform.io commands are available in CLion
  * Update: The issue has been [reported](https://community.platformio.org/t/clion-fails-to-build-project/3126) and fixed in development build.
    * To install it use `platformio upgrade --dev`
    * This produces correct CMakeListsPrivate.txt file (at least the double has issue is fixed)
  



* Build with attiny produced interrupt warnings.
  * Again, no idea, if this is bad or not
  * I will see, as soos as I integrate and upload my project onto the attiny85
  
  
### FastLED
* Install standard FastLED library: `platformio lib install 126`
  * You can search libraries with `platformio lib search ` and the search term
  * For CLion, project needs t be re-inited using `platformio init`
    * BTW: It recreates the CMakeListsPrivate.txt
  * After that, in main.cpp, the FastLED library can be incuded with `#include <FastLED.h>`  
  
##Resources

* [Programmable RGB Mood Light - Attiny85](http://www.instructables.com/id/Programmable-RGB-Mood-Light-Attiny85/) - Inspiration on wiring
* [PlatformIO](http://platformio.org/) - The tooling for uing 
* [PlatformIO CLion integration](http://docs.platformio.org/en/latest/ide/clion.html)
* [PlatformIO attiny boards](http://docs.platformio.org/en/latest/platforms/atmelavr.html#generic-attiny)
* [Jetbrains CLion](https://www.jetbrains.com/clion/) -  The IDE I'm using
* [fastled Animation Library](http://fastled.io/) - Used for controlling WS2812B and other RGB LEDs
* [Arduino Stack Exchange, Clion + arduino](https://arduino.stackexchange.com/a/20296) - Some additional workflow hints
* [Another CLion ATTINY FastLED Project from me](https://github.com/fade2g/attiny85_platformio_fastled)  