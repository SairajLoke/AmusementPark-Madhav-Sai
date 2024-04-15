# AmusementPark-Madhav-Sai

Semester Project for Computer Graphics Lab CS352 


## To build and run the project
(assuming you are in AmusementPark-Madhav-Sai)
```
mkdir build
cd build/
cmake ../
make 
./cs352
```
## Practices to follow
1. Coding style
2. Separate Constants file

## Necessities
1. Easier Mouse functions
2. Free but restricted viewing area

## Features
1. Trees outside instead of fence
2. Sun
3. Crowd
4. To add a opening and closing gate.
5. Balloon shooter
6. Remove some objects and add other better objects with better structures. 
7. Shadows
8. Cmake

## Done  ( in order of implementation)
- [x] Cmake
- [x] Better Mouse functions 
- [x] Animated Sunlight ( moves across the sky )
- [x] Trees
- [x] Grass textured ground
- [x] Night Sky
- [x] Balloon Shooter game
- [x] Restricted View
- [x] Added better keyboard controls
- [x] Tree texture
- [x] Larger Park Area with adjusted improvements
- [x] Remove some objects and add other better objects with better structures. 

## Key Assignments
- **Key 'xaz'**: move in x,y and z axis positive direction respectively.
- **Key 'XAZ'**: move in x,y,z negative axis direction respectively.
- **Key 's'** : human sits in roller coster
- **Key 'e'**: Human out of roller coster
- **Key 's'**: Set human->sittingRollerCoaster to true, set camera view to 2.
- **Key 'e'**: Set human->sittingRollerCoaster to false, set objects->shooting_mode to false, set camera view to 1.
- **Key 'b'**: Toggle balloon shooter view/human view, toggle objects->shooting_mode.
- **Key 'v'**: Toggle objects->arrow_currently_shot.
- **Key 'r'**: Set camera view to 0 (reset view).
- **Key 'c'**: Toggle camera view references, set view to (camera->currView + 1) % 3.
- **Key '1'**: Toggle around-the-world ride.
- **Key '2'**: Toggle roller coaster ride.
- **Key '3'**: Toggle carousel ride.
- **Key '6'**: Toggle first lamp post, toggle GL_LIGHT1, update objects->switchOne.
- **Key '7'**: Toggle second lamp post, toggle GL_LIGHT2, update objects->switchTwo.
- **Key '8'**: Toggle third lamp post, toggle GL_LIGHT3, update objects->switchThree.
- **Key '9'**: Toggle fourth lamp post, toggle GL_LIGHT4, update objects->switchFour.
- **Key 'f'**: Toggle visibility of control points, toggle objects->controlPointsFlag.
- **Key 'g'**: Toggle visibility of door, toggle doorFlag.
- **Key '0'**: Toggle day mode, toggle GL_LIGHT0, update day flag.
- **Key 'i'**: Increase lighting intensity by 0.1 if < 1.0.
- **Key 'k'**: Decrease lighting intensity by 0.1 if > 0.0.
- **Key 'o'**: Toggle objects->activate_sun.
- **Key 'd'**: Toggle to daytime
- **Key 'n'**: Toggle to Night time
- **Key 'ESC' (27)**: Exit program.