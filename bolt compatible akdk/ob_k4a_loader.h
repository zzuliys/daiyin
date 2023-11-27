
struct instance_t
{
    k4a_device_open_fn_t device_open;
    k4a_device_close_fn_t device_close;
    k4a_device_start_cameras_fn_t device_start_cameras;
    k4a_device_stop_cameras_fn_t device_stop_cameras;
    k4a_device_get_capture_fn_t device_get_capture;
    k4a_capture_release_fn_t capture_release;
    ...
};

instance_t get_instance(file_dll);