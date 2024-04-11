#include "bmpLoader.h"

unsigned int ID2[45];

void LoadTexture(const char *filename, GLint num)
{
    TK_RGBImageRec *texture1;

    texture1 = tkRGBImageLoad(filename);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexImage2D(GL_TEXTURE_2D,            // target
                 0,                        // level
                 GL_RGB,                   // internalFormat
                 texture1->sizeX,          // w
                 texture1->sizeY,          // h
                 0,                        // border
                 GL_RGB, GL_UNSIGNED_BYTE, // format,type
                 texture1->data);          // data
    // glTexImage3D()
    // Create Texture
    glGenTextures(1, &ID2[num]);
    glBindTexture(GL_TEXTURE_2D, ID2[num]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_MIRRORED_REPEAT);
    // glGenerateMipmap(GL_TEXTURE_2D);
    glTexImage2D(GL_TEXTURE_2D, 0, 3,
                 texture1->sizeX, texture1->sizeY, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, texture1->data);
}
