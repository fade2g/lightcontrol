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
  * After this change, zhe platform.io commands are available in CLion

* Build with attiny produced interrupt warnings.
  * Again, no idea, if this is bad or not
  * I will see, as soos as I integrate and upload my project onto the attiny85
  
##Resources

* [Programmable AProgrammable RGB Mood Light - Attiny85](http://www.instructables.com/id/Programmable-RGB-Mood-Light-Attiny85/)
* [PlatformIO](http://platformio.org/)
* [PlatformIO CLion integration](http://docs.platformio.org/en/latest/ide/clion.html)
* [PlatformIO attiny boards](http://docs.platformio.org/en/latest/platforms/atmelavr.html#generic-attiny)
* [Jetbrains CLion](https://www.jetbrains.com/clion/)  