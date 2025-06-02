//
//  test.c
//  GUI
//
//  Created by Yujaw Manandhar on 5/24/25.
//

#include <stdio.h>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define pi 3.1415926535897932384626433f

GLuint VAO, VBO;
int colorLocation;

float tileSizeX, tileSizeY;

int mapX = 32, mapY = 32;
int map[] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
};

struct Player
{
    float posX;
    float posY;
    float rotation;
};

struct Player player;

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec2 aPos;\n"
                                 "void main() {\n"
                                 "    gl_Position = vec4(aPos, 0.0, 1.0);\n"
                                 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "uniform vec4 uColor;\n"
                                   "void main() {\n"
                                   "    FragColor = uColor;\n"
                                   "}\0";

void init(void)
{
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    float quadVertices[] = {
        x1, y1, //
        x2, y2, //
        x3, y3, //
        
        x1, y1, //
        x3, y3, //
        x4, y4  //
    };
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void *)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void drawCircle(float x, float y, float radius, int steps)
{
    float angle = pi * 2.0f / steps;
    float circleVertices[(steps + 2) * 2];

    circleVertices[0] = x;
    circleVertices[1] = y;

    for (int i = 0; i <= steps; i++)
    {
        float theta = angle * i;

        circleVertices[2 * (i + 1)] = x + cosf(theta) * radius;
        circleVertices[2 * (i + 1) + 1] = y + sinf(theta) * radius;
    }

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(circleVertices), circleVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void *)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLE_FAN, 0, steps + 2);
}

void drawTriangle(float x1, float y1, float x2, float y2,float x3, float y3)
{
    float triangleVertices[] = {
        x1,     y1, //
        x2,     y2, //
        x3,     y3  //
    };
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void *)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void drawLine(float x1, float y1, float x2, float y2)
{
    float lineVertices[] = {
        x1, y1, //
        x2, y2  //
    };
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(lineVertices), lineVertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void *)0);
    glDrawArrays(GL_LINES, 0, 2);
}

void setColor(float r, float g, float b, float a)
{
    glUniform4f(colorLocation, r, g, b, a);
}

void drawCharacter(struct Player player)
{
    drawCircle(player.posX, player.posY, 0.01f, 10);
}

void drawMap2D(void)
{
    tileSizeX = 2.0f / mapX;
    tileSizeY = 2.0f / mapY;

    for (int y = 0; y < mapY; y++)
    {
        for (int x = 0; x < mapX; x++)
        {
            if (map[y * mapX + x] == 1)
            {
                float posX = -1.0f + tileSizeX * x + tileSizeX / 2.0f;
                float posY = 1.0f - tileSizeY * y - tileSizeY / 2.0f;

                setColor(0.0f, 0.0f, 0.0f, 1.0f);
                drawQuad(
                    posX - tileSizeX / 2, posY + tileSizeY / 2, // top-left
                    posX + tileSizeX / 2, posY + tileSizeY / 2, // top-right
                    posX + tileSizeX / 2, posY - tileSizeY / 2, // bottom-right
                    posX - tileSizeX / 2, posY - tileSizeY / 2  // bottom-left
                );
            }
            else
            {
                float posX = -1.0f + tileSizeX * x + tileSizeX / 2.0f;
                float posY = 1.0f - tileSizeY * y - tileSizeY / 2.0f;

                setColor(0.5f, 0.5f, 0.7f, 1.0f);
                drawQuad(
                    posX - tileSizeX / 2, posY + tileSizeY / 2, // top-left
                    posX + tileSizeX / 2, posY + tileSizeY / 2, // top-right
                    posX + tileSizeX / 2, posY - tileSizeY / 2, // bottom-right
                    posX - tileSizeX / 2, posY - tileSizeY / 2  // bottom-left
                );
            }
        }
    }
}

void drawRays2D(void)
{
    float fov = 0.5f;
    int rayNumber = 50;
    
    float rayAngle = player.rotation - fov;
    for ( int i = 0; i < rayNumber; i ++)
    {
        float rayX = player.posX;
        float rayY = player.posY;
        for(float t = 0.0f; t < 2.0f; t += 0.01f)
        {
            rayX = player.posX + cosf(rayAngle) * t;
            rayY = player.posY + sinf(rayAngle) * t;
            
            int mapIndexX = (int)((rayX + 1.0f) * mapX / 2.0f);
            int mapIndexY = (int)((1.0f - rayY) * mapY / 2.0f);
            
            if(mapIndexX >= 0 && mapIndexX < mapX && mapIndexY >= 0 && mapIndexY < mapY)
            {
                if(map[mapIndexY * mapX + mapIndexX] == 1)
                {
                    break;
                }
            }
        }
        
        drawLine(player.posX, player.posY, rayX, rayY);
        
        rayAngle += ((fov * 2) / (rayNumber - 1)) ;
    }
}

void drawRays3D(void)
{
    float fov = 0.5f;
    int rayNumber = 20000;
    
    float rayAngle = player.rotation - fov;
    for ( int i = 0; i < rayNumber; i ++)
    {
        float rayX = player.posX;
        float rayY = player.posY;
        float distance = 0.0f;
        for(float t = 0.0f; t < 4.0f; t += 0.01f)
        {
            rayX = player.posX + cosf(rayAngle) * t;
            rayY = player.posY + sinf(rayAngle) * t;
            
            int mapIndexX = (int)((rayX + 1.0f) * mapX / 2.0f);
            int mapIndexY = (int)((1.0f - rayY) * mapY / 2.0f);
            
            if(mapIndexX >= 0 && mapIndexX < mapX && mapIndexY >= 0 && mapIndexY < mapY)
            {
                if(map[mapIndexY * mapX + mapIndexX] == 1)
                {
                    distance = t;
                    break;
                }
            }
        }
        
        // Correct fisheye distortion
        float correctedDistance = distance * cosf(rayAngle - player.rotation);
        float wallHeight = 1.0f / correctedDistance;

        // Convert column to screen space (-1 to 1)
        float column = (float)i / rayNumber * 2.0f - 1.0f;

        // Calculate top and bottom of wall in NDC
        float top = wallHeight / 2.0f;
        float bottom = -wallHeight / 2.0f;

        // Draw wall slice as vertical line
        drawLine(column, top, column, bottom);

        rayAngle += (fov * 2) / rayNumber;
    }
}

void keyCallBack(GLFWwindow *window, int key, int scancode, int action, int mod)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_W && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        player.posX += cosf(player.rotation) * 0.05f;
        player.posY += sinf(player.rotation) * 0.05f;
    }
    if (key == GLFW_KEY_S && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        player.posX -= cosf(player.rotation) * 0.05f;
        player.posY -= sinf(player.rotation) * 0.05f;
    }
    if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        player.rotation -= 0.05f;
    }
    if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
    {
        player.rotation += 0.05f;
    }
}

int main(int argv, const char *argc[])
{
    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(1024, 1024, "Yujaw's Window", NULL, NULL);

    if (!window)
    {
        return -1;
    }

    glfwMakeContextCurrent(window);

    glfwSetKeyCallback(window, keyCallBack);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        return -1;
    }

    player.posX = 0;
    player.posY = 0;
    player.rotation = pi / 2;

    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (void *)0);
    glEnableVertexAttribArray(0);

    colorLocation = glGetUniformLocation(shaderProgram, "uColor");

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    while (!glfwWindowShouldClose(window))
    {
        init();
        glUseProgram(shaderProgram);
        
        setColor(0.0f, 0.5f, 0.2f, 1.0f);
        drawRays3D();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}
