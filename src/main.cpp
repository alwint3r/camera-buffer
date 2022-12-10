#include <Arduino.h>
#include "camera.h"
#include "gc2145.h"

static GC2145 galaxyCore;
static Camera cam(galaxyCore);

FrameBuffer fb;

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;

    if (!cam.begin(CAMERA_R320x240, CAMERA_BAYER, 30))
    {
        Serial.println("FAILED INITIALIZING CAMERA!");

        while (1)
            ;
    }

    if (cam.grabFrame(fb, 5000) != 0)
    {
        Serial.println("Failed grabbing frame");
    }
    else
    {
        Serial.write(fb.getBuffer(), cam.frameSize());
    }
}

void loop()
{
}