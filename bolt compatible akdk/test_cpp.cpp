#include"k4a.hpp"

int main(){

    instance_t *instance = k4a::context::get_instance_initialize();


    // 在用户程序中调用函数
    void app(){

        const int32_t TIMEOUT_IN_MS = 1000;
        k4a_capture_t capture = NULL;

        k4a_device_t device = NULL;
        instance->k4a_device_open(K4A_DEVICE_DEFAULT, &device);

        k4a_device_configuration_t config = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;
        config.color_format = K4A_IMAGE_FORMAT_COLOR_MJPG;
        config.color_resolution = K4A_COLOR_RESOLUTION_1080P;
        config.depth_mode = K4A_DEPTH_MODE_WFOV_UNBINNED;
        config.camera_fps = K4A_FRAMES_PER_SECOND_15;

        device->start_cameras(&config);

        instance->k4a_device_start_cameras(device, &config);

        instance->k4a_device_get_capture(device, &capture, TIMEOUT_IN_MS);

        instance->k4a_capture_release(capture);

        instance->k4a_device_stop_cameras(device);

        instance->k4a_device_close(device);

        ...
    }
}