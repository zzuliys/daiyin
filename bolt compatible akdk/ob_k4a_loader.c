#include"ob_k4a_loader"

instance_t get_instance(file_dll){

    // 加载动态链接库
    HMODULE hDLL = LoadLibrary(file_dll);

    // 获取函数指针
    instance_t *instance;
    if (hDLL != NULL) {
        instance->device_open = (k4a_device_open_fn_t)GetProcAddress(hDLL, "k4a_device_open");
        instance->device_close = (k4a_device_close_fn_t)GetProcAddress(hDLL, "k4a_device_close");
        instance->device_start_cameras = (k4a_device_start_cameras_fn_t)GetProcAddress(hDLL, "k4a_device_start_cameras");
        instance->device_stop_cameras = (k4a_device_stop_cameras_fn_t)GetProcAddress(hDLL, "k4a_device_stop_cameras");
        instance->device_get_capture = (k4a_device_get_capture_fn_t)GetProcAddress(hDLL, "k4a_device_get_capture");
        instance->capture_release = (k4a_capture_release_fn_t)GetProcAddress(hDLL, "k4a_capture_release");
        ...
    }
}