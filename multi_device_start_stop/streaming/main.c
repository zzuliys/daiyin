// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include <stdio.h>
#include <stdlib.h>
#include <k4a/k4a.h>

#define MAX_DEVICE_NUM 2
typedef struct
{
    char serial_number[64];
}serial_number_t;

int main(int argc, char **argv)
{
    int returnCode = 1;

    if (argc < 2)
    {
        printf("%s FRAMECOUNT\n", argv[0]);
        printf("Capture FRAMECOUNT color and depth frames from the device using the separate get frame APIs\n");
        returnCode = 2;
       return returnCode;
    }

    const int32_t TIMEOUT_IN_MS = 1000;

    uint32_t device_count = k4a_device_get_installed_count();

    if (device_count == 0)
    {
        printf("No K4A devices found\n");
        return 0;
    }

    k4a_device_t device[MAX_DEVICE_NUM] = { NULL };
    k4a_capture_t capture[MAX_DEVICE_NUM] = { NULL };
    k4a_device_configuration_t config[MAX_DEVICE_NUM] = { 0 };

    serial_number_t serial_number[MAX_DEVICE_NUM] = {0};
    for (uint32_t i = 0; i < MAX_DEVICE_NUM; i++)
    {
        memset(serial_number[i].serial_number, 0, sizeof(serial_number[i].serial_number));
    }

    for (uint32_t i = 0; i < device_count; i++)
    {
        if (K4A_RESULT_SUCCEEDED != k4a_device_open(i, &device[i]))
        {
            printf("Failed to open device\n");
            goto Exit;
        }

        size_t serial_number_len = sizeof(serial_number[i].serial_number);
        if (K4A_BUFFER_RESULT_SUCCEEDED !=
            k4a_device_get_serialnum(device[i], serial_number[i].serial_number, &serial_number_len))
        {
            printf("Failed to get device[%d] serial number\n",i);
            goto Exit;
        }

        config[i] = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;
        config[i].color_format = K4A_IMAGE_FORMAT_COLOR_MJPG;
        config[i].color_resolution = K4A_COLOR_RESOLUTION_1080P;
        config[i].depth_mode = K4A_DEPTH_MODE_NFOV_UNBINNED;
        config[i].camera_fps = K4A_FRAMES_PER_SECOND_30;
    }

    for(int index=0; index<10000; index++){
        printf("************************************* %d ***********************************\n", index);
        for (uint32_t i = 0; i < device_count; i++)
        {
            if (K4A_RESULT_SUCCEEDED != k4a_device_start_cameras(device[i], &config[i]))
            {
                printf("Failed to start device\n");
                goto Exit;
            }
        }

        int captureFrameCount = atoi(argv[1]);
        for (uint32_t i = 0; i < device_count; i++)
        {
            while (captureFrameCount -- >0)
            {
                for (uint32_t i = 0; i < device_count; i++)
                {

                    k4a_image_t image;

                    // Get a depth frame
                    switch (k4a_device_get_capture(device[i], &capture[i], TIMEOUT_IN_MS))
                    {
                    case K4A_WAIT_RESULT_SUCCEEDED:
                        break;
                    case K4A_WAIT_RESULT_TIMEOUT:
                        printf("Timed out waiting for a capture\n");
                        continue;
                        break;
                    case K4A_WAIT_RESULT_FAILED:
                        printf("Failed to read a capture\n");
                        goto Exit;
                    }

                    printf("serial number[%s]", serial_number[i].serial_number);

                    // Probe for a color image
                    image = k4a_capture_get_color_image(capture[i]);
                    if (image)
                    {
                        printf(" | Color res:%4dx%4d stride:%5d,dataSize:%8d ",
                            k4a_image_get_height_pixels(image),
                            k4a_image_get_width_pixels(image),
                            k4a_image_get_stride_bytes(image),
                            (int)k4a_image_get_size(image));
                        k4a_image_release(image);
                    }
                    else
                    {
                        printf(" | Color None                       ");
                    }

                    // probe for a IR16 image
                    image = k4a_capture_get_ir_image(capture[i]);
                    if (image != NULL)
                    {
                        printf(" | Ir16 res:%4dx%4d stride:%5d ",
                            k4a_image_get_height_pixels(image),
                            k4a_image_get_width_pixels(image),
                            k4a_image_get_stride_bytes(image));
                        k4a_image_release(image);
                    }
                    else
                    {
                        printf(" | Ir16 None                       ");
                    }

                    // Probe for a depth16 image
                    image = k4a_capture_get_depth_image(capture[i]);
                    if (image != NULL)
                    {
                        printf(" | Depth16 res:%4dx%4d stride:%5d\n",
                            k4a_image_get_height_pixels(image),
                            k4a_image_get_width_pixels(image),
                            k4a_image_get_stride_bytes(image));
                        k4a_image_release(image);
                    }
                    else
                    {
                        printf(" | Depth16 None\n");
                    }

                    // release capture
                    k4a_capture_release(capture[i]);
                    fflush(stdout);
                }
            }
        }

        for (uint32_t i = 0; i < device_count; i++)
        {
            if (device[i] != NULL)
            {
                k4a_device_stop_cameras(device[i]);
                printf("*******************k4a_device_stop_camera:%d *******\n", i);
            }
        }
    }


    

    returnCode = 0;

Exit:
    for (uint32_t i = 0; i < device_count; i++)
    {
        if (device[i] != NULL)
        {
            printf("!!!!!!!!!!!!!!!!!\n");
            k4a_device_close(device[i]);
        }
    }

    return returnCode;
}
