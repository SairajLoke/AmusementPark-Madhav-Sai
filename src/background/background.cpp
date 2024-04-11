#include "background.h"

void ground()
{
    // Set the number of segments in the circle
    int numSegments = 1000;

    // Enable texturing
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ID2[14]);

    // Push the current transformation matrix onto the stack
    glPushMatrix();

    // Apply any material properties you need
    materialProperty();

    // Begin drawing the circle
    glBegin(GL_TRIANGLE_FAN);

    // Set the texture coordinates for the center of the circle
    glTexCoord2f(0.5f, 0.5f);

    // Set the center of the circle
    float centerX = 0.0f;
    float centerY = 0.0f;
    float radius = 200.0f;

    // Define the vertices of the circle
    for (int i = 0; i <= numSegments; i++) {
        // Compute the angle of the current segment
        float angle = 2.0f * M_PI * ((float)i / (float)numSegments);

        // Compute the x and y coordinates of the vertex
        float x = centerX + radius * cosf(angle);
        float y = centerY + radius * sinf(angle);

        // Set the texture coordinates for the current vertex
        glTexCoord2f((x - centerX) / (2.0f * radius) + 0.5f, (y - centerY) / (2.0f * radius) + 0.5f);

        // Define the vertex
        glVertex3f(x, -20.0f, y);
    }

    // End drawing the circle
    glEnd();

    // Pop the transformation matrix from the stack
    glPopMatrix();

    // Disable texturing
    glDisable(GL_TEXTURE_2D);
}

void sky(float x, float y, float z, float width, float height, float length)
{
    //function to draw the sky
    
    materialProperty();
    glDisable(GL_DEPTH_TEST);
    x = x - width / 2;
    y = y - height / 2;
    z = z - length / 2;

    GLboolean day = true;

    glEnable(GL_TEXTURE_2D);
    if (day == true)
    {
        glBindTexture(GL_TEXTURE_2D, ID2[8]);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, ID2[28]);
    }
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + width, y, z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + width, y, z + length);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + width, y + height, z + length);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + width, y + height, z);
    glEnd();

    if (day == true)
    {
        glBindTexture(GL_TEXTURE_2D, ID2[27]);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, ID2[28]);
    }
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + width, y + height, z);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + width, y + height, z + length);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x, y + height, z + length);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x, y + height, z);
    glEnd();

    if (day == true)
    {
        glBindTexture(GL_TEXTURE_2D, ID2[9]);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, ID2[28]);
    }
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x, y + height, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x, y + height, z + length);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y, z + length);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x, y, z);
    glEnd();

    if (day == true)
    {
        glBindTexture(GL_TEXTURE_2D, ID2[10]);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, ID2[28]);
    }
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x + width, y, z);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x + width, y + height, z);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x, y + height, z);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x, y, z);
    glEnd();

    if (day == true)
    {
        glBindTexture(GL_TEXTURE_2D, ID2[11]);
    }
    else
    {
        glBindTexture(GL_TEXTURE_2D, ID2[28]);
    } 
    glBegin(GL_QUADS);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(x, y, z + length);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(x, y + height, z + length);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(x + width, y + height, z + length);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(x + width, y, z + length);
    glEnd();

    glDisable(GL_TEXTURE_2D);
}
