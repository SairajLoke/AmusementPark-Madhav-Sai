
#include "utils.h"

double degToRad(double angle)
{
    double pi = 3.14159265359;
    return (angle * (pi / 180));
}



// GLfloat model[16]; 
// glGetFloatv(GL_MODELVIEW_MATRIX, model); 

// // Extract the view matrix (3x3 upper left part)
// GLfloat viewMatrix[9];
// for (int i = 0; i < 3; ++i) {
//     for (int j = 0; j < 3; ++j) {
//         viewMatrix[i*3 + j] = modelview[i*4 + j];
//     }
// }

// // Invert the view matrix
// GLfloat inverseViewMatrix[9];
// gluInvertMatrix(viewMatrix, inverseViewMatrix);

// // Define the view direction vector in view space
// GLfloat viewDirection[3] = {0.0f, 0.0f, -1.0f};

// // Transform the view direction vector to world space
// GLfloat worldDirection[3];
// for (int i = 0; i < 3; ++i) {
//     worldDirection[i] = 0.0f;
//     for (int j = 0; j < 3; ++j) {
//         worldDirection[i] += inverseViewMatrix[i*3 + j] * viewDirection[j];
//     }
// }

// // Normalize the world direction vector (optional)
// GLfloat length = sqrt(worldDirection[0] * worldDirection[0] +
//                       worldDirection[1] * worldDirection[1] +
//                       worldDirection[2] * worldDirection[2]);
// if (length != 0.0f) {
//     for (int i = 0; i < 3; ++i) {
//         worldDirection[i] /= length;
//     }
// }

// // Now you have the world direction vector
