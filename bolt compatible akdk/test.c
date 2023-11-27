#include"ob_k4a_loader.h"


// 在用户程序中调用函数
void main(){
    const int32_t TIMEOUT_IN_MS = 1000;

    // 加载不同sdk实例
    instance_t *ob_instance = get_instance("libk4a_ob.dll")
    instance_t *akdk_instance = get_instance("libk4a.dll")

    k4a_device_t ob_device = NULL;
    k4a_device_t akdk_device = NULL;

    // 原有代码： k4a_device_open(K4A_DEVICE_DEFAULT, &device);
    ob_instance->device_open(K4A_DEVICE_DEFAULT, &ob_device);
    akdk_instance->device_open(K4A_DEVICE_DEFAULT, &akdk_device);

    k4a_device_configuration_t config = K4A_DEVICE_CONFIG_INIT_DISABLE_ALL;
    config.color_format = K4A_IMAGE_FORMAT_COLOR_MJPG;
    config.color_resolution = K4A_COLOR_RESOLUTION_1080P;
    config.depth_mode = K4A_DEPTH_MODE_WFOV_UNBINNED;
    config.camera_fps = K4A_FRAMES_PER_SECOND_15;

    // 原有代码：k4a_device_start_cameras(device,&config)
    ob_instance->device_start_cameras(ob_device, &config);
    akdk_instance->device_start_cameras(akdk_device, &config);
    ...
}



